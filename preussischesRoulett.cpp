//============================================================================
// Name        :preussischesRoulett.cpp
// Author      : mr
//============================================================================
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>
#define MAX_MAGAZIN 20
#define GAMER 1
#define PC 2
using namespace std;

//
int dice(int iMin, int iMax){
    double range = iMax - iMin + 1;
    return rand() % (int) range + iMin;
};


//
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
	//
	Revolver::Revolver(int bullets, int chambers)
	{
		bulletCount=bullets;
        chamberCount=chambers;
		bulletPos = 1;
		activePlayer = 0;
		// ?
		chamberPos = dice(1, chamberCount);
    };
	//
	Revolver::~Revolver(){
        cout << "Waffe vernichtet mit " << bulletCount <<" Kugel(n). " <<endl;
	};

    //
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
			cout << "Glueck gehabt\n";
			chamberPos++;
			chamberPos=chamberPos%chamberCount;
		}
		return false;
	};
    //
	void Revolver::Spin()	{
		if( activePlayer == GAMER )
			cout << "Gamer dreht Trommel\n";
		else
			cout << "PC dreht Trommel\n";
		chamberPos = dice(1, chamberCount);
	};

    void Revolver::SetActivePlayer(int nextPlayer) {
		activePlayer = nextPlayer;
	};

	// ?
class ReichsRevolver : public Revolver {
protected:

private:
    int bulletPos[MAX_MAGAZIN];

public:
    ReichsRevolver(int bullets, int chambers):Revolver(bullets, chambers)
	{
		bulletCount=bullets;
        chamberCount=chambers;
        int i, chamberI;
        bool bulletPlaced;
        for (i=0; i< MAX_MAGAZIN; i++)
            bulletPos[i]=0;
        chamberI=0;
        for (i=1; i<= bulletCount; i++){
            bulletPlaced=false;
             while (bulletPlaced!= true){
                    //Sleep(1000);
                	//srand( (unsigned)time( NULL ) );
                    chamberI=dice(1, chamberCount);
                    if(bulletPos[chamberI]==0){
                        bulletPos[chamberI]=1;
                        bulletPlaced=true;
                    }
                    else{
                        chamberI=dice(1, chamberCount);
                    }
            }
            bulletPos[chamberI]=1;
        }
		activePlayer = 0;
		// ?
		chamberPos = dice(1, chamberCount);
    };

    bool Shoot(){
        if( activePlayer == GAMER )
            cout << "Gamer schiesst\n";
        else
            cout << "PC schiesst\n";
		// ?
         if( bulletPos [chamberPos]==1){
                bulletCount--;
                cout << "erschossen\n";
                return true;
            }
				//
        cout << "Glueck gehabt\n";
        chamberPos++;
        chamberPos=chamberPos%chamberCount +1;
        return false;
	};
};




int main()
{
    system ("COLOR 0F");
	srand( (unsigned)time( NULL ) );
    int bullets, chambers;
    char c;
	bool bExit = false,
        bQuit = false;
	int myPlayer, deadPlayer;

    // Instanz gamerRevolver bilden und konfigurieren
    myPlayer = GAMER,
    bullets =1; chambers=6;
	Revolver gamerRevolver(bullets, chambers);
	gamerRevolver.SetActivePlayer(myPlayer);
    // Instanz pcRevolver bilden und konfigurieren
    myPlayer = PC;
    bullets =2; chambers=6;
    ReichsRevolver pcRevolver(bullets, chambers);
	pcRevolver.SetActivePlayer(myPlayer);

    // Spielschleife
    do
    {
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
                gamerRevolver.Spin();
                if(gamerRevolver.Shoot()) {
                    deadPlayer = GAMER;
                    bExit = true;
                    }
                break;
            }
            default: {
                if(gamerRevolver.Shoot()) 					{
                    deadPlayer = GAMER;
                    bExit = true;
                }
                break;
            }

        }
        // PC ist dran
        cout << "\n*** PC ist an der Reihe!\n";
        pcRevolver.Spin();
        if(pcRevolver.Shoot()) {
            deadPlayer = PC;
            bExit = true;
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

