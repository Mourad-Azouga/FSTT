#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<time.h>
#include<windows.h>
/*USER INIT*/
struct User {
	int userID;
	char name[20];
	int phone;
	char prof[10];
	int bookings;
	struct TimeSlot* weeklyAppointments[6]; // For Monday to Friday
	struct User* next;
};

/*TIMESLOT INIT*/

struct Day {
    int dayOfWeek; // 0 for Monday, 1 for Tuesday, ..., 5 for Saturday
    struct TimeSlot* appointments;
    struct Day* next;
};

struct TimeSlot {
	int day;
	int startHour;
	int startMinute;
	int endHour;
	int endMinute;
	char name[100];
	struct TimeSlot* next;
};
/*USER.C*/
void createUser(struct User** users, const char* name, int phone, const char* prof);
struct User* findUser(struct User* users, const char* name);
void displayUserDetails(struct User* user);



/*APPO.C*/
struct TimeSlot* createTimeSlot(int day, int startH, int startM, int endH, int endM);
void makeAppointment(struct TimeSlot* day[6], struct User* users);
void deleteAppointment(struct TimeSlot* week[6], int day, int slotNumber);
void displayTimeSlots(struct TimeSlot* week[6]);


#endif /*HEADER_H*/

