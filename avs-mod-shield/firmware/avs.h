/// 
/// @file
///
/// @brief     header file for AVS functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#ifndef AVS_H
#define AVS_H

#include "configuration.h"
#include "commands.h"
#include "Arduino.h"

class AVS
{
public:
    static void setup();
    static void setAddress(char address);
    static void setData(char data);
    char getData();

private:
    static void initializePins();
};

#endif // AVS_H
