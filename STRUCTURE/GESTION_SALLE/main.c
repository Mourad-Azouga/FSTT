#include "header.h"

// Function to create a new time slot


// Function to display time slots
void displayTimeSlots(struct TimeSlot* timeSlots) {
    struct TimeSlot* currentSlot = timeSlots;
    int slotNumber = 1;
    while (currentSlot != NULL) {
        printf("%d. %02d:%02d - %02d:%02d (%s)\n", slotNumber, currentSlot->startHour, currentSlot->startMinute,
               currentSlot->endHour, currentSlot->endMinute, currentSlot->name);
        slotNumber++;
        currentSlot = currentSlot->next;
    }
}



int main() {
    int chosenSlot;
    // Define predefined time slots as a linked list
    struct TimeSlot* timeSlots = NULL;
    timeSlots = createTimeSlot(9, 0, 10, 45);
    timeSlots->next = createTimeSlot(11, 0, 12, 45);
    timeSlots->next->next = createTimeSlot(13, 0, 14, 45);
    timeSlots->next->next->next = createTimeSlot(15, 0, 16, 45);
    timeSlots->next->next->next->next = createTimeSlot(17, 0, 18, 45);

    int choice;

    do {
        printf("\n---- Meeting Room Reservation System ----\n");
        printf("1. Display Available Time Slots\n");
        printf("2. Make an Appointment\n");
        printf("3. Cancel an Appointment\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        char input[10];

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 3) {
                printf("Invalid input. Please enter a valid choice (1-3).\n");
                continue;
            }

            switch (choice) {
                case 1:
                    printf("Available Time Slots:\n");
                    displayTimeSlots(timeSlots);
                    break;
                case 2:
                    makeAppointment(timeSlots);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    break;
                case 3:
                    printf("Delete an Appointment\n");
                    printf("Enter the number of the appointment you want to delete: ");
                    if (fgets(input, sizeof(input), stdin) != NULL) {
                    if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1) {
                    printf("Invalid input. Please enter a valid appointment number.\n");
                    } else {
                    deleteAppointment(timeSlots, chosenSlot);
                            }
                    } else {
                    printf("Invalid input. Please try again.\n");
                    }
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } else {
            printf("Input error. Please try again.\n");
        }
    } while (choice != 0);

    while (timeSlots != NULL) {
        struct TimeSlot* nextSlot = timeSlots->next;
        free(timeSlots);
        timeSlots = nextSlot;
    }

    return 0;
}
