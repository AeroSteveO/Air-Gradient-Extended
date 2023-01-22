# Air-Gradient-Extended
Using Air Gradient DIY kits with some additional sensors added in (TVOC and Pressure). Flashed using EspHome for monitoring and pushing data to home assistant.

## Sensors:
- SHT3XD
- PMSX003
- Senseair S8
- [LPS22 (the purple plate is what I used)](https://www.aliexpress.us/item/3256804423878004.html)
- [SGP30](https://www.aliexpress.us/item/2255801057593796.html)

## Monitored Values:
- CO2
- eCO2
- TVOC
- Temperature (LPS22 and SHT3XD)
- PM1.0
- PM2.5
- PM10
- Atmospheric Pressure

## File Layout

- /config/esphome/sensor_lps22.h
- /config/esphome/font/productsans.ttf
- /config/esphome/font/Roboto-Light.ttf

## Libraries Utilized:

- [Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor.git)
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO.git)
- [Adafruit_LPS2x](https://github.com/adafruit/Adafruit_LPS2X.git)

## Case:

I used the vented case for my builds, and used the temperature probe tower from the airgradient official case design.

- [Vented Case](https://www.printables.com/model/273756-vented-airgradiant-enclosure)
- [Standard Case](https://www.airgradient.com/open-airgradient/instructions/diy/diy_3d_new.zip)

## Resources:

- [Custom Sensor Documentation](https://esphome.io/components/sensor/custom.html)
- [Adafruit LPS22 Documentation](https://learn.adafruit.com/adafruit-lps25-pressure-sensor)
