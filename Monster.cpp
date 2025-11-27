#include "Monster.h"	




void moveStepMonster(int& x, int& y, int direction) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char ch;
	DWORD charsRead;
	COORD position;

	// Скрываем курсор
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo);

	// Проверяем направление движения и наличие пробела
	switch (direction) {
	case 1: // Вверх
		position = { static_cast<SHORT>(x), static_cast<SHORT>(y - 1) };
		if (y > 0 && ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			y--;
		}
		break;

	case 2: // Вниз
		position = { static_cast<SHORT>(x), static_cast<SHORT>(y + 1) };
		if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			y++;
		}
		break;

	case 3: // Влево
		position = { static_cast<SHORT>(x - 1), static_cast<SHORT>(y) };
		if (x > 0 && ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			x--;
		}
		break;

	case 4: // Вправо
		position = { static_cast<SHORT>(x + 1), static_cast<SHORT>(y) };
		if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			x++;
		}
		break;
	}
	// Отображаем персонажа на новой позиции
	SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(x), static_cast<SHORT>(y) });
	cout << '&';
}

void CheckMovementPosMonster(int& px, int& py, int& x, int& y, Character Player) {
	if (Player.y>y) {
		moveStepMonster(x, y, 2);
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
	if (Player.y<y) {
		moveStepMonster(x, y, 1);
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
	if (Player.x > x) {
		moveStepMonster(x, y, 4);
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}

	if (Player.x < x) {
		moveStepMonster(x, y, 3);
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
}