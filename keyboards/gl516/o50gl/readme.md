# o50gl

![o50gl](https://s2.booth.pm/1d33594d-0c5f-4f93-baf5-2e89e0d99afc/i/4056961/964c5875-a8cb-4990-b892-04ff514c593c_base_resized.jpg)

This is 50 keys otholiner style keyboard.
Use the GL516 case.

* Keyboard Maintainer: [Salicylic_acid3](https://github.com/Salicylic-acid3)
* Hardware Supported: o50gl PCB, Pro Micro
* Hardware Availability: [PCB & Case Data](https://github.com/Salicylic-acid3/GL516_Exemple), [Booth Shop](https://salicylic-acid3.booth.pm/items/4056961)

Make example for this keyboard (after setting up your build environment):

    make gl516/o50gl:default

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

[Build guide](https://zenn.dev/salicylic_acid3/books/gl516_build_guide)

