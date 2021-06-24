#ifndef _gameh_
#define _gameh_

#include <vector>
#include <string>
#include <time.h> 
#include <fstream>
#include <cstdlib>

#include "Engine.h"

class Game : public Engine
{
protected:
	std::vector<std::pair<std::string, double> > Users;
	unsigned long id;
	int usersAmount;
	std::fstream gameAreaFile;
	std::fstream gameResultsFile;

public:

	Game();
	virtual ~Game();
	Game(const Game &g);
	Game& operator=(const Game& g);
	virtual void start();
	virtual void newGame();
	virtual void loadOldGame();
	virtual void generateArea();
	virtual void play(int usersAmount);
	virtual void exportArea();
	virtual void exportResults();
	virtual void displayGameRules()=0;
	virtual void displayMenu() = 0;
	virtual char userDecision() = 0;
	virtual void displayResults() = 0;
	virtual void displayGame() = 0;
	virtual void displayExit() = 0;
	virtual int move() = 0;
	virtual int countOfUsers() = 0;
	virtual int rowSize() = 0;
	virtual int columnSize() = 0;
	virtual void counting() = 0;
	virtual std::string readNick() = 0;
	virtual void errorHandling(std::string error) = 0;
	virtual void saveUserTime(double userTime, std::string nick, std::vector<std::pair<std::string, double> > &Users);
	virtual void resetUsers();
	virtual unsigned long readID() = 0;
	virtual void loadArea(unsigned long &loadID, unsigned long  &actualID, std::string &ignore, int &r, int &c);
private:
	virtual void parser(int index, std::string numbers);
};

#endif