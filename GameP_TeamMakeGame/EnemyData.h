#pragma once
#include "Position.h"
const int SPAWN_X[4] = { 10,10,20,0 };
const int SPAWN_Y[4] = { 20,0,10,10 };
const int MOVE_X[4] = { 0,0,-1,1 };
const int MOVE_Y[4] = { -1,1,0,0 };
const int MOVE_SPEED = 2;
const int LIFE_INIT = 3;
const float SPAWN_TIME = 1.5f;
const Position PLAYER_POS = { 10,10 };