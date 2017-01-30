/// 
/// @file
///
/// @brief     header file for AVS Bus Communication functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#ifndef AVS_BUS_COMMUNICATION_H
#define AVS_BUS_COMMUNICATION_H

#include "configuration.h"
#include "avr_utilities/pin_definitions.hpp"

class AvsBusCommunication
{
public:
    AvsBusCommunication();
    void setAddress(char address);
    bool isAddressSet();
    void setChipEnable(bool chip_enable);
    bool isChipEnabled();
    void writeData(char data);
    char readData();
    void writeLd(bool ld_1, bool ld_2);
    void resetPOR();

private:
    void addressHasBeenSet(bool address_has_been_set);
    void initializePins();

    //Variables
    bool m_address_has_been_set;
    bool m_chip_enable;

    //Address Pins
    PIN_TYPE(B,1) AP0;
    PIN_TYPE(B,0) AP1;
    PIN_TYPE(B,3) AP2;
    PIN_TYPE(B,2) AP3;
    PIN_TYPE(L,1) AP4;
    PIN_TYPE(L,0) AP5;
    PIN_TYPE(L,3) AP6;
    PIN_TYPE(L,2) AP7;
    //Data Pins
    PIN_TYPE(G,2) P0;
    PIN_TYPE(D,7) P1;
    PIN_TYPE(G,0) P2;
    PIN_TYPE(G,1) P3;
    PIN_TYPE(L,6) P4;
    PIN_TYPE(L,7) P5;
    PIN_TYPE(L,4) P6;
    PIN_TYPE(L,5) P7;
    //LED Reset Pin
    PIN_TYPE(C,0) _G;
    //Line Select Pins
    PIN_TYPE(C,1) LD1;
    PIN_TYPE(C,3) LD2;
    PIN_TYPE(C,2) POR;
    //Buzzer Pin
    PIN_TYPE(H,6) BUZZ;
    //Matrix Pins
    PIN_TYPE(A,5) TA0;
    PIN_TYPE(A,4) TA1;
    PIN_TYPE(A,7) TA2;
    PIN_TYPE(A,6) TA3;
    PIN_TYPE(C,6) TA4;
    PIN_TYPE(C,7) TA5;
    PIN_TYPE(C,4) TA6;
    PIN_TYPE(C,5) TA7;
    PIN_TYPE(E,4) TW0;
    PIN_TYPE(E,5) TW1;
    PIN_TYPE(G,5) TW2;
    PIN_TYPE(E,3) TW3;
    PIN_TYPE(H,3) TW4;
    PIN_TYPE(H,4) TW5;
    PIN_TYPE(H,5) TW6;

};

#endif // AVS_BUS_COMMUNICATION_H
