#pragma once
#include "Utility.h"
#include "Classes.h"
#include "Movement.h"
class Monster {
private:

	RarityType Rarity;

	int AttackStrenght;
	string MonsterName;
public:
	int HealthPoint;
	int x, y,x2,y2;
	void SetCoord(int nx, int ny) {
		x = nx;
		y = ny;
		x2 = x;
		y2 = y;
	}

	Monster() {
		HealthPoint = 1;
		AttackStrenght = 1;
		MonsterName = "Student";
		Rarity = Common;
	}
	Monster(int NewHealthPoint, int NewAttackStrenght, RarityType NewRarity, string NewName, int newx, int newy) {
		Rarity = NewRarity;
		HealthPoint = NewHealthPoint;
		AttackStrenght = NewAttackStrenght;
		MonsterName = NewName;
	}
	Monster(RarityType NewRarity) {
		Rarity = NewRarity;
		switch (Rarity) {
		case Common:
			AttackStrenght = RandomInRange(1, 5);
			HealthPoint = RandomInRange(10, 20);
			MonsterName = "Hungry Student";
			break;
		case Rare:
			AttackStrenght = RandomInRange(5, 20);
			HealthPoint = RandomInRange(20, 50);
			MonsterName = "Security";
			break;
		case Epic:
			AttackStrenght = RandomInRange(20, 50);
			HealthPoint = RandomInRange(50, 100);
			MonsterName = "Lecturer";
			break;
		case Legendary:
			AttackStrenght = RandomInRange(80, 100);
			HealthPoint = RandomInRange(50, 200);
			MonsterName = "Dean";
			break;
		}
	}
};

void moveStepMonster(int& x, int& y, int direction);
void CheckMovementPosMonster(int& px, int& py, int& x, int& y, Character Player);
