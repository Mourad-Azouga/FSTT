#include <stdio.h>
#include <string.h>

struct Student {
    char Nom[10];
    char Prenom[10];
    char CNE[8];
    float Moyenne;
};

void inputStudents(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Entrer le nom %d: ", i + 1);
        scanf("%s", students[i].Nom);
        printf("Entrer le prenom %d: ", i + 1);
        scanf("%s", students[i].Prenom);
        printf("Entrer le CNE %d: ", i + 1);
        scanf("%s", students[i].CNE);
        printf("Entrer la moyenne: %d: ", i + 1);
        scanf("%f", &students[i].Moyenne);
        do {
         if (students[i].Moyenne < 0 || students[i].Moyenne > 20)
        {
            printf("Erreur moyenne doit etre entre 20 et 0\nEntrer la moyenne: %d: ", i + 1);
            scanf("%f", &students[i].Moyenne);
        }
        }
        while (students[i].Moyenne < 0 || students[i].Moyenne > 20);
    }
}

void findLowestAverage(struct Student students[], int n) {
    if (n == 0) {
        printf("The list is empty.\n");
        return;
    }

    struct Student lowestStudent = students[0];

    for (int i = 1; i < n; i++) {
        if (students[i].Moyenne < lowestStudent.Moyenne) {
            lowestStudent = students[i];
        }
    }

    printf("L'etudiant avec la moyenne la plus faible est:\n");
    printf("Nom: %s\n", lowestStudent.Nom);
    printf("Prenom: %s\n", lowestStudent.Prenom);
    printf("CNE: %s\n", lowestStudent.CNE);
    printf("Moyenne: %.2f\n", lowestStudent.Moyenne);
}

int main() {
    int n;

    printf("Entrer le nombre total des etudiants:");
    scanf("%d", &n);
    struct Student students[n];
    inputStudents(students, n);
    findLowestAverage(students, n);

    return 0;
}
