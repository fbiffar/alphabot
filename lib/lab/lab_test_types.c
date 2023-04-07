/* --- Generated the 7/4/2023 at 12:11 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab_test.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_test_types.h"

Lab_test__st_2 Lab_test__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_WallFollowing")==0)) {
    return Lab_test__St_2_WallFollowing;
  };
  if ((strcmp(s, "St_2_ObstacleFollowing")==0)) {
    return Lab_test__St_2_ObstacleFollowing;
  };
  if ((strcmp(s, "St_2_LineFollow")==0)) {
    return Lab_test__St_2_LineFollow;
  };
}

char* string_of_Lab_test__st_2(Lab_test__st_2 x, char* buf) {
  switch (x) {
    case Lab_test__St_2_WallFollowing:
      strcpy(buf, "St_2_WallFollowing");
      break;
    case Lab_test__St_2_ObstacleFollowing:
      strcpy(buf, "St_2_ObstacleFollowing");
      break;
    case Lab_test__St_2_LineFollow:
      strcpy(buf, "St_2_LineFollow");
      break;
    default:
      break;
  };
  return buf;
}

Lab_test__st_1 Lab_test__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Turn90Left")==0)) {
    return Lab_test__St_1_Turn90Left;
  };
  if ((strcmp(s, "St_1_RightTurnSlow")==0)) {
    return Lab_test__St_1_RightTurnSlow;
  };
  if ((strcmp(s, "St_1_RightTurn")==0)) {
    return Lab_test__St_1_RightTurn;
  };
  if ((strcmp(s, "St_1_MoveForward")==0)) {
    return Lab_test__St_1_MoveForward;
  };
  if ((strcmp(s, "St_1_MoveCloser")==0)) {
    return Lab_test__St_1_MoveCloser;
  };
  if ((strcmp(s, "St_1_MoveAway")==0)) {
    return Lab_test__St_1_MoveAway;
  };
  if ((strcmp(s, "St_1_LeftTurnSlow")==0)) {
    return Lab_test__St_1_LeftTurnSlow;
  };
  if ((strcmp(s, "St_1_LeftTurn")==0)) {
    return Lab_test__St_1_LeftTurn;
  };
  if ((strcmp(s, "St_1_CheckState")==0)) {
    return Lab_test__St_1_CheckState;
  };
}

char* string_of_Lab_test__st_1(Lab_test__st_1 x, char* buf) {
  switch (x) {
    case Lab_test__St_1_Turn90Left:
      strcpy(buf, "St_1_Turn90Left");
      break;
    case Lab_test__St_1_RightTurnSlow:
      strcpy(buf, "St_1_RightTurnSlow");
      break;
    case Lab_test__St_1_RightTurn:
      strcpy(buf, "St_1_RightTurn");
      break;
    case Lab_test__St_1_MoveForward:
      strcpy(buf, "St_1_MoveForward");
      break;
    case Lab_test__St_1_MoveCloser:
      strcpy(buf, "St_1_MoveCloser");
      break;
    case Lab_test__St_1_MoveAway:
      strcpy(buf, "St_1_MoveAway");
      break;
    case Lab_test__St_1_LeftTurnSlow:
      strcpy(buf, "St_1_LeftTurnSlow");
      break;
    case Lab_test__St_1_LeftTurn:
      strcpy(buf, "St_1_LeftTurn");
      break;
    case Lab_test__St_1_CheckState:
      strcpy(buf, "St_1_CheckState");
      break;
    default:
      break;
  };
  return buf;
}

Lab_test__st Lab_test__st_of_string(char* s) {
  if ((strcmp(s, "St_OnLine")==0)) {
    return Lab_test__St_OnLine;
  };
  if ((strcmp(s, "St_LostLine")==0)) {
    return Lab_test__St_LostLine;
  };
}

char* string_of_Lab_test__st(Lab_test__st x, char* buf) {
  switch (x) {
    case Lab_test__St_OnLine:
      strcpy(buf, "St_OnLine");
      break;
    case Lab_test__St_LostLine:
      strcpy(buf, "St_LostLine");
      break;
    default:
      break;
  };
  return buf;
}

Lab_test__stateName Lab_test__stateName_of_string(char* s) {
  if ((strcmp(s, "OnLine")==0)) {
    return Lab_test__OnLine;
  };
  if ((strcmp(s, "LostLine")==0)) {
    return Lab_test__LostLine;
  };
  if ((strcmp(s, "ObstacleFollowing")==0)) {
    return Lab_test__ObstacleFollowing;
  };
  if ((strcmp(s, "Error")==0)) {
    return Lab_test__Error;
  };
  if ((strcmp(s, "Turn90Right")==0)) {
    return Lab_test__Turn90Right;
  };
  if ((strcmp(s, "Turn90Left")==0)) {
    return Lab_test__Turn90Left;
  };
  if ((strcmp(s, "MoveAway")==0)) {
    return Lab_test__MoveAway;
  };
  if ((strcmp(s, "MoveCloser")==0)) {
    return Lab_test__MoveCloser;
  };
  if ((strcmp(s, "LeftTurn")==0)) {
    return Lab_test__LeftTurn;
  };
  if ((strcmp(s, "RightTurn")==0)) {
    return Lab_test__RightTurn;
  };
  if ((strcmp(s, "LeftTurnSlow")==0)) {
    return Lab_test__LeftTurnSlow;
  };
  if ((strcmp(s, "RightTurnSlow")==0)) {
    return Lab_test__RightTurnSlow;
  };
  if ((strcmp(s, "MoveForward")==0)) {
    return Lab_test__MoveForward;
  };
  if ((strcmp(s, "TurnRightEnd")==0)) {
    return Lab_test__TurnRightEnd;
  };
  if ((strcmp(s, "Stop")==0)) {
    return Lab_test__Stop;
  };
  if ((strcmp(s, "Backwards")==0)) {
    return Lab_test__Backwards;
  };
  if ((strcmp(s, "Forward")==0)) {
    return Lab_test__Forward;
  };
}

char* string_of_Lab_test__stateName(Lab_test__stateName x, char* buf) {
  switch (x) {
    case Lab_test__OnLine:
      strcpy(buf, "OnLine");
      break;
    case Lab_test__LostLine:
      strcpy(buf, "LostLine");
      break;
    case Lab_test__ObstacleFollowing:
      strcpy(buf, "ObstacleFollowing");
      break;
    case Lab_test__Error:
      strcpy(buf, "Error");
      break;
    case Lab_test__Turn90Right:
      strcpy(buf, "Turn90Right");
      break;
    case Lab_test__Turn90Left:
      strcpy(buf, "Turn90Left");
      break;
    case Lab_test__MoveAway:
      strcpy(buf, "MoveAway");
      break;
    case Lab_test__MoveCloser:
      strcpy(buf, "MoveCloser");
      break;
    case Lab_test__LeftTurn:
      strcpy(buf, "LeftTurn");
      break;
    case Lab_test__RightTurn:
      strcpy(buf, "RightTurn");
      break;
    case Lab_test__LeftTurnSlow:
      strcpy(buf, "LeftTurnSlow");
      break;
    case Lab_test__RightTurnSlow:
      strcpy(buf, "RightTurnSlow");
      break;
    case Lab_test__MoveForward:
      strcpy(buf, "MoveForward");
      break;
    case Lab_test__TurnRightEnd:
      strcpy(buf, "TurnRightEnd");
      break;
    case Lab_test__Stop:
      strcpy(buf, "Stop");
      break;
    case Lab_test__Backwards:
      strcpy(buf, "Backwards");
      break;
    case Lab_test__Forward:
      strcpy(buf, "Forward");
      break;
    default:
      break;
  };
  return buf;
}

