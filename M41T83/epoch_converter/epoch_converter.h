#ifndef EPOCH_CONVERTER_H
#define EPOCH_CONVERTER_H
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint16_t year;
    uint16_t month;
    uint16_t day;
} EPOCH_Date;

typedef struct {
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
} EPOCH_Time;

bool is_leap_year(int year);
void epoch_to_date_time(uint64_t epoch, EPOCH_Date *date, EPOCH_Time *time);




#endif