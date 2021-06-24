#ifndef _gametxth_
#define _gametxth_
#include "Game.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

class Gametxt : public Game
{
public:
	Gametxt() {}
	virtual ~Gametxt() {}
	Gametxt(const Gametxt& g) {}
	Gametxt& operator=(const Gametxt& g) {}
	virtual void displayMenu();
	virtual char userDecision();
	virtual void displayGame();
	virtual int move();
	virtual void displayGameRules();
	virtual void displayResults();
	virtual void displayExit();
	virtual int countOfUsers();
	virtual int rowSize();
	virtual int columnSize();
	virtual void counting();
	virtual std::string readNick();
	virtual void errorHandling(std::string error);
	virtual unsigned long readID();
};
#endif