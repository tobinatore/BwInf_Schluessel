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
char Schl�ssel[SIZE_Y][SIZE_X] = { 0 };
int Z�hler;
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


void generiereSchl�ssel()
{

	srand(time(NULL));
	Z�hler++;

	if (Z�hler >= 3)
	{
		Initialisierung();
		Z�hler = 0;
	}

	for (int i = 0; i < SIZE_Y; i++)
	{
		for (int j = 0; j < SIZE_X; j++)
		{
			if (Schl�ssel[i][j] == NULL)
			{
				Schl�ssel[i][j] = Zeichen.front();
				Zeichen.pop();
				Zeichen.push(Schl�ssel[i][j]);
			}

			else if (Schl�ssel[i][j] == 'O' && Zeichen.front() == 'O')
			{
				int Zufallszahl = rand() % 10;

				if (Zufallszahl < 6)
				{
					Schl�ssel[i][j] = '+';
					Zeichen.pop();
					Zeichen.push(Schl�ssel[i][j]);
				}

				else
				{
					Schl�ssel[i][j] = 'O';
					Zeichen.pop();
					Zeichen.push(Schl�ssel[i][j]);
				}
			}

			else if (Schl�ssel[i][j] == '+' && Zeichen.front() == '+')
			{
				int Zufallszahl = rand() % 10;
				if (Zufallszahl < 6)
				{
					Schl�ssel[i][j] = 'O';
					Zeichen.pop();
					Zeichen.push(Schl�ssel[i][j]);
				}

				else
				{
					Schl�ssel[i][j] = '+';
					Zeichen.pop();
					Zeichen.push(Schl�ssel[i][j]);
				}

			}

			else
			{
				Schl�ssel[i][j] = Zeichen.front();
				Zeichen.pop();
				Zeichen.push(Schl�ssel[i][j]);
			}

		}

	}


}

int main()
{
	const unsigned char ue = static_cast<unsigned char>(129);  //�
	int Schl�sselzahl;

	Initialisierung();

	std::cout << "Wie viele Schl"<<ue<<"ssel sollen generiert werden?" << std::endl;
	std::cin >> Schl�sselzahl;
	while (Schl�sselzahl <= 0)
	{
		std::cout << "Bitte eine Zahl gr��er Null eingeben!" << std::endl;
		std::cin >> Schl�sselzahl;
	}
	Schreiben.open("Schl�ssel.txt", std::ios::out | std::ios::trunc);

	for (int i = 0;i < Schl�sselzahl; i++)
	{
		generiereSchl�ssel();
		
		for (int i = 0; i < SIZE_Y; i++)
		{
			for (int j = 0; j < SIZE_X; j++)
			{
				Schreiben << Schl�ssel[i][j];
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


