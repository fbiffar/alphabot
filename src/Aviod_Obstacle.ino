#include <InfraRed.h>
#include <TRSensor.h>
#include <AlphaBotC.h>
#include <Encoder.h>
#include <lab.c>
#include <lab_types.h>

// sensors
InfraRed IR;
TRSensor TR;
AlphaBot Bot;
Encoder Enc;

// controller
Lab__controller_out _out;
Lab__controller_mem mem;

// Encoder
int prev_encoder_left = 0;
int prev_encoder_right = 0;
int steps_left = 0;
int steps_right = 0;
float d_encoder_steps_left;
float d_encoder_steps_right;

// PID Controller
float Kp = 30;
float Kd = 150;
float Ki = 0.05;

// TR Sensor Tuning
float outer_sensors_weight = 2;
unsigned int TR_sensor[5] = {0, 0, 0, 0, 0};

// IR Sensor
unsigned int IR_sensor[5] = {0, 0, 0, 0, 0};

// black line = false or white line = true
int white_line = 1;

// tuning motor
float backward_factor = 0.5;
float basespeed_left = 100;
float basespeed_right = 100;
float motorspeed_left_max = 200;
float motorspeed_left_min = 0;
float motorspeed_right_max = 200;
float motorspeed_right_min = 0;

// obstacle avoidance
float move_away_right = 0;
float move_closer_left = 0.0;
float right_turn_left = 0.6;
float left_turn_right = 0.2;
float right_turn_slow_left = 0.7;
float left_turn_slow_right = 0.25;
float turn_right_end_right = 0.0;
float basespeed_obstacle = 90;

// line thresholds
float line_threshold_white = 70.0;
float line_threshold_black = 60.0;

// waiting time
float waiting_threshold = 1000;

// obstacle

// parking

float min_parking_space = 200;
float stop_threshold = 1000;
float motorspeed_left_parking = 80;
float motorspeed_right_parking = 60;
float basespeed_parking = 80;
float last_forward_mm = 50;

int print_enum(Lab__stateName state)
{
  switch (state)
  {
  case Lab__OnLine:
  {
    Serial.print("OnLine");
    break;
  }
  case Lab__LostLine:
  {
    Serial.print("LostLine");
    break;
  }
  case Lab__ObstacleFollowing:
  {
    Serial.print("ObstacleFollowing");
    break;
  }
  case Lab__Error:
  {
    Serial.print("Error");
    break;
  }
  case Lab__Turn90Right:
  {
    Serial.print("Turn90Right");
    break;
  }
  case Lab__Turn90Left:
  {
    Serial.print("Turn90Left");
    break;
  }
  case Lab__MoveAway:
  {
    Serial.print("MoveAway");
    break;
  }
  case Lab__MoveCloser:
  {
    Serial.print("MoveCloser");
    break;
  }
  case Lab__LeftTurn:
  {
    Serial.print("LeftTurn");
    break;
  }
  case Lab__RightTurn:
  {
    Serial.print("RightTurn");
    break;
  }
  case Lab__LeftTurnSlow:
  {
    Serial.print("LeftTurnSlow");
    break;
  }
  case Lab__RightTurnSlow:
  {
    Serial.print("RightTurnSlow");
    break;
  }
  case Lab__MoveForward:
  {
    Serial.print("MoveForward");
    break;
  }
  case Lab__TurnLeftEnd:
  {
    Serial.print("TurnLeftEnd");
    break;
  }
  case Lab__Stop:
  {
    Serial.print("Stop");
    break;
  }
  case Lab__Backwards:
  {
    Serial.print("Backwards");
    break;
  }
  case Lab__Forward:
  {
    Serial.print("Forward ");
    break;
  }
  default:
  {
    Serial.print("noState");
    break;
  }
  }
  return 0;
}

void setup()
{
  // Initialize sensors
  Serial.begin(115200);
  Serial.print("setup\n");
  Lab__controller_reset(&mem);
  IR = InfraRed();
  TR = TRSensor();
  Bot = AlphaBot();
  Enc = Encoder();
}

int main(int argc, char **argv)
{

  setup();

  while (1)
  {

    // read out sensors
    IR.read_IR(IR_sensor, 5);
    TR.read_sensors_calibration(TR_sensor);

    // print results
    // for (int i = 0; i < 5; i++)
    // {
    //   Serial.print(IR_sensor[i]);
    //   Serial.print("\t");
    // }
    // Serial.print("\n");

    // Serial.print("\t");
    for (int i = 0; i < 5; i++)
    {
      Serial.print(TR_sensor[i]);
      Serial.print("\t");
    }
    // Serial.print("\n");

    // get encoder values
    d_encoder_steps_left = steps_left - prev_encoder_left;
    d_encoder_steps_right = steps_right - prev_encoder_right;
    prev_encoder_left = steps_left;
    prev_encoder_right = steps_right;

    // run heptagon code
    Lab__controller_step((float)TR_sensor[0], (float)TR_sensor[1], (float)TR_sensor[2], (float)TR_sensor[3], (float)TR_sensor[4], // (float l2, float l1, float m, float r1, float r2
                         (int)IR_sensor[0], (int)IR_sensor[1], (int)IR_sensor[2], (int)IR_sensor[3], (int)IR_sensor[4],           // int ir_front, int ir_left_f1, int ir_left_f2,int ir_left_b1, int ir_left_b2,
                         outer_sensors_weight,
                         backward_factor, basespeed_left, basespeed_right,
                         motorspeed_left_max, motorspeed_left_min,
                         motorspeed_right_max, motorspeed_right_min,
                         Kp, Ki, Kd,
                         d_encoder_steps_left, d_encoder_steps_right,
                         // white_line,
                         line_threshold_white, line_threshold_black, waiting_threshold,
                         move_away_right,
                         move_closer_left,
                         right_turn_left,
                         left_turn_right,
                         right_turn_slow_left,
                         left_turn_slow_right,
                         turn_right_end_right,
                         min_parking_space,
                         stop_threshold,
                         motorspeed_left_parking,
                         motorspeed_right_parking,
                         basespeed_parking,
                         basespeed_obstacle,
                         last_forward_mm,
                         &_out,
                         &mem);

    // extract output
    int LS = (int)_out.left_wheel;
    int RS = (int)_out.right_wheel;
    int direction = _out.direction;

    Serial.print(LS);
    Serial.print("\t");
    Serial.print(RS);
    Serial.print("\t");
    // Serial.print(direction);
    // Serial.print("\t");
    print_enum(_out.st);
    Serial.print("\n");

    // give motorspeeds to robo
    Bot.MotorRun(LS, RS, direction);
    // Serial.print(direction);
    delay(1000);
  }
}

ISR(INT0_vect) // interrupt handle for left -> is in main file ?
{
  steps_right++;
}

ISR(INT1_vect) // interrupt handle for right -> is in main file ?
{
  steps_left++;
}