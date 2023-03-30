/* --- Generated the 30/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_131 = false;
  self->v_98 = Lab__St_OnLine;
  self->v_93 = true;
  self->v_87 = false;
  self->v_68 = Lab__St_1_CheckState;
  self->pnr_2 = false;
  self->ck = Lab__St_2_LineFollow;
  self->v_110 = true;
  self->v_105 = true;
  self->v_81 = true;
}

void Lab__controller_step(float l2, float l1, float m, float r1, float r2,
                          int ir_front, int ir_left_f1, int ir_left_f2,
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
                          float line_threshold_black, float stop_threshold,
                          float move_away_right, float move_closer_left,
                          float right_turn_left, float left_turn_right,
                          float right_turn_slow_left,
                          float left_turn_slow_right,
                          float turn_right_end_right,
                          Lab__controller_out* _out,
                          Lab__controller_mem* self) {
  
  int v_32;
  int r_4_St_2_TurnRightEnd;
  Lab__st_2 s_2_St_2_TurnRightEnd;
  int r_4_St_2_WallFollowing;
  Lab__st_2 s_2_St_2_WallFollowing;
  int r_4_St_2_ObstacleFollowing;
  Lab__st_2 s_2_St_2_ObstacleFollowing;
  int r_4_St_2_LineFollow;
  Lab__st_2 s_2_St_2_LineFollow;
  float v_34;
  float v_33;
  int v_67;
  Lab__st_1 v_66;
  int v_65;
  Lab__st_1 v_64;
  int v_63;
  Lab__st_1 v_62;
  int v_61;
  Lab__st_1 v_60;
  int v_59;
  Lab__st_1 v_58;
  int v_57;
  Lab__st_1 v_56;
  int v_55;
  Lab__st_1 v_54;
  int v_53;
  Lab__st_1 v_52;
  int v_51;
  Lab__st_1 v_50;
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
  int r_3_St_1_Turn90Right;
  Lab__st_1 s_1_St_1_Turn90Right;
  int r_3_St_1_CheckState;
  Lab__st_1 s_1_St_1_CheckState;
  Lab__st_1 ck_4;
  float v_70;
  float v_69;
  float v_72;
  float v_71;
  float v_74;
  float v_73;
  float v_76;
  float v_75;
  float v_78;
  float v_77;
  float v_80;
  float v_79;
  float v_86;
  float v_85;
  int v_83;
  int v_82;
  float sum_encoder_steps_left;
  int finished_turn;
  int nr_1_St_1_MoveForward;
  Lab__st_1 ns_1_St_1_MoveForward;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveForward;
  int direction_St_2_WallFollowing_St_1_MoveForward;
  float right_wheel_St_2_WallFollowing_St_1_MoveForward;
  float left_wheel_St_2_WallFollowing_St_1_MoveForward;
  int nr_1_St_1_LeftTurnSlow;
  Lab__st_1 ns_1_St_1_LeftTurnSlow;
  Lab__stateName st_St_2_WallFollowing_St_1_LeftTurnSlow;
  int direction_St_2_WallFollowing_St_1_LeftTurnSlow;
  float right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
  float left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
  int nr_1_St_1_RightTurnSlow;
  Lab__st_1 ns_1_St_1_RightTurnSlow;
  Lab__stateName st_St_2_WallFollowing_St_1_RightTurnSlow;
  int direction_St_2_WallFollowing_St_1_RightTurnSlow;
  float right_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
  float left_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
  int nr_1_St_1_LeftTurn;
  Lab__st_1 ns_1_St_1_LeftTurn;
  Lab__stateName st_St_2_WallFollowing_St_1_LeftTurn;
  int direction_St_2_WallFollowing_St_1_LeftTurn;
  float right_wheel_St_2_WallFollowing_St_1_LeftTurn;
  float left_wheel_St_2_WallFollowing_St_1_LeftTurn;
  int nr_1_St_1_RightTurn;
  Lab__st_1 ns_1_St_1_RightTurn;
  Lab__stateName st_St_2_WallFollowing_St_1_RightTurn;
  int direction_St_2_WallFollowing_St_1_RightTurn;
  float right_wheel_St_2_WallFollowing_St_1_RightTurn;
  float left_wheel_St_2_WallFollowing_St_1_RightTurn;
  int nr_1_St_1_MoveCloser;
  Lab__st_1 ns_1_St_1_MoveCloser;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveCloser;
  int direction_St_2_WallFollowing_St_1_MoveCloser;
  float right_wheel_St_2_WallFollowing_St_1_MoveCloser;
  float left_wheel_St_2_WallFollowing_St_1_MoveCloser;
  int nr_1_St_1_MoveAway;
  Lab__st_1 ns_1_St_1_MoveAway;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveAway;
  int direction_St_2_WallFollowing_St_1_MoveAway;
  float right_wheel_St_2_WallFollowing_St_1_MoveAway;
  float left_wheel_St_2_WallFollowing_St_1_MoveAway;
  int nr_1_St_1_Turn90Right;
  Lab__st_1 ns_1_St_1_Turn90Right;
  Lab__stateName st_St_2_WallFollowing_St_1_Turn90Right;
  int direction_St_2_WallFollowing_St_1_Turn90Right;
  float right_wheel_St_2_WallFollowing_St_1_Turn90Right;
  float left_wheel_St_2_WallFollowing_St_1_Turn90Right;
  int nr_1_St_1_CheckState;
  Lab__st_1 ns_1_St_1_CheckState;
  Lab__stateName st_St_2_WallFollowing_St_1_CheckState;
  int direction_St_2_WallFollowing_St_1_CheckState;
  float right_wheel_St_2_WallFollowing_St_1_CheckState;
  float left_wheel_St_2_WallFollowing_St_1_CheckState;
  Lab__st_1 ck_5;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  Lab__st_1 s_1;
  Lab__st_1 ns_1;
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
  float v_96;
  int v_94;
  int v_92;
  Lab__st_2 v_91;
  int v_90;
  int v_89;
  int v_88;
  float counter;
  int v_97;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  float v_102;
  float v_101;
  float v_100;
  float v_99;
  float v_130;
  float v_129;
  int v_128;
  float v_127;
  int v_126;
  float v_125;
  float v_124;
  float v_123;
  int v_122;
  float v_121;
  int v_120;
  float v_119;
  float v_118;
  float v_117;
  float v_116;
  float v_115;
  float v_114;
  int v_112;
  int v_111;
  float v_109;
  int v_107;
  int v_106;
  float v_104;
  float v_103;
  float error;
  float p;
  float i;
  float d;
  float correction;
  int nr_St_LostLine;
  Lab__st ns_St_LostLine;
  Lab__stateName st_St_2_LineFollow_St_LostLine;
  int direction_St_2_LineFollow_St_LostLine;
  float right_wheel_St_2_LineFollow_St_LostLine;
  float left_wheel_St_2_LineFollow_St_LostLine;
  int nr_St_OnLine;
  Lab__st ns_St_OnLine;
  Lab__stateName st_St_2_LineFollow_St_OnLine;
  int direction_St_2_LineFollow_St_OnLine;
  float right_wheel_St_2_LineFollow_St_OnLine;
  float left_wheel_St_2_LineFollow_St_OnLine;
  Lab__st ck_3;
  Lab__st s;
  Lab__st ns;
  int r_2;
  int nr;
  int pnr;
  int nr_2_St_2_TurnRightEnd;
  Lab__st_2 ns_2_St_2_TurnRightEnd;
  Lab__stateName st_St_2_TurnRightEnd;
  int direction_St_2_TurnRightEnd;
  float right_wheel_St_2_TurnRightEnd;
  float left_wheel_St_2_TurnRightEnd;
  int nr_2_St_2_WallFollowing;
  Lab__st_2 ns_2_St_2_WallFollowing;
  Lab__stateName st_St_2_WallFollowing;
  int direction_St_2_WallFollowing;
  float right_wheel_St_2_WallFollowing;
  float left_wheel_St_2_WallFollowing;
  int nr_2_St_2_ObstacleFollowing;
  Lab__st_2 ns_2_St_2_ObstacleFollowing;
  Lab__stateName st_St_2_ObstacleFollowing;
  int direction_St_2_ObstacleFollowing;
  float right_wheel_St_2_ObstacleFollowing;
  float left_wheel_St_2_ObstacleFollowing;
  int nr_2_St_2_LineFollow;
  Lab__st_2 ns_2_St_2_LineFollow;
  Lab__stateName st_St_2_LineFollow;
  int direction_St_2_LineFollow;
  float right_wheel_St_2_LineFollow;
  float left_wheel_St_2_LineFollow;
  Lab__st_2 ck_1;
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
  Lab__st_2 s_2;
  Lab__st_2 ns_2;
  int r_4;
  int nr_2;
  int left_line;
  int left_m;
  int alligned;
  float r;
  float l;
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
    case Lab__St_2_LineFollow:
      v_32 = !(ir_front);
      if (v_32) {
        r_4_St_2_LineFollow = true;
        s_2_St_2_LineFollow = Lab__St_2_ObstacleFollowing;
      } else {
        r_4_St_2_LineFollow = self->pnr_2;
        s_2_St_2_LineFollow = Lab__St_2_LineFollow;
      };
      s_2 = s_2_St_2_LineFollow;
      r_4 = r_4_St_2_LineFollow;
      break;
    case Lab__St_2_ObstacleFollowing:
      r_4_St_2_ObstacleFollowing = self->pnr_2;
      s_2_St_2_ObstacleFollowing = Lab__St_2_ObstacleFollowing;
      s_2 = s_2_St_2_ObstacleFollowing;
      r_4 = r_4_St_2_ObstacleFollowing;
      break;
    case Lab__St_2_WallFollowing:
      r_4_St_2_WallFollowing = self->pnr_2;
      s_2_St_2_WallFollowing = Lab__St_2_WallFollowing;
      s_2 = s_2_St_2_WallFollowing;
      r_4 = r_4_St_2_WallFollowing;
      break;
    case Lab__St_2_TurnRightEnd:
      if (alligned) {
        r_4_St_2_TurnRightEnd = true;
        s_2_St_2_TurnRightEnd = Lab__St_2_LineFollow;
      } else {
        r_4_St_2_TurnRightEnd = self->pnr_2;
        s_2_St_2_TurnRightEnd = Lab__St_2_TurnRightEnd;
      };
      s_2 = s_2_St_2_TurnRightEnd;
      r_4 = r_4_St_2_TurnRightEnd;
      break;
    default:
      break;
  };
  ck_1 = s_2;
  switch (ck_1) {
    case Lab__St_2_LineFollow:
      if (r_4) {
        pnr = false;
        ck_2 = Lab__St_OnLine;
      } else {
        pnr = self->v_131;
        ck_2 = self->v_98;
      };
      nr_2_St_2_LineFollow = false;
      ns_2_St_2_LineFollow = Lab__St_2_LineFollow;
      ns_2 = ns_2_St_2_LineFollow;
      nr_2 = nr_2_St_2_LineFollow;
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
          v_97 = !(left_m);
          if (v_97) {
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
          v_127 = (basespeed_right-motorspeed_right_max);
          v_125 = (basespeed_right-motorspeed_right_min);
          v_121 = (motorspeed_left_min-basespeed_left);
          v_119 = (motorspeed_left_max-basespeed_left);
          direction_St_2_LineFollow_St_OnLine = 1;
          st_St_2_LineFollow_St_OnLine = Lab__OnLine;
          v_111 = (r_4||r_2);
          if (self->v_110) {
            v_112 = true;
          } else {
            v_112 = v_111;
          };
          v_106 = (r_4||r_2);
          if (self->v_105) {
            v_107 = true;
          } else {
            v_107 = v_106;
          };
          v_104 = (l-r);
          v_103 = (r-l);
          if (white_line) {
            error = v_103;
          } else {
            error = v_104;
          };
          v_114 = (error-self->v_113);
          if (v_112) {
            d = error;
          } else {
            d = v_114;
          };
          v_118 = (d*kD);
          v_109 = (self->v_108+error);
          if (v_107) {
            i = 0.000000;
          } else {
            i = v_109;
          };
          v_116 = (i*kI);
          p = error;
          v_115 = (p*kP);
          v_117 = (v_115+v_116);
          correction = (v_117+v_118);
          v_129 = (basespeed_right-correction);
          v_128 = (correction<v_127);
          if (v_128) {
            v_130 = motorspeed_right_max;
          } else {
            v_130 = v_129;
          };
          v_126 = (correction>v_125);
          if (v_126) {
            right_wheel_St_2_LineFollow_St_OnLine = motorspeed_right_min;
          } else {
            right_wheel_St_2_LineFollow_St_OnLine = v_130;
          };
          v_123 = (basespeed_left+correction);
          v_122 = (correction<v_121);
          if (v_122) {
            v_124 = motorspeed_left_min;
          } else {
            v_124 = v_123;
          };
          v_120 = (correction>v_119);
          if (v_120) {
            left_wheel_St_2_LineFollow_St_OnLine = motorspeed_left_max;
          } else {
            left_wheel_St_2_LineFollow_St_OnLine = v_124;
          };
          nr_St_OnLine = false;
          ns_St_OnLine = Lab__St_OnLine;
          left_wheel_St_2_LineFollow = left_wheel_St_2_LineFollow_St_OnLine;
          right_wheel_St_2_LineFollow = right_wheel_St_2_LineFollow_St_OnLine;
          direction_St_2_LineFollow = direction_St_2_LineFollow_St_OnLine;
          st_St_2_LineFollow = st_St_2_LineFollow_St_OnLine;
          ns = ns_St_OnLine;
          nr = nr_St_OnLine;
          break;
        case Lab__St_LostLine:
          v_101 = (motorspeed_right_max-motorspeed_right_min);
          v_102 = (v_101*backward_factor);
          right_wheel_St_2_LineFollow_St_LostLine = (motorspeed_right_min+v_102);
          v_99 = (motorspeed_left_max-motorspeed_left_min);
          v_100 = (v_99*backward_factor);
          left_wheel_St_2_LineFollow_St_LostLine = (motorspeed_left_min+v_100);
          direction_St_2_LineFollow_St_LostLine = 4;
          st_St_2_LineFollow_St_LostLine = Lab__LostLine;
          nr_St_LostLine = false;
          ns_St_LostLine = Lab__St_LostLine;
          left_wheel_St_2_LineFollow = left_wheel_St_2_LineFollow_St_LostLine;
          right_wheel_St_2_LineFollow = right_wheel_St_2_LineFollow_St_LostLine;
          direction_St_2_LineFollow = direction_St_2_LineFollow_St_LostLine;
          st_St_2_LineFollow = st_St_2_LineFollow_St_LostLine;
          ns = ns_St_LostLine;
          nr = nr_St_LostLine;
          break;
        default:
          break;
      };
      _out->left_wheel = left_wheel_St_2_LineFollow;
      _out->right_wheel = right_wheel_St_2_LineFollow;
      _out->direction = direction_St_2_LineFollow;
      _out->st = st_St_2_LineFollow;
      self->v_131 = nr;
      self->v_98 = ns;
      break;
    case Lab__St_2_ObstacleFollowing:
      right_wheel_St_2_ObstacleFollowing = motorspeed_right_min;
      left_wheel_St_2_ObstacleFollowing = motorspeed_left_min;
      direction_St_2_ObstacleFollowing = 0;
      st_St_2_ObstacleFollowing = Lab__ObstacleFollowing;
      v_96 = (self->v_95+1.000000);
      if (self->v_93) {
        v_94 = true;
      } else {
        v_94 = r_4;
      };
      if (v_94) {
        counter = 0.000000;
      } else {
        counter = v_96;
      };
      if (ir_front) {
        v_92 = true;
        v_91 = Lab__St_2_LineFollow;
      } else {
        v_92 = false;
        v_91 = Lab__St_2_ObstacleFollowing;
      };
      v_89 = !(ir_front);
      v_88 = (counter>=stop_threshold);
      v_90 = (v_88&&v_89);
      if (v_90) {
        nr_2_St_2_ObstacleFollowing = true;
        ns_2_St_2_ObstacleFollowing = Lab__St_2_WallFollowing;
      } else {
        nr_2_St_2_ObstacleFollowing = v_92;
        ns_2_St_2_ObstacleFollowing = v_91;
      };
      ns_2 = ns_2_St_2_ObstacleFollowing;
      nr_2 = nr_2_St_2_ObstacleFollowing;
      _out->left_wheel = left_wheel_St_2_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_2_ObstacleFollowing;
      _out->direction = direction_St_2_ObstacleFollowing;
      _out->st = st_St_2_ObstacleFollowing;
      self->v_95 = counter;
      self->v_93 = false;
      break;
    case Lab__St_2_WallFollowing:
      if (r_4) {
        pnr_1 = false;
        ck_4 = Lab__St_1_CheckState;
      } else {
        pnr_1 = self->v_87;
        ck_4 = self->v_68;
      };
      left_back_too_far = ir_left_b2;
      v_39 = !(left_back_too_far);
      left_back_too_close = !(ir_left_b1);
      v_38 = !(left_back_too_close);
      left_back_correct = (v_38&&v_39);
      left_front_too_far = ir_left_f2;
      v_37 = !(left_front_too_far);
      left_front_too_close = !(ir_left_f1);
      v_36 = !(left_front_too_close);
      left_front_correct = (v_36&&v_37);
      front_free = !(ir_front);
      v_35 = !(left_line);
      if (v_35) {
        nr_2_St_2_WallFollowing = true;
        ns_2_St_2_WallFollowing = Lab__St_2_TurnRightEnd;
      } else {
        nr_2_St_2_WallFollowing = false;
        ns_2_St_2_WallFollowing = Lab__St_2_WallFollowing;
      };
      ns_2 = ns_2_St_2_WallFollowing;
      nr_2 = nr_2_St_2_WallFollowing;
      switch (ck_4) {
        case Lab__St_1_CheckState:
          v_49 = (left_front_correct&&left_back_correct);
          if (v_49) {
            v_51 = true;
            v_50 = Lab__St_1_MoveForward;
          } else {
            v_51 = pnr_1;
            v_50 = Lab__St_1_CheckState;
          };
          v_48 = (left_front_too_far&&left_back_correct);
          if (v_48) {
            v_53 = true;
            v_52 = Lab__St_1_LeftTurnSlow;
          } else {
            v_53 = v_51;
            v_52 = v_50;
          };
          v_47 = (left_front_too_close&&left_back_correct);
          if (v_47) {
            v_55 = true;
            v_54 = Lab__St_1_RightTurnSlow;
          } else {
            v_55 = v_53;
            v_54 = v_52;
          };
          v_46 = (left_front_correct&&left_back_too_far);
          if (v_46) {
            v_57 = true;
            v_56 = Lab__St_1_RightTurnSlow;
          } else {
            v_57 = v_55;
            v_56 = v_54;
          };
          v_45 = (left_front_correct&&left_back_too_close);
          if (v_45) {
            v_59 = true;
            v_58 = Lab__St_1_LeftTurnSlow;
          } else {
            v_59 = v_57;
            v_58 = v_56;
          };
          v_44 = (left_front_too_far&&left_back_too_far);
          if (v_44) {
            v_61 = true;
            v_60 = Lab__St_1_MoveCloser;
          } else {
            v_61 = v_59;
            v_60 = v_58;
          };
          v_43 = (left_front_too_far&&left_back_too_close);
          if (v_43) {
            v_63 = true;
            v_62 = Lab__St_1_LeftTurn;
          } else {
            v_63 = v_61;
            v_62 = v_60;
          };
          v_42 = (left_front_too_close&&left_back_too_far);
          if (v_42) {
            v_65 = true;
            v_64 = Lab__St_1_RightTurn;
          } else {
            v_65 = v_63;
            v_64 = v_62;
          };
          v_41 = (left_front_too_close&&left_back_too_close);
          if (v_41) {
            v_67 = true;
            v_66 = Lab__St_1_MoveAway;
          } else {
            v_67 = v_65;
            v_66 = v_64;
          };
          v_40 = !(front_free);
          if (v_40) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab__St_1_Turn90Right;
          } else {
            r_3_St_1_CheckState = v_67;
            s_1_St_1_CheckState = v_66;
          };
          s_1 = s_1_St_1_CheckState;
          r_3 = r_3_St_1_CheckState;
          break;
        case Lab__St_1_Turn90Right:
          r_3_St_1_Turn90Right = pnr_1;
          s_1_St_1_Turn90Right = Lab__St_1_Turn90Right;
          s_1 = s_1_St_1_Turn90Right;
          r_3 = r_3_St_1_Turn90Right;
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
          right_wheel_St_2_WallFollowing_St_1_CheckState = motorspeed_right_min;
          left_wheel_St_2_WallFollowing_St_1_CheckState = motorspeed_left_min;
          direction_St_2_WallFollowing_St_1_CheckState = 0;
          st_St_2_WallFollowing_St_1_CheckState = Lab__Error;
          nr_1_St_1_CheckState = false;
          ns_1_St_1_CheckState = Lab__St_1_CheckState;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_CheckState;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_CheckState;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_CheckState;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_CheckState;
          ns_1 = ns_1_St_1_CheckState;
          nr_1 = nr_1_St_1_CheckState;
          break;
        case Lab__St_1_Turn90Right:
          right_wheel_St_2_WallFollowing_St_1_Turn90Right = motorspeed_right_min;
          left_wheel_St_2_WallFollowing_St_1_Turn90Right = motorspeed_left_max;
          direction_St_2_WallFollowing_St_1_Turn90Right = 3;
          st_St_2_WallFollowing_St_1_Turn90Right = Lab__Turn90Right;
          v_85 = (self->v_84+d_encoder_steps_left);
          v_82 = (r_4||r_3);
          if (self->v_81) {
            v_83 = true;
          } else {
            v_83 = v_82;
          };
          if (v_83) {
            sum_encoder_steps_left = 0.000000;
          } else {
            sum_encoder_steps_left = v_85;
          };
          v_86 = (9.425000*sum_encoder_steps_left);
          finished_turn = (204.200000<v_86);
          if (finished_turn) {
            nr_1_St_1_Turn90Right = true;
            ns_1_St_1_Turn90Right = Lab__St_1_CheckState;
          } else {
            nr_1_St_1_Turn90Right = false;
            ns_1_St_1_Turn90Right = Lab__St_1_Turn90Right;
          };
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_Turn90Right;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_Turn90Right;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_Turn90Right;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_Turn90Right;
          ns_1 = ns_1_St_1_Turn90Right;
          nr_1 = nr_1_St_1_Turn90Right;
          break;
        case Lab__St_1_MoveAway:
          v_79 = (basespeed_right-motorspeed_right_min);
          v_80 = (v_79*move_away_right);
          right_wheel_St_2_WallFollowing_St_1_MoveAway = (motorspeed_right_min+v_80);
          left_wheel_St_2_WallFollowing_St_1_MoveAway = basespeed_left;
          direction_St_2_WallFollowing_St_1_MoveAway = 3;
          st_St_2_WallFollowing_St_1_MoveAway = Lab__MoveAway;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveAway;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveAway;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveAway;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveAway;
          ns_1 = ns_1_St_1_MoveAway;
          nr_1 = nr_1_St_1_MoveAway;
          break;
        case Lab__St_1_MoveCloser:
          right_wheel_St_2_WallFollowing_St_1_MoveCloser = basespeed_right;
          v_77 = (basespeed_left-motorspeed_left_min);
          v_78 = (v_77*move_closer_left);
          left_wheel_St_2_WallFollowing_St_1_MoveCloser = (motorspeed_left_min+v_78);
          direction_St_2_WallFollowing_St_1_MoveCloser = 2;
          st_St_2_WallFollowing_St_1_MoveCloser = Lab__MoveCloser;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveCloser;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveCloser;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveCloser;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveCloser;
          ns_1 = ns_1_St_1_MoveCloser;
          nr_1 = nr_1_St_1_MoveCloser;
          break;
        case Lab__St_1_RightTurn:
          right_wheel_St_2_WallFollowing_St_1_RightTurn = motorspeed_right_min;
          v_75 = (motorspeed_left_max-motorspeed_left_min);
          v_76 = (v_75*right_turn_left);
          left_wheel_St_2_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_76);
          direction_St_2_WallFollowing_St_1_RightTurn = 3;
          st_St_2_WallFollowing_St_1_RightTurn = Lab__RightTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_RightTurn;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_RightTurn;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_RightTurn;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_RightTurn;
          ns_1 = ns_1_St_1_RightTurn;
          nr_1 = nr_1_St_1_RightTurn;
          break;
        case Lab__St_1_LeftTurn:
          v_73 = (motorspeed_right_max-motorspeed_right_min);
          v_74 = (v_73*left_turn_right);
          right_wheel_St_2_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_74);
          left_wheel_St_2_WallFollowing_St_1_LeftTurn = motorspeed_left_min;
          direction_St_2_WallFollowing_St_1_LeftTurn = 2;
          st_St_2_WallFollowing_St_1_LeftTurn = Lab__LeftTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_LeftTurn;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_LeftTurn;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_LeftTurn;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_LeftTurn;
          ns_1 = ns_1_St_1_LeftTurn;
          nr_1 = nr_1_St_1_LeftTurn;
          break;
        case Lab__St_1_RightTurnSlow:
          right_wheel_St_2_WallFollowing_St_1_RightTurnSlow = motorspeed_right_min;
          v_71 = (motorspeed_left_max-motorspeed_left_min);
          v_72 = (v_71*right_turn_slow_left);
          left_wheel_St_2_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_72);
          direction_St_2_WallFollowing_St_1_RightTurnSlow = 3;
          st_St_2_WallFollowing_St_1_RightTurnSlow = Lab__RightTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_RightTurnSlow;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_RightTurnSlow;
          ns_1 = ns_1_St_1_RightTurnSlow;
          nr_1 = nr_1_St_1_RightTurnSlow;
          break;
        case Lab__St_1_LeftTurnSlow:
          v_69 = (motorspeed_right_max-motorspeed_right_min);
          v_70 = (v_69*left_turn_slow_right);
          right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_70);
          left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow = motorspeed_left_min;
          direction_St_2_WallFollowing_St_1_LeftTurnSlow = 2;
          st_St_2_WallFollowing_St_1_LeftTurnSlow = Lab__LeftTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_LeftTurnSlow;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_LeftTurnSlow;
          ns_1 = ns_1_St_1_LeftTurnSlow;
          nr_1 = nr_1_St_1_LeftTurnSlow;
          break;
        case Lab__St_1_MoveForward:
          right_wheel_St_2_WallFollowing_St_1_MoveForward = basespeed_right;
          left_wheel_St_2_WallFollowing_St_1_MoveForward = basespeed_left;
          direction_St_2_WallFollowing_St_1_MoveForward = 1;
          st_St_2_WallFollowing_St_1_MoveForward = Lab__MoveForward;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveForward;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveForward;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveForward;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveForward;
          ns_1 = ns_1_St_1_MoveForward;
          nr_1 = nr_1_St_1_MoveForward;
          break;
        default:
          break;
      };
      _out->left_wheel = left_wheel_St_2_WallFollowing;
      _out->right_wheel = right_wheel_St_2_WallFollowing;
      _out->direction = direction_St_2_WallFollowing;
      _out->st = st_St_2_WallFollowing;
      self->v_87 = nr_1;
      self->v_68 = ns_1;
      break;
    case Lab__St_2_TurnRightEnd:
      v_33 = (basespeed_right-motorspeed_left_min);
      v_34 = (v_33*turn_right_end_right);
      right_wheel_St_2_TurnRightEnd = (motorspeed_right_min+v_34);
      left_wheel_St_2_TurnRightEnd = basespeed_left;
      direction_St_2_TurnRightEnd = 3;
      st_St_2_TurnRightEnd = Lab__TurnRightEnd;
      nr_2_St_2_TurnRightEnd = false;
      ns_2_St_2_TurnRightEnd = Lab__St_2_TurnRightEnd;
      ns_2 = ns_2_St_2_TurnRightEnd;
      nr_2 = nr_2_St_2_TurnRightEnd;
      _out->left_wheel = left_wheel_St_2_TurnRightEnd;
      _out->right_wheel = right_wheel_St_2_TurnRightEnd;
      _out->direction = direction_St_2_TurnRightEnd;
      _out->st = st_St_2_TurnRightEnd;
      break;
    default:
      break;
  };
  self->l_1 = l;
  self->r_1 = r;
  self->alligned_1 = alligned;
  self->left_m_1 = left_m;
  self->left_line_1 = left_line;
  self->pnr_2 = nr_2;
  self->ck = ns_2;
  switch (ck_1) {
    case Lab__St_2_LineFollow:
      switch (ck_3) {
        case Lab__St_OnLine:
          self->v_113 = error;
          self->v_110 = false;
          self->v_108 = i;
          self->v_105 = false;
          break;
        default:
          break;
      };
      break;
    case Lab__St_2_WallFollowing:
      switch (ck_5) {
        case Lab__St_1_Turn90Right:
          self->v_84 = sum_encoder_steps_left;
          self->v_81 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

