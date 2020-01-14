#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Hero {
public:
	string Name;
	int HP = 100;
	int Damage;
	int Speed;

	Hero() {}
	
	Hero(string name, int hp, int damage, short int speed) :name(name), hp(hp), damage(damage), speed(speed) {}
	

};

