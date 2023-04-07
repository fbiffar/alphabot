#include <InfraRed.h>
#include <TRSensor.h>
#include <AlphaBotC.h>
#include <Encoder.h>
#include <lab_test.c>
#include <lab_test_types.h>

// sensors
InfraRed IR;
TRSensor TR;
AlphaBot Bot;
Encoder Enc;

// controller
Lab_test__controller_out _out;
Lab_test__controller_mem mem;

// Encoder
int prev_encoder_left = 0;
int prev_encoder_right = 0;
int steps_left = 0;
int steps_right = 0;
float d_encoder_steps_left;
float d_encoder_steps_right;

// PID Controller
float Kp = 30;
float Kd = 25;
float Ki = 0.05;

// TR Sensor Tuning
float outer_sensors_weight = 2;
unsigned int TR_sensor[5] = {0, 0, 0, 0, 0};

// IR Sensor
unsigned int IR_sensor[5] = {0, 0, 0, 0, 0};

// black line = false or white line = true
int white_line = 1;

// tuning motor
float backward_factor = 0.26;
float basespeed_left = 100;
float basespeed_right = 100;
float motorspeed_left_max = 200;
float motorspeed_left_min = 60;
float motorspeed_right_max = 200;
float motorspeed_right_min = 60;

// obstacle avoidance
float move_away_right = 0.5;
float move_closer_left = 0.5;
float right_turn_left = 0.5;
float left_turn_right = 0.5;
float right_turn_slow_left = 0.25;
float left_turn_slow_right = 0.25;
float turn_right_end_right = 0.1;

// line thresholds
float line_threshold_white = 70.0;
float line_threshold_black = 60.0;

// waiting time
float waiting_threshold = 10;

// parking

float min_parking_space = 300;
float stop_threshold = 60;
float motorspeed_left_parking = 80;
float motorspeed_right_parking = 60;
float basespeed_parking = 80;
float last_forward_mm = 300;

void setup()
{
  // Initialize sensors
  Serial.begin(115200);
  Serial.print("setup\n");
  Lab_test__controller_reset(&mem);
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
    // for (int i = 0; i < 5; i++)
    // {
    //   Serial.print(TR_sensor[i]);
    //   Serial.print("\t");
    // }
    // Serial.print("\n");

    // get encoder values
    d_encoder_steps_left = steps_left - prev_encoder_left;
    d_encoder_steps_right = steps_right - prev_encoder_right;
    prev_encoder_left = steps_left;
    prev_encoder_right = steps_right;

    // run heptagon code
    Lab_test__controller_step((float)TR_sensor[0], (float)TR_sensor[1], (float)TR_sensor[2], (float)TR_sensor[3], (float)TR_sensor[4], // (float l2, float l1, float m, float r1, float r2
                              (int)IR_sensor[0], (int)IR_sensor[1], (int)IR_sensor[2], (int)IR_sensor[3], (int)IR_sensor[4],           // int ir_front, int ir_left_f1, int ir_left_f2,int ir_left_b1, int ir_left_b2,
                              outer_sensors_weight,
                              backward_factor, basespeed_left, basespeed_right,
                              motorspeed_left_max, motorspeed_left_min,
                              motorspeed_right_max, motorspeed_right_min,
                              Kp, Ki, Kd,
                              d_encoder_steps_left, d_encoder_steps_right,
                              white_line, line_threshold_white, line_threshold_black, waiting_threshold,
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
    const char *state = print_enum(_out.st);
    Serial.print(state);
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

const char *print_enum(enum Lab_test__stateName state)
{
  switch (state)
  {
  case Lab_test__OnLine:
    return "OnLine";
  case Lab_test__LostLine:
    return "LostLine";
  case Lab_test__ObstacleFollowing:
    return "ObstacleFollowing";
  case Lab_test__Error:
    return "Error";
  case Lab_test__Turn90Right:
    return "Turn90Right";
  case Lab_test__Turn90Left:
    return "Turn90Left";
  case Lab_test__MoveAway:
    return "MoveAway";
  case Lab_test__MoveCloser:
    return "MoveCloser";
  case Lab_test__LeftTurn:
    return "LeftTurn";
  case Lab_test__RightTurn:
    return "RightTurn";
  case Lab_test__LeftTurnSlow:
    return "LeftTurnSlow";
  case Lab_test__RightTurnSlow:
    return "RightTurnSlow";
  case Lab_test__MoveForward:
    return "MoveForward";
  case Lab_test__TurnRightEnd:
    return "TurnRightEnd";
  case Lab_test__Stop:
    return "Stop";
  case Lab_test__Backwards:
    return "Backwards";
  case Lab_test__Forward:
    return "Forward ";
  default:
    return "noState";
  }
}