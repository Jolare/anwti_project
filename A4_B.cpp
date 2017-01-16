//============================================================================
// Name        : a4_B.cpp
// Author      : mr
//============================================================================

#include <iostream>
#include <cstring>
#define LEN 12

using namespace std;

class Car {
private:
	char manufacturer[LEN];
	char model[LEN];
	int yearOfProd;
	int milage;

public:
	Car (const char* ma, int mil);
	Car ();
	~Car ();

void accelerate(int kmh);
	void brake(int kmh);
};

Car::Car(const char* ma, int mil){
    memset(manufacturer, 0, sizeof(manufacturer));
	strncpy(manufacturer, ma, sizeof(manufacturer)-1);
    memset(model, 0, sizeof(model));
	strncpy(model, "1", sizeof(model)-1);
	yearOfProd=2014;
	milage=mil;
}

//?:
Car::Car(){
    memset(manufacturer, 0, sizeof(manufacturer));
	strncpy(manufacturer, "Hersteller", sizeof(manufacturer)-1);
    memset(model, 0, sizeof(model));
	model[sizeof(model)]='\0';
	yearOfProd=2015;
	milage=10000;
}

Car::~Car(){
	cout << model << " wurde abgewrackt." << endl;
}

void Car::accelerate(int kmh) {
	cout << manufacturer << " " << model << " beschleunigt auf " << kmh << " km/h!" <<  " und das bei km-Stand " << milage <<endl;
}

void Car::brake(int kmh) {
	cout << manufacturer << " " << model << " bremst ab auf " << kmh << " km/h!" <<  " und das bei km-Stand " << milage <<endl;
}

class Jeep : public Car{
private:
	bool fourwheeldrive;

public:

	bool get_fourwheel( void );
	void set_fourwheel(bool drive);
};


bool Jeep::get_fourwheel( void ){
	return fourwheeldrive;
}

void Jeep::set_fourwheel(bool drive){
	fourwheeldrive = drive;
}

class PowerJeep : public Jeep{
private:
	bool winch;

public:

	bool get_winch( void );
	void set_winch(bool ext_winch);
};


bool PowerJeep::get_winch( void ){
	return winch;
}

void PowerJeep::set_winch(bool ext_winch){
	winch = ext_winch;
}


int main() {
	Car mycar("autole", 1000);
	//Car default_car;
	mycar.accelerate(100);
	mycar.brake(80);
	Car dads_car(mycar);
	Car moms_car(mycar);
	moms_car.accelerate(200);
	moms_car.brake(180);

	Jeep myJeep;
	myJeep.accelerate(300);
	myJeep.set_fourwheel(true);
	if(myJeep.get_fourwheel()){
		cout << "Allrad ist eingeschaltet" << endl;}

	PowerJeep myPowerJeep;
	myPowerJeep.set_winch(true);
		if(myPowerJeep.get_winch()){
			cout << "Seilwinde ist eingeschaltet" << endl;}

	return 0;
}


