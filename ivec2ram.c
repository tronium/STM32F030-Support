/*
 *  ivec2ram
 *
 *  This code relocates the interrupt vector table to RAM.
 *  This code is very useful for firmware with IRQ(s) (such as SysTick) activated, and you want to run the firmware immediately after flashing it using the factory bootloader through the serial port (not using the ST-Link) interface.
 *  For example, such as when using stm32flash with "-w" and "-g" options to flash and run the firmware.
 *  Without this, you need to move the jumper for the BOOT0 pin manually (to disable the bootloader) and press the reset button to be able to run the firmware.
 *
 *  Additionally, the Replace_Interrupt_Vector() is provided for dynamically overriding (swapping) any IRQ handler during run-time.
 *
 *  Usage:
 *  1. Include the header file "ivec2ram.h" in the main program ("main.c"). No function call is needed. The Remap_Interrupt_Vector_to_RAM() will run automatically before main().
 *  2. Change the value of IV_SECTION_NAME parameter to match the definition in the ld file for the mapping allocation (0x2000'0000). Add a new section if necessary.
 *     To make/force your our section, put these lines in the very beginning of the section declaration in the ld file (change the section name accordingly):
 *	   .your_iv_section_name :
 *	   {
 *	     *(.your_iv_section_name)
 *	   } >RAM
 *
 *
 *  Created on: 19 April 2017
 *      Author: Ori Novanda
 *       Email: cargmax-at-gmail.com
 *
 */

#include "ivec2ram.h"
#include "stm32f0xx.h"

__attribute__ ((section (IV_SECTION_NAME))) void* RAM_InterruptVector[NUMBER_OF_INTERRUPT_VECTOR];

void Remap_Interrupt_Vector_to_RAM() {
	void** flash_interrupt_vector = (void**) FLASH_CODE_ADDRESS;
	for(int i=0; i<NUMBER_OF_INTERRUPT_VECTOR; i++) {
		RAM_InterruptVector[i] = flash_interrupt_vector[i];
	}
	SYSCFG->CFGR1 &= ~(SYSCFG_CFGR1_MEM_MODE);
	SYSCFG->CFGR1 |= (SYSCFG_CFGR1_MEM_MODE_0 | SYSCFG_CFGR1_MEM_MODE_1);
}

void* Replace_Interrupt_Vector(void* newAddress, int vectorIdx) {
	void* oldAddress =  (void*) RAM_InterruptVector[vectorIdx];
	RAM_InterruptVector[vectorIdx] = newAddress;
	return oldAddress;
}
