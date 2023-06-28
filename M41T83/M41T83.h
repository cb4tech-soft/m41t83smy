#ifndef __M41T83_H__
#define __M41T83_H__

#include <sys/types.h>
#include <Wire.h>
#include "gpio.h"
#include "M41T83_def.h"
#ifndef M41T83_ADDRESS
    #define M41T83_ADDRESS 0x68
#endif
#ifndef I2C_SDA
    #define I2C_SDA 5
#endif
#ifndef I2C_SCL
    #define I2C_SCL 6
#endif
#ifndef SERIALDBG
    #define SERIALDBG Serial0
#endif

enum Century {
    C20 = 0,
    C21 = 1,
    C22 = 2,
    C23 = 3
};

enum DayOfWeek {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};


typedef struct M41T83_MEMORY_s{
    M41T83_TENTH_REG tenth_reg;
    M41T83_SEC_REG second_reg;
    M41T83_MIN_REG minute_reg;
    M41T83_HOUR_REG hour_reg;
    M41T83_DAY_WEEK_REG day_week_reg;
    M41T83_DAY_MONTH_REG day_month_reg;
    M41T83_MONTH_REG month_reg;
    M41T83_YEAR_REG year_reg;
    M41T83_DIG_CAL_REG dig_cal_reg;
    M41T83_WATCHDOG_REG watchdog_reg;
    M41T83_ALARM_1_MONTH_REG alarm_1_month_reg;
    M41T83_ALARM_1_DATE_REG alarm_1_date_reg;
    M41T83_ALARM_1_HOUR_REG alarm_1_hour_reg;
    M41T83_ALARM_1_MIN_REG alarm_1_min_reg;
    M41T83_ALARM_1_SEC_REG alarm_1_sec_reg;
    M41T83_FLAG_REG flag_reg;
    M41T83_TMR_REG timer_value_reg;
    M41T83_TMR_CTRL_REG timer_ctrl_reg;
    M41T83_ANA_CAL_REG ana_cal_reg;
    M41T83_SQW_REG sqw_reg;
    M41T83_ALARM_2_MONTH_REG alarm_2_month_reg;
    M41T83_ALARM_2_DATE_REG alarm_2_date_reg;
    M41T83_ALARM_2_HOUR_REG alarm_2_hour_reg;
    M41T83_ALARM_2_MIN_REG alarm_2_min_reg;
    M41T83_ALARM_2_SEC_REG alarm_2_sec_reg;
    uint8_t user_sram[7];
}M41T83_MEMORY_t;

typedef union M41T83_MEMORY_u{
    M41T83_MEMORY_t reg; uint8_t bytes[M41T83_REG_SIZE];
} M41T83_MEMORY;

uint8_t M41T83_clear_HT_bit();
uint8_t M41T83_KickStart_ST_bit();
M41T83_MEMORY M41T83_read_memory();
uint8_t M41T83_read_register(uint8_t register_address);
uint8_t M41T83_write_register(uint8_t register_address, uint8_t data);
uint8_t M41T83_set_time(uint8_t hour, uint8_t minute, uint8_t second, uint8_t centh);
uint8_t M41T83_set_date(uint8_t day, uint8_t month, uint8_t years, uint8_t century);
uint8_t M41T83_set_dayOfWeek(uint8_t dayOfWeek);
void M41T83_print_time(M41T83_MEMORY *memory);
void M41T83_print_time();
void M41T83_print_date();
uint64_t M41T83_get_unix_time();
void M41T83_set_unix_time(uint64_t epoch);

#endif

