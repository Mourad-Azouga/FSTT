#include "header.h"

struct TimeSlot* createTimeSlot(int day, int startH, int startM, int endH, int endM) {
	struct TimeSlot* newSlot = (struct TimeSlot*)malloc(sizeof(struct TimeSlot));
	if (newSlot == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newSlot->day = day;	
	newSlot->startHour = startH;
	newSlot->startMinute = startM;
	newSlot->endHour = endH;
	newSlot->endMinute = endM;
	strcpy(newSlot->name, "Available"); //Set name to "Available" for init
	newSlot->next = NULL;

	return newSlot;
}
//----------------------------------------------------------------------------------------------------------------------
// Function to make an appointment
void makeAppointment(struct TimeSlot* day[6], struct User* users) {
    // Display available time slots
    printf("Available Time Slots:\n");
    displayTimeSlots(day);

    // Ask the user to enter their name
    char userName[100];
    printf("Enter your name: ");
    if (fgets(userName, sizeof(userName), stdin) != NULL) {
        strtok(userName, "\n"); // Remove newline character

        // Check if the user exists
        struct User* user = findUser(users, userName);

        if (user == NULL) {
            printf("User '%s' does not exist. Please create a user first.\n", userName);
            return;
        }

        // Ask the user to choose a day and a time slot
        int chosenDay;
        int chosenSlot;
        char input[100];

        printf("Enter the number of the day (1-6) you want to make an appointment: ");
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &chosenDay) != 1 || chosenDay < 1 || chosenDay > 6) {
                printf("Invalid input. Please enter a valid day (1-6).\n");
                return;
            }

            printf("Enter the number of the time slot you want to reserve (1-5): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1 || chosenSlot > 5) {
                    printf("Invalid input. Please enter a valid time slot number (1-5).\n");
                    return;
                }

                // Check if the selected time slot is available
                struct TimeSlot* currentSlot = day[chosenDay - 1];
                int slotNumber = 1;

                while (currentSlot != NULL && slotNumber < chosenSlot) {
                    currentSlot = currentSlot->next;
                    slotNumber++;
                }

                if (currentSlot == NULL || strcmp(currentSlot->name, "Available") != 0) {
                    printf("Invalid time slot or slot is already booked. Please choose another one.\n");
                    return;
                }
                struct User* currentUser = users;
//ftch ela user li dar l appointment w zidlo f booking count
while (currentUser != NULL) {
    if (strcmp(currentUser->name, userName) == 0) {
        // User found, increment their bookings
        currentUser->bookings++;
        break;  // No need to continue searching
    }
    currentUser = currentUser->next;
}
                // Reserve the time slot for the user
                strcpy(currentSlot->name, userName);
                printf("Appointment successfully reserved for %s on day %d.\n", userName, chosenDay);
            } else {
                printf("Invalid input. Please try again.\n");
            }
        } else {
            printf("Invalid input. Please try again.\n");
        }
    } else {
        printf("Invalid input. Please try again.\n");
    }
}


//----------------------------------------------------------------------------------------------------------------------
void deleteAppointment(struct TimeSlot* week[6], int day, int slotNumber) {
    // Check if the day and slot number are valid
    if (day < 1 || day > 6 || slotNumber < 1 || slotNumber > 5) {
        printf("Invalid day or time slot number. Please try again.\n");
        return;
    }

    // Find the selected time slot
    struct TimeSlot* currentSlot = week[day - 1];
    int slot = 1;

    while (currentSlot != NULL && slot < slotNumber) {
        currentSlot = currentSlot->next;
        slot++;
    }

    if (currentSlot == NULL) {
        printf("Invalid time slot. Please try again.\n");
        return;
    }

    // Check if the selected time slot is already available
    if (strcmp(currentSlot->name, "Available") == 0) {
        printf("This time slot is already available. No appointment to delete.\n");
        return;
    }

    // The time slot is booked; delete the appointment
    strcpy(currentSlot->name, "Available");
    printf("Appointment in slot %d on day %d has been deleted.\n", slotNumber, day);
}
