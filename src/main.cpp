#include <Arduino.h>
#include <DHT.h>

/**
 * @file dht_monitor.ino
 * @brief Temperature and Humidity monitoring using DHT11 sensor.
 * @author Vedansh
 * @date 2026-02-28
 *
 * @details
 * This program reads temperature and humidity data from a DHT11 sensor
 * connected to an Arduino board and prints the values to the Serial Monitor
 * every 2 seconds. It demonstrates basic sensor interfacing and serial
 * communication in an embedded system.
 */

/** @brief Digital pin connected to the DHT11 data pin */
#define DHTPIN 2

/** @brief Type of DHT sensor being used (DHT11) */
#define DHTTYPE DHT11

/**
 * @brief DHT sensor object
 *
 * Initializes the DHT sensor with the specified pin and type.
 */
DHT dht(DHTPIN, DHTTYPE);

/**
 * @brief Arduino setup function
 *
 * Initializes serial communication and starts the DHT sensor.
 * This function runs once when the Arduino boots.
 */
void setup() {
    Serial.begin(9600);   ///< Start serial communication at 9600 baud rate
    dht.begin();          ///< Initialize the DHT sensor

    Serial.println("DHT11 Temperature & Humidity Monitoring System Started...");
}

/**
 * @brief Arduino main loop function
 *
 * Continuously reads humidity and temperature values from the DHT11 sensor.
 * If the sensor reading fails, an error message is printed.
 * Otherwise, the temperature (°C) and humidity (%) are displayed
 * on the Serial Monitor every 2 seconds.
 */
void loop() {

    /**
     * @brief Read humidity from the DHT sensor
     * @return Humidity value in percentage (%)
     */
    float humidity = dht.readHumidity();

    /**
     * @brief Read temperature from the DHT sensor
     * @return Temperature value in Celsius (°C)
     */
    float temperature = dht.readTemperature();

    /**
     * @brief Validate sensor readings
     *
     * Checks if the sensor returned invalid values (NaN).
     * If invalid, an error message is displayed and the loop iteration ends.
     */
    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Error: Failed to read from DHT sensor!");
        return;
    }

    /**
     * @brief Print temperature and humidity to Serial Monitor
     */
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    /**
     * @brief Delay before next sensor reading
     *
     * Waits 2000 milliseconds (2 seconds) to avoid excessive polling,
     * as DHT11 has a slow sampling rate.
     */
    delay(2000);
}
