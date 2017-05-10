/*
 *  First created on: 10 May 2017
 *            Author: Ori Novanda
 *             Email: cargmax-at-gmail.com
 */

#ifndef SUPPORTCONF_H_
#define SUPPORTCONF_H_

#define TOOLCHAIN_TARGET_EMBITZ 1
#define TOOLCHAIN_TARGET_TRUESTUDIO 2
#define TOOLCHAIN_TARGET_MDK_ARM 3

#define TOOLCHAIN_TARGET TOOLCHAIN_TARGET_MDK_ARM
#warning TOOLCHAIN_TARGET is set to TOOLCHAIN_TARGET_MDK_ARM

#define NUMBER_OF_INTERRUPT_VECTOR 48

#define FLASH_CODE_ADDRESS 0x8000000
#define RAM_ADDRESS 0x20000000

#endif /* SUPPORTCONF_H_ */
