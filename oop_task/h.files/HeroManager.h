#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Hero.h"

using namespace std;

class HeroManager
{
public:

	vector<Hero> heroes;

	void createHeroes(int a) {
		vector<string> names = {
			"Hero1", "Hero2", "Hero3", "Hero4", "Hero5", "Hero6", "Hero7", "Hero8", "Hero9", "Hero10", "Oliver", "Jake"
		};
		srand(time(NULL));
		for (int i = 0; i < heroes.size(); i++) {
			int id = rand() % 10;
			int hp = rand() % 100 + 1;
			int damage = rand() % 10 + 1;
			int speed = rand() % 5 + 1;
			Hero hero = Hero(names[id], hp, damage, speed);
			heroes.push_back(hero);
		}
	}

	void ListOfHeroes() {
		cout << "Heroes" << endl << endl;
		for (size_t i = 0; i < heroes.size(); i++) {
			cout << "Name: " << heroes[i].getName()
				<< "\tHP: " << heroes[i].getHP()
				<< "\tDamage: " << heroes[i].getDamage()
				<< "\tSpeed: " << heroes[i].getSpeed()
				<< endl << endl;
		}
	}

	Hero GetHeroByName(string name) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) {
				cout << "Name: " << heroes[i].getName()
					<< "\tHP: " << heroes[i].getHP()
					<< "\tDamage: " << heroes[i].getDamage()
					<< "\tSpeed: " << heroes[i].getSpeed()
					<< endl << endl;
				return heroes[i];
			}
		}
	}

	int AddHero(string name, int hp, int damage, int speed) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) {
				cout << "This name already exists!" << endl;
				return 0;
			}
		}
		Hero hero = Hero(name, hp, damage, speed);
		heroes.push_back(hero);
	}

	void RemovePlayer(string name) {
		for (size_t i = 0; i < heroes.size(); i++) {
			if (heroes[i].getName() == name) heroes.erase(heroes.begin() + i);
			break;
		}
	}
};
