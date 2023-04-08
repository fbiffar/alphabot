/* --- Generated the 8/4/2023 at 10:52 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_test.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_test.h"

void Lab_test__controller_reset(Lab_test__controller_mem* self) {
  self->v_129 = false;
  self->v_97 = Lab_test__St_OnLine;
  self->v_92 = true;
  self->v_86 = false;
  self->v_69 = Lab_test__St_1_CheckState;
  self->pnr_2 = false;
  self->ck = Lab_test__St_2_LineFollow;
  self->v_32 = true;
  self->v_118 = true;
  self->v_109 = true;
  self->v_104 = true;
  self->v_98 = true;
  self->v_80 = true;
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
                               float basespeed_obstacle,
                               float last_forward_mm,
                               Lab_test__controller_out* _out,
                               Lab_test__controller_mem* self) {
  
  int v_36;
  int r_4_St_2_WallFollowing;
  Lab_test__st_2 s_2_St_2_WallFollowing;
  int r_4_St_2_ObstacleFollowing;
  Lab_test__st_2 s_2_St_2_ObstacleFollowing;
  int r_4_St_2_LineFollow;
  Lab_test__st_2 s_2_St_2_LineFollow;
  int v_68;
  Lab_test__st_1 v_67;
  int v_66;
  Lab_test__st_1 v_65;
  int v_64;
  Lab_test__st_1 v_63;
  int v_62;
  Lab_test__st_1 v_61;
  int v_60;
  Lab_test__st_1 v_59;
  int v_58;
  Lab_test__st_1 v_57;
  int v_56;
  Lab_test__st_1 v_55;
  int v_54;
  Lab_test__st_1 v_53;
  int v_52;
  Lab_test__st_1 v_51;
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
  float v_71;
  float v_70;
  float v_73;
  float v_72;
  float v_75;
  float v_74;
  float v_77;
  float v_76;
  float v_79;
  float v_78;
  float v_85;
  float v_84;
  int v_82;
  int v_81;
  float sum_encoder_steps;
  int finished_turn;
  int nr_1_St_1_MoveForward;
  Lab_test__st_1 ns_1_St_1_MoveForward;
  Lab_test__stateName st_St_2_WallFollowing_St_1_MoveForward;
  int direction_St_2_WallFollowing_St_1_MoveForward;
  float right_wheel_St_2_WallFollowing_St_1_MoveForward;
  float left_wheel_St_2_WallFollowing_St_1_MoveForward;
  int nr_1_St_1_LeftTurnSlow;
  Lab_test__st_1 ns_1_St_1_LeftTurnSlow;
  Lab_test__stateName st_St_2_WallFollowing_St_1_LeftTurnSlow;
  int direction_St_2_WallFollowing_St_1_LeftTurnSlow;
  float right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
  float left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
  int nr_1_St_1_RightTurnSlow;
  Lab_test__st_1 ns_1_St_1_RightTurnSlow;
  Lab_test__stateName st_St_2_WallFollowing_St_1_RightTurnSlow;
  int direction_St_2_WallFollowing_St_1_RightTurnSlow;
  float right_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
  float left_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
  int nr_1_St_1_LeftTurn;
  Lab_test__st_1 ns_1_St_1_LeftTurn;
  Lab_test__stateName st_St_2_WallFollowing_St_1_LeftTurn;
  int direction_St_2_WallFollowing_St_1_LeftTurn;
  float right_wheel_St_2_WallFollowing_St_1_LeftTurn;
  float left_wheel_St_2_WallFollowing_St_1_LeftTurn;
  int nr_1_St_1_RightTurn;
  Lab_test__st_1 ns_1_St_1_RightTurn;
  Lab_test__stateName st_St_2_WallFollowing_St_1_RightTurn;
  int direction_St_2_WallFollowing_St_1_RightTurn;
  float right_wheel_St_2_WallFollowing_St_1_RightTurn;
  float left_wheel_St_2_WallFollowing_St_1_RightTurn;
  int nr_1_St_1_MoveCloser;
  Lab_test__st_1 ns_1_St_1_MoveCloser;
  Lab_test__stateName st_St_2_WallFollowing_St_1_MoveCloser;
  int direction_St_2_WallFollowing_St_1_MoveCloser;
  float right_wheel_St_2_WallFollowing_St_1_MoveCloser;
  float left_wheel_St_2_WallFollowing_St_1_MoveCloser;
  int nr_1_St_1_MoveAway;
  Lab_test__st_1 ns_1_St_1_MoveAway;
  Lab_test__stateName st_St_2_WallFollowing_St_1_MoveAway;
  int direction_St_2_WallFollowing_St_1_MoveAway;
  float right_wheel_St_2_WallFollowing_St_1_MoveAway;
  float left_wheel_St_2_WallFollowing_St_1_MoveAway;
  int nr_1_St_1_Turn90Left;
  Lab_test__st_1 ns_1_St_1_Turn90Left;
  Lab_test__stateName st_St_2_WallFollowing_St_1_Turn90Left;
  int direction_St_2_WallFollowing_St_1_Turn90Left;
  float right_wheel_St_2_WallFollowing_St_1_Turn90Left;
  float left_wheel_St_2_WallFollowing_St_1_Turn90Left;
  int nr_1_St_1_CheckState;
  Lab_test__st_1 ns_1_St_1_CheckState;
  Lab_test__stateName st_St_2_WallFollowing_St_1_CheckState;
  int direction_St_2_WallFollowing_St_1_CheckState;
  float right_wheel_St_2_WallFollowing_St_1_CheckState;
  float left_wheel_St_2_WallFollowing_St_1_CheckState;
  Lab_test__st_1 ck_5;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  Lab_test__st_1 s_1;
  Lab_test__st_1 ns_1;
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
  float v_95;
  int v_93;
  int v_91;
  Lab_test__st_2 v_90;
  int v_89;
  int v_88;
  int v_87;
  float counter;
  int v_96;
  int r_2_St_LostLine;
  Lab_test__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab_test__st s_St_OnLine;
  Lab_test__st ck_2;
  int v_100;
  int v_99;
  float v_128;
  float v_127;
  float v_126;
  float v_125;
  float v_124;
  int v_122;
  int v_121;
  int v_120;
  int v_119;
  float v_117;
  float v_116;
  float v_115;
  float v_114;
  float v_113;
  int v_111;
  int v_110;
  float v_108;
  int v_106;
  int v_105;
  float v_103;
  float v_102;
  float error;
  float p;
  float i;
  float d;
  float correction;
  int nr_St_LostLine;
  Lab_test__st ns_St_LostLine;
  float parking_distance_St_LostLine;
  Lab_test__stateName st_St_2_LineFollow_St_LostLine;
  int direction_St_2_LineFollow_St_LostLine;
  float right_wheel_St_2_LineFollow_St_LostLine;
  float left_wheel_St_2_LineFollow_St_LostLine;
  int nr_St_OnLine;
  Lab_test__st ns_St_OnLine;
  float parking_distance_St_OnLine;
  Lab_test__stateName st_St_2_LineFollow_St_OnLine;
  int direction_St_2_LineFollow_St_OnLine;
  float right_wheel_St_2_LineFollow_St_OnLine;
  float left_wheel_St_2_LineFollow_St_OnLine;
  Lab_test__st ck_3;
  Lab_test__st s;
  Lab_test__st ns;
  int r_2;
  int nr;
  int pnr;
  float parking_distance;
  int nr_2_St_2_WallFollowing;
  Lab_test__st_2 ns_2_St_2_WallFollowing;
  Lab_test__stateName st_St_2_WallFollowing;
  int direction_St_2_WallFollowing;
  float right_wheel_St_2_WallFollowing;
  float left_wheel_St_2_WallFollowing;
  int nr_2_St_2_ObstacleFollowing;
  Lab_test__st_2 ns_2_St_2_ObstacleFollowing;
  Lab_test__stateName st_St_2_ObstacleFollowing;
  int direction_St_2_ObstacleFollowing;
  float right_wheel_St_2_ObstacleFollowing;
  float left_wheel_St_2_ObstacleFollowing;
  int nr_2_St_2_LineFollow;
  Lab_test__st_2 ns_2_St_2_LineFollow;
  Lab_test__stateName st_St_2_LineFollow;
  int direction_St_2_LineFollow;
  float right_wheel_St_2_LineFollow;
  float left_wheel_St_2_LineFollow;
  Lab_test__st_2 ck_1;
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
  Lab_test__st_2 s_2;
  Lab_test__st_2 ns_2;
  int r_4;
  int nr_2;
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
    case Lab_test__St_2_LineFollow:
      v_36 = !(ir_front);
      if (v_36) {
        r_4_St_2_LineFollow = true;
        s_2_St_2_LineFollow = Lab_test__St_2_ObstacleFollowing;
      } else {
        r_4_St_2_LineFollow = self->pnr_2;
        s_2_St_2_LineFollow = Lab_test__St_2_LineFollow;
      };
      s_2 = s_2_St_2_LineFollow;
      r_4 = r_4_St_2_LineFollow;
      break;
    case Lab_test__St_2_ObstacleFollowing:
      r_4_St_2_ObstacleFollowing = self->pnr_2;
      s_2_St_2_ObstacleFollowing = Lab_test__St_2_ObstacleFollowing;
      s_2 = s_2_St_2_ObstacleFollowing;
      r_4 = r_4_St_2_ObstacleFollowing;
      break;
    case Lab_test__St_2_WallFollowing:
      r_4_St_2_WallFollowing = self->pnr_2;
      s_2_St_2_WallFollowing = Lab_test__St_2_WallFollowing;
      s_2 = s_2_St_2_WallFollowing;
      r_4 = r_4_St_2_WallFollowing;
      break;
    default:
      break;
  };
  ck_1 = s_2;
  switch (ck_1) {
    case Lab_test__St_2_LineFollow:
      if (r_4) {
        pnr = false;
        ck_2 = Lab_test__St_OnLine;
      } else {
        pnr = self->v_129;
        ck_2 = self->v_97;
      };
      nr_2_St_2_LineFollow = false;
      ns_2_St_2_LineFollow = Lab_test__St_2_LineFollow;
      ns_2 = ns_2_St_2_LineFollow;
      nr_2 = nr_2_St_2_LineFollow;
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
          v_96 = !(left_m);
          if (v_96) {
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
          right_wheel_St_2_LineFollow_St_OnLine = 0.000000;
          left_wheel_St_2_LineFollow_St_OnLine = 0.000000;
          direction_St_2_LineFollow_St_OnLine = 0;
          st_St_2_LineFollow_St_OnLine = Lab_test__OnLine;
          v_124 = (d_encoder_steps_right+d_encoder_steps_left);
          v_125 = (v_124/2.000000);
          v_126 = (v_125*9.425000);
          v_127 = (self->v_123+v_126);
          v_121 = !(car_to_the_right);
          v_122 = (first_car&&v_121);
          if (v_122) {
            v_128 = v_127;
          } else {
            v_128 = 0.000000;
          };
          v_119 = (r_4||r_2);
          if (self->v_118) {
            v_120 = true;
          } else {
            v_120 = v_119;
          };
          if (v_120) {
            parking_distance_St_OnLine = 0.000000;
          } else {
            parking_distance_St_OnLine = v_128;
          };
          v_110 = (r_4||r_2);
          if (self->v_109) {
            v_111 = true;
          } else {
            v_111 = v_110;
          };
          v_105 = (r_4||r_2);
          if (self->v_104) {
            v_106 = true;
          } else {
            v_106 = v_105;
          };
          v_103 = (l-r);
          v_102 = (r-l);
          if (white_line) {
            error = v_102;
          } else {
            error = v_103;
          };
          v_113 = (error-self->v_112);
          if (v_111) {
            d = error;
          } else {
            d = v_113;
          };
          v_117 = (d*kD);
          v_108 = (self->v_107+error);
          if (v_106) {
            i = error;
          } else {
            i = v_108;
          };
          v_115 = (i*kI);
          p = error;
          v_114 = (p*kP);
          v_116 = (v_114+v_115);
          correction = (v_116+v_117);
          nr_St_OnLine = false;
          ns_St_OnLine = Lab_test__St_OnLine;
          left_wheel_St_2_LineFollow = left_wheel_St_2_LineFollow_St_OnLine;
          right_wheel_St_2_LineFollow = right_wheel_St_2_LineFollow_St_OnLine;
          direction_St_2_LineFollow = direction_St_2_LineFollow_St_OnLine;
          st_St_2_LineFollow = st_St_2_LineFollow_St_OnLine;
          parking_distance = parking_distance_St_OnLine;
          ns = ns_St_OnLine;
          nr = nr_St_OnLine;
          break;
        case Lab_test__St_LostLine:
          right_wheel_St_2_LineFollow_St_LostLine = 0.000000;
          left_wheel_St_2_LineFollow_St_LostLine = 0.000000;
          direction_St_2_LineFollow_St_LostLine = 0;
          st_St_2_LineFollow_St_LostLine = Lab_test__LostLine;
          v_99 = (r_4||r_2);
          if (self->v_98) {
            v_100 = true;
          } else {
            v_100 = v_99;
          };
          if (v_100) {
            parking_distance_St_LostLine = 0.000000;
          } else {
            parking_distance_St_LostLine = self->v_101;
          };
          nr_St_LostLine = false;
          ns_St_LostLine = Lab_test__St_LostLine;
          left_wheel_St_2_LineFollow = left_wheel_St_2_LineFollow_St_LostLine;
          right_wheel_St_2_LineFollow = right_wheel_St_2_LineFollow_St_LostLine;
          direction_St_2_LineFollow = direction_St_2_LineFollow_St_LostLine;
          st_St_2_LineFollow = st_St_2_LineFollow_St_LostLine;
          parking_distance = parking_distance_St_LostLine;
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
      self->parking_distance_1 = parking_distance;
      self->v_129 = nr;
      self->v_97 = ns;
      break;
    case Lab_test__St_2_ObstacleFollowing:
      right_wheel_St_2_ObstacleFollowing = 0.000000;
      left_wheel_St_2_ObstacleFollowing = 0.000000;
      direction_St_2_ObstacleFollowing = 0;
      st_St_2_ObstacleFollowing = Lab_test__ObstacleFollowing;
      v_95 = (self->v_94+1.000000);
      if (self->v_92) {
        v_93 = true;
      } else {
        v_93 = r_4;
      };
      if (v_93) {
        counter = 0.000000;
      } else {
        counter = v_95;
      };
      if (ir_front) {
        v_91 = true;
        v_90 = Lab_test__St_2_LineFollow;
      } else {
        v_91 = false;
        v_90 = Lab_test__St_2_ObstacleFollowing;
      };
      v_88 = !(ir_front);
      v_87 = (counter>=waiting_threshold);
      v_89 = (v_87&&v_88);
      if (v_89) {
        nr_2_St_2_ObstacleFollowing = true;
        ns_2_St_2_ObstacleFollowing = Lab_test__St_2_WallFollowing;
      } else {
        nr_2_St_2_ObstacleFollowing = v_91;
        ns_2_St_2_ObstacleFollowing = v_90;
      };
      ns_2 = ns_2_St_2_ObstacleFollowing;
      nr_2 = nr_2_St_2_ObstacleFollowing;
      _out->left_wheel = left_wheel_St_2_ObstacleFollowing;
      _out->right_wheel = right_wheel_St_2_ObstacleFollowing;
      _out->direction = direction_St_2_ObstacleFollowing;
      _out->st = st_St_2_ObstacleFollowing;
      self->v_94 = counter;
      self->v_92 = false;
      break;
    case Lab_test__St_2_WallFollowing:
      if (r_4) {
        pnr_1 = false;
        ck_4 = Lab_test__St_1_CheckState;
      } else {
        pnr_1 = self->v_86;
        ck_4 = self->v_69;
      };
      right_back_too_far = ir_left_b2;
      v_40 = !(right_back_too_far);
      right_back_too_close = !(ir_left_b1);
      v_39 = !(right_back_too_close);
      right_back_correct = (v_39&&v_40);
      right_front_too_far = ir_left_f2;
      v_38 = !(right_front_too_far);
      right_front_too_close = !(ir_left_f1);
      v_37 = !(right_front_too_close);
      right_front_correct = (v_37&&v_38);
      front_free = ir_front;
      nr_2_St_2_WallFollowing = false;
      ns_2_St_2_WallFollowing = Lab_test__St_2_WallFollowing;
      ns_2 = ns_2_St_2_WallFollowing;
      nr_2 = nr_2_St_2_WallFollowing;
      switch (ck_4) {
        case Lab_test__St_1_CheckState:
          v_50 = (right_front_correct&&right_back_correct);
          if (v_50) {
            v_52 = true;
            v_51 = Lab_test__St_1_MoveForward;
          } else {
            v_52 = pnr_1;
            v_51 = Lab_test__St_1_CheckState;
          };
          v_49 = (right_front_too_far&&right_back_correct);
          if (v_49) {
            v_54 = true;
            v_53 = Lab_test__St_1_RightTurnSlow;
          } else {
            v_54 = v_52;
            v_53 = v_51;
          };
          v_48 = (right_front_too_close&&right_back_correct);
          if (v_48) {
            v_56 = true;
            v_55 = Lab_test__St_1_LeftTurnSlow;
          } else {
            v_56 = v_54;
            v_55 = v_53;
          };
          v_47 = (right_front_correct&&right_back_too_far);
          if (v_47) {
            v_58 = true;
            v_57 = Lab_test__St_1_LeftTurnSlow;
          } else {
            v_58 = v_56;
            v_57 = v_55;
          };
          v_46 = (right_front_correct&&right_back_too_close);
          if (v_46) {
            v_60 = true;
            v_59 = Lab_test__St_1_RightTurnSlow;
          } else {
            v_60 = v_58;
            v_59 = v_57;
          };
          v_45 = (right_front_too_far&&right_back_too_far);
          if (v_45) {
            v_62 = true;
            v_61 = Lab_test__St_1_MoveCloser;
          } else {
            v_62 = v_60;
            v_61 = v_59;
          };
          v_44 = (right_front_too_far&&right_back_too_close);
          if (v_44) {
            v_64 = true;
            v_63 = Lab_test__St_1_RightTurn;
          } else {
            v_64 = v_62;
            v_63 = v_61;
          };
          v_43 = (right_front_too_close&&right_back_too_close);
          if (v_43) {
            v_66 = true;
            v_65 = Lab_test__St_1_MoveAway;
          } else {
            v_66 = v_64;
            v_65 = v_63;
          };
          v_42 = (right_front_too_close&&right_back_too_far);
          if (v_42) {
            v_68 = true;
            v_67 = Lab_test__St_1_LeftTurn;
          } else {
            v_68 = v_66;
            v_67 = v_65;
          };
          v_41 = !(front_free);
          if (v_41) {
            r_3_St_1_CheckState = true;
            s_1_St_1_CheckState = Lab_test__St_1_Turn90Left;
          } else {
            r_3_St_1_CheckState = v_68;
            s_1_St_1_CheckState = v_67;
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
          right_wheel_St_2_WallFollowing_St_1_CheckState = 0.000000;
          left_wheel_St_2_WallFollowing_St_1_CheckState = 0.000000;
          direction_St_2_WallFollowing_St_1_CheckState = 0;
          st_St_2_WallFollowing_St_1_CheckState = Lab_test__Error;
          nr_1_St_1_CheckState = false;
          ns_1_St_1_CheckState = Lab_test__St_1_CheckState;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_CheckState;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_CheckState;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_CheckState;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_CheckState;
          ns_1 = ns_1_St_1_CheckState;
          nr_1 = nr_1_St_1_CheckState;
          break;
        case Lab_test__St_1_Turn90Left:
          right_wheel_St_2_WallFollowing_St_1_Turn90Left = basespeed_obstacle;
          left_wheel_St_2_WallFollowing_St_1_Turn90Left = 0.000000;
          direction_St_2_WallFollowing_St_1_Turn90Left = 3;
          st_St_2_WallFollowing_St_1_Turn90Left = Lab_test__Turn90Left;
          v_84 = (self->v_83+d_encoder_steps_right);
          v_81 = (r_4||r_3);
          if (self->v_80) {
            v_82 = true;
          } else {
            v_82 = v_81;
          };
          if (v_82) {
            sum_encoder_steps = 0.000000;
          } else {
            sum_encoder_steps = v_84;
          };
          v_85 = (9.425000*sum_encoder_steps);
          finished_turn = (184.200000<v_85);
          if (finished_turn) {
            nr_1_St_1_Turn90Left = true;
            ns_1_St_1_Turn90Left = Lab_test__St_1_CheckState;
          } else {
            nr_1_St_1_Turn90Left = false;
            ns_1_St_1_Turn90Left = Lab_test__St_1_Turn90Left;
          };
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_Turn90Left;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_Turn90Left;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_Turn90Left;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_Turn90Left;
          ns_1 = ns_1_St_1_Turn90Left;
          nr_1 = nr_1_St_1_Turn90Left;
          break;
        case Lab_test__St_1_MoveAway:
          right_wheel_St_2_WallFollowing_St_1_MoveAway = basespeed_obstacle;
          v_78 = (basespeed_obstacle-motorspeed_left_min);
          v_79 = (v_78*move_closer_left);
          left_wheel_St_2_WallFollowing_St_1_MoveAway = (motorspeed_left_min+v_79);
          direction_St_2_WallFollowing_St_1_MoveAway = 2;
          st_St_2_WallFollowing_St_1_MoveAway = Lab_test__MoveAway;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveAway;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveAway;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveAway;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveAway;
          ns_1 = ns_1_St_1_MoveAway;
          nr_1 = nr_1_St_1_MoveAway;
          break;
        case Lab_test__St_1_MoveCloser:
          right_wheel_St_2_WallFollowing_St_1_MoveCloser = (motorspeed_right_min*move_away_right);
          left_wheel_St_2_WallFollowing_St_1_MoveCloser = basespeed_obstacle;
          direction_St_2_WallFollowing_St_1_MoveCloser = 3;
          st_St_2_WallFollowing_St_1_MoveCloser = Lab_test__MoveCloser;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveCloser;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveCloser;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveCloser;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveCloser;
          ns_1 = ns_1_St_1_MoveCloser;
          nr_1 = nr_1_St_1_MoveCloser;
          break;
        case Lab_test__St_1_RightTurn:
          right_wheel_St_2_WallFollowing_St_1_RightTurn = 0.000000;
          v_76 = (motorspeed_left_max-motorspeed_left_min);
          v_77 = (v_76*right_turn_left);
          left_wheel_St_2_WallFollowing_St_1_RightTurn = (motorspeed_left_min+v_77);
          direction_St_2_WallFollowing_St_1_RightTurn = 3;
          st_St_2_WallFollowing_St_1_RightTurn = Lab_test__RightTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_RightTurn;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_RightTurn;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_RightTurn;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_RightTurn;
          ns_1 = ns_1_St_1_RightTurn;
          nr_1 = nr_1_St_1_RightTurn;
          break;
        case Lab_test__St_1_LeftTurn:
          v_74 = (motorspeed_right_max-motorspeed_right_min);
          v_75 = (v_74*left_turn_right);
          right_wheel_St_2_WallFollowing_St_1_LeftTurn = (motorspeed_right_min+v_75);
          left_wheel_St_2_WallFollowing_St_1_LeftTurn = 0.000000;
          direction_St_2_WallFollowing_St_1_LeftTurn = 2;
          st_St_2_WallFollowing_St_1_LeftTurn = Lab_test__LeftTurn;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_LeftTurn;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_LeftTurn;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_LeftTurn;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_LeftTurn;
          ns_1 = ns_1_St_1_LeftTurn;
          nr_1 = nr_1_St_1_LeftTurn;
          break;
        case Lab_test__St_1_RightTurnSlow:
          right_wheel_St_2_WallFollowing_St_1_RightTurnSlow = 0.000000;
          v_72 = (motorspeed_left_max-motorspeed_left_min);
          v_73 = (v_72*right_turn_slow_left);
          left_wheel_St_2_WallFollowing_St_1_RightTurnSlow = (motorspeed_left_min+v_73);
          direction_St_2_WallFollowing_St_1_RightTurnSlow = 3;
          st_St_2_WallFollowing_St_1_RightTurnSlow = Lab_test__RightTurnSlow;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_RightTurnSlow;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_RightTurnSlow;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_RightTurnSlow;
          ns_1 = ns_1_St_1_RightTurnSlow;
          nr_1 = nr_1_St_1_RightTurnSlow;
          break;
        case Lab_test__St_1_LeftTurnSlow:
          v_70 = (motorspeed_right_max-motorspeed_right_min);
          v_71 = (v_70*left_turn_slow_right);
          right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow = (motorspeed_right_min+v_71);
          left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow = motorspeed_left_min;
          direction_St_2_WallFollowing_St_1_LeftTurnSlow = 2;
          st_St_2_WallFollowing_St_1_LeftTurnSlow = Lab_test__LeftTurnSlow;
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
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_LeftTurnSlow;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_LeftTurnSlow;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_LeftTurnSlow;
          ns_1 = ns_1_St_1_LeftTurnSlow;
          nr_1 = nr_1_St_1_LeftTurnSlow;
          break;
        case Lab_test__St_1_MoveForward:
          right_wheel_St_2_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          left_wheel_St_2_WallFollowing_St_1_MoveForward = basespeed_obstacle;
          direction_St_2_WallFollowing_St_1_MoveForward = 1;
          st_St_2_WallFollowing_St_1_MoveForward = Lab_test__MoveForward;
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
      self->v_86 = nr_1;
      self->v_69 = ns_1;
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
  self->pnr_2 = nr_2;
  self->ck = ns_2;
  self->v_34 = first_car;
  self->v_32 = false;
  switch (ck_1) {
    case Lab_test__St_2_LineFollow:
      switch (ck_3) {
        case Lab_test__St_OnLine:
          self->v_123 = parking_distance;
          self->v_118 = false;
          self->v_112 = error;
          self->v_109 = false;
          self->v_107 = i;
          self->v_104 = false;
          break;
        case Lab_test__St_LostLine:
          self->v_101 = parking_distance;
          self->v_98 = false;
          break;
        default:
          break;
      };
      break;
    case Lab_test__St_2_WallFollowing:
      switch (ck_5) {
        case Lab_test__St_1_Turn90Left:
          self->v_83 = sum_encoder_steps;
          self->v_80 = false;
          break;
        default:
          break;
      };
      break;
    default:
      break;
  };;
}

