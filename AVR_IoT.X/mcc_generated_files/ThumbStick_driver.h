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
#ifndef THUMBSTICK_DRIVER_H
#define	THUMBSTICK_DRIVER_H

#include <stdint.h>
#include <stdbool.h>
//********************************************
// Measurement Type
//********************************************
// Single Ended:            Measures with reference to Ground
// Pseudo Differential:     Measures with reference to a different Channel
typedef enum
{
    SINGLE_ENDED = 0x06,
    PSEUDO_DIFFERENTIAL = 0x04,         
}MCP3204_MeasurementTypes_t;
//********************************************
// Available Channels
//********************************************
// Single: Channel 0 | Differential: CH0 = IN+ & CH1 = IN- 
// Single: Channel 1 | Differential: CH0 = IN- & CH1 = IN+ 
// Single: Channel 2 | Differential: CH2 = IN+ & CH3 = IN-
// Single: Channel 3 | Differential: CH2 = IN- & CH3 = IN+
typedef enum
{
    MCP3204_CH0 = 0x00,
    MCP3204_CH1 = 0x40,
    MCP3204_CH2 = 0x80,
    MCP3204_CH3 = 0xC0,
}MCP3204_Channels_t;

//********************************************
// Driver Function Prototypes 
//********************************************
uint16_t ThumbStick_MCP3402ReadChannel(MCP3204_MeasurementTypes_t, MCP3204_Channels_t);
bool ThumbStick_isPressed(void);
        
#endif	/* THUMBSTICK_DRIVER_H */