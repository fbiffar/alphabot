/* --- Generated the 8/4/2023 at 12:35 --- */
/* --- heptagon compiler, version 1.05.00 (compiled thu. jan. 12 12:27:5 CET 2023) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s controller -hepts lab.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lab_types.h"

Lab__st_3 Lab__st_3_of_string(char* s) {
  if ((strcmp(s, "St_3_WallFollowing")==0)) {
    return Lab__St_3_WallFollowing;
  };
  if ((strcmp(s, "St_3_TurnLeftEnd")==0)) {
    return Lab__St_3_TurnLeftEnd;
  };
  if ((strcmp(s, "St_3_Stop")==0)) {
    return Lab__St_3_Stop;
  };
  if ((strcmp(s, "St_3_Parking")==0)) {
    return Lab__St_3_Parking;
  };
  if ((strcmp(s, "St_3_ObstacleFollowing")==0)) {
    return Lab__St_3_ObstacleFollowing;
  };
  if ((strcmp(s, "St_3_LineFollow")==0)) {
    return Lab__St_3_LineFollow;
  };
}

char* string_of_Lab__st_3(Lab__st_3 x, char* buf) {
  switch (x) {
    case Lab__St_3_WallFollowing:
      strcpy(buf, "St_3_WallFollowing");
      break;
    case Lab__St_3_TurnLeftEnd:
      strcpy(buf, "St_3_TurnLeftEnd");
      break;
    case Lab__St_3_Stop:
      strcpy(buf, "St_3_Stop");
      break;
    case Lab__St_3_Parking:
      strcpy(buf, "St_3_Parking");
      break;
    case Lab__St_3_ObstacleFollowing:
      strcpy(buf, "St_3_ObstacleFollowing");
      break;
    case Lab__St_3_LineFollow:
      strcpy(buf, "St_3_LineFollow");
      break;
    default:
      break;
  };
  return buf;
}

Lab__st_2 Lab__st_2_of_string(char* s) {
  if ((strcmp(s, "St_2_Turn90Right")==0)) {
    return Lab__St_2_Turn90Right;
  };
  if ((strcmp(s, "St_2_Forward")==0)) {
    return Lab__St_2_Forward;
  };
  if ((strcmp(s, "St_2_Backwards")==0)) {
    return Lab__St_2_Backwards;
  };
}

char* string_of_Lab__st_2(Lab__st_2 x, char* buf) {
  switch (x) {
    case Lab__St_2_Turn90Right:
      strcpy(buf, "St_2_Turn90Right");
      break;
    case Lab__St_2_Forward:
      strcpy(buf, "St_2_Forward");
      break;
    case Lab__St_2_Backwards:
      strcpy(buf, "St_2_Backwards");
      break;
    default:
      break;
  };
  return buf;
}

Lab__st_1 Lab__st_1_of_string(char* s) {
  if ((strcmp(s, "St_1_Turn90Left")==0)) {
    return Lab__St_1_Turn90Left;
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
    case Lab__St_1_Turn90Left:
      strcpy(buf, "St_1_Turn90Left");
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
  if ((strcmp(s, "Turn90Left")==0)) {
    return Lab__Turn90Left;
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
  if ((strcmp(s, "TurnLeftEnd")==0)) {
    return Lab__TurnLeftEnd;
  };
  if ((strcmp(s, "Stop")==0)) {
    return Lab__Stop;
  };
  if ((strcmp(s, "Backwards")==0)) {
    return Lab__Backwards;
  };
  if ((strcmp(s, "Forward")==0)) {
    return Lab__Forward;
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
    case Lab__Turn90Left:
      strcpy(buf, "Turn90Left");
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
    case Lab__TurnLeftEnd:
      strcpy(buf, "TurnLeftEnd");
      break;
    case Lab__Stop:
      strcpy(buf, "Stop");
      break;
    case Lab__Backwards:
      strcpy(buf, "Backwards");
      break;
    case Lab__Forward:
      strcpy(buf, "Forward");
      break;
    default:
      break;
  };
  return buf;
}

