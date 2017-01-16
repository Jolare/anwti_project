//============================================================================
// Name        : auto.cpp
// Author      : mr
//============================================================================

using namespace std;
#include <iostream>
#include <cstring>
#define LEN 12

class Car {			//?
private:			//?
char oName[LEN];
char manu[LEN];
char model[LEN];
int year;
int mileage;

public:			// ?
	Car (const char* ma, const char* name, int mil);
	Car ();
	~Car ();

void accelerate(int kmh);
void brake(int kmh);
int get_yearOfProd( void );
void set_yearOfProd(int year);

};

// ?:
Car::Car(const char* ma, const char * name, int mil){
    memset(manu, 0, sizeof(manu));
	strncpy(manu, ma, sizeof(manu)-1);
    memset(oName, 0, sizeof(oName));
    strncpy(oName, name, sizeof(oName)-1);
    memset(model, 0, sizeof(model));
	strncpy(model, "1", sizeof(model)-1);
	year=2014;
	mileage=mil;
}

//?:
Car::Car(){
    memset(manu, 0, sizeof(manu));
	strncpy(manu, "Hersteller", sizeof(manu)-1);
    memset(oName, 0, sizeof(oName));
    strncpy(oName, "Objektname", sizeof(oName)-1);
    memset(model, 0, sizeof(model));
	model[sizeof(model)]='\0';
	year=2015;
	mileage=10000;
}

// ?:
Car::~Car(){
	cout << manu << " " << model  << " " << oName <<  " wurde abgewrackt." << endl;
}

void Car::accelerate(int kmh) {
	cout << manu <<" " << model << " " << oName<< " beschleunigt auf " << kmh << " km/h!"
	<<  " und das bei km-Stand " << mileage<< endl;
}

void Car::brake(int kmh) {
	cout << manu << " " << model << " " << oName<< " bremst ab auf " << kmh << " km/h!"
	<<  " und das bei km-Stand " << mileage << endl;
}

int Car::get_yearOfProd( void ){
	return year;
}

void Car::set_yearOfProd(int yearX){
	year = yearX;
}


int main() {
    int year;
	Car yourcar;				// ?
	Car mycar("Porsche", "mycar", 1);	// ?
	mycar.accelerate(100);		// ?
	yourcar.accelerate(200);
	mycar.brake(50);
    mycar.brake(80);
	Car dads_car(mycar);
	Car moms_car(mycar);
	moms_car.accelerate(220);
	moms_car.brake(180);
	year=mycar.get_yearOfProd();
	cout << "Herstelljahr mycar " << year	 << endl;
	mycar.set_yearOfProd(1999);
    year=mycar.get_yearOfProd();
	cout << "Herstelljahr mycar " << year	 << endl;
	return 0;				// ?
}
