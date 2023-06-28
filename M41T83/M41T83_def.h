#ifndef __M41T83_DEF_H__
#define __M41T83_DEF_H__

#include <sys/types.h>

#define M41T83_REG_SIZE 32

#define M41T83_ADDR_ST M41T83_HEX_ADDR_SECONDS
#define M41T83_ADDR_HT M41T83_HEX_ADDR_ALARM1_HOUR

#define M41T83_ADDR_TENTH_SECONDS 0
#define M41T83_ADDR_SECONDS 1
#define M41T83_ADDR_MINUTES 2
#define M41T83_ADDR_HOURS 3
#define M41T83_ADDR_DAY 4
#define M41T83_ADDR_DATE 5
#define M41T83_ADDR_MONTH 6
#define M41T83_ADDR_YEAR 7
#define M41T83_ADDR_DIGITAL_CALIBRATION 8
#define M41T83_ADDR_WATCHDOG 9
#define M41T83_ADDR_ALARM1_MONTH 10
#define M41T83_ADDR_ALARM1_DAY 11
#define M41T83_ADDR_ALARM1_HOUR 12
#define M41T83_ADDR_ALARM1_MINUTE 13
#define M41T83_ADDR_ALARM1_SECOND 14
#define M41T83_ADDR_FLAGS 15
#define M41T83_ADDR_TIMER_VALUE 16
#define M41T83_ADDR_TIMER_CONTROL 17
#define M41T83_ADDR_ANALOG_CALIBRATION 18
#define M41T83_ADDR_SQW 19
#define M41T83_ADDR_ALARM2_MONTH 20
#define M41T83_ADDR_ALARM2_DAY 21
#define M41T83_ADDR_ALARM2_HOUR 22
#define M41T83_ADDR_ALARM2_MINUTE 23
#define M41T83_ADDR_ALARM2_SECOND 24
#define M41T83_ADDR_USER_RAM0 25
#define M41T83_ADDR_USER_RAM1 26
#define M41T83_ADDR_USER_RAM2 27
#define M41T83_ADDR_USER_RAM3 28
#define M41T83_ADDR_USER_RAM4 29
#define M41T83_ADDR_USER_RAM5 30
#define M41T83_ADDR_USER_RAM6 31



#define M41T83_HEX_ADDR_SECONDS  0x01
#define M41T83_HEX_ADDR_MINUTES  0x02
#define M41T83_HEX_ADDR_HOURS    0x03
#define M41T83_HEX_ADDR_DATE_DAYOFWEEK 0x04
#define M41T83_HEX_ADDR_DATE_DAYOFMONTH 0x05
#define M41T83_HEX_ADDR_DATE_MONTH 0x06
#define M41T83_HEX_ADDR_DATE_YEARS 0x07
#define M41T83_HEX_ADDR_DIGITAL_CALIBRATION 0x08
#define M41T83_HEX_ADDR_WATCHDOG 0x09
#define M41T83_HEX_ADDR_ALARM1_MONTH 0x0A
#define M41T83_HEX_ADDR_ALARM1_DAY 0x0B
#define M41T83_HEX_ADDR_ALARM1_HOUR 0x0C
#define M41T83_HEX_ADDR_ALARM1_MINUTE 0x0D
#define M41T83_HEX_ADDR_ALARM1_SECOND 0x0E
#define M41T83_HEX_ADDR_FLAG 0x0F
#define M41T83_HEX_ADDR_TIMER_VALUE 0x10
#define M41T83_HEX_ADDR_TIMER_CONTROL 0x11
#define M41T83_HEX_ADDR_ANALOG_CALIBRATION 0x12
#define M41T83_HEX_ADDR_SQW 0x13
#define M41T83_HEX_ADDR_ALARM2_MONTH 0x14
#define M41T83_HEX_ADDR_ALARM2_DAY 0x15
#define M41T83_HEX_ADDR_ALARM2_HOUR 0x16
#define M41T83_HEX_ADDR_ALARM2_MINUTE 0x17
#define M41T83_HEX_ADDR_ALARM2_SECOND 0x18
#define M41T83_HEX_ADDR_SRAM_START 0x19





typedef struct M41T83_TENTH_REG_s{
    uint8_t centh:4;
    uint8_t tenth:4;
}M41T83_TENTH_REG_t;

typedef union M41T83_TENTH_REG_u{
    M41T83_TENTH_REG_t reg; uint8_t byte;
} M41T83_TENTH_REG;


typedef struct M41T83_SEC_REG_s{
    uint8_t seconds:4;
    uint8_t ten_seconds:3;
    uint8_t ST:1;
}M41T83_SEC_REG_t;

typedef union M41T83_SEC_REG_u{
    M41T83_SEC_REG_t reg; uint8_t byte;
} M41T83_SEC_REG;


typedef struct M41T83_MIN_REG_s{
    uint8_t minutes:4;
    uint8_t ten_minutes:3;
    uint8_t _unused:1;
}M41T83_MIN_REG_t;

typedef union M41T83_MIN_REG_u{
    M41T83_MIN_REG_t reg; uint8_t byte;
} M41T83_MIN_REG;


typedef struct M41T83_HOUR_REG_s{
    uint8_t hours:4;
    uint8_t ten_hours:2;
    uint8_t century:2;
}M41T83_HOUR_REG_t;

typedef union M41T83_HOUR_REG_u{
    M41T83_HOUR_REG_t reg; uint8_t byte;
} M41T83_HOUR_REG;


typedef struct M41T83_DAY_WEEK_REG_s{
    uint8_t day_of_week:3;
    uint8_t _unused:5;
}M41T83_DAY_WEEK_REG_t;

typedef union M41T83_DAY_WEEK_REG_u{
    M41T83_DAY_WEEK_REG_t reg; uint8_t byte;
} M41T83_DAY_WEEK_REG;


typedef struct M41T83_DAY_MONTH_REG_s{
    uint8_t day_of_month:4;
    uint8_t ten_day_of_month:2;
    uint8_t _unused:2;
}M41T83_DAY_MONTH_REG_t;

typedef union M41T83_DAY_MONTH_REG_u{
    M41T83_DAY_MONTH_REG_t reg; uint8_t byte;
} M41T83_DAY_MONTH_REG;


typedef struct M41T83_MONTH_REG_s{
    uint8_t months:4;
    uint8_t ten_months:1;
    uint8_t _unused:3;
}M41T83_MONTH_REG_t;

typedef union M41T83_MONTH_REG_u{
    M41T83_MONTH_REG_t reg; uint8_t byte;
} M41T83_MONTH_REG;


typedef struct M41T83_YEAR_REG_s{
    uint8_t years:4;
    uint8_t ten_years:4;
}M41T83_YEAR_REG_t;

typedef union M41T83_YEAR_REG_u{
    M41T83_YEAR_REG_t reg; uint8_t byte;
} M41T83_YEAR_REG;


typedef struct M41T83_DIG_CAL_REG_s{
    uint8_t DC:5;   // Digital Calibration bits
    uint8_t DCS:1;  // Digital Calibration Sign
    uint8_t FT:1;   // Frequency Test
    uint8_t OUT:1;  // OUTPUT LEVEL
}M41T83_DIG_CAL_REG_t;

typedef union M41T83_DIG_CAL_REG_u{
    M41T83_DIG_CAL_REG_t reg; uint8_t byte;
} M41T83_DIG_CAL_REG;


typedef struct M41T83_WATCHDOG_REG_s{
    uint8_t RB:2; // Watchdog resolution bits
    uint8_t BMB:5; // Watchdog multiplier bits
    uint8_t OFIE:1; // Oscillator Fail Interrupt Enable
}M41T83_WATCHDOG_REG_t;

typedef union M41T83_WATCHDOG_REG_u{
    M41T83_WATCHDOG_REG_t reg; uint8_t byte;
} M41T83_WATCHDOG_REG;


typedef struct M41T83_ALARM_1_MONTH_REG_s{
    uint8_t month:4;
    uint8_t ten_month:1;
    uint8_t ABE:1;    // Alarm battery backup enable
    uint8_t SQWE:1;     // Square Wave Enable 
    uint8_t A1IE:1;     // Alarm 1 Interrupt Enable
}M41T83_ALARM_1_MONTH_REG_t;

typedef union M41T83_ALARM_1_MONTH_REG_u{
    M41T83_ALARM_1_MONTH_REG_t reg; uint8_t byte;
} M41T83_ALARM_1_MONTH_REG;


typedef struct M41T83_ALARM_1_DATE_REG_s{
    uint8_t day:4;
    uint8_t ten_day:2;
    uint8_t RPT15:1;     // alarm repeat mode bit 4
    uint8_t RPT14:1;     // alarm repeat mode bit 3
}M41T83_ALARM_1_DATE_REG_t;

typedef union M41T83_ALARM_1_DATE_REG_u{
    M41T83_ALARM_1_DATE_REG_t reg; uint8_t byte;
} M41T83_ALARM_1_DATE_REG;


typedef struct M41T83_ALARM_1_HOUR_REG_s{
    uint8_t hour:4;
    uint8_t ten_hour:2;
    uint8_t HT:1;       // Halt update bit
    uint8_t RPT13:1;     // alarm repeat mode bit 2
}M41T83_ALARM_1_HOUR_REG_t;

typedef union M41T83_ALARM_1_HOUR_REG_u{
    M41T83_ALARM_1_HOUR_REG_t reg; uint8_t byte;
} M41T83_ALARM_1_HOUR_REG;


typedef struct M41T83_ALARM_1_MIN_REG_s{
    uint8_t min:4;
    uint8_t ten_min:3;
    uint8_t RPT12:1;     // alarm repeat mode bit 1
} M41T83_ALARM_1_MIN_REG_t;

typedef union M41T83_ALARM_1_MIN_REG_u{
    M41T83_ALARM_1_MIN_REG_t reg; uint8_t byte;
} M41T83_ALARM_1_MIN_REG;


typedef struct M41T83_ALARM_1_SEC_REG_s{
    uint8_t sec:4;
    uint8_t ten_sec:3;
    uint8_t RPT11:1;     // alarm repeat mode bit 0
} M41T83_ALARM_1_SEC_REG_t;

typedef union M41T83_ALARM_1_SEC_REG_u{
    M41T83_ALARM_1_SEC_REG_t reg; uint8_t byte;
} M41T83_ALARM_1_SEC_REG;


typedef struct M41T83_FLAG_REG_s{
    uint8_t unused:2;
    uint8_t OF:1;   // Oscillator fail flag
    uint8_t TF:1;   // Timer flag
    uint8_t BL:1;   // Battery Low flag
    uint8_t AF2:1;  // Alarm 2 flag
    uint8_t AF1:1;  // Alarm 1 flag
    uint8_t WDF:1;  // Watchdog flag
}M41T83_FLAG_REG_t;

typedef union M41T83_FLAG_REG_u{
    M41T83_FLAG_REG_t reg; uint8_t byte;
} M41T83_FLAG_REG;


typedef struct M41T83_TMR_REG_s{
    uint8_t countdown_value:8;
}M41T83_TMR_REG_t;

typedef union M41T83_TMR_REG_u{
    M41T83_TMR_REG_t reg; uint8_t byte;
} M41T83_TMR_REG;


typedef struct M41T83_TMR_CTRL_REG_s{
    uint8_t TD:2;       // Timer frequency
    uint8_t unused:3;   // unused
    uint8_t TIE:1;      // Timer interrupt enable
    uint8_t TI_TP:1;    // Timer interrupt or timer pulse
    uint8_t TE:1;       // Timer enable
}M41T83_TMR_CTRL_REG_t;

typedef union M41T83_TMR_CTRL_REG_u{
    M41T83_TMR_CTRL_REG_t reg; uint8_t byte;
} M41T83_TMR_CTRL_REG;


typedef struct M41T83_ANA_CAL_REG_s{
    uint8_t AC:7;     // Analog calibration value
    uint8_t ACS:1;    // Analog calibration sign
}M41T83_ANA_CAL_REG_t;

typedef union M41T83_ANA_CAL_REG_u{
    M41T83_ANA_CAL_REG_t reg; uint8_t byte;
} M41T83_ANA_CAL_REG;


typedef struct M41T83_SQW_REG_s{
    uint8_t OTP:1;      // One time programmable
    uint8_t AL2E:1;     // Alarm 2 enable
    uint8_t unused:2;     // unused
    uint8_t RS:4;          // SQW Frequency select
}M41T83_SQW_REG_t;

typedef union M41T83_SQW_REG_u{
    M41T83_SQW_REG_t reg; uint8_t byte;
} M41T83_SQW_REG;


typedef struct M41T83_ALARM_2_MONTH_REG_s{
    uint8_t month:4;
    uint8_t ten_month:1;
    uint8_t unused:2;
    uint8_t A1IE:1;     // Alarm 2 Interrupt Enable
}M41T83_ALARM_2_MONTH_REG_t;

typedef union M41T83_ALARM_2_MONTH_REG_u{
    M41T83_ALARM_2_MONTH_REG_t reg; uint8_t byte;
} M41T83_ALARM_2_MONTH_REG;


typedef struct M41T83_ALARM_2_DATE_REG_s{
    uint8_t day:4;
    uint8_t ten_day:2;
    uint8_t RPT25:1;     // alarm repeat mode bit 4
    uint8_t RPT24:1;     // alarm repeat mode bit 3
}M41T83_ALARM_2_DATE_REG_t;

typedef union M41T83_ALARM_2_DATE_REG_u{
    M41T83_ALARM_2_DATE_REG_t reg; uint8_t byte;
} M41T83_ALARM_2_DATE_REG;


typedef struct M41T83_ALARM_2_HOUR_REG_s{
    uint8_t hour:4;
    uint8_t ten_hour:2;
    uint8_t unused:1;
    uint8_t RPT23:1;     // alarm repeat mode bit 2
}M41T83_ALARM_2_HOUR_REG_t;

typedef union M41T83_ALARM_2_HOUR_REG_u{
    M41T83_ALARM_2_HOUR_REG_t reg; uint8_t byte;
} M41T83_ALARM_2_HOUR_REG;


typedef struct M41T83_ALARM_2_MIN_REG_s{
    uint8_t min:4;
    uint8_t ten_min:3;
    uint8_t RPT22:1;     // alarm repeat mode bit 1
}M41T83_ALARM_2_MIN_REG_t;

typedef union M41T83_ALARM_2_MIN_REG_u{
    M41T83_ALARM_2_MIN_REG_t reg; uint8_t byte;
} M41T83_ALARM_2_MIN_REG;


typedef struct M41T83_ALARM_2_SEC_REG_s{
    uint8_t sec:4;
    uint8_t ten_sec:3;
    uint8_t RPT11:1;     // alarm repeat mode bit 0
} M41T83_ALARM_2_SEC_REG_t;

typedef union M41T83_ALARM_2_SEC_REG_u{
    M41T83_ALARM_2_SEC_REG_t reg; uint8_t byte;
} M41T83_ALARM_2_SEC_REG;



#endif