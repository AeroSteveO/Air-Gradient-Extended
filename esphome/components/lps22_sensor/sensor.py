import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import CONF_ID, ICON_EMPTY, UNIT_EMPTY,UNIT_HPA, UNIT_CELSIUS,  CONF_TEMPERATURE, CONF_PRESSURE, DEVICE_CLASS_PRESSURE, DEVICE_CLASS_TEMPERATURE, STATE_CLASS_MEASUREMENT

DEPENDENCIES = ['i2c']

CONF_I2C_ADDR = 0x5d

lps22_sensor = cg.esphome_ns.namespace('lps22_sensor')
LPS22Sensor = lps22_sensor.class_('LPS22Sensor', cg.PollingComponent, i2c.I2CDevice)

#CONFIG_SCHEMA = sensor.sensor_schema(UNIT_EMPTY, ICON_EMPTY, 1).extend({
#    cv.GenerateID(): cv.declare_id(LPS22Sensor),
#}).extend(cv.polling_component_schema('60s')).extend(i2c.i2c_device_schema(CONF_I2C_ADDR))
CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(LPS22Sensor),
            cv.Required(CONF_TEMPERATURE): sensor.sensor_schema(
                unit_of_measurement=UNIT_CELSIUS,
                accuracy_decimals=1,
                device_class=DEVICE_CLASS_TEMPERATURE,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
            cv.Required(CONF_PRESSURE): sensor.sensor_schema(
                unit_of_measurement=UNIT_HECTOPASCAL,
                accuracy_decimals=1,
                device_class=DEVICE_CLASS_PRESSURE,
                state_class=STATE_CLASS_MEASUREMENT,
            ),
#            cv.Optional(CONF_HEATER_ENABLED, default=False): cv.boolean,
        },
    )
    .extend(cv.polling_component_schema("60s"))
    .extend(i2c.i2c_device_schema(0x44))
)
async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield sensor.register_sensor(var, config)
    yield i2c.register_i2c_device(var, config)

    if CONF_TEMPERATURE in config:
        sens = await sensor.new_sensor(config[CONF_TEMPERATURE])
        cg.add(var.set_temperature_sensor(sens))

    if CONF_PRESSURE in config:
        sens = await sensor.new_sensor(config[CONF_PRESSURE])
        cg.add(var.set_pressure_sensor(sens))