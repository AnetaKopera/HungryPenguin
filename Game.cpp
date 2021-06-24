#include "Game.h"


Game::Game()
{
	usersAmount = 0;
	id =0;
	gameAreaFile.open("gameArea.txt", std::ios::in | std::ios::out | std::ios::app);
	gameResultsFile.open("results.txt", std::ios::out | std::ios::app );
}



Game :: Game(const Game& g)
{
	usersAmount = g.usersAmount;
	id = g.id;
}

Game &Game  :: operator=(const Game& g)
{
	if (&g != this)
	{
		usersAmount = g.usersAmount;
		id = g.id;
	}return *this;
}

Game::~Game()
{
	gameAreaFile.close();
	gameResultsFile.close();
}

void Game::start()
{
	displayMenu();
	char decision;
	decision=userDecision();
	if (decision == '1')
	{
		newGame();
	}
	else if (decision == '2')
	{
		loadOldGame();
	}
	else if (decision == '3')
	{
		displayGameRules();
	}
	else if (decision == '4')
	{
		displayResults();
	}
	else if (decision == '5')
	{
		displayExit();
	}
	else
	{
		start();
	}
}

void Game::newGame()
{
	gameResultsFile.close();
	gameResultsFile.open("results.txt", std::ios::out | std::ios::app);
	try 
	{
		resetUsers();
		int r = 0, c = 0;
		usersAmount = countOfUsers();
		r = rowSize();
		c = columnSize();
		gA = new GameArea(r, c);
		generateArea();
		exportArea();
		play(usersAmount);
	}
	catch (std::string obj)
	{
		errorHandling(obj);
		newGame();
	}
}


void Game::resetUsers()
{
	for (size_t t = Users.size(); t >0; t--)
	{
		Users.pop_back();
	}
}

void Game::play(int usersAmount)
{
	for (int i = 0; i < usersAmount; i++)
	{
		time_t startTime, endTime;
		double userTime;
		setPenguinPosition(getPenguinPositionXstart(), getPenguinPositionYstart());
		std::string nick= readNick();
		counting();
		displayGame();
		time(&startTime);
		while ((getPenguinPositionX ()!= getFishPositionX()) || (getPenguinPositionY ()!= getFishPositionY()))
		{
			int direction = move();
			int action=Analyze(direction, penguinX, penguinY);
			if (action == -1)
			{
				start();
				break; 
			}
			else if (action == 2)
			{
				setPenguinPosition(getPenguinPositionXstart(), getPenguinPositionYstart());
			
			}
			else if (action == 3)
			{
				
				if (direction == 0)
				{
					setPenguinPosition(getPenguinPositionX()-1, getPenguinPositionY());
				}
				else if (direction == 1)
				{
					setPenguinPosition(getPenguinPositionX() + 1, getPenguinPositionY());
				}
				else if (direction == 2)
				{
					setPenguinPosition(getPenguinPositionX(), getPenguinPositionY()+1);
				}
				else if (direction == 3)
				{
					setPenguinPosition(getPenguinPositionX(), getPenguinPositionY()-1);
				}
		
			}
			displayGame();
		}
		time(&endTime);
		userTime = difftime(endTime, startTime);
		saveUserTime(userTime,nick,Users);
	}
	exportResults();
	start();
}


void Game:: saveUserTime(double userTime, std::string nick, std::vector<std::pair<std::string, double> > & Users)
{
	Users.push_back(std::make_pair(nick, userTime));
}

void Game::exportArea()
{
	time_t now = time(0);
	id=(unsigned long)now;
	gameAreaFile <<now << "\n";
	gameAreaFile << getFishPositionX() << " " << getFishPositionY() <<" "
				 << getPenguinPositionX() << " "<<getPenguinPositionY() << "\n";
	gameAreaFile << gA->getRows() << " " << gA->getColumns() << "\n";
	for (int i = 0; i < gA->getRows(); i++)
	{
		for (int j = 0; j < gA->getColumns(); j++)
		{
			gameAreaFile << gA->getField(i,j);
		}
		gameAreaFile << "\n";
	}
	gameAreaFile << "--------------------\n";
}

void Game::exportResults()
{
	gameResultsFile.close();
	gameResultsFile.open("results.txt", std::ios::out | std::ios::app);
	gameResultsFile <<"Id gry: "<< id << "\n";
	for (size_t t = 0; t < Users.size(); t++)
	{
		gameResultsFile << "	Nick: " << Users[t].first << " czas: " << Users[t].second << " sekund\n";
	}
}


void Game::loadOldGame()
{
	gameAreaFile.close();
	gameAreaFile.open("gameArea.txt", std::ios::in | std::ios::out | std::ios::app);

	try
	{
		resetUsers();
		unsigned long loadID = 0;
		loadID  = readID();
		unsigned long actualID = 0;
		std::string ignore = "";
		int r = 0, c = 0;
		loadArea(loadID, actualID, ignore, r,c);
		gA = new GameArea(r, c);
		for (int i = 0; i < r; i++)
		{
			std::string numbers;
			gameAreaFile >> numbers;
			parser(i,numbers);
		}
		play(usersAmount);
	}
	catch (std::string obj)
	{
		errorHandling(obj);
		loadOldGame();
	}
}

void Game::loadArea(unsigned long &loadID, unsigned long  &actualID, std::string &ignore, int &r, int &c)
{

	gameAreaFile >> actualID;
	bool find = 1;
	while (loadID != actualID)
	{
		gameAreaFile >> ignore;
		gameAreaFile >> ignore;
		gameAreaFile >> ignore;
		gameAreaFile >> ignore;
		gameAreaFile >> r;
		gameAreaFile >> c;
		for (int i = 0; i < r; i++)
		{
			gameAreaFile >> ignore;
		}
		gameAreaFile >> ignore;

		if (gameAreaFile.eof())
		{
			std::string exception;
			exception = "Nie ma planszy o podanym numerze id";
			find = 0;
			throw exception;
			break;
		}
		gameAreaFile >> actualID;

	}
	if (find == 1) {
		id = actualID;

		int fX, fY, pX, pY;
		gameAreaFile >> fX;
		gameAreaFile >> fY;
		gameAreaFile >> pX;
		gameAreaFile >> pY;
		setFishPosition(fX, fY);
		setPenguinPosition(pX, pY);
		setPenguinPositionstart(pX, pY);
		resetUsers();
		usersAmount = countOfUsers();
		gameAreaFile >> r;
		gameAreaFile >> c;
	}
}
void Game::parser(int index, std::string numbers)
{
	for (size_t t = 0; t < numbers.size(); t++)
	{
		if (numbers[t] == '1')
		{
			gA->setField(index, t);
		}
	}
}

void Game::generateArea()
{
	srand(static_cast<unsigned int>(time(NULL)));
	int x = rand() % gA->getRows(), y = gA->getColumns() - 1;

	gA->setField(x, y);
	setPenguinPosition(x,y);
	setPenguinPositionstart(x, y);

	bool success = false;

	do
	{
		int direction = rand() % 3;

		if (direction == 0)
		{
			if (y > 0 && !gA->getField(x, y - 1))
			{
				gA->setField(x, --y);
			}

			if (y == 0)
			{
				success = true;
				setFishPosition(x, y);
			}
		}
		else if (direction == 1)
		{
			if (x - 1 >= 0 && !gA->getField(x - 1, y))
			{
				gA->setField(--x, y);
			}
		}
		else
		{
			if (x + 1 <= gA->getRows() - 1 && !gA->getField(x + 1, y))
			{
				gA->setField(++x, y);
			}
		}
	} while (!success);
}

