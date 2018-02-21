#include "max6675.h"


//Control

int C_time = 1000;

double Setpoint, U, Y, Error;

double K_p=10;

unsigned long T_1 = 0;
unsigned long T_2;


//Sensor De Temperatura

const int pin_SO = 4;
const int pin_CS = 5;
const int pin_SCK = 6;

MAX6675 Termocupla(pin_SCK, pin_CS, pin_SO);

double Temperatura;

//Pines salidas a Reles

const int FAN = 10;
const int RES = 9;

void setup(){	

	//Control PID

	Setpoint=105;

	//Comunicacion Serial

	Serial.begin(9600);

	//Reles

	pinMode(FAN, OUTPUT);
	pinMode(RES, OUTPUT);

	delay(500);

	digitalWrite(FAN, HIGH);

}

void loop(){
	
	T_2 = millis();

	if(T_2 - T_1 >= C_time)
	{
		Temperatura = (double)Termocupla.readCelsius();

		Error = Setpoint - Temperatura;

		U = K_p * Error;

		T_1 = T_2;

		Serial.print("Temperatura : ");
		Serial.println(Temperatura);
	}


	if(U > 0){
		digitalWrite(RES, HIGH);
	}
	if(U < 0){
		digitalWrite(RES, LOW);
	}
}

