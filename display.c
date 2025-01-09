//draw temperature bar on EV3 screen depending on temperature of water
void displayTemperatureBar(int temperature) {

	//use the temperature passed in parameters to draw associated rectangle
	if(temperature == 0)
	{
		eraseRect(10,100,50,0);
		fillRect(10,35,50,0);
	}

	else if  (temperature == 50) {
		eraseRect(10,100,50,10);
		fillRect(10,65,50,0);
	}

	else if (temperature ==100) {
		eraseRect(10,100,50,10);
		fillRect(10,100,50,0);
	}

}

//draw timer bar on EV3 screen depending on how much time has passed while washing hands
void displayTimerBar(float timePassed) {

	eraseRect(80, 100, 120, 0);
	fillRect(80, timePassed * 3, 120, 0);

}

//make initial display for EV3 upon startup with both bars
void intitializeDisplay() {

	//TEMP BAR
	fillRect(10,65,50,0);
	displayStringAt(0,110, "Temperature");
	displayStringAt(55,90, "HOT");
	displayStringAt(55,10, "COLD");


	//TIMER BAR
	drawRect(80, 100, 120, 0);
	displayStringAt(90,110, "Time");
	displayStringAt(125,10, "0s");
	displayStringAt(125,50, "15s");
	displayStringAt(125,90, "30s");


}
