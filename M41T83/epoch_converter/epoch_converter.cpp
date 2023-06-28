#include <stdint.h>
#include "epoch_converter.h"
#include <stdbool.h>

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24
#define DAYS_PER_YEAR 365
#define DAYS_PER_4_YEARS (DAYS_PER_YEAR * 4 + 1)
#define DAYS_PER_100_YEARS (DAYS_PER_4_YEARS * 25 - 1)
#define DAYS_PER_400_YEARS (DAYS_PER_100_YEARS * 4 + 1)

bool is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void epoch_to_date_time(uint64_t epoch, EPOCH_Date *date, EPOCH_Time *time) {
    int days = epoch / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY);
    int seconds_remaining = epoch % (SECONDS_PER_MINUTE * MINUTES_PER_HOUR * HOURS_PER_DAY);

    // Calculate the time
    time->hour = seconds_remaining / (SECONDS_PER_MINUTE * MINUTES_PER_HOUR);
    seconds_remaining %= SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
    time->minute = seconds_remaining / SECONDS_PER_MINUTE;
    time->second = seconds_remaining % SECONDS_PER_MINUTE;

    // Calculate the date
    int years_elapsed = 1970;
    while (days >= (is_leap_year(years_elapsed) ? DAYS_PER_YEAR + 1 : DAYS_PER_YEAR)) {
        days -= (is_leap_year(years_elapsed) ? DAYS_PER_YEAR + 1 : DAYS_PER_YEAR);
        years_elapsed++;
    }
    date->year = years_elapsed;

    // Adjust for leap years
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(date->year)) {
        days_in_month[1] = 29;
    }

    date->month = 0;
    while (days >= days_in_month[date->month]) {
        days -= days_in_month[date->month];
        date->month++;
    }
    date->month++; // Adjust month to 1-indexed
    date->day = days + 1; // Adjust day to 1-indexed
}


