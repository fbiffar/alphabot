#include <InfraRed.h>
#include <TRSensor.h>
#include <AlphaBotC.h>
#include <Encoder.h>
#include <lab.c>
#include <lab_types.h>

//sensors 
InfraRed IR;
TRSensor TR;
AlphaBot Bot;
Encoder Enc; 

//controller
Lab__controller_out _out;
Lab__controller_mem mem;


//Encoder 
int prev_encoder_left = 0;
int prev_encoder_right = 0;
int steps_left = 0;
int steps_right = 0;
float d_encoder_steps_left;
float d_encoder_steps_right;



//PID Controller
float Kp = 2;
float Kd = 0;
float Ki = 0;

//TR Sensor Tuning
float outer_sensors_weight = 2; 
unsigned int TR_sensor[5]={0,0,0,0,0};


//black line = false or white line = true 
int white_line = 0; 

//tuning motor
float backward_factor = 0.2;
float basespeed_left = 50;
float basespeed_right = 50;
float motorspeed_left_max = 2*basespeed_left;
float motorspeed_left_min = 0;
float motorspeed_right_max = 2*basespeed_right;
float motorspeed_right_min = 0; 
float move_away_right = 0.5;
float move_closer_left = 0.5;
float right_turn_left = 0.5;
float left_turn_right = 0.5;
float right_turn_slow_left = 0.25;
float left_turn_slow_right = 0.25;
float turn_right_end_right = 0.1;

//line thresholds 
float line_threshold_white = 5.0;
float line_threshold_black = 5.0; 

//waiting time 
float stop_threshold = 100;

  




void setup(){ 
    //Initialize sensors 
    Serial.begin(115200);
    Serial.print("setup\n");
    Lab__controller_reset(&mem);
    IR = InfraRed();
    TR = TRSensor();
    Bot = AlphaBot();
    Enc = Encoder();
}

int main(int argc, char** argv) {

  setup();
  
  int count = 0;
  

  while(count<3){
    //initialze vectors
    //int IR_range[5]={0,0,0,0,0};
    
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

    // Serial.print("\t");
    // for(int i = 0;i < 5;i++)
    // {
    //   Serial.print(TR_sensor[i]);
    //   Serial.print("\t");
    
    // }
    // Serial.print("\n");

    //get encoder values
    d_encoder_steps_left = steps_left - prev_encoder_left;
    d_encoder_steps_right = steps_right - prev_encoder_right;
    prev_encoder_left = steps_left;
    prev_encoder_right = steps_right;

    //run heptagon code 
    Lab__controller_step((float) TR_sensor[0],(float) TR_sensor[1], (float) TR_sensor[2], (float) TR_sensor[3],(float) TR_sensor[4],           // (float l2, float l1, float m, float r1, float r2,
    //Lab_V2__controller_step(7.0, 7.0, 7.0, 7.0, 4.0,           // (float l2, float l1, float m, float r1, float r2,
                            1,1,1,1,1,                                                                      // int ir_front, int ir_left_f1, int ir_left_f2,int ir_left_b1, int ir_left_b2,
                            outer_sensors_weight,
                            backward_factor, basespeed_left, basespeed_right, 
                            motorspeed_left_max, motorspeed_left_min,
                            motorspeed_right_max, motorspeed_right_min,
                            Kp, Ki, Kd,
                            d_encoder_steps_left, d_encoder_steps_right,
                            white_line, line_threshold_white, line_threshold_black, stop_threshold,
                            move_away_right, 
                            move_closer_left,
                            right_turn_left,
                            left_turn_right,
                            right_turn_slow_left,
                            left_turn_slow_right,
                            turn_right_end_right, 
                            &_out,
                            &mem
                            );      


    // extract output
    int LS =(int) _out.left_wheel;
    int RS =(int) _out.right_wheel;
    int direction = _out.direction; 

    
    Serial.print(LS);
    Serial.print("\t");                       
    Serial.print(RS); 
    Serial.print("\t");                       
    Serial.print(direction); 
    Serial.print("\t");                       
    // Serial.print(_out -> st);  
    Serial.print("\n");                       
                                          
                                 

    //give motorspeeds to robo
    Bot.MotorRun((int)LS,(int)RS, (int)direction);
    delay(100);
    //Bot.MotorRun(0,0,0);

    //count++;


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