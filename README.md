# Air-Gradient-Extended
Using Air Gradient DIY kits and EspHome, with some additional sensors added in (TVOC and Pressure)

## Air-Gradient DIY Baseline Sensors
- SHT3XD
- PMSX003
- Senseair S8


## Additional Sensors
- LPS22
- SGP30

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
