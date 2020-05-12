/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#include <stdint.h>
#include <stdbool.h>
#include "include/pin_manager.h"
#include "drivers/spi_master.h"
#include "ThumbStick_driver.h"

//********************************************
// Actions Channels
//********************************************
// Select MCP3204
// SPI communication using 8-bit segments
// Bits 7 & 6 define ADC input
// Get first 8 bits of ADC value
// Shift ADC value by 8
// Get remaining 4 bits of ADC value, and form 12-bit ADC value
// Deselect MCP3204
// Returns 12-bit ADC value

//********************************************
// MCP3402 Driver Function 
//********************************************
uint16_t ThumbStick_MCP3402ReadChannel(MCP3204_MeasurementTypes_t measurementType, MCP3204_Channels_t readChannel)
{
    uint16_t thumbStickValue = 0;

    while(!spiMaster[thumbStick].spiOpen())
    {
    }	
    PORTC_set_pin_level(3, false); /* set ThumbStick_nCS output low */
    spiMaster[thumbStick].exchangeByte(measurementType);
    thumbStickValue = spiMaster[thumbStick].exchangeByte(readChannel) & 0x0F;
    thumbStickValue = thumbStickValue << 8;
    thumbStickValue = thumbStickValue |  spiMaster[thumbStick].exchangeByte(0x00);
    PORTC_set_pin_level(3, true); /* set ThumbStick_nCS output high */
    spiMaster[thumbStick].spiClose();

    return thumbStickValue;
}
//********************************************
// GPIO Driver Function 
//********************************************
bool ThumbStick_isPressed(void)
{
    return PORTD_get_pin_level(6) /* get ThumbStick_StickPress value */;
}
/**
 End of File
*/