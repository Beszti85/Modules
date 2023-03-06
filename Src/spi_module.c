/*
 * spi_module.c
 *
 *  Created on: Jun 20, 2022
 *      Author: drCsabesz
 */

#include "mcp23s17.h"

// Display segments cathods
#define SEG1_ON  0x

static MCP23S17_Handler_t SpiHandler;

// Display segments connected to MCP23S17 Port B
static uint8_t Disp7SegCharSet[16u] = { 0xF6u, 0x22u, 0xB9u, 0xABu, 0x63u, 0xCBu, 0xDBu, 0xA2u, 0xFBu, 0xEBu, 0xF3u, 0x5Bu, 0xD8u, 0x3Bu, 0xD9u, 0xD1u };

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

void SPIMODULE_DisplayCharTest( void )
{

}

