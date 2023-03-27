/* --- Generated the 26/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#ifndef LAB_H
#define LAB_H

#include "lab_types.h"
typedef struct Lab__controller_mem {
  Lab__st_2 ck;
  Lab__st_1 v_183;
  int v_196;
  Lab__st v_198;
  int v_207;
  int pnr_2;
  Lab__stateName st_1;
  int l_1;
  int r_1;
  int alligned_1;
  int left_line_1;
} Lab__controller_mem;

typedef struct Lab__controller_out {
  int left_wheel;
  int right_wheel;
  int direction;
} Lab__controller_out;

void Lab__controller_reset(Lab__controller_mem* self);

void Lab__controller_step(int l2, int l1, int m, int r1, int r2,
                          int ir_front, int ir_front_left, int ir_side_front,
                          int ir_side, int ir_side_back,
                          Lab__controller_out* _out,
                          Lab__controller_mem* self);

#endif // LAB_H
