/*
 * ledmatrix8x8.h
 *
 *  Created on: 2022. jún. 10.
 *      Author: drCsabesz
 */

#ifndef INC_LEDMATRIX8X8_H_
#define INC_LEDMATRIX8X8_H_

#include "max7219.h"

void LEDMATRIX_Init( MAX7219_Handler_t* ptrHandler );
void LEDMATRIX_RotateArrow( MAX7219_Handler_t* ptrHandler );

#endif /* INC_LEDMATRIX8X8_H_ */
