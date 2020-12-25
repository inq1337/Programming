#include <iostream>
#include <vector>

struct Coin {
	short count;
};

struct Rune {
	short level;
	enum class Elenemt {
		FIRE,
		WATER,
		EARTH,
		AIR
	} element;
};

struct Weapon {
	short damage, critical, durability;
};

struct Armor {
	short guard, durability;
};

enum class ItemType {
	COIN,
	RUNE,
	WEAPON,
	ARMOR
};

struct Item {
	enum class ItemType {
		COIN,
		RUNE,
		WEAPON,
		ARMOR
	} type;
	union Types {
		Coin coin;
		Rune rune;
		Weapon weapon;
		Armor armor;
	};
};

int main()
{
	srand(time(0));
	int chance = (rand() % 10001) + 1;

	std::vector<Item> LootBox;

}