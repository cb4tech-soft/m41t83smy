
#include "cypress_RTC_utils.h"


const uint16_t CYPRESS_RTC_daysBeforeMonthTbl[CYPRESS_RTC_MONTHS_PER_YEAR] = {
                                                 (0u), /* JANUARY */
                                                 (0u + 31u), /* FEBRUARY */
                                                 (0u + 31u + 28u), /* MARCH */
                                                 (0u + 31u + 28u + 31u), /* APRIL */
                                                 (0u + 31u + 28u + 31u + 30u), /* MAY */
                                                 (0u + 31u + 28u + 31u + 30u + 31u), /* JUNE */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u), /* JULY */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u + 31u), /* AUGUST */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u + 31u + 31u), /* SEPTEMBER */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u + 31u + 31u + 30u), /* OCTOBER */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u + 31u + 31u + 30u + 31u), /* NOVEMBER */
                                                 (0u + 31u + 28u + 31u + 30u + 31u + 30u + 31u + 31u + 30u + 31u + 30u)}; /* DECEMBER */

const uint8_t CYPRESS_RTC_daysInMonthTbl[CYPRESS_RTC_MONTHS_PER_YEAR] = {CYPRESS_RTC_DAYS_IN_JANUARY,
                                                                                 CYPRESS_RTC_DAYS_IN_FEBRUARY,
                                                                                 CYPRESS_RTC_DAYS_IN_MARCH,
                                                                                 CYPRESS_RTC_DAYS_IN_APRIL,
                                                                                 CYPRESS_RTC_DAYS_IN_MAY,
                                                                                 CYPRESS_RTC_DAYS_IN_JUNE,
                                                                                 CYPRESS_RTC_DAYS_IN_JULY,
                                                                                 CYPRESS_RTC_DAYS_IN_AUGUST,
                                                                                 CYPRESS_RTC_DAYS_IN_SEPTEMBER,
                                                                                 CYPRESS_RTC_DAYS_IN_OCTOBER,
                                                                                 CYPRESS_RTC_DAYS_IN_NOVEMBER,
                                                                                 CYPRESS_RTC_DAYS_IN_DECEMBER};


/*******************************************************************************
* Function Name: CYPRESS_RTC_DateTimeToUnix
****************************************************************************//**
*
* This is an internal function to convert the date and time from the regular 
* time format into the UNIX time format.
*
* \param inputDate
* The date in the selected in the customizer "date format"
*
* \param inputTime
* The time in the defined "time format"
*
* \return
* Returns the date and time in the UNIX format
*
*******************************************************************************/
uint64_t CYPRESS_RTC_DateTimeToUnix(uint32_t inputDate, uint32_t inputTime)
{
    uint32_t i;
    uint32_t tmpYear;
    uint32_t tmpMonth;
    uint32_t tmpVal;
    uint64_t unixTime;

    unixTime = 0u;
    tmpYear = CYPRESS_RTC_GetYear(inputDate);

    /* Calculate seconds from epoch start up to (but not including) current year */
    for(i = CYPRESS_RTC_YEAR_0; i < tmpYear; i++)
    {
        if(0u != CYPRESS_RTC_LeapYear(i))
        {
            unixTime += CYPRESS_RTC_SECONDS_PER_LEAP_YEAR;
        }
        else
        {
            unixTime += CYPRESS_RTC_SECONDS_PER_NONLEAP_YEAR;
        }
    }

    /* Calculates how many seconds had elapsed in this year prior to the current month */
    tmpMonth = CYPRESS_RTC_GetMonth(inputDate);
    tmpVal = CYPRESS_RTC_DaysBeforeMonth(tmpMonth, tmpYear);

    /* Calculates how many seconds are in current month days prior to today */
    unixTime += (uint64_t) tmpVal * CYPRESS_RTC_SECONDS_PER_DAY;
    unixTime += ((uint64_t) CYPRESS_RTC_GetDay(inputDate) - 1u) * CYPRESS_RTC_SECONDS_PER_DAY;

    /* Calculates how many seconds have elapsed today up to the current hour */
    tmpVal = CYPRESS_RTC_GetHours(inputTime);
    if ((uint32_t)CYPRESS_RTC_24_HOURS_FORMAT != CYPRESS_RTC_GetTimeFormat(inputTime))
    {
        uint32_t curAmpm;

        curAmpm = CYPRESS_RTC_GetAmPm(inputTime);

        /* Add 12 hours as it is past midday period */
        if (((uint32_t)CYPRESS_RTC_AM != curAmpm) && (tmpVal < 12u))
        {
            tmpVal += CYPRESS_RTC_HOURS_PER_HALF_DAY;
        }
        /* Set hours to zero as it is a midnight */
        else if (((uint32_t)CYPRESS_RTC_AM == curAmpm) && (tmpVal == 12u))
        {
            tmpVal = 0U;
        }
        else
        {
            /* Do nothing */
        }
    }
    unixTime += (uint64_t)tmpVal * CYPRESS_RTC_SECONDS_PER_HOUR;

    /* Calculates how many seconds have elapsed today up to the current minute */
    unixTime += ((uint64_t) CYPRESS_RTC_GetMinutes(inputTime)) * CYPRESS_RTC_SECONDS_PER_MINUTE;

    /* Add remaining seconds of current minute */
    unixTime += CYPRESS_RTC_GetSecond(inputTime);

    return(unixTime);
}