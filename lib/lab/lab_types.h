/* --- Generated the 26/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#ifndef LAB_TYPES_H
#define LAB_TYPES_H

#include "stdbool.h"
#include "assert.h"
//#include "pervasives.h"
typedef enum {
  Lab__St_2_WallFollowing,
  Lab__St_2_ToFollowPosition,
  Lab__St_2_LineFollow
} Lab__st_2;

Lab__st_2 Lab__st_2_of_string(char* s);

char* string_of_Lab__st_2(Lab__st_2 x, char* buf);

typedef enum {
  Lab__St_1_TurnLeft,
  Lab__St_1_ObstacleFront,
  Lab__St_1_MoveForward,
  Lab__St_1_MoveCloser,
  Lab__St_1_MoveAway,
  Lab__St_1_MakeParallel
} Lab__st_1;

Lab__st_1 Lab__st_1_of_string(char* s);

char* string_of_Lab__st_1(Lab__st_1 x, char* buf);

typedef enum {
  Lab__St_OnLine,
  Lab__St_LostLine
} Lab__st;

Lab__st Lab__st_of_string(char* s);

char* string_of_Lab__st(Lab__st x, char* buf);

static const int Lab__line_threshold = 800;

static const int Lab__min_front = 75;

static const int Lab__min_front_left = 250;

static const int Lab__parallel_threshold = 5;

static const int Lab__min_wall = 50;

static const int Lab__max_wall = 100;

static const int Lab__max_black = 1023;

static const int Lab__max_speed = 100;

static const int Lab__speed = 100;

static const int Lab__c2 = 2;

static const int Lab__c1 = 30;

typedef enum {
  Lab__OnLine,
  Lab__LostLine,
  Lab__ObstacleFront,
  Lab__TurnLeft,
  Lab__MakeParallel,
  Lab__MoveAway,
  Lab__MoveCloser,
  Lab__MoveForward,
  Lab__ToFollowPosition
} Lab__stateName;

Lab__stateName Lab__stateName_of_string(char* s);

char* string_of_Lab__stateName(Lab__stateName x, char* buf);

#endif // LAB_TYPES_H
