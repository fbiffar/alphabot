#include <InfraRed.h>
#include <TRSensor.h>
#include <AlphaBotC.h>
#include <Encoder.h>

//sensors 
InfraRed IR;
TRSensor TR;
AlphaBot Bot;
Encoder Enc; 
//Encoder 
int steps_left = 0;
int steps_right = 0;
int prev_steps_left = 0;
int prev_steps_right = 0;
//PID Controller
float Kp;
float Kd;
float Ki;
//motor constants
float max_speed_left;
float max_speed_right;
float min_speed_left;
float min_speed_right;
float base_speed_left;
float base_speed_right; 
float backwards;
//TR Sensor Tuning
float outer_sensors; 
int TR_max[5];
int TR_min[5];
//black line = false or white line = true 
bool bw; 






void setup(){ 
    //Initialize sensors 
    Serial.begin(115200);
    Serial.print("setup");
    IR = InfraRed();
    TR = TRSensor();
    Bot = AlphaBot();
    Enc = Encoder();
}

int main(int argc, char** argv) {

  setup();
  
  while(1){
    //initialze vectors
    int IR_range[5]={0,0,0,0,0};
    int TR_sensor[5]={0,0,0,0,0};
    
    //read out sensors
    IR.read_IR(IR_range, 5);
    TR.read_sensors_calibration(TR_sensor);

    //print results 
    for(int i = 0;i < 5;i++)
    {
      Serial.print(IR_range[i]);
      Serial.print("\t");
    
    }
    Serial.print("\n");

    for(int i = 0;i < 5;i++)
    {
      Serial.print(TR_sensor[i]);
      Serial.print("\t");
    
    }
    Serial.print("\n");

    //run heptagon code 


    //give motorspeeds to robo
    //Bot.MotorRun((int)LS,(int)RS, (int)direction);


  }
  
  
}

ISR(INT0_vect) //interrupt handle for left -> is in main file ?
{
 steps_right ++;

}

ISR(INT1_vect) //interrupt handle for right -> is in main file ?
{
 steps_left ++;
}