#ifndef _engineh_
#define _engineh_
#include "GameArea.h"
#include "Field.h"

class Engine
{
protected:
	GameArea* gA;
	int	penguinX;
	int penguinY;
	int	penguinXstart;
	int penguinYstart;
	int fishX;
	int fishY;
public:
	Engine();
	virtual ~Engine();
	Engine(const Engine& e);
	Engine& operator =(const Engine& e);
	void setPenguinPosition(int x, int y);
	void setPenguinPositionstart(int x, int y);
	void setFishPosition(int x, int y);
	int getPenguinPositionX();
	int getPenguinPositionY();
	int getFishPositionX();
	int getFishPositionY();
	int getPenguinPositionXstart();
	int getPenguinPositionYstart();
	int Analyze(int direction, int x, int y); 
};

#endif