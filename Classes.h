#pragma once
#include <vector>
#include <string>
using namespace std;

//struct Options {//структура с переменными настроек
//	string Difficulty;//сложность
//	stack<int> DungeonSize;//размер игрового поля
//	int HealthPoint;//жизненные очки
//	Options() {
//		Difficulty = "low";
//		HealthPoint = 1;
//		DungeonSize.push(0);
//	}
//};


enum WeaponType
{
	Sword, Axe, Bow, Dagger, Spear
};

enum RarityType {
	Common, Rare, Epic, Legendary
};

class Weapon {
private:
	WeaponType Type;
	RarityType Rarity;
	int Damage;
	string WeaponName;

public:
	Weapon(WeaponType NewType, RarityType NewRarity, int NewDamage, string NewWeaponName) :
		Type(NewType), Rarity(NewRarity), Damage(NewDamage), WeaponName(NewWeaponName){
	};
	Weapon() {
		Type = Spear;
		Damage = 1;
		Rarity = Common;
		WeaponName = "Broken Spear";
	}
	RarityType getRarity() const { return Rarity; }
	string getName() const { return WeaponName; }
	int getDamage() const { return Damage; }
};

class Armor {
private:
	int ProtectionValue;
	int Durability;
	string ArmorName;
	RarityType Rarity;
public:
	Armor(RarityType NewRarity, int NewProtectionValue, int NewStrength, string NewName) :
		Rarity(NewRarity), ProtectionValue(NewProtectionValue), Durability(NewStrength), ArmorName(NewName) {
	};
	Armor() {
		ProtectionValue = 1;
		Durability = 100;
		ArmorName = "Leather Armor";
		Rarity = Common;
	}
	RarityType getRarity() const { return Rarity; }
	string getName() const { return ArmorName; }
	int getDefense() const { return ProtectionValue; }
	int getDurability() const { return Durability; }
};

enum EffectType {
	Heal, AttackBoost, DefenceBoost
};

class Object {
private:
	RarityType Rarity;
	string ObjectName;
	EffectType Effect;
public:
	Object(RarityType NewRarity, string NewObjectName, EffectType NewEffect) :
		Rarity(NewRarity), ObjectName(NewObjectName), Effect(NewEffect) {
	};
	Object() {
		Rarity = Common;
		ObjectName = "Weak Heal Potion";
		Effect = Heal;
	}
	RarityType getRarity() const { return Rarity; }
	string getName() const { return ObjectName; }
	EffectType getEffect() const { return Effect; }
};

class Inventory {
public:
	vector<Weapon> InvWeapon;
	vector<Armor> InvArmor;
	vector<Object> InvObject;

	
	void pushObject(Object NewObject) {
		InvObject.push_back(NewObject);
	}
	void pushObject(Weapon NewWeapon) {
		InvWeapon.push_back(NewWeapon);
	}
	void pushObject(Armor NewArmor) {
		InvArmor.push_back(NewArmor);
	}
	void delObject(int num) {
		if (num > InvWeapon.size()) {
			num = num - InvWeapon.size();

			if (num > InvArmor.size()) {
				num = num - InvArmor.size();
				InvObject.erase(InvObject.begin() + num - 1);
			}
			else {
				InvArmor.erase(InvArmor.begin() + num - 1);
			}
		}
		else {
			InvWeapon.erase(InvWeapon.begin() + num - 1);
		}
	}

	// Метод для получения предмета по номеру (без удаления)
	Weapon getWeapon(int index) {
		if (index >= 0 && index < InvWeapon.size()) {
			return InvWeapon[index];
		}
		
	}

	Armor getArmor(int index) {
		if (index >= 0 && index < InvArmor.size()) {
			return InvArmor[index];
		}
	
	}

	Object getObject(int index) {
		if (index >= 0 && index < InvObject.size()) {
			return InvObject[index];
		}
	}

	// Метод для получения типа предмета по общему номеру
	string getItemType(int num) {
		if (num > InvWeapon.size()) {
			num = num - InvWeapon.size();

			if (num > InvArmor.size()) {
				return "Object";
			}
			else {
				return "Armor";
			}
		}
		else {
			return "Weapon";
		}
	}

	// Метод для получения предмета по общему номеру
	void getItemByGlobalIndex(int num, Weapon& weapon) {
		if (num <= InvWeapon.size()) {
			weapon = InvWeapon[num - 1];
		}
		else {
			
		}
	}

	void getItemByGlobalIndex(int num, Armor& armor) {
		if (num > InvWeapon.size() && num <= InvWeapon.size() + InvArmor.size()) {
			armor = InvArmor[num - InvWeapon.size() - 1];
		}
		else {
		
		}
	}

	void getItemByGlobalIndex(int num, Object& object) {
		if (num > InvWeapon.size() + InvArmor.size()) {
			object = InvObject[num - InvWeapon.size() - InvArmor.size() - 1];
		}
		else {
	
		}
	}
};



class Character {
private:
	int NumRoom;
	int MaxHealth;
	
	
	
	
	Armor CharArmor;
	
public:  
	Weapon CharWeapon;
	int money;
	int Health;
	int x, y,x2,y2;

Character()
	{
		Weapon NewWeapon;
		Armor NewArmor;
		Inventory NewInventory;
		CharWeapon = NewWeapon;
		CharArmor = NewArmor;
		PlayerInv = NewInventory;
		MaxHealth = 1000;
		x = 7;
		y = 7;
		NumRoom = 1;
		money = 5;

	}

	int getMoney() const { return money; }

	void spendMoney(int amount) { money -= amount; }

	void addMoney(int amount) { money += amount; }

	Inventory PlayerInv;



	
	void SetRoomNum(int NewRoomNum) {
		NumRoom = NewRoomNum;
	}
	void SetCoord(int X, int Y)
	{
		x2 = x = X;
		y2 = y = Y;
	}
	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	void SetMaxHP(int HealthPoint) {
		MaxHealth = HealthPoint;
		Health = MaxHealth;
	}
	void AddHP(int HealthPoint) {
		if ((Health + HealthPoint) > MaxHealth) {
			Health = MaxHealth;
		}
		else {
			Health = Health + HealthPoint;
		}
	}
};



