#pragma once
#include <iostream>
#include <string>
using namespace std;


class Hero {

public:
	string Name;
	int HP = 100;
	int Damage;
	int Speed;

	Hero() {}
	
	Hero(string name, int hp, int damage, short int speed) :name(name), hp(hp), damage(damage), speed(speed) {}
	
	string getName() {
		return name;
	}
	int getHP() {
		return hp;
	}
	int getDamage() {
		return damage;
	}
	int getSpeed() {
		return speed;
	}
};

