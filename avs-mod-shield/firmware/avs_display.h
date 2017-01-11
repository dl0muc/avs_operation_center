/// 
/// @file
///
/// @brief     header file for AVS Display functions
///
/// @author    DC1MIL - andz
/// @date      2017-01-07
/// @copyright CC-BY-SA 4.0
///
/// @details   This file is part of the AVS Arduino Shield Firmware
///

#ifndef AVS_DISPLAY_H
#define AVS_DISPLAY_H

#include "configuration.h"
#include "avs_bus_communication.h"

#define AVS_DISP_LINES          2
#define AVS_DISP_CHARS         20
//Timings
#define AVS_DISP_INIT_DELAY    50 //We don't read the PowerUp Signal :/ so its just guessing
#define AVS_DISP_HOLD_TIME      2 //Datasheet says min 1µs but lets begin with 2
#define AVS_DISP_OFF_TIME      50 //Display needs 40µs to handle the data, lets try 50
//Commands
#define AVS_DISP_COM_16_CYCLES_GRID 0x05 //Dark
#define AVS_DISP_COM_32_CYCLES_GRID 0x06 //Brighter
#define AVS_DISP_COM_64_CYCLES_GRID 0x07 //Brightest
#define AVS_DISP_COM_MSB_NORMAL     0x08 //If MSB is HIGH, curser is shown
#define AVS_DISP_COM_MSB_BLANK      0x09 //If MSB is HIGH, blank instead of character
#define AVS_DISP_COM_MSB_INVERT     0x0A //If MSB is HIGH, character is inverted
#define AVS_DISP_COM_REFRESH        0x0E //Init and sync controllers (Send it only to the Master)
#define AVS_DISP_COM_DUTY_CYCLE     0x40 //add 0-63 to select duty cycle
#define AVS_DISP_COM_DIGIT_COUNTER  0x80 //0x80 = 32, 0x81 = 1, 0x82 = 2...
#define AVS_DISP_COM_BUFFER_POINTER 0xC0 //0xC0 = first Character, 0xC1 second...



class AvsDisplay
{

public:
    AvsDisplay(AvsBusCommunication* avs_bus);
    void initDisplay();

    enum tLineNumber {LD1, LD2, LD_both};
    void writeCharacter(char character, tLineNumber line_number, bool msb);
    void writeCharacter(char character, tLineNumber line_number, int curser_position, bool msb);


private:
    void cycleLd(tLineNumber line_number);
    void setCommand(char command, tLineNumber line_number);

    AvsBusCommunication* m_avs_bus;
    char m_display_data[AVS_DISP_LINES][AVS_DISP_CHARS];
    
};

#endif // AVS_DISPLAY_H
