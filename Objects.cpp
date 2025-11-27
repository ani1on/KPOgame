// GameObjects.cpp
#include "Objects.h"

// Общие (Common) - ОПРЕДЕЛЕНИЯ
const Weapon WeaponSwordStudent(Sword, Common, 3, "Меч студента");
const Weapon WeaponAxeGardener(Axe, Common, 5, "Топор садовника");
const Weapon WeaponBowWoterPistol(Bow, Common, 2, "Водяной пистолетик");
const Weapon WeaponDaggerPen(Dagger, Common, 2, "Ручка 'БрГТУ'");
const Weapon WeaponSpearStick(Spear, Common, 3, "Палка");

const Armor ArmorTNF(Common, 3, 100, "Пуханчик 'Зе Норс Фейс'");
const Armor ArmorOldSweatar(Common, 2, 100, "Потрепанный свитер");

const Object ObjectHat(Common, "Шляпа в тесте", Heal);
const Object ObjectProteinBar(Common, "Протеиновый батончик", AttackBoost);
const Object ObjectReference(Common, "Справка с больничного", DefenceBoost);

// Редкие (Rare) - ОПРЕДЕЛЕНИЯ
const Weapon WeaponSwordWooden(Sword, Rare, 9, "Деревянный меч");
const Weapon WeaponAxeRake(Axe, Rare, 15, "Топор садовника");
const Weapon WeaponBowSlingshot(Bow, Rare, 7, "Рогатка");
const Weapon WeaponDaggerButerfly(Dagger, Rare, 8, "Нож бабочка (тупой)");
const Weapon WeaponSpearCoolStick(Spear, Rare, 13, "Крутая палка");

const Armor ArmorRobe(Rare, 10, 100, "Роба рабочего");
const Armor ArmorAdidas(Rare, 6, 100, "Костюм 'Абидас'");

const Object ObjectHotDog(Rare, "ХочДог", Heal);
const Object Object5(Rare, "5 раз за спецназ", AttackBoost);
const Object ObjectShpak(Rare, "Шпак", DefenceBoost);

// Эпические (Epic) - ОПРЕДЕЛЕНИЯ
const Weapon WeaponSwordPirat(Sword, Epic, 25, "Пиратская сабля");
const Weapon WeaponAxeGrandfather(Axe, Epic, 30, "Топор деда");
const Weapon WeaponBowWooden(Bow, Epic, 15, "Деревянный лук");
const Weapon WeaponDaggerScrewdriver(Dagger, Epic, 12, "Отверка плюсовая");
const Weapon WeaponSpearOverCoolStick(Spear, Epic, 25, "Самая крутая палка");

const Armor ArmorBlazer(Epic, 20, 100, "Пиджак");
const Armor ArmorHelmet(Epic, 30, 100, "Каска рабочего");

const Object ObjectBurger(Epic, "Бургур с кефаса", Heal);
const Object ObjectEnergyDrink(Epic, "Энергетик", AttackBoost);
const Object ObjectUnderpants(Epic, "Подштаники", DefenceBoost);

// Легендарные (Legendary) - ОПРЕДЕЛЕНИЯ
const Weapon WeaponSwordDream(Sword, Legendary, 70, "Меч сноведений");
const Weapon WeaponAxe2(Axe, Legendary, 50, "Топор двуручный");
const Weapon WeaponBowPistol(Bow, Legendary, 60, "Пистолет охранника");
const Weapon WeaponDaggerKnife(Dagger, Legendary, 40, "Кухонный нож");
const Weapon WeaponSpearMetal(Spear, Legendary, 50, "Арматурина");

const Armor ArmorSecurity(Legendary, 20, 100, "Броня инкосатора");
const Armor ArmorUSSR(Legendary, 30, 100, "Советская телогрейка");

const Object ObjectShawarma(Legendary, "Шавуха из пападонера", Heal);
const Object ObjectRadBull(Legendary, "Редбул", AttackBoost);
const Object ObjectPainkiller(Legendary, "Обезбол", DefenceBoost);