#include "mbed.h"
#include "uLCD_4DGL.h"
using namespace std::chrono;

AnalogOut  aout(PA_4);
AnalogIn Ain(PB_1);
DigitalIn upbtn(PA_7);
DigitalIn downbtn(PA_6);
DigitalIn confirmbtn(PA_2);
DigitalIn transmit(USER_BUTTON);
uLCD_4DGL uLCD(D1, D0, D2);
DigitalOut led(LED1);

float ADCdata[128]={0};
int j = 0;
bool s = 0;

bool preup;
bool predown;
bool precon;
bool pretrans;


int freq_s = 1; // frequeny to select: 120Hz
int freq = 1;

void f_change()
{
    j = 0;
    uLCD.cls();
    switch (freq)
    {
    case 0:
        uLCD.printf("\ncurrent frquency:\n %3dHz", 60);
        break;
    default:
        uLCD.printf("\ncurrent frquency:\n %3dHz", freq * 120);
        break;
    }
    switch (freq_s)
    {
    case 0:
        uLCD.printf("\nselect frquency:\n %3dHz", 60);
        break;
    default:
        uLCD.printf("\nselect frquency:\n %3dHz", freq_s * 120);
        break;
    }
    
}

int main(void)
{   
    upbtn.mode(PullNone);
    downbtn.mode(PullNone);
    confirmbtn.mode(PullNone); 
    transmit.mode(PullNone);

    switch (freq)
    {
    case 0:
        uLCD.printf("\ncurrent frquency:\n %3dHz", 60);
        break;
    default:
        uLCD.printf("\ncurrent frquency:\n %3dHz", freq * 120);
        break;
    }
    switch (freq_s)
    {
    case 0:
        uLCD.printf("\nselect frquency:\n %3dHz", 60);
        break;
    default:
        uLCD.printf("\nselect frquency:\n %3dHz", freq_s * 120);
        break;
    }

    preup = upbtn;
    predown = downbtn;
    precon = confirmbtn;
    pretrans = transmit;

    while (1) {
        if(preup != upbtn) {
            if(freq_s < 2) {
                freq_s++;
                f_change();
                preup = upbtn;
            }
        }
        if(predown != downbtn) {
            if(freq_s > 0) { 
                freq_s--;
                f_change();
                predown = downbtn;
            }
        }
        if(precon != confirmbtn) {
            freq = freq_s;
            f_change();
            precon = confirmbtn;
        }
        if (j == 128) led = 1;
        if (pretrans != transmit) {
            for (int i = 0; i < 128; i++){
                printf("%f\r\n", ADCdata[i]);
            }
            pretrans = transmit;
        }
        switch(freq)
        {
            case 2: // 240Hz
                for (float i = 0.0f; i < 0.90f; i += 0.225f) {
                    aout = i;
                    if (j < 128 && s) {
                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                for (float i = 0.90f; i > 0.0f; i -= 0.15f) {
                    aout = i;
                    if (j < 128 && s) {
                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                break;

            case 1: // 120Hz
                for (float i = 0.0f; i < 0.90f; i += 0.1125f) {
                    aout = i;
                    if (j < 128 && s) {
                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                for (float i = 0.90f; i > 0.0f; i -= 0.075f) {
                    aout = i;
                    if (j < 128 && s) {
                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                break;
            
            case 0: //60Hz
                for (float i = 0.0f; i < 0.90f; i += 0.05625f) {
                    aout = i;
                    if (j < 128 && s) {

                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                for (float i = 0.90f; i > 0.0f; i -= 0.0375f) {
                    aout = i;
                    if (j < 128 && s) {
                        ADCdata[j] = Ain;
                        j++;
                    }
                    s = !s;
                    wait_us(420);
                }
                break;
        }
        

    }

}