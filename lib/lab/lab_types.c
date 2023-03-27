/* --- Generated the 26/3/2023 at 15:58 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_types.h"

Lab__st_2 Lab__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_WallFollowing")==0)) {
    return Lab__St_2_WallFollowing;
  };
  if ((strcmp(s, "St_2_ToFollowPosition")==0)) {
    return Lab__St_2_ToFollowPosition;
  };
  if ((strcmp(s, "St_2_LineFollow")==0)) {
    return Lab__St_2_LineFollow;
  };
}

char* string_of_Lab__st_2(Lab__st_2 x, char* buf) {
  switch (x) {
    case Lab__St_2_WallFollowing:
      strcpy(buf, "St_2_WallFollowing");
      break;
    case Lab__St_2_ToFollowPosition:
      strcpy(buf, "St_2_ToFollowPosition");
      break;
    case Lab__St_2_LineFollow:
      strcpy(buf, "St_2_LineFollow");
      break;
    default:
      break;
  };
  return buf;
}

Lab__st_1 Lab__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_TurnLeft")==0)) {
    return Lab__St_1_TurnLeft;
  };
  if ((strcmp(s, "St_1_ObstacleFront")==0)) {
    return Lab__St_1_ObstacleFront;
  };
  if ((strcmp(s, "St_1_MoveForward")==0)) {
    return Lab__St_1_MoveForward;
  };
  if ((strcmp(s, "St_1_MoveCloser")==0)) {
    return Lab__St_1_MoveCloser;
  };
  if ((strcmp(s, "St_1_MoveAway")==0)) {
    return Lab__St_1_MoveAway;
  };
  if ((strcmp(s, "St_1_MakeParallel")==0)) {
    return Lab__St_1_MakeParallel;
  };
}

char* string_of_Lab__st_1(Lab__st_1 x, char* buf) {
  switch (x) {
    case Lab__St_1_TurnLeft:
      strcpy(buf, "St_1_TurnLeft");
      break;
    case Lab__St_1_ObstacleFront:
      strcpy(buf, "St_1_ObstacleFront");
      break;
    case Lab__St_1_MoveForward:
      strcpy(buf, "St_1_MoveForward");
      break;
    case Lab__St_1_MoveCloser:
      strcpy(buf, "St_1_MoveCloser");
      break;
    case Lab__St_1_MoveAway:
      strcpy(buf, "St_1_MoveAway");
      break;
    case Lab__St_1_MakeParallel:
      strcpy(buf, "St_1_MakeParallel");
      break;
    default:
      break;
  };
  return buf;
}

Lab__st Lab__st_of_string(char* s) {
  if ((strcmp(s, "St_OnLine")==0)) {
    return Lab__St_OnLine;
  };
  if ((strcmp(s, "St_LostLine")==0)) {
    return Lab__St_LostLine;
  };
}

char* string_of_Lab__st(Lab__st x, char* buf) {
  switch (x) {
    case Lab__St_OnLine:
      strcpy(buf, "St_OnLine");
      break;
    case Lab__St_LostLine:
      strcpy(buf, "St_LostLine");
      break;
    default:
      break;
  };
  return buf;
}

Lab__stateName Lab__stateName_of_string(char* s) {
  if ((strcmp(s, "OnLine")==0)) {
    return Lab__OnLine;
  };
  if ((strcmp(s, "LostLine")==0)) {
    return Lab__LostLine;
  };
  if ((strcmp(s, "ObstacleFront")==0)) {
    return Lab__ObstacleFront;
  };
  if ((strcmp(s, "TurnLeft")==0)) {
    return Lab__TurnLeft;
  };
  if ((strcmp(s, "MakeParallel")==0)) {
    return Lab__MakeParallel;
  };
  if ((strcmp(s, "MoveAway")==0)) {
    return Lab__MoveAway;
  };
  if ((strcmp(s, "MoveCloser")==0)) {
    return Lab__MoveCloser;
  };
  if ((strcmp(s, "MoveForward")==0)) {
    return Lab__MoveForward;
  };
  if ((strcmp(s, "ToFollowPosition")==0)) {
    return Lab__ToFollowPosition;
  };
}

char* string_of_Lab__stateName(Lab__stateName x, char* buf) {
  switch (x) {
    case Lab__OnLine:
      strcpy(buf, "OnLine");
      break;
    case Lab__LostLine:
      strcpy(buf, "LostLine");
      break;
    case Lab__ObstacleFront:
      strcpy(buf, "ObstacleFront");
      break;
    case Lab__TurnLeft:
      strcpy(buf, "TurnLeft");
      break;
    case Lab__MakeParallel:
      strcpy(buf, "MakeParallel");
      break;
    case Lab__MoveAway:
      strcpy(buf, "MoveAway");
      break;
    case Lab__MoveCloser:
      strcpy(buf, "MoveCloser");
      break;
    case Lab__MoveForward:
      strcpy(buf, "MoveForward");
      break;
    case Lab__ToFollowPosition:
      strcpy(buf, "ToFollowPosition");
      break;
    default:
      break;
  };
  return buf;
}

