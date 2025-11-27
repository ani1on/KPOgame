#pragma once
#include "Map.h"
#include "Utility.h"
#include "Classes.h"
#include "Objects.h"
#include "Monster.h"
class Trader {
private:
	Inventory TraderInv;
	RarityType TraderRarity;

	int calculatePrice(const string& itemType, RarityType rarity) {
		int basePrice = 0;

		// Базовая цена в зависимости от типа предмета
		if (itemType == "Weapon") basePrice = 100;
		else if (itemType == "Armor") basePrice = 80;
		else if (itemType == "Object") basePrice = 50;

		// Множитель в зависимости от редкости
		int multiplier = 1;
		switch (rarity) {
		case Common: multiplier = 1; break;
		case Rare: multiplier = 2; break;
		case Epic: multiplier = 3; break;
		case Legendary: multiplier = 5; break;
		}

		return basePrice * multiplier;
	}
public:
    Trader(RarityType NewRarity) {
        TraderRarity = NewRarity;
    }
    RarityType GetTraderRarity() {
        return TraderRarity;
    }
    void DelInvObject(int ObjectNum) {
        TraderInv.delObject(ObjectNum);
    }

    // Метод для продажи предмета игроку
    void SaleObject(int ObjectNum, Character& Player) {
        string itemType = TraderInv.getItemType(ObjectNum);
        int price = 0;

        if (itemType == "Weapon") {
            Weapon weapon;
            TraderInv.getItemByGlobalIndex(ObjectNum, weapon);
            price = calculatePrice("Weapon", weapon.getRarity());

            // Проверяем, хватает ли у игрока денег
            if (Player.getMoney() >= price) {
                Player.spendMoney(price); // Списываем деньги
                Player.PlayerInv.pushObject(weapon);
                TraderInv.delObject(ObjectNum);

                cout << "Куплено: " << weapon.getName() << " за " << price << " монет\n";

            }
            else {

                cout << "Недостаточно монет! Нужно: " << price << ", у вас: " << Player.getMoney() << "\n";

            }
        }
        else if (itemType == "Armor") {
            Armor armor;
            TraderInv.getItemByGlobalIndex(ObjectNum, armor);
            price = calculatePrice("Armor", armor.getRarity());

            if (Player.getMoney() >= price) {
                Player.spendMoney(price);
                Player.PlayerInv.pushObject(armor);
                TraderInv.delObject(ObjectNum);

                cout << "Куплено: " << armor.getName() << " за " << price << " монет\n";

            }
            else {

                cout << "Недостаточно монет! Нужно: " << price << ", у вас: " << Player.getMoney() << "\n";

            }
        }
        else if (itemType == "Object") {
            Object object;
            TraderInv.getItemByGlobalIndex(ObjectNum, object);
            price = calculatePrice("Object", object.getRarity());

            if (Player.getMoney() >= price) {
                Player.spendMoney(price);
                Player.PlayerInv.pushObject(object);
                TraderInv.delObject(ObjectNum);

                cout << "Куплено: " << object.getName() << " за " << price << " монет\n";

            }
            else {

                cout << "Недостаточно монет! Нужно: " << price << ", у вас: " << Player.getMoney() << "\n";

            }
        }
    }

    // Метод для покупки предмета у игрока (игрок продает торговцу)
    void BuyFromPlayer(int ObjectNum, Character& Player) {
        string itemType = Player.PlayerInv.getItemType(ObjectNum);
        int price = 0;

        if (itemType == "Weapon") {
            Weapon weapon;
            Player.PlayerInv.getItemByGlobalIndex(ObjectNum, weapon);
            price = calculatePrice("Weapon", weapon.getRarity()) / 2; // Игрок получает половину цены

            this->TraderInv.pushObject(weapon);
            Player.PlayerInv.delObject(ObjectNum);
            Player.addMoney(price);
            cout << "Продано: " << weapon.getName() << " за " << price << " монет\n";
        }
        else if (itemType == "Armor") {
            Armor armor;
            Player.PlayerInv.getItemByGlobalIndex(ObjectNum, armor);
            price = calculatePrice("Armor", armor.getRarity()) / 2;

            this->TraderInv.pushObject(armor);
            Player.PlayerInv.delObject(ObjectNum);
            Player.addMoney(price);
            cout << "Продано: " << armor.getName() << " за " << price << " монет\n";
        }
        else if (itemType == "Object") {
            Object object;
            Player.PlayerInv.getItemByGlobalIndex(ObjectNum, object);
            price = calculatePrice("Object", object.getRarity()) / 2;

            this->TraderInv.pushObject(object);
            Player.PlayerInv.delObject(ObjectNum);
            Player.addMoney(price);
            cout << "Продано: " << object.getName() << " за " << price << " монет\n";
        }
    }
	void CreateInv() {

		switch (TraderRarity) {
		case Common:

			TraderInv.pushObject(WeaponSwordStudent);
			TraderInv.pushObject(WeaponAxeGardener);
			TraderInv.pushObject(WeaponBowWoterPistol);
			TraderInv.pushObject(WeaponDaggerPen);
			TraderInv.pushObject(WeaponSpearStick);

			TraderInv.pushObject(ArmorTNF);
			TraderInv.pushObject(ArmorOldSweatar);

			TraderInv.pushObject(ObjectHat);
			TraderInv.pushObject(ObjectProteinBar);
			TraderInv.pushObject(ObjectReference);

			break;

		case Rare:


			TraderInv.pushObject(WeaponSwordWooden);
			TraderInv.pushObject(WeaponAxeRake);
			TraderInv.pushObject(WeaponBowSlingshot);
			TraderInv.pushObject(WeaponDaggerButerfly);
			TraderInv.pushObject(WeaponSpearCoolStick);

			TraderInv.pushObject(ArmorRobe);
			TraderInv.pushObject(ArmorAdidas);

			TraderInv.pushObject(ObjectHotDog);
			TraderInv.pushObject(Object5);
			TraderInv.pushObject(ObjectShpak);

			break;
		case Epic:


			TraderInv.pushObject(WeaponSwordPirat);
			TraderInv.pushObject(WeaponAxeGrandfather);
			TraderInv.pushObject(WeaponBowWooden);
			TraderInv.pushObject(WeaponDaggerScrewdriver);
			TraderInv.pushObject(WeaponSpearOverCoolStick);

			TraderInv.pushObject(ArmorBlazer);
			TraderInv.pushObject(ArmorHelmet);

			TraderInv.pushObject(ObjectBurger);
			TraderInv.pushObject(ObjectEnergyDrink);
			TraderInv.pushObject(ObjectUnderpants);

			break;

		case Legendary:


			TraderInv.pushObject(WeaponSwordDream);
			TraderInv.pushObject(WeaponAxe2);
			TraderInv.pushObject(WeaponBowPistol);
			TraderInv.pushObject(WeaponDaggerKnife);
			TraderInv.pushObject(WeaponSpearMetal);

			TraderInv.pushObject(ArmorSecurity);
			TraderInv.pushObject(ArmorUSSR);

			TraderInv.pushObject(ObjectShawarma);
			TraderInv.pushObject(ObjectRadBull);
			TraderInv.pushObject(ObjectPainkiller);

			break;
		}
	}
    void ShowInventory() {
        SetCursorPosition(3, 0);
        cout << "=== ИНВЕНТАРЬ ТОРГОВЦА ===";
        SetCursorPosition(3, 2);
        cout << "Редкость торговца: ";
        switch (TraderRarity) {
        case Common: cout << "Обычный"; break;
        case Rare: cout << "Редкий"; break;
        case Epic: cout << "Эпический"; break;
        case Legendary: cout << "Легендарный"; break;
        }

        int itemNumber = 1;

        
        if (TraderInv.InvWeapon.empty()) {
            cout << "Пусто";
        }
        else {
            for (const auto& weapon : TraderInv.InvWeapon) {
                int price = calculatePrice("Weapon", weapon.getRarity());
                SetCursorPosition(3, 5+itemNumber);
                cout << itemNumber << ". " << weapon.getName();
                cout << " | Урон: " << weapon.getDamage();
                cout << " | Редкость: ";
                switch (weapon.getRarity()) {
                case Common: cout << "Обычный"; break;
                case Rare: cout << "Редкий"; break;
                case Epic: cout << "Эпический"; break;
                case Legendary: cout << "Легендарный"; break;
                }
                cout << " | Цена: " << price << " монет";
                itemNumber++;
            }
        }
        
        if (TraderInv.InvArmor.empty()) {
            cout << "Пусто";
        }
        else {
            for (const auto& armor : TraderInv.InvArmor) {
                SetCursorPosition(3, 5 + itemNumber);
                int price = calculatePrice("Armor", armor.getRarity());
                cout << itemNumber << ". " << armor.getName();
                cout << " | Защита: " << armor.getDefense();
                cout << " | Прочность: " << armor.getDurability();
                cout << " | Редкость: ";
                switch (armor.getRarity()) {
                case Common: cout << "Обычный"; break;
                case Rare: cout << "Редкий"; break;
                case Epic: cout << "Эпический"; break;
                case Legendary: cout << "Легендарный"; break;
                }
                cout << " | Цена: " << price << " монет";
                itemNumber++;
            }
        }

        // Вывод объектов
        
        if (TraderInv.InvObject.empty()) {
            cout << "Пусто";
        }
        else {
            for (const auto& object : TraderInv.InvObject) {
                SetCursorPosition(3, 5 + itemNumber);
                int price = calculatePrice("Object", object.getRarity());
                cout << itemNumber << ". " << object.getName();
                cout << " | Эффект: ";
                switch (object.getEffect()) {
                case Heal: cout << "Лечение"; break;
                case AttackBoost: cout << "Усиление атаки"; break;
                case DefenceBoost: cout << "Усиление защиты"; break;
                }
                cout << " | Редкость: ";
                switch (object.getRarity()) {
                case Common: cout << "Обычный"; break;
                case Rare: cout << "Редкий"; break;
                case Epic: cout << "Эпический"; break;
                case Legendary: cout << "Легендарный"; break;
                }
                cout << " | Цена: " << price << " монет                                                  ";
                itemNumber++;
            }
        }
        SetCursorPosition(3, 5 + itemNumber);

        
    }

    // Метод для получения количества предметов у торговца
    int getItemCount() {
        return TraderInv.InvWeapon.size() + TraderInv.InvArmor.size() + TraderInv.InvObject.size();
    }

};

void OutputIvent(Trader& NewTrader);
void TraderEvent(Character& player);
