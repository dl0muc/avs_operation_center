/// 
/// @file
///
/// @brief     AVS Bus Communication Functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#include "avs_bus_communication.h"

///
/// 
///
AvsBusCommunication::AvsBusCommunication()
{
    m_address_has_been_set = false;
    m_chip_enable = false;
    // Do Setup Stuff here
    initializePins();
}

///
/// 
///
void AvsBusCommunication::setAddress(char address)
{
    //Address A7 is the Chip Enable and has to get set later
    write(AP0, address & 0x01);
    write(AP1, (address >> 1) & 0x01);
    write(AP2, (address >> 2) & 0x01);
    write(AP3, (address >> 3) & 0x01);
    write(AP4, (address >> 4) & 0x01);
    write(AP5, (address >> 5) & 0x01);
    write(AP6, (address >> 6) & 0x01);
    
    addressHasBeenSet(true);
}

void AvsBusCommunication::addressHasBeenSet(bool address_has_been_set)
{
    m_address_has_been_set = address_has_been_set;
}

bool AvsBusCommunication::isAddressSet()
{
    return m_address_has_been_set;
}

///
/// 
///
void AvsBusCommunication::setChipEnable(bool chip_enable)
{
    write(AP7, chip_enable);
    m_chip_enable = chip_enable;
}

bool AvsBusCommunication::isChipEnabled()
{
    return m_chip_enable;
}

///
/// 
///
void AvsBusCommunication::writeData(char data)
{
    //Set Data pins as outport
    make_output(P0);
    make_output(P1);
    make_output(P2);
    make_output(P3);
    make_output(P4);
    make_output(P5);
    make_output(P6);
    make_output(P7);
    //Write Data
    write(P0, data & 0x01);
    write(P1, (data >> 1) & 0x01);
    write(P2, (data >> 2) & 0x01);
    write(P3, (data >> 3) & 0x01);
    write(P4, (data >> 4) & 0x01);
    write(P5, (data >> 5) & 0x01);
    write(P6, (data >> 6) & 0x01);
    write(P7, (data >> 7) & 0x01);
}

///
/// 
///
char AvsBusCommunication::readData()
{
    //Set Data pins as inport
    make_input(P0);
    make_input(P1);
    make_input(P2);
    make_input(P3);
    make_input(P4);
    make_input(P5);
    make_input(P6);
    make_input(P7);    
    //Read Data
    char data = read(P7) & 0x01;
    data = (data << 1) | (read(P6) & 0x01);
    data = (data << 1) | (read(P5) & 0x01);
    data = (data << 1) | (read(P4) & 0x01);
    data = (data << 1) | (read(P3) & 0x01);
    data = (data << 1) | (read(P2) & 0x01);
    data = (data << 1) | (read(P1) & 0x01);
    data = (data << 1) | (read(P0) & 0x01);

    return data;
}

void AvsBusCommunication::writeLd(bool ld_1, bool ld_2)
{
    write(LD1, ld_1);
    write(LD2, ld_2);
}

///
/// 
///
void AvsBusCommunication::initializePins()
{
    //Set Address Pins as outport
    make_output(AP1);
    make_output(AP1);
    make_output(AP2);
    make_output(AP3);
    make_output(AP4);
    make_output(AP5);
    make_output(AP6);
    make_output(AP7);
    //Set Data Pins as outport
    make_output(P0);
    make_output(P1);
    make_output(P2);
    make_output(P3);
    make_output(P4);
    make_output(P5);
    make_output(P6);
    make_output(P7);
    //Set LED Reset Pin as outport
    make_output(_G);
    //Set Line Select Pins as outport
    make_output(LD1);
    make_output(LD2);
    //Set Buzzer as Outport
    make_output(BUZZ);
    //Set Matrix Pins and enable Pullups
    make_input(TA0);
    make_input(TA1);
    make_input(TA2);
    make_input(TA3);
    make_input(TA4);
    make_input(TA5);
    make_input(TA6);
    make_input(TA7);
    set(TA0);
    set(TA1);
    set(TA2);
    set(TA3);
    set(TA4);
    set(TA5);
    set(TA6);
    set(TA7);
    make_output(TW0);
    make_output(TW1);
    make_output(TW2);
    make_output(TW3);
    make_output(TW4);
    make_output(TW5);
    make_output(TW6);
}