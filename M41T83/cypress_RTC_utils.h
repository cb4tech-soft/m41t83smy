
#ifndef __CYPRESS_RTC_UTILS_H__
#define __CYPRESS_RTC_UTILS_H__

#include <sys/types.h>

#define CYPRESS_RTC_AM                 (0u)    /**< AM period of day */
#define CYPRESS_RTC_PM                 (1u)    /**< PM period of day */

#define CYPRESS_RTC_12_HOURS_FORMAT    (1) /**< The 12 hour (AM/PM) format */
#define CYPRESS_RTC_24_HOURS_FORMAT    (0) /**< The 24 hour format */

#define CYPRESS_RTC_DAYS_PER_WEEK       (7u)

#define CYPRESS_RTC_MONTHS_PER_YEAR     (12uL)

#define CYPRESS_RTC_HOURS_PER_DAY       (24uL)
#define CYPRESS_RTC_HOURS_PER_HALF_DAY  (12uL)

#define CYPRESS_RTC_SECONDS_PER_MINUTE  (60uL)
#define CYPRESS_RTC_SECONDS_PER_HOUR    (3600uL)
#define CYPRESS_RTC_SECONDS_PER_DAY     (24uL * 3600uL)

#define CYPRESS_RTC_SECONDS_PER_LEAP_YEAR    (366uL * 24uL * 3600uL)
#define CYPRESS_RTC_SECONDS_PER_NONLEAP_YEAR (365uL * 24uL * 3600uL)

#define CYPRESS_RTC_UNIX_TIME_PM        ((12uL * 3600uL) + 1uL)

#define CYPRESS_RTC_YEAR_0             (1970u)

#define CYPRESS_RTC_10_MONTH_OFFSET   (20u)
#define CYPRESS_RTC_MONTH_OFFSET      (16u)
#define CYPRESS_RTC_10_DAY_OFFSET     (28u)
#define CYPRESS_RTC_DAY_OFFSET        (24u)
#define CYPRESS_RTC_1000_YEAR_OFFSET  (12u)
#define CYPRESS_RTC_100_YEAR_OFFSET   (8u)
#define CYPRESS_RTC_10_YEAR_OFFSET    (4u)
#define CYPRESS_RTC_YEAR_OFFSET       (0u)



#define CYPRESS_RTC_10_MONTH_MASK          (0x00000001uL << CYPRESS_RTC_10_MONTH_OFFSET)
#define CYPRESS_RTC_MONTH_MASK             (0x0000000FuL << CYPRESS_RTC_MONTH_OFFSET)
#define CYPRESS_RTC_10_DAY_MASK            (0x00000003uL << CYPRESS_RTC_10_DAY_OFFSET)
#define CYPRESS_RTC_DAY_MASK               (0x0000000FuL << CYPRESS_RTC_DAY_OFFSET)
#define CYPRESS_RTC_1000_YEAR_MASK         (0x00000003uL << CYPRESS_RTC_1000_YEAR_OFFSET)
#define CYPRESS_RTC_100_YEAR_MASK          (0x0000000FuL << CYPRESS_RTC_100_YEAR_OFFSET)
#define CYPRESS_RTC_10_YEAR_MASK           (0x0000000FuL << CYPRESS_RTC_10_YEAR_OFFSET)
#define CYPRESS_RTC_YEAR_MASK              (0x0000000FuL << CYPRESS_RTC_YEAR_OFFSET)

#define  CYPRESS_RTC_MONTH_FULL_MASK       (CYPRESS_RTC_10_MONTH_MASK  | CYPRESS_RTC_MONTH_MASK)
#define  CYPRESS_RTC_DAY_FULL_MASK         (CYPRESS_RTC_10_DAY_MASK    | CYPRESS_RTC_DAY_MASK)
#define  CYPRESS_RTC_YEAR_FULL_MASK        (CYPRESS_RTC_1000_YEAR_MASK | CYPRESS_RTC_100_YEAR_MASK |\
                                                 CYPRESS_RTC_10_YEAR_MASK   | CYPRESS_RTC_YEAR_MASK)



/* Definition of time register fields */
#define CYPRESS_RTC_TIME_FORMAT_OFFSET     (23u)
#define CYPRESS_RTC_PERIOD_OF_DAY_OFFSET   (22u)
#define CYPRESS_RTC_10_HOURS_OFFSET        (20u)
#define CYPRESS_RTC_HOURS_OFFSET           (16u)
#define CYPRESS_RTC_10_MINUTES_OFFSET      (12u)
#define CYPRESS_RTC_MINUTES_OFFSET         (8u)
#define CYPRESS_RTC_10_SECONDS_OFFSET      (4u)
#define CYPRESS_RTC_SECONDS_OFFSET         (0u)

#define CYPRESS_RTC_TIME_FORMAT_MASK       (0x00000001uL << CYPRESS_RTC_TIME_FORMAT_OFFSET)
#define CYPRESS_RTC_PERIOD_OF_DAY_MASK     (0x00000001uL << CYPRESS_RTC_PERIOD_OF_DAY_OFFSET)
#define CYPRESS_RTC_10_HOURS_MASK          (0x00000003uL << CYPRESS_RTC_10_HOURS_OFFSET)
#define CYPRESS_RTC_HOURS_MASK             (0x0000000FuL << CYPRESS_RTC_HOURS_OFFSET)
#define CYPRESS_RTC_10_MINUTES_MASK        (0x00000007uL << CYPRESS_RTC_10_MINUTES_OFFSET)
#define CYPRESS_RTC_MINUTES_MASK           (0x0000000FuL << CYPRESS_RTC_MINUTES_OFFSET)
#define CYPRESS_RTC_10_SECONDS_MASK        (0x00000007uL << CYPRESS_RTC_10_SECONDS_OFFSET)
#define CYPRESS_RTC_SECONDS_MASK           (0x0000000FuL << CYPRESS_RTC_SECONDS_OFFSET)


/* DST DayOfWeek setting constants */
#define CYPRESS_RTC__SUNDAY 1
#define CYPRESS_RTC__MONDAY 2
#define CYPRESS_RTC__TUESDAY 3
#define CYPRESS_RTC__WEDNESDAY 4
#define CYPRESS_RTC__THURSDAY 5
#define CYPRESS_RTC__FRIDAY 6
#define CYPRESS_RTC__SATURDAY 7

/* DST Month setting constants */
#define CYPRESS_RTC__JAN 1
#define CYPRESS_RTC__FEB 2
#define CYPRESS_RTC__MAR 3
#define CYPRESS_RTC__APR 4
#define CYPRESS_RTC__MAY 5
#define CYPRESS_RTC__JUN 6
#define CYPRESS_RTC__JUL 7
#define CYPRESS_RTC__AUG 8
#define CYPRESS_RTC__SEP 9
#define CYPRESS_RTC__OCT 10
#define CYPRESS_RTC__NOV 11
#define CYPRESS_RTC__DEC 12
/**
* \defgroup group_rtc_month Month definitions
* \{
* Constants definition for Months
*/
#define CYPRESS_RTC_JANUARY    (CYPRESS_RTC__JAN)    /**< Sequential number of January in the year */
#define CYPRESS_RTC_FEBRUARY   (CYPRESS_RTC__FEB)    /**< Sequential number of February in the year */
#define CYPRESS_RTC_MARCH      (CYPRESS_RTC__MAR)    /**< Sequential number of March in the year */
#define CYPRESS_RTC_APRIL      (CYPRESS_RTC__APR)    /**< Sequential number of April in the year */
#define CYPRESS_RTC_MAY        (CYPRESS_RTC__MAY)    /**< Sequential number of May in the year */
#define CYPRESS_RTC_JUNE       (CYPRESS_RTC__JUN)    /**< Sequential number of June in the year */
#define CYPRESS_RTC_JULY       (CYPRESS_RTC__JUL)    /**< Sequential number of July in the year */
#define CYPRESS_RTC_AUGUST     (CYPRESS_RTC__AUG)    /**< Sequential number of August in the year */
#define CYPRESS_RTC_SEPTEMBER  (CYPRESS_RTC__SEP)    /**< Sequential number of September in the year */
#define CYPRESS_RTC_OCTOBER    (CYPRESS_RTC__OCT)    /**< Sequential number of October in the year */
#define CYPRESS_RTC_NOVEMBER   (CYPRESS_RTC__NOV)    /**< Sequential number of November in the year */
#define CYPRESS_RTC_DECEMBER   (CYPRESS_RTC__DEC)    /**< Sequential number of December in the year */
/** \} group_rtc_month */

#define CYPRESS_RTC_DAYS_IN_JANUARY     (31u)    /**< Number of days in January  */
#define CYPRESS_RTC_DAYS_IN_FEBRUARY    (28u)    /**< Number of days in February */
#define CYPRESS_RTC_DAYS_IN_MARCH       (31u)    /**< Number of days in March */
#define CYPRESS_RTC_DAYS_IN_APRIL       (30u)    /**< Number of days in April */
#define CYPRESS_RTC_DAYS_IN_MAY         (31u)    /**< Number of days in May */
#define CYPRESS_RTC_DAYS_IN_JUNE        (30u)    /**< Number of days in June */
#define CYPRESS_RTC_DAYS_IN_JULY        (31u)    /**< Number of days in July */
#define CYPRESS_RTC_DAYS_IN_AUGUST      (31u)    /**< Number of days in August */
#define CYPRESS_RTC_DAYS_IN_SEPTEMBER   (30u)    /**< Number of days in September */
#define CYPRESS_RTC_DAYS_IN_OCTOBER     (31u)    /**< Number of days in October */
#define CYPRESS_RTC_DAYS_IN_NOVEMBER    (30u)    /**< Number of days in November */
#define CYPRESS_RTC_DAYS_IN_DECEMBER    (31u)    /**< Number of days in December */

extern const uint16_t CYPRESS_RTC_daysBeforeMonthTbl[CYPRESS_RTC_MONTHS_PER_YEAR];
extern const uint8_t  CYPRESS_RTC_daysInMonthTbl[CYPRESS_RTC_MONTHS_PER_YEAR];



typedef struct
{
    uint32_t time;        /**< Time in the format used in API*/
    uint32_t date;        /**< Date in the format used in API*/
    uint32_t dayOfWeek;   /**< Day of the week, see \ref group_rtc_day_of_the_week */
    uint32_t status;      /**< RTC status, see \ref group_rtc_status */
}CYPRESS_RTC_DATE_TIME;

/*
* CYPRESS_RTC_DST_TIME structure is the data structure that is used to 
* save time and date values for Daylight Savings Time Start and Stop 
* (RTC_dstTimeDateStart and RTC_dstTimeDateStop)
*/
typedef struct
{
    uint32_t hour;          /**< Hour value */
    uint32_t dayOfWeek;     /**< Day of the week, see \ref group_rtc_day_of_the_week */
    uint32_t dayOfMonth;    /**< Day of the month */
    uint32_t weekOfMonth;   /**< Week of the month, see \ref group_rtc_dst_week_of_month */
    uint32_t month;         /**< Month value, see \ref group_rtc_month */
    uint8_t  timeFormat;    /**< The DST operation mode, see \ref 
                               CYPRESS_RTC_DST_DATETYPE_ENUM */
}CYPRESS_RTC_DST_TIME;


uint64_t CYPRESS_RTC_DateTimeToUnix(uint32_t inputDate, uint32_t inputTime);


/*******************************************************************************
* Function Name: CYPRESS_RTC_ConstructTime
****************************************************************************//**
*
* Returns the time in the format used in APIs from individual elements
* passed (hour, min, sec etc)
*
* \param timeFormat
* The 12/24 hours time format, see \ref group_rtc_hour_format
*
* \param stateAmPm 
* The AM/PM status, see \ref group_rtc_am_pm.
*
* \param hour
* The hour.
*
* \param min
* The minute.
*
* \param sec
* The second.
*
* \return
* Time in the format used in API.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_ConstructTime(uint32_t timeFormat, uint32_t stateAmPm, 
                                                       uint32_t hour, uint32_t min, uint32_t sec)
{
    uint32_t retVal;

    retVal  = timeFormat << CYPRESS_RTC_TIME_FORMAT_OFFSET;
    retVal |= stateAmPm << CYPRESS_RTC_PERIOD_OF_DAY_OFFSET;

    retVal |= (hour / 10u) << CYPRESS_RTC_10_HOURS_OFFSET;
    retVal |= (hour % 10u) << CYPRESS_RTC_HOURS_OFFSET;

    retVal |= (min / 10u) << CYPRESS_RTC_10_MINUTES_OFFSET;
    retVal |= (min % 10u) << CYPRESS_RTC_MINUTES_OFFSET;

    retVal |= (sec / 10u) << CYPRESS_RTC_10_SECONDS_OFFSET;
    retVal |= (sec % 10u) << CYPRESS_RTC_SECONDS_OFFSET;

    return (retVal);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_ConstructDate
****************************************************************************//**
*
*  Returns the date in the format used in APIs from individual elements
*  passed (day. Month and year)
*
* \param month
* The month.
*
* \param day
* The day.
*
* \param year
* The year.
*
* \return
* The date in the format used in API.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_ConstructDate(uint32_t month, uint32_t day, uint32_t year)
{
    uint32_t retVal;
    uint32_t tmpVal = year;

    retVal  = (month / 10u) << CYPRESS_RTC_10_MONTH_OFFSET;
    retVal |= (month % 10u) << CYPRESS_RTC_MONTH_OFFSET;

    retVal |= (day / 10u) << CYPRESS_RTC_10_DAY_OFFSET;
    retVal |= (day % 10u) << CYPRESS_RTC_DAY_OFFSET;

    retVal |= (year / 1000u) << CYPRESS_RTC_1000_YEAR_OFFSET;
    tmpVal %= 1000u;

    retVal |= (tmpVal / 100u) << CYPRESS_RTC_100_YEAR_OFFSET;
    tmpVal %= 100u;

    retVal |= (tmpVal / 10u) << CYPRESS_RTC_10_YEAR_OFFSET;
    retVal |= (tmpVal % 10u) << CYPRESS_RTC_YEAR_OFFSET;

    return (retVal);
}



/*******************************************************************************
* Function Name: CYPRESS_RTC_GetYear
****************************************************************************//**
*
* Returns the year value from the date value that is passed as parameter.
*
* \param date
* The date value.
*
* \return
* The year value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetYear(uint32_t date)
{
    uint32_t retVal;

    retVal  = ((date & CYPRESS_RTC_1000_YEAR_MASK) >> CYPRESS_RTC_1000_YEAR_OFFSET) * 1000u;
    retVal += ((date & CYPRESS_RTC_100_YEAR_MASK) >> CYPRESS_RTC_100_YEAR_OFFSET) * 100u;
    retVal += ((date & CYPRESS_RTC_10_YEAR_MASK) >> CYPRESS_RTC_10_YEAR_OFFSET) * 10u;
    retVal += (date & CYPRESS_RTC_YEAR_MASK) >> CYPRESS_RTC_YEAR_OFFSET;

    return (retVal);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_IsBitSet
****************************************************************************//**
*
* Checks the state of a bit passed through parameter.
*
* \param var
* The variable to be checked.
*
* \param mask
* The mask for a bit to be checked.
*
* \return
*  0u - Bit is not set. <br> 1u - Bit is set.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_IsBitSet(uint32_t var, uint32_t mask)
{
    return ((mask == (var & mask)) ? 1Lu : 0Lu);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_LeapYear
****************************************************************************//**
*
* Checks whether the year passed through the parameter is leap or no.
*
* \param year
* The year to be checked.
*
* \return
* 0u - The year is not leap <br> 1u - The year is leap.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_LeapYear(uint32_t year)
{
    uint32_t retVal;

    if(((0u == (year % 4Lu)) && (0u != (year % 100Lu))) || (0u == (year % 400Lu)))
    {
        retVal = 1uL;
    }
    else
    {
        retVal = 0uL;
    }

    return(retVal);
}



/*******************************************************************************
* Function Name: CYPRESS_RTC_GetMonth
****************************************************************************//**
*
* Returns the month value from the date value that is passed as parameter.
*
* \param date
* The date value.
*
* \return
* The month value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetMonth(uint32_t date)
{
    uint32_t retVal;

    retVal  = ((date & CYPRESS_RTC_10_MONTH_MASK) >> CYPRESS_RTC_10_MONTH_OFFSET) * 10u;
    retVal += (date & CYPRESS_RTC_MONTH_MASK) >> CYPRESS_RTC_MONTH_OFFSET;

    return (retVal);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_DaysBeforeMonth
****************************************************************************//**
*
* Calculates how many days elapsed from the beginning of the year to the
* beginning of the current month.
*
* \param month
* A month of a year, see \ref group_rtc_month
*
* \param year
* A year value.
*
* \return
* A number of days elapsed from the beginning of the year to the
* beginning of the current month passed through the parameters.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_DaysBeforeMonth(uint32_t month, uint32_t year)
{
    uint32_t retVal;

    retVal = CYPRESS_RTC_daysBeforeMonthTbl[month - 1u];
    if((0u != CYPRESS_RTC_LeapYear(year)) && (month > (uint32_t)CYPRESS_RTC_FEBRUARY))
    {
        retVal++;
    }

    return(retVal);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_GetAmPm
****************************************************************************//**
*
* Returns the AM/PM status from the time value that is passed as parameter.
*
* \param inputTime
* The time value.
*
* \return
* The am/pm period of day, see \ref group_rtc_am_pm.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetAmPm(uint32_t inputTime)
{
    return (CYPRESS_RTC_IsBitSet(inputTime, CYPRESS_RTC_PERIOD_OF_DAY_MASK));
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_GetDay
****************************************************************************//**
*
* Returns the day value from the date value that is passed as parameter.
*
* \param date
* The date value.
*
* \return
* The day value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetDay(uint32_t date)
{
    uint32_t retVal;

    retVal  = ((date & CYPRESS_RTC_10_DAY_MASK) >> CYPRESS_RTC_10_DAY_OFFSET) * 10u;
    retVal += (date & CYPRESS_RTC_DAY_MASK) >> CYPRESS_RTC_DAY_OFFSET;

    return (retVal);
}



/*******************************************************************************
* Function Name: CYPRESS_RTC_GetHours
****************************************************************************//**
*
* Returns the hours value from the time value that is passed as a/the parameter.
*
* \param inputTime
* The time value.
*
* \return
* The hours value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetHours(uint32_t inputTime)
{
    uint32_t retVal;

    retVal  = ((inputTime & CYPRESS_RTC_10_HOURS_MASK) >> CYPRESS_RTC_10_HOURS_OFFSET) * 10u;
    retVal += (inputTime & CYPRESS_RTC_HOURS_MASK) >> CYPRESS_RTC_HOURS_OFFSET;

    return (retVal);
}



/*******************************************************************************
* Function Name: CYPRESS_RTC_GetTimeFormat
****************************************************************************//**
* \internal
* Reads the time format from the variable that contains time in the
* "HH:MM:SS" format.
*
* \param inputTime
* The current value of the time in the "HH:MM:SS" format.
*
* \return
* Returns the time format that is stored in the variable that contains time
* in the "HH:MM:SS" format.
* \endinternal
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetTimeFormat(uint32_t inputTime)
{
    return ((0uL != (inputTime & (1uL << CYPRESS_RTC_TIME_FORMAT_OFFSET))) ?
                                       (uint32_t)CYPRESS_RTC_12_HOURS_FORMAT :
                                       (uint32_t)CYPRESS_RTC_24_HOURS_FORMAT);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_GetSecond
****************************************************************************//**
*
* Returns the seconds value from the time value that is passed as a/the 
* parameter.
*
* \param inputTime
* The time value.
*
* \return
* The seconds value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetSecond(uint32_t inputTime)
{
    uint32_t retVal;

    retVal  = ((inputTime & CYPRESS_RTC_10_SECONDS_MASK) >> CYPRESS_RTC_10_SECONDS_OFFSET) * 10u;
    retVal += (inputTime & CYPRESS_RTC_SECONDS_MASK) >> CYPRESS_RTC_SECONDS_OFFSET;

    return (retVal);
}


/*******************************************************************************
* Function Name: CYPRESS_RTC_GetMinutes
****************************************************************************//**
*
* Returns the minutes value from the time value that is passed as a/the 
* parameter.
*
* \param inputTime
* The time value.
*
* \return
* The minutes value.
*
*******************************************************************************/
static inline uint32_t CYPRESS_RTC_GetMinutes(uint32_t inputTime)
{
    uint32_t retVal;

    retVal  = ((inputTime & CYPRESS_RTC_10_MINUTES_MASK) >> CYPRESS_RTC_10_MINUTES_OFFSET) * 10u;
    retVal += (inputTime & CYPRESS_RTC_MINUTES_MASK) >> CYPRESS_RTC_MINUTES_OFFSET;

    return (retVal);
}



#endif /* __CYPRESS_RTC_UTILS_H__ */