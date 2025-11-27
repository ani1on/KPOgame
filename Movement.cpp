
#include "Movement.h"
void moveStep(int& x, int& y, char direction) {
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
	case 'W': // Вверх
		position = { static_cast<SHORT>(x), static_cast<SHORT>(y - 1) };
		if (y > 0 && ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			y--;
		}
		break;

	case 'S': // Вниз
		position = { static_cast<SHORT>(x), static_cast<SHORT>(y + 1) };
		if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			y++;
		}
		break;

	case 'A': // Влево
		position = { static_cast<SHORT>(x - 1), static_cast<SHORT>(y) };
		if (x > 0 && ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			x--;
		}
		break;

	case 'D': // Вправо
		position = { static_cast<SHORT>(x + 1), static_cast<SHORT>(y) };
		if (ReadConsoleOutputCharacterA(hConsole, &ch, 1, position, &charsRead) && ch == ' ') {
			x++;
		}
		break;
	}

	// Отображаем персонажа на новой позиции
	SetConsoleCursorPosition(hConsole, { static_cast<SHORT>(x), static_cast<SHORT>(y) });
	cout << '@';
}
void clearchar(int x, int y) {
	SetCursorPosition(x, y);
	cout << ' ';
}
void CheckMovementPos(int& px, int& py, int& x, int& y) {

	if ((GetAsyncKeyState('W') & 0x8000)) {
		moveStep(x, y, 'W');
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
	if ((GetAsyncKeyState('A') & 0x8000)) {
		moveStep(x, y, 'A');
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
	if ((GetAsyncKeyState('D') & 0x8000)) {
		moveStep(x, y, 'D');
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}

	if ((GetAsyncKeyState('S') & 0x8000)) {
		moveStep(x, y, 'S');
		if ((px != x) || (py != y)) {
			clearchar(px, py);
			px = x; py = y;
		}
	}
	if ((GetAsyncKeyState('E') & 0x8000)) {

	}
}
void MainMovement(int px, int py, int x2, int y2) {
	int difficult = RandomInRange(1, 4);
	RarityType Rarity;
	switch (difficult) {
	case 1: Rarity = Common; break;
	case 2: Rarity = Rare; break;
	case 3: Rarity = Epic; break;
	case 4: Rarity = Legendary; break;
		
	}
	Monster NewMonster(Rarity);
	RoomTree Tree;
	Character Player;
	Player.SetCoord(px, py);
	Tree.setSize(50);
	NewMonster.SetCoord(50, 20);
	Tree.createTree();
	OutputRoom(Tree);
	for (bool key = true;key;) {
		CheckMovementPos(Player.x, Player.y, Player.x2, Player.y2);
		
		RoomTransition(ChoosingPath(Player.x, Player.y),Tree,Player);

		Sleep(50);

	}
}