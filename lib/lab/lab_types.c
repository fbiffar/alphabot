/* --- Generated the 30/3/2023 at 13:52 --- */
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
  if ((strcmp(s, "St_2_TurnRightEnd")==0)) {
    return Lab__St_2_TurnRightEnd;
  };
  if ((strcmp(s, "St_2_ObstacleFollowing")==0)) {
    return Lab__St_2_ObstacleFollowing;
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
    case Lab__St_2_TurnRightEnd:
      strcpy(buf, "St_2_TurnRightEnd");
      break;
    case Lab__St_2_ObstacleFollowing:
      strcpy(buf, "St_2_ObstacleFollowing");
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
  if ((strcmp(s, "St_1_Turn90Right")==0)) {
    return Lab__St_1_Turn90Right;
  };
  if ((strcmp(s, "St_1_RightTurnSlow")==0)) {
    return Lab__St_1_RightTurnSlow;
  };
  if ((strcmp(s, "St_1_RightTurn")==0)) {
    return Lab__St_1_RightTurn;
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
  if ((strcmp(s, "St_1_LeftTurnSlow")==0)) {
    return Lab__St_1_LeftTurnSlow;
  };
  if ((strcmp(s, "St_1_LeftTurn")==0)) {
    return Lab__St_1_LeftTurn;
  };
  if ((strcmp(s, "St_1_CheckState")==0)) {
    return Lab__St_1_CheckState;
  };
}

char* string_of_Lab__st_1(Lab__st_1 x, char* buf) {
  switch (x) {
    case Lab__St_1_Turn90Right:
      strcpy(buf, "St_1_Turn90Right");
      break;
    case Lab__St_1_RightTurnSlow:
      strcpy(buf, "St_1_RightTurnSlow");
      break;
    case Lab__St_1_RightTurn:
      strcpy(buf, "St_1_RightTurn");
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
    case Lab__St_1_LeftTurnSlow:
      strcpy(buf, "St_1_LeftTurnSlow");
      break;
    case Lab__St_1_LeftTurn:
      strcpy(buf, "St_1_LeftTurn");
      break;
    case Lab__St_1_CheckState:
      strcpy(buf, "St_1_CheckState");
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
  if ((strcmp(s, "ObstacleFollowing")==0)) {
    return Lab__ObstacleFollowing;
  };
  if ((strcmp(s, "Error")==0)) {
    return Lab__Error;
  };
  if ((strcmp(s, "Turn90Right")==0)) {
    return Lab__Turn90Right;
  };
  if ((strcmp(s, "MoveAway")==0)) {
    return Lab__MoveAway;
  };
  if ((strcmp(s, "MoveCloser")==0)) {
    return Lab__MoveCloser;
  };
  if ((strcmp(s, "LeftTurn")==0)) {
    return Lab__LeftTurn;
  };
  if ((strcmp(s, "RightTurn")==0)) {
    return Lab__RightTurn;
  };
  if ((strcmp(s, "LeftTurnSlow")==0)) {
    return Lab__LeftTurnSlow;
  };
  if ((strcmp(s, "RightTurnSlow")==0)) {
    return Lab__RightTurnSlow;
  };
  if ((strcmp(s, "MoveForward")==0)) {
    return Lab__MoveForward;
  };
  if ((strcmp(s, "TurnRightEnd")==0)) {
    return Lab__TurnRightEnd;
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
    case Lab__ObstacleFollowing:
      strcpy(buf, "ObstacleFollowing");
      break;
    case Lab__Error:
      strcpy(buf, "Error");
      break;
    case Lab__Turn90Right:
      strcpy(buf, "Turn90Right");
      break;
    case Lab__MoveAway:
      strcpy(buf, "MoveAway");
      break;
    case Lab__MoveCloser:
      strcpy(buf, "MoveCloser");
      break;
    case Lab__LeftTurn:
      strcpy(buf, "LeftTurn");
      break;
    case Lab__RightTurn:
      strcpy(buf, "RightTurn");
      break;
    case Lab__LeftTurnSlow:
      strcpy(buf, "LeftTurnSlow");
      break;
    case Lab__RightTurnSlow:
      strcpy(buf, "RightTurnSlow");
      break;
    case Lab__MoveForward:
      strcpy(buf, "MoveForward");
      break;
    case Lab__TurnRightEnd:
      strcpy(buf, "TurnRightEnd");
      break;
    default:
      break;
  };
  return buf;
}

