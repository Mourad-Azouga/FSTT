#include "header.h"
typedef struct artist {
    char name[20];
    char nat[20];
} artist_caller;

typedef struct chanson {
    char titre[20];
    int dur;
    int ann;
    artist_caller *artist;
    struct chanson *next;
} chanson_caller;

chanson_caller *artist_finder(chanson_caller **head, char *name);
chanson_caller *create_chanson(chanson_caller **head, char* titre, int dur, int ann, char* name);
void suppi_chanson(chanson_caller **head, char* name);
void cher_natio(chanson_caller **head, char* nat);


int main (void)
{
    char titre[20],name[20], nat[20];
    int ann, dur;
    chanson_caller *head = NULL, *new, *current = NULL;
    while (1)
    {
        printf("\nLa current biblio est: \n");
        if (!head) {
            printf("Empty\n");
        }
        else {
            current = head;
            while (current != NULL)
            {
                printf("Chanson: %s Duree: %d Annee: %d Artist nom: %s Artist Nationalite: %s\n", current->titre, current->dur, current->ann, current->artist->name, current->artist->nat);
                current = current->next;
            }
        }
    int choix;
    printf("\nPour Ajouter une nouvelle chanson taper 1\nPour Supprimer une chanson Taper 2\nPour Chercher les chansons des artistes avec une nationalite donnee taper 3\nAfficher les chansons de plus de 30 minutes de duree\n");
    scanf(" %d", &choix);
    getchar();
    switch (choix) 
    {
        case 1:
        /*Take titre*/
            printf("Vous avez choisis l'Ajout d'une nouvelle chanson:\n");
            printf("SVP de saisir le titre: ");
            fgets(titre, sizeof(titre), stdin);
            titre[strcspn(titre, "\n\r\t")] = '\0';
        /*Take dur*/
            printf("SVP de saisir la duree en forme en minutes: ");
            scanf("%d", &dur);
            getchar();          
        /*Take ann*/
            printf("SVP de saisir l'annee de pub: ");
            scanf("%d", &ann);
            getchar();
        /*Take artist*/
            printf("SVP de saisir le nom du singer: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            new = create_chanson(&head, titre, dur, ann, name);
            printf("Vous avez choisis:\n%s\n%d\n%d\n%s\n%s\n", new->titre, new->dur, new->ann, new->artist->name, new->artist->nat);
        break;

        case 2:
            if (!head) {
                fprintf(stderr, "Biblio empty\n");
                break;
                }
            printf("Vous avez choisis de supprimer une chanson:\nSVP de saisir le nom de la chanson: ");
            fgets(titre, sizeof(titre), stdin);
            titre[strcspn(titre, "\n\r\t")] = '\0';
            suppi_chanson(&head, titre); 
        break;

        case 3:
            if (!head) {
                fprintf(stderr, "Biblio empty\n");
                break;
                }
            printf("Vous avez choisis de cherche les chansons avec la meme nationalite d'artist\nSVP de saisir la nationalite que vous voulez chercher: ");
            fgets(nat, sizeof(nat), stdin);
            nat[strcspn(nat, "\n\r\t")] = '\0';
            cher_natio(&head, nat);
        break;

        case 4:
                if (!head) {
                fprintf(stderr, "Biblio empty\n");
                break;
                }
            printf("Affichage des chansons ayant > 30min duree\n");
            current = head;
            while (current != NULL)
            {
                if (current->dur >= 30) {
            printf("Chanson touvee!\n Titre: %s, Duree %d, Annee %d, Artist: %s, Nationalite: %s\n", current->titre, current->dur, current->ann, current->artist->name, current->artist->nat);
                }
                current = current->next;
            }
        break;
        default:
        printf("Veuiller choisir le nombre correspendant a l'operation\n");
    }

    }
}

chanson_caller*artist_finder(chanson_caller **head, char *name)
{
    chanson_caller *pointer = NULL;
    if (!*head) {
        return (NULL);
    }
    pointer = *head;
    while (pointer != NULL)
    {
        if (strcmp(pointer->artist->name, name) == 0) {
           return (pointer); 
        }
        pointer = pointer->next;
    }
    return (NULL);

}
chanson_caller *create_chanson(chanson_caller **head, char* titre, int dur, int ann, char* name)
{
    char nat[20];
    chanson_caller *d_name;
    chanson_caller *pointer = NULL;
    chanson_caller *new = (chanson_caller *)malloc(sizeof(chanson_caller));
     new->artist = (artist_caller *)malloc(sizeof(artist_caller));
    if (new == NULL || new->artist == NULL ) {
        fprintf(stderr, "malloc issue");
        exit(EXIT_FAILURE);
    }
    strcpy(new->titre, titre);
    new->dur = dur;
    new->ann = ann;

    d_name = artist_finder(head, name);
    if (d_name == NULL) {
    /*Artist not found, creating new one*/
    strcpy(new->artist->name, name);
    printf("SVP de saisir la nationalite du singer: ");
    fgets(nat, sizeof(nat), stdin);
    nat[strcspn(nat, "\n")] = '\0';
    strcpy(new->artist->nat, nat);
    }
    else {
        printf("Artist trouvee\n");
        strcpy(new->artist->name, d_name->artist->name);
        strcpy(new->artist->nat, d_name->artist->nat);
        }
    if (!*head) {
        new->next = NULL;
        *head = new;
    }
    else {
        new->next = *head;
        *head = new;
    }
    return(new);
}
void suppi_chanson(chanson_caller **head, char* titre)
{
    chanson_caller *current = NULL, *current_slow = NULL;
    current = *head;

    while (current != NULL)
    {
        if (strcmp(current->titre, titre) == 0) {
            if (current == *head) {
                *head = current->next;
            }
            else {
                current_slow->next = current->next;
            }
            free(current);
            printf("La chanson a ete supprimer avec succee!\n");
            return;
        }
        current_slow = current;
        current = current->next;
    }

}
void cher_natio(chanson_caller **head, char* nat)
{
    chanson_caller *current = NULL;
    current = *head;
    while (current != NULL)
    {
        if (strcmp(current->artist->nat, nat) == 0) {
            printf("Chanson touvee!\n Titre: %s, Duree %d, Annee %d, Artist: %s, Nationalite: %s\n", current->titre, current->dur, current->ann, current->artist->name, current->artist->nat);
        }
        current = current->next;
    }
    return;
}
