#include <SD.h>

File myfile;
const int sensorPin = A0; // Pin A0 to read analog input
const int chipSelect = 4; 
const int output_pin = 10; 
const int min_reading = 0;
const int max_reading = 600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.print("Initializing card...");
  
  // declare default CS pin as OUTPUT
   pinMode(output_pin, OUTPUT);
   digitalWrite(output_pin, HIGH);
   
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("initialization of the SD card failed");
    return;
  }
  Serial.println("initialization of the SDcard is done.");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //int pressure_reading = analogRead(sensorPin); // Read in from sensor.
 
  myfile = SD.open("textFile.txt", FILE_WRITE);
  
  if (myfile) // If the file was opened
  {
    // This is the part where the pressure reading is mapped to a percentage scale.
    int pressure_reading_readable = map(pressure_reading, min_reading, max_reading, 0, 100);
    
    Serial.print("Writing to SD card");
    
    myfile.print(pressure_reading_readable);
    myfile.close(); // close the file:
    
    Serial.println("Done closing.");
  } 
  else // The file wasn't opened
  {
    // if the file didn't open, report an error:
    Serial.println("error opening the text file.");
  }
  
}
