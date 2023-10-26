#include "header.h"
struct User* users = NULL;

// Function to create a new time slot


// Function to display time slots
void displayTimeSlots(struct TimeSlot* week[6]) {
    for (int day = 0; day < 6; day++) {
        printf("Day %d:\n", day + 1);
        struct TimeSlot* currentSlot = week[day];
        int slotNumber = 1;

        while (currentSlot != NULL) {
            printf("%d. %02d:%02d - %02d:%02d (%s)\n", slotNumber, currentSlot->startHour, currentSlot->startMinute,
                   currentSlot->endHour, currentSlot->endMinute, currentSlot->name);
            slotNumber++;
            currentSlot = currentSlot->next;
        }
        printf("\n");
    }
}




#include "header.h"

int main() {
    char input[10];
    int chosenDay, chosenSlot;
    struct TimeSlot* week[6]; // An array to hold time slots for 6 days
for (int day = 0; day < 6; day++) {
    if (day == 5) {
        week[day] = createTimeSlot(day + 1, 9, 0, 10, 45);
        week[day]->next = createTimeSlot(day + 1, 11, 0, 12, 45);
    } else {
        week[day] = createTimeSlot(day + 1, 9, 0, 10, 45);
        week[day]->next = createTimeSlot(day + 1, 11, 0, 12, 45);
        week[day]->next->next = createTimeSlot(day + 1, 13, 0, 14, 45);
        week[day]->next->next->next = createTimeSlot(day + 1, 15, 0, 16, 45);
        week[day]->next->next->next->next = createTimeSlot(day + 1, 17, 0, 18, 45);
    }
}


    struct User* users = NULL;
    char cont[5];
    int choice;

    do {
        Sleep(2000);
        printf("\n---- Meeting Room Reservation System ----\n");
        printf("1. Display Available Time Slots\n");
        printf("2. Make an Appointment\n");
        printf("3. Cancel an Appointment\n");
        printf("4. Create new user\n");
        printf("5. Find user\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &choice) != 1 || choice < 0 || choice > 5) {
                printf("Invalid input. Please enter a valid choice (0-5).\n");
                continue;
            }

            switch (choice) {
                case 1:
                    printf("Available Time Slots:\n");
                    displayTimeSlots(week);
                    break;
                case 2:
                    makeAppointment(week, users);
                    break;
                case 0:
                    printf("Exiting the program.\n");
                    break;
case 3:
    printf("Cancel an Appointment\n");
    printf("Enter the number of the day (1-6) for the appointment you want to delete: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        if (sscanf(input, "%d", &chosenDay) != 1 || chosenDay < 1 || chosenDay > 6) {
            printf("Invalid input. Please enter a valid day (1-6).\n");
        } else {
            printf("Enter the number of the time slot you want to cancel (1-5): ");
            if (fgets(input, sizeof(input), stdin) != NULL) {
                if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1 || chosenSlot > 5) {
                    printf("Invalid input. Please enter a valid time slot number (1-5).\n");
                } else {
                    deleteAppointment(week, chosenDay, chosenSlot); // Updated function call
                }
            }
        }
    }
    break;
                    break;
                case 4:
                    printf("Create a New User\n");
                    char userName[100];
                    int phone;
                    char prof[10];
                    printf("Enter the name of the new user: ");
                    if (fgets(userName, sizeof(userName), stdin) != NULL) {
                        strtok(userName, "\n"); // Remove newline character
                        printf("Enter phone number: ");
                        if (scanf("%d", &phone) != 1) {
                            printf("Invalid phone input. Please enter a valid phone number.\n");
                        }
                        getchar(); // Consume the newline character left by scanf

                        printf("Enter profession: ");
                        if (fgets(prof, sizeof(prof), stdin) != NULL) {
                            strtok(prof, "\n"); // Remove newline character
                            createUser(&users, userName, phone, prof);
                            printf("User created successfully.\n");
                        } else {
                            printf("Invalid profession input.\n");
                        }
                    } else {
                        printf("Invalid name input.\n");
                    }
                    break;
                case 5:
                    printf("Find a User\n");
                    char searchName[100];
                    printf("Enter the name of the user to find: ");
                    if (fgets(searchName, sizeof(searchName), stdin) != NULL) {
                        strtok(searchName, "\n"); // Remove newline character
                        struct User* foundUser = findUser(users, searchName);
                        displayUserDetails(foundUser);
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

    // Free memory for time slots
    for (int day = 0; day < 6; day++) {
        struct TimeSlot* currentSlot = week[day];
        while (currentSlot != NULL) {
            struct TimeSlot* nextSlot = currentSlot->next;
            free(currentSlot);
            currentSlot = nextSlot;
        }
    }

    return 0;
}
