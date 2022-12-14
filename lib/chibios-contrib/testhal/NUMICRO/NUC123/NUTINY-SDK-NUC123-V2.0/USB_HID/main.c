/*
  Copyright (C) 2016 Jonathan Struebel
  Modifications copyright (C) 2020 Alex Lewontin

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/
#include "hal.h"
#include "usbcfg.h"

/*
 * Onboard LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waBlinkThread, 128);
static THD_FUNCTION(BlinkThread, arg)
{

  (void)arg;

  chRegSetThreadName("blinker");
  while (true) {
    systime_t time = USBD1.state == USB_ACTIVE ? 250 : 500;
    OnboardLED_Toggle();
    chThdSleepMilliseconds(time);
  }
}

/*
 * Application entry point.
 */
int main(void)
{
  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();
  OnboardLED_Init();

  /*
   * Turn off the onboard LED.
   */
  OnboardLED_Off();

  chTraceSuspend(CH_DBG_TRACE_MASK_SWITCH);
  /*
   * Initializes a USB HID driver.
   */
  hidObjectInit(&UHD1);
  hidStart(&UHD1, &usbhidcfg);

  /*
   * Activates the USB driver and then the USB bus pull-up on D+.
   * Note, a delay is inserted in order to not have to disconnect the cable
   * after a reset.
   */

  usbDisconnectBus(usbhidcfg.usbp);
  chThdSleepMilliseconds(1000);
  usbStart(usbhidcfg.usbp, &usbcfg);
  chThdSleepMilliseconds(1000);
  usbConnectBus(usbhidcfg.usbp);

  /*
   * Creates the blinker thread.
   */
  chThdCreateStatic(
      waBlinkThread, sizeof(waBlinkThread), NORMALPRIO, BlinkThread, NULL);

  while (true) {
    if (usbhidcfg.usbp->state == USB_ACTIVE) {
      uint8_t report;
      size_t  n = hidGetReport(0, &report, sizeof(report));
      hidWriteReport(&UHD1, &report, n);
      n = hidReadReportt(&UHD1, &report, sizeof(report), TIME_IMMEDIATE);
      if (n > 0)
        hidSetReport(0, &report, n);
    }

    chThdSleepMilliseconds(1000);
  }
}
