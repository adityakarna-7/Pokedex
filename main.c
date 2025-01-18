#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pokemon{
    int id;
    char name[50];
    char type1[20];
    char type2[20];
    int hp;
    int attack;
    int defense;
};

void addpkmn();
void displaypkmn();
void searchpkmn();
void deletepkmn();
void editpkmn();

int main(){
    int choice;
    do{
        printf("-----POKEDEX-----\n");
        printf("1. Add Pokemon\n");
        printf("2. Display Pokemon\n");
        printf("3. Search Pokemon\n");
        printf("4. Delete Pokemon\n");
        printf("5. Edit Pokemon\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addpkmn();
                break;
            case 2:
                displaypkmn();
                break;
            case 3:
                searchpkmn();
                break;
            case 4:
                deletepkmn();
                break;
            case 5:
                editpkmn();
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 6);
    return 0;
}

void addpkmn(){
    struct pokemon p;
    FILE *fptr;
    fptr = fopen("pokedex.dat", "ab");

    if (fptr == NULL){
        printf("Error opening file\n");
        exit(1);
    }

    printf("Enter ID: ");
    scanf("%d", &p.id);

    printf("Enter Pokemon name: ");
    scanf("%[^\n]", p.name);
    
    printf("Enter Primary")

}
