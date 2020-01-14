#pragma once
#include <iostream>
#include <vector>
using namespace std;


class Player {
public:

	string Name;
	int Rank = 1000;

	Player(string Name, int Rank, int id) : Name(Name), Rank(Rank), id(id) {
	}

    void Change_Name(string Name) {
		this->Name = Name;

	}

	void ready() {
		cout << "Hero " << Name << " is ready" << endl;
	}
private:
	int id;
};