/*
 * spi_module.c
 *
 *  Created on: Jun 20, 2022
 *      Author: drCsabesz
 */

#include "mcp23s17.h"

// Display segments cathods
#define PIN_SEG1          5u
#define PIN_SEG2          6u
#define PIN_SEG3          4u
#define PIN_SEG4          7u

#define NUM_OF_SEGMENTS   4u
#define DOT_ON            0x04u
#define DOT_OFF           0xFBu
#define NUM_OF_HEX_CHARS  16u

// Module chip MCP23S17 handler
static MCP23S17_Handler_t SpiHandler;
// Display counters
static uint8_t SegmentCounter;
static uint8_t DispTestIndex;
//Display segment masks for MCP23S17 Port A
static uint8_t DispSegOn[NUM_OF_SEGMENTS] = { 0xDFu, 0xBFu, 0xEFu, 0x7Fu };
// Display segments connected to MCP23S17 Port B
static uint8_t Disp7SegCharSet[NUM_OF_HEX_CHARS] = { 0xFAu, 0x22u, 0xB9u, 0xABu, 0x63u, 0xCBu, 0xDBu, 0xA2u, 0xFBu, 0xEBu, 0xF3u, 0x5Bu, 0xD8u, 0x3Bu, 0xD9u, 0xD1u };

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

void SPIMODULE_UpdateDisplayTestValue( void )
{
  MCP23S17_WritePortB( &SpiHandler, Disp7SegCharSet[DispTestIndex] );
  DispTestIndex++;
  if( DispTestIndex == NUM_OF_HEX_CHARS )
  {
    DispTestIndex = 0u;
  }
}

void SPIMODULE_DisplayCharTest( void )
{
  uint8_t portAValue = 0u;
  portAValue = MCP23S17_ReadPortA( &SpiHandler );
  portAValue |= 0xF0u;
  portAValue &= DispSegOn[SegmentCounter];
  MCP23S17_WritePortA( &SpiHandler, portAValue );
  SegmentCounter++;
  if( SegmentCounter == NUM_OF_SEGMENTS )
  {
    SegmentCounter = 0u;
  }
}

