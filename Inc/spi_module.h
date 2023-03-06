/*
 * spi_module.h
 *
 *  Created on: Jun 20, 2022
 *      Author: drCsabesz
 */

#ifndef INC_SPI_MODULE_H_
#define INC_SPI_MODULE_H_

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

void SPIMODULE_Init( SPI_HandleTypeDef* ptrSpi, GPIO_TypeDef* ptrGpioPort, uint16_t gpioPin  );
void SPIMODULE_LedsSetState( uint8_t ledState );
void SPIMODULE_ToogleDisplay( uint8_t ledState );

#ifdef __cplusplus
}
#endif

#endif /* INC_SPI_MODULE_H_ */
