LTO_ENABLE = yes

# The OLED is an optional module and nothing here draws on it (no oled_task_kb/oled_task_user),
# so it stays off. A keymap that renders it sets OLED_ENABLE = yes in its rules.mk
# (plus WPM_ENABLE = yes if it shows WPM). The OLED settings in config.h stay for such a keymap.
OLED_ENABLE = no
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_i2c