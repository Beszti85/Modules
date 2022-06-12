/*
 * ledmatrix8x8.c
 *
 *  Created on: 2022. jún. 10.
 *      Author: drCsabesz
 */

#include "ledmatrix8x8.h"
#include "max7219.h"

// Led Matrix patterns
uint8_t LEDMATRIX_RotArrow[32u] = { 0x18u, 0x3Cu, 0x7Eu, 0xFFu, 0x18u, 0x18u, 0x18u, 0x18u,
                                    0x10u, 0x30u, 0x70u, 0xFFu, 0xFFu, 0x70u, 0x30u, 0x10u,
                                    0x18u, 0x18u, 0x18u, 0x18u, 0xFFu, 0x7Eu, 0x3Cu, 0x18u,
                                    0x08u, 0x0Cu, 0x0Eu, 0xFFu, 0xFFu, 0x0Eu, 0x0Cu, 0x08u, };

void LEDMATRIX_Init( void )
{
  MAX7219_Init();
}

void LEDMATRIX_RotateArrow( void )
{
  static uint8_t rotCtr = 0u;

  MAX7219_SetAllDigits( &LEDMATRIX_RotArrow[rotCtr * 8u] );

  rotCtr++;

  if( rotCtr == 4u)
  {
    rotCtr = 0u;
  }
}
