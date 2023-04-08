/* --- Generated the 8/4/2023 at 16:56 --- */
/* --- heptagon compiler, version 1.05.00 (compiled tue. jan. 10 17:5:19 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_227 = false;
  self->v_173 = Lab__St_OnLine;
  self->v_154 = true;
  self->v_148 = false;
  self->v_127 = Lab__St_1_CheckState;
  self->v_94 = true;
  self->v_77 = true;
  self->v_76 = false;
  self->v_63 = Lab__St_2_Backwards;
  self->white_line_1 = false;
  self->pnr_3 = false;
  self->ck = Lab__St_3_LineFollow;
  self->v_32 = true;
  self->v_204 = true;
  self->v_195 = true;
  self->v_190 = true;
  self->v_180 = true;
  self->v_175 = true;
  self->v_144 = true;
  self->v_138 = true;
  self->v_70 = true;
  self->v_64 = true;
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
                          float d_encoder_steps_right,
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
  
  int v_62;
  int v_61;
  int v_60;
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
  float v_69;
  float v_68;
  int v_66;
  int v_65;
  float sum_encoder_steps_left_1;
  float v_75;
  float v_74;
  int v_72;
  int v_71;
  float sum_encoder_steps_left;
  int finished_turn_2;
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
  float v_81;
  float v_80;
  int v_78;
  float sum_encoder_steps_1;
  int finished_turn_1;
  int v_126;
  Lab__st_1 v_125;
  int v_124;
  Lab__st_1 v_123;
  int v_122;
  Lab__st_1 v_121;
  int v_120;
  Lab__st_1 v_119;
  int v_118;
  Lab__st_1 v_117;
  int v_116;
  Lab__st_1 v_115;
  int v_114;
  Lab__st_1 v_113;
  int v_112;
  Lab__st_1 v_111;
  int v_110;
  Lab__st_1 v_109;
  int v_108;
  int v_107;
  int v_106;
  int v_105;
  int v_104;
  int v_103;
  int v_102;
  int v_101;
  int v_100;
  int v_99;
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
  float v_129;
  float v_128;
  float v_131;
  float v_130;
  float v_133;
  float v_132;
  float v_135;
  float v_134;
  float v_137;
  float v_136;
  int v_147;
  int v_146;
  int v_145;
  float v_143;
  float v_142;
  int v_140;
  int v_139;
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
  float v_98;
  float v_97;
  float v_96;
  int v_95;
  int v_93;
  int v_92;
  int v_91;
  int v_90;
  int v_89;
  int v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
  int v_83;
  int v_82;
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
  int back_online;
  int away_from_line;
  float diff_steps;
  float v_157;
  int v_155;
  int v_153;
  Lab__st_3 v_152;
  int v_151;
  int v_150;
  int v_149;
  float counter_1;
  int v_170;
  int v_172;
  Lab__st v_171;
  int r_2_St_Tcross;
  Lab__st s_St_Tcross;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  int v_179;
  int v_177;
  int v_176;
  int v_174;
  int counter;
  float v_187;
  float v_186;
  float v_185;
  float v_184;
  int v_182;
  int v_181;
  float v_226;
  float v_225;
  int v_224;
  float v_223;
  int v_222;
  float v_221;
  float v_220;
  float v_219;
  int v_218;
  float v_217;
  int v_216;
  float v_215;
  float v_214;
  float v_213;
  float v_212;
  float v_211;
  float v_210;
  int v_208;
  int v_207;
  int v_206;
  int v_205;
  float v_203;
  float v_202;
  float v_201;
  float v_200;
  float v_199;
  int v_197;
  int v_196;
  float v_194;
  int v_192;
  int v_191;
  float v_189;
  float v_188;
  float error;
  float p;
  float i;
  float d;
  float correction;
  int nr_St_Tcross;
  Lab__st ns_St_Tcross;
  float parking_distance_St_Tcross;
  Lab__stateName st_St_3_LineFollow_St_Tcross;
  int direction_St_3_LineFollow_St_Tcross;
  float right_wheel_St_3_LineFollow_St_Tcross;
  float left_wheel_St_3_LineFollow_St_Tcross;
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
  int v_169;
  Lab__st_3 v_168;
  int v_167;
  int v_166;
  int v_165;
  int v_164;
  int v_163;
  int v_162;
  int v_161;
  int v_160;
  int v_159;
  int v_158;
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
  int v_59;
  int v_58;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  int v_52;
  int v_51;
  int v_50;
  int v_49;
  int v_48;
  int v_47;
  int v_46;
  int v_45;
  int v_44;
  int v_43;
  int v_42;
  int v_41;
  int v_40;
  int v_39;
  int v_38;
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
  int white_line;
  int white_t_cross;
  v_58 = (r2>line_threshold_white);
  v_56 = (r1>line_threshold_white);
  v_54 = (m>line_threshold_white);
  v_52 = (l1>line_threshold_white);
  v_51 = (l2>line_threshold_white);
  v_53 = (v_51&&v_52);
  v_55 = (v_53&&v_54);
  v_57 = (v_55&&v_56);
  v_59 = (v_57&&v_58);
  v_48 = (m>line_threshold_white);
  v_46 = (l2<line_threshold_black);
  v_45 = (r2<line_threshold_black);
  v_47 = (v_45&&v_46);
  v_49 = (v_47&&v_48);
  if (v_49) {
    v_50 = true;
  } else {
    v_50 = self->white_line_1;
  };
  v_42 = (m<line_threshold_black);
  v_40 = (l2>line_threshold_white);
  v_39 = (r2>line_threshold_white);
  v_41 = (v_39&&v_40);
  v_43 = (v_41&&v_42);
  if (v_43) {
    v_44 = false;
  } else {
    v_44 = self->white_line_1;
  };
  v_38 = (self->white_line_1==true);
  if (v_38) {
    white_line = v_44;
  } else {
    white_line = v_50;
  };
  white_t_cross = (v_59&&white_line);
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
      v_61 = !(ir_front);
      v_60 = (white_line==true);
      v_62 = (v_60&&v_61);
      if (v_62) {
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
      r_5_St_3_TurnLeftEnd = self->pnr_3;
      s_3_St_3_TurnLeftEnd = Lab__St_3_TurnLeftEnd;
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
        pnr = self->v_227;
        ck_2 = self->v_173;
      };
      v_166 = (r1>stop_threshold);
      v_164 = (m>stop_threshold);
      v_162 = (l1>stop_threshold);
      v_161 = (white_line==false);
      v_163 = (v_161&&v_162);
      v_165 = (v_163&&v_164);
      v_167 = (v_165&&v_166);
      if (v_167) {
        v_169 = true;
        v_168 = Lab__St_3_Stop;
      } else {
        v_169 = false;
        v_168 = Lab__St_3_LineFollow;
      };
      v_158 = (white_line==false);
      switch (ck_2) {
        case Lab__St_OnLine:
          if (white_t_cross) {
            v_172 = true;
          } else {
            v_172 = pnr;
          };
          if (left_line) {
            r_2_St_OnLine = true;
          } else {
            r_2_St_OnLine = v_172;
          };
          if (white_t_cross) {
            v_171 = Lab__St_Tcross;
          } else {
            v_171 = Lab__St_OnLine;
          };
          if (left_line) {
            s_St_OnLine = Lab__St_LostLine;
          } else {
            s_St_OnLine = v_171;
          };
          s = s_St_OnLine;
          r_2 = r_2_St_OnLine;
          break;
        case Lab__St_LostLine:
          v_170 = !(left_m);
          if (v_170) {
            r_2_St_LostLine = true;
            s_St_LostLine = Lab__St_OnLine;
          } else {
            r_2_St_LostLine = pnr;
            s_St_LostLine = Lab__St_LostLine;
          };
          s = s_St_LostLine;
          r_2 = r_2_St_LostLine;
          break;
        case Lab__St_Tcross:
          r_2_St_Tcross = pnr;
          s_St_Tcross = Lab__St_Tcross;
          s = s_St_Tcross;
          r_2 = r_2_St_Tcross;
          break;
        default:
          break;
      };
      ck_3 = s;
      switch (ck_3) {
        case Lab__St_OnLine:
          v_223 = (basespeed_right-motorspeed_right_max);
          v_221 = (basespeed_right-motorspeed_right_min);
          v_217 = (motorspeed_left_min-basespeed_left);
          v_215 = (motorspeed_left_max-basespeed_left);
          direction_St_3_LineFollow_St_OnLine = 1;
          st_St_3_LineFollow_St_OnLine = Lab__OnLine;
          v_210 = (d_encoder_steps_right+d_encoder_steps_left);
          v_211 = (v_210/2.000000);
          v_212 = (v_211*9.425000);
          v_213 = (self->v_209+v_212);
          v_207 = !(car_to_the_right);
          v_208 = (first_car&&v_207);
          if (v_208) {
            v_214 = v_213;
          } else {
            v_214 = 0.000000;
          };
          v_205 = (r_5||r_2);
          if (self->v_204) {
            v_206 = true;
          } else {
            v_206 = v_205;
          };
          if (v_206) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_214;
          };
          v_196 = (r_5||r_2);
          if (self->v_195) {
            v_197 = true;
          } else {
            v_197 = v_196;
          };
          v_191 = (r_5||r_2);
          if (self->v_190) {
            v_192 = true;
          } else {
            v_192 = v_191;
          };
          v_189 = (l-r);
          v_188 = (r-l);
          if (white_line) {
            error = v_188;
          } else {
            error = v_189;
          };
          v_199 = (error-self->v_198);
          if (v_197) {
            d = error;
          } else {
            d = v_199;
          };
          v_203 = (d*kD);
          v_194 = (self->v_193+error);
          if (v_192) {
            i = error;
          } else {
            i = v_194;
          };
          v_201 = (i*kI);
          p = error;
          v_200 = (p*kP);
          v_202 = (v_200+v_201);
          correction = (v_202+v_203);
          v_225 = (basespeed_right-correction);
          v_224 = (correction<v_223);
          if (v_224) {
            v_226 = motorspeed_right_max;
          } else {
            v_226 = v_225;
          };
          v_222 = (correction>v_221);
          if (v_222) {
            right_wheel_St_3_LineFollow_St_OnLine = motorspeed_right_min;
          } else {
            right_wheel_St_3_LineFollow_St_OnLine = v_226;
          };
          v_219 = (basespeed_left+correction);
          v_218 = (correction<v_217);
          if (v_218) {
            v_220 = motorspeed_left_min;
          } else {
            v_220 = v_219;
          };
          v_216 = (correction>v_215);
          if (v_216) {
            left_wheel_St_3_LineFollow_St_OnLine = motorspeed_left_max;
          } else {
            left_wheel_St_3_LineFollow_St_OnLine = v_220;
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
          v_186 = (motorspeed_right_max-motorspeed_right_min);
          v_187 = (v_186*backward_factor);
          right_wheel_St_3_LineFollow_St_LostLine = (motorspeed_right_min+v_187);
          v_184 = (motorspeed_left_max-motorspeed_left_min);
          v_185 = (v_184*backward_factor);
          left_wheel_St_3_LineFollow_St_LostLine = (motorspeed_left_min+v_185);
          direction_St_3_LineFollow_St_LostLine = 4;
          st_St_3_LineFollow_St_LostLine = Lab__LostLine;
          v_181 = (r_5||r_2);
          if (self->v_180) {
            v_182 = true;
          } else {
            v_182 = v_181;
          };
          if (v_182) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_183;
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
        case Lab__St_Tcross:
          parking_distance_St_Tcross = self->parking_distance_1;
          right_wheel_St_3_LineFollow_St_Tcross = basespeed_right;
          left_wheel_St_3_LineFollow_St_Tcross = 0.000000;
          direction_St_3_LineFollow_St_Tcross = 2;
          st_St_3_LineFollow_St_Tcross = Lab__Tcross;
          v_179 = (self->v_178+1);
          v_176 = (r_5||r_2);
          if (self->v_175) {
            v_177 = true;
          } else {
            v_177 = v_176;
          };
          if (v_177) {
            counter = 0;
          } else {
            counter = v_179;
          };
          v_174 = (counter>4);
          if (v_174) {
            nr_St_Tcross = true;
            ns_St_Tcross = Lab__St_OnLine;
          } else {
            nr_St_Tcross = false;
            ns_St_Tcross = Lab__St_Tcross;
          };
          left_wheel_St_3_LineFollow = left_wheel_St_3_LineFollow_St_Tcross;
          right_wheel_St_3_LineFollow = right_wheel_St_3_LineFollow_St_Tcross;
          direction_St_3_LineFollow = direction_St_3_LineFollow_St_Tcross;
          st_St_3_LineFollow = st_St_3_LineFollow_St_Tcross;
          parking_distance = parking_distance_St_Tcross;
          ns = ns_St_Tcross;
          nr = nr_St_Tcross;
          break;
        default:
          break;
      };
      v_159 = (parking_distance>=min_parking_space);
      v_160 = (v_158&&v_159);
      if (v_160) {
        nr_3_St_3_LineFollow = true;
        ns_3_St_3_LineFollow = Lab__St_3_Parking;
      } else {
        nr_3_St_3_LineFollow = v_169;
        ns_3_St_3_LineFollow = v_168;
      };
      _out->left_wheel = left_wheel_St_3_LineFollow;
      _out->right_wheel = right_wheel_St_3_LineFollow;
      _out->direction = direction_St_3_LineFollow;
      _out->st = st_St_3_LineFollow;
      ns_3 = ns_3_St_3_LineFollow;
      nr_3 = nr_3_St_3_LineFollow;
      self->parking_distance_1 = parking_distance;
      self->v_227 = nr;
      self->v_173 = ns;
      break;
    case Lab__St_3_ObstacleFollowing:
      right_wheel_St_3_ObstacleFollowing = 0.000000;
      left_wheel_St_3_ObstacleFollowing = 0.000000;
      direction_St_3_ObstacleFollowing = 0;
      st_St_3_ObstacleFollowing = Lab__ObstacleFollowing;
      v_157 = (self->v_156+1.000000);
      if (self->v_154) {
        v_155 = true;
      } else {
        v_155 = r_5;
      };
      if (v_155) {
        counter_1 = 0.000000;
      } else {
        counter_1 = v_157;
      };
      if (ir_front) {
        v_153 = true;
        v_152 = Lab__St_3_LineFollow;
      } else {
        v_153 = false;
        v_152 = Lab__St_3_ObstacleFollowing;
      };
      v_150 = !(ir_front);
      v_149 = (counter_1>=waiting_threshold);
      v_151 = (v_149&&v_150);
      if (v_151) {
        nr_3_St_3_ObstacleFollowing = true;
        ns_3_St_3_ObstacleFollowing = Lab__St_3_WallFollowing;
      } else {
        nr_3_St_3_ObstacleFollowing = v_153;
        ns_3_St_3_ObstacleFollowing = v_152;
      };
      _out->left_wheel = left_wheel_St_3_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_3_ObstacleFollowing;
      _out->direction = direction_St_3_ObstacleFollowing;
      _out->st = st_St_3_ObstacleFollowing;
      ns_3 = ns_3_St_3_ObstacleFollowing;
      nr_3 = nr_3_St_3_ObstacleFollowing;
      self->v_156 = counter_1;
      self->v_154 = false;
      break;
    case Lab__St_3_WallFollowing:
      if (r_5) {
        pnr_1 = false;
        ck_4 = Lab__St_1_CheckState;
      } else {
        pnr_1 = self->v_148;
        ck_4 = self->v_127;
      };
      v_96 = (d_encoder_steps_left-d_encoder_steps_right);
      v_97 = (self->diff_steps_1+v_96);
      if (self->v_94) {
        v_95 = true;
      } else {
        v_95 = r_5;
      };
      v_92 = (m>line_threshold_white);
      v_91 = (l1>line_threshold_white);
      v_93 = (v_91&&v_92);
      v_89 = (m>line_threshold_white);
      v_88 = (r1>line_threshold_white);
      v_90 = (v_88&&v_89);
      back_online = (v_90||v_93);
      right_back_too_far = ir_left_b2;
      v_87 = !(right_back_too_far);
      right_back_too_close = !(ir_left_b1);
      v_86 = !(right_back_too_close);
      right_back_correct = (v_86&&v_87);
      right_front_too_far = ir_left_f2;
      v_85 = !(right_front_too_far);
      right_front_too_close = !(ir_left_f1);
      v_84 = !(right_front_too_close);
      right_front_correct = (v_84&&v_85);
      front_free = ir_front;
      switch (ck_4) {
        case Lab__St_1_CheckState:
          v_108 = (right_front_correct&&right_back_correct);
          if (v_108) {
            v_110 = true;
            v_109 = Lab__St_1_MoveForward;
          } else {
            v_110 = pnr_1;
            v_109 = Lab__St_1_CheckState;
          };
          v_107 = (right_front_too_far&&right_back_correct);
          if (v_107) {
            v_112 = true;
            v_111 = Lab__St_1_RightTurnSlow;
          } else {
            v_112 = v_110;
            v_111 = v_109;
          };
          v_106 = (right_front_too_close&&right_back_correct);
          if (v_106) {
            v_114 = true;
            v_113 = Lab__St_1_LeftTurnSlow;
          } else {
            v_114 = v_112;
            v_113 = v_111;
          };
          v_105 = (right_front_correct&&right_back_too_far);
          if (v_105) {
            v_116 = true;
            v_115 = Lab__St_1_LeftTurnSlow;
          } else {
            v_116 = v_114;
            v_115 = v_113;
          };
          v_104 = (right_front_correct&&right_back_too_close);
          if (v_104) {
            v_118 = true;
            v_117 = Lab__St_1_RightTurnSlow;
          } else {
            v_118 = v_116;
            v_117 = v_115;
          };
          v_103 = (right_front_too_far&&right_back_too_far);
          if (v_103) {
            v_120 = true;
            v_119 = Lab__St_1_MoveCloser;
          } else {
            v_120 = v_118;
            v_119 = v_117;
          };
          v_102 = (right_front_too_far&&right_back_too_close);
          if (v_102) {
            v_122 = true;
            v_121 = Lab__St_1_RightTurn;
          } else {
            v_122 = v_120;
            v_121 = v_119;
          };
          v_101 = (right_front_too_close&&right_back_too_close);
          if (v_101) {
            v_124 = true;
            v_123 = Lab__St_1_MoveAway;
          } else {
            v_124 = v_122;
            v_123 = v_121;
          };
          v_100 = (right_front_too_close&&right_back_too_far);
          if (v_100) {
            v_126 = true;
            v_125 = Lab__St_1_LeftTurn;
          } else {
            v_126 = v_124;
            v_125 = v_123;
          };
          v_99 = !(front_free);
          if (v_99) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab__St_1_Turn90Left;
          } else {
            r_3_St_1_CheckState = v_126;
            s_1_St_1_CheckState = v_125;
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
          right_wheel_St_3_WallFollowing_St_1_Turn90Left = basespeed_obstacle;
          left_wheel_St_3_WallFollowing_St_1_Turn90Left = 0.000000;
          direction_St_3_WallFollowing_St_1_Turn90Left = 3;
          st_St_3_WallFollowing_St_1_Turn90Left = Lab__Turn90Left;
          v_145 = (r_5||r_3);
          if (self->v_144) {
            v_146 = true;
          } else {
            v_146 = v_145;
          };
          v_142 = (self->v_141+d_encoder_steps_right);
          v_139 = (r_5||r_3);
          if (self->v_138) {
            v_140 = true;
          } else {
            v_140 = v_139;
          };
          if (v_140) {
            sum_encoder_steps = 0.000000;
          } else {
            sum_encoder_steps = v_142;
          };
          v_143 = (9.425000*sum_encoder_steps);
          finished_turn = (174.200000<v_143);
          v_147 = (self->away_from_line_1||finished_turn);
          if (v_146) {
            away_from_line_St_1_Turn90Left = false;
          } else {
            away_from_line_St_1_Turn90Left = v_147;
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
          away_from_line_St_1_MoveAway = self->away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_MoveAway = basespeed_obstacle;
          v_136 = (basespeed_obstacle-motorspeed_left_min);
          v_137 = (v_136*move_closer_left);
          left_wheel_St_3_WallFollowing_St_1_MoveAway = (motorspeed_left_min+v_137);
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
          away_from_line_St_1_MoveCloser = self->away_from_line_1;
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
          away_from_line_St_1_RightTurn = self->away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_RightTurn = 0.000000;
          v_134 = (motorspeed_left_max-motorspeed_left_min);
          v_135 = (v_134*right_turn_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_135);
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
          away_from_line_St_1_LeftTurn = self->away_from_line_1;
          v_132 = (motorspeed_right_max-motorspeed_right_min);
          v_133 = (v_132*left_turn_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_133);
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
          away_from_line_St_1_RightTurnSlow = self->away_from_line_1;
          right_wheel_St_3_WallFollowing_St_1_RightTurnSlow = 0.000000;
          v_130 = (motorspeed_left_max-motorspeed_left_min);
          v_131 = (v_130*right_turn_slow_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_131);
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
          away_from_line_St_1_LeftTurnSlow = self->away_from_line_1;
          v_128 = (motorspeed_right_max-motorspeed_right_min);
          v_129 = (v_128*left_turn_slow_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_129);
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
          away_from_line_St_1_MoveForward = self->away_from_line_1;
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
      if (away_from_line) {
        v_98 = v_97;
      } else {
        v_98 = self->diff_steps_1;
      };
      if (v_95) {
        diff_steps = 0.000000;
      } else {
        diff_steps = v_98;
      };
      v_82 = (diff_steps>30.000000);
      v_83 = (back_online&&v_82);
      if (v_83) {
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
      self->diff_steps_1 = diff_steps;
      self->away_from_line_1 = away_from_line;
      self->v_148 = nr_1;
      self->v_127 = ns_1;
      self->v_94 = false;
      break;
    case Lab__St_3_TurnLeftEnd:
      right_wheel_St_3_TurnLeftEnd = basespeed_obstacle;
      left_wheel_St_3_TurnLeftEnd = (motorspeed_right_min*turn_right_end_right);
      direction_St_3_TurnLeftEnd = 3;
      st_St_3_TurnLeftEnd = Lab__TurnLeftEnd;
      v_80 = (self->v_79+d_encoder_steps_right);
      if (self->v_77) {
        v_78 = true;
      } else {
        v_78 = r_5;
      };
      if (v_78) {
        sum_encoder_steps_1 = 0.000000;
      } else {
        sum_encoder_steps_1 = v_80;
      };
      v_81 = (9.425000*sum_encoder_steps_1);
      finished_turn_1 = (204.200000<v_81);
      if (finished_turn_1) {
        nr_3_St_3_TurnLeftEnd = true;
        ns_3_St_3_TurnLeftEnd = Lab__St_3_LineFollow;
      } else {
        nr_3_St_3_TurnLeftEnd = false;
        ns_3_St_3_TurnLeftEnd = Lab__St_3_TurnLeftEnd;
      };
      _out->left_wheel = left_wheel_St_3_TurnLeftEnd;
      _out->right_wheel = right_wheel_St_3_TurnLeftEnd;
      _out->direction = direction_St_3_TurnLeftEnd;
      _out->st = st_St_3_TurnLeftEnd;
      ns_3 = ns_3_St_3_TurnLeftEnd;
      nr_3 = nr_3_St_3_TurnLeftEnd;
      self->v_79 = sum_encoder_steps_1;
      self->v_77 = false;
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
        pnr_2 = self->v_76;
        ck_6 = self->v_63;
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
          v_74 = (self->v_73+d_encoder_steps_left);
          v_71 = (r_5||r_4);
          if (self->v_70) {
            v_72 = true;
          } else {
            v_72 = v_71;
          };
          if (v_72) {
            sum_encoder_steps_left = 0.000000;
          } else {
            sum_encoder_steps_left = v_74;
          };
          v_75 = (9.425000*sum_encoder_steps_left);
          finished_turn_2 = (204.200000<v_75);
          finished_move_St_2_Turn90Right = false;
          if (finished_turn_2) {
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
          v_68 = (self->v_67+d_encoder_steps_left);
          v_65 = (r_5||r_4);
          if (self->v_64) {
            v_66 = true;
          } else {
            v_66 = v_65;
          };
          if (v_66) {
            sum_encoder_steps_left_1 = 0.000000;
          } else {
            sum_encoder_steps_left_1 = v_68;
          };
          v_69 = (9.425000*sum_encoder_steps_left_1);
          finished_move_St_2_Forward = (last_forward_mm<v_69);
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
      self->v_76 = nr_2;
      self->v_63 = ns_2;
      break;
    default:
      break;
  };
  self->white_t_cross_1 = white_t_cross;
  self->white_line_1 = white_line;
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
          self->v_209 = parking_distance;
          self->v_204 = false;
          self->v_198 = error;
          self->v_195 = false;
          self->v_193 = i;
          self->v_190 = false;
          break;
        case Lab__St_LostLine:
          self->v_183 = parking_distance;
          self->v_180 = false;
          break;
        case Lab__St_Tcross:
          self->v_178 = counter;
          self->v_175 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_WallFollowing:
      switch (ck_5) {
        case Lab__St_1_Turn90Left:
          self->v_144 = false;
          self->v_141 = sum_encoder_steps;
          self->v_138 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_Parking:
      switch (ck_7) {
        case Lab__St_2_Turn90Right:
          self->v_73 = sum_encoder_steps_left;
          self->v_70 = false;
          break;
        case Lab__St_2_Forward:
          self->v_67 = sum_encoder_steps_left_1;
          self->v_64 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

