/* --- Generated the 8/4/2023 at 11:36 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#ifndef LAB_H
#define LAB_H

#include "lab_types.h"
typedef struct Lab__controller_mem {
  Lab__st_3 ck;
  Lab__st_2 v_41;
  float v_45;
  int v_42;
  float v_51;
  int v_48;
  int v_54;
  Lab__st_1 v_89;
  int v_93;
  int v_90;
  int v_97;
  int v_94;
  int v_103;
  int v_100;
  int v_109;
  int v_106;
  int v_115;
  int v_112;
  int v_121;
  int v_118;
  int v_125;
  int v_122;
  int v_137;
  int v_134;
  float v_131;
  int v_128;
  int v_139;
  int away_from_line_1;
  float v_147;
  int v_145;
  Lab__st v_162;
  float v_166;
  int v_163;
  float v_192;
  int v_187;
  float v_181;
  int v_178;
  float v_176;
  int v_173;
  int v_210;
  float parking_distance_1;
  int v_36;
  int v_32;
  int pnr_3;
  int car_to_the_right_1;
  int first_car_1;
  float l_1;
  float r_1;
  int alligned_1;
  int left_m_1;
  int left_line_1;
} Lab__controller_mem;

typedef struct Lab__controller_out {
  float left_wheel;
  float right_wheel;
  int direction;
  Lab__stateName st;
} Lab__controller_out;

void Lab__controller_reset(Lab__controller_mem* self);

void Lab__controller_step(float l2, float l1, float m, float r1, float r2,
                          int ir_front, int ir_left_f2, int ir_left_f1,
                          int ir_left_b1, int ir_left_b2,
                          float outer_sensor_weight, float backward_factor,
                          float basespeed_left, float basespeed_right,
                          float motorspeed_left_max,
                          float motorspeed_left_min,
                          float motorspeed_right_max,
                          float motorspeed_right_min, float kP, float kI,
                          float kD, float d_encoder_steps_left,
                          float d_encoder_steps_right, int white_line,
                          float line_threshold_white,
                          float line_threshold_black,
                          float waiting_threshold, float move_away_right,
                          float move_closer_left, float right_turn_left,
                          float left_turn_right, float right_turn_slow_left,
                          float left_turn_slow_right,
                          float turn_right_end_right,
                          float min_parking_space, float stop_threshold,
                          float motorspeed_left_parking,
                          float motorspeed_right_parking,
                          float basespeed_parking, float basespeed_obstacle,
                          float last_forward_mm, Lab__controller_out* _out,
                          Lab__controller_mem* self);

#endif // LAB_H
