#include <Arduino.h>
#include "Output_32chanel.h"

Output_32chanel::Output_32chanel(TCA6416A *chanel0x20, TCA6416A* chanel0x21, ClosedCube_TCA9546A* mixerI2c){
    this->chanel0x20 = chanel0x20;
    this->chanel0x21 = chanel0x21;
    this->mixerI2c = mixerI2c;
}

Output_32chanel::~Output_32chanel(){
}

void Output_32chanel::begin(void){
    mixerI2c->selectChannel(3);
      while (!chanel0x20->begin(0)) { // Address 0 or 1, depending on your addr-pin
        Serial.println("TCA6416A not found");
      delay(1000);
    }
    while (!chanel0x21->begin(1)) { // Address 0 or 1, depending on your addr-pin
        Serial.println("TCA6416A not found");
      delay(1000);
    }
    
    for (size_t pin = 0; pin < 16; pin++){
      chanel0x20->pin_write(pin, LOW);
    }

    for (size_t pin = 0; pin < 16; pin++){
      chanel0x21->pin_write(pin, LOW);
    }
  
    for (size_t i = 0; i < 16; i++){
      chanel0x20->pin_mode(i, OUTPUT);
    }
    for (size_t i = 0; i < 16; i++){
      chanel0x21->pin_mode(i, OUTPUT);
    }
}


void Output_32chanel::setChanelValue(uint8_t chanel, bool value){
    mixerI2c->selectChannel(3);
    uint8_t hardwareChanel = this->mixerIndex[chanel];
    
    if (value){
        this->output32bitRegister |= 1 << chanel;
    }
    else{
        this->output32bitRegister &= ~(1 << chanel);
    }

    if (hardwareChanel < 16){
        chanel0x20->pin_write(hardwareChanel, value);
    }
    else{
        chanel0x21->pin_write(hardwareChanel-16, value);
    }
}