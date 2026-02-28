#include <Arduino.h>   // Core Arduino library (automatically included in most IDEs)

#include <DHT.h>       // Library to handle DHT11/DHT22 temperature & humidity sensors

#define DHTPIN 2       // Define the digital pin where the DHT11 data pin is connected
#define DHTTYPE DHT11  // Specify the type of DHT sensor (DHT11 in this case)

// Create a DHT object with the specified pin and sensor type
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(9600);   // Start serial communication at 9600 baud rate

    dht.begin();          // Initialize the DHT sensor

    // Print a startup message to Serial Monitor
    Serial.println("DHT11 Temperature & Humidity Monitoring System Started...");
}

void loop() {

    // Read humidity value from the sensor
    float humidity = dht.readHumidity();

    // Read temperature value in Celsius from the sensor
    float temperature = dht.readTemperature();

    // Check if any reading failed (NaN = Not a Number)
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Error: Failed to read from DHT sensor!");
        return;  // Exit loop iteration and try again in next cycle
    }

    // Print temperature value
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");

    // Print humidity value
    Serial.print(humidity);
    Serial.println(" %");

    // Wait for 2 seconds before taking the next reading
    delay(2000);
}
