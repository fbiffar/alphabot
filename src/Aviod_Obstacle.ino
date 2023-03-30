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
int prev_encoder_left = 0;
int prev_encoder_right = 0;
int steps_left = 0;
int steps_right = 0;
float d_encoder_steps_left;
float d_encoder_steps_right;



//PID Controller
float Kp;
float Kd;
float Ki;

//TR Sensor Tuning
float outer_sensors_weight; 

//black line = false or white line = true 
bool white_line; 

//tuning motor
float backward_factor = 0.2;
float basespeed_left = 100;
float basespeed_right = 100;
float motorspeed_left_max = 200;
float motorspeed_left_min = 0;
float motorspeed_right_max = 200;
float motorspeed_right_min = 0; 
float move_away_right = 0.5;
float move_closer_left = 0.5;
float right_turn_left = 0.5;
float left_turn_right = 0.5;
float right_turn_slow_left = 0.25;
float left_turn_slow_right = 0.25;
float turn_right_end_right = 0.1;

//line thresholds 
float line_threshold_white = 7.0;
float line_threshold_black = 4.0; 

//waiting time 
float stop_threshold = 100;

  




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
    //IR.read_IR(IR_range, 5);
    TR.read_sensors_calibration(TR_sensor);

    //print results 
    // for(int i = 0;i < 5;i++)
    // {
    //   Serial.print(IR_range[i]);
    //   Serial.print("\t");
    
    // }
    // Serial.print("\n");

    for(int i = 0;i < 5;i++)
    {
      Serial.print(TR_sensor[i]);
      Serial.print("\t");
    
    }
    Serial.print("\n");

    //get encoder values
    d_encoder_steps_left = steps_left - prev_encoder_left;
    d_encoder_steps_right = steps_right - prev_encoder_right;
    prev_encoder_left = steps_left;
    prev_encoder_right = steps_right;

    //run heptagon code 


    //give motorspeeds to robo
    Bot.MotorRun((int)LS,(int)RS, (int)direction);


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