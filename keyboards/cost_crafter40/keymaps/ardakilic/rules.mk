COMBO_ENABLE = yes
# Enable pointing device support (trackpad)
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = azoteq_iqs5xx

# Enable OS Detection for automatic Mac/Windows layer switching
OS_DETECTION_ENABLE = yes

# Enable mousekey support for combos
MOUSEKEY_ENABLE = yes

# Fix for unused function warning in I2C driver on RP2040
# error: 'i2c_lld_serve_interrupt' defined but not used [-Werror=unused-function]
# EXTRAFLAGS += -Wno-unused-function
