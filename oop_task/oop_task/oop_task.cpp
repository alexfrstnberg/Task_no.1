#include <iostream>
#include <vector>
using namespace std;


class Player {
public:

	Player(string Name, int Rank, int id) : Name(Name), Rank(Rank), id(id) {
		//this->Name = Name; this->Rank = Rank; this->id = id;
	}
	string Name;
	int Rank = 1000;

	void Change_Name(string Name) {
		this->Name = Name;

	}

	void ready() {
		cout << "Hero " << Name << " is ready" << endl;
	}
private:
	int id;
};

class Hero {
public:
	Hero() {}
	//Hero(string name, int hp, short int damage, short int speed) :name(name), hp(hp),
		//damage(damage), speed(speed) {}
	void printInfo() {

		cout << "Hero: " << Name << endl
			<< "HP: " << HP << endl
			<< "Damage: " << Damage << endl
			<< "Speed: " << Speed << endl;
	}
	string Name;
	int HP = 100;
	short int Damage;
	short int Speed;
private:




};
vector<Hero> hero(10);
string HeroName[] = { "Hero1", "Hero2", "Hero3", "Hero4", "Hero5", "Hero6", "Hero7", "Hero8", "Hero9", "Hero10" };
int HeroDamage[] = { 10,  15,  20,  25,  30,  30,  25,  20,  15,  10 };
int HeroSpeed[] = { 200, 245, 280, 250, 250, 230, 225, 220, 220, 250 };
void CreateHero() {
	for (int i = 0; i < 10; i++) {
		int j = rand() % 10;
		hero[i].Name = HeroName[j];
		// hero[i].HP = HeroHP[i];
		hero[i].Damage = HeroDamage[j];
		hero[i].Speed = HeroSpeed[j];
	}
}

class Session {
public:
	int Start_Time;

};



class TeamPart {
public:

};

class Player_Manager {
public:

};

class Hero_Manager {
public:

};

class Game_Manager {
public:

};



int main() {


	CreateHero();
	for (int i = 0; i < 10; i++)
		hero[i].printInfo();
	system("pause");
}