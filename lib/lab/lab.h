/* --- Generated the 9/4/2023 at 11:8 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#ifndef LAB_H
#define LAB_H

#include "lab_types.h"
typedef struct Lab__controller_mem {
  Lab__st_3 ck;
  Lab__st_2 v_63;
  float v_67;
  int v_64;
  float v_73;
  int v_70;
  int v_76;
  float v_79;
  int v_77;
  Lab__st_1 v_127;
  int v_144;
  float v_141;
  int v_138;
  int v_148;
  int v_94;
  float diff_steps_1;
  int away_from_line_1;
  float v_156;
  int v_154;
  Lab__st v_177;
  int v_182;
  int v_179;
  float v_187;
  int v_184;
  float v_213;
  int v_208;
  float v_202;
  int v_199;
  float v_197;
  int v_194;
  int v_231;
  float parking_distance_1;
  int v_36;
  int v_32;
  int pnr_3;
  int white_t_cross_1;
  int white_line_1;
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
                          float d_encoder_steps_right,
                          float line_threshold_white,
                          float line_threshold_black,
                          float tcross_threshold_white,
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
