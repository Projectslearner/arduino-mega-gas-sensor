/*
    Project name : GAS Sensor
    Modified Date: 13-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-gas-sensor
*/

const int gasSensorPin = A0;   // Analog pin connected to the gas sensor
const float VCC = 5.0;         // Voltage supplied to the gas sensor (adjust as needed)
const float thresholdPPM = 50.0; // Threshold gas concentration in ppm

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  pinMode(gasSensorPin, INPUT); // Set gas sensor pin as INPUT
}

void loop() {
  // Read the analog voltage from the gas sensor
  int sensorValue = analogRead(gasSensorPin);
  
  // Convert analog value to voltage (0 to VCC)
  float sensorVoltage = (float)sensorValue * VCC / 1023.0;
  
  // Calculate gas concentration in ppm based on calibration curve
  float gasPPM = analogToPPM(sensorVoltage);
  
  // Print sensor data to Serial Monitor
  Serial.print("Sensor Voltage (V): ");
  Serial.println(sensorVoltage, 2);  // Print voltage with 2 decimal places
  Serial.print("Gas Concentration (ppm): ");
  Serial.println(gasPPM, 2);          // Print ppm with 2 decimal places
  
  // Check if gas concentration exceeds threshold
  if (gasPPM > thresholdPPM) {
    Serial.println("Gas Detected!");
    // Add additional actions here, such as activating an alarm or notification
  }
  
  delay(1000);   // Delay for 1 second before next reading
}

// Function to convert analog voltage to ppm (example calibration curve)
float analogToPPM(float voltage) {
  // Example calibration curve for MQ series gas sensors
  float ppm = 0.25 * voltage - 25; // Adjust this formula based on sensor datasheet
  return ppm;
}
