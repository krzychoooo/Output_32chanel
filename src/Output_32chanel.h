#ifndef B86A42CB_E53E_4982_8323_827E523D116E
#define B86A42CB_E53E_4982_8323_827E523D116E

#include <Arduino.h>
#include <TCA6416A.h>

class Output_32chanel
{
private:
    TCA6416A chanel0x20, chanel0x21;
    void setOutputRegister(uint8_t index, bool value);
    //                                0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
    const uint8_t mixerIndex[32] = {  16, 17, 18, 19, 20, 21, 22, 23, 7,  6,  5,  4,  3,  2,  1,  0,  24, 25, 26, 27, 28, 29, 30, 31, 15, 14, 13, 12, 11, 10, 9,  8};
public:
    Output_32chanel(/* args */);
    ~Output_32chanel();

    uint32_t output32bitRegister;
    void setChanelValue(uint8_t chanel, bool value);
};



#endif /* B86A42CB_E53E_4982_8323_827E523D116E */
