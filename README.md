# TP_cpp (Pokemon Project)


## Classes

*   **Pokemon Class**: Represents individual Pokemon with attributes like ID, name, HP, attack, defense, and speed.
*   **Pokemon Collections**: Classes like `PokemonVector`, `PokemonParty`, and `PokemonAttack` to manage groups of Pokémon.
*   **Pokedex**: A singleton class to load and provide access to Pokémon data from a CSV file.


## Project Structure

```
.
├── CMakeLists.txt
├── main.cpp
├── sources/
│   └── pokedex.csv
├── utils/
│   ├── inc/
│   │   ├── Pokemon.h
│   │   ├── Pokedex.h
│   │   ├── PokemonVector.h
│   │   ├── PokemonParty.h
│   │   └── PokemonAttack.h
│   └── src/
│       └── (*.cpp source files)
└── tests/
    ├── test_pokemon.cpp
    ├── test_pokedex.cpp
    ├── test_pokemon_vector.cpp
    ├── test_pokemon_party.cpp
    └── test_pokemon_attack.cpp
```

## Building the Project

### Prerequisites

*   A C++20 compatible compiler (like GCC or Clang)
*   CMake (version 3.28 or higher)

### Build Steps

1.  **Clone the repository:**
    ```bash
    git clone https://github.com/Mael-Archenault/TP_cpp.git
    cd TP_cpp
    ```

2.  **Create a build directory:**
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure with CMake:**
    ```bash
    cmake ..
    ```

4.  **Compile the project:**
    ```bash
    make
    ```

    This will create the main executable `TP_cpp` and the test executables in the `build` directory.

## Running the Application

```bash
./TP_cpp
```

(currently nothing in this executable)

## Running Tests

You can run the tests using CTest after building the project.

```bash
cd build
ctest
```

Alternatively, you can run individual test executables directly:

```bash
./test_pokedex
./test_pokemon
# etc.
```