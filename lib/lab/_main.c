/* --- Generated the 26/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Lab__controller_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int l2;
  int l1;
  int m;
  int r1;
  int r2;
  int ir_front;
  int ir_front_left;
  int ir_side_front;
  int ir_side;
  int ir_side_back;
  Lab__controller_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Lab__controller_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &l2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &l1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &m)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &r1)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &r2)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_front)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_front_left)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_side_front)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_side)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &ir_side_back)==EOF)) {
      return 0;
    };;
    Lab__controller_step(l2, l1, m, r1, r2, ir_front, ir_front_left,
                         ir_side_front, ir_side, ir_side_back, &_res, &mem);
    printf("%d\n", _res.left_wheel);
    printf("%d\n", _res.right_wheel);
    printf("%d\n", _res.direction);
    fflush(stdout);
  };
  return 0;
}

