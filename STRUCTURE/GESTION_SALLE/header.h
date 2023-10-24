#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<time.h>
/*TIMESLOT INIT*/
struct TimeSlot {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    char name[100];
    struct TimeSlot* next;
};

/*APPO.C*/
struct TimeSlot* createTimeSlot(int startH, int startM, int endH, int endM);
void makeAppointment(struct TimeSlot* timeSlots);
void deleteAppointment(struct TimeSlot* timeSlots, int slotNumber);
void displayTimeSlots(struct TimeSlot* timeSlots);
void displayTimeSlotsWithAppointments(struct TimeSlot* timeSlots);


#endif /*HEADER_H*/

