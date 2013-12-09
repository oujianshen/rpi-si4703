#include "../Si4703_Breakout.h"
#include <stdio.h>

int main()
{
        int resetPin = 23; //GPIO_23
        int sdaPin = 0; //GPIO_0 (SDA)

        Si4703_Breakout radio(resetPin, sdaPin);
        radio.powerOn();
        radio.setVolume(5);
        radio.setChannel(1040); //FM4 104.0Mhz (Austria)

        char rdsBuffer[10] = {0};
        radio.readRDS(rdsBuffer, 15000); //timeout 15sec
        printf("Listening to station: %s %.1f\n", rdsBuffer, radio.getChannel()/10.0);

        return 0;
}
