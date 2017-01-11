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
#include "avs_bus_communication.h"
#include "avs_display.h"

class Avs
{
public:
    Avs();
    void commandLoop();

private:
    AvsBusCommunication* m_avs_bus;
    AvsDisplay* m_avs_display;

};

#endif // AVS_H
