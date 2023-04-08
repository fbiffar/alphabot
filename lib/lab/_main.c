/* --- Generated the 8/4/2023 at 11:57 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Lab__controller_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  float l2;
  float l1;
  float m;
  float r1;
  float r2;
  int ir_front;
  int ir_left_f2;
  int ir_left_f1;
  int ir_left_b1;
  int ir_left_b2;
  float outer_sensor_weight;
  float backward_factor;
  float basespeed_left;
  float basespeed_right;
  float motorspeed_left_max;
  float motorspeed_left_min;
  float motorspeed_right_max;
  float motorspeed_right_min;
  float kP;
  float kI;
  float kD;
  float d_encoder_steps_left;
  float d_encoder_steps_right;
  int white_line;
  float line_threshold_white;
  float line_threshold_black;
  float waiting_threshold;
  float move_away_right;
  float move_closer_left;
  float right_turn_left;
  float left_turn_right;
  float right_turn_slow_left;
  float left_turn_slow_right;
  float turn_right_end_right;
  float min_parking_space;
  float stop_threshold;
  float motorspeed_left_parking;
  float motorspeed_right_parking;
  float basespeed_parking;
  float basespeed_obstacle;
  float last_forward_mm;
  Lab__controller_out _res;
  char buf_3[20];
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Lab__controller_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%f", &l2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &l1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &m)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &r1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &r2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_front)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_left_f2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_left_f1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_left_b1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_left_b2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &outer_sensor_weight)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &backward_factor)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &basespeed_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &basespeed_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_left_max)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_left_min)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_right_max)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_right_min)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &kP)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &kI)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &kD)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &d_encoder_steps_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &d_encoder_steps_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &white_line)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &line_threshold_white)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &line_threshold_black)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &waiting_threshold)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &move_away_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &move_closer_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &right_turn_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &left_turn_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &right_turn_slow_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &left_turn_slow_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &turn_right_end_right)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &min_parking_space)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &stop_threshold)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_left_parking)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &motorspeed_right_parking)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &basespeed_parking)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &basespeed_obstacle)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%f", &last_forward_mm)==EOF)) {
      return 0;
    };;
    Lab__controller_step(l2, l1, m, r1, r2, ir_front, ir_left_f2, ir_left_f1,
                         ir_left_b1, ir_left_b2, outer_sensor_weight,
                         backward_factor, basespeed_left, basespeed_right,
                         motorspeed_left_max, motorspeed_left_min,
                         motorspeed_right_max, motorspeed_right_min, kP, kI,
                         kD, d_encoder_steps_left, d_encoder_steps_right,
                         white_line, line_threshold_white,
                         line_threshold_black, waiting_threshold,
                         move_away_right, move_closer_left, right_turn_left,
                         left_turn_right, right_turn_slow_left,
                         left_turn_slow_right, turn_right_end_right,
                         min_parking_space, stop_threshold,
                         motorspeed_left_parking, motorspeed_right_parking,
                         basespeed_parking, basespeed_obstacle,
                         last_forward_mm, &_res, &mem);
    printf("%f\n", _res.left_wheel);
    printf("%f\n", _res.right_wheel);
    printf("%d\n", _res.direction);
    printf("%s\n", string_of_Lab__stateName(_res.st, buf_3));
    fflush(stdout);
  };
  return 0;
}

