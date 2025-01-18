typedef struct {
    int id;
    char name[50];
    char type[30];
    int level;
} Pokemon;

void addPokemon();
void displayPokemon();
void searchPokemon(int id);
void editPokemon(int id);
void deletePokemon(int id);