# Jank Invaders (Space Invaders Clone)

A Space Invaders-inspired arcade game built with C++ and SFML as a college project.

## Description

Jank Invaders is a semi-working Space Invaders clone featuring a single level with alien enemies and player-controlled spaceship. The player must shoot down all alien spaceships while avoiding their projectiles. The game features a one-life system - eliminate all aliens to win, or get hit and lose.

## Features

- Player-controlled spaceship with left/right movement
- Shooting mechanics for both player and aliens
- 4x8 grid of alien enemies
- Collision detection between bullets and entities
- Game timer and best time tracking
- Simple sprite-based graphics using SFML

## Prerequisites

- C++17 or later
- SFML 3.0 (Graphics, Window, System components)
- CMake 3.12 or later
- A C++ compiler (GCC/G++ on Linux)

## Installation

### Linux

1. Install SFML:
```sh
sudo apt-get update
sudo apt-get install libsfml-dev
```

2. Clone the repository:
```sh
git clone <repository-url>
cd space_invaders
```

3. Build the project:
```sh
mkdir -p build
cd build
cmake ..
make
```

4. Run the game:
```sh
./SFML_Template
```

## Controls

- **Left Arrow**: Move spaceship left
- **Right Arrow**: Move spaceship right
- **Space**: Fire projectile

## Project Structure

```
space_invaders/
├── main.cpp          # Main game loop and logic
├── Alien.h/cpp       # Alien enemy class
├── Player.h/cpp      # Player spaceship class
├── Bullet.h/cpp      # Projectile class
├── CMakeLists.txt    # Build configuration
├── Invaders.png      # Sprite sheet
├── time.txt          # Best time storage
└── README.md         # This file
```

## Known Issues

As documented in [`final.txt`](final.txt):

- Alien shooting timing can be inconsistent at the 3-second mark
- Multiple projectiles may spawn in rapid succession
- No cooldown system between shots
- Frame rate inconsistencies affect gameplay
- Most code is concentrated in [`main.cpp`](main.cpp) rather than being modularized

## Future Improvements

- Implement proper shooting cooldown system
- Add multiple lives for the player
- Create additional levels
- Improve frame rate management
- Better code organization and modularization
- Add sound effects and background music

## Technical Details

The game uses:
- **SFML Graphics**: For rendering sprites and shapes
- **SFML Window**: For window management and event handling
- **SFML System**: For timing and vector operations
- **C++ Chrono**: For game timing and duration tracking

## Build Configuration

The project uses CMake with the following key settings:
- C++ Standard: 17
- SFML Version: 3.0
- Cross-platform support (Linux and Windows with MinGW)

See [`CMakeLists.txt`](CMakeLists.txt) for full build configuration.

## Credits

Created by Charles Mowbray as a college project.

## License

Educational project - see course materials for usage restrictions.