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
	strcpy(newSlot->name, "Disponible"); //Set name to "Disponible" for init
	newSlot->next = NULL;

	return newSlot;
}
//----------------------------------------------------------------------------------------------------------------------
// Function to make an appointment
void makeAppointment(struct TimeSlot* day[6], struct User* users) {
	// Display available time slots
	printf("Creneaux Horaires Disponibles :\n");
	displayTimeSlots(day);

	// Ask the user to enter their name
	char userName[100];
	printf("Entrez votre nom : ");
	if (fgets(userName, sizeof(userName), stdin) != NULL) {
		strtok(userName, "\n"); // Remove newline character

		// Check if the user exists
		struct User* user = findUser(users, userName);

		if (user == NULL) {
			printf("L'utilisateur '%s' n'existe pas. Veuillez d'abord creer un utilisateur.\n", userName);
			return;
		}

		// Ask the user to choose a day and a time slot
		int chosenDay;
		int chosenSlot;
		char input[100];

		printf("Entrez le numero du jour (1-6) ou vous souhaitez prendre un rendez-vous :  ");
		if (fgets(input, sizeof(input), stdin) != NULL) {
			if (sscanf(input, "%d", &chosenDay) != 1 || chosenDay < 1 || chosenDay > 6) {
				printf("Entree non valide. Veuillez entrer un jour valide (1-6).\n");
				return;
			}

			printf("Entrez le numero du creneau horaire que vous souhaitez reserver (1-5) : ");
			if (fgets(input, sizeof(input), stdin) != NULL) {
				if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1 || chosenSlot > 5) {
					printf("Entree non valide. Veuillez entrer un numero de creneau horaire valide (1-5).\n");
					return;
				}

				// Check if the selected time slot is available
				struct TimeSlot* currentSlot = day[chosenDay - 1];
				int slotNumber = 1;

				while (currentSlot != NULL && slotNumber < chosenSlot) {
					currentSlot = currentSlot->next;
					slotNumber++;
				}

				if (currentSlot == NULL || strcmp(currentSlot->name, "Disponible") != 0) {
					printf("Creneau horaire non valide ou deja reserve. Veuillez en choisir un autre.\n");
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
				printf("Rendez-vous reserve avec succes pour %s le jour %d.\n", userName, chosenDay);
			} else {
				printf("Entree non valide. Veuillez reessayer.\n");
			}
		} else {
			printf("Entree non valide. Veuillez reessayer.\n");
		}
	} else {
		printf("Entree non valide. Veuillez reessayer.\n");
	}
}


//----------------------------------------------------------------------------------------------------------------------
void deleteAppointment(struct TimeSlot* week[6], int day, int slotNumber) {
	// Check if the day and slot number are valid
	if (day < 1 || day > 6 || slotNumber < 1 || slotNumber > 5) {
		printf("Jour ou numero de creneau non valide. Veuillez reessayer.\n");
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
		printf("Creneau horaire non valide. Veuillez reessayer.\n");
		return;
	}

	// Check if the selected time slot is already available
	if (strcmp(currentSlot->name, "Disponible") == 0) {
		printf("Ce creneau horaire est deja disponible. Aucun rendez-vous à supprimer.\n");
		return;
	}

	// The time slot is booked; delete the appointment
	strcpy(currentSlot->name, "Disponible");
	printf("Le rendez-vous dans le creneau %d le jour %d a ete supprime.\n", slotNumber, day);
}
