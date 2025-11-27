#pragma once
#include <iostream>
#include "Monster.h"
#include <conio.h>
#include <windows.h>
#include "Utility.h"

#include "Classes.h"
#include "Map.h"
#include "Event.h"
using namespace std;
void moveStep(int& x, int& y, char direction);
void CheckMovementPos(int& px, int& py, int& x, int& y);
void moveStep(int& x, int& y, char direction);
void clearchar(int x, int y);//очистка следов за игроком
void MainMovement(int px, int py, int x2, int y2);

