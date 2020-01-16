#pragma once
#include <iostream>
#include "Player.h"
#include "Hero.h"

using namespace std;

class Team
{
public:
	Player player;
	Hero hero;

	Team(const Player& player, const Hero& hero) {
		this->player = player;
		this->hero = hero;
	}
};

