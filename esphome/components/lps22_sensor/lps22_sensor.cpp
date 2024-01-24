#include "esphome/core/log.h"
#include "lps22_sensor.h"

namespace esphome {
namespace lps22_sensor {

static const char *TAG = "lps22_sensor.sensor";

void LPS22Sensor::setup(){
	Serial.begin(115200);
	while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens

	Serial.println("Adafruit LPS22 test!");

	// Try to initialize!
	if (!lps.begin_I2C()) {
		Serial.println("Failed to find LPS22 chip");
		while (1) { delay(10); }
	}
	Serial.println("LPS22 Found!");

	lps.setDataRate(LPS22_RATE_10_HZ);
	Serial.print("Data rate set to: ");
	switch (lps.getDataRate()) {
		case LPS22_RATE_ONE_SHOT: Serial.println("One Shot / Power Down"); break;
		case LPS22_RATE_1_HZ: Serial.println("1 Hz"); break;
		case LPS22_RATE_10_HZ: Serial.println("10 Hz"); break;
		case LPS22_RATE_25_HZ: Serial.println("25 Hz"); break;
		case LPS22_RATE_50_HZ: Serial.println("50 Hz"); break;
		case LPS22_RATE_75_HZ: Serial.println("75 Hz"); break;
	}
}

void LPS22Sensor::update(){
	sensors_event_t temp;
	sensors_event_t pressure;
	lps.getEvent(&pressure, &temp);// get pressure
	Serial.print("Temperature: ");Serial.print(temp.temperature);Serial.println(" degrees C");
	Serial.print("Pressure: ");Serial.print(pressure.pressure);Serial.println(" hPa");
	Serial.println("");

	float temperature = temp.temperature;
	temperature_sensor->publish_state(temperature);

	float pres = pressure.pressure;
	pressure_sensor->publish_state(pres);
	delay(100);
}

void LPS22Sensor::dump_config(){
  ESP_LOGCONFIG(TAG, "LPS22:");
  LOG_I2C_DEVICE(this);
  if (this->is_failed()) {
    ESP_LOGE(TAG, "Communication with LPS22 failed!");
  }
  LOG_UPDATE_INTERVAL(this);

  LOG_SENSOR("  ", "Temperature", this->temperature_sensor);
  LOG_SENSOR("  ", "Pressure", this->pressure_sensor);
}

}  // namespace LPS22Sensor
}  // namespace esphome