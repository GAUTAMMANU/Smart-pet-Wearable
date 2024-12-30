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
- **Arduino Nano**: Small and efficient microcontroller for handling the sensors, GSM, and GPS modules.
- **MPU-6050**: Detects pet's activity by measuring acceleration.
- **SIM800L GSM Module**: Sends real-time SMS data to the owner.
- **DS18B20 Temperature Sensor**: Measures pet's body temperature.
- **NEO-6M GPS Module**: Tracks the pet's location in real-time.
- **1000µF Capacitor**: Stabilizes power to the SIM800L module to prevent drops during transmission.
- **Li-ion Battery**: Powers the system; 5V for Arduino and 3.7V for SIM800L. (while testing just connect arduino to your laptop for power)
- TP4056 1A Li-ion Battery Charging Module (will be needed for recharging li-ion battery, not necessary though-other methods maybe used)

## Components and Connections

1. **Arduino Nano to MPU-6050 (Accelerometer & Gyroscope)**
   - **VCC** -> **5V** (Arduino Nano)
   - **GND** -> **GND** (Arduino Nano)
   - **SDA** -> **A4** (Arduino Nano)
   - **SCL** -> **A5** (Arduino Nano)

2. **Arduino Nano to SIM800L GSM Module**
   - **VCC** -> **3.7V Li-ion Battery** (through 1000µF capacitor)
   - **GND** -> **GND** (Arduino Nano)
   - **TX** -> **D2** (Arduino Nano)
   - **RX** -> **D3** (Arduino Nano)

3. **Arduino Nano to DS18B20 Temperature Sensor**
   - **VCC** -> **5V** (Arduino Nano)
   - **GND** -> **GND** (Arduino Nano)
   - **Data** -> **D4** (Arduino Nano)

4. **Arduino Nano to NEO-6M GPS Module**
   - **VCC** -> **5V** (Arduino Nano)
   - **GND** -> **GND** (Arduino Nano)
   - **TX** -> **D5** (Arduino Nano)
   - **RX** -> **D6** (Arduino Nano)

5. **Capacitor for SIM800L**
   - A **1000µF** capacitor is connected in parallel with the **VCC** pin of the **SIM800L GSM module** to stabilize the power supply. This capacitor helps handle the high current draw of the SIM800L during transmission.

## General Instructions

- **Arduino Code Uploading**: Only the latest uploaded code will be active on the Arduino at any time. If you need to reload the program, press the reset button on the Arduino Nano to restart and upload a new sketch.
- **NEO-6M GPS Module**: The GPS module requires good reception and an open environment to establish a connection. It may take a few minutes(maybe even +20 min) for the GPS to acquire a signal(show a blink). If it struggles to connect, consider using an improved antenna or alternative portable GPS modules for better performance.
- **SIM800L GSM Module**: The SIM800L GSM module blinks once every second while attempting to connect to the network. Once the connection is successfully established, the blink rate changes to once every 3 seconds. If the SIM800L keeps restarting or fails to establish a connection, check the connections to the battery and capacitor. Inadequate power can cause instability; ensure the capacitor is correctly placed to handle voltage spikes.
- **Component Sources**: Components, breadboards, and connectors (male/female) can be sourced from reliable online stores such as [Robu.in](https://www.robu.in), [Robocraze](https://www.robocraze.com), and similar electronics suppliers. 
- **Testing and Troubleshooting**: Always ensure that the power supply and connections are correct before powering up the system. A stable power source and proper wiring are crucial for the proper functioning of all components, especially the SIM800L and GPS module.

## References

- [MPU-6050 Pinout & Datasheet](https://components101.com/sensors/mpu6050-module)
- [SIM800L Pinout & Datasheet](https://components101.com/wireless/sim800l-gsm-module-pinout-datasheet-equivalent-circuit-specs)
- [DS18B20 Pinout & Datasheet](https://randomnerdtutorials.com/guide-for-ds18b20-temperature-sensor-with-arduino/)
- [NEO-6M GPS Module Pinout & Datasheet]([https://www.electronicwings.com/nodemcu/neo-6m-gps-module](https://randomnerdtutorials.com/guide-to-neo-6m-gps-module-with-arduino/))

## General References

- [Arduino Documentation](https://www.arduino.cc/en/Tutorial/HomePage)

## Conclusion
The **Smart Pet Wearable** is a versatile and cost-effective solution for monitoring the health and well-being of your pet. With temperature tracking, activity detection, and GPS location capabilities, this project provides a simple but powerful tool for ensuring your pet's safety and health. Through real-time SMS updates, pet owners can quickly address any potential issues, making it an essential gadget for responsible pet care.
