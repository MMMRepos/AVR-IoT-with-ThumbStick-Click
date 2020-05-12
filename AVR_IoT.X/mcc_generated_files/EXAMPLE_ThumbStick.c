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

#include <stdio.h>
#include <stdint.h>
#include "delay.h"
#include "ThumbStick_presentation.h"
#include "ThumbStick_driver.h"

//********************************************
// Define Values used for EXAMPLE
//********************************************
#define stickMaxValue       0xFFF
#define stickCenterValue    0x7FF

//********************************************
// Local (Static) Functions Prototypes
//********************************************
static stickCoordinateDirections_t EXAMPLE_GetDirection(void);
static uint8_t EXAMPLE_CoordinateState(uint16_t);

//********************************************
// EXAMPLE Implementation Function
//********************************************
void EXAMPLE_ThumbStick_Implementation(void)            // Call within while(1) loop in Main.c
{
    if (! ThumbStick_isPressed())
    {
        printf("Button Press Event!!! \r\n");
    }
    // Coordinate Direction Example Implementation
    switch (EXAMPLE_GetDirection())
    {
        case stickUp:
            printf("Up \r\n");
        break;
        case stickDown:
            printf("Down \r\n");
        break;
        case stickLeft:
            printf("Left \r\n");
        break;
        case stickRight:
            printf("Right \r\n");
        break;
        case stickCentered:
            printf("Center \r\n");
        break;
        case stickUpLeft:
            printf("Up-Left \r\n");
        break;
        case stickUpRight:
            printf("Up-Right \r\n");
        break;
        case stickDownLeft:
            printf("Down-Left \r\n");
        break;
        case stickDownRight:
            printf("Down-Right \r\n");
        break;
    }
    // Hex Value Example Implementation
    printf("\tVertical: %x \r\n", ThumbStick_MCP3402ReadChannel(SINGLE_ENDED, VERTICAL));
    printf("\tHorizontal: %x \r\n", ThumbStick_MCP3402ReadChannel(SINGLE_ENDED, HORIZONTAL));

    DELAY_milliseconds(1000);
}
//********************************************
// EXAMPLE Get Coordinate Direction
//********************************************
static stickCoordinateDirections_t EXAMPLE_GetDirection(void)
{
    stickCoordinateDirections_t coordinateDirection = stickCentered;  

    coordinateDirection = ( (EXAMPLE_CoordinateState(ThumbStick_MCP3402ReadChannel(SINGLE_ENDED, MCP3204_CH0)) << 4) 
                         + EXAMPLE_CoordinateState(ThumbStick_MCP3402ReadChannel(SINGLE_ENDED, MCP3204_CH1)) );
    
    return coordinateDirection;
}
//********************************************
// EXAMPLE Coordinate Direction Handler
//********************************************
static uint8_t EXAMPLE_CoordinateState(uint16_t passedValue)
{
    if (passedValue < (stickCenterValue - stickThreshold) )
    {             
        return 0;           // Left Column  |   Upper Row       
    }             
    else if (passedValue > (stickCenterValue + stickThreshold) )  
    {      
        return 2;           // Right Column |   Bottom Row 
    }
    else                         
    {                                       
        return 1;           // Center Column|   Center Row
    } 
}
/**
 End of File
*/
