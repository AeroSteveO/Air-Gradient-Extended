import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c, sensor
from esphome.const import CONF_ID, ICON_EMPTY, UNIT_EMPTY

DEPENDENCIES = ['i2c']

CONF_I2C_ADDR = 0x5d

lps22_sensor = cg.esphome_ns.namespace('lps22_sensor')
LPS22Sensor = lps22_sensor.class_('LPS22Sensor', cg.PollingComponent, i2c.I2CDevice)

CONFIG_SCHEMA = sensor.sensor_schema(UNIT_EMPTY, ICON_EMPTY, 1).extend({
    cv.GenerateID(): cv.declare_id(LPS22Sensor),
}).extend(cv.polling_component_schema('60s')).extend(i2c.i2c_device_schema(CONF_I2C_ADDR))

def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield sensor.register_sensor(var, config)
    yield i2c.register_i2c_device(var, config)