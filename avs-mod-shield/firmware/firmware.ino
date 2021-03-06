/// 
/// @file
///
/// @brief     Main file of the AVS Arduino Shield Firmware
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#include "avs.h"

Avs *avs;

void setup()
{
    avs = new Avs();
} // setup

void loop()
{
    avs->commandLoop();
#if ENABLE_DEBUG
    //Some Debug Stuff here
#endif //ENABLE_DEBUG
} // loop
