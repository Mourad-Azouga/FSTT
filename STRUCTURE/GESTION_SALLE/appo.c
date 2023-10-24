#include "header.h"

struct TimeSlot* createTimeSlot(int startH, int startM, int endH, int endM) {
    struct TimeSlot* newSlot = (struct TimeSlot*)malloc(sizeof(struct TimeSlot));
    if (newSlot == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

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
void makeAppointment(struct TimeSlot* timeSlots) {
    // Display available time slots
    printf("Available Time Slots:\n");
    displayTimeSlots(timeSlots);

    // Ask the user to choose a time slot
    int chosenSlot;
    char input[100];

    printf("Enter the number of the time slot you want to reserve: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1) {
            printf("Invalid input. Please enter a valid time slot number.\n");
            return;
        }

        // Traverse the linked list to the chosen slot
        struct TimeSlot* currentSlot = timeSlots;
        int slotIndex = 1; // Start with 1-based index
        while (currentSlot != NULL && slotIndex < chosenSlot) {
            currentSlot = currentSlot->next;
            slotIndex++;
        }

        if (currentSlot == NULL) {
            printf("Invalid time slot number. Please try again.\n");
        } else {
            // Check if the selected time slot is available
            if (strcmp(currentSlot->name, "Available") == 0) {
                // Ask for the user's name
                char userName[100];
                printf("Enter your name: ");
                if (fgets(userName, sizeof(userName), stdin) != NULL) {
                    strtok(userName, "\n"); // Remove newline character
                    strcpy(currentSlot->name, userName);
                    printf("Appointment successfully reserved for %s.\n", userName);
                } else {
                    printf("Invalid name input.\n");
                }
            } else {
                printf("This time slot is already booked. Please choose another one.\n");
            }
        }
    } else {
        printf("Invalid input. Please try again.\n");
    }
}
//----------------------------------------------------------------------------------------------------------------------
void deleteAppointment(struct TimeSlot* timeSlots, int slotNumber) {
    struct TimeSlot* currentSlot = timeSlots;
    int slotIndex = 1;

    while (currentSlot != NULL && slotIndex < slotNumber) {
        currentSlot = currentSlot->next;
        slotIndex++;
    }

    if (currentSlot == NULL) {
        printf("Invalid time slot number. Please try again.\n");
    } else {
        if (strcmp(currentSlot->name, "Available") == 0) {
            printf("This time slot is already available. No appointment to delete.\n");
        } else {
            strcpy(currentSlot->name, "Available");
            printf("Appointment in slot %d has been deleted.\n", slotNumber);
        }
    }
}