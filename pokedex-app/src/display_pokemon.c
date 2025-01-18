#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"

void displayPokemon() {
    FILE *file = fopen("pokedex.dat", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    Pokemon p;
    printf("Pokédex Entries:\n");
    while (fread(&p, sizeof(Pokemon), 1, file)) {
        printf("ID: %d, Name: %s, Type: %s\n", p.id, p.name, p.type);
    }

    fclose(file);
}