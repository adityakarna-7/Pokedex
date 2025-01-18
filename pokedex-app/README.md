# Pokedex Application

This is a simple Pokedex application implemented in C. The application allows users to manage a collection of Pokémon entries with functionalities to add, display, search, edit, and delete Pokémon.

## Features

- **Add Pokémon**: Input details for a new Pokémon and save it to a binary file named `pokedex.dat`.
- **Display Pokémon**: Read from the `pokedex.dat` file and display all stored Pokémon entries.
- **Search Pokémon**: Search for a Pokémon by its ID and display its details if found.
- **Edit Pokémon**: Modify the details of an existing Pokémon entry in the `pokedex.dat` file.
- **Delete Pokémon**: Remove a Pokémon entry from the `pokedex.dat` file.

## Project Structure

```
pokedex-app
├── src
│   ├── main.c            # Main function and menu-driven interface
│   ├── add_pokemon.c     # Functionality to add a new Pokémon
│   ├── display_pokemon.c  # Functionality to display all Pokémon
│   ├── search_pokemon.c   # Functionality to search for a Pokémon
│   ├── edit_pokemon.c     # Functionality to edit a Pokémon entry
│   ├── delete_pokemon.c   # Functionality to delete a Pokémon entry
│   └── pokedex.h          # Header file with structure and function prototypes
├── Makefile               # Build instructions for the project
└── README.md              # Project documentation
```

## Build Instructions

To compile the project, navigate to the project directory and run:

```
make
```

This will generate the executable for the Pokedex application.

## Running the Application

After building the project, you can run the application using:

```
./pokedex-app
```

Follow the on-screen instructions to manage your Pokémon entries.