/*
 * spi_module.c
 *
 *  Created on: Jun 20, 2022
 *      Author: drCsabesz
 */

#include "mcp23s17.h"

static MCP23S17_Handler_t SpiHandler;

void SPIMODULE_Init( SPI_HandleTypeDef* ptrSpi, GPIO_TypeDef* ptrGpioPort, uint16_t gpioPin  )
{
  SpiHandler.ptrHSpi = ptrSpi;
  SpiHandler.portCS  = ptrGpioPort;
  SpiHandler.pinCS   = gpioPin;

  MCP23S17_Init(&SpiHandler);
  MCP23S17_SetIODirectionAB(&SpiHandler, 0, 0 );
  MCP23S17_ReadAllRegs(&SpiHandler);
}

void SPIMODULE_LedsSetState( uint8_t ledState )
{
  if( ledState == 0 )
  {
    MCP23S17_WritePortA( &SpiHandler, 0x0Fu );
  }
  else
  {
    MCP23S17_WritePortA( &SpiHandler, 0x00u );
  }
}

void SPIMODULE_ToogleDisplay( uint8_t ledState )
{
  if( ledState == 0 )
  {
    MCP23S17_WritePortB( &SpiHandler, 0xFFu );
    MCP23S17_WritePortA( &SpiHandler, 0xFFu );
  }
  else
  {
    MCP23S17_WritePortB( &SpiHandler, 0x00u );
    MCP23S17_WritePortA( &SpiHandler, 0x00u );
  }
}
