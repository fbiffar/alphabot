/* --- Generated the 26/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab.h"

void Lab__controller_reset(Lab__controller_mem* self) {
  self->v_207 = false;
  self->v_198 = Lab__St_OnLine;
  self->v_196 = false;
  self->v_183 = Lab__St_1_ObstacleFront;
  self->pnr_2 = false;
  self->ck = Lab__St_2_LineFollow;
}

void Lab__controller_step(int l2, int l1, int m, int r1, int r2,
                          int ir_front, int ir_front_left, int ir_side_front,
                          int ir_side, int ir_side_back,
                          Lab__controller_out* _out,
                          Lab__controller_mem* self) {
  
  int v_14;
  int v_15;
  int r_4_St_2_ToFollowPosition;
  Lab__st_2 s_2_St_2_ToFollowPosition;
  int r_4_St_2_WallFollowing;
  Lab__st_2 s_2_St_2_WallFollowing;
  int r_4_St_2_LineFollow;
  Lab__st_2 s_2_St_2_LineFollow;
  int v_43;
  Lab__st_1 v_42;
  int v_41;
  Lab__st_1 v_40;
  int v_39;
  Lab__st_1 v_38;
  int v_37;
  Lab__st_1 v_36;
  int v_35;
  int v_34;
  int v_33;
  int v_32;
  int v_31;
  int v_30;
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
  int v_68;
  Lab__st_1 v_67;
  int v_66;
  Lab__st_1 v_65;
  int v_64;
  Lab__st_1 v_63;
  int v_62;
  Lab__st_1 v_61;
  int v_60;
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
  int v_95;
  Lab__st_1 v_94;
  int v_93;
  Lab__st_1 v_92;
  int v_91;
  Lab__st_1 v_90;
  int v_89;
  Lab__st_1 v_88;
  int v_87;
  int v_86;
  int v_85;
  int v_84;
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
  int v_72;
  int v_71;
  int v_70;
  int v_69;
  int v_122;
  Lab__st_1 v_121;
  int v_120;
  Lab__st_1 v_119;
  int v_118;
  Lab__st_1 v_117;
  int v_116;
  Lab__st_1 v_115;
  int v_114;
  int v_113;
  int v_112;
  int v_111;
  int v_110;
  int v_109;
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
  int v_98;
  int v_97;
  int v_96;
  int v_152;
  Lab__st_1 v_151;
  int v_150;
  Lab__st_1 v_149;
  int v_148;
  Lab__st_1 v_147;
  int v_146;
  Lab__st_1 v_145;
  int v_144;
  int v_143;
  int v_142;
  int v_141;
  int v_140;
  int v_139;
  int v_138;
  int v_137;
  int v_136;
  int v_135;
  int v_134;
  int v_133;
  int v_132;
  int v_131;
  int v_130;
  int v_129;
  int v_128;
  int v_127;
  int v_126;
  int v_125;
  int v_124;
  int v_123;
  int v_182;
  Lab__st_1 v_181;
  int v_180;
  Lab__st_1 v_179;
  int v_178;
  Lab__st_1 v_177;
  int v_176;
  Lab__st_1 v_175;
  int v_174;
  int v_173;
  int v_172;
  int v_171;
  int v_170;
  int v_169;
  int v_168;
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
  int v_157;
  int v_156;
  int v_155;
  int v_154;
  int v_153;
  int r_3_St_1_MoveForward;
  Lab__st_1 s_1_St_1_MoveForward;
  int r_3_St_1_MoveCloser;
  Lab__st_1 s_1_St_1_MoveCloser;
  int r_3_St_1_MoveAway;
  Lab__st_1 s_1_St_1_MoveAway;
  int r_3_St_1_MakeParallel;
  Lab__st_1 s_1_St_1_MakeParallel;
  int r_3_St_1_TurnLeft;
  Lab__st_1 s_1_St_1_TurnLeft;
  int r_3_St_1_ObstacleFront;
  Lab__st_1 s_1_St_1_ObstacleFront;
  Lab__st_1 ck_4;
  int v_195;
  int v_194;
  int v_193;
  int v_192;
  int v_191;
  int v_190;
  int v_189;
  int v_188;
  int v_187;
  int v_186;
  int v_185;
  int v_184;
  int diff;
  int correctSpeed;
  int nr_1_St_1_MoveForward;
  Lab__st_1 ns_1_St_1_MoveForward;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveForward;
  int direction_St_2_WallFollowing_St_1_MoveForward;
  int right_wheel_St_2_WallFollowing_St_1_MoveForward;
  int left_wheel_St_2_WallFollowing_St_1_MoveForward;
  int nr_1_St_1_MoveCloser;
  Lab__st_1 ns_1_St_1_MoveCloser;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveCloser;
  int direction_St_2_WallFollowing_St_1_MoveCloser;
  int right_wheel_St_2_WallFollowing_St_1_MoveCloser;
  int left_wheel_St_2_WallFollowing_St_1_MoveCloser;
  int nr_1_St_1_MoveAway;
  Lab__st_1 ns_1_St_1_MoveAway;
  Lab__stateName st_St_2_WallFollowing_St_1_MoveAway;
  int direction_St_2_WallFollowing_St_1_MoveAway;
  int right_wheel_St_2_WallFollowing_St_1_MoveAway;
  int left_wheel_St_2_WallFollowing_St_1_MoveAway;
  int nr_1_St_1_MakeParallel;
  Lab__st_1 ns_1_St_1_MakeParallel;
  Lab__stateName st_St_2_WallFollowing_St_1_MakeParallel;
  int direction_St_2_WallFollowing_St_1_MakeParallel;
  int right_wheel_St_2_WallFollowing_St_1_MakeParallel;
  int left_wheel_St_2_WallFollowing_St_1_MakeParallel;
  int nr_1_St_1_TurnLeft;
  Lab__st_1 ns_1_St_1_TurnLeft;
  Lab__stateName st_St_2_WallFollowing_St_1_TurnLeft;
  int direction_St_2_WallFollowing_St_1_TurnLeft;
  int right_wheel_St_2_WallFollowing_St_1_TurnLeft;
  int left_wheel_St_2_WallFollowing_St_1_TurnLeft;
  int nr_1_St_1_ObstacleFront;
  Lab__st_1 ns_1_St_1_ObstacleFront;
  Lab__stateName st_St_2_WallFollowing_St_1_ObstacleFront;
  int direction_St_2_WallFollowing_St_1_ObstacleFront;
  int right_wheel_St_2_WallFollowing_St_1_ObstacleFront;
  int left_wheel_St_2_WallFollowing_St_1_ObstacleFront;
  Lab__st_1 ck_5;
  int v_19;
  int v_18;
  int v_17;
  int v_16;
  Lab__st_1 s_1;
  Lab__st_1 ns_1;
  int r_3;
  int nr_1;
  int pnr_1;
  int front_free;
  int corner;
  int parallel;
  int too_close;
  int too_far;
  int v_197;
  int r_2_St_LostLine;
  Lab__st s_St_LostLine;
  int r_2_St_OnLine;
  Lab__st s_St_OnLine;
  Lab__st ck_2;
  int v_206;
  int v_205;
  int v_204;
  int v_203;
  int v_202;
  int v_201;
  int v_200;
  int v_199;
  int nr_St_LostLine;
  Lab__st ns_St_LostLine;
  Lab__stateName st_St_2_LineFollow_St_LostLine;
  int direction_St_2_LineFollow_St_LostLine;
  int right_wheel_St_2_LineFollow_St_LostLine;
  int left_wheel_St_2_LineFollow_St_LostLine;
  int nr_St_OnLine;
  Lab__st ns_St_OnLine;
  Lab__stateName st_St_2_LineFollow_St_OnLine;
  int direction_St_2_LineFollow_St_OnLine;
  int right_wheel_St_2_LineFollow_St_OnLine;
  int left_wheel_St_2_LineFollow_St_OnLine;
  Lab__st ck_3;
  Lab__st s;
  Lab__st ns;
  int r_2;
  int nr;
  int pnr;
  int nr_2_St_2_ToFollowPosition;
  Lab__st_2 ns_2_St_2_ToFollowPosition;
  Lab__stateName st_St_2_ToFollowPosition;
  int direction_St_2_ToFollowPosition;
  int right_wheel_St_2_ToFollowPosition;
  int left_wheel_St_2_ToFollowPosition;
  int nr_2_St_2_WallFollowing;
  Lab__st_2 ns_2_St_2_WallFollowing;
  Lab__stateName st_St_2_WallFollowing;
  int direction_St_2_WallFollowing;
  int right_wheel_St_2_WallFollowing;
  int left_wheel_St_2_WallFollowing;
  int nr_2_St_2_LineFollow;
  Lab__st_2 ns_2_St_2_LineFollow;
  Lab__stateName st_St_2_LineFollow;
  int direction_St_2_LineFollow;
  int right_wheel_St_2_LineFollow;
  int left_wheel_St_2_LineFollow;
  Lab__st_2 ck_1;
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
  int alligned;
  int r;
  int l;
  Lab__stateName st;
  v_13 = (Lab__c2*l2);
  l = (l1+v_13);
  v_12 = (Lab__c2*r2);
  r = (r1+v_12);
  v_11 = (r1<400);
  v_9 = (m<Lab__line_threshold);
  v_8 = (l1<400);
  v_10 = (v_8||v_9);
  alligned = (v_10||v_11);
  v_7 = (r2>Lab__line_threshold);
  v_5 = (r1>Lab__line_threshold);
  v_3 = (m>Lab__line_threshold);
  v_1 = (l1>Lab__line_threshold);
  v = (l2>Lab__line_threshold);
  v_2 = (v&&v_1);
  v_4 = (v_2&&v_3);
  v_6 = (v_4&&v_5);
  left_line = (v_6&&v_7);
  switch (self->ck) {
    case Lab__St_2_LineFollow:
      v_15 = (ir_front<Lab__min_front);
      if (v_15) {
        r_4_St_2_LineFollow = true;
        s_2_St_2_LineFollow = Lab__St_2_WallFollowing;
      } else {
        r_4_St_2_LineFollow = self->pnr_2;
        s_2_St_2_LineFollow = Lab__St_2_LineFollow;
      };
      s_2 = s_2_St_2_LineFollow;
      r_4 = r_4_St_2_LineFollow;
      break;
    case Lab__St_2_WallFollowing:
      v_14 = !(left_line);
      if (v_14) {
        r_4_St_2_WallFollowing = true;
        s_2_St_2_WallFollowing = Lab__St_2_ToFollowPosition;
      } else {
        r_4_St_2_WallFollowing = self->pnr_2;
        s_2_St_2_WallFollowing = Lab__St_2_WallFollowing;
      };
      s_2 = s_2_St_2_WallFollowing;
      r_4 = r_4_St_2_WallFollowing;
      break;
    case Lab__St_2_ToFollowPosition:
      if (alligned) {
        r_4_St_2_ToFollowPosition = true;
        s_2_St_2_ToFollowPosition = Lab__St_2_LineFollow;
      } else {
        r_4_St_2_ToFollowPosition = self->pnr_2;
        s_2_St_2_ToFollowPosition = Lab__St_2_ToFollowPosition;
      };
      s_2 = s_2_St_2_ToFollowPosition;
      r_4 = r_4_St_2_ToFollowPosition;
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
        pnr = self->v_207;
        ck_2 = self->v_198;
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
          v_197 = (m>Lab__line_threshold);
          if (v_197) {
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
          v_204 = (l-r);
          v_205 = (v_204/Lab__c1);
          v_206 = (Lab__speed-v_205);
          v_203 = (r<l);
          if (v_203) {
            right_wheel_St_2_LineFollow_St_OnLine = v_206;
          } else {
            right_wheel_St_2_LineFollow_St_OnLine = 100;
          };
          v_200 = (r-l);
          v_201 = (v_200/Lab__c1);
          v_202 = (Lab__speed-v_201);
          v_199 = (r<l);
          if (v_199) {
            left_wheel_St_2_LineFollow_St_OnLine = 100;
          } else {
            left_wheel_St_2_LineFollow_St_OnLine = v_202;
          };
          direction_St_2_LineFollow_St_OnLine = 1;
          st_St_2_LineFollow_St_OnLine = Lab__OnLine;
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
          right_wheel_St_2_LineFollow_St_LostLine = 25;
          left_wheel_St_2_LineFollow_St_LostLine = 25;
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
      st = st_St_2_LineFollow;
      self->v_207 = nr;
      self->v_198 = ns;
      break;
    case Lab__St_2_WallFollowing:
      if (r_4) {
        pnr_1 = false;
        ck_4 = Lab__St_1_ObstacleFront;
      } else {
        pnr_1 = self->v_196;
        ck_4 = self->v_183;
      };
      too_far = (ir_side>Lab__max_wall);
      too_close = (ir_side<Lab__min_wall);
      v_18 = (ir_side_back-Lab__parallel_threshold);
      v_19 = (ir_side_front>v_18);
      v_16 = (ir_side_back+Lab__parallel_threshold);
      v_17 = (ir_side_front<v_16);
      parallel = (v_17&&v_19);
      corner = (ir_front_left>Lab__min_front_left);
      front_free = (ir_front>Lab__min_front);
      nr_2_St_2_WallFollowing = false;
      ns_2_St_2_WallFollowing = Lab__St_2_WallFollowing;
      ns_2 = ns_2_St_2_WallFollowing;
      nr_2 = nr_2_St_2_WallFollowing;
      switch (ck_4) {
        case Lab__St_1_ObstacleFront:
          v_173 = !(too_far);
          v_171 = !(too_close);
          v_168 = !(corner);
          v_169 = (front_free&&v_168);
          v_170 = (v_169&&parallel);
          v_172 = (v_170&&v_171);
          v_174 = (v_172&&v_173);
          if (v_174) {
            v_176 = true;
            v_175 = Lab__St_1_MoveForward;
          } else {
            v_176 = pnr_1;
            v_175 = Lab__St_1_ObstacleFront;
          };
          v_165 = !(too_close);
          v_162 = !(corner);
          v_163 = (front_free&&v_162);
          v_164 = (v_163&&parallel);
          v_166 = (v_164&&v_165);
          v_167 = (v_166&&too_far);
          if (v_167) {
            v_178 = true;
            v_177 = Lab__St_1_MoveCloser;
          } else {
            v_178 = v_176;
            v_177 = v_175;
          };
          v_158 = !(corner);
          v_159 = (front_free&&v_158);
          v_160 = (v_159&&parallel);
          v_161 = (v_160&&too_close);
          if (v_161) {
            v_180 = true;
            v_179 = Lab__St_1_MoveAway;
          } else {
            v_180 = v_178;
            v_179 = v_177;
          };
          v_156 = !(parallel);
          v_154 = !(corner);
          v_155 = (front_free&&v_154);
          v_157 = (v_155&&v_156);
          if (v_157) {
            v_182 = true;
            v_181 = Lab__St_1_MakeParallel;
          } else {
            v_182 = v_180;
            v_181 = v_179;
          };
          v_153 = (front_free&&corner);
          if (v_153) {
            r_3_St_1_ObstacleFront = true;
            s_1_St_1_ObstacleFront = Lab__St_1_TurnLeft;
          } else {
            r_3_St_1_ObstacleFront = v_182;
            s_1_St_1_ObstacleFront = v_181;
          };
          s_1 = s_1_St_1_ObstacleFront;
          r_3 = r_3_St_1_ObstacleFront;
          break;
        case Lab__St_1_TurnLeft:
          v_143 = !(too_far);
          v_141 = !(too_close);
          v_138 = !(corner);
          v_139 = (front_free&&v_138);
          v_140 = (v_139&&parallel);
          v_142 = (v_140&&v_141);
          v_144 = (v_142&&v_143);
          if (v_144) {
            v_146 = true;
            v_145 = Lab__St_1_MoveForward;
          } else {
            v_146 = pnr_1;
            v_145 = Lab__St_1_TurnLeft;
          };
          v_135 = !(too_close);
          v_132 = !(corner);
          v_133 = (front_free&&v_132);
          v_134 = (v_133&&parallel);
          v_136 = (v_134&&v_135);
          v_137 = (v_136&&too_far);
          if (v_137) {
            v_148 = true;
            v_147 = Lab__St_1_MoveCloser;
          } else {
            v_148 = v_146;
            v_147 = v_145;
          };
          v_128 = !(corner);
          v_129 = (front_free&&v_128);
          v_130 = (v_129&&parallel);
          v_131 = (v_130&&too_close);
          if (v_131) {
            v_150 = true;
            v_149 = Lab__St_1_MoveAway;
          } else {
            v_150 = v_148;
            v_149 = v_147;
          };
          v_126 = !(parallel);
          v_124 = !(corner);
          v_125 = (front_free&&v_124);
          v_127 = (v_125&&v_126);
          if (v_127) {
            v_152 = true;
            v_151 = Lab__St_1_MakeParallel;
          } else {
            v_152 = v_150;
            v_151 = v_149;
          };
          v_123 = !(front_free);
          if (v_123) {
            r_3_St_1_TurnLeft = true;
            s_1_St_1_TurnLeft = Lab__St_1_ObstacleFront;
          } else {
            r_3_St_1_TurnLeft = v_152;
            s_1_St_1_TurnLeft = v_151;
          };
          s_1 = s_1_St_1_TurnLeft;
          r_3 = r_3_St_1_TurnLeft;
          break;
        case Lab__St_1_MakeParallel:
          v_113 = !(too_far);
          v_111 = !(too_close);
          v_108 = !(corner);
          v_109 = (front_free&&v_108);
          v_110 = (v_109&&parallel);
          v_112 = (v_110&&v_111);
          v_114 = (v_112&&v_113);
          if (v_114) {
            v_116 = true;
            v_115 = Lab__St_1_MoveForward;
          } else {
            v_116 = pnr_1;
            v_115 = Lab__St_1_MakeParallel;
          };
          v_105 = !(too_close);
          v_102 = !(corner);
          v_103 = (front_free&&v_102);
          v_104 = (v_103&&parallel);
          v_106 = (v_104&&v_105);
          v_107 = (v_106&&too_far);
          if (v_107) {
            v_118 = true;
            v_117 = Lab__St_1_MoveCloser;
          } else {
            v_118 = v_116;
            v_117 = v_115;
          };
          v_98 = !(corner);
          v_99 = (front_free&&v_98);
          v_100 = (v_99&&parallel);
          v_101 = (v_100&&too_close);
          if (v_101) {
            v_120 = true;
            v_119 = Lab__St_1_MoveAway;
          } else {
            v_120 = v_118;
            v_119 = v_117;
          };
          v_97 = (front_free&&corner);
          if (v_97) {
            v_122 = true;
            v_121 = Lab__St_1_TurnLeft;
          } else {
            v_122 = v_120;
            v_121 = v_119;
          };
          v_96 = !(front_free);
          if (v_96) {
            r_3_St_1_MakeParallel = true;
            s_1_St_1_MakeParallel = Lab__St_1_ObstacleFront;
          } else {
            r_3_St_1_MakeParallel = v_122;
            s_1_St_1_MakeParallel = v_121;
          };
          s_1 = s_1_St_1_MakeParallel;
          r_3 = r_3_St_1_MakeParallel;
          break;
        case Lab__St_1_MoveAway:
          v_86 = !(too_far);
          v_84 = !(too_close);
          v_81 = !(corner);
          v_82 = (front_free&&v_81);
          v_83 = (v_82&&parallel);
          v_85 = (v_83&&v_84);
          v_87 = (v_85&&v_86);
          if (v_87) {
            v_89 = true;
            v_88 = Lab__St_1_MoveForward;
          } else {
            v_89 = pnr_1;
            v_88 = Lab__St_1_MoveAway;
          };
          v_78 = !(too_close);
          v_75 = !(corner);
          v_76 = (front_free&&v_75);
          v_77 = (v_76&&parallel);
          v_79 = (v_77&&v_78);
          v_80 = (v_79&&too_far);
          if (v_80) {
            v_91 = true;
            v_90 = Lab__St_1_MoveCloser;
          } else {
            v_91 = v_89;
            v_90 = v_88;
          };
          v_73 = !(parallel);
          v_71 = !(corner);
          v_72 = (front_free&&v_71);
          v_74 = (v_72&&v_73);
          if (v_74) {
            v_93 = true;
            v_92 = Lab__St_1_MakeParallel;
          } else {
            v_93 = v_91;
            v_92 = v_90;
          };
          v_70 = (front_free&&corner);
          if (v_70) {
            v_95 = true;
            v_94 = Lab__St_1_TurnLeft;
          } else {
            v_95 = v_93;
            v_94 = v_92;
          };
          v_69 = !(front_free);
          if (v_69) {
            r_3_St_1_MoveAway = true;
            s_1_St_1_MoveAway = Lab__St_1_ObstacleFront;
          } else {
            r_3_St_1_MoveAway = v_95;
            s_1_St_1_MoveAway = v_94;
          };
          s_1 = s_1_St_1_MoveAway;
          r_3 = r_3_St_1_MoveAway;
          break;
        case Lab__St_1_MoveCloser:
          v_59 = !(too_far);
          v_57 = !(too_close);
          v_54 = !(corner);
          v_55 = (front_free&&v_54);
          v_56 = (v_55&&parallel);
          v_58 = (v_56&&v_57);
          v_60 = (v_58&&v_59);
          if (v_60) {
            v_62 = true;
            v_61 = Lab__St_1_MoveForward;
          } else {
            v_62 = pnr_1;
            v_61 = Lab__St_1_MoveCloser;
          };
          v_50 = !(corner);
          v_51 = (front_free&&v_50);
          v_52 = (v_51&&parallel);
          v_53 = (v_52&&too_close);
          if (v_53) {
            v_64 = true;
            v_63 = Lab__St_1_MoveAway;
          } else {
            v_64 = v_62;
            v_63 = v_61;
          };
          v_48 = !(parallel);
          v_46 = !(corner);
          v_47 = (front_free&&v_46);
          v_49 = (v_47&&v_48);
          if (v_49) {
            v_66 = true;
            v_65 = Lab__St_1_MakeParallel;
          } else {
            v_66 = v_64;
            v_65 = v_63;
          };
          v_45 = (front_free&&corner);
          if (v_45) {
            v_68 = true;
            v_67 = Lab__St_1_TurnLeft;
          } else {
            v_68 = v_66;
            v_67 = v_65;
          };
          v_44 = !(front_free);
          if (v_44) {
            r_3_St_1_MoveCloser = true;
            s_1_St_1_MoveCloser = Lab__St_1_ObstacleFront;
          } else {
            r_3_St_1_MoveCloser = v_68;
            s_1_St_1_MoveCloser = v_67;
          };
          s_1 = s_1_St_1_MoveCloser;
          r_3 = r_3_St_1_MoveCloser;
          break;
        case Lab__St_1_MoveForward:
          v_33 = !(too_close);
          v_30 = !(corner);
          v_31 = (front_free&&v_30);
          v_32 = (v_31&&parallel);
          v_34 = (v_32&&v_33);
          v_35 = (v_34&&too_far);
          if (v_35) {
            v_37 = true;
            v_36 = Lab__St_1_MoveCloser;
          } else {
            v_37 = pnr_1;
            v_36 = Lab__St_1_MoveForward;
          };
          v_26 = !(corner);
          v_27 = (front_free&&v_26);
          v_28 = (v_27&&parallel);
          v_29 = (v_28&&too_close);
          if (v_29) {
            v_39 = true;
            v_38 = Lab__St_1_MoveAway;
          } else {
            v_39 = v_37;
            v_38 = v_36;
          };
          v_24 = !(parallel);
          v_22 = !(corner);
          v_23 = (front_free&&v_22);
          v_25 = (v_23&&v_24);
          if (v_25) {
            v_41 = true;
            v_40 = Lab__St_1_MakeParallel;
          } else {
            v_41 = v_39;
            v_40 = v_38;
          };
          v_21 = (front_free&&corner);
          if (v_21) {
            v_43 = true;
            v_42 = Lab__St_1_TurnLeft;
          } else {
            v_43 = v_41;
            v_42 = v_40;
          };
          v_20 = !(front_free);
          if (v_20) {
            r_3_St_1_MoveForward = true;
            s_1_St_1_MoveForward = Lab__St_1_ObstacleFront;
          } else {
            r_3_St_1_MoveForward = v_43;
            s_1_St_1_MoveForward = v_42;
          };
          s_1 = s_1_St_1_MoveForward;
          r_3 = r_3_St_1_MoveForward;
          break;
        default:
          break;
      };
      ck_5 = s_1;
      switch (ck_5) {
        case Lab__St_1_ObstacleFront:
          right_wheel_St_2_WallFollowing_St_1_ObstacleFront = 10;
          left_wheel_St_2_WallFollowing_St_1_ObstacleFront = 100;
          direction_St_2_WallFollowing_St_1_ObstacleFront = 3;
          st_St_2_WallFollowing_St_1_ObstacleFront = Lab__ObstacleFront;
          nr_1_St_1_ObstacleFront = false;
          ns_1_St_1_ObstacleFront = Lab__St_1_ObstacleFront;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_ObstacleFront;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_ObstacleFront;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_ObstacleFront;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_ObstacleFront;
          ns_1 = ns_1_St_1_ObstacleFront;
          nr_1 = nr_1_St_1_ObstacleFront;
          break;
        case Lab__St_1_TurnLeft:
          right_wheel_St_2_WallFollowing_St_1_TurnLeft = 100;
          left_wheel_St_2_WallFollowing_St_1_TurnLeft = 10;
          direction_St_2_WallFollowing_St_1_TurnLeft = 2;
          st_St_2_WallFollowing_St_1_TurnLeft = Lab__TurnLeft;
          nr_1_St_1_TurnLeft = false;
          ns_1_St_1_TurnLeft = Lab__St_1_TurnLeft;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_TurnLeft;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_TurnLeft;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_TurnLeft;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_TurnLeft;
          ns_1 = ns_1_St_1_TurnLeft;
          nr_1 = nr_1_St_1_TurnLeft;
          break;
        case Lab__St_1_MakeParallel:
          v_194 = (ir_side_front>ir_side_back);
          v_192 = (ir_side_front>ir_side_back);
          v_191 = (ir_side_front>ir_side_back);
          if (v_191) {
            direction_St_2_WallFollowing_St_1_MakeParallel = 2;
          } else {
            direction_St_2_WallFollowing_St_1_MakeParallel = 3;
          };
          v_184 = (ir_side_front-ir_side_back);
          diff = (v_184*10);
          v_188 = -(diff);
          v_187 = (diff<0);
          if (v_187) {
            v_189 = v_188;
          } else {
            v_189 = diff;
          };
          v_186 = (diff<-100);
          if (v_186) {
            v_190 = 0;
          } else {
            v_190 = v_189;
          };
          v_185 = (diff>Lab__speed);
          if (v_185) {
            correctSpeed = 100;
          } else {
            correctSpeed = v_190;
          };
          v_195 = (Lab__speed-correctSpeed);
          if (v_194) {
            right_wheel_St_2_WallFollowing_St_1_MakeParallel = 100;
          } else {
            right_wheel_St_2_WallFollowing_St_1_MakeParallel = v_195;
          };
          v_193 = (Lab__speed-correctSpeed);
          if (v_192) {
            left_wheel_St_2_WallFollowing_St_1_MakeParallel = v_193;
          } else {
            left_wheel_St_2_WallFollowing_St_1_MakeParallel = 100;
          };
          st_St_2_WallFollowing_St_1_MakeParallel = Lab__MakeParallel;
          nr_1_St_1_MakeParallel = false;
          ns_1_St_1_MakeParallel = Lab__St_1_MakeParallel;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MakeParallel;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MakeParallel;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MakeParallel;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MakeParallel;
          ns_1 = ns_1_St_1_MakeParallel;
          nr_1 = nr_1_St_1_MakeParallel;
          break;
        case Lab__St_1_MoveAway:
          right_wheel_St_2_WallFollowing_St_1_MoveAway = 90;
          left_wheel_St_2_WallFollowing_St_1_MoveAway = 100;
          direction_St_2_WallFollowing_St_1_MoveAway = 3;
          st_St_2_WallFollowing_St_1_MoveAway = Lab__MoveAway;
          nr_1_St_1_MoveAway = false;
          ns_1_St_1_MoveAway = Lab__St_1_MoveAway;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveAway;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveAway;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveAway;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveAway;
          ns_1 = ns_1_St_1_MoveAway;
          nr_1 = nr_1_St_1_MoveAway;
          break;
        case Lab__St_1_MoveCloser:
          right_wheel_St_2_WallFollowing_St_1_MoveCloser = 100;
          left_wheel_St_2_WallFollowing_St_1_MoveCloser = 90;
          direction_St_2_WallFollowing_St_1_MoveCloser = 3;
          st_St_2_WallFollowing_St_1_MoveCloser = Lab__MoveCloser;
          nr_1_St_1_MoveCloser = false;
          ns_1_St_1_MoveCloser = Lab__St_1_MoveCloser;
          left_wheel_St_2_WallFollowing = left_wheel_St_2_WallFollowing_St_1_MoveCloser;
          right_wheel_St_2_WallFollowing = right_wheel_St_2_WallFollowing_St_1_MoveCloser;
          direction_St_2_WallFollowing = direction_St_2_WallFollowing_St_1_MoveCloser;
          st_St_2_WallFollowing = st_St_2_WallFollowing_St_1_MoveCloser;
          ns_1 = ns_1_St_1_MoveCloser;
          nr_1 = nr_1_St_1_MoveCloser;
          break;
        case Lab__St_1_MoveForward:
          right_wheel_St_2_WallFollowing_St_1_MoveForward = 100;
          left_wheel_St_2_WallFollowing_St_1_MoveForward = 100;
          direction_St_2_WallFollowing_St_1_MoveForward = 1;
          st_St_2_WallFollowing_St_1_MoveForward = Lab__MoveForward;
          nr_1_St_1_MoveForward = false;
          ns_1_St_1_MoveForward = Lab__St_1_MoveForward;
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
      st = st_St_2_WallFollowing;
      self->v_196 = nr_1;
      self->v_183 = ns_1;
      break;
    case Lab__St_2_ToFollowPosition:
      right_wheel_St_2_ToFollowPosition = 10;
      left_wheel_St_2_ToFollowPosition = 100;
      direction_St_2_ToFollowPosition = 3;
      st_St_2_ToFollowPosition = Lab__ToFollowPosition;
      nr_2_St_2_ToFollowPosition = false;
      ns_2_St_2_ToFollowPosition = Lab__St_2_ToFollowPosition;
      ns_2 = ns_2_St_2_ToFollowPosition;
      nr_2 = nr_2_St_2_ToFollowPosition;
      _out->left_wheel = left_wheel_St_2_ToFollowPosition;
      _out->right_wheel = right_wheel_St_2_ToFollowPosition;
      _out->direction = direction_St_2_ToFollowPosition;
      st = st_St_2_ToFollowPosition;
      break;
    default:
      break;
  };
  self->st_1 = st;
  self->l_1 = l;
  self->r_1 = r;
  self->alligned_1 = alligned;
  self->left_line_1 = left_line;
  self->pnr_2 = nr_2;
  self->ck = ns_2;;
}

