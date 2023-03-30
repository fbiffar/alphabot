/* --- Generated the 30/3/2023 at 11:51 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_V2.ept --- */

#ifndef LAB_V2_TYPES_H
#define LAB_V2_TYPES_H

#include "stdbool.h"
#include "assert.h"
//#include "pervasives.h"
typedef enum {
  Lab_V2__St_2_WallFollowing,
  Lab_V2__St_2_TurnRightEnd,
  Lab_V2__St_2_ObstacleFollowing,
  Lab_V2__St_2_LineFollow
} Lab_V2__st_2;

Lab_V2__st_2 Lab_V2__st_2_of_string(char* s);

char* string_of_Lab_V2__st_2(Lab_V2__st_2 x, char* buf);

typedef enum {
  Lab_V2__St_1_Turn90Right,
  Lab_V2__St_1_RightTurnSlow,
  Lab_V2__St_1_RightTurn,
  Lab_V2__St_1_MoveForward,
  Lab_V2__St_1_MoveCloser,
  Lab_V2__St_1_MoveAway,
  Lab_V2__St_1_LeftTurnSlow,
  Lab_V2__St_1_LeftTurn,
  Lab_V2__St_1_CheckState
} Lab_V2__st_1;

Lab_V2__st_1 Lab_V2__st_1_of_string(char* s);

char* string_of_Lab_V2__st_1(Lab_V2__st_1 x, char* buf);

typedef enum {
  Lab_V2__St_OnLine,
  Lab_V2__St_LostLine
} Lab_V2__st;

Lab_V2__st Lab_V2__st_of_string(char* s);

char* string_of_Lab_V2__st(Lab_V2__st x, char* buf);

typedef enum {
  Lab_V2__OnLine,
  Lab_V2__LostLine,
  Lab_V2__ObstacleFollowing,
  Lab_V2__Error,
  Lab_V2__Turn90Right,
  Lab_V2__MoveAway,
  Lab_V2__MoveCloser,
  Lab_V2__LeftTurn,
  Lab_V2__RightTurn,
  Lab_V2__LeftTurnSlow,
  Lab_V2__RightTurnSlow,
  Lab_V2__MoveForward,
  Lab_V2__TurnRightEnd
} Lab_V2__stateName;

Lab_V2__stateName Lab_V2__stateName_of_string(char* s);

char* string_of_Lab_V2__stateName(Lab_V2__stateName x, char* buf);

#endif // LAB_V2_TYPES_H
