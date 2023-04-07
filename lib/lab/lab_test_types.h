/* --- Generated the 7/4/2023 at 11:13 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_test.ept --- */

#ifndef LAB_TEST_TYPES_H
#define LAB_TEST_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Lab_test__St_3_WallFollowing,
  Lab_test__St_3_TurnRightEnd,
  Lab_test__St_3_Stop,
  Lab_test__St_3_Parking,
  Lab_test__St_3_ObstacleFollowing,
  Lab_test__St_3_LineFollow
} Lab_test__st_3;

Lab_test__st_3 Lab_test__st_3_of_string(char* s);

char* string_of_Lab_test__st_3(Lab_test__st_3 x, char* buf);

typedef enum {
  Lab_test__St_2_Turn90Right,
  Lab_test__St_2_Forward,
  Lab_test__St_2_Backwards
} Lab_test__st_2;

Lab_test__st_2 Lab_test__st_2_of_string(char* s);

char* string_of_Lab_test__st_2(Lab_test__st_2 x, char* buf);

typedef enum {
  Lab_test__St_1_Turn90Left,
  Lab_test__St_1_RightTurnSlow,
  Lab_test__St_1_RightTurn,
  Lab_test__St_1_MoveForward,
  Lab_test__St_1_MoveCloser,
  Lab_test__St_1_MoveAway,
  Lab_test__St_1_LeftTurnSlow,
  Lab_test__St_1_LeftTurn,
  Lab_test__St_1_CheckState
} Lab_test__st_1;

Lab_test__st_1 Lab_test__st_1_of_string(char* s);

char* string_of_Lab_test__st_1(Lab_test__st_1 x, char* buf);

typedef enum {
  Lab_test__St_OnLine,
  Lab_test__St_LostLine
} Lab_test__st;

Lab_test__st Lab_test__st_of_string(char* s);

char* string_of_Lab_test__st(Lab_test__st x, char* buf);

typedef enum {
  Lab_test__OnLine,
  Lab_test__LostLine,
  Lab_test__ObstacleFollowing,
  Lab_test__Error,
  Lab_test__Turn90Right,
  Lab_test__Turn90Left,
  Lab_test__MoveAway,
  Lab_test__MoveCloser,
  Lab_test__LeftTurn,
  Lab_test__RightTurn,
  Lab_test__LeftTurnSlow,
  Lab_test__RightTurnSlow,
  Lab_test__MoveForward,
  Lab_test__TurnRightEnd,
  Lab_test__Stop,
  Lab_test__Backwards,
  Lab_test__Forward
} Lab_test__stateName;

Lab_test__stateName Lab_test__stateName_of_string(char* s);

char* string_of_Lab_test__stateName(Lab_test__stateName x, char* buf);

#endif // LAB_TEST_TYPES_H
