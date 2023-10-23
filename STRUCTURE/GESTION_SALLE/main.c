#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure for time slots
struct TimeSlot {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    char name[50]; // Name of the person reserving the slot
    struct TimeSlot* next;
};

// Define a structure for user details
struct User {
    char name[50];
    char phoneNumber[15];
    char profession[50];
    char idNumber[20];
    int appointmentCount;
};

// Function to create a new time slot
struct TimeSlot* createTimeSlot(int startH, int startM, int endH, int endM, const char* name) {
    struct TimeSlot* newSlot = (struct TimeSlot*)malloc(sizeof(struct TimeSlot));
    if (newSlot == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newSlot->startHour = startH;
    newSlot->startMinute = startM;
    newSlot->endHour = endH;
    newSlot->endMinute = endM;
    strcpy(newSlot->name, name); // Set the name
    newSlot->next = NULL;

    return newSlot;
}

// Function to create a new user
struct User createUser() {
    struct User newUser;
    //printf("Enter your name: ");
    //scanf("%s", newUser.name);
    printf("Enter your phone number: ");
    scanf("%s", newUser.phoneNumber);
    printf("Enter your profession: ");
    scanf("%s", newUser.profession);
    printf("Enter your ID number: ");
    scanf("%s", newUser.idNumber);

    newUser.appointmentCount = 0; // Initialize the appointment count to 0
    return newUser;
}
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
// Function to display time slots for the day, excluding booked slots
void displayAvailableTimeSlots(struct TimeSlot* timeSlots, struct User* users, int userCount) {
    struct TimeSlot* currentSlot = timeSlots;
    int slotNumber = 1;
    while (currentSlot != NULL) {
        if (strcmp(currentSlot->name, "Available") == 0) {
            printf("%d. %02d:%02d - %02d:%02d (Available)\n", slotNumber, currentSlot->startHour, currentSlot->startMinute,
                   currentSlot->endHour, currentSlot->endMinute);
            slotNumber++;
        } else {
            // This slot is already booked, so we skip it
        }
        currentSlot = currentSlot->next;
    }
}

// Function to get the current time and date
void getCurrentTimeAndDate() {
    time_t t;
    struct tm* info;
    char buffer[80];

    time(&t);
    info = localtime(&t);

    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", info);
    printf("Current Date and Time: %s\n", buffer);
}

// Function to search for a user by name and return their index in the users array
int findUserIndex(const struct User* users, int userCount, const char* name) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i; // User found, return the index
        }
    }
    return -1; // User not found
}

// Function to display all user details
void displayUserDetails(const struct User* user) {
    printf("Name: %s\n", user->name);
    printf("Phone Number: %s\n", user->phoneNumber);
    printf("Profession: %s\n", user->profession);
    printf("ID Number: %s\n", user->idNumber);
    printf("Appointment Count: %d\n", user->appointmentCount);
}

// Function to make an appointment
void makeAppointment(struct TimeSlot* timeSlots, struct User* users, int* userCount) {
    // Display today's available time slots
    printf("Today's Available Time Slots:\n");
    displayAvailableTimeSlots(timeSlots, users, *userCount);
    // Create an array to keep track of available time slots
    int availableSlots[5];
    int availableSlotCount = 0;

    // Iterate through the timeSlots linked list to find available slots
    for (int i = 0; i < 5; i++) {
        if (strcmp(timeSlots[i].name, "Available") == 0) {
            availableSlots[availableSlotCount] = i;
            availableSlotCount++;
        }
    
    
    }
printf("Initial timeSlots:\n");
for (int i = 0; i < 5; i++) {
    printf("%d: %s\n", i, timeSlots[i].name);
}

    if (availableSlotCount == 0) {
        printf("No available time slots. All slots are already bookSed.\n");
        return;
    }
    

    // Ask the user to choose a time slot
    int chosenSlot;
    do {
        printf("Enter the number of the time slot you want to reserve: ");
        if (scanf("%d", &chosenSlot) != 1 || chosenSlot < 1 || chosenSlot > availableSlotCount) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer
            printf("Invalid input. Please enter a valid time slot number.\n");
        }
    } while (chosenSlot < 1 || chosenSlot > availableSlotCount);

    // Adjust to 0-based index using the chosen slot's index from the available slots array
    chosenSlot = availableSlots[chosenSlot - 1];

    // Ask for the user's name
    char userName[50];
    printf("Enter your name: ");
    scanf("%s", userName);

    // Check if the user already exists
    int userIndex = findUserIndex(users, *userCount, userName);
    if (userIndex != -1) {
        // User exists, mark the time slot as reserved by the user
        strcpy(timeSlots[chosenSlot].name, userName);
        users[userIndex].appointmentCount++; // Increment appointment count
        printf("Appointment successfully reserved for %s.\n", userName);
    } else {
        // User doesn't exist, create a new user with details
        struct User newUser = createUser();
        // Update userName to newUser.name
        strcpy(newUser.name, userName);
        strcpy(timeSlots[chosenSlot].name, newUser.name); // Mark the time slot
        users[(*userCount)++] = newUser; // Add the user to the array
        printf("New user %s created, and appointment reserved.\n", userName);
    }
    availableSlotCount--;
}

int main() {
    // Define predefined time slots as a linked list
    struct TimeSlot* timeSlots = NULL;
    timeSlots = createTimeSlot(9, 0, 10, 45, "Available");
    timeSlots->next = createTimeSlot(11, 0, 12, 45, "Available");
    timeSlots->next->next = createTimeSlot(13, 0, 14, 45, "Available");
    timeSlots->next->next->next = createTimeSlot(15, 0, 16, 45, "Available");
    timeSlots->next->next->next->next = createTimeSlot(17, 0, 18, 45, "Available");

    struct User users[100]; // Array to store user details
    int userCount = 0; // Number of users in the array

    int choice;
    do {
        printf("\n---- Meeting Room Reservation System ----\n");
        getCurrentTimeAndDate();
        printf("1. Check today's sessions\n");
        printf("2. Print old sessions\n");
        printf("3. Make an appointment\n");
        printf("4. Remove an appointment\n");
        printf("5. Search for a user\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        char input[10];
       if (fgets(input, sizeof(input), stdin) != NULL) {
            choice = atoi(input);
            if (choice >= 1 && choice <= 6) {
                switch (choice) {
                    case 1:
                        printf("Today's Sessions:\n");
                        displayTimeSlots(timeSlots);
                        break;
                    case 2:
                        // Implement the functionality to print old sessions
                        // This will involve freeing and storing old sessions.
                        // We'll work on this part later.
                        break;
                    case 3:
                        makeAppointment(timeSlots, users, &userCount);
                        break;
                    case 4:
                        // Implement the functionality to remove an appointment
                        // You'll need to update the timeSlots accordingly.
                        break;
                    case 5:
                        // Search for a user by name
                        char searchName[50];
                        printf("Enter the name of the user you want to search for: ");
                        scanf("%s", searchName);
                        int userIndex = findUserIndex(users, userCount, searchName);
                        if (userIndex != -1) {
                            printf("User Details:\n");
                            displayUserDetails(&users[userIndex]);
                        } else {
                            printf("User not found.\n");
                        }
                        break;
                    case 6:
                        printf("Exiting the program.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } else {
                printf("Invalid input. Please enter a valid choice (1-6).\n");
            }
        } else {
            printf("Input error. Please try again.\n");
        }
    } while (choice != 6);

    // ... (the rest of your code)
    
    return 0;
}