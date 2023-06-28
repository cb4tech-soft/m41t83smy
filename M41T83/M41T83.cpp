#include <Arduino.h>
#include <Wire.h>
#include "M41T83.h"
#include "M41T83_def.h"
#include "cypress_RTC_utils.h"
#include "epoch_converter/epoch_converter.h"

uint8_t M41T83_read_register(uint8_t register_address)
{
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(register_address);

    int error = Wire.endTransmission(false);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_read_register: Error, no device found at address 0x" + String(M41T83_ADDRESS, HEX));
    }
    uint8_t data = 0;
    int n = Wire.requestFrom(M41T83_ADDRESS, 1);
    if (n != 1)
    {
        SERIALDBG.println( "M41T83_read_register: Error, no device found at address 0x" + String(M41T83_ADDRESS, HEX));
    }
    else
    {
        data = Wire.read();
    }
    return data;
}

uint8_t M41T83_write_register(uint8_t register_address, uint8_t data)
{
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(register_address);
    Wire.write(data);
    int error = Wire.endTransmission(true);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_write_register: Error, no device found at address 0x" + String(M41T83_ADDRESS, HEX));
    }
    return error;
}


// from doc: Upon initial power-up, the user should set the ST bit to a '1,' then immediately reset the ST
// bit to 0. This provides an additional “kick-start” to the oscillator circuit

uint8_t M41T83_KickStart_ST_bit()
{

    uint8_t regAddr = M41T83_ADDR_ST;
    uint8_t dataValue = M41T83_read_register(regAddr);
    M41T83_SEC_REG stBitReg;
    stBitReg.byte = dataValue;
    stBitReg.reg.ST = 1;
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(regAddr);
    Wire.write(stBitReg.byte);
    uint8_t error = Wire.endTransmission(true);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_KickStart_ST_bit: Error, ST : 1");
    }
    delay(20);
    stBitReg.reg.ST = 0;

    
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(regAddr);
    Wire.write(stBitReg.byte);
    error = Wire.endTransmission(true);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_KickStart_ST_bit: Error, ST : 0");
    }
    delay(10);
    return error;
}

M41T83_MEMORY M41T83_read_memory()
{
    M41T83_MEMORY memory;
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(M41T83_ADDR_TENTH_SECONDS);
    int error = Wire.endTransmission(false);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_read_memory: Error, read memory");
    }
    int n = Wire.requestFrom(M41T83_ADDRESS, M41T83_REG_SIZE);
    if (n != M41T83_REG_SIZE)
    {
        SERIALDBG.println( "M41T83_read_memory: Error, " + String(n) + " bytes read, expected " + String(M41T83_REG_SIZE));
    }
    else
    {
        int i = 0;
        while (i < M41T83_REG_SIZE)
        {
            memory.bytes[i] = Wire.read();
            i++;
        }
    }
    return memory;
}

uint8_t M41T83_clear_HT_bit()
{
    uint8_t regAddr = M41T83_ADDR_HT;
    uint8_t dataValue = M41T83_read_register(regAddr);
    M41T83_ALARM_1_HOUR_REG htBitReg;
    htBitReg.byte = 0;
    htBitReg.reg.HT = 0;
    Wire.beginTransmission(M41T83_ADDRESS);
    Wire.write(regAddr);
    Wire.write(htBitReg.byte);
    uint8_t error = Wire.endTransmission(true);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_clear_HT_bit: Error, HT : 0");
    }
    delay(10);
    return error;
}

uint8_t M41T83_set_time(uint8_t hour, uint8_t minute, uint8_t second, uint8_t centh)
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();

    memory.reg.tenth_reg.reg.centh = centh%10;
    memory.reg.tenth_reg.reg.tenth = centh/10;
    
    memory.reg.second_reg.reg.seconds = second%10;
    memory.reg.second_reg.reg.ten_seconds = second/10;

    memory.reg.minute_reg.reg.minutes = minute%10;
    memory.reg.minute_reg.reg.ten_minutes = minute/10;

    memory.reg.hour_reg.reg.hours = hour%10;
    memory.reg.hour_reg.reg.ten_hours = hour/10;

    uint8_t error = M41T83_write_register(M41T83_ADDR_TENTH_SECONDS, memory.reg.tenth_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_time: Error, write tenth seconds");
    }
    error = M41T83_write_register(M41T83_ADDR_SECONDS, memory.reg.second_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_time: Error, write seconds");
    }
    error = M41T83_write_register(M41T83_ADDR_MINUTES, memory.reg.minute_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_time: Error, write minutes");
    }
    error = M41T83_write_register(M41T83_ADDR_HOURS, memory.reg.hour_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_time: Error, write hours");
    }
    return error;
}

uint8_t M41T83_set_date(uint8_t day, uint8_t month, uint8_t years, uint8_t century)
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();

    memory.reg.day_month_reg.reg.day_of_month = day%10;
    memory.reg.day_month_reg.reg.ten_day_of_month = day/10;
    
    memory.reg.month_reg.reg.months = month%10;
    memory.reg.month_reg.reg.ten_months = month/10;

    memory.reg.year_reg.reg.years = years%10;
    memory.reg.year_reg.reg.ten_years = years/10;
    SERIALDBG.printf("M41T83_set_date:%d -> ten years: %d - years:%d\n", years, memory.reg.year_reg.reg.ten_years, memory.reg.year_reg.reg.years);

    memory.reg.hour_reg.reg.century = century;
    

    uint8_t error = M41T83_write_register(M41T83_ADDR_DATE, memory.reg.day_month_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_date: Error, write day of month");
    }
    error = M41T83_write_register(M41T83_ADDR_MONTH, memory.reg.month_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_date: Error, write month");
    }
    error = M41T83_write_register(M41T83_ADDR_YEAR, memory.reg.year_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_date: Error, write year");
    }
    error = M41T83_write_register(M41T83_ADDR_HOURS, memory.reg.hour_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_date: Error, write hours");
    }

    return error;
}

uint8_t M41T83_set_dayOfWeek(uint8_t dayOfWeek)
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();

    memory.reg.day_week_reg.reg.day_of_week = dayOfWeek;

    uint8_t error = M41T83_write_register(M41T83_ADDR_DAY, memory.reg.day_week_reg.byte);
    if (error != 0)
    {
        SERIALDBG.println( "M41T83_set_dayOfWeek: Error, write day of week");
    }
    return error;
}

void M41T83_print_time()
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();
    SERIALDBG.print("Time: ");
    SERIALDBG.print(memory.reg.hour_reg.reg.ten_hours);
    SERIALDBG.print(memory.reg.hour_reg.reg.hours);
    SERIALDBG.print(":");
    SERIALDBG.print(memory.reg.minute_reg.reg.ten_minutes);
    SERIALDBG.print(memory.reg.minute_reg.reg.minutes);
    SERIALDBG.print(":");
    SERIALDBG.print(memory.reg.second_reg.reg.ten_seconds);
    SERIALDBG.print(memory.reg.second_reg.reg.seconds);
    SERIALDBG.print(".");
    SERIALDBG.print(memory.reg.tenth_reg.reg.tenth);
    SERIALDBG.println(memory.reg.tenth_reg.reg.centh);
}

void M41T83_print_time(M41T83_MEMORY *memory)
{
    SERIALDBG.print("Time: ");
    SERIALDBG.print(memory->reg.hour_reg.reg.ten_hours);
    SERIALDBG.print(memory->reg.hour_reg.reg.hours);
    SERIALDBG.print(":");
    SERIALDBG.print(memory->reg.minute_reg.reg.ten_minutes);
    SERIALDBG.print(memory->reg.minute_reg.reg.minutes);
    SERIALDBG.print(":");
    SERIALDBG.print(memory->reg.second_reg.reg.ten_seconds);
    SERIALDBG.print(memory->reg.second_reg.reg.seconds);
    SERIALDBG.print(".");
    SERIALDBG.print(memory->reg.tenth_reg.reg.tenth);
    SERIALDBG.println(memory->reg.tenth_reg.reg.centh);
}

void M41T83_print_date()
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();
    SERIALDBG.print("Date: ");
    switch (memory.reg.day_week_reg.reg.day_of_week)
    {
        case Monday:
            SERIALDBG.print("Monday");
            break;
        case Tuesday:
            SERIALDBG.print("Tuesday");
            break;
        case Wednesday:
            SERIALDBG.print("Wednesday");
            break;
        case Thursday:
            SERIALDBG.print("Thursday");
            break;
        case Friday:
            SERIALDBG.print("Friday");
            break;
        case Saturday:
            SERIALDBG.print("Saturday");
            break;
        case Sunday:
            SERIALDBG.print("Sunday");
            break;
        default:
            SERIALDBG.print("Unknown");
            break;
    } 
    SERIALDBG.print(" ");
    SERIALDBG.print(memory.reg.day_month_reg.reg.ten_day_of_month);
    SERIALDBG.print(memory.reg.day_month_reg.reg.day_of_month);
    SERIALDBG.print("/");
    SERIALDBG.print(memory.reg.month_reg.reg.ten_months);
    SERIALDBG.print(memory.reg.month_reg.reg.months);
    SERIALDBG.print("/");
    switch (memory.reg.hour_reg.reg.century)
    {
    case C20:
        SERIALDBG.print("20");
        break;
    case C21:
        SERIALDBG.print("21");
        break;
    case C22:
        SERIALDBG.print("22");
        break;
    case C23:
        SERIALDBG.print("23");
        break;
    }
    SERIALDBG.print(memory.reg.year_reg.reg.ten_years);
    SERIALDBG.println(memory.reg.year_reg.reg.years);
}

uint64_t M41T83_get_unix_time()
{
    M41T83_MEMORY memory;
    memory = M41T83_read_memory();
    int hour = memory.reg.hour_reg.reg.ten_hours * 10 + memory.reg.hour_reg.reg.hours;
    int minute = memory.reg.minute_reg.reg.ten_minutes * 10 + memory.reg.minute_reg.reg.minutes;
    int second = memory.reg.second_reg.reg.ten_seconds * 10 + memory.reg.second_reg.reg.seconds;
    uint32_t cypressTime = CYPRESS_RTC_ConstructTime(0, 0, hour, minute, second);
    int year = 2000 + memory.reg.year_reg.reg.ten_years * 10 + memory.reg.year_reg.reg.years;
    int month = memory.reg.month_reg.reg.ten_months * 10 + memory.reg.month_reg.reg.months;
    int day = memory.reg.day_month_reg.reg.ten_day_of_month * 10 + memory.reg.day_month_reg.reg.day_of_month;
    uint32_t cypressDate = CYPRESS_RTC_ConstructDate(month, day, year);
    uint64_t unixTime = CYPRESS_RTC_DateTimeToUnix(cypressDate, cypressTime);
    return unixTime;
}

uint64_t M41T83_get_unix_time(M41T83_MEMORY *memory)
{
    int hour = memory->reg.hour_reg.reg.ten_hours * 10 + memory->reg.hour_reg.reg.hours;
    int minute = memory->reg.minute_reg.reg.ten_minutes * 10 + memory->reg.minute_reg.reg.minutes;
    int second = memory->reg.second_reg.reg.ten_seconds * 10 + memory->reg.second_reg.reg.seconds;
    uint32_t cypressTime = CYPRESS_RTC_ConstructTime(0, 0, hour, minute, second);
    int year = 2000 + memory->reg.year_reg.reg.ten_years * 10 + memory->reg.year_reg.reg.years;
    int month = memory->reg.month_reg.reg.ten_months * 10 + memory->reg.month_reg.reg.months;
    int day = memory->reg.day_month_reg.reg.ten_day_of_month * 10 + memory->reg.day_month_reg.reg.day_of_month;
    uint32_t cypressDate = CYPRESS_RTC_ConstructDate(month, day, year);
    uint64_t unixTime = CYPRESS_RTC_DateTimeToUnix(cypressDate, cypressTime);

    return unixTime;
}


void M41T83_set_unix_time(uint64_t epoch)
{
    EPOCH_Date date;
    EPOCH_Time time;
    epoch_to_date_time(epoch, &date, &time);
    Serial0.printf("\nDate: %d/%d/%d Time: %d:%d:%d Epoch: %lld \n", date.year, date.month, date.day, time.hour, time.minute, time.second, epoch);
    int16_t year = date.year - 2000;
    if (year < 0)
    {
        year = 0;
    }
    uint8_t century = C20;
    if (year >= 300)
    {
        century = C23;
        year -= 300;
    }
    else if (year >= 200)
    {
        century = C22;
        year -= 200;
    }
    else if (year >= 100)
    {
        century = C21;
        year -= 100;
    }
    

    M41T83_set_date(date.day, date.month, year, century);
    delay(100);
    M41T83_set_time(time.hour, time.minute, time.second, 0);
}