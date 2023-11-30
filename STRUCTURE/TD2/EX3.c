#include "header.h"
typedef struct ADN {
    char base[2];
    struct ADN *next;
} list_caller;
void nouv_seq(list_caller **head, const char* adn);
void seq_finder(list_caller **head, const char* seq);
void main (void)
{
    char adn[100];
    list_caller *head = NULL, *pointer = NULL;
    int choix;
    while (1)
    {
    printf("Bienvenu au base ADN\nTaper 1 pour: Inserer une nouvelle sequence d'ADN\nTaper 2 pour: Rechercher une sequence specifique dans la structure de l'ADN\nTaper 3 pour: Afficher l'ensemble de l'ADN stocke dans la structure\nTaper 4 pour: Comparer deux ADN pour deux patients differents\n");
    scanf("%d", &choix);
    getchar();
    switch(choix) {
        case 1:
        /*Khetarina getline bach manlimitiwch adn size, sinon fgets wndiro adn[100]  */
            size_t adn_size = 0;
            printf("Vous avez choisis d'inserer une nouvelle sequence d'ADN\n SVP de saisir la nouvelle serie < 100: ");
            fgets(adn, sizeof(adn), stdin);
            adn[strcspn(adn, "\n")] = '\0';
            for (int i = 0; i < strlen(adn); i++)
            {
                if (adn[i] != 'A' && adn[i] != 'C' && adn[i] != 'T' && adn[i] != 'G'){
                    printf("Erreur sequence ADN: Nucleotide non reconnue :%s\n", adn[i]);
                    break;
                }
            }
            nouv_seq(&head, adn);
        break;
                case 2:

            printf("SVP de saisir la sequence que vou voulez trouver dans la structure: ");
            fgets(adn, sizeof(adn), stdin);
            adn[strcspn(adn, "\n")] = '\0';
              for (int i = 0; i < strlen(adn); i++)
            {
                if (adn[i] != 'A' && adn[i] != 'C' && adn[i] != 'T' && adn[i] != 'G' || adn[i] == '\n'){
                    printf("Erreur sequence ADN: Nucleotide non reconnue :%s\n", adn[i]);
                    break;
                }
            }
            seq_finder(&head, adn);

        break;

        case 3:
        pointer = head;
            while (pointer != NULL) {
                printf("%s", pointer->base);
                pointer = pointer->next;
            }
            putchar('\n');  
        break;

        case 4:
        printf("4");
        break;
        
        default:
        printf("SVP de taper une valeur entre 1 et 4\n");
    }
    }
list_caller *current = head, *cur;
while (current != NULL) {
    cur = current;
    current = current->next;
    free(cur);
}
}
void nouv_seq(list_caller **head, const char* adn)
{
    list_caller *pointer = NULL;
    if (adn == NULL) {
        printf("ll");
    }
    for (int i = 0; i < strlen(adn); i++) {
    list_caller *new = (list_caller *)malloc(sizeof(list_caller));
    if (new == NULL) {
        fprintf(stderr, "malloc errror");
        exit(EXIT_FAILURE);
    }
    strncpy(new->base, &adn[i], 1);
    new->base[1] = '\0';
    new->next = NULL;

    if (!*head) {
       *head = new;
    } else {
    pointer = *head;
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->next = new;
    }
    }
    return;
}
void seq_finder(list_caller **head, const char *seq)
{
    list_caller *pointer = NULL;
    if (!*head) {
        fprintf(stderr, "Structure ADN non existante\n");
        return;
    }
    pointer = *head;
    while (pointer != NULL) {
    int i = 0;
        while (pointer != NULL && seq[i] != '\0') {
            if (seq[i] == pointer->base[0]){
                i++;
            pointer = pointer->next;
            } else {
                i = 0;
            pointer = pointer->next;

            }
        }
        if (seq[i] == '\0') {
                printf("Trouvee!\n");
                return;
            }
    }
    
        printf("Non trouvee\n");
        return;
}