#include "header.h"

// Create a new user
void createUser(struct User** users, const char* name, const char* phone, const char* prof) {
	struct User* newUser = (struct User*)malloc(sizeof(struct User));
	if (newUser == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	// Assign a unique user ID (Starting from 1)
	static int userIDCounter = 1;
	newUser->userID = userIDCounter++;
	newUser->bookings = 0;

	strncpy(newUser->name, name, sizeof(newUser->name) - 1);
	newUser->name[sizeof(newUser->name) - 1] = '\0'; // Ensure null-terminated

	strncpy(newUser->phone, phone, sizeof(newUser->phone) - 1);
	newUser->phone[sizeof(newUser->phone) - 1] = '\0'; // Ensure null-terminated

	strncpy(newUser->prof, prof, sizeof(newUser->prof) - 1);
	newUser->prof[sizeof(newUser->prof) - 1] = '\0'; // Ensure null-terminated

	newUser->next = *users;
	*users = newUser;
}

// Find a user by name
struct User* findUser(struct User* users, const char* name) {
	struct User* current = users;
	while (current != NULL) {
		if (strcmp(current->name, name) == 0) {
			return current;
		}
		current = current->next;
	}
	return NULL; // User not found
}

// Display user details
void displayUserDetails(struct User* user) {
	if (user != NULL) {
		printf("ID de l'utilisateur : %d\n", user->userID);
		printf("Nom : %s\n", user->name);
		printf("Numero de telephone : %s\n", user->phone);
		printf("Profession : %s\n", user->prof);
		printf("Nombre de reservations : %d\n", user->bookings);
		// Add code to display other user details
	} else {
		printf("Utilisateur non trouve.\n");
	}
}

// Function to delete a user
void deleteUser(struct User** users, const char* name) {
	// Find the user
	struct User* userToDelete = findUser(*users, name);

	if (userToDelete != NULL) {
		// Display user details
		displayUserDetails(userToDelete);

		// Ask for confirmation
		char confirm[10];
		printf("Etes-vous sur de vouloir supprimer cet utilisateur? (oui/non): ");
		if (fgets(confirm, sizeof(confirm), stdin) != NULL) {
			strtok(confirm, "\n"); // Remove newline character
			if (strcmp(confirm, "oui") == 0) {
				// User confirmed deletion
				struct User* current = *users;
				struct User* prev = NULL;

				// Find and delete the user from the list
				while (current != userToDelete) {
					prev = current;
					current = current->next;
				}

				if (prev == NULL) {
					*users = current->next;
				} else {
					prev->next = current->next;
				}

				// Free memory for the deleted user
				free(userToDelete);

				printf("Utilisateur supprime avec succes.\n");
			} else {
				printf("Suppression de l'utilisateur annulee.\n");
			}
		}
	} else {
		// User not found
		printf("Utilisateur non trouvé.\n");
	}
}
