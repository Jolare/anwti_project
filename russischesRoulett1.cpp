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
	Gun(int bullets, int chambers)
	{
		bulletCount=bullets;
        chamberCount=chambers;
		m_BulletPos = 1;
		m_Player = NULL;
		// Am Anfang ist die Position zufällig!
		m_Pos = RandomInt(1, chamberCount);
    };
	~Gun(){};

	void Spin()
	{
		if( *m_Player == user )
			cout << "Mensch dreht Trommel\n";
		else
			cout << "PC dreht Trommel\n";
		m_Pos = RandomInt(1, chamberCount);
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
			m_Pos=m_Pos%chamberCount;

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
public:
	int bulletCount;
    int chamberCount;
};


int main()
{
	// seed setzen
	srand( (unsigned)time( NULL ) );
    int bullets;
    char c;
	bool bExit = false,
		bNoEnd = false;
	player myPlayer = user,
			deadPlayer;
	Gun myGun(1,2);
	myGun.SetActivePlayer(&myPlayer);

	do
	{
		// Spieler bestimmen
		if( myPlayer == user )
		{
			cout << "\n*** Mensch ist an der Reihe!\n'q' beendet \n's' dreht die Trommel und schiesst \nalle anderen Eingaben schiessen sofort\n";
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
            cout << "\n*** PC ist an der Reihe!\n";
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
			cout << "Mensch ist tot\n";
		else
			cout << "PC ist tot\n";
	}
}
