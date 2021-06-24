#include "GameArea.h"
#include <string>

GameArea::GameArea()
{
	rows = 10;
	columns = 50;
	area = new Field * [rows];
	for (int i = 0; i < rows; i++)
	{
		area[i] = new Field[columns];
	}
}

GameArea::GameArea(int rows, int columns)
{
	if (rows<=0 || columns<=0) 
	{
		std::string exception = "Zly rozmiar planszy!";
		throw exception; 
	}
	else
	{
		this->rows = rows;
		this->columns = columns;
		area = new Field * [rows];
		for (int i = 0; i < rows; i++)
		{
			area[i] = new Field[columns];
		}
	}
}

GameArea::GameArea(const GameArea & g)
{
	rows = g.rows;
	columns = g.columns;
	area = new Field * [g.rows];
	for (int i = 0; i < g.rows; i++)
	{
		area[i] = new Field[g.columns];
	}
}

GameArea &GameArea ::operator= (const GameArea& g)
{
	if (&g != this) 
	{
		rows = g.rows;
		columns = g.columns;
		area = new Field * [g.rows];
		for (int i = 0; i < g.rows; i++)
		{
			area[i] = new Field[g.columns];
		}
	} return *this;
}

GameArea:: ~GameArea() 
{
	for (int i = 0; i < rows; i++)
	{
		delete[] area[i];
	}
	delete[] area;
}
int GameArea::getRows() const
{
	return rows;
}

int GameArea::getColumns() const
{
	return columns;
}

void GameArea::setRows(int r)
{
	r = rows;
}

void GameArea::setColumns(int c)
{
	c = columns;
}

void GameArea::setField(int X, int Y)
{
	area[X][Y].setIceFloe();
}

bool GameArea::getField(int X, int Y)
{
	bool info;
	info = area[X][Y].getInformation();
	return info;
}