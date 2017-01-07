/// 
/// @file
///
/// @brief     AVS functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#include "avs.h"
#include "Arduino.h"

///
/// 
///

void AVS::setup()
{
    // Do Setup Stuff here
    initializePins();
}

void AVS::setAddress(char address)
{
    //Set address (A7 at last, as it is the CE)    
}

void AVS::setData(char data)
{
    //Set Data pins as outport

    //Write Data
}

char AVS::getData()
{
    //Set Data pins as inport

    //Read Data
}

void AVS::initializePins()
{
    //Set Address Pins as outport
    pinMode(AP0, OUTPUT);
    pinMode(AP1, OUTPUT);
    pinMode(AP2, OUTPUT);
    pinMode(AP3, OUTPUT);
    pinMode(AP4, OUTPUT);
    pinMode(AP5, OUTPUT);
    pinMode(AP6, OUTPUT);
    pinMode(AP7, OUTPUT);
    //Set Data Pins as outport
    pinMode(P0, OUTPUT);
    pinMode(P1, OUTPUT);
    pinMode(P2, OUTPUT);
    pinMode(P3, OUTPUT);
    pinMode(P4, OUTPUT);
    pinMode(P5, OUTPUT);
    pinMode(P6, OUTPUT);
    pinMode(P7, OUTPUT);
    //Set LED Reset Pin as outport
    pinMode(_G, OUTPUT);
    //Set Line Select Pins as outport
    pinMode(LD1, OUTPUT);
    pinMode(LD2, OUTPUT);
    //Set Buzzer as Outport
    pinMode(BUZZ, OUTPUT);
    //Set Matrix Pins and enable Pullups
    pinMode(TA0, INPUT_PULLUP);
    pinMode(TA1, INPUT_PULLUP);
    pinMode(TA2, INPUT_PULLUP);
    pinMode(TA3, INPUT_PULLUP);
    pinMode(TA4, INPUT_PULLUP);
    pinMode(TA5, INPUT_PULLUP);
    pinMode(TA6, INPUT_PULLUP);
    pinMode(TA7, INPUT_PULLUP);
    pinMode(TW0, OUTPUT);
    pinMode(TW1, OUTPUT);
    pinMode(TW2, OUTPUT);
    pinMode(TW3, OUTPUT);
    pinMode(TW4, OUTPUT);
    pinMode(TW5, OUTPUT);
    pinMode(TW6, OUTPUT);
}