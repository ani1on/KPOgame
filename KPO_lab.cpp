#include "Classes.h"
#include "Movement.h"
#include "Utility.h"
using namespace std;
//156 45
Character Player;
struct Options {//структура с переменными настроек
	string Difficulty;//сложность
	stack<int> DungeonSize;//размер игрового поля
	int HealthPoint;//жизненные очки
	Options() {
		Difficulty = "low";
		HealthPoint = 1;
		DungeonSize.push(0);
	}
} Option;

//Общие функции

void UserInput(char A, char a);//ожидание пользователя
void UserChoice(int ymax, int ymin, int x, int& sol, int step);//функция выбора
//Меню игры
void Menu(bool& QuitGame);//Основная функция игры
void MenuOptions();//Подменю настроек игры
void MenuAbout();//подменю о программе
//Игра
void StartGame();//начало игры
//workwithfiles
void WriteToSettingFile();//запись в файл настроек
void ReadFromSettingFile();//чтение файла настроек
int main()
{
	//Options option;//объект, хронящий данные настроек
	bool QuitGame = false;//переменная выхода из игры
	for (;;) {//основной цикл игры

		Menu(QuitGame);//ф-ия меню
		if (QuitGame) {//проверка на выход из игры
			SetCursorPosition(65, 20);
			cout << "Exit the game";
			return 0;
		}
		Player.SetMaxHP(Option.HealthPoint * 20);

		StartGame();
		SetCursorPosition(0, 0);

	}

}
void UserInput(char A, char a) {//считывание нажатой клавиши
	char key;
	do {
		key = _getch();
	} while (key != A && key != a);

}

void Menu(bool& QuitGame) {
	ReadFromSettingFile();
	//константы подменю
	const int MenuSolutionStart = 0;
	const int MenuSolutionLoad = 1;
	const int MenuSolutionOptions = 2;
	const int MenuSolutionAbout = 3;
	const int MenuSolutionQuit = 4;
	for (;;) {//цикл меню
		system("cls");
		Sleep(400);
		int choice = 0;//выбор поьзователя
		SetCursorPosition(65, 20);
		cout << "Dungeon Adventure";
		SetCursorPosition(70, 22);
		cout << "New Game";
		SetCursorPosition(70, 23);
		cout << "Load Game";
		SetCursorPosition(70, 24);
		cout << "Options";
		SetCursorPosition(70, 25);
		cout << "About";
		SetCursorPosition(70, 26);
		cout << "Quit";
		UserChoice(26, 22, 69, choice, 1);
		switch (choice) {//условия перехода
		case MenuSolutionStart://начало игры

			return;
			break;
		case MenuSolutionLoad:

			return;
			break;
		case MenuSolutionOptions://настройки
			MenuOptions();
			break;
		case MenuSolutionAbout://о программе
			MenuAbout();
			break;
		case MenuSolutionQuit://выход из игры
			QuitGame = true;
			return;
			break;

		}
	}
}

void MenuOptions() {//поденю настройки игры
	const string DifLow = "low";
	const string DifNormal = "normal";
	const string DifHard = "hard";
	system("cls");
	for (int choice = 0;;) {//цикл подменю
		SetCursorPosition(40, 20);
		cout << "Options";
		SetCursorPosition(39, 22);
		cout << "Difficulty:" << Option.Difficulty << "      ";
		SetCursorPosition(39, 23);
		cout << "Dungeon size:" << Option.DungeonSize.top();
		SetCursorPosition(39, 24);
		cout << "HealthPoint:" << Option.HealthPoint;
		SetCursorPosition(39, 25);
		cout << "Save Setting";
		SetCursorPosition(39, 26);
		cout << "Undo Dungeon Size";
		SetCursorPosition(39, 27);
		cout << "Return last save";

		SetCursorPosition(39, 28);
		cout << "Back";
		Sleep(500);
		UserChoice(28, 22, 38, choice, 1);//выбор пользователем
		int value = 0;
		switch (choice) {//изменение выбранных значений
		case 0:
			if (Option.Difficulty == DifLow) {
				Option.Difficulty = DifNormal;
			}
			else {
				if (Option.Difficulty == DifNormal) {
					Option.Difficulty = DifHard;
				}
				else {
					Option.Difficulty = DifLow;
				}
			}
			break;
		case 1:
			if (!Option.DungeonSize.empty()) {
				value = Option.DungeonSize.top();
			}
			value++;
			if (value > 5) {
				value = 0;
			}
			Option.DungeonSize.push(value);
			break;
		case 2:
			Option.HealthPoint++;
			if (Option.HealthPoint > 5) {
				Option.HealthPoint = 0;
			}
			break;
		case 3:
			WriteToSettingFile();
			SetCursorPosition(50, 29);
			cout << "Save successful!";
			Sleep(500);
			SetCursorPosition(50, 29);
			cout << "                  "; // Очищаем сообщение
			break;
		case 4: // Новый случай - откат DungeonSize
			if (Option.DungeonSize.size() > 1) {
				Option.DungeonSize.pop();
				// Показываем сообщение об успешном откате
				SetCursorPosition(50, 29);
				cout << "Undo successful!";
				Sleep(500);
				SetCursorPosition(50, 29);
				cout << "                  "; // Очищаем сообщение
			}
			else {
				// Показываем сообщение, если откат невозможен
				SetCursorPosition(50, 29);
				cout << "Cannot undo further!";
				Sleep(500);
				SetCursorPosition(50, 29);
				cout << "                     "; // Очищаем сообщение
			}
			break;
		case 5:
			ReadFromSettingFile();
			break;
		case 6:
			
			return;
			break;

		}

	}

}
void MenuAbout() {//о программе
	system("cls");
	SetCursorPosition(0, 10);
	cout << R"(
                      "Dungeon Adventure"
           Version: 1
           Creator: Dubovik Ivan
           Group:   PO-14

                           Q - back
)";//вывод данных
	UserInput('Q', 'q');
}
void StartGame() {//начало игры
	system("cls");
	MainMovement(85,30,88,30);
	SetCursorPosition(70, 20);
	cout << "GAME STARTED";
	SetCursorPosition(73, 22);
	cout << "q - back";
	UserInput('q', 'Q');
}
void WriteToSettingFile() {
	ofstream file1("setting.txt");
	if (!file1) {
		cerr << "Ошибка открытия файла для записи!" << endl;
		return;
	}
	file1 << Option.HealthPoint << endl;
	file1 << Option.Difficulty << endl;
	file1.close();

	ofstream file2("settingDSize.txt");
	if (!file2) {
		cerr << "Ошибка открытия файла для записи!" << endl;
		return;
	}

	// Создаем временный стек для сохранения порядка
	stack<int> temp = Option.DungeonSize;

	// Записываем в файл в правильном порядке
	while (!temp.empty()) {
		file2 << temp.top() << " ";
		temp.pop();
	}
	file2.close();
}
void ReadFromSettingFile() {
	ifstream file1("setting.txt");
	
	if (!file1) {
		cerr << "Ошибка открытия файла для записи!" << endl;
		return;
	}

	file1 >> Option.HealthPoint;
	file1.ignore(); // Пропускаем символ новой строки
	getline(file1, Option.Difficulty);
	file1.close();

	ifstream file2("settingDSize.txt");
	if (!file2) {
		cerr << "Ошибка открытия файла для чтения!" << endl;
		return;
	}
	// Очищаем текущий стек
	while (!Option.DungeonSize.empty()) {
		Option.DungeonSize.pop();
	}

	// Читаем значения и складываем во временный стек
	stack<int> temp;
	int value;
	while (file2 >> value) {
		temp.push(value);
	}

	// Перекладываем в основной стек в правильном порядке
	while (!temp.empty()) {
		Option.DungeonSize.push(temp.top());
		temp.pop();
	}
	file2.close();
}
