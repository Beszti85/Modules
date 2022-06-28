/*
 * spi_module.c
 *
 *  Created on: Jun 20, 2022
 *      Author: drCsabesz
 */

#include "mcp23s17.h"

void SPIMODULE_Init( void )
{
  MCP23S17_Init();
  MCP23S17_SetIODirectionAB( 0, 0 );
}

void SPIMODULE_LedsSetState( uint8_t ledState )
{
  if( ledState == 0 )
  {
    MCP23S17_WriteOutputA( 0xFFu );
  }
  else
  {
    MCP23S17_WriteOutputA( 0x00u );
  }
  MCP23S17_ReadAllRegs();
}
