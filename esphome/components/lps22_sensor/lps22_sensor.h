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
  Adafruit_LPS22 lps;
  Sensor *temperature_sensor = new Sensor();
  Sensor *pressure_sensor = new Sensor();
  SensorLps22() : PollingComponent(15000) { }
  
  void setup() override;
  void update() override;
  void dump_config() override;
};

}  // namespace LPS22Sensor
}  // namespace esphome