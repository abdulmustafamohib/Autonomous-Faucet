#include "PC_FileIO.c"

// Function to retrieve preferred temperature from a file
float getPreferredTemp() {

	TFileHandle fin;
	int defaultTemp = 25;  // Default temperature if the file is not found
	float temperature;

	// Open the file in read mode
	bool fileOkay = openReadPC(fin,"temp.txt");

	// If the file exists, read the temperature, else use default
	if (fileOkay) {
		readFloatPC(fin, temperature);
		closeFilePC(fin);
		return temperature;
	}
	else {
		displayTextLine(1, "File could not be opened");
	}

	//close file and return default temp if file could not be opened
	closeFilePC(fin);
	return defaultTemp;
}

// Function to save preferred temperature to a file
void savePreferredTemp(long temp) {

	TFileHandle fout;

	// Open the file in write mode
	bool fileOkay = openWritePC(fout, "temp.txt");

	if(fileOkay) {
		writeLongPC(fout, temp);
	}
	else {
		displayTextLine(1, "File could not be saved");
	}

	//close file
	closeFilePC(fout);
}
