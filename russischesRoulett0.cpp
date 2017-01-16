#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
using namespace std;

int RandomInt(int iMin, int iMax)
{
	return iMin + int((float)(iMax+1) * rand()/(RAND_MAX+1.0));
};

enum player{user, pc};

class Gun
{
public:
	Gun()
	{
		m_BulletPos = 1;
		m_Player = NULL;
		// Am Anfang ist die Position zufällig!
		m_Pos = RandomInt(1, 6);
    };
	~Gun(){};

	void Spin()
	{
		if( *m_Player == user )
			cout << "Mensch dreht Trommel\n";
		else
			cout << "PC dreht Trommel\n";
		m_Pos = RandomInt(1, 6);
	};

	bool Shoot()
	{
		if( *m_Player == user )
			cout << "Mensch schiesst\n";
		else
			cout << "PC schiesst\n";

		// Schießen, wenn die Patrone im Lauf liegt
		if( m_Pos == m_BulletPos)
			return true;
		// Ansonsten die Trommel eins weiter drehen
		else
		{
			m_Pos++;
			if( m_Pos > 6 )
				m_Pos = 1;

		}

		return false;
	};


	void SetActivePlayer(player *newPlayer)
	{
		m_Player = newPlayer;
	};

protected:
	int m_Pos,
		m_BulletPos,
		m_NoShootCount;
	player *m_Player;
};


int main()
{
	// seed setzen
	srand( (unsigned)time( NULL ) );

        char c;
	bool bExit = false,
		bNoEnd = false;
	player myPlayer = user,
			deadPlayer;
	Gun myGun;
	myGun.SetActivePlayer(&myPlayer);

	do
	{
		// Spieler bestimmen
		if( myPlayer == user )
		{
			cout << "Mesch ist an der Reihe!\n'q' beendet, 's' dreht die Trommel und schiesst, alle anderen Eingaben schiessen sofort\n>";
			cin >> c;
			switch(c)
			{
			case 'q':
				{
					bExit = true;
					bNoEnd = true;
					break;
				}
			case 's':
				{
					myGun.Spin();
					if(myGun.Shoot())
					{
						deadPlayer = user;
						bExit = true;
					}
					break;
				}
			default:
				{
					if(myGun.Shoot())
					{
						deadPlayer = user;
						bExit = true;
					}
					break;
				}
			}

			//Spieler wechseln!
			myPlayer = pc;
		}
		//** COMPUTER
		else
		{

            myGun.Spin();
			if(myGun.Shoot())
			{
				deadPlayer = pc;
				bExit = true;
			}
			//Spieler wechseln!
			myPlayer = user;
		}

	}while(!bExit);

	if(bNoEnd)
		cout << "Mensch gibt auf\n";
	else
	{
		if( deadPlayer == user)
			cout << "mensch ist tot\n";
		else
			cout << "PC ist tot\n";
	}
}
