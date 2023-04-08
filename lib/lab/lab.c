/* --- Generated the 8/4/2023 at 14:47 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_204 = false;
  self->v_156 = Lab__St_OnLine;
  self->v_139 = true;
  self->v_133 = false;
  self->v_112 = Lab__St_1_CheckState;
  self->v_68 = true;
  self->v_67 = false;
  self->v_54 = Lab__St_2_Backwards;
  self->white_line_1 = false;
  self->pnr_3 = false;
  self->ck = Lab__St_3_LineFollow;
  self->v_32 = true;
  self->v_181 = true;
  self->v_172 = true;
  self->v_167 = true;
  self->v_157 = true;
  self->v_129 = true;
  self->v_123 = true;
  self->v_61 = true;
  self->v_55 = true;
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
  
  int v_53;
  int v_52;
  int v_51;
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
  float v_60;
  float v_59;
  int v_57;
  int v_56;
  float sum_encoder_steps_left_1;
  float v_66;
  float v_65;
  int v_63;
  int v_62;
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
  float v_72;
  float v_71;
  int v_69;
  float sum_encoder_steps_1;
  int finished_turn_1;
  int v_111;
  Lab__st_1 v_110;
  int v_109;
  Lab__st_1 v_108;
  int v_107;
  Lab__st_1 v_106;
  int v_105;
  Lab__st_1 v_104;
  int v_103;
  Lab__st_1 v_102;
  int v_101;
  Lab__st_1 v_100;
  int v_99;
  Lab__st_1 v_98;
  int v_97;
  Lab__st_1 v_96;
  int v_95;
  Lab__st_1 v_94;
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
  float v_114;
  float v_113;
  float v_116;
  float v_115;
  float v_118;
  float v_117;
  float v_120;
  float v_119;
  float v_122;
  float v_121;
  int v_132;
  int v_131;
  int v_130;
  float v_128;
  float v_127;
  int v_125;
  int v_124;
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
  int v_83;
  int v_82;
  int v_81;
  int v_80;
  int v_79;
  int v_78;
  int v_77;
  int v_76;
  int v_75;
  int v_74;
  int v_73;
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
  float v_142;
  int v_140;
  int v_138;
  Lab__st_3 v_137;
  int v_136;
  int v_135;
  int v_134;
  float counter;
  int v_155;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  float v_164;
  float v_163;
  float v_162;
  float v_161;
  int v_159;
  int v_158;
  float v_203;
  float v_202;
  int v_201;
  float v_200;
  int v_199;
  float v_198;
  float v_197;
  float v_196;
  int v_195;
  float v_194;
  int v_193;
  float v_192;
  float v_191;
  float v_190;
  float v_189;
  float v_188;
  float v_187;
  int v_185;
  int v_184;
  int v_183;
  int v_182;
  float v_180;
  float v_179;
  float v_178;
  float v_177;
  float v_176;
  int v_174;
  int v_173;
  float v_171;
  int v_169;
  int v_168;
  float v_166;
  float v_165;
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
  int v_154;
  Lab__st_3 v_153;
  int v_152;
  int v_151;
  int v_150;
  int v_149;
  int v_148;
  int v_147;
  int v_146;
  int v_145;
  int v_144;
  int v_143;
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
      v_52 = !(ir_front);
      v_51 = (white_line==true);
      v_53 = (v_51&&v_52);
      if (v_53) {
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
        pnr = self->v_204;
        ck_2 = self->v_156;
      };
      v_151 = (r1>stop_threshold);
      v_149 = (m>stop_threshold);
      v_147 = (l1>stop_threshold);
      v_146 = (white_line==false);
      v_148 = (v_146&&v_147);
      v_150 = (v_148&&v_149);
      v_152 = (v_150&&v_151);
      if (v_152) {
        v_154 = true;
        v_153 = Lab__St_3_Stop;
      } else {
        v_154 = false;
        v_153 = Lab__St_3_LineFollow;
      };
      v_143 = (white_line==false);
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
          v_155 = !(left_m);
          if (v_155) {
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
          v_200 = (basespeed_right-motorspeed_right_max);
          v_198 = (basespeed_right-motorspeed_right_min);
          v_194 = (motorspeed_left_min-basespeed_left);
          v_192 = (motorspeed_left_max-basespeed_left);
          direction_St_3_LineFollow_St_OnLine = 1;
          st_St_3_LineFollow_St_OnLine = Lab__OnLine;
          v_187 = (d_encoder_steps_right+d_encoder_steps_left);
          v_188 = (v_187/2.000000);
          v_189 = (v_188*9.425000);
          v_190 = (self->v_186+v_189);
          v_184 = !(car_to_the_right);
          v_185 = (first_car&&v_184);
          if (v_185) {
            v_191 = v_190;
          } else {
            v_191 = 0.000000;
          };
          v_182 = (r_5||r_2);
          if (self->v_181) {
            v_183 = true;
          } else {
            v_183 = v_182;
          };
          if (v_183) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_191;
          };
          v_173 = (r_5||r_2);
          if (self->v_172) {
            v_174 = true;
          } else {
            v_174 = v_173;
          };
          v_168 = (r_5||r_2);
          if (self->v_167) {
            v_169 = true;
          } else {
            v_169 = v_168;
          };
          v_166 = (l-r);
          v_165 = (r-l);
          if (white_line) {
            error = v_165;
          } else {
            error = v_166;
          };
          v_176 = (error-self->v_175);
          if (v_174) {
            d = error;
          } else {
            d = v_176;
          };
          v_180 = (d*kD);
          v_171 = (self->v_170+error);
          if (v_169) {
            i = error;
          } else {
            i = v_171;
          };
          v_178 = (i*kI);
          p = error;
          v_177 = (p*kP);
          v_179 = (v_177+v_178);
          correction = (v_179+v_180);
          v_202 = (basespeed_right-correction);
          v_201 = (correction<v_200);
          if (v_201) {
            v_203 = motorspeed_right_max;
          } else {
            v_203 = v_202;
          };
          v_199 = (correction>v_198);
          if (v_199) {
            right_wheel_St_3_LineFollow_St_OnLine = motorspeed_right_min;
          } else {
            right_wheel_St_3_LineFollow_St_OnLine = v_203;
          };
          v_196 = (basespeed_left+correction);
          v_195 = (correction<v_194);
          if (v_195) {
            v_197 = motorspeed_left_min;
          } else {
            v_197 = v_196;
          };
          v_193 = (correction>v_192);
          if (v_193) {
            left_wheel_St_3_LineFollow_St_OnLine = motorspeed_left_max;
          } else {
            left_wheel_St_3_LineFollow_St_OnLine = v_197;
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
          v_163 = (motorspeed_right_max-motorspeed_right_min);
          v_164 = (v_163*backward_factor);
          right_wheel_St_3_LineFollow_St_LostLine = (motorspeed_right_min+v_164);
          v_161 = (motorspeed_left_max-motorspeed_left_min);
          v_162 = (v_161*backward_factor);
          left_wheel_St_3_LineFollow_St_LostLine = (motorspeed_left_min+v_162);
          direction_St_3_LineFollow_St_LostLine = 4;
          st_St_3_LineFollow_St_LostLine = Lab__LostLine;
          v_158 = (r_5||r_2);
          if (self->v_157) {
            v_159 = true;
          } else {
            v_159 = v_158;
          };
          if (v_159) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_160;
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
      v_144 = (parking_distance>=min_parking_space);
      v_145 = (v_143&&v_144);
      if (v_145) {
        nr_3_St_3_LineFollow = true;
        ns_3_St_3_LineFollow = Lab__St_3_Parking;
      } else {
        nr_3_St_3_LineFollow = v_154;
        ns_3_St_3_LineFollow = v_153;
      };
      _out->left_wheel = left_wheel_St_3_LineFollow;
      _out->right_wheel = right_wheel_St_3_LineFollow;
      _out->direction = direction_St_3_LineFollow;
      _out->st = st_St_3_LineFollow;
      ns_3 = ns_3_St_3_LineFollow;
      nr_3 = nr_3_St_3_LineFollow;
      self->parking_distance_1 = parking_distance;
      self->v_204 = nr;
      self->v_156 = ns;
      break;
    case Lab__St_3_ObstacleFollowing:
      right_wheel_St_3_ObstacleFollowing = 0.000000;
      left_wheel_St_3_ObstacleFollowing = 0.000000;
      direction_St_3_ObstacleFollowing = 0;
      st_St_3_ObstacleFollowing = Lab__ObstacleFollowing;
      v_142 = (self->v_141+1.000000);
      if (self->v_139) {
        v_140 = true;
      } else {
        v_140 = r_5;
      };
      if (v_140) {
        counter = 0.000000;
      } else {
        counter = v_142;
      };
      if (ir_front) {
        v_138 = true;
        v_137 = Lab__St_3_LineFollow;
      } else {
        v_138 = false;
        v_137 = Lab__St_3_ObstacleFollowing;
      };
      v_135 = !(ir_front);
      v_134 = (counter>=waiting_threshold);
      v_136 = (v_134&&v_135);
      if (v_136) {
        nr_3_St_3_ObstacleFollowing = true;
        ns_3_St_3_ObstacleFollowing = Lab__St_3_WallFollowing;
      } else {
        nr_3_St_3_ObstacleFollowing = v_138;
        ns_3_St_3_ObstacleFollowing = v_137;
      };
      _out->left_wheel = left_wheel_St_3_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_3_ObstacleFollowing;
      _out->direction = direction_St_3_ObstacleFollowing;
      _out->st = st_St_3_ObstacleFollowing;
      ns_3 = ns_3_St_3_ObstacleFollowing;
      nr_3 = nr_3_St_3_ObstacleFollowing;
      self->v_141 = counter;
      self->v_139 = false;
      break;
    case Lab__St_3_WallFollowing:
      if (r_5) {
        pnr_1 = false;
        ck_4 = Lab__St_1_CheckState;
      } else {
        pnr_1 = self->v_133;
        ck_4 = self->v_112;
      };
      v_82 = (m>line_threshold_white);
      v_81 = (l1>line_threshold_white);
      v_83 = (v_81&&v_82);
      v_79 = (m>line_threshold_white);
      v_78 = (r1>line_threshold_white);
      v_80 = (v_78&&v_79);
      back_online = (v_80||v_83);
      right_back_too_far = ir_left_b2;
      v_77 = !(right_back_too_far);
      right_back_too_close = !(ir_left_b1);
      v_76 = !(right_back_too_close);
      right_back_correct = (v_76&&v_77);
      right_front_too_far = ir_left_f2;
      v_75 = !(right_front_too_far);
      right_front_too_close = !(ir_left_f1);
      v_74 = !(right_front_too_close);
      right_front_correct = (v_74&&v_75);
      front_free = ir_front;
      switch (ck_4) {
        case Lab__St_1_CheckState:
          v_93 = (right_front_correct&&right_back_correct);
          if (v_93) {
            v_95 = true;
            v_94 = Lab__St_1_MoveForward;
          } else {
            v_95 = pnr_1;
            v_94 = Lab__St_1_CheckState;
          };
          v_92 = (right_front_too_far&&right_back_correct);
          if (v_92) {
            v_97 = true;
            v_96 = Lab__St_1_RightTurnSlow;
          } else {
            v_97 = v_95;
            v_96 = v_94;
          };
          v_91 = (right_front_too_close&&right_back_correct);
          if (v_91) {
            v_99 = true;
            v_98 = Lab__St_1_LeftTurnSlow;
          } else {
            v_99 = v_97;
            v_98 = v_96;
          };
          v_90 = (right_front_correct&&right_back_too_far);
          if (v_90) {
            v_101 = true;
            v_100 = Lab__St_1_LeftTurnSlow;
          } else {
            v_101 = v_99;
            v_100 = v_98;
          };
          v_89 = (right_front_correct&&right_back_too_close);
          if (v_89) {
            v_103 = true;
            v_102 = Lab__St_1_RightTurnSlow;
          } else {
            v_103 = v_101;
            v_102 = v_100;
          };
          v_88 = (right_front_too_far&&right_back_too_far);
          if (v_88) {
            v_105 = true;
            v_104 = Lab__St_1_MoveCloser;
          } else {
            v_105 = v_103;
            v_104 = v_102;
          };
          v_87 = (right_front_too_far&&right_back_too_close);
          if (v_87) {
            v_107 = true;
            v_106 = Lab__St_1_RightTurn;
          } else {
            v_107 = v_105;
            v_106 = v_104;
          };
          v_86 = (right_front_too_close&&right_back_too_close);
          if (v_86) {
            v_109 = true;
            v_108 = Lab__St_1_MoveAway;
          } else {
            v_109 = v_107;
            v_108 = v_106;
          };
          v_85 = (right_front_too_close&&right_back_too_far);
          if (v_85) {
            v_111 = true;
            v_110 = Lab__St_1_LeftTurn;
          } else {
            v_111 = v_109;
            v_110 = v_108;
          };
          v_84 = !(front_free);
          if (v_84) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab__St_1_Turn90Left;
          } else {
            r_3_St_1_CheckState = v_111;
            s_1_St_1_CheckState = v_110;
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
          v_130 = (r_5||r_3);
          if (self->v_129) {
            v_131 = true;
          } else {
            v_131 = v_130;
          };
          v_127 = (self->v_126+d_encoder_steps_right);
          v_124 = (r_5||r_3);
          if (self->v_123) {
            v_125 = true;
          } else {
            v_125 = v_124;
          };
          if (v_125) {
            sum_encoder_steps = 0.000000;
          } else {
            sum_encoder_steps = v_127;
          };
          v_128 = (9.425000*sum_encoder_steps);
          finished_turn = (174.200000<v_128);
          v_132 = (self->away_from_line_1||finished_turn);
          if (v_131) {
            away_from_line_St_1_Turn90Left = false;
          } else {
            away_from_line_St_1_Turn90Left = v_132;
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
          v_121 = (basespeed_obstacle-motorspeed_left_min);
          v_122 = (v_121*move_closer_left);
          left_wheel_St_3_WallFollowing_St_1_MoveAway = (motorspeed_left_min+v_122);
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
          v_119 = (motorspeed_left_max-motorspeed_left_min);
          v_120 = (v_119*right_turn_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_120);
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
          v_117 = (motorspeed_right_max-motorspeed_right_min);
          v_118 = (v_117*left_turn_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_118);
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
          v_115 = (motorspeed_left_max-motorspeed_left_min);
          v_116 = (v_115*right_turn_slow_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_116);
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
          v_113 = (motorspeed_right_max-motorspeed_right_min);
          v_114 = (v_113*left_turn_slow_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_114);
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
      v_73 = (back_online&&away_from_line);
      if (v_73) {
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
      self->away_from_line_1 = away_from_line;
      self->v_133 = nr_1;
      self->v_112 = ns_1;
      break;
    case Lab__St_3_TurnLeftEnd:
      right_wheel_St_3_TurnLeftEnd = basespeed_obstacle;
      left_wheel_St_3_TurnLeftEnd = (motorspeed_right_min*turn_right_end_right);
      direction_St_3_TurnLeftEnd = 3;
      st_St_3_TurnLeftEnd = Lab__TurnLeftEnd;
      v_71 = (self->v_70+d_encoder_steps_right);
      if (self->v_68) {
        v_69 = true;
      } else {
        v_69 = r_5;
      };
      if (v_69) {
        sum_encoder_steps_1 = 0.000000;
      } else {
        sum_encoder_steps_1 = v_71;
      };
      v_72 = (9.425000*sum_encoder_steps_1);
      finished_turn_1 = (174.200000<v_72);
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
      self->v_70 = sum_encoder_steps_1;
      self->v_68 = false;
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
        pnr_2 = self->v_67;
        ck_6 = self->v_54;
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
          v_65 = (self->v_64+d_encoder_steps_left);
          v_62 = (r_5||r_4);
          if (self->v_61) {
            v_63 = true;
          } else {
            v_63 = v_62;
          };
          if (v_63) {
            sum_encoder_steps_left = 0.000000;
          } else {
            sum_encoder_steps_left = v_65;
          };
          v_66 = (9.425000*sum_encoder_steps_left);
          finished_turn_2 = (204.200000<v_66);
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
          v_59 = (self->v_58+d_encoder_steps_left);
          v_56 = (r_5||r_4);
          if (self->v_55) {
            v_57 = true;
          } else {
            v_57 = v_56;
          };
          if (v_57) {
            sum_encoder_steps_left_1 = 0.000000;
          } else {
            sum_encoder_steps_left_1 = v_59;
          };
          v_60 = (9.425000*sum_encoder_steps_left_1);
          finished_move_St_2_Forward = (last_forward_mm>v_60);
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
      self->v_67 = nr_2;
      self->v_54 = ns_2;
      break;
    default:
      break;
  };
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
          self->v_186 = parking_distance;
          self->v_181 = false;
          self->v_175 = error;
          self->v_172 = false;
          self->v_170 = i;
          self->v_167 = false;
          break;
        case Lab__St_LostLine:
          self->v_160 = parking_distance;
          self->v_157 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_WallFollowing:
      switch (ck_5) {
        case Lab__St_1_Turn90Left:
          self->v_129 = false;
          self->v_126 = sum_encoder_steps;
          self->v_123 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_3_Parking:
      switch (ck_7) {
        case Lab__St_2_Turn90Right:
          self->v_64 = sum_encoder_steps_left;
          self->v_61 = false;
          break;
        case Lab__St_2_Forward:
          self->v_58 = sum_encoder_steps_left_1;
          self->v_55 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

