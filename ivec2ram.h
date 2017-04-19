/*
 *  Created on: 19 April 2017
 *      Author: Ori Novanda
 *       Email: cargmax-at-gmail.com
 */

#ifndef IVEC2RAM_H_
#define IVEC2RAM_H_

#define NUMBER_OF_INTERRUPT_VECTOR 48

#define FLASH_CODE_ADDRESS 0x8000000

//for Atollic+STM32CubeMX
#define IV_SECTION_NAME ".data"
//for embitz
//#define SECTION_NAME "vtable"

extern __attribute__ ((section (IV_SECTION_NAME))) void* RAM_InterruptVector[NUMBER_OF_INTERRUPT_VECTOR];

__attribute__ ((constructor)) void Remap_Interrupt_Vector_to_RAM(); // will run before main()

void* Replace_Interrupt_Vector(void* newAddress, int Vector_idx);

#endif /* IVEC2RAM_H_ */
