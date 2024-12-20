# Smart Gesture Glove: Translating Hand Gestures into Words

## Overview
This repository contains the implementation of a **Smart Gesture Glove** that translates hand gestures into meaningful words. The glove uses **flex sensors**, hardware circuits, and a combination of **Arduino**, **Python**, and **MATLAB** to create an efficient gesture recognition system.

## Features
- Gesture recognition using flex sensors.
- Data sampling with Python and serial communication.
- Machine learning model (KNN) implemented in MATLAB.
- Real-time gesture translation using Arduino programming.

---

## How It Works
### 1. **Hardware Setup**
- **Components**: Flex sensors, resistors (8.2 kΩ), Arduino.
- The flex sensors detect finger bending by changing resistance.

### 2. **Data Collection**
- Python reads sensor data from the serial port.
- Sensor readings for each gesture are saved into `.txt` files.

### 3. **Model Training**
- MATLAB uses a KNN model to process the sensor data.
- Mean and threshold values are calculated from the samples.

### 4. **Final Gesture Translation**
- Threshold and mean values are incorporated into the final Arduino code.
- The glove translates user gestures into meaningful words in real-time.

---

## Installation and Usage
### 1. **Prerequisites**
- Arduino IDE
- Python 3.2
- MATLAB with KNN support

### 2. **Steps**
1. Clone this repository:
   ```bash
   git clone https://github.com/Faizan_Nexus/smart-gesture-glove.git
   ```
2. Set up the hardware circuit as described in the `GlovePic` image.
3. Upload the basic sensor test code to your Arduino.
4. Use the Python script in `data_Collection` to collect gesture data.
5. Train the KNN model in MATLAB using the scripts in `TrainingMode_KNN_Code/`.
6. Upload the final code to Arduino from `finalCode/`.

---

## Folder Structure
- `Smart Sign GLove/` - Contains all the files.
- `/GlovePic` - Project Image.
- `/TrainingModel_KNN_Code` - MATLAB KNN model and processing scripts.
- `finalCode/` - Arduino code for gesture translation.
- `Docs/` - Detailed project documentation and setup instructions.

---

## Contributors
- **Muhammad Faizan** ([GitHub Profile](https://github.com/Faizan-Nexus))
- **Muhammad Zuhaib** ([GitHub Profile](https://github.com/Zuhaib23))

---

## Acknowledgements
Special thanks to the team for their collaborative efforts and to the open-source tools and platforms that made this project possible.

---

## License
This project is licensed under the MIT License. See `LICENSE` for details.
