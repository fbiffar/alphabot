/* --- Generated the 7/4/2023 at 11:13 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_test.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_test.h"

void Lab_test__controller_reset(Lab_test__controller_mem* self) {
  self->v_160 = false;
  self->v_128 = Lab_test__St_OnLine;
  self->v_111 = true;
  self->v_105 = false;
  self->v_86 = Lab_test__St_1_CheckState;
  self->v_50 = false;
  self->v_37 = Lab_test__St_2_Backwards;
  self->pnr_3 = false;
  self->ck = Lab_test__St_3_LineFollow;
  self->v_32 = true;
  self->v_149 = true;
  self->v_140 = true;
  self->v_135 = true;
  self->v_129 = true;
  self->v_99 = true;
  self->v_44 = true;
  self->v_38 = true;
}

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
                               Lab_test__controller_mem* self) {
  
  int v_36;
  int r_5_St_3_Parking;
  Lab_test__st_3 s_3_St_3_Parking;
  int r_5_St_3_Stop;
  Lab_test__st_3 s_3_St_3_Stop;
  int r_5_St_3_TurnRightEnd;
  Lab_test__st_3 s_3_St_3_TurnRightEnd;
  int r_5_St_3_WallFollowing;
  Lab_test__st_3 s_3_St_3_WallFollowing;
  int r_5_St_3_ObstacleFollowing;
  Lab_test__st_3 s_3_St_3_ObstacleFollowing;
  int r_5_St_3_LineFollow;
  Lab_test__st_3 s_3_St_3_LineFollow;
  int r_4_St_2_Forward;
  Lab_test__st_2 s_2_St_2_Forward;
  int r_4_St_2_Turn90Right;
  Lab_test__st_2 s_2_St_2_Turn90Right;
  int r_4_St_2_Backwards;
  Lab_test__st_2 s_2_St_2_Backwards;
  Lab_test__st_2 ck_6;
  float v_43;
  float v_42;
  int v_40;
  int v_39;
  float sum_encoder_steps_left_1;
  float v_49;
  float v_48;
  int v_46;
  int v_45;
  float sum_encoder_steps_left;
  int finished_turn_1;
  int nr_2_St_2_Forward;
  Lab_test__st_2 ns_2_St_2_Forward;
  int finished_move_St_2_Forward;
  Lab_test__stateName st_St_3_Parking_St_2_Forward;
  int direction_St_3_Parking_St_2_Forward;
  float right_wheel_St_3_Parking_St_2_Forward;
  float left_wheel_St_3_Parking_St_2_Forward;
  int nr_2_St_2_Turn90Right;
  Lab_test__st_2 ns_2_St_2_Turn90Right;
  int finished_move_St_2_Turn90Right;
  Lab_test__stateName st_St_3_Parking_St_2_Turn90Right;
  int direction_St_3_Parking_St_2_Turn90Right;
  float right_wheel_St_3_Parking_St_2_Turn90Right;
  float left_wheel_St_3_Parking_St_2_Turn90Right;
  int nr_2_St_2_Backwards;
  Lab_test__st_2 ns_2_St_2_Backwards;
  int finished_move_St_2_Backwards;
  Lab_test__stateName st_St_3_Parking_St_2_Backwards;
  int direction_St_3_Parking_St_2_Backwards;
  float right_wheel_St_3_Parking_St_2_Backwards;
  float left_wheel_St_3_Parking_St_2_Backwards;
  Lab_test__st_2 ck_7;
  Lab_test__st_2 s_2;
  Lab_test__st_2 ns_2;
  int r_4;
  int nr_2;
  int pnr_2;
  int finished_move;
  float v_52;
  float v_51;
  int v_85;
  Lab_test__st_1 v_84;
  int v_83;
  Lab_test__st_1 v_82;
  int v_81;
  Lab_test__st_1 v_80;
  int v_79;
  Lab_test__st_1 v_78;
  int v_77;
  Lab_test__st_1 v_76;
  int v_75;
  Lab_test__st_1 v_74;
  int v_73;
  Lab_test__st_1 v_72;
  int v_71;
  Lab_test__st_1 v_70;
  int v_69;
  Lab_test__st_1 v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int v_62;
  int v_61;
  int v_60;
  int v_59;
  int v_58;
  int r_3_St_1_MoveForward;
  Lab_test__st_1 s_1_St_1_MoveForward;
  int r_3_St_1_LeftTurnSlow;
  Lab_test__st_1 s_1_St_1_LeftTurnSlow;
  int r_3_St_1_RightTurnSlow;
  Lab_test__st_1 s_1_St_1_RightTurnSlow;
  int r_3_St_1_LeftTurn;
  Lab_test__st_1 s_1_St_1_LeftTurn;
  int r_3_St_1_RightTurn;
  Lab_test__st_1 s_1_St_1_RightTurn;
  int r_3_St_1_MoveCloser;
  Lab_test__st_1 s_1_St_1_MoveCloser;
  int r_3_St_1_MoveAway;
  Lab_test__st_1 s_1_St_1_MoveAway;
  int r_3_St_1_Turn90Left;
  Lab_test__st_1 s_1_St_1_Turn90Left;
  int r_3_St_1_CheckState;
  Lab_test__st_1 s_1_St_1_CheckState;
  Lab_test__st_1 ck_4;
  float v_88;
  float v_87;
  float v_90;
  float v_89;
  float v_92;
  float v_91;
  float v_94;
  float v_93;
  float v_96;
  float v_95;
  float v_98;
  float v_97;
  float v_104;
  float v_103;
  int v_101;
  int v_100;
  float sum_encoder_steps_right;
  int finished_turn;
  int nr_1_St_1_MoveForward;
  Lab_test__st_1 ns_1_St_1_MoveForward;
  Lab_test__stateName st_St_3_WallFollowing_St_1_MoveForward;
  int direction_St_3_WallFollowing_St_1_MoveForward;
  float right_wheel_St_3_WallFollowing_St_1_MoveForward;
  float left_wheel_St_3_WallFollowing_St_1_MoveForward;
  int nr_1_St_1_LeftTurnSlow;
  Lab_test__st_1 ns_1_St_1_LeftTurnSlow;
  Lab_test__stateName st_St_3_WallFollowing_St_1_LeftTurnSlow;
  int direction_St_3_WallFollowing_St_1_LeftTurnSlow;
  float right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
  float left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
  int nr_1_St_1_RightTurnSlow;
  Lab_test__st_1 ns_1_St_1_RightTurnSlow;
  Lab_test__stateName st_St_3_WallFollowing_St_1_RightTurnSlow;
  int direction_St_3_WallFollowing_St_1_RightTurnSlow;
  float right_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
  float left_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
  int nr_1_St_1_LeftTurn;
  Lab_test__st_1 ns_1_St_1_LeftTurn;
  Lab_test__stateName st_St_3_WallFollowing_St_1_LeftTurn;
  int direction_St_3_WallFollowing_St_1_LeftTurn;
  float right_wheel_St_3_WallFollowing_St_1_LeftTurn;
  float left_wheel_St_3_WallFollowing_St_1_LeftTurn;
  int nr_1_St_1_RightTurn;
  Lab_test__st_1 ns_1_St_1_RightTurn;
  Lab_test__stateName st_St_3_WallFollowing_St_1_RightTurn;
  int direction_St_3_WallFollowing_St_1_RightTurn;
  float right_wheel_St_3_WallFollowing_St_1_RightTurn;
  float left_wheel_St_3_WallFollowing_St_1_RightTurn;
  int nr_1_St_1_MoveCloser;
  Lab_test__st_1 ns_1_St_1_MoveCloser;
  Lab_test__stateName st_St_3_WallFollowing_St_1_MoveCloser;
  int direction_St_3_WallFollowing_St_1_MoveCloser;
  float right_wheel_St_3_WallFollowing_St_1_MoveCloser;
  float left_wheel_St_3_WallFollowing_St_1_MoveCloser;
  int nr_1_St_1_MoveAway;
  Lab_test__st_1 ns_1_St_1_MoveAway;
  Lab_test__stateName st_St_3_WallFollowing_St_1_MoveAway;
  int direction_St_3_WallFollowing_St_1_MoveAway;
  float right_wheel_St_3_WallFollowing_St_1_MoveAway;
  float left_wheel_St_3_WallFollowing_St_1_MoveAway;
  int nr_1_St_1_Turn90Left;
  Lab_test__st_1 ns_1_St_1_Turn90Left;
  Lab_test__stateName st_St_3_WallFollowing_St_1_Turn90Left;
  int direction_St_3_WallFollowing_St_1_Turn90Left;
  float right_wheel_St_3_WallFollowing_St_1_Turn90Left;
  float left_wheel_St_3_WallFollowing_St_1_Turn90Left;
  int nr_1_St_1_CheckState;
  Lab_test__st_1 ns_1_St_1_CheckState;
  Lab_test__stateName st_St_3_WallFollowing_St_1_CheckState;
  int direction_St_3_WallFollowing_St_1_CheckState;
  float right_wheel_St_3_WallFollowing_St_1_CheckState;
  float left_wheel_St_3_WallFollowing_St_1_CheckState;
  Lab_test__st_1 ck_5;
  int v_57;
  int v_56;
  int v_55;
  int v_54;
  int v_53;
  Lab_test__st_1 s_1;
  Lab_test__st_1 ns_1;
  int r_3;
  int nr_1;
  int pnr_1;
  int front_free;
  int left_front_too_close;
  int left_front_too_far;
  int left_back_too_close;
  int left_back_too_far;
  int left_front_correct;
  int left_back_correct;
  float v_114;
  int v_112;
  int v_110;
  Lab_test__st_3 v_109;
  int v_108;
  int v_107;
  int v_106;
  float counter;
  int v_127;
  int r_2_St_LostLine;
  Lab_test__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab_test__st s_St_OnLine;
  Lab_test__st ck_2;
  int v_131;
  int v_130;
  float v_159;
  float v_158;
  float v_157;
  float v_156;
  float v_155;
  int v_153;
  int v_152;
  int v_151;
  int v_150;
  float v_148;
  float v_147;
  float v_146;
  float v_145;
  float v_144;
  int v_142;
  int v_141;
  float v_139;
  int v_137;
  int v_136;
  float v_134;
  float v_133;
  float error;
  float p;
  float i;
  float d;
  float correction;
  int nr_St_LostLine;
  Lab_test__st ns_St_LostLine;
  float parking_distance_St_LostLine;
  Lab_test__stateName st_St_3_LineFollow_St_LostLine;
  int direction_St_3_LineFollow_St_LostLine;
  float right_wheel_St_3_LineFollow_St_LostLine;
  float left_wheel_St_3_LineFollow_St_LostLine;
  int nr_St_OnLine;
  Lab_test__st ns_St_OnLine;
  float parking_distance_St_OnLine;
  Lab_test__stateName st_St_3_LineFollow_St_OnLine;
  int direction_St_3_LineFollow_St_OnLine;
  float right_wheel_St_3_LineFollow_St_OnLine;
  float left_wheel_St_3_LineFollow_St_OnLine;
  Lab_test__st ck_3;
  int v_126;
  Lab_test__st_3 v_125;
  int v_124;
  int v_123;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  int v_118;
  int v_117;
  int v_116;
  int v_115;
  Lab_test__st s;
  Lab_test__st ns;
  int r_2;
  int nr;
  int pnr;
  float parking_distance;
  int nr_3_St_3_Parking;
  Lab_test__st_3 ns_3_St_3_Parking;
  Lab_test__stateName st_St_3_Parking;
  int direction_St_3_Parking;
  float right_wheel_St_3_Parking;
  float left_wheel_St_3_Parking;
  int nr_3_St_3_Stop;
  Lab_test__st_3 ns_3_St_3_Stop;
  Lab_test__stateName st_St_3_Stop;
  int direction_St_3_Stop;
  float right_wheel_St_3_Stop;
  float left_wheel_St_3_Stop;
  int nr_3_St_3_TurnRightEnd;
  Lab_test__st_3 ns_3_St_3_TurnRightEnd;
  Lab_test__stateName st_St_3_TurnRightEnd;
  int direction_St_3_TurnRightEnd;
  float right_wheel_St_3_TurnRightEnd;
  float left_wheel_St_3_TurnRightEnd;
  int nr_3_St_3_WallFollowing;
  Lab_test__st_3 ns_3_St_3_WallFollowing;
  Lab_test__stateName st_St_3_WallFollowing;
  int direction_St_3_WallFollowing;
  float right_wheel_St_3_WallFollowing;
  float left_wheel_St_3_WallFollowing;
  int nr_3_St_3_ObstacleFollowing;
  Lab_test__st_3 ns_3_St_3_ObstacleFollowing;
  Lab_test__stateName st_St_3_ObstacleFollowing;
  int direction_St_3_ObstacleFollowing;
  float right_wheel_St_3_ObstacleFollowing;
  float left_wheel_St_3_ObstacleFollowing;
  int nr_3_St_3_LineFollow;
  Lab_test__st_3 ns_3_St_3_LineFollow;
  Lab_test__stateName st_St_3_LineFollow;
  int direction_St_3_LineFollow;
  float right_wheel_St_3_LineFollow;
  float left_wheel_St_3_LineFollow;
  Lab_test__st_3 ck_1;
  int v_35;
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
  Lab_test__st_3 s_3;
  Lab_test__st_3 ns_3;
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
  v_33 = !(ir_left_f2);
  v_35 = (v_33||self->v_34);
  if (self->v_32) {
    first_car = false;
  } else {
    first_car = v_35;
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
    case Lab_test__St_3_LineFollow:
      v_36 = !(ir_front);
      if (v_36) {
        r_5_St_3_LineFollow = true;
        s_3_St_3_LineFollow = Lab_test__St_3_ObstacleFollowing;
      } else {
        r_5_St_3_LineFollow = self->pnr_3;
        s_3_St_3_LineFollow = Lab_test__St_3_LineFollow;
      };
      s_3 = s_3_St_3_LineFollow;
      r_5 = r_5_St_3_LineFollow;
      break;
    case Lab_test__St_3_ObstacleFollowing:
      r_5_St_3_ObstacleFollowing = self->pnr_3;
      s_3_St_3_ObstacleFollowing = Lab_test__St_3_ObstacleFollowing;
      s_3 = s_3_St_3_ObstacleFollowing;
      r_5 = r_5_St_3_ObstacleFollowing;
      break;
    case Lab_test__St_3_WallFollowing:
      r_5_St_3_WallFollowing = self->pnr_3;
      s_3_St_3_WallFollowing = Lab_test__St_3_WallFollowing;
      s_3 = s_3_St_3_WallFollowing;
      r_5 = r_5_St_3_WallFollowing;
      break;
    case Lab_test__St_3_TurnRightEnd:
      if (alligned) {
        r_5_St_3_TurnRightEnd = true;
        s_3_St_3_TurnRightEnd = Lab_test__St_3_LineFollow;
      } else {
        r_5_St_3_TurnRightEnd = self->pnr_3;
        s_3_St_3_TurnRightEnd = Lab_test__St_3_TurnRightEnd;
      };
      s_3 = s_3_St_3_TurnRightEnd;
      r_5 = r_5_St_3_TurnRightEnd;
      break;
    case Lab_test__St_3_Stop:
      r_5_St_3_Stop = self->pnr_3;
      s_3_St_3_Stop = Lab_test__St_3_Stop;
      s_3 = s_3_St_3_Stop;
      r_5 = r_5_St_3_Stop;
      break;
    case Lab_test__St_3_Parking:
      r_5_St_3_Parking = self->pnr_3;
      s_3_St_3_Parking = Lab_test__St_3_Parking;
      s_3 = s_3_St_3_Parking;
      r_5 = r_5_St_3_Parking;
      break;
    default:
      break;
  };
  ck_1 = s_3;
  switch (ck_1) {
    case Lab_test__St_3_LineFollow:
      if (r_5) {
        pnr = false;
        ck_2 = Lab_test__St_OnLine;
      } else {
        pnr = self->v_160;
        ck_2 = self->v_128;
      };
      v_123 = (r1>stop_threshold);
      v_121 = (m>stop_threshold);
      v_119 = (l1>stop_threshold);
      v_118 = (white_line==false);
      v_120 = (v_118&&v_119);
      v_122 = (v_120&&v_121);
      v_124 = (v_122&&v_123);
      if (v_124) {
        v_126 = true;
        v_125 = Lab_test__St_3_Stop;
      } else {
        v_126 = false;
        v_125 = Lab_test__St_3_LineFollow;
      };
      v_115 = (white_line==false);
      switch (ck_2) {
        case Lab_test__St_OnLine:
          if (left_line) {
            r_2_St_OnLine = true;
            s_St_OnLine = Lab_test__St_LostLine;
          } else {
            r_2_St_OnLine = pnr;
            s_St_OnLine = Lab_test__St_OnLine;
          };
          s = s_St_OnLine;
          r_2 = r_2_St_OnLine;
          break;
        case Lab_test__St_LostLine:
          v_127 = !(left_m);
          if (v_127) {
            r_2_St_LostLine = true;
            s_St_LostLine = Lab_test__St_OnLine;
          } else {
            r_2_St_LostLine = pnr;
            s_St_LostLine = Lab_test__St_LostLine;
          };
          s = s_St_LostLine;
          r_2 = r_2_St_LostLine;
          break;
        default:
          break;
      };
      ck_3 = s;
      switch (ck_3) {
        case Lab_test__St_OnLine:
          right_wheel_St_3_LineFollow_St_OnLine = 0.000000;
          left_wheel_St_3_LineFollow_St_OnLine = 0.000000;
          direction_St_3_LineFollow_St_OnLine = 0;
          st_St_3_LineFollow_St_OnLine = Lab_test__OnLine;
          v_155 = (d_encoder_steps_right+d_encoder_steps_left);
          v_156 = (v_155/2.000000);
          v_157 = (v_156*9.425000);
          v_158 = (self->v_154+v_157);
          v_152 = !(car_to_the_right);
          v_153 = (first_car&&v_152);
          if (v_153) {
            v_159 = v_158;
          } else {
            v_159 = 0.000000;
          };
          v_150 = (r_5||r_2);
          if (self->v_149) {
            v_151 = true;
          } else {
            v_151 = v_150;
          };
          if (v_151) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_159;
          };
          v_141 = (r_5||r_2);
          if (self->v_140) {
            v_142 = true;
          } else {
            v_142 = v_141;
          };
          v_136 = (r_5||r_2);
          if (self->v_135) {
            v_137 = true;
          } else {
            v_137 = v_136;
          };
          v_134 = (l-r);
          v_133 = (r-l);
          if (white_line) {
            error = v_133;
          } else {
            error = v_134;
          };
          v_144 = (error-self->v_143);
          if (v_142) {
            d = error;
          } else {
            d = v_144;
          };
          v_148 = (d*kD);
          v_139 = (self->v_138+error);
          if (v_137) {
            i = error;
          } else {
            i = v_139;
          };
          v_146 = (i*kI);
          p = error;
          v_145 = (p*kP);
          v_147 = (v_145+v_146);
          correction = (v_147+v_148);
          nr_St_OnLine = false;
          ns_St_OnLine = Lab_test__St_OnLine;
          left_wheel_St_3_LineFollow = left_wheel_St_3_LineFollow_St_OnLine;
          right_wheel_St_3_LineFollow = right_wheel_St_3_LineFollow_St_OnLine;
          direction_St_3_LineFollow = direction_St_3_LineFollow_St_OnLine;
          st_St_3_LineFollow = st_St_3_LineFollow_St_OnLine;
          parking_distance = parking_distance_St_OnLine;
          ns = ns_St_OnLine;
          nr = nr_St_OnLine;
          break;
        case Lab_test__St_LostLine:
          right_wheel_St_3_LineFollow_St_LostLine = 0.000000;
          left_wheel_St_3_LineFollow_St_LostLine = 0.000000;
          direction_St_3_LineFollow_St_LostLine = 0;
          st_St_3_LineFollow_St_LostLine = Lab_test__LostLine;
          v_130 = (r_5||r_2);
          if (self->v_129) {
            v_131 = true;
          } else {
            v_131 = v_130;
          };
          if (v_131) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_132;
          };
          nr_St_LostLine = false;
          ns_St_LostLine = Lab_test__St_LostLine;
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
      v_116 = (parking_distance>=min_parking_space);
      v_117 = (v_115&&v_116);
      if (v_117) {
        nr_3_St_3_LineFollow = true;
        ns_3_St_3_LineFollow = Lab_test__St_3_Parking;
      } else {
        nr_3_St_3_LineFollow = v_126;
        ns_3_St_3_LineFollow = v_125;
      };
      _out->left_wheel = left_wheel_St_3_LineFollow;
      _out->right_wheel = right_wheel_St_3_LineFollow;
      _out->direction = direction_St_3_LineFollow;
      _out->st = st_St_3_LineFollow;
      ns_3 = ns_3_St_3_LineFollow;
      nr_3 = nr_3_St_3_LineFollow;
      self->parking_distance_1 = parking_distance;
      self->v_160 = nr;
      self->v_128 = ns;
      break;
    case Lab_test__St_3_ObstacleFollowing:
      right_wheel_St_3_ObstacleFollowing = motorspeed_right_min;
      left_wheel_St_3_ObstacleFollowing = motorspeed_left_min;
      direction_St_3_ObstacleFollowing = 0;
      st_St_3_ObstacleFollowing = Lab_test__ObstacleFollowing;
      v_114 = (self->v_113+1.000000);
      if (self->v_111) {
        v_112 = true;
      } else {
        v_112 = r_5;
      };
      if (v_112) {
        counter = 0.000000;
      } else {
        counter = v_114;
      };
      if (ir_front) {
        v_110 = true;
        v_109 = Lab_test__St_3_LineFollow;
      } else {
        v_110 = false;
        v_109 = Lab_test__St_3_ObstacleFollowing;
      };
      v_107 = !(ir_front);
      v_106 = (counter>=waiting_threshold);
      v_108 = (v_106&&v_107);
      if (v_108) {
        nr_3_St_3_ObstacleFollowing = true;
        ns_3_St_3_ObstacleFollowing = Lab_test__St_3_WallFollowing;
      } else {
        nr_3_St_3_ObstacleFollowing = v_110;
        ns_3_St_3_ObstacleFollowing = v_109;
      };
      _out->left_wheel = left_wheel_St_3_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_3_ObstacleFollowing;
      _out->direction = direction_St_3_ObstacleFollowing;
      _out->st = st_St_3_ObstacleFollowing;
      ns_3 = ns_3_St_3_ObstacleFollowing;
      nr_3 = nr_3_St_3_ObstacleFollowing;
      self->v_113 = counter;
      self->v_111 = false;
      break;
    case Lab_test__St_3_WallFollowing:
      if (r_5) {
        pnr_1 = false;
        ck_4 = Lab_test__St_1_CheckState;
      } else {
        pnr_1 = self->v_105;
        ck_4 = self->v_86;
      };
      left_back_too_far = ir_left_b2;
      v_57 = !(left_back_too_far);
      left_back_too_close = !(ir_left_b1);
      v_56 = !(left_back_too_close);
      left_back_correct = (v_56&&v_57);
      left_front_too_far = ir_left_f2;
      v_55 = !(left_front_too_far);
      left_front_too_close = !(ir_left_f1);
      v_54 = !(left_front_too_close);
      left_front_correct = (v_54&&v_55);
      front_free = !(ir_front);
      v_53 = !(left_line);
      if (v_53) {
        nr_3_St_3_WallFollowing = true;
        ns_3_St_3_WallFollowing = Lab_test__St_3_TurnRightEnd;
      } else {
        nr_3_St_3_WallFollowing = false;
        ns_3_St_3_WallFollowing = Lab_test__St_3_WallFollowing;
      };
      switch (ck_4) {
        case Lab_test__St_1_CheckState:
          v_67 = (left_front_correct&&left_back_correct);
          if (v_67) {
            v_69 = true;
            v_68 = Lab_test__St_1_MoveForward;
          } else {
            v_69 = pnr_1;
            v_68 = Lab_test__St_1_CheckState;
          };
          v_66 = (left_front_too_far&&left_back_correct);
          if (v_66) {
            v_71 = true;
            v_70 = Lab_test__St_1_LeftTurnSlow;
          } else {
            v_71 = v_69;
            v_70 = v_68;
          };
          v_65 = (left_front_too_close&&left_back_correct);
          if (v_65) {
            v_73 = true;
            v_72 = Lab_test__St_1_RightTurnSlow;
          } else {
            v_73 = v_71;
            v_72 = v_70;
          };
          v_64 = (left_front_correct&&left_back_too_far);
          if (v_64) {
            v_75 = true;
            v_74 = Lab_test__St_1_RightTurnSlow;
          } else {
            v_75 = v_73;
            v_74 = v_72;
          };
          v_63 = (left_front_correct&&left_back_too_close);
          if (v_63) {
            v_77 = true;
            v_76 = Lab_test__St_1_LeftTurnSlow;
          } else {
            v_77 = v_75;
            v_76 = v_74;
          };
          v_62 = (left_front_too_far&&left_back_too_far);
          if (v_62) {
            v_79 = true;
            v_78 = Lab_test__St_1_MoveCloser;
          } else {
            v_79 = v_77;
            v_78 = v_76;
          };
          v_61 = (left_front_too_far&&left_back_too_close);
          if (v_61) {
            v_81 = true;
            v_80 = Lab_test__St_1_LeftTurn;
          } else {
            v_81 = v_79;
            v_80 = v_78;
          };
          v_60 = (left_front_too_close&&left_back_too_far);
          if (v_60) {
            v_83 = true;
            v_82 = Lab_test__St_1_RightTurn;
          } else {
            v_83 = v_81;
            v_82 = v_80;
          };
          v_59 = (left_front_too_close&&left_back_too_close);
          if (v_59) {
            v_85 = true;
            v_84 = Lab_test__St_1_MoveAway;
          } else {
            v_85 = v_83;
            v_84 = v_82;
          };
          v_58 = !(front_free);
          if (v_58) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab_test__St_1_Turn90Left;
          } else {
            r_3_St_1_CheckState = v_85;
            s_1_St_1_CheckState = v_84;
          };
          s_1 = s_1_St_1_CheckState;
          r_3 = r_3_St_1_CheckState;
          break;
        case Lab_test__St_1_Turn90Left:
          r_3_St_1_Turn90Left = pnr_1;
          s_1_St_1_Turn90Left = Lab_test__St_1_Turn90Left;
          s_1 = s_1_St_1_Turn90Left;
          r_3 = r_3_St_1_Turn90Left;
          break;
        case Lab_test__St_1_MoveAway:
          r_3_St_1_MoveAway = pnr_1;
          s_1_St_1_MoveAway = Lab_test__St_1_MoveAway;
          s_1 = s_1_St_1_MoveAway;
          r_3 = r_3_St_1_MoveAway;
          break;
        case Lab_test__St_1_MoveCloser:
          r_3_St_1_MoveCloser = pnr_1;
          s_1_St_1_MoveCloser = Lab_test__St_1_MoveCloser;
          s_1 = s_1_St_1_MoveCloser;
          r_3 = r_3_St_1_MoveCloser;
          break;
        case Lab_test__St_1_RightTurn:
          r_3_St_1_RightTurn = pnr_1;
          s_1_St_1_RightTurn = Lab_test__St_1_RightTurn;
          s_1 = s_1_St_1_RightTurn;
          r_3 = r_3_St_1_RightTurn;
          break;
        case Lab_test__St_1_LeftTurn:
          r_3_St_1_LeftTurn = pnr_1;
          s_1_St_1_LeftTurn = Lab_test__St_1_LeftTurn;
          s_1 = s_1_St_1_LeftTurn;
          r_3 = r_3_St_1_LeftTurn;
          break;
        case Lab_test__St_1_RightTurnSlow:
          r_3_St_1_RightTurnSlow = pnr_1;
          s_1_St_1_RightTurnSlow = Lab_test__St_1_RightTurnSlow;
          s_1 = s_1_St_1_RightTurnSlow;
          r_3 = r_3_St_1_RightTurnSlow;
          break;
        case Lab_test__St_1_LeftTurnSlow:
          r_3_St_1_LeftTurnSlow = pnr_1;
          s_1_St_1_LeftTurnSlow = Lab_test__St_1_LeftTurnSlow;
          s_1 = s_1_St_1_LeftTurnSlow;
          r_3 = r_3_St_1_LeftTurnSlow;
          break;
        case Lab_test__St_1_MoveForward:
          r_3_St_1_MoveForward = pnr_1;
          s_1_St_1_MoveForward = Lab_test__St_1_MoveForward;
          s_1 = s_1_St_1_MoveForward;
          r_3 = r_3_St_1_MoveForward;
          break;
        default:
          break;
      };
      ck_5 = s_1;
      switch (ck_5) {
        case Lab_test__St_1_CheckState:
          right_wheel_St_3_WallFollowing_St_1_CheckState = motorspeed_right_min;
          left_wheel_St_3_WallFollowing_St_1_CheckState = motorspeed_left_min;
          direction_St_3_WallFollowing_St_1_CheckState = 0;
          st_St_3_WallFollowing_St_1_CheckState = Lab_test__Error;
          nr_1_St_1_CheckState = false;
          ns_1_St_1_CheckState = Lab_test__St_1_CheckState;
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_CheckState;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_CheckState;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_CheckState;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_CheckState;
          ns_1 = ns_1_St_1_CheckState;
          nr_1 = nr_1_St_1_CheckState;
          break;
        case Lab_test__St_1_Turn90Left:
          right_wheel_St_3_WallFollowing_St_1_Turn90Left = 0.000000;
          left_wheel_St_3_WallFollowing_St_1_Turn90Left = basespeed_left;
          direction_St_3_WallFollowing_St_1_Turn90Left = 3;
          st_St_3_WallFollowing_St_1_Turn90Left = Lab_test__Turn90Left;
          v_103 = (self->v_102+d_encoder_steps_right);
          v_100 = (r_5||r_3);
          if (self->v_99) {
            v_101 = true;
          } else {
            v_101 = v_100;
          };
          if (v_101) {
            sum_encoder_steps_right = 0.000000;
          } else {
            sum_encoder_steps_right = v_103;
          };
          v_104 = (9.425000*sum_encoder_steps_right);
          finished_turn = (204.200000<v_104);
          if (finished_turn) {
            nr_1_St_1_Turn90Left = true;
            ns_1_St_1_Turn90Left = Lab_test__St_1_CheckState;
          } else {
            nr_1_St_1_Turn90Left = false;
            ns_1_St_1_Turn90Left = Lab_test__St_1_Turn90Left;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_Turn90Left;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_Turn90Left;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_Turn90Left;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_Turn90Left;
          ns_1 = ns_1_St_1_Turn90Left;
          nr_1 = nr_1_St_1_Turn90Left;
          break;
        case Lab_test__St_1_MoveAway:
          v_97 = (basespeed_right-motorspeed_right_min);
          v_98 = (v_97*move_away_right);
          right_wheel_St_3_WallFollowing_St_1_MoveAway = (motorspeed_right_min+v_98);
          left_wheel_St_3_WallFollowing_St_1_MoveAway = basespeed_left;
          direction_St_3_WallFollowing_St_1_MoveAway = 3;
          st_St_3_WallFollowing_St_1_MoveAway = Lab_test__MoveAway;
          if (true) {
            nr_1_St_1_MoveAway = true;
          } else {
            nr_1_St_1_MoveAway = false;
          };
          if (true) {
            ns_1_St_1_MoveAway = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_MoveAway = Lab_test__St_1_MoveAway;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveAway;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveAway;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveAway;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveAway;
          ns_1 = ns_1_St_1_MoveAway;
          nr_1 = nr_1_St_1_MoveAway;
          break;
        case Lab_test__St_1_MoveCloser:
          right_wheel_St_3_WallFollowing_St_1_MoveCloser = basespeed_right;
          v_95 = (basespeed_left-motorspeed_left_min);
          v_96 = (v_95*move_closer_left);
          left_wheel_St_3_WallFollowing_St_1_MoveCloser = (motorspeed_left_min+v_96);
          direction_St_3_WallFollowing_St_1_MoveCloser = 2;
          st_St_3_WallFollowing_St_1_MoveCloser = Lab_test__MoveCloser;
          if (true) {
            nr_1_St_1_MoveCloser = true;
          } else {
            nr_1_St_1_MoveCloser = false;
          };
          if (true) {
            ns_1_St_1_MoveCloser = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_MoveCloser = Lab_test__St_1_MoveCloser;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveCloser;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveCloser;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveCloser;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveCloser;
          ns_1 = ns_1_St_1_MoveCloser;
          nr_1 = nr_1_St_1_MoveCloser;
          break;
        case Lab_test__St_1_RightTurn:
          right_wheel_St_3_WallFollowing_St_1_RightTurn = motorspeed_right_min;
          v_93 = (motorspeed_left_max-motorspeed_left_min);
          v_94 = (v_93*right_turn_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_94);
          direction_St_3_WallFollowing_St_1_RightTurn = 3;
          st_St_3_WallFollowing_St_1_RightTurn = Lab_test__RightTurn;
          if (true) {
            nr_1_St_1_RightTurn = true;
          } else {
            nr_1_St_1_RightTurn = false;
          };
          if (true) {
            ns_1_St_1_RightTurn = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_RightTurn = Lab_test__St_1_RightTurn;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_RightTurn;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_RightTurn;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_RightTurn;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_RightTurn;
          ns_1 = ns_1_St_1_RightTurn;
          nr_1 = nr_1_St_1_RightTurn;
          break;
        case Lab_test__St_1_LeftTurn:
          v_91 = (motorspeed_right_max-motorspeed_right_min);
          v_92 = (v_91*left_turn_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_92);
          left_wheel_St_3_WallFollowing_St_1_LeftTurn = motorspeed_left_min;
          direction_St_3_WallFollowing_St_1_LeftTurn = 2;
          st_St_3_WallFollowing_St_1_LeftTurn = Lab_test__LeftTurn;
          if (true) {
            nr_1_St_1_LeftTurn = true;
          } else {
            nr_1_St_1_LeftTurn = false;
          };
          if (true) {
            ns_1_St_1_LeftTurn = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_LeftTurn = Lab_test__St_1_LeftTurn;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_LeftTurn;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_LeftTurn;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_LeftTurn;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_LeftTurn;
          ns_1 = ns_1_St_1_LeftTurn;
          nr_1 = nr_1_St_1_LeftTurn;
          break;
        case Lab_test__St_1_RightTurnSlow:
          right_wheel_St_3_WallFollowing_St_1_RightTurnSlow = motorspeed_right_min;
          v_89 = (motorspeed_left_max-motorspeed_left_min);
          v_90 = (v_89*right_turn_slow_left);
          left_wheel_St_3_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_90);
          direction_St_3_WallFollowing_St_1_RightTurnSlow = 3;
          st_St_3_WallFollowing_St_1_RightTurnSlow = Lab_test__RightTurn;
          if (true) {
            nr_1_St_1_RightTurnSlow = true;
          } else {
            nr_1_St_1_RightTurnSlow = false;
          };
          if (true) {
            ns_1_St_1_RightTurnSlow = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_RightTurnSlow = Lab_test__St_1_RightTurnSlow;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_RightTurnSlow;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_RightTurnSlow;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_RightTurnSlow;
          ns_1 = ns_1_St_1_RightTurnSlow;
          nr_1 = nr_1_St_1_RightTurnSlow;
          break;
        case Lab_test__St_1_LeftTurnSlow:
          v_87 = (motorspeed_right_max-motorspeed_right_min);
          v_88 = (v_87*left_turn_slow_right);
          right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_88);
          left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow = motorspeed_left_min;
          direction_St_3_WallFollowing_St_1_LeftTurnSlow = 2;
          st_St_3_WallFollowing_St_1_LeftTurnSlow = Lab_test__LeftTurn;
          if (true) {
            nr_1_St_1_LeftTurnSlow = true;
          } else {
            nr_1_St_1_LeftTurnSlow = false;
          };
          if (true) {
            ns_1_St_1_LeftTurnSlow = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_LeftTurnSlow = Lab_test__St_1_LeftTurnSlow;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_LeftTurnSlow;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_LeftTurnSlow;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_LeftTurnSlow;
          ns_1 = ns_1_St_1_LeftTurnSlow;
          nr_1 = nr_1_St_1_LeftTurnSlow;
          break;
        case Lab_test__St_1_MoveForward:
          right_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_right;
          left_wheel_St_3_WallFollowing_St_1_MoveForward = basespeed_left;
          direction_St_3_WallFollowing_St_1_MoveForward = 1;
          st_St_3_WallFollowing_St_1_MoveForward = Lab_test__MoveForward;
          if (true) {
            nr_1_St_1_MoveForward = true;
          } else {
            nr_1_St_1_MoveForward = false;
          };
          if (true) {
            ns_1_St_1_MoveForward = Lab_test__St_1_CheckState;
          } else {
            ns_1_St_1_MoveForward = Lab_test__St_1_MoveForward;
          };
          left_wheel_St_3_WallFollowing = left_wheel_St_3_WallFollowing_St_1_MoveForward;
          right_wheel_St_3_WallFollowing = right_wheel_St_3_WallFollowing_St_1_MoveForward;
          direction_St_3_WallFollowing = direction_St_3_WallFollowing_St_1_MoveForward;
          st_St_3_WallFollowing = st_St_3_WallFollowing_St_1_MoveForward;
          ns_1 = ns_1_St_1_MoveForward;
          nr_1 = nr_1_St_1_MoveForward;
          break;
        default:
          break;
      };
      _out->left_wheel = left_wheel_St_3_WallFollowing;
      _out->right_wheel = right_wheel_St_3_WallFollowing;
      _out->direction = direction_St_3_WallFollowing;
      _out->st = st_St_3_WallFollowing;
      ns_3 = ns_3_St_3_WallFollowing;
      nr_3 = nr_3_St_3_WallFollowing;
      self->v_105 = nr_1;
      self->v_86 = ns_1;
      break;
    case Lab_test__St_3_TurnRightEnd:
      v_51 = (basespeed_right-motorspeed_left_min);
      v_52 = (v_51*turn_right_end_right);
      right_wheel_St_3_TurnRightEnd = (motorspeed_right_min+v_52);
      left_wheel_St_3_TurnRightEnd = basespeed_left;
      direction_St_3_TurnRightEnd = 3;
      st_St_3_TurnRightEnd = Lab_test__TurnRightEnd;
      nr_3_St_3_TurnRightEnd = false;
      ns_3_St_3_TurnRightEnd = Lab_test__St_3_TurnRightEnd;
      _out->left_wheel = left_wheel_St_3_TurnRightEnd;
      _out->right_wheel = right_wheel_St_3_TurnRightEnd;
      _out->direction = direction_St_3_TurnRightEnd;
      _out->st = st_St_3_TurnRightEnd;
      ns_3 = ns_3_St_3_TurnRightEnd;
      nr_3 = nr_3_St_3_TurnRightEnd;
      break;
    case Lab_test__St_3_Stop:
      right_wheel_St_3_Stop = 0.000000;
      left_wheel_St_3_Stop = 0.000000;
      direction_St_3_Stop = 0;
      st_St_3_Stop = Lab_test__Stop;
      nr_3_St_3_Stop = false;
      ns_3_St_3_Stop = Lab_test__St_3_Stop;
      _out->left_wheel = left_wheel_St_3_Stop;
      _out->right_wheel = right_wheel_St_3_Stop;
      _out->direction = direction_St_3_Stop;
      _out->st = st_St_3_Stop;
      ns_3 = ns_3_St_3_Stop;
      nr_3 = nr_3_St_3_Stop;
      break;
    case Lab_test__St_3_Parking:
      if (r_5) {
        pnr_2 = false;
        ck_6 = Lab_test__St_2_Backwards;
      } else {
        pnr_2 = self->v_50;
        ck_6 = self->v_37;
      };
      switch (ck_6) {
        case Lab_test__St_2_Backwards:
          if (car_to_the_right) {
            r_4_St_2_Backwards = true;
            s_2_St_2_Backwards = Lab_test__St_2_Turn90Right;
          } else {
            r_4_St_2_Backwards = pnr_2;
            s_2_St_2_Backwards = Lab_test__St_2_Backwards;
          };
          s_2 = s_2_St_2_Backwards;
          r_4 = r_4_St_2_Backwards;
          break;
        case Lab_test__St_2_Turn90Right:
          r_4_St_2_Turn90Right = pnr_2;
          s_2_St_2_Turn90Right = Lab_test__St_2_Turn90Right;
          s_2 = s_2_St_2_Turn90Right;
          r_4 = r_4_St_2_Turn90Right;
          break;
        case Lab_test__St_2_Forward:
          r_4_St_2_Forward = pnr_2;
          s_2_St_2_Forward = Lab_test__St_2_Forward;
          s_2 = s_2_St_2_Forward;
          r_4 = r_4_St_2_Forward;
          break;
        default:
          break;
      };
      ck_7 = s_2;
      switch (ck_7) {
        case Lab_test__St_2_Backwards:
          right_wheel_St_3_Parking_St_2_Backwards = basespeed_parking;
          left_wheel_St_3_Parking_St_2_Backwards = basespeed_parking;
          direction_St_3_Parking_St_2_Backwards = 4;
          st_St_3_Parking_St_2_Backwards = Lab_test__Backwards;
          finished_move_St_2_Backwards = false;
          nr_2_St_2_Backwards = false;
          ns_2_St_2_Backwards = Lab_test__St_2_Backwards;
          left_wheel_St_3_Parking = left_wheel_St_3_Parking_St_2_Backwards;
          right_wheel_St_3_Parking = right_wheel_St_3_Parking_St_2_Backwards;
          direction_St_3_Parking = direction_St_3_Parking_St_2_Backwards;
          st_St_3_Parking = st_St_3_Parking_St_2_Backwards;
          finished_move = finished_move_St_2_Backwards;
          ns_2 = ns_2_St_2_Backwards;
          nr_2 = nr_2_St_2_Backwards;
          break;
        case Lab_test__St_2_Turn90Right:
          right_wheel_St_3_Parking_St_2_Turn90Right = motorspeed_right_parking;
          left_wheel_St_3_Parking_St_2_Turn90Right = motorspeed_left_parking;
          direction_St_3_Parking_St_2_Turn90Right = 3;
          st_St_3_Parking_St_2_Turn90Right = Lab_test__Turn90Right;
          v_48 = (self->v_47+d_encoder_steps_left);
          v_45 = (r_5||r_4);
          if (self->v_44) {
            v_46 = true;
          } else {
            v_46 = v_45;
          };
          if (v_46) {
            sum_encoder_steps_left = 0.000000;
          } else {
            sum_encoder_steps_left = v_48;
          };
          v_49 = (9.425000*sum_encoder_steps_left);
          finished_turn_1 = (204.200000<v_49);
          finished_move_St_2_Turn90Right = false;
          if (finished_turn_1) {
            nr_2_St_2_Turn90Right = true;
            ns_2_St_2_Turn90Right = Lab_test__St_2_Forward;
          } else {
            nr_2_St_2_Turn90Right = false;
            ns_2_St_2_Turn90Right = Lab_test__St_2_Turn90Right;
          };
          left_wheel_St_3_Parking = left_wheel_St_3_Parking_St_2_Turn90Right;
          right_wheel_St_3_Parking = right_wheel_St_3_Parking_St_2_Turn90Right;
          direction_St_3_Parking = direction_St_3_Parking_St_2_Turn90Right;
          st_St_3_Parking = st_St_3_Parking_St_2_Turn90Right;
          finished_move = finished_move_St_2_Turn90Right;
          ns_2 = ns_2_St_2_Turn90Right;
          nr_2 = nr_2_St_2_Turn90Right;
          break;
        case Lab_test__St_2_Forward:
          right_wheel_St_3_Parking_St_2_Forward = basespeed_parking;
          left_wheel_St_3_Parking_St_2_Forward = basespeed_parking;
          direction_St_3_Parking_St_2_Forward = 3;
          st_St_3_Parking_St_2_Forward = Lab_test__Forward;
          v_42 = (self->v_41+d_encoder_steps_left);
          v_39 = (r_5||r_4);
          if (self->v_38) {
            v_40 = true;
          } else {
            v_40 = v_39;
          };
          if (v_40) {
            sum_encoder_steps_left_1 = 0.000000;
          } else {
            sum_encoder_steps_left_1 = v_42;
          };
          v_43 = (9.425000*sum_encoder_steps_left_1);
          finished_move_St_2_Forward = (last_forward_mm>v_43);
          nr_2_St_2_Forward = false;
          ns_2_St_2_Forward = Lab_test__St_2_Forward;
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
        ns_3_St_3_Parking = Lab_test__St_3_Stop;
      } else {
        nr_3_St_3_Parking = false;
        ns_3_St_3_Parking = Lab_test__St_3_Parking;
      };
      _out->left_wheel = left_wheel_St_3_Parking;
      _out->right_wheel = right_wheel_St_3_Parking;
      _out->direction = direction_St_3_Parking;
      _out->st = st_St_3_Parking;
      ns_3 = ns_3_St_3_Parking;
      nr_3 = nr_3_St_3_Parking;
      self->v_50 = nr_2;
      self->v_37 = ns_2;
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
  self->v_34 = first_car;
  self->v_32 = false;
  switch (ck_1) {
    case Lab_test__St_3_LineFollow:
      switch (ck_3) {
        case Lab_test__St_OnLine:
          self->v_154 = parking_distance;
          self->v_149 = false;
          self->v_143 = error;
          self->v_140 = false;
          self->v_138 = i;
          self->v_135 = false;
          break;
        case Lab_test__St_LostLine:
          self->v_132 = parking_distance;
          self->v_129 = false;
          break;
        default:
          break;
      };
      break;
    case Lab_test__St_3_WallFollowing:
      switch (ck_5) {
        case Lab_test__St_1_Turn90Left:
          self->v_102 = sum_encoder_steps_right;
          self->v_99 = false;
          break;
        default:
          break;
      };
      break;
    case Lab_test__St_3_Parking:
      switch (ck_7) {
        case Lab_test__St_2_Turn90Right:
          self->v_47 = sum_encoder_steps_left;
          self->v_44 = false;
          break;
        case Lab_test__St_2_Forward:
          self->v_41 = sum_encoder_steps_left_1;
          self->v_38 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

