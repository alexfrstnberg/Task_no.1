#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Player {

private:
	int id;
	string Name;
	int Rank = 1000;

public:
	
	Player(string Name, int Rank, int id) : Name(Name), Rank(Rank), id(id) {
	}

    void Change_Name(string Name) {
		this->Name = Name;

	}

	void addRank() {
		rank += 25;
	}

	void subRank() {
		if (rank >= 25)	rank -= 25;
	}

	void ready() {
		cout << "Hero " << Name << " is ready" << endl;
	}

	string getName() {
		return name;
	}

	int getRank() {
		return rank;
	}

	int getID() {
		return id;
	}
};