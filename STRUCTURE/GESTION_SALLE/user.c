#include "header.h"

// Create a new user
void createUser(struct User** users, const char* name, int phone, const char* prof) {
	struct User* newUser = (struct User*)malloc(sizeof(struct User));
	if (newUser == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	// Assign a unique user ID (you can implement this logic)
	// For simplicity, we'll use a static counter here.
	static int userIDCounter = 1;
	newUser->userID = userIDCounter++;
	newUser->bookings = 0;

	strncpy(newUser->name, name, sizeof(newUser->name) - 1);
	newUser->name[sizeof(newUser->name) - 1] = '\0'; // Ensure null-terminated

	newUser->phone = phone;

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
		printf("Numero de telephone : %d\n", user->phone);
		printf("Profession : %s\n", user->prof);
		printf("Nombre de reservations : %d\n", user->bookings);
		// Add code to display other user details
	} else {
		printf("Utilisateur non trouve.\n");
	}
}
