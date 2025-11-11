// Enable Azoteq TPS65 Trackpad on GP18 and GP19
#define AZOTEQ_IQS5XX_TPS65
#define I2C1_SDA_PIN GP18
#define I2C1_SCL_PIN GP19
#define I2C_DRIVER I2CD1

// Combo configuration
#define COMBO_TERM 50
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO

// Enable OS Detection
#define OS_DETECTION_ENABLE

// Tapping term for layer tap and mod tap keys
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY

// Prevent accidental modifier activations
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
