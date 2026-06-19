#include <Arduino.h>
#include "Output_32chanel.h"

Output_32chanel::Output_32chanel(/* args */){
}

Output_32chanel::~Output_32chanel(){
}

void Output_32chanel::setChanelValue(uint8_t chanel, bool value){
    uint8_t hardwareChanel = this->mixerIndex[chanel];
    if (value){
        this->output32bitRegister |= 1 << chanel;
    }
    else{
        this->output32bitRegister &= ~(1 << chanel);
    }
    if (hardwareChanel < 16){
        chanel0x20.pin_write(hardwareChanel, value);
    }
    else{
        chanel0x21.pin_write(hardwareChanel, value);
    }
    
}