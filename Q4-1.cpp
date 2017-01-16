//============================================================================
// Name        : auto.cpp
// Author      : mr
//============================================================================

using namespace std;
#include <iostream>
#include <cstring>
#define LEN 12

class Car {			//Klasse Car
private:			//private Eigenschaften/Variablen der Klasse Car
char oName[LEN];
char manu[LEN];
	char model[LEN];
	int year;
	int mileage;

public:			// Öffentliche Methoden der Klasse Car
	Car (const char* ma, const char* name);
	Car ();
	~Car ();

void accelerate(int kmh);
void brake(int kmh);
int get_yearOfProd(void);
void set_yearOfProd(int year1);
int get_mileage(void);
void set_mileage(int mile);
};

// ?:Setzt die an Car(char ma, char name) übergebenen Variablen
// in die Variablen der Klasse ein
Car::Car(const char* ma, const char * name){
    	memset(manu, 0, sizeof(manu));
        strncpy(manu, ma, sizeof(manu)-1);
    	memset(oName, 0, sizeof(oName));
    	strncpy(oName, name, sizeof(oName)-1);
    	memset(model, 0, sizeof(model));
        strncpy(model, "1", sizeof(model)-1);
        mileage=150000;
		year=2014;
}

//?:Setzt die Variablen für die mit Methode Car() abgeleiteten Klassen
Car::Car(){
    	memset(manu, 0, sizeof(manu));
	strncpy(manu, "Hersteller", sizeof(manu)-1);
    	memset(oName, 0, sizeof(oName));
    	strncpy(oName, "Objektname", sizeof(oName)-1);
    	memset(model, 0, sizeof(model));
	model[sizeof(model)]='\0';
	mileage=100000;
	year=2015;
}

// ?:Implementierung der öffentlichen Methoden der Klasse Car
Car::~Car(){
	cout << manu << " " << model  << " " << oName <<  " wurde abgewrackt." << endl;
}

void Car::accelerate(int kmh) {
	cout << manu <<" " << model << " " << oName<< " beschleunigt auf " << kmh << " km/h!"<< endl;
}

void Car::brake(int kmh) {
	cout << manu << " " << model << " " << oName<< " bremst ab auf " << kmh << " km/h!" << endl;
}

int Car::get_yearOfProd(void){
    return year;
}

void Car::set_yearOfProd(int year1){
    year = year1;
}

int Car::get_mileage(void){
    return mileage;
}

void Car::set_mileage(int mile){
    mileage = mile;
}

int main() {
    int year1;
	Car yourcar;				// ?
	Car mycar("Porsche", "mycar");	// ?
	Car momsCar(mycar);
	Car dadsCar(mycar);
	mycar.accelerate(100);		// ?
	yourcar.accelerate(200);
	mycar.brake(50);
	year1=mycar.get_yearOfProd();
	cout << "Herstellungsjahr mycar: " << year1 << endl;
	mycar.set_yearOfProd(2001);
	year1=mycar.get_yearOfProd();
	cout << "Herstellungsjahr mycar: " << year1 << endl;
	return 0;				// ?
}
