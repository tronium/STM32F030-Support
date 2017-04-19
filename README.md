STM32F030-Support
=================

Author: Ori Novanda (cargmax-at-gmail.com)

Collection of supporting code I made from programming the STM32F030 microcontroller.

1. *ivec2ram*

   To make the firmware runable immedialy after flashing using the factory serial bootloader (not ST-Link) without manually changing BOOT0 jumper and pressing reset button.
   For example, when flashing and running the firmware using stm32flash with "-w" and "-g" option.

2. *printf2uart*

   To use the UART/USART as the output of printf().
