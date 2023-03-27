#include <TRSensor.h>
#include "AlphaBotC.h"
#include <lab.h>

TRSensor TR;
AlphaBot Bot;
Lab__controller_out* _out;
Lab__controller_mem* mem;




void setup(){
    Serial.begin(115200);
    Lab__controller_reset(mem);
    TR = TRSensor();
    Bot = AlphaBot();
}

int main(int argc, char** argv) {

    setup();

    while(1){
        int sensorValues[5]={0,0,0,0,0};
        TR.read_sensors(sensorValues);
        
        for(int i = 0;i < 5;i++)
        {
            Serial.print(sensorValues[i]);
            Serial.print("\t");
        }
        Serial.print("\n");

        Lab__controller_step(sensorValues[0], sensorValues[1], sensorValues[2], sensorValues[3], sensorValues[4],
                            0,0,0,0,0,
                            _out,
                            mem);

        Serial.print(_out->left_wheel);
        Serial.print("\t");
        Serial.print(_out->right_wheel);
        Serial.print("\t");
        Serial.print(_out->direction);
        Serial.print("\n");
        int LW = _out->left_wheel;
        int RW = _out->right_wheel;
        int direction = _out->direction;

        if (direction== 4){
            LW = -LW;
            RW = -RW;
        }

        Bot.MotorRun(LW,RW, _out->direction);
    } 
}