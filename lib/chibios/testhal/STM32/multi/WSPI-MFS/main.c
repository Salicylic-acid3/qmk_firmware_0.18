/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

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

#include <string.h>

#include "ch.h"
#include "hal.h"

#include "hal_serial_nor.h"
#include "hal_mfs.h"

#include "mfs_test_root.h"

#include "portab.h"

const SNORConfig snorcfg1 = {
  .busp             = &PORTAB_WSPI1,
  .buscfg           = &WSPIcfg1
};

SNORDriver snor1;
snor_nocache_buffer_t __nocache_snor1buf;

const MFSConfig mfscfg1 = {
  .flashp           = (BaseFlash *)&snor1,
  .erased           = 0xFFFFFFFFU,
  .bank_size        = 4096U,
  .bank0_start      = 0U,
  .bank0_sectors    = 1U,
  .bank1_start      = 1U,
  .bank1_sectors    = 1U
};

/*
 * LED blinker thread, times are in milliseconds.
 */
static THD_WORKING_AREA(waThread1, 128);
static THD_FUNCTION(Thread1, arg) {

  (void)arg;
  chRegSetThreadName("blinker");
  while (true) {
    palToggleLine(PORTAB_LINE_LED1);
    chThdSleepMilliseconds(500);
  }
}

/*
 * Application entry point.
 */
int main(void) {

  /*
   * System initializations.
   * - HAL initialization, this also initializes the configured device drivers
   *   and performs the board-specific initializations.
   * - Kernel initialization, the main() function becomes a thread and the
   *   RTOS is active.
   */
  halInit();
  chSysInit();

  /* Board-dependent GPIO setup code.*/
  portab_setup();

  /* Starting a serial port for test report output.*/
  sdStart(&PORTAB_SD1, NULL);

  /* Initializing and starting snor1 driver.*/
  snorObjectInit(&snor1, &__nocache_snor1buf);
  snorStart(&snor1, &snorcfg1);
#if 1
  /* Testing memory mapped mode.*/
  {
    uint8_t *addr;

    snorMemoryMap(&snor1, &addr);
    chThdSleepMilliseconds(50);
    snorMemoryUnmap(&snor1);
  }
#endif
  /* Creates the blinker thread.*/
  chThdCreateStatic(waThread1, sizeof(waThread1), NORMALPRIO, Thread1, NULL);

  /* Normal main() thread activity, in this demo it does nothing.*/
  while (true) {
    if (palReadLine(PORTAB_LINE_BUTTON) == PORTAB_BUTTON_PRESSED) {
       test_execute((BaseSequentialStream *)&PORTAB_SD1, &mfs_test_suite);
    }
    chThdSleepMilliseconds(500);
  }
  return 0;
}
