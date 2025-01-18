#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

void editPokemon() {
    FILE *fptr;
    Pokemon p;
    int id, found = 0;

    fptr = fopen("pokedex.dat", "r+b");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return;
    }

    printf("Enter ID of the Pokémon to edit: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Pokemon), 1, fptr)) {
        if (p.id == id) {
            found = 1;
            printf("Editing Pokémon ID: %d\n", p.id);
            printf("Current Name: %s\n", p.name);
            printf("Enter new name: ");
            scanf(" %[^\n]", p.name);
            printf("Enter new Primary Type: ");
            scanf(" %[^\n]", p.primaryType);
            printf("Enter new Secondary Type (or 'none' if not applicable): ");
            scanf(" %[^\n]", p.secondaryType);

            fseek(fptr, -sizeof(Pokemon), SEEK_CUR);
            fwrite(&p, sizeof(Pokemon), 1, fptr);
            printf("Pokémon updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Pokémon with ID %d not found.\n", id);
    }

    fclose(fptr);
}