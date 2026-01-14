# AirQuality-Humidity-PPM-Monitor-using-ESP32
Uses:
  ESP32, MQ2 Gas Sensor Module, DHT22, Knob-controlled variable resistor (linear potentiometer), wokwi-lcd1602, 1 Green and Red LED, piezoelectric buzzer
Function:
  First 10 loops finds the average of PPM to calibrate the MQ2 gas sensor and set the calibrated PPM level.
  Calibrated temperature and humidity limits set by user.
  All succeeding loops of the system reads the Temperature, Humidity, PPM.
Outputs:
  All values are normal and within calibrated thresholds:
    Green LED = True
    LCD screen displays Temp and Humidity, shows "All safe"
  At least one value outside of calibrated threshold:
    Buzzer beeps once, Red LED lights up, LCD screen shows "Danger"
    Keeps this up until all the values are back to the normal limits
