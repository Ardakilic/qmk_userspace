#include_next <mcuconf.h>

// Enable I2C1 for the Azoteq IQS5xx driver
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 FALSE
