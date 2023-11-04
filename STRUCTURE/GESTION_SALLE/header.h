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
	char name[100];
	char phone[19];
	char prof[100];
	int bookings;
	struct TimeSlot* weeklyAppointments[6]; // For Monday to Saturday 6 fiha gher 2
	struct User* next;
};

/*TIMESLOT INIT*/

struct TimeSlot {//Don't group the time, for future use
	int day;
	int startHour;
	int startMinute;
	int endHour;
	int endMinute;
	char name[100];
	struct TimeSlot* next;
};

struct DateTime {//will be used to eliminate past time appointments !IMPORTANT
    char timeString[9];
    int dayIndex;
    int currentHour; // Add a member to store the current hour
    int currentMinute; // Add a member to store the current minute
};
/*MAIN.C*/
struct DateTime printCurrentTimeAndDay();
void displayTimeSlots(struct TimeSlot* week[6]);

/*USER.C*/
void createUser(struct User** users, const char* name, const char* phone, const char* prof);
struct User* findUser(struct User* users, const char* name);
void displayUserDetails(struct User* user);
void deleteUser(struct User** users, const char* name);


/*APPO.C*/
struct TimeSlot* createTimeSlot(int day, int startH, int startM, int endH, int endM);
void makeAppointment(struct TimeSlot* day[6], struct User* users);
void deleteAppointment(struct TimeSlot* week[6], int day, int slotNumber);
void displayTimeSlots(struct TimeSlot* week[6]);


#endif /*HEADER_H*/

