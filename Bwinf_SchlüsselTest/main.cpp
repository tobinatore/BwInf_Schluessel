#include <iostream>		//Ein-/Ausgabe
#include <queue>		// Queue
#include <time.h>		//time(NULL)
#include <cstdlib>		//system("Pause)
#include <fstream>		//in .txt Datei schreiben


#define Pause system("pause")
#define QUEUE_SIZE 81
#define SIZE_X 5
#define SIZE_Y 5

std::queue<char> Zeichen;
char Schlüssel[SIZE_Y][SIZE_X] = { 0 };
int Zähler;
std::ofstream Schreiben;

void Initialisierung()
{
	srand(time(NULL));
	for (int i = 0; i < QUEUE_SIZE; i++)
	{
		int	Zufallszahl = rand() % 100;

		if (Zufallszahl<50)
		{
			Zeichen.push('+');
		}

		if (Zufallszahl>49)
		{
			Zeichen.push('O');
		}


	}
}


void generiereSchlüssel()
{

	srand(time(NULL));
	Zähler++;

	if (Zähler >= 3)
	{
		Initialisierung();
		Zähler = 0;
	}

	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < SIZE_X; j++)
		{
			if (Schlüssel[i][j] == NULL)
			{
				Schlüssel[i][j] = Zeichen.front();
				Zeichen.pop();
				Zeichen.push(Schlüssel[i][j]);
			}

			else if (Schlüssel[i][j] == 'O' && Zeichen.front() == 'O')
			{
				int Zufallszahl = rand() % 10;

				if (Zufallszahl < 6)
				{
					Schlüssel[i][j] = '+';
					Zeichen.pop();
					Zeichen.push(Schlüssel[i][j]);
				}

				else
				{
					Schlüssel[i][j] = 'O';
					Zeichen.pop();
					Zeichen.push(Schlüssel[i][j]);
				}
			}

			else if (Schlüssel[i][j] == '+' && Zeichen.front() == '+')
			{
				int Zufallszahl = rand() % 10;
				if (Zufallszahl < 6)
				{
					Schlüssel[i][j] = 'O';
					Zeichen.pop();
					Zeichen.push(Schlüssel[i][j]);
				}

				else
				{
					Schlüssel[i][j] = '+';
					Zeichen.pop();
					Zeichen.push(Schlüssel[i][j]);
				}

			}

			else
			{
				Schlüssel[i][j] = Zeichen.front();
				Zeichen.pop();
				Zeichen.push(Schlüssel[i][j]);
			}

		}

	}


}

int main()
{
	const unsigned char ue = static_cast<unsigned char>(129);  //ü
	int Schlüsselzahl;

	Initialisierung();

	std::cout << "Wie viele Schl"<<ue<<"ssel sollen generiert werden?" << std::endl;
	std::cin >> Schlüsselzahl;
	while (Schlüsselzahl <= 0)
	{
		std::cout << "Bitte eine Zahl größer Null eingeben!" << std::endl;
		std::cin >> Schlüsselzahl;
	}
	Schreiben.open("Schlüssel.txt", std::ios::out | std::ios::trunc);

	for (int i = 0;i < Schlüsselzahl; i++)
	{
		generiereSchlüssel();
		
		for (int i = 0; i < SIZE_Y; i++)
		{
			for (int j = 0; j < SIZE_X; j++)
			{
				Schreiben << Schlüssel[i][j];
			}
			Schreiben << std::endl;
		}
		Schreiben << std::endl;
		
	}
	Schreiben.close();
	std::cout << "Die Schl"<<ue<<"ssel wurden in der Datei 'Schl" << ue << "ssel.txt' gespeichert!" << std::endl;
	Pause;
	return 0;

}


