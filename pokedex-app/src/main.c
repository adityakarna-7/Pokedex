#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"

void displayMenu() {
    printf("Pokedex Application\n");
    printf("1. Add Pokemon\n");
    printf("2. Display Pokemon\n");
    printf("3. Search Pokemon\n");
    printf("4. Edit Pokemon\n");
    printf("5. Delete Pokemon\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                addPokemon();
                break;
            case 2:
                displayPokemon();
                break;
            case 3:
                searchPokemon();
                break;
            case 4:
                editPokemon();
                break;
            case 5:
                deletePokemon();
                break;
            case 6:
                printf("Exiting the application.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}