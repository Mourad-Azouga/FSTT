#include "header.h"

struct User* users = NULL;
//function to find and index the current user time and day
struct DateTime printCurrentTimeAndDay() {
    struct DateTime dateTime;
    time_t currentTime;
    struct tm* timeInfo;

    // Get the current time
    time(&currentTime);
    timeInfo = localtime(&currentTime);

    // Format time as HH:MM:SS
    strftime(dateTime.timeString, sizeof(dateTime.timeString), "%H:%M:%S", timeInfo);

    // Store the day index
    dateTime.dayIndex = timeInfo->tm_wday;
	//dont touch these, used for comparison in the makeappo
	dateTime.currentHour = timeInfo->tm_hour;
	dateTime.currentMinute = timeInfo->tm_min;

    return dateTime;
}

// Function to display time slots
void displayTimeSlots(struct TimeSlot* week[6]) {
	const char* jours[]={"ID:1-Lundi", "ID:2-Mardi", "ID:3-Mercredi", "ID:4-Jeudi", "ID:5-Vendredi", "ID:6-Samedi"};
	for (int day = 0; day < 6; day++) {
		printf(" %s:\n", jours[day]);
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





int main() {
	const char* dayNames[] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
	struct DateTime currentDateTime = printCurrentTimeAndDay();
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
	int choice;

	do {
		Sleep(2000);
		printf("\n---- Systeme de Reservation de Salle de Reunion ----\n");
		printf("Heure actuelle : %s, Jour actuel : %s\n", currentDateTime.timeString, dayNames[currentDateTime.dayIndex]);
		printf("1. Afficher les Creneaux Horaires Disponibles\n");
		printf("2. Prendre un Rendez-vous\n");
		printf("3. Annuler un Rendez-vous\n");
		printf("4. Creer un Nouvel Utilisateur\n");
		printf("5. Trouver un Utilisateur\n");
		printf("6. Supprimer un Utilisateur\n");
		printf("0. Quitter\n");
		printf("Entrez votre choix : ");

		if (fgets(input, sizeof(input), stdin) != NULL) {
			if (sscanf(input, "%d", &choice) != 1 || choice < 0 || choice > 6) {
				printf("Entree non valide. Veuillez entrer un choix valide (0-6).\n");
				continue;
			}

			switch (choice) {
				case 1:
					printf("Creneaux Horaires Disponibles :\n");
					displayTimeSlots(week);
					break;
				case 2:
					makeAppointment(week, users);
					break;
				case 0:
					printf("Fermeture du programme.\n");
					break;
				case 3:
					printf("Annuler un Rendez-vous\n");
					printf("Entrez le numero du jour (1-6) pour le rendez-vous que vous souhaitez supprimer : ");
					if (fgets(input, sizeof(input), stdin) != NULL) {
						if (sscanf(input, "%d", &chosenDay) != 1 || chosenDay < 1 || chosenDay > 6) {
							printf("Entree non valide. Veuillez entrer un jour valide (1-6).\n");
						} else {
							printf("Entrez le numero du creneau horaire que vous souhaitez annuler (1-5) : ");
							if (fgets(input, sizeof(input), stdin) != NULL) {
								if (sscanf(input, "%d", &chosenSlot) != 1 || chosenSlot < 1 || chosenSlot > 5) {
									printf("Entree non valide. Veuillez entrer un numero de creneau horaire valide (1-5).\n");
								} else {
									deleteAppointment(week, chosenDay, chosenSlot); // Updated function call
								}
							}
						}
					}
					break;
					break;
				case 4:
					printf("Creer un Nouvel Utilisateur\n");
					char userName[100];
					char phone[19];
					char prof[100];
					printf("Entrez le nom du nouvel utilisateur : ");
					if (fgets(userName, sizeof(userName), stdin) != NULL) {
						strtok(userName, "\n");//remove \n
						if (findUser(users, userName) != NULL)
						{printf("user exists");
						break;}
						printf("Entrez le numero de telephone :");
						if (scanf("%19s", phone) != 1) { 
    					printf("Entree non valide. Veuillez entrer un numero de telephone valide.\n");
						}
						getchar(); // Consume the newline character left by scanf

						printf("Entrez la profession : ");
						if (fgets(prof, sizeof(prof), stdin) != NULL) {
							strtok(prof, "\n"); // Remove\n from string
							createUser(&users, userName, phone, prof);
							printf("Utilisateur cree avec succes.\n");
						} else {
							printf("Entree non valide.\n");
						}
					} else {
						printf("Entree non valide.\n");
					}
					break;
				case 5:
					printf("Trouver un Utilisateur\n");
					char searchName[100];
					printf("Entrez le nom de l'utilisateur a trouver : ");
					if (fgets(searchName, sizeof(searchName), stdin) != NULL) {
						strtok(searchName, "\n"); // Remove newline character
						struct User* foundUser = findUser(users, searchName);
						displayUserDetails(foundUser);
					} else {
						printf("Entree non valide. Veuillez reessayer.\n");
					}
					break;
				case 6:
					printf("Supprimer un Utilisateur\n");
					char userNameToDelete[100];
					printf("Saisissez le nom de l'utilisateur que vous souhaitez supprimer : ");
					if (fgets(userNameToDelete, sizeof(userNameToDelete), stdin) != NULL) {
						strtok(userNameToDelete, "\n"); // Remove newline character
						deleteUser(&users, userNameToDelete);
					} else {
						printf("Erreur d'entree. Veuillez reessayer.\n");
					}
					break;
				default:
					printf("Choix non valide. Veuillez reessayer.\n");
			}
		} else {
			printf("Erreur d'entree. Veuillez reessayer.\n");
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
