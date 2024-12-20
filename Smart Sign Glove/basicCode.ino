// Mean values for different gestures
const float coolMeanVals[] = {103.74, 103.74, 103.92, 95.154, 94.156};
const float foodMeanVals[] = {107.93, 107.8, 107.97, 135.31, 127.1};
const float leaveMeanVals[] = {70.824, 70.807, 71.055, 176.58, 89.71};
const float helpMeanVals[] = {122.33, 122.32, 122.29, 115.2, 106.74};
const float howMeanVals[] = {81.43, 81.376, 81.581, 106.06, 90.071};
const float medsMeanVals[] = {102.7, 102.64, 102.74, 173.04, 108.38};
const float niceMeanVals[] = {105.92, 105.86, 105.86, 95.04, 157.01};
const float okMeanVals[] = {79.843, 79.864, 80.079, 175.32, 142.97};
const float washroomMeanVals[] = {91.285, 91.276, 91.507, 119.95, 111.81};
const float whyMeanVals[] = {106.03, 105.94, 106.09, 179.21, 144.78};
const float yesMeanVals[] = {102.9, 102.93, 103.14, 118, 98.118};

// Threshold for gesture detection
const int threshold = 25;

// Sensor pin definitions
const int thumbPin = A0;
const int indexPin = A1;
const int middlePin = A2;
const int ringPin = A3;
const int littlePin = A4;

// Offset to handle sensor inaccuracies or environmental changes
const int offsets[] = {5, 5, 5, 5, 5}; // Adjust offsets as needed for each sensor

void setup() {
  Serial.begin(9600);
  pinMode(thumbPin, INPUT);
  pinMode(indexPin, INPUT);
  pinMode(middlePin, INPUT);
  pinMode(ringPin, INPUT);
  pinMode(littlePin, INPUT);
}

void loop() {
  // Read sensor values
  float sensorVals[5];
  sensorVals[0] = analogRead(thumbPin);
  sensorVals[1] = analogRead(indexPin);
  sensorVals[2] = analogRead(middlePin);
  sensorVals[3] = analogRead(ringPin);
  sensorVals[4] = analogRead(littlePin);

  // Adjust sensor values with offsets
  for (int i = 0; i < 5; i++) {
    sensorVals[i] += offsets[i];
  }

  // Check if a gesture matches
  if (gestureMatched(sensorVals, coolMeanVals)) {
    Serial.println("Cool Gesture Detected!");
  } else if (gestureMatched(sensorVals, foodMeanVals)) {
    Serial.println("Food Gesture Detected!");
  } else if (gestureMatched(sensorVals, leaveMeanVals)) {
    Serial.println("Leave Gesture Detected!");
  } else if (gestureMatched(sensorVals, helpMeanVals)) {
    Serial.println("Help Gesture Detected!");
  } else if (gestureMatched(sensorVals, howMeanVals)) {
    Serial.println("How Gesture Detected!");
  } else if (gestureMatched(sensorVals, medsMeanVals)) {
    Serial.println("Meds Gesture Detected!");
  } else if (gestureMatched(sensorVals, niceMeanVals)) {
    Serial.println("Nice Gesture Detected!");
  } else if (gestureMatched(sensorVals, okMeanVals)) {
    Serial.println("OK Gesture Detected!");
  } else if (gestureMatched(sensorVals, washroomMeanVals)) {
    Serial.println("Washroom Gesture Detected!");
  } else if (gestureMatched(sensorVals, whyMeanVals)) {
    Serial.println("Why Gesture Detected!");
  } else if (gestureMatched(sensorVals, yesMeanVals)) {
    Serial.println("Yes Gesture Detected!");
  } else {
    Serial.println("No gesture detected.");
  }

  delay(2000); // Delay for sensor stability
}

// Function to check if sensor values match a gesture
bool gestureMatched(float sensorVals[], const float meanVals[]) {
  for (int i = 0; i < 5; i++) {
    if (abs(sensorVals[i] - meanVals[i]) > threshold) {
      return false;
    }
  }
  return true;
}
