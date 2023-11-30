/*Over siplified bach ndiro le TD ms kayna bzaf dial les probs fhal ida kano 2++ meds aandom nefs smiya wla ida kan 1 med 2 merat f lila w bzf dial lhajat akhrin*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char* jours[] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};
typedef struct med {
    char name[20];
    char pre[20];
    char spe[20];
    int inter;
} med_caller;
typedef struct jours {
    int jour;
    struct med *med[3];
    struct jours *next;
} list_caller;
void jours_init(list_caller **head);
void ajout(list_caller **head, list_caller *pointer);
void modifi(list_caller **head, list_caller *pointer);
void main ()
{
    int choix, i;
    char jour_choisis[10];
    list_caller *head = NULL, *pointer = NULL;
    printf("Gestion hebdomadaire\n");
    jours_init(&head);
    pointer = head;
    while (1)
    {
    do {
        printf("%s -> \tMed1: %s, Med2: %s, Med3: %s\n", jours[pointer->jour], pointer->med[0]->name, pointer->med[1]->name, pointer->med[2]->name);
        pointer = pointer->next;
    } while (pointer != head);
    printf("\nTaper 1 pour: Ajouter les 3 medecins intervenants pour un jour donne\nTaper 2 pour: Modifier les medecins intervenants pour un jour donne\nTaper 3 pour: Afficher les medecins qui interviennent plus de 3 fois\n");
    scanf("%d", &choix);
    getchar();
    switch (choix) {
        case 1 :
            printf("Vous avez choisis d'ajouter les medecins intervenants:\nSVP de choisir le jour: ");
            fgets(jour_choisis, sizeof(jour_choisis), stdin);
            jour_choisis[strcspn(jour_choisis, "\n")] = '\0';
            pointer = head;
            for (int i = 0; i < 7; i++) {
                if (strcmp(jours[pointer->jour], jour_choisis) == 0) {
                    ajout(&head, pointer);
                    break;
                }
                pointer = pointer->next;
            } 
        break;
        case 2 :
            printf("Vous avez choisis de modifier les medecins intervenants:\nSVP de choisir le jour: ");
            fgets(jour_choisis, sizeof(jour_choisis), stdin);
            jour_choisis[strcspn(jour_choisis, "\n")] = '\0';
            pointer = head;
            for (i = 0; i < 7; i++) {
                if (strcmp(jours[pointer->jour], jour_choisis) == 0) {
                    modifi(&head, pointer);
                    break;
                }
                pointer = pointer->next;
            } 
        break;

        case 3 :
        pointer = head;
        printf("La list des medecin ayant plus de 3 interentions :\n");
        for (i = 0; i < 7; i++) {
            for (int j = 0; j < 3; j++) {
                if (pointer->med[j]->inter >= 3) {
                    printf("Medecin: %s %s %s\n", pointer->med[j]->name, pointer->med[j]->pre, pointer->med[j]->spe);
                }
            }
            pointer = pointer->next;
        }
        break;

        case 4 :
        return;
        break; 
        default:
        printf("SVP de taper un nombre entre 1 et 3\n");
        break;   
    }
    }    
}
void jours_init(list_caller **head)
{
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        list_caller *new = (list_caller *)malloc(sizeof(list_caller));
        new->med[0] = (med_caller *) malloc(sizeof(med_caller));
        new->med[1] = (med_caller *) malloc(sizeof(med_caller));
        new->med[2] = (med_caller *) malloc(sizeof(med_caller));

        if (new == NULL || new->med[0] == NULL || new->med[1] == NULL || new->med[2] == NULL) {
            fprintf(stderr, "malloc error");
            exit(EXIT_FAILURE);
        }
        strcpy(new->med[0]->name, "empty");
        strcpy(new->med[1]->name, "empty");
        strcpy(new->med[2]->name, "empty");
        new->jour = i;
        new->next = *head;
        if (!*head) {
            *head = new;
            (*head)->next = *head;
        }
        else {
            list_caller *pointer = *head;
            while (pointer->next != *head) {
                pointer = pointer->next;
            }
            pointer->next = new;
        }
    }
}
void ajout(list_caller **head, list_caller *pointer)
{
    printf("Vous avez choisi le jour: %s\n", jours[pointer->jour]);
    if (strcmp(pointer->med[0]->name, "empty") != 0 || strcmp(pointer->med[1]->name, "empty") != 0 || strcmp(pointer->med[2]->name, "empty") != 0 ){
        printf("Jour deja plein\n");
        return;
    }
for (int i = 0; i < 3; i++) {
    printf(" SVP saisir le nom du medecin: ");
    fgets(pointer->med[i]->name, sizeof(pointer->med[i]->name), stdin);
    pointer->med[i]->name[strcspn(pointer->med[i]->name, "\n\t\r")] = '\0';
    printf(" SVP de saisir le prenom du medecin: ");
    fgets(pointer->med[i]->pre, sizeof(pointer->med[i]->pre), stdin);
    pointer->med[i]->pre[strcspn(pointer->med[i]->pre, "\n\t\r")] = '\0';
    printf(" SVP de saisir la specialite du medecin: ");
    fgets(pointer->med[i]->spe, sizeof(pointer->med[i]->spe), stdin);
    pointer->med[i]->spe[strcspn(pointer->med[i]->spe, "\n\t\r")] = '\0';
    printf("Medecin ajoutee avec succee: \n%s %s %s\n", pointer->med[i]->name, pointer->med[i]->pre, pointer->med[i]->spe);
    pointer->med[i]->inter += 1;
}
    printf("Tous les medecin du jours %s sont ajoutee avec succee!\n", jours[pointer->jour]);
    return;
}
void modifi(list_caller **head, list_caller *pointer)
{
        printf("Vous avez choisi le jour: %s\n", jours[pointer->jour]);
    if (strcmp(pointer->med[0]->name, "empty") == 0 || strcmp(pointer->med[1]->name, "empty") == 0 || strcmp(pointer->med[2]->name, "empty") == 0 ) {
        printf("Jours encore pas remplis svp d'ajouter les medecins d'abord\n");
        return;
    }
    for (int i = 0; i < 3; i++) {
    printf(" SVP saisir le nom du medecin: ");
    fgets(pointer->med[i]->name, sizeof(pointer->med[i]->name), stdin);
    pointer->med[i]->name[strcspn(pointer->med[i]->name, "\n\t\r")] = '\0';
    pointer->med[i]->inter = i;
    printf(" SVP de saisir le prenom du medecin: ");
    fgets(pointer->med[i]->pre, sizeof(pointer->med[i]->pre), stdin);
    pointer->med[i]->pre[strcspn(pointer->med[i]->pre, "\n\t\r")] = '\0';
    printf(" SVP de saisir la specialite du medecin: ");
    fgets(pointer->med[i]->spe, sizeof(pointer->med[i]->spe), stdin);
    pointer->med[i]->spe[strcspn(pointer->med[i]->spe, "\n\t\r")] = '\0';
    printf("Medecin modifier avec succee: \n%s %s %s\n", pointer->med[i]->name, pointer->med[i]->pre, pointer->med[i]->spe);
    pointer->med[i]->inter += 1;
    }
    printf("Tous les medecin du jours %s sont modifier avec succee!\n", jours[pointer->jour]);
    return;
}