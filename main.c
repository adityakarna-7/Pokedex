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
void dataentrymode();
void deletemode();
void searchbyname();
void editmode();
void searchmode();

int main(){
    int option;
    do{
        printf("-----POKEDEX-----\n");
        printf("1. Data Entry Mode\n");
        printf("2. Search Mode\n");
        printf("3. Edit Mode\n");
        printf("4. Delete Mode\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
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
            deletemode;
            break;

        case 5:
            printf("Exiting.....\n");
        
        default:
            printf("Invalid Option! Select correct option....\n");
        }
        
    }while(option != 5);
    return 0;
}

void dataentrymode(){
    char cont;
    do
    {
        addpkmn();
        printf("Do you want to add more Pokemon? (y/n): ");
        scanf("%c",&cont);
    } while (cont == 'y' || cont == 'Y');
    
}

void addpkmn(){
    struct pokemon p;
    FILE *fptr = fopen("pokedex.dat","ab");

    if (!fptr){
        printf("Error opening file!!\n");
        return;
    }

    printf("Enter Pokemon ID: ");
    scanf("%d",&p.id);

    printf("Enter Pokemon Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name,"\n")] = 0;

    printf("Enter Primary type: ");
    fgets(p.type1,sizeof(p.type1),stdin);
    p.type1[strcspn(p.type1,"\n")]=0;

    printf("Enter Secondary type: ");
    fgets(p.type2,sizeof(p.type2),stdin);
    p.type2[strcspn(p.type2,"\n")]=0;
    printf("Enter HP: ");
    scanf("%d",&p.hp);
    printf("Enter Defense: ");
    scanf("%d",&p.defense);

    fwrite(&p,sizeof(p),1,fptr);
    fclose(fptr);
    printf("Pokemon added successfully!!\n");


}

void searchmode(){
    int option;
    do{
        printf("-----SEARCH MODE-----\n");
        printf("1. Search by Name\n");
        printf("2. Search by Type\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        getchar();

        switch (option)
        {
        case 1:
            searchbyname();
            break;

        case 2:
            searchbytype();
            break;

        case 3:
            searchbyid();
            break;

        case 4:
            displaypkmn();
            break;

        case 5:
            printf("Exiting.....\n");
        
        default:
            printf("Invalid Option! Select correct option....\n");
        }
        
    }while(option != 4);
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
            p.name[strcspn(p.name,"\n")] = 0;

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