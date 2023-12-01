#include "header.h"
typedef struct empo {
    char nom[30];
    char add[50];
    char tel[14];
    char pos[50];
    int salaire;
    struct empo *l;
    struct empo *r;
} tree_caller;
