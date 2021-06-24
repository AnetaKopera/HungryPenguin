#include "Gametxt.h"


void Gametxt:: displayMenu()
{
	system("cls");
	std::cout << "MENU\n";
	std::cout << "Nacisnij numer by wybrac opcje\n";
	std::cout << "1 Nowa gra\n";
	std::cout << "2 Zaladuj stara gre\n";
	std::cout << "3 Zasady gry\n";
	std::cout << "4 Wyniki\n";
	std::cout << "5 Wyjscie\n";
 }

char Gametxt::userDecision()
{
	char number = _getch();
	return number;
}
void Gametxt::displayGameRules()
{
	system("cls");
	std::cout << "ZASADY GRY\n";
	std::cout << "Drogi graczu\nPrzed toba gra HungryPenguin - prosta gra konsolowa dla "
		"ciebie i twoich znajomych.\nTwoim zadaniem jest nakramienie pingwina.\n"
		"Czyli doprowadznie go do obiadu, ryby wyswietlanej jako R, przez zawila sciezke.\n"
		"Pamietaj liczy sie czas bo jest on bardzo glodny.\n"
		"Chodz tylko po krach lodowych '*' i omijaj dziury w trasie '-'\n"
		"Podczas gry steruj pingwinem wyswietlanym jako P,"
		" za pomoca klawiszy klawiatury.\n"
		"Klawisze odpowiedzialne za sterowanie:\n"
		"a - lewo\nd - prawo\nw- gora\ns - dol\nq - wyjscie z trybu gry\n"
		"Powodzenia\n"
		"Autor: Aneta Kopera\n";

	std::cout << "\nWcisnij q by wrocic do menu glownego";
	char decision=userDecision();
	if ((decision == 'q')|| (decision=='Q'))
	{
		start();
	}
	else
	{
		displayGameRules();
	}
}

void Gametxt::displayResults()
{
	system("cls");
	std::cout << "WYNIKI\n";
	std::cout << "Id gry: " << id << "\n";
	for (size_t t = 0; t < Users.size(); t++)
	{
		std::cout << "Nick: " << Users[t].first << " czas: " << Users[t].second << " sekund\n";
	}

	std::cout << "\nWcisnij q by wrocic do menu glownego";
	char decision = userDecision();
	if ((decision == 'q') || (decision == 'Q'))
	{
		start();
	}
	else
	{
		displayResults();
	}
}

void Gametxt::displayExit()
{
	system("cls");
	std::cout << "Czy na pewno chcesz wyjsc z gry?\n";
	std::cout << "\nWcisnij t aby wyjsc lub n aby pozostac w grze.\n";
	char decision = userDecision();
	if ((decision == 'n') || (decision == 'N'))
	{
		start();
	}
	else if ((decision == 't') || (decision == 'T'))
	{
		system("cls");
		std::cout << "ZEGNAJ DO ZOBACZENIA WKROTCE\n";
		Sleep(1500);
	}
	else
	{
		displayExit();
	}
}

int Gametxt::countOfUsers()
{
	int usersAmount = 0;
	system("cls");
	std::cout << "Podaj ilosc graczy i zatwierdz wybor przyciskiem enter ";
	std::cin >> usersAmount;
	if (usersAmount <= 0)
	{
		std::string exception;
		exception = "Zla ilosc uzytkownikow";
		throw exception;
	}
	return usersAmount;
}

int Gametxt::rowSize()
{
	int row = 0;
	system("cls");
	std::cout << "Podaj ilosc wierszy dla planszy i zatwierdz wybor przyciskiem enter ";
	std::cin >> row;
	return row;
}

int Gametxt::columnSize()
{
	int column = 0;
	system("cls");
	std::cout << "Podaj ilosc kolumn dla planszy i zatwierdz wybor przyciskiem enter ";
	std::cin >> column;
	return column;
}

void Gametxt::counting()
{
	system("cls");
	for (int time = 5; time > 0; time--)
	{
		std::cout << time;
		Sleep(1000);
		system("cls");
	}
}
void Gametxt::displayGame()
{
	system("cls");

	for (int i = 0; i < gA->getRows(); i++)
	{
		for (int j = 0; j < gA->getColumns(); j++)
		{
			if ((i == getPenguinPositionX()) && ( j == getPenguinPositionY()))
			{
				std::cout << "P";
			}
			else if ((i == getFishPositionX()) && (j == getFishPositionY()))
			{
				std::cout << "R";
			}
			else if (gA->getField(i, j) == 0)
			{
				std::cout << "-";
			}
			else if (gA->getField(i, j) == 1)
			{
				std::cout << "*";
			}
		}
		std::cout << "\n";
	}
	std::cout << "Jesli chcesz wyjsc z gry wcisnij q.";
}

int Gametxt::move()
{
	char direction = userDecision();
	if (direction == 'q' || direction == 'Q')
	{
		return -1;
	}
	else if (direction == 'w' || direction == 'W')
	{
		return 0;
	}
	else if (direction == 's' || direction == 'S')
	{
		return 1;
	}
	else if (direction == 'd' || direction == 'D')
	{
		return 2;
	}
	else if (direction == 'a' || direction == 'A')
	{
		return 3;
	}
	else
	{
		return 4;
	}
}

std::string Gametxt::readNick()
{
	std::string nick;
	system("cls");
	std::cout << "Podaj swoj nick i zatwierdz przyciskiem enter: ";
	std::cin >> nick;
	return nick;
}

void Gametxt:: errorHandling(std::string error)
{
	system("cls");
	std::cout << error;
	Sleep(2000);
}

unsigned long Gametxt::readID()
{
	system("cls");
	std::cout << "Podaj nr ID i zatwierdz przyciskiem enter: ";
	unsigned long  number;
	std::cin >> number;
	return number;
}