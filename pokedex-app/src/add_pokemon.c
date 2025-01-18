#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokedex.h"

void addPokemon() {
    FILE *fptr;
    Pokemon p;

    fptr = fopen("pokedex.dat", "ab");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    printf("Enter ID: ");
    scanf("%d", &p.id);
    getchar(); // to consume the newline character left by scanf

    printf("Enter Pokemon name: ");
    scanf("%[^\n]", p.name);
    getchar(); // to consume the newline character

    printf("Enter Primary Type: ");
    scanf("%[^\n]", p.primaryType);
    getchar(); // to consume the newline character

    printf("Enter Secondary Type (if any, else press enter): ");
    scanf("%[^\n]", p.secondaryType);
    
    fwrite(&p, sizeof(Pokemon), 1, fptr);
    fclose(fptr);

    printf("Pokemon added successfully!\n");
}