#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "windows.h"
#include "Player.h"
#include "Hero.h"
#include "Team.h"

using namespace std;

template <typename T>
void randVector(vector<T>& vec) {
	srand(time(NULL));
	for (size_t i = 0; i < vec.size(); i++) {
		swap(vec[i], vec[rand() % vec.size()]);
	}
}

class Session
{
	vector<Team> Lobby;
	vector<Team> Red;
	vector<Team> Blue;
	vector<Hero> newHeroes;
	time_t StartTime = 0;

	int winner = -1;

	void chooseWinner() {
		int hpBlue = 0, hpRed = 0, damageBlue = 0, damageRed = 0;
		//Calculate hp and damage
		for (size_t i = 0; i < Blue.size(); i++) {
			hpBlue += Blue[i].hero.getHP();
			damageBlue += Blue[i].hero.getDamage();
		}
		for (size_t i = 0; i < Red.size(); i++) {
			hpRed += Red[i].hero.getHP();
			damageRed += Red[i].hero.getDamage();
		}

		if (hpBlue - damageRed > hpRed - damageBlue) {
			winner = 1;//Blue
		}
		else if (hpBlue - damageRed == hpRed - damageBlue) {
			winner = 0;//Tie
		}
		else {
			winner = 2;//Red
		}
	}

	void AnnounceTheWinner() {
		if (winner > 0) {
			cout << arr[winner] << " won this game" << endl;
		}
		else {
			cout << arr[winner] << endl;
		}
	}

	void ChangeRank(vector<Player>& players) {
		for (size_t i = 0; i < Blue.size(); i++) {

			int idBlue = Blue[i].player.getID();
			int idRed = Red[i].player.getID();

			for (size_t j = 0; j < players.size(); j++)
			{
				switch (winner) {
				case 1:
					if (players[j].getID() == idBlue) players[j].addRank();
					if (players[j].getID() == idRed) players[j].subRank();
					break;
				case 2:
					if (players[j].getID() == idRed) players[j].addRank();
					if (players[j].getID() == idBlue) players[j].subRank();
					break;
				}
			}
		}
	}

	void AddTeamPart() {
		for (size_t i = 0; i < Lobby.size(); i++) {
			if (i < 5) {
				Blue.push_back(Lobby[i]);
			}
			else {
				Red.push_back(Lobby[i]);
			}
		}
	}

	bool checkTeams() {
		int mmrRed = 0, mmrBlue = 0;
		for (size_t i = 0; i < Red.size(); i++) {
			mmrRed += Red[i].player.getRank();
			mmrBlue += Blue[i].player.getRank();
		}
		if (fabs(mmrBlue - mmrRed) >= 100)	return false;
		return true;
	}

	bool checkPlayers() {
		int maxBlue = 0, maxRed = 0, minBlue = 999999999, minRed = 999999999;

		for (size_t i = 0; i < Blue.size(); i++)
		{
			if (Blue[i].player.getRank() > maxBlue) maxBlue = Blue[i].player.getRank();
			if (Blue[i].player.getRank() < minBlue) minBlue = Blue[i].player.getRank();

			if (Red[i].player.getRank() > maxRed) maxRed = Red[i].player.getRank();
			if (Red[i].player.getRank() < minRed) minRed = Red[i].player.getRank();
		}

		if (maxBlue - minBlue >= 200 || maxRed - minRed >= 200) return false;

		return true;
	}

public:
	string arr[3] = { "Tie", "Blue", "Red" };
	//Init
	Session(vector<Player>& players, vector<Hero>& heroes) {
		// Copy heroes to the new array
		for (size_t i = 0; i < heroes.size(); i++) {
			newHeroes.push_back(heroes[i]);
		}

		randVector(players);
		randVector(newHeroes);

		//Add players and heroes to the Lobby
		for (size_t i = 0; i < 10; i++) {
			if (newHeroes.size() < 10) {
				if (i < 5) {
					Team tp = Team(players[i], newHeroes[i]);
					Lobby.push_back(tp);
				}
				else {
					Part tp = Part(players[i], newHeroes[i - 5]);
					Lobby.push_back(tp);
				}
			}
			else {
				Part tp = Part(players[i], newHeroes[i]);
				Lobby.push_back(tp);
			}
		}

		AddTeamPart();
		//Lim 10 000
		for (int i = 0; (!checkTeams() || !checkPlayers()) && i < 10000; i++)
		{
			randVector(Lobby);
			Blue.clear();
			Red.clear();
			AddTeamPart();
		}

		//For randomizing
		Sleep(1000);
	}

	~Session() {
		newHeroes.clear();
		Red.clear();
		Blue.clear();
		Lobby.clear();
	}

	void showRedTeam() {
		cout << endl
			<< "Red Team" << endl << endl;
		for (size_t i = 0; i < Red.size(); i++)
		{
			//Show player info
			cout << "Name: " << Red[i].player.getName()
				<< "\tID: " << Red[i].player.getID()
				<< "\tRank: " << Red[i].player.getRank()
				<< endl;
			//Shwow hero info
			cout << "Name: " << Red[i].hero.getName()
				<< "\tHP: " << Red[i].hero.getHP()
				<< "\tDamage: " << Red[i].hero.getDamage()
				<< "\tSpeed: " << Red[i].hero.getSpeed()
				<< endl
				<< (i == Red.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		cout << endl << endl;
	}

	void showBlueTeam() {
		cout << endl
			<< "                  Blue Team" << endl << endl;
		for (size_t i = 0; i < Blue.size(); i++)
		{
			//Show player info
			cout << "Name: " << Blue[i].player.getName()
				<< "\tID: " << Blue[i].player.getID()
				<< "\tRank: " << Blue[i].player.getRank()
				<< endl;
			//Shwow hero info
			cout << "Name: " << Blue[i].hero.getName()
				<< "\tHP: " << Blue[i].hero.getHP()
				<< "\tDamage: " << Blue[i].hero.getDamage()
				<< "\tSpeed: " << Blue[i].hero.getSpeed()
				<< endl
				<< (i == Blue.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		cout << endl << endl;
	}

	void gameStart(vector<Player>& players) {
		StartTime = time(0);
		chooseWinner();
		AnnounceTheWinner();
		ChangeRank(players);
	}

	time_t getTime() {
		return StartTime;
	}

	void showTime() {
		tm* ltm = localtime(&StartTime);
		cout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\t"
			<< "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
	}

	int getWinner() {
		return winner;
	}

	void saveLog() {
		ofstream fout;
		fout.open("log.txt", ofstream::app);

		fout << endl << endl << "New Game" << endl << endl;

		//Save time
		tm* ltm = localtime(&StartTime);
		fout << "Date: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << "\t"
			<< "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

		//Save winner
		int winner = getWinner();
		fout << arr[winner] << " won" << endl;

		//Save team red
		fout << endl
			<< "                  Red Team" << endl << endl;
		for (size_t i = 0; i < Red.size(); i++)
		{
			//Show player info
			fout << "Name: " << Red[i].player.getName()
				<< "\tID: " << Red[i].player.getID()
				<< "\tRank: " << Red[i].player.getRank()
				<< endl;
			//Shwow hero info
			fout << "Name: " << Red[i].hero.getName()
				<< "\tHP: " << Red[i].hero.getHP()
				<< "\tDamage: " << Red[i].hero.getDamage()
				<< "\tSpeed: " << Red[i].hero.getSpeed()
				<< endl
				<< (i == Red.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		fout << endl << endl;

		//Save team blue
		fout << endl
			<< "                  Blue Team" << endl << endl;
		for (size_t i = 0; i < Blue.size(); i++)
		{
			//Show player info
			fout << "Name: " << Blue[i].player.getName()
				<< "\tID: " << Blue[i].player.getID()
				<< "\tRank: " << Blue[i].player.getRank()
				<< endl;
			//Shwow hero info
			fout << "Name: " << Blue[i].hero.getName()
				<< "\tHP: " << Blue[i].hero.getHP()
				<< "\tDamage: " << Blue[i].hero.getDamage()
				<< "\tSpeed: " << Blue[i].hero.getSpeed()
				<< endl
				<< (i == Blue.size() - 1 ? "" : "------------------------------------------------")
				<< endl;
		}
		fout <<endl << endl;

		fout.close();
	}
};