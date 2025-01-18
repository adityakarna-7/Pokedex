#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pokemon {
    int id;
    char name[50];
    char type1[20];
    char type2[20];
    int hp;
    int attack;
    int defense;
    int speed;
    int special_attack;
    int special_defense;
};

void addpkmn();
void displaypkmn();
void searchpkmn();
void deletepkmn();
void editpkmn();
void dataentrymode();
void deletemode();
void searchbyname();
void editmode();
void searchmode();
void searchbytype();
void searchbyid();

int main() {
    int option;
    do {
        printf("-----POKEDEX-----\n");
        printf("1. Data Entry Mode\n");
        printf("2. Search Mode\n");
        printf("3. Edit Mode\n");
        printf("4. Delete Mode\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar(); // Consume leftover newline character

        switch (option) {
            case 1:
                dataentrymode();
                break;
            case 2:
                searchmode();
                break;
            case 3:
                editmode();
                break;
            case 4:
                deletemode();
                break;
            case 5:
                printf("Exiting.....\n");
                break;
            default:
                printf("Invalid Option! Select correct option....\n");
        }
    } while (option != 5);
    return 0;
}

void dataentrymode() {
    char cont;
    do {
        addpkmn();
        printf("Do you want to add more Pokemon? (y/n): ");
        scanf(" %c", &cont); // Notice the space before %c to consume the leftover newline character
    } while (cont == 'y' || cont == 'Y');
}

void addpkmn() {
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat", "ab");

    if (!fptr) {
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon ID: ");
    scanf("%d", &p.id);
    getchar(); // Consume leftover newline
    printf("Enter Pokemon Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0; // Remove trailing newline
    printf("Enter Primary type: ");
    fgets(p.type1, sizeof(p.type1), stdin);
    p.type1[strcspn(p.type1, "\n")] = 0;
    printf("Enter Secondary type (or 'None'): ");
    fgets(p.type2, sizeof(p.type2), stdin);
    p.type2[strcspn(p.type2, "\n")] = 0;
    printf("Enter HP: ");
    scanf("%d", &p.hp);
    printf("Enter Attack: ");
    scanf("%d", &p.attack);
    printf("Enter Defense: ");
    scanf("%d", &p.defense);
    printf("Enter Speed: ");
    scanf("%d", &p.speed);
    printf("Enter Special Attack: ");
    scanf("%d", &p.special_attack);
    printf("Enter Special Defense: ");
    scanf("%d", &p.special_defense);

    fwrite(&p, sizeof(p), 1, fptr);
    fclose(fptr);

    printf("Pokemon added successfully!\n");
}

void searchmode() {
    int choice;
    do {
        printf("\n--- Search Mode ---\n");
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Search by Type\n");
        printf("4. Display All Pokemon\n");
        printf("5. Exit Search Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) {
            case 1:
                searchbyid();
                break;
            case 2:
                searchbyname();
                break;
            case 3:
                searchbytype();
                break;
            case 4:
                displaypkmn();
                break;
            case 5:
                printf("Exiting Search Mode...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void searchbyid() {
    struct pokemon p;
    int id, found = 0;
    FILE *fptr = fopen("pokedex.dat", "rb");

    if (!fptr) {
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon ID to search: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(p), 1, fptr)) {
        if (p.id == id) {
            printf("\nPokemon Found!\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Type 1: %s\n", p.type1);
            printf("Type 2: %s\n", strcmp(p.type2, "None") == 0 ? "N/A" : p.type2);
            printf("HP: %d\n", p.hp);
            printf("Attack: %d\n", p.attack);
            printf("Defense: %d\n", p.defense);
            printf("Speed: %d\n", p.speed);
            printf("Special Attack: %d\n", p.special_attack);
            printf("Special Defense: %d\n", p.special_defense);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Pokemon not found!!\n");
    }

    fclose(fptr);
}

void searchbytype() {
    struct pokemon p;
    char type[20];
    int found = 0;
    FILE *fptr = fopen("pokedex.dat", "rb");

    if (!fptr) {
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon Type to search: ");
    fgets(type, sizeof(type), stdin);
    type[strcspn(type, "\n")] = 0; // Remove trailing newline

    while (fread(&p, sizeof(p), 1, fptr)) {
        if (strcasecmp(p.type1, type) == 0 || strcasecmp(p.type2, type) == 0) {
            if (!found) {
                printf("\nPokemon Found!\n");
            }
            printf("\nID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Type 1: %s\n", p.type1);
            printf("Type 2: %s\n", strcmp(p.type2, "None") == 0 ? "N/A" : p.type2);
            printf("HP: %d\n", p.hp);
            printf("Attack: %d\n", p.attack);
            printf("Defense: %d\n", p.defense);
            printf("Speed: %d\n", p.speed);
            printf("Special Attack: %d\n", p.special_attack);
            printf("Special Defense: %d\n", p.special_defense);
            found = 1;
        }
    }

    if (!found) {
        printf("Pokemon not found!!\n");
    }

    fclose(fptr);
}

void displaypkmn() {
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat", "rb");

    if (!fptr) {
        printf("Error opening file!!\n");
        return;
    }

    printf("\n--- All Pokemon ---\n");
    while (fread(&p, sizeof(p), 1, fptr)) {
        printf("\nID: %d\n", p.id);
        printf("Name: %s\n", p.name);
        printf("Type 1: %s\n", p.type1);
        printf("Type 2: %s\n", strcmp(p.type2, "None") == 0 ? "N/A" : p.type2);
        printf("HP: %d\n", p.hp);
        printf("Attack: %d\n", p.attack);
        printf("Defense: %d\n", p.defense);
        printf("Speed: %d\n", p.speed);
        printf("Special Attack: %d\n", p.special_attack);
        printf("Special Defense: %d\n", p.special_defense);
    }

    fclose(fptr);
}

void searchpkmn(){
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat","rb");
    int found = 0;

    if (!fptr){
        printf("Error opening file!!\n");
        return;
    }

    int id;
    printf("Enter Pokemon ID: ");
    scanf("%d",&id);

    while (fread(&p,sizeof(p),1,fptr)){
        if (p.id == id){
            printf("Pokemon ID: %d\n",p.id);
            printf("Pokemon Name: %s\n",p.name);
            printf("Primary Type: %s\n",p.type1);
            printf("Secondary Type: %s\n",p.type2);
            printf("HP: %d\n",p.hp);
            printf("Attack: %d\n",p.attack);
            printf("Defense: %d\n",p.defense);
            printf("Speed: %d\n",p.speed);
            printf("Special Attack: %d\n",p.special_attack);
            printf("Special Defense: %d\n",p.special_defense);
            found = 1;
            break;
        }
    }

    if (!found){
        printf("Pokemon not found!!\n");
    }
    fclose(fptr);
}

void searchbyname(){
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat","rb");
    int found = 0;
    char name[50];

    if (!fptr){
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon Name: ");
    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]=0;

    while (fread(&p,sizeof(p),1,fptr)){
        if (strcmp(p.name,name)==0){
            printf("Pokemon ID: %d\n",p.id);
            printf("Pokemon Name: %s\n",p.name);
            printf("Primary Type: %s\n",p.type1);
            printf("Secondary Type: %s\n",p.type2);
            printf("HP: %d\n",p.hp);
            printf("Attack: %d\n",p.attack);
            printf("Defense: %d\n",p.defense);
            printf("Speed: %d\n",p.speed);
            printf("Special Attack: %d\n",p.special_attack);
            printf("Special Defense: %d\n",p.special_defense);
            found = 1;
            break;
        }
    }

    if (!found){
        printf("Pokemon not found!!\n");
    }
    fclose(fptr);
}

void editmode(){
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat","rb+");
    int found = 0;
    int id;

    if (!fptr){
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon ID: ");
    scanf("%d",&id);

    while (fread(&p,sizeof(p),1,fptr)){
        if (p.id == id){
            printf("Enter new Pokemon ID: ");
            scanf("%d",&p.id);

            printf("Enter new Pokemon Name: ");
            fgets(p.name, sizeof(p.name), stdin);
            p.name[strcspn(p.name,"\n")]=0;

            printf("Enter new Primary type: ");
            fgets(p.type1,sizeof(p.type1),stdin);
            p.type1[strcspn(p.type1,"\n")]=0;

            printf("Enter new Secondary type: ");
            fgets(p.type2,sizeof(p.type2),stdin);
            p.type2[strcspn(p.type2,"\n")]=0;
            printf("Enter new HP: ");
            scanf("%d",&p.hp);
            printf("Enter new Defense: ");
            scanf("%d",&p.defense);
            printf("Enter new Speed: ");
            scanf("%d",&p.speed);
            printf("Enter new Special Attack: ");
            scanf("%d",&p.special_attack);
            printf("Enter new Special Defense: ");
            scanf("%d",&p.special_defense);

            fseek(fptr,-sizeof(p),SEEK_CUR);
            fwrite(&p,sizeof(p),1,fptr);
            found = 1;
            break;
        }
    }

    if (!found){
        printf("Pokemon not found!!\n");
    }
    fclose(fptr);
}

void deletemode(){
    deletepkmn();
}

void deletepkmn(){
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat","rb+");
    FILE *temp = fopen("temp.dat","wb");
    int found = 0;
    int id;

    if (!fptr){
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon ID: ");
    scanf("%d",&id);

    while (fread(&p,sizeof(p),1,fptr)){
        if (p.id == id){
            found = 1;
            continue;
        }
        fwrite(&p,sizeof(p),1,temp);
    }

    if (!found){
        printf("Pokemon not found!!\n");
    }
    else{
        printf("Pokemon deleted successfully!!\n");
    }
    fclose(fptr);
    fclose(temp);
    remove("pokedex.dat");
    rename("temp.dat","pokedex.dat");
}