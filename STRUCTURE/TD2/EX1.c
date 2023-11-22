#include "header.h"
typedef struct chanson {
    char name[100];
    char dur[100];
    char ann[100];
    struct artist *artist;
    struct chanson *next;
    struct chanson *prev;
} caller;
typedef struct artist {
    char name[100];
    char nat[100];
};

void main (void)
{
    int choix;
    struct chanson *biblio = NULL;
    printf("Bienvenue");
    do {
    printf("Menu\nAjoutter une chanson clicker 1\n")
    scanf("%d", choix);
    switch (choix)
    {
        case 1:
        ajout();
        break;
    }
    }
}
struct chanson* ajout()
{
    char name[100];
    char dur[100];
    char ann[100];
    char art[100];
    struct chanson *pointer;
    struct chanson *new = (struct chanson *)malloc(sizeof(struct chanson*));
    if (new == NULL)
    {
        printf("malloc problem");
        exit(EXIT_FAILURE);
    }
    while (poiner->next != NULL)
    {

    }
    printf("Saisir le nom du chanson\n");
    scandf("%s", nom);
    new->name = nom;
    printf("Saisir la durée du chanson\n");
    scandf("%s", dur);
    new->dur = dur;
    printf("Saisir l'annee du chanson\n");
    scandf("%s", ann);
    new->dur = ann;
    printf("Saisir l'artist\n");
    scanf("%s", art)
    new->artist = art;
    if (pointer == NULL)
    {
        pointer = new;

    }


     while (poiner->next != NULL)
    {
        
    }
    return (new);
}