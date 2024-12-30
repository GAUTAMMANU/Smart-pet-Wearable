# Smart Pet Wearable

## Problem Statement
In today's world, pet owners often face difficulties in monitoring the health and well-being of their pets, especially when they are not at home. This can include concerns such as tracking the pet's physical activity, temperature, and location. Existing pet wearables may not provide an integrated solution for all these needs, or they may be costly.

## Importance of the Problem
Pets are important members of many families, and their health and safety should be a priority. With a wearable device, pet owners can gain real-time insights into their pets' health metrics (such as temperature) and physical activity (such as walking or running), which can help prevent health issues or provide immediate assistance in case of an emergency. Moreover, by being able to track a pet's location, owners can ensure that their pets are safe and locate them in case they wander off.

## The Solution
The **Smart Pet Wearable** is a device designed to monitor pets' temperature, activity, and location. It uses sensors and GSM communication to send real-time data to the owner's phone via SMS. The device is designed to be lightweight, portable, and easy to use, providing pet owners with critical information regarding their pets' health and whereabouts.

### Use Cases
1. **Health Monitoring**: The device tracks the temperature of the pet to detect fever or hypothermia.
2. **Activity Monitoring**: It detects the physical activity of the pet (stationary, walking, or running), helping to monitor its activity level and overall fitness.
3. **Location Tracking**: The GPS feature allows the owner to locate the pet if it gets lost or wanders away.
4. **Emergency Alerts**: The device can send an alert if a pet’s temperature or activity level is abnormal.

## Components Used and Why

### 1. **Arduino Nano**
   - **Reason**: Arduino Nano is a small, versatile microcontroller that is perfect for compact projects. It is powerful enough to handle the input and output operations for the sensors, GPS module, and GSM module while being energy-efficient for portable applications.

### 2. **MPU-6050 (Accelerometer & Gyroscope)**
   - **Reason**: This sensor is used to detect the pet's movement and activity. It helps in determining whether the pet is stationary, walking, or running by measuring the accelerations along different axes.

### 3. **SIM800L GSM Module**
   - **Reason**: The SIM800L is used for sending SMS messages with the pet’s health data (temperature, activity level, location). This allows the owner to receive real-time updates on their pet’s condition via text messages.

### 4. **DS18B20 Temperature Sensor**
   - **Reason**: This sensor is used to monitor the pet’s body temperature. By checking the temperature, the device can provide insights into the pet's health status, such as detecting fever or abnormal body temperature.

### 5. **NEO-6M GPS Module**
   - **Reason**: This GPS module is used to track the pet's location in real-time. It provides accurate latitude and longitude data, which can be sent to the owner via SMS in case the pet is lost or strays.

### 6. **1000µF Capacitor**
   - **Reason**: The 1000µF capacitor is used to stabilize the power supply for the **SIM800L GSM module**, which can sometimes cause power fluctuations due to its high current draw during operation.

### 7. **3.7V 2.2A Li-ion Battery**
   - **Reason**: This battery is used to power the **SIM800L GSM module**, ensuring it has sufficient power for sending messages, especially during high current draws.

## Circuit Diagram

Below are the connections for each component in the Smart Pet Wearable system:

### **Arduino Nano to MPU-6050**:
- **VCC** -> **5V** (Arduino Nano)
- **GND** -> **GND** (Arduino Nano)
- **SDA** -> **A4** (Arduino Nano)
- **SCL** -> **A5** (Arduino Nano)

### **Arduino Nano to SIM800L**:
- **VCC** -> **3.7V battery (through 1000µF capacitor)**
- **GND** -> **GND** (Arduino Nano)
- **TX** -> **D2 (TX)** (Arduino Nano)
- **RX** -> **D3 (RX)** (Arduino Nano)

### **Arduino Nano to DS18B20**:
- **VCC** -> **5V** (Arduino Nano)
- **GND** -> **GND** (Arduino Nano)
- **Data** -> **D4** (Arduino Nano)

### **Arduino Nano to NEO-6M GPS Module**:
- **VCC** -> **5V** (Arduino Nano)
- **GND** -> **GND** (Arduino Nano)
- **TX** -> **D5 (RX)** (Arduino Nano)
- **RX** -> **D6 (TX)** (Arduino Nano)

## Pin Diagrams for Components

### 1. **Arduino Nano**
   - **Pin A4**: SDA (I2C)
   - **Pin A5**: SCL (I2C)
   - **Pin D2**: TX (For SIM800L)
   - **Pin D3**: RX (For SIM800L)
   - **Pin D4**: Data (For DS18B20)
   - **Pin D5**: RX (For GPS Module)
   - **Pin D6**: TX (For GPS Module)

### 2. **MPU-6050**
   - **VCC** -> 5V
   - **GND** -> GND
   - **SDA** -> A4 (Arduino Nano)
   - **SCL** -> A5 (Arduino Nano)

### 3. **SIM800L**
   - **VCC** -> 3.7V Li-ion Battery
   - **GND** -> GND (Arduino Nano)
   - **TX** -> D2 (Arduino Nano)
   - **RX** -> D3 (Arduino Nano)

### 4. **DS18B20**
   - **VCC** -> 5V (Arduino Nano)
   - **GND** -> GND (Arduino Nano)
   - **Data** -> D4 (Arduino Nano)

### 5. **NEO-6M GPS Module**
   - **VCC** -> 5V (Arduino Nano)
   - **GND** -> GND (Arduino Nano)
   - **TX** -> D5 (Arduino Nano)
   - **RX** -> D6 (Arduino Nano)

## References

- [MPU-6050 Pinout & Datasheet](https://www.instructables.com/id/How-to-use-the-MPU-6050-with-Arduino/)
- [SIM800L Pinout & Datasheet](https://www.electronicwings.com/nodemcu/sim800l-gsm-module)
- [DS18B20 Pinout & Datasheet](https://www.analog.com/en/products/ds18b20.html)
- [NEO-6M GPS Module Pinout & Datasheet](https://www.electronicwings.com/nodemcu/neo-6m-gps-module)

## General References

- [Arduino Documentation](https://www.arduino.cc/en/Tutorial/HomePage)
- [Fritzing Circuit Diagrams](https://fritzing.org/home/)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits)
- [KiCad Documentation](https://kicad.org/)

## Conclusion
The **Smart Pet Wearable** is a versatile and cost-effective solution for monitoring the health and well-being of your pet. With temperature tracking, activity detection, and GPS location capabilities, this project provides a simple but powerful tool for ensuring your pet's safety and health. Through real-time SMS updates, pet owners can quickly address any potential issues, making it an essential gadget for responsible pet care.
