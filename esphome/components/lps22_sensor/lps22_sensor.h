#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

// ...
// Basic demo for pressure readings from Adafruit LPS2X
#include <Wire.h>
#include <Adafruit_LPS2X.h>
#include <Adafruit_Sensor.h>

namespace esphome {
namespace lps22_sensor {

class LPS22Sensor : public sensor::Sensor, public PollingComponent, public i2c::I2CDevice {
 public:
  void set_temperature_sensor(sensor::Sensor *temperature_sensor_) { temperature_sensor = temperature_sensor_; }
  void set_pressure_sensor(sensor::Sensor *pressure_sensor_) { pressure_sensor = pressure_sensor_; }
  
  Adafruit_LPS22 lps;
  Sensor *temperature_sensor{nullptr}; // = new Sensor();
  Sensor *pressure_sensor{nullptr}; // = new Sensor();
  LPS22Sensor() : PollingComponent(15000) { }
  
  void setup() override;
  void update() override;
  void dump_config() override;
};

}  // namespace LPS22Sensor
}  // namespace esphome