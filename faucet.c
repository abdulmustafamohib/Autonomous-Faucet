#include "display.c"

//checks to see if hands are still in ultrasonic FOV within the given distance range
bool handsDetected() {
	return SensorValue[S1] < 20;
}

//sets power to motors depending on temperature; takes in both hot and cold motor power since
//	we planned on making motor functions more complex but did not have the time to
void setMotorPower(int temp, int &hotMotorPower, int &coldMotorPower) {

	if (temp == 0) {
		hotMotorPower = 0;
		coldMotorPower = 35;

	}

	else if (temp == 100) {
		hotMotorPower = 35;
		coldMotorPower = 0;

	}

	else if (temp == 50) {
		hotMotorPower = 30;
		coldMotorPower = 30;
	}

}

//sets maximum encoder tick count depending on temperature; takes in both hot and cold motor encoder counts since
//	we planned on making encoder functions more complex but did not have the time to
void setMotorEncoderTicks(int temp, int &motorDegreesHot, int &motorDegreesCold) {

	if (temp == 0) {
		motorDegreesHot = 0;
		motorDegreesCold = 140;
	}

	else if (temp == 100) {
		motorDegreesCold = 0;
		motorDegreesHot = 140;
	}

	else if (temp == 50) {
		motorDegreesHot = 100;
		motorDegreesCold = 100;
	}

}


//function that controls the faucet handles
void turnOnFaucetHandles(int temp) {

	int motorDegreesHot = 0;
	int motorDegreesCold = 0;
	int hotMotorPower = 0;
	int coldMotorPower = 0;

	//set max encoder count and motor powers
	setMotorEncoderTicks(temp, motorDegreesHot, motorDegreesCold);
	setMotorPower(temp, hotMotorPower, coldMotorPower);

	nMotorEncoder[motorA] = 0;
	nMotorEncoder[motorD] = 0;

	motor[motorA] = hotMotorPower;
	motor[motorD] = coldMotorPower;


	// Rotate motors to specific degrees
	while ((abs(nMotorEncoder[motorA]) < motorDegreesHot || abs(nMotorEncoder[motorD]) < motorDegreesCold)) {
		if (SensorValue[S4] == 1) {
			break;
		}
	}

	motor[motorA] = 0;
	motor[motorD] = 0;

	float timePassed = 0;
	float timePassed2 = 0;
	clearTimer(T1);
	clearTimer(T2);

	//checks to see if hands are in frame or hands are not in frame but timer is less than 2 seconds
	while((handsDetected() || timePassed2 < 2)) {

		//E-stop condition
		if (SensorValue[S4] == 1) {
			break;
		}

		//timer for timer bar on EV3
		timePassed = time1[T1]/1000;
		displayTimerBar(timePassed);

		//timer to check if 2 seconds have passed by or not
		timePassed2 = time1[T2]/1000;
		//timePassed2 = timePassed

		//reset timer everytime hands come into view
		if(handsDetected()) {
			clearTimer(T2);
		}
	}

	//reset timer bar
	eraseRect(80, 100, 120, 0);

	//set each motor to the other motor's initial power and make it negative
	motor[motorA] = -1 * hotMotorPower;
	motor[motorD] = -1 * coldMotorPower;
	wait1Msec(1100);

	//turn off motors after 1.1 seconds
	motor[motorA] = 0;
	motor[motorD] = 0;

	wait1Msec(500);

}
