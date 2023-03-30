/* --- Generated the 30/3/2023 at 13:52 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#ifndef LAB_TYPES_H
#define LAB_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Lab__St_2_WallFollowing,
  Lab__St_2_TurnRightEnd,
  Lab__St_2_ObstacleFollowing,
  Lab__St_2_LineFollow
} Lab__st_2;

Lab__st_2 Lab__st_2_of_string(char* s);

char* string_of_Lab__st_2(Lab__st_2 x, char* buf);

typedef enum {
  Lab__St_1_Turn90Right,
  Lab__St_1_RightTurnSlow,
  Lab__St_1_RightTurn,
  Lab__St_1_MoveForward,
  Lab__St_1_MoveCloser,
  Lab__St_1_MoveAway,
  Lab__St_1_LeftTurnSlow,
  Lab__St_1_LeftTurn,
  Lab__St_1_CheckState
} Lab__st_1;

Lab__st_1 Lab__st_1_of_string(char* s);

char* string_of_Lab__st_1(Lab__st_1 x, char* buf);

typedef enum {
  Lab__St_OnLine,
  Lab__St_LostLine
} Lab__st;

Lab__st Lab__st_of_string(char* s);

char* string_of_Lab__st(Lab__st x, char* buf);

typedef enum {
  Lab__OnLine,
  Lab__LostLine,
  Lab__ObstacleFollowing,
  Lab__Error,
  Lab__Turn90Right,
  Lab__MoveAway,
  Lab__MoveCloser,
  Lab__LeftTurn,
  Lab__RightTurn,
  Lab__LeftTurnSlow,
  Lab__RightTurnSlow,
  Lab__MoveForward,
  Lab__TurnRightEnd
} Lab__stateName;

Lab__stateName Lab__stateName_of_string(char* s);

char* string_of_Lab__stateName(Lab__stateName x, char* buf);

#endif // LAB_TYPES_H
