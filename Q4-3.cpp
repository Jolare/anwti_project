//============================================================================
// Name        : russischesRoulett.cpp
// Author      : mr
//============================================================================
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#define GAMER 1
#define PC 2
using namespace std;


// ?
int dice(int iMin, int iMax){
    double range = iMax - iMin + 1;
    return rand() % (int) range + iMin;
};


// ?
class Revolver {
protected:
    int chamberPos,	bulletPos;
    int activePlayer;
    int bulletCount;
    int chamberCount;
public:
    Revolver(int bullets, int chambers);
    ~Revolver();
    void Spin();
    bool Shoot();
    void SetActivePlayer(int nextPlayer);
private:

};
	// ?
	Revolver::Revolver(int bullets, int chambers)
	{
		bulletCount=bullets;
        chamberCount=chambers;
		bulletPos = 1;
		activePlayer = 0;
		// ?
		chamberPos = dice(1,6);
    };
	// ?
	Revolver::~Revolver(){
        cout << "Waffe vernichtet mit " << bulletCount <<" Kugel(n). " <<endl;
	};
    //?
	void Revolver::Spin()	{
		if( activePlayer == GAMER )
			cout << "Gamer dreht Trommel\n";
		else
			cout << "PC dreht Trommel\n";
            chamberPos = dice(1,6);
	};
    // ?
	bool Revolver::Shoot(){
		if( activePlayer == GAMER )
			cout << "Gamer schiesst\n";
		else
			cout << "PC schiesst\n";
		// ?
		if( chamberPos == bulletPos){
            bulletCount--;
            cout << "erschossen\n";
            return true;
		}
		// ?
		else {
			chamberPos++;
			chamberPos=chamberPos%chamberCount+1;
            cout << "Glueck gehabt\n";
		}
		return false;
	};
    // ?
	void Revolver::SetActivePlayer(int nextPlayer) {
		activePlayer = nextPlayer;
	};




int main()
{
	// ?
	srand( (unsigned)time( NULL ) );
    int bullets, chambers;

    char c;
	bool bExit = false,
		bQuit = false;
    int myPlayer, deadPlayer;

    myPlayer = GAMER;
    bullets =1; chambers=6;
    // ?
	Revolver myRevolver(bullets, chambers);
	myRevolver.SetActivePlayer(myPlayer);

	do  // ?
	{
		if( myPlayer == GAMER ) {
            // Gamer ist dran
			cout << "\n*** Gamer ist an der Reihe!\n'q' beendet \n's' dreht die Trommel und schiesst \nalle anderen Eingaben schiessen sofort\n";
			cin >> c;
			switch(c)
			{
			case 'q': {
					bExit = true;
					bQuit = true;
					break;
            }
			case 's': {
					myRevolver.Spin();
					if(myRevolver.Shoot()) {
						deadPlayer = GAMER;
						bExit = true;
					}
					break;
            }
			default: {
					if(myRevolver.Shoot()) 					{
						deadPlayer = GAMER;
						bExit = true;
					}
					break;
            }
        }

			// ?
        myPlayer = PC;
        myRevolver.SetActivePlayer(myPlayer);
		}
		// PC ist dran
		else 	{
            cout << "\n*** PC ist an der Reihe!\n";
            myRevolver.Spin();
			if(myRevolver.Shoot()) {
				deadPlayer = PC;
				bExit = true;
			}
			//Spieler wechseln!
			myPlayer = GAMER;
			myRevolver.SetActivePlayer(myPlayer);
		}

	}while(!bExit);

	if(bQuit)
		cout << "Gamer gibt auf\n";
	else 	{
		if( deadPlayer == GAMER)
			cout << "Gamer ist tot\n";
		else
			cout << "PC ist tot\n";
	}
	return 0;
}
