/* --- Generated the 7/4/2023 at 11:59 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_test.ept --- */

#ifndef LAB_TEST_H
#define LAB_TEST_H

#include "lab_test_types.h"
typedef struct Lab_test__controller_mem {
  Lab_test__st_2 ck;
  Lab_test__st_1 v_69;
  float v_85;
  int v_82;
  int v_89;
  float v_97;
  int v_95;
  Lab_test__st v_100;
  float v_104;
  int v_101;
  float v_126;
  int v_121;
  float v_115;
  int v_112;
  float v_110;
  int v_107;
  int v_132;
  float parking_distance_1;
  int v_34;
  int v_32;
  int pnr_2;
  int car_to_the_right_1;
  int first_car_1;
  float l_1;
  float r_1;
  int alligned_1;
  int left_m_1;
  int left_line_1;
} Lab_test__controller_mem;

typedef struct Lab_test__controller_out {
  float left_wheel;
  float right_wheel;
  int direction;
  Lab_test__stateName st;
} Lab_test__controller_out;

void Lab_test__controller_reset(Lab_test__controller_mem* self);

void Lab_test__controller_step(float l2, float l1, float m, float r1,
                               float r2, int ir_front, int ir_left_f2,
                               int ir_left_f1, int ir_left_b1,
                               int ir_left_b2, float outer_sensor_weight,
                               float backward_factor, float basespeed_left,
                               float basespeed_right,
                               float motorspeed_left_max,
                               float motorspeed_left_min,
                               float motorspeed_right_max,
                               float motorspeed_right_min, float kP,
                               float kI, float kD,
                               float d_encoder_steps_left,
                               float d_encoder_steps_right, int white_line,
                               float line_threshold_white,
                               float line_threshold_black,
                               float waiting_threshold,
                               float move_away_right, float move_closer_left,
                               float right_turn_left, float left_turn_right,
                               float right_turn_slow_left,
                               float left_turn_slow_right,
                               float turn_right_end_right,
                               float min_parking_space, float stop_threshold,
                               float motorspeed_left_parking,
                               float motorspeed_right_parking,
                               float basespeed_parking,
                               float last_forward_mm,
                               Lab_test__controller_out* _out,
                               Lab_test__controller_mem* self);

#endif // LAB_TEST_H
