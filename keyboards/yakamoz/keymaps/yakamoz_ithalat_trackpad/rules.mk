WPM_ENABLE = yes
AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware

# Azoteq TPS65 trackpad in the "ithalat" wrist rest, on the OLED's I2C bus (I2C1, GP2/GP3).
# QMK selects exactly ONE pointing driver: this replaces the optional Pimoroni trackball
# (keymaps/default_trackball); the two cannot be used together without a custom driver.
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = azoteq_iqs5xx
