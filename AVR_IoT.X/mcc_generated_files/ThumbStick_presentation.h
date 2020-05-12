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

#ifndef EXAMPLE_PRESENTATION_H
#define	EXAMPLE_PRESENTATION_H

//*************************************************************
// Vertical/Horizontal Channel Reference for 12-bit Hex Values
//*************************************************************
#define VERTICAL    MCP3204_CH0
#define HORIZONTAL  MCP3204_CH1

//*************************************************************
// Coordinate Direction Threshold Limit
//*************************************************************
#define stickThreshold      0x240
//*************************************************************
// Coordinate Direction Look-up Table
//*************************************************************
typedef enum 
{
    stickUpLeft = 0x00, stickUp  = 0x01, stickUpRight  = 0x02,
    stickLeft = 0x10, stickCentered = 0x11, stickRight  = 0x12,
    stickDownLeft = 0x20, stickDown = 0x21, stickDownRight = 0x22,
}stickCoordinateDirections_t;

#endif	/* EXAMPLE_PRESENTATION_H */