COMBO_ENABLE = yes
# Enable pointing device support (trackpad)
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = azoteq_iqs5xx

# Fix for unused function warning in I2C driver on RP2040
# error: 'i2c_lld_serve_interrupt' defined but not used [-Werror=unused-function]
# EXTRAFLAGS += -Wno-unused-function
