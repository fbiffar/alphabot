/* --- Generated the 8/4/2023 at 12:9 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_182 = false;
  self->v_134 = Lab__St_OnLine;
  self->v_117 = true;
  self->v_111 = false;
  self->v_110 = false;
  self->v_89 = Lab__St_1_CheckState;
  self->v_54 = false;
  self->v_41 = Lab__St_2_Backwards;
  self->pnr_3 = false;
  self->ck = Lab__St_3_LineFollow;
  self->v_32 = true;
  self->v_159 = true;
  self->v_150 = true;
  self->v_145 = true;
  self->v_135 = true;
  self->v_106 = true;
  self->v_100 = true;
  self->v_48 = true;
  self->v_42 = true;
}

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
                          Lab__controller_mem* self) {
  
  int v_40;
  int v_39;
  int v_38;
  int r_5_St_3_Parking;
  Lab__st_3 s_3_St_3_Parking;
  int r_5_St_3_Stop;
  Lab__st_3 s_3_St_3_Stop;
  int r_5_St_3_TurnLeftEnd;
  Lab__st_3 s_3_St_3_TurnLeftEnd;
  int r_5_St_3_WallFollowing;
  Lab__st_3 s_3_St_3_WallFollowing;
  int r_5_St_3_ObstacleFollowing;
  Lab__st_3 s_3_St_3_ObstacleFollowing;
  int r_5_St_3_LineFollow;
  Lab__st_3 s_3_St_3_LineFollow;
  int r_4_St_2_Forward;
  Lab__st_2 s_2_St_2_Forward;
  int r_4_St_2_Turn90Right;
  Lab__st_2 s_2_St_2_Turn90Right;
  int r_4_St_2_Backwards;
  Lab__st_2 s_2_St_2_Backwards;
  Lab__st_2 ck_6;
  float v_47;
  float v_46;
  int v_44;
  int v_43;
  float sum_encoder_steps_left_1;
  float v_53;
  float v_52;
  int v_50;
  int v_49;
  float sum_encoder_steps_left;
  int finished_turn_1;
  int nr_2_St_2_Forward;
  Lab__st_2 ns_2_St_2_Forward;
  int finished_move_St_2_Forward;
  Lab__stateName st_St_3_Parking_St_2_Forward;
  int direction_St_3_Parking_St_2_Forward;
  float right_wheel_St_3_Parking_St_2_Forward;
  float left_wheel_St_3_Parking_St_2_Forward;
  int nr_2_St_2_Turn90Right;
  Lab__st_2 ns_2_St_2_Turn90Right;
  int finished_move_St_2_Turn90Right;
  Lab__stateName st_St_3_Parking_St_2_Turn90Right;
  int direction_St_3_Parking_St_2_Turn90Right;
  float right_wheel_St_3_Parking_St_2_Turn90Right;
  float left_wheel_St_3_Parking_St_2_Turn90Right;
  int nr_2_St_2_Backwards;
  Lab__st_2 ns_2_St_2_Backwards;
  int finished_move_St_2_Backwards;
  Lab__stateName st_St_3_Parking_St_2_Backwards;
  int direction_St_3_Parking_St_2_Backwards;
  float right_wheel_St_3_Parking_St_2_Backwards;
  float left_wheel_St_3_Parking_St_2_Backwards;
  Lab__st_2 ck_7;
  Lab__st_2 s_2;
  Lab__st_2 ns_2;
  int r_4;
  int nr_2;
  int pnr_2;
  int finished_move;
  int v_88;
  Lab__st_1 v_87;
  int v_86;
  Lab__st_1 v_85;
  int v_84;
  Lab__st_1 v_83;
  int v_82;
  Lab__st_1 v_81;
  int v_80;
  Lab__st_1 v_79;
  int v_78;
  Lab__st_1 v_77;
  int v_76;
  Lab__st_1 v_75;
  int v_74;
  Lab__st_1 v_73;
  int v_72;
  Lab__st_1 v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int r_3_St_1_MoveForward;
  Lab__st_1 s_1_St_1_MoveForward;
  int r_3_St_1_LeftTurnSlow;
  Lab__st_1 s_1_St_1_LeftTurnSlow;
  int r_3_St_1_RightTurnSlow;
  Lab__st_1 s_1_St_1_RightTurnSlow;
  int r_3_St_1_LeftTurn;
  Lab__st_1 s_1_St_1_LeftTurn;
  int r_3_St_1_RightTurn;
  Lab__st_1 s_1_St_1_RightTurn;
  int r_3_St_1_MoveCloser;
  Lab__st_1 s_1_St_1_MoveCloser;
  int r_3_St_1_MoveAway;
  Lab__st_1 s_1_St_1_MoveAway;
  int r_3_St_1_Turn90Left;
  Lab__st_1 s_1_St_1_Turn90Left;
  int r_3_St_1_CheckState;
  Lab__st_1 s_1_St_1_CheckState;
  Lab__st_1 ck_4;
  float v_91;
  float v_90;
  float v_93;
  float v_92;
  float v_95;
  float v_94;
  float v_97;
  float v_96;
  float v_99;
  float v_98;
  int v_109;
  int v_108;
  int v_107;
  float v_105;
  float v_104;
  int v_102;
  int v_101;
  float sum_encoder_steps;
  int finished_turn;
  int nr_1_St_1_MoveForward;
  Lab__st_1 ns_1_St_1_MoveForward;
  int away_from_line_St_1_MoveForward;
  Lab__stateName st_St_3_WallFollowing_St_1_MoveForward;
  int direction_St_3_WallFollowing_St_1_MoveForward;
  float right_wheel_St_3_WallFollowing_St_1_MoveForward;
  float left_wheel_St_3_WallFollowing_St_1_MoveForward;
  int nr_1_St_1_LeftTurnSlow;
  Lab__st_1 ns_1_St_1_LeftTurnSlow;
  int away_from_line_St_1_LeftTurnSlow;
  Lab__stateName st_St_3_WallFollowing_St_1_LeftTurnSlow;
  int direction_St_3_WallFollowing_St_1_LeftTurnSlow;
  float right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
  float left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
  int nr_1_St_1_RightTurnSlow;
  Lab__st_1 ns_1_St_1_RightTurnSlow;
  int away_from_line_St_1_RightTurnSlow;
  Lab__stateName st_St_3_WallFollowing_St_1_RightTurnSlow;
  int direction_St_3_WallFollowing_St_1_RightTurnSlow;
  float right_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
  float left_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
  int nr_1_St_1_LeftTurn;
  Lab__st_1 ns_1_St_1_LeftTurn;
  int away_from_line_St_1_LeftTurn;
  Lab__stateName st_St_3_WallFollowing_St_1_LeftTurn;
  int direction_St_3_WallFollowing_St_1_LeftTurn;
  float right_wheel_St_3_WallFollowing_St_1_LeftTurn;
  float left_wheel_St_3_WallFollowing_St_1_LeftTurn;
  int nr_1_St_1_RightTurn;
  Lab__st_1 ns_1_St_1_RightTurn;
  int away_from_line_St_1_RightTurn;
  Lab__stateName st_St_3_WallFollowing_St_1_RightTurn;
  int direction_St_3_WallFollowing_St_1_RightTurn;
  float right_wheel_St_3_WallFollowing_St_1_RightTurn;
  float left_wheel_St_3_WallFollowing_St_1_RightTurn;
  int nr_1_St_1_MoveCloser;
  Lab__st_1 ns_1_St_1_MoveCloser;
  int away_from_line_St_1_MoveCloser;
  Lab__stateName st_St_3_WallFollowing_St_1_MoveCloser;
  int direction_St_3_WallFollowing_St_1_MoveCloser;
  float right_wheel_St_3_WallFollowing_St_1_MoveCloser;
  float left_wheel_St_3_WallFollowing_St_1_MoveCloser;
  int nr_1_St_1_MoveAway;
  Lab__st_1 ns_1_St_1_MoveAway;
  int away_from_line_St_1_MoveAway;
  Lab__stateName st_St_3_WallFollowing_St_1_MoveAway;
  int direction_St_3_WallFollowing_St_1_MoveAway;
  float right_wheel_St_3_WallFollowing_St_1_MoveAway;
  float left_wheel_St_3_WallFollowing_St_1_MoveAway;
  int nr_1_St_1_Turn90Left;
  Lab__st_1 ns_1_St_1_Turn90Left;
  int away_from_line_St_1_Turn90Left;
  Lab__stateName st_St_3_WallFollowing_St_1_Turn90Left;
  int direction_St_3_WallFollowing_St_1_Turn90Left;
  float right_wheel_St_3_WallFollowing_St_1_Turn90Left;
  float left_wheel_St_3_WallFollowing_St_1_Turn90Left;
  int nr_1_St_1_CheckState;
  Lab__st_1 ns_1_St_1_CheckState;
  int away_from_line_St_1_CheckState;
  Lab__stateName st_St_3_WallFollowing_St_1_CheckState;
  int direction_St_3_WallFollowing_St_1_CheckState;
  float right_wheel_St_3_WallFollowing_St_1_CheckState;
  float left_wheel_St_3_WallFollowing_St_1_CheckState;
  Lab__st_1 ck_5;
  int v_60;
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  Lab__st_1 s_1;
  Lab__st_1 ns_1;
  int r_3;
  int nr_1;
  int pnr_1;
  int away_from_line_1;
  int front_free;
  int right_front_too_close;
  int right_front_too_far;
  int right_back_too_close;
  int right_back_too_far;
  int right_front_correct;
  int right_back_correct;
  int away_from_line;
  float v_120;
  int v_118;
  int v_116;
  Lab__st_3 v_115;
  int v_114;
  int v_113;
  int v_112;
  float counter;
  int v_133;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  float v_142;
  float v_141;
  float v_140;
  float v_139;
  int v_137;
  int v_136;
  float v_181;
  float v_180;
  int v_179;
  float v_178;
  int v_177;
  float v_176;
  float v_175;
  float v_174;
  int v_173;
  float v_172;
  int v_171;
  float v_170;
  float v_169;
  float v_168;
  float v_167;
  float v_166;
  float v_165;
  int v_163;
  int v_162;
  int v_161;
  int v_160;
  float v_158;
  float v_157;
  float v_156;
  float v_155;
  float v_154;
  int v_152;
  int v_151;
  float v_149;
  int v_147;
  int v_146;
  float v_144;
  float v_143;
  float error;
  float p;
  float i;
  float d;
  float correction;
  int nr_St_LostLine;
  Lab__st ns_St_LostLine;
  float parking_distance_St_LostLine;
  Lab__stateName st_St_3_LineFollow_St_LostLine;
  int direction_St_3_LineFollow_St_LostLine;
  float right_wheel_St_3_LineFollow_St_LostLine;
  float left_wheel_St_3_LineFollow_St_LostLine;
  int nr_St_OnLine;
  Lab__st ns_St_OnLine;
  float parking_distance_St_OnLine;
  Lab__stateName st_St_3_LineFollow_St_OnLine;
  int direction_St_3_LineFollow_St_OnLine;
  float right_wheel_St_3_LineFollow_St_OnLine;
  float left_wheel_St_3_LineFollow_St_OnLine;
  Lab__st ck_3;
  int v_132;
  Lab__st_3 v_131;
  int v_130;
  int v_129;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  Lab__st s;
  Lab__st ns;
  int r_2;
  int nr;
  int pnr;
  float parking_distance;
  int nr_3_St_3_Parking;
  Lab__st_3 ns_3_St_3_Parking;
  Lab__stateName st_St_3_Parking;
  int direction_St_3_Parking;
  float right_wheel_St_3_Parking;
  float left_wheel_St_3_Parking;
  int nr_3_St_3_Stop;
  Lab__st_3 ns_3_St_3_Stop;
  Lab__stateName st_St_3_Stop;
  int direction_St_3_Stop;
  float right_wheel_St_3_Stop;
  float left_wheel_St_3_Stop;
  int nr_3_St_3_TurnLeftEnd;
  Lab__st_3 ns_3_St_3_TurnLeftEnd;
  Lab__stateName st_St_3_TurnLeftEnd;
  int direction_St_3_TurnLeftEnd;
  float right_wheel_St_3_TurnLeftEnd;
  float left_wheel_St_3_TurnLeftEnd;
  int nr_3_St_3_WallFollowing;
  Lab__st_3 ns_3_St_3_WallFollowing;
  Lab__stateName st_St_3_WallFollowing;
  int direction_St_3_WallFollowing;
  float right_wheel_St_3_WallFollowing;
  float left_wheel_St_3_WallFollowing;
  int nr_3_St_3_ObstacleFollowing;
  Lab__st_3 ns_3_St_3_ObstacleFollowing;
  Lab__stateName st_St_3_ObstacleFollowing;
  int direction_St_3_ObstacleFollowing;
  float right_wheel_St_3_ObstacleFollowing;
  float left_wheel_St_3_ObstacleFollowing;
  int nr_3_St_3_LineFollow;
  Lab__st_3 ns_3_St_3_LineFollow;
  Lab__stateName st_St_3_LineFollow;
  int direction_St_3_LineFollow;
  float right_wheel_St_3_LineFollow;
  float left_wheel_St_3_LineFollow;
  Lab__st_3 ck_1;
  int v_37;
  int v_35;
  int v_34;
  int v_33;
  float v_31;
  float v_30;
  int v_29;
  int v_28;
  int v_27;
  int v_26;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  Lab__st_3 s_3;
  Lab__st_3 ns_3;
  int r_5;
  int nr_3;
  int left_line;
  int left_m;
  int alligned;
  float r;
  float l;
  int first_car;
  int car_to_the_right;
  car_to_the_right = !(ir_left_f2);
  v_34 = !(white_line);
  v_33 = !(ir_left_f2);
  v_35 = (v_33&&v_34);
  v_37 = (v_35||self->v_36);
  if (self->v_32) {
    first_car = false;
  } else {
    first_car = v_37;
  };
  v_31 = (outer_sensor_weight*l2);
  l = (l1+v_31);
  v_30 = (outer_sensor_weight*r2);
  r = (r1+v_30);
  v_28 = (r1<line_threshold_black);
  v_26 = (m<line_threshold_black);
  v_25 = (l1<line_threshold_black);
  v_27 = (v_25||v_26);
  v_29 = (v_27||v_28);
  v_23 = (r1>line_threshold_white);
  v_21 = (m>line_threshold_white);
  v_20 = (l1>line_threshold_white);
  v_22 = (v_20||v_21);
  v_24 = (v_22||v_23);
  if (white_line) {
    alligned = v_24;
  } else {
    alligned = v_29;
  };
  v_19 = (m>line_threshold_black);
  v_18 = (m<line_threshold_white);
  if (white_line) {
    left_m = v_18;
  } else {
    left_m = v_19;
  };
  v_16 = (r2>line_threshold_black);
  v_14 = (r1>line_threshold_black);
  v_12 = (m>line_threshold_black);
  v_10 = (l1>line_threshold_black);
  v_9 = (l2>line_threshold_black);
  v_11 = (v_9&&v_10);
  v_13 = (v_11&&v_12);
  v_15 = (v_13&&v_14);
  v_17 = (v_15&&v_16);
  v_7 = (r2<line_threshold_white);
  v_5 = (r1<line_threshold_white);
  v_3 = (m<line_threshold_white);
  v_1 = (l1<line_threshold_white);
  v = (l2<line_threshold_white);
  v_2 = (v&&v_1);
  v_4 = (v_2&&v_3);
  v_6 = (v_4&&v_5);
  v_8 = (v_6&&v_7);
  if (white_line) {
    left_line = v_8;
  } else {
    left_line = v_17;
  };
  switch (self->ck) {
    case Lab__St_3_LineFollow:
      v_39 = !(ir_front);
      v_38 = (white_line==true);
      v_40 = (v_38&&v_39);
      if (v_40) {
        r_5_St_3_LineFollow = true;
        s_3_St_3_LineFollow = Lab__St_3_ObstacleFollowing;
      } else {
        r_5_St_3_LineFollow = self->pnr_3;
        s_3_St_3_LineFollow = Lab__St_3_LineFollow;
      };
      s_3 = s_3_St_3_LineFollow;
      r_5 = r_5_St_3_LineFollow;
      break;
    case Lab__St_3_ObstacleFollowing:
      r_5_St_3_ObstacleFollowing = self->pnr_3;
      s_3_St_3_ObstacleFollowing = Lab__St_3_ObstacleFollowing;
      s_3 = s_3_St_3_ObstacleFollowing;
      r_5 = r_5_St_3_ObstacleFollowing;
      break;
    case Lab__St_3_WallFollowing:
      r_5_St_3_WallFollowing = self->pnr_3;
      s_3_St_3_WallFollowing = Lab__St_3_WallFollowing;
      s_3 = s_3_St_3_WallFollowing;
      r_5 = r_5_St_3_WallFollowing;
      break;
    case Lab__St_3_TurnLeftEnd:
      if (alligned) {
        r_5_St_3_TurnLeftEnd = true;
        s_3_St_3_TurnLeftEnd = Lab__St_3_LineFollow;
      } else {
        r_5_St_3_TurnLeftEnd = self->pnr_3;
        s_3_St_3_TurnLeftEnd = Lab__St_3_TurnLeftEnd;
      };
      s_3 = s_3_St_3_TurnLeftEnd;
      r_5 = r_5_St_3_TurnLeftEnd;
      break;
    case Lab__St_3_Stop:
      r_5_St_3_Stop = self->pnr_3;
      s_3_St_3_Stop = Lab__St_3_Stop;
      s_3 = s_3_St_3_Stop;
      r_5 = r_5_St_3_Stop;
      break;
    case Lab__St_3_Parking:
      r_5_St_3_Parking = self->pnr_3;
      s_3_St_3_Parking = Lab__St_3_Parking;
      s_3 = s_3_St_3_Parking;
      r_5 = r_5_St_3_Parking;
      break;
    default:
      break;
  };
  ck_1 = s_3;
  switch (ck_1) {
    case Lab__St_3_LineFollow:
      if (r_5) {
        pnr = false;
        ck_2 = Lab__St_OnLine;
      } else {
        pnr = self->v_182;
        ck_2 = self->v_134;
      };
      v_129 = (r1>stop_threshold);
      v_127 = (m>stop_threshold);
      v_125 = (l1>stop_threshold);
      v_124 = (white_line==false);
      v_126 = (v_124&&v_125);
      v_128 = (v_126&&v_127);
      v_130 = (v_128&&v_129);
      if (v_130) {
        v_132 = true;
        v_131 = Lab__St_3_Stop;
      } else {
        v_132 = false;
        v_131 = Lab__St_3_LineFollow;
      };
      v_121 = (white_line==false);
      switch (ck_2) {
        case Lab__St_OnLine:
          if (left_line) {
            r_2_St_OnLine = true;
            s_St_OnLine = Lab__St_LostLine;
          } else {
            r_2_St_OnLine = pnr;
            s_St_OnLine = Lab__St_OnLine;
          };
          s = s_St_OnLine;
          r_2 = r_2_St_OnLine;
          break;
        case Lab__St_LostLine:
          v_133 = !(left_m);
          if (v_133) {
            r_2_St_LostLine = true;
            s_St_LostLine = Lab__St_OnLine;
          } else {
            r_2_St_LostLine = pnr;
            s_St_LostLine = Lab__St_LostLine;
          };
          s = s_St_LostLine;
          r_2 = r_2_St_LostLine;
          break;
        default:
          break;
      };
      ck_3 = s;
      switch (ck_3) {
        case Lab__St_OnLine:
          v_178 = (basespeed_right-motorspeed_right_max);
          v_176 = (basespeed_right-motorspeed_right_min);
          v_172 = (motorspeed_left_min-basespeed_left);
          v_170 = (motorspeed_left_max-basespeed_left);
          direction_St_3_LineFollow_St_OnLine = 1;
          st_St_3_LineFollow_St_OnLine = Lab__OnLine;
          v_165 = (d_encoder_steps_right+d_encoder_steps_left);
          v_166 = (v_165/2.000000);
          v_167 = (v_166*9.425000);
          v_168 = (self->v_164+v_167);
          v_162 = !(car_to_the_right);
          v_163 = (first_car&&v_162);
          if (v_163) {
            v_169 = v_168;
          } else {
            v_169 = 0.000000;
          };
          v_160 = (r_5||r_2);
          if (self->v_159) {
            v_161 = true;
          } else {
            v_161 = v_160;
          };
          if (v_161) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_169;
          };
          v_151 = (r_5||r_2);
          if (self->v_150) {
            v_152 = true;
          } else {
            v_152 = v_151;
          };
          v_146 = (r_5||r_2);
          if (self->v_145) {
            v_147 = true;
          } else {
            v_147 = v_146;
          };
          v_144 = (l-r);
          v_143 = (r-l);
          if (white_line) {
            error = v_143;
          } else {
            error = v_144;
          };
          v_154 = (error-self->v_153);
          if (v_152) {
            d = error;
          } else {
            d = v_154;
          };
          v_158 = (d*kD);
          v_149 = (self->v_148+error);
          if (v_147) {
            i = error;
          } else {
            i = v_149;
          };
          v_156 = (i*kI);
          p = error;
          v_155 = (p*kP);
          v_157 = (v_155+v_156);
          correction = (v_157+v_158);
          v_180 = (basespeed_right-correction);
          v_179 = (correction<v_178);
          if (v_179) {
            v_181 = motorspeed_right_max;
          } else {
            v_181 = v_180;
          };
          v_177 = (correction>v_176);
          if (v_177) {
            right_wheel_St_3_LineFollow_St_OnLine = motorspeed_right_min;
          } else {
            right_wheel_St_3_LineFollow_St_OnLine = v_181;
          };
          v_174 = (basespeed_left+correction);
          v_173 = (correction<v_172);
          if (v_173) {
            v_175 = motorspeed_left_min;
          } else {
            v_175 = v_174;
          };
          v_171 = (correction>v_170);
          if (v_171) {
            left_wheel_St_3_LineFollow_St_OnLine = motorspeed_left_max;
          } else {
            left_wheel_St_3_LineFollow_St_OnLine = v_175;
          };
          nr_St_OnLine = false;
          ns_St_OnLine = Lab__St_OnLine;
          left_wheel_St_3_LineFollow = left_wheel_St_3_LineFollow_St_OnLine;
          right_wheel_St_3_LineFollow = right_wheel_St_3_LineFollow_St_OnLine;
          direction_St_3_LineFollow = direction_St_3_LineFollow_St_OnLine;
          st_St_3_LineFollow = st_St_3_LineFollow_St_OnLine;
          parking_distance = parking_distance_St_OnLine;
          ns = ns_St_OnLine;
          nr = nr_St_OnLine;
          break;
        case Lab__St_LostLine:
          v_141 = (motorspeed_right_max-motorspeed_right_min);
          v_142 = (v_141*backward_factor);
          right_wheel_St_3_LineFollow_St_LostLine = (motorspeed_right_min+v_142);
          v_139 = (motorspeed_left_max-motorspeed_left_min);
          v_140 = (v_139*backward_factor);
          left_wheel_St_3_LineFollow_St_LostLine = (motorspeed_left_min+v_140);
          direction_St_3_LineFollow_St_LostLine = 4;
          st_St_3_LineFollow_St_LostLine = Lab__LostLine;
          v_136 = (r_5||r_2);
          if (self->v_135) {
            v_137 = true;
          } else {
            v_137 = v_136;
          };
          if (v_137) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_138;
          };
          nr_St_LostLine = false;
          ns_St_LostLine = Lab__St_LostLine;
          left_wheel_St_3_LineFollow = left_wheel_St_3_LineFollow_St_LostLine;
          right_wheel_St_3_LineFollow = right_wheel_St_3_LineFollow_St_LostLine;
          direction_St_3_LineFollow = direction_St_3_LineFollow_St_LostLine;
          st_St_3_LineFollow = st_St_3_LineFollow_St_LostLine;
          parking_distance = parking_distance_St_LostLine;
          ns = ns_St_LostLine;
          nr = nr_St_LostLine;
          break;
        default:
          break;
      };
      v_122 = (parking_distance>=min_parking_space);
      v_123 = (v_121&&v_122);
      if (v_123) {
        nr_3_St_3_LineFollow = true;
        ns_3_St_3_LineFollow = Lab__St_3_Parking;
      } else {
        nr_3_St_3_LineFollow = v_132;
        ns_3_St_3_LineFollow = v_131;
      };
      _out->left_wheel = left_wheel_St_3_LineFollow;
      _out->right_wheel = right_wheel_St_3_LineFollow;
      _out->direction = direction_St_3_LineFollow;
      _out->st = st_St_3_LineFollow;
      ns_3 = ns_3_St_3_LineFollow;
      nr_3 = nr_3_St_3_LineFollow;
      self->parking_distance_1 = parking_distance;
      self->v_182 = nr;
      self->v_134 = ns;
      break;
    case Lab__St_3_ObstacleFollowing:
      right_wheel_St_3_ObstacleFollowing = 0.000000;
      left_wheel_St_3_ObstacleFollowing = 0.000000;
      direction_St_3_ObstacleFollowing = 0;
      st_St_3_ObstacleFollowing = Lab__ObstacleFollowing;
      v_120 = (self->v_119+1.000000);
      if (self->v_117) {
        v_118 = true;
      } else {
        v_118 = r_5;
      };
      if (v_118) {
        counter = 0.000000;
      } else {
        counter = v_120;
      };
      if (ir_front) {
        v_116 = true;
        v_115 = Lab__St_3_LineFollow;
      } else {
        v_116 = false;
        v_115 = Lab__St_3_ObstacleFollowing;
      };
      v_113 = !(ir_front);
      v_112 = (counter>=waiting_threshold);
      v_114 = (v_112&&v_113);
      if (v_114) {
        nr_3_St_3_ObstacleFollowing = true;
        ns_3_St_3_ObstacleFollowing = Lab__St_3_WallFollowing;
      } else {
        nr_3_St_3_ObstacleFollowing = v_116;
        ns_3_St_3_ObstacleFollowing = v_115;
      };
      _out->left_wheel = left_wheel_St_3_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_3_ObstacleFollowing;
      _out->direction = direction_St_3_ObstacleFollowing;
      _out->st = st_St_3_ObstacleFollowing;
      ns_3 = ns_3_St_3_ObstacleFollowing;
      nr_3 = nr_3_St_3_ObstacleFollowing;
      self->v_119 = counter;
      self->v_117 = false;
      break;
    case Lab__St_3_WallFollowing:
      if (r_5) {
        away_from_line_1 = false;
        pnr_1 = false;
        ck_4 = Lab__St_1_CheckState;
      } else {
        away_from_line_1 = self->v_111;
        pnr_1 = self->v_110;
        ck_4 = self->v_89;
      };
      right_back_too_far = ir_left_b2;
      v_60 = !(right_back_too_far);
      right_back_too_close = !(ir_left_b1);
      v_59 = !(right_back_too_close);
      right_back_correct = (v_59&&v_60);
      right_front_too_far = ir_left_f2;
      v_58 = !(right_front_too_far);
      right_front_too_close = !(ir_left_f1);
      v_57 = !(right_front_too_close);
      right_front_correct = (v_57&&v_58);
      front_free = ir_front;
      v_55 = !(left_line);
      switch (ck_4) {
        case Lab__St_1_CheckState:
          v_70 = (right_front_correct&&right_back_correct);
          if (v_70) {
            v_72 = true;
            v_71 = Lab__St_1_MoveForward;
          } else {
            v_72 = pnr_1;
            v_71 = Lab__St_1_CheckState;
          };
          v_69 = (right_front_too_far&&right_back_correct);
          if (v_69) {
            v_74 = true;
            v_73 = Lab__St_1_RightTurnSlow;
          } else {
            v_74 = v_72;
            v_73 = v_71;
          };
          v_68 = (right_front_too_close&&right_back_correct);
          if (v_68) {
            v_76 = true;
            v_75 = Lab__St_1_LeftTurnSlow;
          } else {
            v_76 = v_74;
            v_75 = v_73;
          };
          v_67 = (right_front_correct&&right_back_too_far);
          if (v_67) {
            v_78 = true;
            v_77 = Lab__St_1_LeftTurnSlow;
          } else {
            v_78 = v_76;
            v_77 = v_75;
          };
          v_66 = (right_front_correct&&right_back_too_close);
          if (v_66) {
            v_80 = true;
            v_79 = Lab__St_1_RightTurnSlow;
          } else {
            v_80 = v_78;
            v_79 = v_77;
          };
          v_65 = (right_front_too_far&&right_back_too_far);
          if (v_65) {
            v_82 = true;
            v_81 = Lab__St_1_MoveCloser;
          } else {
            v_82 = v_80;
            v_81 = v_79;
          };
          v_64 = (right_front_too_far&&right_back_too_close);
          if (v_64) {
            v_84 = true;
            v_83 = Lab__St_1_RightTurn;
          } else {
            v_84 = v_82;
            v_83 = v_81;
          };
          v_63 = (right_front_too_close&&right_back_too_close);
          if (v_63) {
            v_86 = true;
            v_85 = Lab__St_1_MoveAway;
          } else {
            v_86 = v_84;
            v_85 = v_83;
          };
          v_62 = (right_front_too_close&&right_back_too_far);
          if (v_62) {
            v_88 = true;
            v_87 = Lab__St_1_LeftTurn;
          } else {
            v_88 = v_86;
            v_87 = v_85;
          };
          v_61 = !(front_free);
          if (v_61) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab__St_1_Turn90Left;
          } else {
            r_3_St_1_CheckState = v_88;
            s_1_St_1_CheckState = v_87;
          };
          s_1 = s_1_St_1_CheckState;
          r_3 = r_3_St_1_CheckState;
          break;
        case Lab__St_1_Turn90Left:
          r_3_St_1_Turn90Left = pnr_1;
          s_1_St_1_Turn90Left = Lab__St_1_Turn90Left;
          s_1 = s_1_St_1_Turn90Left;
          r_3 = r_3_St_1_Turn90Left;
          break;
        case Lab__St_1_MoveAway:
          r_3_St_1_MoveAway = pnr_1;
          s_1_St_1_MoveAway = Lab__St_1_MoveAway;
          s_1 = s_1_St_1_MoveAway;
          r_3 = r_3_St_1_MoveAway;
          break;
        case Lab__St_1_MoveCloser:
          r_3_St_1_MoveCloser = pnr_1;
          s_1_St_1_MoveCloser = Lab__St_1_MoveCloser;
          s_1 = s_1_St_1_MoveCloser;
          r_3 = r_3_St_1_MoveCloser;
          break;
        case Lab__St_1_RightTurn:
          r_3_St_1_RightTurn = pnr_1;
          s_1_St_1_RightTurn = Lab__St_1_RightTurn;
          s_1 = s_1_St_1_RightTurn;
          r_3 = r_3_St_1_RightTurn;
          break;
        case Lab__St_1_LeftTurn:
          r_3_St_1_LeftTurn = pnr_1;
          s_1_St_1_LeftTurn = Lab__St_1_LeftTurn;
          s_1 = s_1_St_1_LeftTurn;
          r_3 = r_3_St_1_LeftTurn;
          break;
        case Lab__St_1_RightTurnSlow:
          r_3_St_1_RightTurnSlow = pnr_1;
          s_1_St_1_RightTurnSlow = Lab__St_1_RightTurnSlow;
          s_1 = s_1_St_1_RightTurnSlow;
          r_3 = r_3_St_1_RightTurnSlow;
          break;
        case Lab__St_1_LeftTurnSlow:
          r_3_St_1_LeftTurnSlow = pnr_1;
          s_1_St_1_LeftTurnSlow = Lab__St_1_LeftTurnSlow;
          s_1 = s_1_St_1_LeftTurnSlow;
          r_3 = r_3_St_1_LeftTurnSlow;
          break;
        case Lab__St_1_MoveForward:
          r_3_St_1_MoveForward = pnr_1;
          s_1_St_1_MoveForward = Lab__St_1_MoveForward;
          s_1 = s_1_St_1_MoveForward;
          r_3 = r_3_St_1_MoveForward;
          break;
        default:
          break;
      };
      ck_5 = s_1;
      switch (ck_5) {
        case Lab__St_1_CheckState:
          away_from_line_St_1_CheckState = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_CheckState = 0.000000;
          left_wheel_St_3_WallFollowing_St_1_CheckState = 0.000000;
          direction_St_3_WallFollowing_St_1_CheckState = 0;
          st_St_3_WallFollowing_St_1_CheckState = Lab__Error;
          nr_1_St_1_CheckState = false;
          ns_1_St_1_CheckState = Lab__St_1_CheckState;
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_CheckState;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_CheckState;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_CheckState;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_CheckState;
          away_from_line = away_from_line_St_1_CheckState;
          ns_1 = ns_1_St_1_CheckState;
          nr_1 = nr_1_St_1_CheckState;
          break;
        case Lab__St_1_Turn90Left:
          right_wheel_St_3_WallFollowing_St_1_Turn90Left = basespeed_obstacle;
          left_wheel_St_3_WallFollowing_St_1_Turn90Left = 0.000000;
          direction_St_3_WallFollowing_St_1_Turn90Left = 3;
          st_St_3_WallFollowing_St_1_Turn90Left = Lab__Turn90Left;
          v_107 = (r_5||r_3);
          if (self->v_106) {
            v_108 = true;
          } else {
            v_108 = v_107;
          };
          v_104 = (self->v_103+d_encoder_steps_right);
          v_101 = (r_5||r_3);
          if (self->v_100) {
            v_102 = true;
          } else {
            v_102 = v_101;
          };
          if (v_102) {
            sum_encoder_steps = 0.000000;
          } else {
            sum_encoder_steps = v_104;
          };
          v_105 = (9.425000*sum_encoder_steps);
          finished_turn = (184.200000<v_105);
          v_109 = (away_from_line_1||finished_turn);
          if (v_108) {
            away_from_line_St_1_Turn90Left = false;
          } else {
            away_from_line_St_1_Turn90Left = v_109;
          };
          if (finished_turn) {
            nr_1_St_1_Turn90Left = true;
            ns_1_St_1_Turn90Left = Lab__St_1_CheckState;
          } else {
            nr_1_St_1_Turn90Left = false;
            ns_1_St_1_Turn90Left = Lab__St_1_Turn90Left;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_Turn90Left;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_Turn90Left;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_Turn90Left;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_Turn90Left;
          away_from_line = away_from_line_St_1_Turn90Left;
          ns_1 = ns_1_St_1_Turn90Left;
          nr_1 = nr_1_St_1_Turn90Left;
          break;
        case Lab__St_1_MoveAway:
          away_from_line_St_1_MoveAway = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_MoveAway = basespeed_obstacle;
          v_98 = (basespeed_obstacle-motorspeed_left_min);
          v_99 = (v_98*move_closer_left);
          left_wheel_St_3_WallFollowing_St_1_MoveAway = (motorspeed_left_min+v_99);
          direction_St_3_WallFollowing_St_1_MoveAway = 2;
          st_St_3_WallFollowing_St_1_MoveAway = Lab__MoveAway;
          if (true) {
            nr_1_St_1_MoveAway = true;
          } else {
            nr_1_St_1_MoveAway = false;
          };
          if (true) {
            ns_1_St_1_MoveAway = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_MoveAway = Lab__St_1_MoveAway;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveAway;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveAway;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveAway;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveAway;
          away_from_line = away_from_line_St_1_MoveAway;
          ns_1 = ns_1_St_1_MoveAway;
          nr_1 = nr_1_St_1_MoveAway;
          break;
        case Lab__St_1_MoveCloser:
          away_from_line_St_1_MoveCloser = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_MoveCloser = (motorspeed_right_min*move_away_right);
          left_wheel_St_3_WallFollowing_St_1_MoveCloser = basespeed_obstacle;
          direction_St_3_WallFollowing_St_1_MoveCloser = 3;
          st_St_3_WallFollowing_St_1_MoveCloser = Lab__MoveCloser;
          if (true) {
            nr_1_St_1_MoveCloser = true;
          } else {
            nr_1_St_1_MoveCloser = false;
          };
          if (true) {
            ns_1_St_1_MoveCloser = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_MoveCloser = Lab__St_1_MoveCloser;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveCloser;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveCloser;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveCloser;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveCloser;
          away_from_line = away_from_line_St_1_MoveCloser;
          ns_1 = ns_1_St_1_MoveCloser;
          nr_1 = nr_1_St_1_MoveCloser;
          break;
        case Lab__St_1_RightTurn:
          away_from_line_St_1_RightTurn = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_RightTurn = 0.000000;
          v_96 = (motorspeed_left_max-motorspeed_left_min);
          v_97 = (v_96*right_turn_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_97);
          direction_St_3_WallFollowing_St_1_RightTurn = 3;
          st_St_3_WallFollowing_St_1_RightTurn = Lab__RightTurn;
          if (true) {
            nr_1_St_1_RightTurn = true;
          } else {
            nr_1_St_1_RightTurn = false;
          };
          if (true) {
            ns_1_St_1_RightTurn = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_RightTurn = Lab__St_1_RightTurn;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_RightTurn;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_RightTurn;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_RightTurn;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_RightTurn;
          away_from_line = away_from_line_St_1_RightTurn;
          ns_1 = ns_1_St_1_RightTurn;
          nr_1 = nr_1_St_1_RightTurn;
          break;
        case Lab__St_1_LeftTurn:
          away_from_line_St_1_LeftTurn = away_from_line_1;
          v_94 = (motorspeed_right_max-motorspeed_right_min);
          v_95 = (v_94*left_turn_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_95);
          left_wheel_St_3_WallFollowing_St_1_LeftTurn = 0.000000;
          direction_St_3_WallFollowing_St_1_LeftTurn = 2;
          st_St_3_WallFollowing_St_1_LeftTurn = Lab__LeftTurn;
          if (true) {
            nr_1_St_1_LeftTurn = true;
          } else {
            nr_1_St_1_LeftTurn = false;
          };
          if (true) {
            ns_1_St_1_LeftTurn = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_LeftTurn = Lab__St_1_LeftTurn;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_LeftTurn;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_LeftTurn;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_LeftTurn;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_LeftTurn;
          away_from_line = away_from_line_St_1_LeftTurn;
          ns_1 = ns_1_St_1_LeftTurn;
          nr_1 = nr_1_St_1_LeftTurn;
          break;
        case Lab__St_1_RightTurnSlow:
          away_from_line_St_1_RightTurnSlow = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_RightTurnSlow = 0.000000;
          v_92 = (motorspeed_left_max-motorspeed_left_min);
          v_93 = (v_92*right_turn_slow_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_93);
          direction_St_3_WallFollowing_St_1_RightTurnSlow = 3;
          st_St_3_WallFollowing_St_1_RightTurnSlow = Lab__RightTurnSlow;
          if (true) {
            nr_1_St_1_RightTurnSlow = true;
          } else {
            nr_1_St_1_RightTurnSlow = false;
          };
          if (true) {
            ns_1_St_1_RightTurnSlow = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_RightTurnSlow = Lab__St_1_RightTurnSlow;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_RightTurnSlow;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_RightTurnSlow;
          away_from_line = away_from_line_St_1_RightTurnSlow;
          ns_1 = ns_1_St_1_RightTurnSlow;
          nr_1 = nr_1_St_1_RightTurnSlow;
          break;
        case Lab__St_1_LeftTurnSlow:
          away_from_line_St_1_LeftTurnSlow = away_from_line_1;
          v_90 = (motorspeed_right_max-motorspeed_right_min);
          v_91 = (v_90*left_turn_slow_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_91);
          left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = motorspeed_left_min;
          direction_St_3_WallFollowing_St_1_LeftTurnSlow = 2;
          st_St_3_WallFollowing_St_1_LeftTurnSlow = Lab__LeftTurnSlow;
          if (true) {
            nr_1_St_1_LeftTurnSlow = true;
          } else {
            nr_1_St_1_LeftTurnSlow = false;
          };
          if (true) {
            ns_1_St_1_LeftTurnSlow = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_LeftTurnSlow = Lab__St_1_LeftTurnSlow;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_LeftTurnSlow;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_LeftTurnSlow;
          away_from_line = away_from_line_St_1_LeftTurnSlow;
          ns_1 = ns_1_St_1_LeftTurnSlow;
          nr_1 = nr_1_St_1_LeftTurnSlow;
          break;
        case Lab__St_1_MoveForward:
          away_from_line_St_1_MoveForward = away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          left_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          direction_St_3_WallFollowing_St_1_MoveForward = 1;
          st_St_3_WallFollowing_St_1_MoveForward = Lab__MoveForward;
          if (true) {
            nr_1_St_1_MoveForward = true;
          } else {
            nr_1_St_1_MoveForward = false;
          };
          if (true) {
            ns_1_St_1_MoveForward = Lab__St_1_CheckState;
          } else {
            ns_1_St_1_MoveForward = Lab__St_1_MoveForward;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveForward;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveForward;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveForward;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveForward;
          away_from_line = away_from_line_St_1_MoveForward;
          ns_1 = ns_1_St_1_MoveForward;
          nr_1 = nr_1_St_1_MoveForward;
          break;
        default:
          break;
      };
      v_56 = (v_55&&away_from_line);
      if (v_56) {
        nr_3_St_3_WallFollowing = true;
        ns_3_St_3_WallFollowing = Lab__St_3_TurnLeftEnd;
      } else {
        nr_3_St_3_WallFollowing = false;
        ns_3_St_3_WallFollowing = Lab__St_3_WallFollowing;
      };
      _out->left_wheel = left_wheel_St_3_WallFollowing;
      _out->right_wheel = right_wheel_St_3_WallFollowing;
      _out->direction = direction_St_3_WallFollowing;
      _out->st = st_St_3_WallFollowing;
      ns_3 = ns_3_St_3_WallFollowing;
      nr_3 = nr_3_St_3_WallFollowing;
      self->v_111 = away_from_line;
      self->v_110 = nr_1;
      self->v_89 = ns_1;
      break;
    case Lab__St_3_TurnLeftEnd:
      right_wheel_St_3_TurnLeftEnd = basespeed_left;
      left_wheel_St_3_TurnLeftEnd = (motorspeed_right_min*turn_right_end_right);
      direction_St_3_TurnLeftEnd = 3;
      st_St_3_TurnLeftEnd = Lab__TurnLeftEnd;
      nr_3_St_3_TurnLeftEnd = false;
      ns_3_St_3_TurnLeftEnd = Lab__St_3_TurnLeftEnd;
      _out->left_wheel = left_wheel_St_3_TurnLeftEnd;
      _out->right_wheel = right_wheel_St_3_TurnLeftEnd;
      _out->direction = direction_St_3_TurnLeftEnd;
      _out->st = st_St_3_TurnLeftEnd;
      ns_3 = ns_3_St_3_TurnLeftEnd;
      nr_3 = nr_3_St_3_TurnLeftEnd;
      break;
    case Lab__St_3_Stop:
      right_wheel_St_3_Stop = 0.000000;
      left_wheel_St_3_Stop = 0.000000;
      direction_St_3_Stop = 0;
      st_St_3_Stop = Lab__Stop;
      nr_3_St_3_Stop = false;
      ns_3_St_3_Stop = Lab__St_3_Stop;
      _out->left_wheel = left_wheel_St_3_Stop;
      _out->right_wheel = right_wheel_St_3_Stop;
      _out->direction = direction_St_3_Stop;
      _out->st = st_St_3_Stop;
      ns_3 = ns_3_St_3_Stop;
      nr_3 = nr_3_St_3_Stop;
      break;
    case Lab__St_3_Parking:
      if (r_5) {
        pnr_2 = false;
        ck_6 = Lab__St_2_Backwards;
      } else {
        pnr_2 = self->v_54;
        ck_6 = self->v_41;
      };
      switch (ck_6) {
        case Lab__St_2_Backwards:
          if (car_to_the_right) {
            r_4_St_2_Backwards = true;
            s_2_St_2_Backwards = Lab__St_2_Turn90Right;
          } else {
            r_4_St_2_Backwards = pnr_2;
            s_2_St_2_Backwards = Lab__St_2_Backwards;
          };
          s_2 = s_2_St_2_Backwards;
          r_4 = r_4_St_2_Backwards;
          break;
        case Lab__St_2_Turn90Right:
          r_4_St_2_Turn90Right = pnr_2;
          s_2_St_2_Turn90Right = Lab__St_2_Turn90Right;
          s_2 = s_2_St_2_Turn90Right;
          r_4 = r_4_St_2_Turn90Right;
          break;
        case Lab__St_2_Forward:
          r_4_St_2_Forward = pnr_2;
          s_2_St_2_Forward = Lab__St_2_Forward;
          s_2 = s_2_St_2_Forward;
          r_4 = r_4_St_2_Forward;
          break;
        default:
          break;
      };
      ck_7 = s_2;
      switch (ck_7) {
        case Lab__St_2_Backwards:
          right_wheel_St_3_Parking_St_2_Backwards = basespeed_parking;
          left_wheel_St_3_Parking_St_2_Backwards = basespeed_parking;
          direction_St_3_Parking_St_2_Backwards = 4;
          st_St_3_Parking_St_2_Backwards = Lab__Backwards;
          finished_move_St_2_Backwards = false;
          nr_2_St_2_Backwards = false;
          ns_2_St_2_Backwards = Lab__St_2_Backwards;
          left_wheel_St_3_Parking = left_wheel_St_3_Parking_St_2_Backwards;
          right_wheel_St_3_Parking = right_wheel_St_3_Parking_St_2_Backwards;
          direction_St_3_Parking = direction_St_3_Parking_St_2_Backwards;
          st_St_3_Parking = st_St_3_Parking_St_2_Backwards;
          finished_move = finished_move_St_2_Backwards;
          ns_2 = ns_2_St_2_Backwards;
          nr_2 = nr_2_St_2_Backwards;
          break;
        case Lab__St_2_Turn90Right:
          right_wheel_St_3_Parking_St_2_Turn90Right = motorspeed_right_parking;
          left_wheel_St_3_Parking_St_2_Turn90Right = motorspeed_left_parking;
          direction_St_3_Parking_St_2_Turn90Right = 3;
          st_St_3_Parking_St_2_Turn90Right = Lab__Turn90Right;
          v_52 = (self->v_51+d_encoder_steps_left);
          v_49 = (r_5||r_4);
          if (self->v_48) {
            v_50 = true;
          } else {
            v_50 = v_49;
          };
          if (v_50) {
            sum_encoder_steps_left = 0.000000;
          } else {
            sum_encoder_steps_left = v_52;
          };
          v_53 = (9.425000*sum_encoder_steps_left);
          finished_turn_1 = (204.200000<v_53);
          finished_move_St_2_Turn90Right = false;
          if (finished_turn_1) {
            nr_2_St_2_Turn90Right = true;
            ns_2_St_2_Turn90Right = Lab__St_2_Forward;
          } else {
            nr_2_St_2_Turn90Right = false;
            ns_2_St_2_Turn90Right = Lab__St_2_Turn90Right;
          };
          left_wheel_St_3_Parking = left_wheel_St_3_Parking_St_2_Turn90Right;
          right_wheel_St_3_Parking = right_wheel_St_3_Parking_St_2_Turn90Right;
          direction_St_3_Parking = direction_St_3_Parking_St_2_Turn90Right;
          st_St_3_Parking = st_St_3_Parking_St_2_Turn90Right;
          finished_move = finished_move_St_2_Turn90Right;
          ns_2 = ns_2_St_2_Turn90Right;
          nr_2 = nr_2_St_2_Turn90Right;
          break;
        case Lab__St_2_Forward:
          right_wheel_St_3_Parking_St_2_Forward = basespeed_parking;
          left_wheel_St_3_Parking_St_2_Forward = basespeed_parking;
          direction_St_3_Parking_St_2_Forward = 3;
          st_St_3_Parking_St_2_Forward = Lab__Forward;
          v_46 = (self->v_45+d_encoder_steps_left);
          v_43 = (r_5||r_4);
          if (self->v_42) {
            v_44 = true;
          } else {
            v_44 = v_43;
          };
          if (v_44) {
            sum_encoder_steps_left_1 = 0.000000;
          } else {
            sum_encoder_steps_left_1 = v_46;
          };
          v_47 = (9.425000*sum_encoder_steps_left_1);
          finished_move_St_2_Forward = (last_forward_mm>v_47);
          nr_2_St_2_Forward = false;
          ns_2_St_2_Forward = Lab__St_2_Forward;
          left_wheel_St_3_Parking = left_wheel_St_3_Parking_St_2_Forward;
          right_wheel_St_3_Parking = right_wheel_St_3_Parking_St_2_Forward;
          direction_St_3_Parking = direction_St_3_Parking_St_2_Forward;
          st_St_3_Parking = st_St_3_Parking_St_2_Forward;
          finished_move = finished_move_St_2_Forward;
          ns_2 = ns_2_St_2_Forward;
          nr_2 = nr_2_St_2_Forward;
          break;
        default:
          break;
      };
      if (finished_move) {
        nr_3_St_3_Parking = true;
        ns_3_St_3_Parking = Lab__St_3_Stop;
      } else {
        nr_3_St_3_Parking = false;
        ns_3_St_3_Parking = Lab__St_3_Parking;
      };
      _out->left_wheel = left_wheel_St_3_Parking;
      _out->right_wheel = right_wheel_St_3_Parking;
      _out->direction = direction_St_3_Parking;
      _out->st = st_St_3_Parking;
      ns_3 = ns_3_St_3_Parking;
      nr_3 = nr_3_St_3_Parking;
      self->v_54 = nr_2;
      self->v_41 = ns_2;
      break;
    default:
      break;
  };
  self->car_to_the_right_1 = car_to_the_right;
  self->first_car_1 = first_car;
  self->l_1 = l;
  self->r_1 = r;
  self->alligned_1 = alligned;
  self->left_m_1 = left_m;
  self->left_line_1 = left_line;
  self->pnr_3 = nr_3;
  self->ck = ns_3;
  self->v_36 = first_car;
  self->v_32 = false;
  switch (ck_1) {
    case Lab__St_3_LineFollow:
      switch (ck_3) {
        case Lab__St_OnLine:
          self->v_164 = parking_distance;
          self->v_159 = false;
          self->v_153 = error;
          self->v_150 = false;
          self->v_148 = i;
          self->v_145 = false;
          break;
        case Lab__St_LostLine:
          self->v_138 = parking_distance;
          self->v_135 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_WallFollowing:
      switch (ck_5) {
        case Lab__St_1_Turn90Left:
          self->v_106 = false;
          self->v_103 = sum_encoder_steps;
          self->v_100 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_Parking:
      switch (ck_7) {
        case Lab__St_2_Turn90Right:
          self->v_51 = sum_encoder_steps_left;
          self->v_48 = false;
          break;
        case Lab__St_2_Forward:
          self->v_45 = sum_encoder_steps_left_1;
          self->v_42 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

