#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<time.h>
/*USER INIT*/
struct User {
    int userID;
    char name[10];
    int phone;
    char prof[10];
    struct User* next;
};
/*USER.C*/
void createUser(struct User** users, const char* name, int phone, const char* prof);
struct User* findUser(struct User* users, const char* name);
void displayUserDetails(struct User* user);

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
void makeAppointment(struct TimeSlot* timeSlots, struct User* users);
void deleteAppointment(struct TimeSlot* timeSlots, int slotNumber);
void displayTimeSlots(struct TimeSlot* timeSlots);
void displayTimeSlotsWithAppointments(struct TimeSlot* timeSlots);


#endif /*HEADER_H*/

