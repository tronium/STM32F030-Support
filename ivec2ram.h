/*
 *  First created on: 19 April 2017
 *            Author: Ori Novanda
 *             Email: cargmax-at-gmail.com
 */

#ifndef IVEC2RAM_H_
#define IVEC2RAM_H_

#include "supportconf.h"

#if TOOLCHAIN_TARGET == TOOLCHAIN_TARGET_MDK_ARM
  #define IV_SECTION_NAME_HELPER(x) #x
	#define IV_SECTION_NAME ".ARM.__at" IV_SECTION_NAME_HELPER(RAM_ADDRESS)
#elif TOOLCHAIN_TARGET == TOOLCHAIN_TARGET_TRUESTUDIO
	#define IV_SECTION_NAME ".data"
#elif TOOLCHAIN_TARGET == TOOLCHAIN_TARGET_EMBITZ
	#warning "Please create and put the 'vtable' section in the beginning of RAM section declaration"
	#define IV_SECTION_NAME "vtable"
#else
	#error TOOLCHAIN_TARGET is not recognized
#endif

extern __attribute__ ((section (IV_SECTION_NAME))) void* RAM_InterruptVector[NUMBER_OF_INTERRUPT_VECTOR];

__attribute__ ((constructor)) void Remap_Interrupt_Vector_to_RAM(); // will run before main()

void* Replace_Interrupt_Vector(void* newAddress, int Vector_idx);

#endif /* IVEC2RAM_H */
