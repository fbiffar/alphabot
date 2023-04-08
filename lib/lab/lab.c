/* --- Generated the 8/4/2023 at 11:36 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_210 = false;
  self->v_162 = Lab__St_OnLine;
  self->v_145 = true;
  self->v_139 = false;
  self->v_89 = Lab__St_1_CheckState;
  self->v_54 = false;
  self->v_41 = Lab__St_2_Backwards;
  self->pnr_3 = false;
  self->ck = Lab__St_3_LineFollow;
  self->v_32 = true;
  self->v_187 = true;
  self->v_178 = true;
  self->v_173 = true;
  self->v_163 = true;
  self->v_134 = true;
  self->v_128 = true;
  self->v_122 = true;
  self->v_118 = true;
  self->v_112 = true;
  self->v_106 = true;
  self->v_100 = true;
  self->v_94 = true;
  self->v_90 = true;
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
  int r_5_St_3_TurnRightEnd;
  Lab__st_3 s_3_St_3_TurnRightEnd;
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
  int v_92;
  int v_91;
  float v_99;
  float v_98;
  int v_96;
  int v_95;
  float v_105;
  float v_104;
  int v_102;
  int v_101;
  float v_111;
  float v_110;
  int v_108;
  int v_107;
  float v_117;
  float v_116;
  int v_114;
  int v_113;
  int v_120;
  int v_119;
  float v_127;
  float v_126;
  int v_124;
  int v_123;
  int v_138;
  int v_136;
  int v_135;
  float v_133;
  float v_132;
  int v_130;
  int v_129;
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
  int front_free;
  int right_front_too_close;
  int right_front_too_far;
  int right_back_too_close;
  int right_back_too_far;
  int right_front_correct;
  int right_back_correct;
  int away_from_line;
  float v_148;
  int v_146;
  int v_144;
  Lab__st_3 v_143;
  int v_142;
  int v_141;
  int v_140;
  float counter;
  int v_161;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  float v_170;
  float v_169;
  float v_168;
  float v_167;
  int v_165;
  int v_164;
  float v_209;
  float v_208;
  int v_207;
  float v_206;
  int v_205;
  float v_204;
  float v_203;
  float v_202;
  int v_201;
  float v_200;
  int v_199;
  float v_198;
  float v_197;
  float v_196;
  float v_195;
  float v_194;
  float v_193;
  int v_191;
  int v_190;
  int v_189;
  int v_188;
  float v_186;
  float v_185;
  float v_184;
  float v_183;
  float v_182;
  int v_180;
  int v_179;
  float v_177;
  int v_175;
  int v_174;
  float v_172;
  float v_171;
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
  int v_160;
  Lab__st_3 v_159;
  int v_158;
  int v_157;
  int v_156;
  int v_155;
  int v_154;
  int v_153;
  int v_152;
  int v_151;
  int v_150;
  int v_149;
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
  int nr_3_St_3_TurnRightEnd;
  Lab__st_3 ns_3_St_3_TurnRightEnd;
  Lab__stateName st_St_3_TurnRightEnd;
  int direction_St_3_TurnRightEnd;
  float right_wheel_St_3_TurnRightEnd;
  float left_wheel_St_3_TurnRightEnd;
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
    case Lab__St_3_TurnRightEnd:
      if (alligned) {
        r_5_St_3_TurnRightEnd = true;
        s_3_St_3_TurnRightEnd = Lab__St_3_LineFollow;
      } else {
        r_5_St_3_TurnRightEnd = self->pnr_3;
        s_3_St_3_TurnRightEnd = Lab__St_3_TurnRightEnd;
      };
      s_3 = s_3_St_3_TurnRightEnd;
      r_5 = r_5_St_3_TurnRightEnd;
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
        pnr = self->v_210;
        ck_2 = self->v_162;
      };
      v_157 = (r1>stop_threshold);
      v_155 = (m>stop_threshold);
      v_153 = (l1>stop_threshold);
      v_152 = (white_line==false);
      v_154 = (v_152&&v_153);
      v_156 = (v_154&&v_155);
      v_158 = (v_156&&v_157);
      if (v_158) {
        v_160 = true;
        v_159 = Lab__St_3_Stop;
      } else {
        v_160 = false;
        v_159 = Lab__St_3_LineFollow;
      };
      v_149 = (white_line==false);
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
          v_161 = !(left_m);
          if (v_161) {
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
          v_206 = (basespeed_right-motorspeed_right_max);
          v_204 = (basespeed_right-motorspeed_right_min);
          v_200 = (motorspeed_left_min-basespeed_left);
          v_198 = (motorspeed_left_max-basespeed_left);
          direction_St_3_LineFollow_St_OnLine = 1;
          st_St_3_LineFollow_St_OnLine = Lab__OnLine;
          v_193 = (d_encoder_steps_right+d_encoder_steps_left);
          v_194 = (v_193/2.000000);
          v_195 = (v_194*9.425000);
          v_196 = (self->v_192+v_195);
          v_190 = !(car_to_the_right);
          v_191 = (first_car&&v_190);
          if (v_191) {
            v_197 = v_196;
          } else {
            v_197 = 0.000000;
          };
          v_188 = (r_5||r_2);
          if (self->v_187) {
            v_189 = true;
          } else {
            v_189 = v_188;
          };
          if (v_189) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_197;
          };
          v_179 = (r_5||r_2);
          if (self->v_178) {
            v_180 = true;
          } else {
            v_180 = v_179;
          };
          v_174 = (r_5||r_2);
          if (self->v_173) {
            v_175 = true;
          } else {
            v_175 = v_174;
          };
          v_172 = (l-r);
          v_171 = (r-l);
          if (white_line) {
            error = v_171;
          } else {
            error = v_172;
          };
          v_182 = (error-self->v_181);
          if (v_180) {
            d = error;
          } else {
            d = v_182;
          };
          v_186 = (d*kD);
          v_177 = (self->v_176+error);
          if (v_175) {
            i = error;
          } else {
            i = v_177;
          };
          v_184 = (i*kI);
          p = error;
          v_183 = (p*kP);
          v_185 = (v_183+v_184);
          correction = (v_185+v_186);
          v_208 = (basespeed_right-correction);
          v_207 = (correction<v_206);
          if (v_207) {
            v_209 = motorspeed_right_max;
          } else {
            v_209 = v_208;
          };
          v_205 = (correction>v_204);
          if (v_205) {
            right_wheel_St_3_LineFollow_St_OnLine = motorspeed_right_min;
          } else {
            right_wheel_St_3_LineFollow_St_OnLine = v_209;
          };
          v_202 = (basespeed_left+correction);
          v_201 = (correction<v_200);
          if (v_201) {
            v_203 = motorspeed_left_min;
          } else {
            v_203 = v_202;
          };
          v_199 = (correction>v_198);
          if (v_199) {
            left_wheel_St_3_LineFollow_St_OnLine = motorspeed_left_max;
          } else {
            left_wheel_St_3_LineFollow_St_OnLine = v_203;
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
          v_169 = (motorspeed_right_max-motorspeed_right_min);
          v_170 = (v_169*backward_factor);
          right_wheel_St_3_LineFollow_St_LostLine = (motorspeed_right_min+v_170);
          v_167 = (motorspeed_left_max-motorspeed_left_min);
          v_168 = (v_167*backward_factor);
          left_wheel_St_3_LineFollow_St_LostLine = (motorspeed_left_min+v_168);
          direction_St_3_LineFollow_St_LostLine = 4;
          st_St_3_LineFollow_St_LostLine = Lab__LostLine;
          v_164 = (r_5||r_2);
          if (self->v_163) {
            v_165 = true;
          } else {
            v_165 = v_164;
          };
          if (v_165) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_166;
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
      v_150 = (parking_distance>=min_parking_space);
      v_151 = (v_149&&v_150);
      if (v_151) {
        nr_3_St_3_LineFollow = true;
        ns_3_St_3_LineFollow = Lab__St_3_Parking;
      } else {
        nr_3_St_3_LineFollow = v_160;
        ns_3_St_3_LineFollow = v_159;
      };
      _out->left_wheel = left_wheel_St_3_LineFollow;
      _out->right_wheel = right_wheel_St_3_LineFollow;
      _out->direction = direction_St_3_LineFollow;
      _out->st = st_St_3_LineFollow;
      ns_3 = ns_3_St_3_LineFollow;
      nr_3 = nr_3_St_3_LineFollow;
      self->parking_distance_1 = parking_distance;
      self->v_210 = nr;
      self->v_162 = ns;
      break;
    case Lab__St_3_ObstacleFollowing:
      right_wheel_St_3_ObstacleFollowing = 0.000000;
      left_wheel_St_3_ObstacleFollowing = 0.000000;
      direction_St_3_ObstacleFollowing = 0;
      st_St_3_ObstacleFollowing = Lab__ObstacleFollowing;
      v_148 = (self->v_147+1.000000);
      if (self->v_145) {
        v_146 = true;
      } else {
        v_146 = r_5;
      };
      if (v_146) {
        counter = 0.000000;
      } else {
        counter = v_148;
      };
      if (ir_front) {
        v_144 = true;
        v_143 = Lab__St_3_LineFollow;
      } else {
        v_144 = false;
        v_143 = Lab__St_3_ObstacleFollowing;
      };
      v_141 = !(ir_front);
      v_140 = (counter>=waiting_threshold);
      v_142 = (v_140&&v_141);
      if (v_142) {
        nr_3_St_3_ObstacleFollowing = true;
        ns_3_St_3_ObstacleFollowing = Lab__St_3_WallFollowing;
      } else {
        nr_3_St_3_ObstacleFollowing = v_144;
        ns_3_St_3_ObstacleFollowing = v_143;
      };
      _out->left_wheel = left_wheel_St_3_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_3_ObstacleFollowing;
      _out->direction = direction_St_3_ObstacleFollowing;
      _out->st = st_St_3_ObstacleFollowing;
      ns_3 = ns_3_St_3_ObstacleFollowing;
      nr_3 = nr_3_St_3_ObstacleFollowing;
      self->v_147 = counter;
      self->v_145 = false;
      break;
    case Lab__St_3_WallFollowing:
      if (r_5) {
        pnr_1 = false;
        ck_4 = Lab__St_1_CheckState;
      } else {
        pnr_1 = self->v_139;
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
          away_from_line_St_1_CheckState = self->away_from_line_1;
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
          v_135 = (r_5||r_3);
          if (self->v_134) {
            v_136 = true;
          } else {
            v_136 = v_135;
          };
          right_wheel_St_3_WallFollowing_St_1_Turn90Left = basespeed_obstacle;
          left_wheel_St_3_WallFollowing_St_1_Turn90Left = 0.000000;
          direction_St_3_WallFollowing_St_1_Turn90Left = 3;
          st_St_3_WallFollowing_St_1_Turn90Left = Lab__Turn90Left;
          v_132 = (self->v_131+d_encoder_steps_right);
          v_129 = (r_5||r_3);
          if (self->v_128) {
            v_130 = true;
          } else {
            v_130 = v_129;
          };
          if (v_130) {
            sum_encoder_steps = 0.000000;
          } else {
            sum_encoder_steps = v_132;
          };
          v_133 = (9.425000*sum_encoder_steps);
          finished_turn = (184.200000<v_133);
          v_138 = (self->v_137||finished_turn);
          if (v_136) {
            away_from_line_St_1_Turn90Left = false;
          } else {
            away_from_line_St_1_Turn90Left = v_138;
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
          right_wheel_St_3_WallFollowing_St_1_MoveAway = basespeed_obstacle;
          v_126 = (basespeed_obstacle-motorspeed_left_min);
          v_127 = (v_126*move_closer_left);
          left_wheel_St_3_WallFollowing_St_1_MoveAway = (motorspeed_left_min+v_127);
          direction_St_3_WallFollowing_St_1_MoveAway = 2;
          st_St_3_WallFollowing_St_1_MoveAway = Lab__MoveAway;
          v_123 = (r_5||r_3);
          if (self->v_122) {
            v_124 = true;
          } else {
            v_124 = v_123;
          };
          if (v_124) {
            away_from_line_St_1_MoveAway = false;
          } else {
            away_from_line_St_1_MoveAway = self->v_125;
          };
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
          right_wheel_St_3_WallFollowing_St_1_MoveCloser = (motorspeed_right_min*move_away_right);
          left_wheel_St_3_WallFollowing_St_1_MoveCloser = basespeed_obstacle;
          direction_St_3_WallFollowing_St_1_MoveCloser = 3;
          st_St_3_WallFollowing_St_1_MoveCloser = Lab__MoveCloser;
          v_119 = (r_5||r_3);
          if (self->v_118) {
            v_120 = true;
          } else {
            v_120 = v_119;
          };
          if (v_120) {
            away_from_line_St_1_MoveCloser = false;
          } else {
            away_from_line_St_1_MoveCloser = self->v_121;
          };
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
          right_wheel_St_3_WallFollowing_St_1_RightTurn = 0.000000;
          v_116 = (motorspeed_left_max-motorspeed_left_min);
          v_117 = (v_116*right_turn_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_117);
          direction_St_3_WallFollowing_St_1_RightTurn = 3;
          st_St_3_WallFollowing_St_1_RightTurn = Lab__RightTurn;
          v_113 = (r_5||r_3);
          if (self->v_112) {
            v_114 = true;
          } else {
            v_114 = v_113;
          };
          if (v_114) {
            away_from_line_St_1_RightTurn = false;
          } else {
            away_from_line_St_1_RightTurn = self->v_115;
          };
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
          v_110 = (motorspeed_right_max-motorspeed_right_min);
          v_111 = (v_110*left_turn_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_111);
          left_wheel_St_3_WallFollowing_St_1_LeftTurn = 0.000000;
          direction_St_3_WallFollowing_St_1_LeftTurn = 2;
          st_St_3_WallFollowing_St_1_LeftTurn = Lab__LeftTurn;
          v_107 = (r_5||r_3);
          if (self->v_106) {
            v_108 = true;
          } else {
            v_108 = v_107;
          };
          if (v_108) {
            away_from_line_St_1_LeftTurn = false;
          } else {
            away_from_line_St_1_LeftTurn = self->v_109;
          };
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
          right_wheel_St_3_WallFollowing_St_1_RightTurnSlow = 0.000000;
          v_104 = (motorspeed_left_max-motorspeed_left_min);
          v_105 = (v_104*right_turn_slow_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_105);
          direction_St_3_WallFollowing_St_1_RightTurnSlow = 3;
          st_St_3_WallFollowing_St_1_RightTurnSlow = Lab__RightTurnSlow;
          v_101 = (r_5||r_3);
          if (self->v_100) {
            v_102 = true;
          } else {
            v_102 = v_101;
          };
          if (v_102) {
            away_from_line_St_1_RightTurnSlow = false;
          } else {
            away_from_line_St_1_RightTurnSlow = self->v_103;
          };
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
          v_98 = (motorspeed_right_max-motorspeed_right_min);
          v_99 = (v_98*left_turn_slow_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_99);
          left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = motorspeed_left_min;
          direction_St_3_WallFollowing_St_1_LeftTurnSlow = 2;
          st_St_3_WallFollowing_St_1_LeftTurnSlow = Lab__LeftTurnSlow;
          v_95 = (r_5||r_3);
          if (self->v_94) {
            v_96 = true;
          } else {
            v_96 = v_95;
          };
          if (v_96) {
            away_from_line_St_1_LeftTurnSlow = false;
          } else {
            away_from_line_St_1_LeftTurnSlow = self->v_97;
          };
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
          right_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          left_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          direction_St_3_WallFollowing_St_1_MoveForward = 1;
          st_St_3_WallFollowing_St_1_MoveForward = Lab__MoveForward;
          v_91 = (r_5||r_3);
          if (self->v_90) {
            v_92 = true;
          } else {
            v_92 = v_91;
          };
          if (v_92) {
            away_from_line_St_1_MoveForward = false;
          } else {
            away_from_line_St_1_MoveForward = self->v_93;
          };
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
        ns_3_St_3_WallFollowing = Lab__St_3_TurnRightEnd;
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
      self->away_from_line_1 = away_from_line;
      self->v_139 = nr_1;
      self->v_89 = ns_1;
      break;
    case Lab__St_3_TurnRightEnd:
      right_wheel_St_3_TurnRightEnd = (motorspeed_right_min*turn_right_end_right);
      left_wheel_St_3_TurnRightEnd = basespeed_left;
      direction_St_3_TurnRightEnd = 3;
      st_St_3_TurnRightEnd = Lab__TurnRightEnd;
      nr_3_St_3_TurnRightEnd = false;
      ns_3_St_3_TurnRightEnd = Lab__St_3_TurnRightEnd;
      _out->left_wheel = left_wheel_St_3_TurnRightEnd;
      _out->right_wheel = right_wheel_St_3_TurnRightEnd;
      _out->direction = direction_St_3_TurnRightEnd;
      _out->st = st_St_3_TurnRightEnd;
      ns_3 = ns_3_St_3_TurnRightEnd;
      nr_3 = nr_3_St_3_TurnRightEnd;
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
          self->v_192 = parking_distance;
          self->v_187 = false;
          self->v_181 = error;
          self->v_178 = false;
          self->v_176 = i;
          self->v_173 = false;
          break;
        case Lab__St_LostLine:
          self->v_166 = parking_distance;
          self->v_163 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_WallFollowing:
      switch (ck_5) {
        case Lab__St_1_Turn90Left:
          self->v_137 = away_from_line;
          self->v_134 = false;
          self->v_131 = sum_encoder_steps;
          self->v_128 = false;
          break;
        case Lab__St_1_MoveAway:
          self->v_125 = away_from_line;
          self->v_122 = false;
          break;
        case Lab__St_1_MoveCloser:
          self->v_121 = away_from_line;
          self->v_118 = false;
          break;
        case Lab__St_1_RightTurn:
          self->v_115 = away_from_line;
          self->v_112 = false;
          break;
        case Lab__St_1_LeftTurn:
          self->v_109 = away_from_line;
          self->v_106 = false;
          break;
        case Lab__St_1_RightTurnSlow:
          self->v_103 = away_from_line;
          self->v_100 = false;
          break;
        case Lab__St_1_LeftTurnSlow:
          self->v_97 = away_from_line;
          self->v_94 = false;
          break;
        case Lab__St_1_MoveForward:
          self->v_93 = away_from_line;
          self->v_90 = false;
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

