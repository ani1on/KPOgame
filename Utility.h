#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <windows.h>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <fstream>
using namespace std;
void UserChoice(int ymax, int ymin, int x, int& sol, int step);
int RandomInRange(int min, int max);
void SetCursorPosition(int x, int y);//установка курсора в нужное место
double RandomProbability();// устанавливает вероятность 0 - 1.0