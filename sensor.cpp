#include <wiringPi.h>	//for pin operations

#include <unistd.h> //to use function usleep

#include <chrono>	//for time operations and meassuring

#include <csignal> //for signal handling

//#include "motor.h" //will be added later, interface to control the motors

#include <iostream>
#include <stdio.h>

#define pin 27
#define minDistance 35

void signalHandler(int signum){
	std::cout << "STOP. TOO CLOSE\n";	
	//stopMotor();
}

float getDistance(){
	//start sensor - set signal pin on high for 5 microseconds and set pin on Input afterwards
	pinMode(pin, OUTPUT);
	digitalWrite(pin, 0);	
	usleep(2);
	
	digitalWrite(pin, 1);
	usleep(5);
	digitalWrite(pin, 0);
	
	pinMode(pin, INPUT);
	//end
	
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	while(digitalRead(pin) == 0){
		//std::cout << digitalRead(27) << std::endl;		
		start = std::chrono::high_resolution_clock::now();
	}
	
	std::chrono::time_point<std::chrono::high_resolution_clock> end;
	while(digitalRead(pin) == 1){
		//std::cout << digitalRead(pin) << std::endl;	
		 end = std::chrono::high_resolution_clock::now();
	 }
	
	auto elapsed = end - start;
	
	//duration in microseconds that it took the sensor to send and receive the signal
	long long duration = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
	
	//distance is duration*0.034(cm/us)(speed of sound) /2(there and back)
	float distance = duration * 0.034 / 2;
	
	return distance;
}

int main() {	
	//WiringPi setup
	if(wiringPiSetup() == -1)
		return 1;
		
	//register signal SIGINT and signal handler
	signal(SIGINT, signalHandler);
	
	//endless loop
	while(true){
		float distance = getDistance();
		std::cout << distance << std::endl;
		//if there is an object in front of the robot closer than the minDistance, the signalHandler is called to stop
		if(distance < minDistance){
			raise(SIGINT);
		}
		usleep(2000000);
	}
	
	return 0;
}
