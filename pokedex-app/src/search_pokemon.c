#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"

void searchPokemon() {
    FILE *fptr;
    Pokemon p;
    int id, found = 0;

    fptr = fopen("pokedex.dat", "rb");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter Pokemon ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Pokemon), 1, fptr)) {
        if (p.id == id) {
            printf("Pokemon found:\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Primary Type: %s\n", p.primaryType);
            printf("Secondary Type: %s\n", p.secondaryType);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Pokemon with ID %d not found.\n", id);
    }

    fclose(fptr);
}