//returns distance of hand from ultrasonic sensor
int getHandDistance() {
	return SensorValue[S2];
}

//int function getWaterTemperature;
	//returns a temperature respective to where the last hand distance was
int getWaterTemperature() {

	//get hand distance
	int distance = getHandDistance();
	int defaultTemp = 50;

	//check to see how far the hand was and return appropriate value
	if (distance < 10) {
		return 0;
	}
	else if (distance > 10 && distance < 20) {
		return 50;
	}
	else if (distance > 20 && distance < 40) {
		return 100;
	}
	return defaultTemp;
}
