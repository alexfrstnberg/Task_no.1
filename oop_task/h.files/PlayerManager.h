#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Player.h"

using namespace std;

class PlayerManager
{
public:
	vector<Player> players;

	void generatePlayers(int n) {
		vector<string> names = {
			"Player1", "Player2", "Player3", "Player4", "Player5", "Player6", "Player7", "Player8", "Player9", "Player10"
		};
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			int id = rand() % names.size();
			Player player = Player(names[id], 1000, i + 1);
			players.push_back(player);
		}
	}

	
	void ListOfPlayers() {
		cout << "Players:" << endl << endl;
		for (size_t i = 0; i < players.size(); i++) {
			cout << "Name: " << players[i].getName()
				<< "\tID: " << players[i].getID()
				<< "\tRank: " << players[i].getRank()
				<< endl << endl;
		}
	}

	Player GetPlayerByName(string name) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getName() == name) {
				//Test
				cout << "Name: " << players[i].getName()
					<< "\tID: " << players[i].getID()
					<< "\tRank: " << players[i].getRank()
					<< endl << endl;
				//End test
				return players[i];
			}
			else continue;
		}
	}

	Player GetPlayerById(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getID() == id) {
				cout << "Name: " << players[i].getName()
					<< "\tID: " << players[i].getID()
					<< "\tRank: " << players[i].getRank()
					<< endl << endl;
				return players[i];
			}
		}
	}

	void AddPlayer(string name) {
		int id = players[players.size() - 1].getID() + 1;
		Player player = Player(name, 1000, id);
		players.push_back(player);
	}

	void RemovePlayer(int id) {
		for (size_t i = 0; i < players.size(); i++) {
			if (players[i].getID() == id) players.erase(players.begin() + i);
			break;
		}
	}
};
