#ifndef _gameareah_
#define _gameareah_
#include "Field.h"
class GameArea
{
protected:
	Field** area;
	int rows;
	int columns;
public:
	GameArea();
	GameArea(int rows, int columns);
	GameArea(const GameArea & g);
	GameArea &operator=(const GameArea& g);
	virtual ~GameArea();
	int getRows() const;
	int getColumns() const;
	void setRows(int rows);
	void setColumns(int columns);
	void setField(int X, int Y);
	bool getField(int X, int Y);

};

#endif