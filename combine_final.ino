#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// SIM800L Serial
SoftwareSerial SIM800L(2, 3); // RX, TX

// DS18B20 Temperature Sensor
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// MPU-6050 Accelerometer & Gyroscope
Adafruit_MPU6050 mpu;

// Variables
String incomingMessage = "";
String senderNumber = "";
unsigned long activityDuration = 5000; // 5 seconds for activity monitoring

void setup() {
  Serial.begin(9600);

  // Initialize SIM800L
  Serial.println("Initializing SIM800L...");
  SIM800L.begin(9600);
  delay(1000);

  if (initializeSIM800L()) {
    Serial.println("SIM800L Initialized!");
  } else {
    Serial.println("SIM800L Initialization Failed!");
    while (1); // Stop execution if SIM800L initialization fails
  }

  // Initialize DS18B20
  Serial.println("Initializing DS18B20...");
  sensors.begin();

  // Initialize MPU6050
  Serial.println("Initializing MPU6050...");
  if (!mpu.begin()) {
    Serial.println("MPU6050 initialization failed!");
  } else {
    Serial.println("MPU6050 initialized successfully.");
  }
}

void loop() {
  // Check for incoming SMS
  if (SIM800L.available()) {
    char c = SIM800L.read();
    if (c == '\n') {
      if (incomingMessage.startsWith("+CMT:")) {
        processIncomingSMS(incomingMessage);
      }
      incomingMessage = "";
    } else {
      incomingMessage += c;
    }
  }
}

// Function to initialize SIM800L
bool initializeSIM800L() {
  if (!sendCommand("AT")) return false;             // Test AT command
  if (!sendCommand("AT+CMGF=1")) return false;      // Set SMS mode to text
  if (!sendCommand("AT+CNMI=1,2,0,0,0")) return false; // New message notification
  return true;
}

// Function to process incoming SMS
void processIncomingSMS(String message) {
  Serial.println("New SMS Received!");
  Serial.println("Processing SMS: " + message);

  // Extract sender's number
  int start = message.indexOf("\"") + 1;
  int end = message.indexOf("\"", start);
  senderNumber = message.substring(start, end);
  Serial.println("Sender: " + senderNumber);

  // Collect temperature and activity data
  String temperature = getTemperature();
  String activity = getActivity();

  // Get location
  String latitude = "N/A", longitude = "N/A";
  if (!getLocation(latitude, longitude)) {
    latitude = "Error"; 
    longitude = "Error";
  }

  // Prepare and send the response
  String responseMessage = "Temperature: " + temperature + "°C\n";
  responseMessage += "Activity: " + activity + "\n";
  responseMessage += "Location: Lat: " + latitude + ", Lon: " + longitude;
  sendSMS(senderNumber, responseMessage);
}

// Function to send SMS
void sendSMS(String number, String message) {
  Serial.println("Sending SMS to " + number + ": " + message);
  sendCommand("AT+CMGS=\"" + number + "\"");
  SIM800L.print(message);
  SIM800L.write(26); // CTRL+Z
}

// Function to send AT commands to SIM800L
bool sendCommand(String command) {
  SIM800L.println(command);
  delay(500);
  if (SIM800L.available()) {
    String response = SIM800L.readString();
    Serial.println("Command: " + command);
    Serial.println("Response: " + response);
    return response.indexOf("OK") != -1;
  }
  return false;
}

// Function to get temperature from DS18B20
String getTemperature() {
  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);
  if (tempC == DEVICE_DISCONNECTED_C) {
    return "N/A";
  }
  return String(tempC, 1); // One decimal place
}

// Function to get activity using MPU6050
String getActivity() {
  unsigned long startTime = millis();
  float accelXChange = 0, accelYChange = 0, accelZChange = 0;
  sensors_event_t a, g, temp;
  float lastAccelX = 0, lastAccelY = 0, lastAccelZ = 0;

  while (millis() - startTime < activityDuration) {
    mpu.getEvent(&a, &g, &temp);

    if (lastAccelX != 0) {
      accelXChange += abs(a.acceleration.x - lastAccelX);
      accelYChange += abs(a.acceleration.y - lastAccelY);
      accelZChange += abs(a.acceleration.z - lastAccelZ);
    }

    lastAccelX = a.acceleration.x;
    lastAccelY = a.acceleration.y;
    lastAccelZ = a.acceleration.z;

    delay(10); // Sampling delay
  }

  float totalAccelChange = accelXChange + accelYChange + accelZChange;
  if (totalAccelChange < 60) {
    return "Stationary";
  } else if (totalAccelChange < 70) {
    return "Walking";
  } else {
    return "Running";
  }
}

// Function to retrieve location from SIM800L
bool getLocation(String &latitude, String &longitude) {
  sendCommand("AT+CIPGSMLOC=1,1");
  delay(3000);
  if (SIM800L.available()) {
    String response = SIM800L.readString();
    Serial.println("Location Response: " + response);
    if (response.startsWith("+CIPGSMLOC:")) {
      int latStart = response.indexOf(",") + 1;
      int latEnd = response.indexOf(",", latStart);
      int lonStart = response.indexOf(",", latEnd + 1);
      int lonEnd = response.indexOf(",", lonStart + 1);

      latitude = response.substring(latStart, latEnd);
      longitude = response.substring(lonStart, lonEnd);
      return true;
    }
  }
  return false;
}
