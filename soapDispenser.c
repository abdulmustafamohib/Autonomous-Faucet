//void function dispenseSoap; used to dispense soap
void dispenseSoap() {

	wait1Msec(1500);

	//reset encoders
	nMotorEncoder[motorB] = nMotorEncoder[motorC] = 0;

	//give power to motors to move down
	motor[motorB] = 20;
	motor[motorC] = 20;

	//keep moving down specified encoder count
	while ((abs(nMotorEncoder[motorB]) < 150|| abs(nMotorEncoder[motorC]) < 150) && SensorValue[S4] != 1) {
		if (SensorValue[S4] == 1) {
			break;
		}
	}

	//stop motors and reset encoders; wait 2 seconds
	motor[motorB] = motor[motorC] =0;
	nMotorEncoder[motorB] = nMotorEncoder[motorC] = 0;
	wait1Msec(2000);

	//give power to motors to go back up
	motor[motorB] = motor[motorC] = -20;

	//go back up same encoder count
	while ((abs(nMotorEncoder[motorB]) < 150 || abs(nMotorEncoder[motorC]) < 150) && SensorValue[S4] != 1) {
		if (SensorValue[S4] == 1) {
			break;
		}
	}

	//stop motors
	motor[motorB] = motor[motorC] = 0;

	wait1Msec(2000);

}
