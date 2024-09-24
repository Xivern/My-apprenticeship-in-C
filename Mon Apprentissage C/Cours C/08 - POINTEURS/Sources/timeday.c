#include "..\Headers\timeday.h"

void minuteToHour(int *_ptrHours, int *_ptrMinute)
{
    *_ptrHours  = *_ptrMinute/60;
    *_ptrMinute = *_ptrMinute%60;
}