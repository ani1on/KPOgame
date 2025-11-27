#include "Utility.h"
void UserChoice(int ymax, int ymin, int x, int& sol, int step) {//функция выбора
	SetCursorPosition(x, ymin + sol * step);//установка в начальное положение
	cout << ">";
	for (int y = ymin + sol * step;;) {//цикл передвижений курсора

		if ((GetAsyncKeyState('W') & 0x8000) && (y > ymin)) {//считывание нажатий и условия соблюдения границ
			SetCursorPosition(x, y);//очистка старого положения
			cout << " ";
			y -= step;//уменьшение значения Y курсора на шаг
			SetCursorPosition(x, y);//установка курсора на новое место
			cout << ">";
			Sleep(200);
			sol--;//уменьшение значения 

		}
		if ((GetAsyncKeyState('S') & 0x8000) && (y < ymax)) {//то же самое что и выше
			SetCursorPosition(x, y);
			cout << " ";
			y += step;
			SetCursorPosition(x, y);
			cout << ">";
			Sleep(200);
			sol++;//увеличение значения
		}
		if (GetAsyncKeyState('E') & 0x8000) {//считывает выбор пользователя
			SetCursorPosition(x, y);//очиска курсора
			cout << " ";
			break;
		}
	}
}
void SetCursorPosition(int x, int y) {//установка курсора
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
	SetConsoleCursorPosition(hConsole, pos);
}

int RandomInRange(int min, int max) {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
// Функция для вероятностей (0.0 до 1.0)
double RandomProbability() {
	static random_device rd;
	static mt19937 gen(rd());
	uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}