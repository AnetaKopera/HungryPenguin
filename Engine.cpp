#include "Engine.h"

Engine::Engine()
{
	gA = 0;
	penguinX = 0;
	penguinY = 0;
	penguinXstart = 0;
	penguinYstart = 0;
	fishX = 0;
	fishY = 0;
}

Engine::Engine(const Engine& e)
{
	gA = e.gA;
	penguinX = e.penguinX;
	penguinY = e.penguinY;
	penguinXstart = e.penguinXstart;
	penguinYstart = e.penguinYstart;
	fishX = e.fishX;
	fishY = e.fishY;
}

Engine& Engine ::operator=(const Engine& e)
{
	if (&e != this)
	{
		gA = e.gA;
		penguinX = e.penguinX;
		penguinY = e.penguinY;
		penguinXstart = e.penguinXstart;
		penguinYstart = e.penguinYstart;
		fishX = e.fishX;
		fishY = e.fishY;
	}
	return *this;
}

Engine::~Engine() 
{
	delete gA; 
}

int Engine::Analyze(int direction, int x, int y)
{
	if (direction == -1)
	{
		//wyjscie 
		return -1;
	}
	else if (direction == 0)
	{
		x--;
	}
	else if (direction == 1)
	{
		x++;
	}
	else if (direction == 2)
	{
		y++;
	}
	else if (direction == 3)
	{
		y--;
	}
	else if(direction == 4)
	{
		return 0; //wcisniety inny klawisz
	}

	if ((x < 0) || (x >= gA->getRows()) || (y < 0) || (y >= gA->getColumns()))
	{
		//gdy poza plansz¹
		return 1;
	}
	else if (gA->getField(x, y) == false)
	{
		//gdy na pole dziura wejdzie
		return 2;
	}
	else
	{
		//dobry ruch
		return 3;
	}
	
}

void Engine::setPenguinPosition(int x, int y)
{
	penguinX = x;
	penguinY = y;
}

void Engine::setPenguinPositionstart(int x, int y)
{
	penguinXstart = x;
	penguinYstart = y;
}

void Engine::setFishPosition(int x, int y)
{
	fishX = x;
	fishY = y;
}

int Engine::getPenguinPositionX()
{
	return penguinX;
}

int Engine::getPenguinPositionY()
{
	return penguinY;
}

int Engine::getPenguinPositionXstart()
{
	return penguinXstart;
}

int Engine::getPenguinPositionYstart()
{
	return penguinYstart;
}

int Engine::getFishPositionX()
{
	return fishX;
}

int Engine::getFishPositionY()
{
	return fishY;
}
