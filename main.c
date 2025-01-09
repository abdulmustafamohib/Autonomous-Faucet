#include "temperature.c"
#include "faucet.c"
#include "soapDispenser.c"
#include "file.c"

//void function; configures all sensors
void configureSensors() {
	SensorType[S1] = sensorEV3_Ultrasonic;
	wait1Msec(50);
	SensorType[S2] = sensorEV3_Ultrasonic;
	wait1Msec(50);
	SensorType[S3] = sensorEV3_IRSensor;
	wait1Msec(50);
	SensorType[S4] = sensorEV3_Touch;

}

//main thread of operation
task main()
{

	//configure the sensors and initalize display on EV3
	configureSensors();
	int temperature = 50;
	intitializeDisplay();

	clearTimer(T3);
	long timePassed = 0;

	//keep polling for inputs while the E-stop isn't pressed
		//and the inactivity time between inputs hasn't exceeded 20 seconds
	while (SensorValue[S4] != 1 && timePassed < 20) {

		//timer used to track time between inputs
		timePassed = time1[T3]/1000;

		//change temperature
		if (SensorValue[S2] < 40) {
			temperature = getWaterTemperature();
			displayTemperatureBar(temperature);
			clearTimer(T3);
		}

		//turn on handles
		if (SensorValue[S1] < 20) {
			turnOnFaucetHandles(temperature);
			clearTimer(T3);
		}

		//dispense soap
		if (SensorValue[S3] < 15) {
			dispenseSoap();
			clearTimer(T3);
		}

		//save temp to file
		if (getButtonPress(buttonRight)) {
			savePreferredTemp(temperature);
			clearTimer(T3);
		}

		//load temp from file
		if(getButtonPress(buttonLeft)) {
			temperature = getPreferredTemp();
			displayTemperatureBar(temperature);
			clearTimer(T3);
		}
	}

}
