/// 
/// @file
///
/// @brief     AVS Display Functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#include "avs_display.h"
#include "avs_bus_communication.h"
#include "Arduino.h"

///
/// 
///
AvsDisplay::AvsDisplay(AvsBusCommunication* avs_bus)
{
    m_avs_bus = avs_bus;

}

void AvsDisplay::initDisplay()
{
    //first wait a few ms to powerup display
    m_avs_bus->writeData(0x00);
    delay(AVS_DISP_INIT_DELAY);
    m_avs_bus->resetPOR(); //may not work at the moment
    delayMicroseconds(100);
    //set 3 times D2-D7 on HIGH and LOW to enable parallel data
    for(int i = 0; i < 3; i++){
        delayMicroseconds(100);
        m_avs_bus->writeData(0xFC);
        delayMicroseconds(100);
        m_avs_bus->writeData(0x00);
    }  
    setCommand(AVS_DISP_COM_64_CYCLES_GRID, LD_both); //We want it bright
    setCommand(AVS_DISP_COM_MSB_INVERT, LD_both); //Inverted if MSB is HIGH
    setCommand(AVS_DISP_COM_DIGIT_COUNTER + AVS_DISP_CHARS, LD_both); //20 Digits
    setCommand(AVS_DISP_COM_REFRESH, LD1);
}

void AvsDisplay::setCommand(char command, tLineNumber line_number)
{
    m_avs_bus->writeData(0x01); //Enable Command Mode
    cycleLd(line_number);
    m_avs_bus->writeData(command);
    cycleLd(line_number);
}

void AvsDisplay::writeString(char* string, char length, tLineNumber line_number, bool msb)
{
    char length_ = 0;
    if(length < AVS_DISP_CHARS)
        length_ = length;
    else
        length_ = AVS_DISP_CHARS;

    for(int i = 0; i < length_; i++)
    {
        writeCharacter(string[i], line_number, i, msb);
    }
}

void AvsDisplay::writeCharacter(char character, tLineNumber line_number, bool msb)
{
    char special_character = 0x00;
    if(msb == true)
        special_character = 0x80;

    if(character >= 0x20 && character <=0x7A) //In that Range the Display Table == ASCII
    {
        m_avs_bus->writeData(character + special_character);
        cycleLd(line_number);
    }
    else
    {
        m_avs_bus->writeData(0x3F + special_character); // 0x3F == '?'
        cycleLd(line_number);
    }    
}

void AvsDisplay::writeCharacter(char character, tLineNumber line_number, int curser_position, bool msb)
{
    //Same as above, but with command for jumping curser
    if(curser_position < AVS_DISP_CHARS)
        setCommand(AVS_DISP_COM_BUFFER_POINTER + curser_position, line_number);
    else
        setCommand(AVS_DISP_COM_BUFFER_POINTER + AVS_DISP_CHARS, line_number);
    writeCharacter(character, line_number, msb);
}

void AvsDisplay::cycleLd(tLineNumber line_number)
{
    switch(line_number) {
        case LD1:
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_ON_TIME);
        m_avs_bus->writeLd(true, false);
        delayMicroseconds(AVS_DISP_HOLD_TIME);
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_OFF_TIME);
        break;
        case LD2:
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_ON_TIME);
        m_avs_bus->writeLd(false, true);
        delayMicroseconds(AVS_DISP_HOLD_TIME);
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_OFF_TIME);
        break;
        case LD_both:
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_ON_TIME);
        m_avs_bus->writeLd(true, false);
        delayMicroseconds(AVS_DISP_HOLD_TIME);
        m_avs_bus->writeLd(false, true);
        delayMicroseconds(AVS_DISP_HOLD_TIME);
        m_avs_bus->writeLd(false, false);
        delayMicroseconds(AVS_DISP_OFF_TIME);
        break;
        default:
        break;
    }
}




