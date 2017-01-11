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

///
/// 
///

Avs::Avs() {
    m_avs_bus = new AvsBusCommunication();
    m_avs_display = new AvsDisplay(m_avs_bus);
}

void Avs::commandLoop() {
// Do all the commands here
}

