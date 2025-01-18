#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

void deletePokemon(int id) {
    FILE *fptr = fopen("pokedex.dat", "rb");
    FILE *tempFptr = fopen("temp.dat", "wb");
    Pokemon p;
    int found = 0;

    if (fptr == NULL || tempFptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fread(&p, sizeof(Pokemon), 1, fptr)) {
        if (p.id == id) {
            found = 1;
            printf("Deleted Pokemon ID: %d, Name: %s\n", p.id, p.name);
        } else {
            fwrite(&p, sizeof(Pokemon), 1, tempFptr);
        }
    }

    fclose(fptr);
    fclose(tempFptr);

    if (!found) {
        printf("Pokemon with ID %d not found.\n", id);
    } else {
        remove("pokedex.dat");
        rename("temp.dat", "pokedex.dat");
    }
}