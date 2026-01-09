# 🚢 Naval Battle Simulator

Naval Battle Simulator is a C-based combat simulation developed as a first-year programming assignment and expanded to model fleet-level naval engagements. The project simulates battles between a single battleship and multiple escort ships, allowing experimentation with firing strategies, movement logic, and damage modelling while generating detailed execution logs for analysis.

## 📌 Overview

The simulator is organised into multiple stages that progressively introduce more advanced mechanics. Each stage builds on a shared naval battlefield abstraction, enabling structured growth from basic combat logic to strategy-driven decision making.

The project is implemented entirely in standard C, ensuring platform independence. The repository includes source files, configuration logic, and sample outputs produced during development and testing.

## ⚙️ Key Features

### Configurable Battlefield
- Define grid dimensions at runtime
- Select battleship type and escort ship composition
- Customise each simulation run interactively

### Probabilistic Combat System
- Randomised ship placement and movement paths
- Variable weapon accuracy and firing arcs
- Dynamic encounter outcomes across runs

### Progressive Simulation Design
- Each part extends previous logic without redesigning the core system
- Incremental complexity from basic combat to tactical optimisation

##  Simulation Breakdown

###  Part 1 (`pi1.c`) – Core Combat Engine
- Basic combat loop implementation
- Hit detection and battlefield visualisation
- Battle statistics and run tracking
- Static ship positioning
- Initial ship configuration and display

###  Part 2 (`pi2.c`) – Mobility & Weapon Reliability
- Battleship movement trajectories
- Dynamic repositioning during combat
- Multiple movement cycles (k movements)
- Enhanced battlefield state tracking
- Movement-based distance calculations

###  Part 3 (`pi3.c`) – Damage Accumulation
- Escort ship impact power tracking
- Battleship health system (initial health: 1.00)
- Survival determined by cumulative damage instead of single hits
- Health-based destruction logic
- Damage accumulation over multiple encounters

###  Part 4 (`pi4.c`) – Tactical Optimisation
- Reload-aware firing logic
- Intelligent target prioritisation
- Maximised enemy neutralisation with reduced incoming damage
- Advanced battle simulation with health tracking
- Optimised combat resolution

## 🛠️ Technologies Used

- **Language:** C
- **Paradigm:** Procedural programming
- **Environment:** Platform-independent (GCC compatible)
- **Compilation:** `gcc -o pi[1-4] pi[1-4].c -lm`

## 📂 Repository Contents

- `pi1.c` - Core Combat Engine implementation
- `pi2.c` - Mobility & Weapon Reliability implementation
- `pi3.c` - Damage Accumulation implementation
- `pi4.c` - Tactical Optimisation implementation
- `RUN_INSTRUCTIONS.md` - Detailed usage guide
- Sample output logs from test executions
- Documentation and instructions for running the simulator



### Prerequisites
- GCC compiler (or compatible C compiler)
- Math library support (`-lm` flag)

### Compilation
```bash
gcc -o pi1 pi1.c -lm
gcc -o pi2 pi2.c -lm
gcc -o pi3 pi3.c -lm
gcc -o pi4 pi4.c -lm
```

### Running the Simulator
```bash
./pi1  # Run Part 1 - Core Combat Engine
./pi2  # Run Part 2 - Mobility & Weapon Reliability
./pi3  # Run Part 3 - Damage Accumulation
./pi4  # Run Part 4 - Tactical Optimisation
```

### Interactive Input
Each program will prompt you for:
- Maximum velocity of battleship shell (Vb_max)
- Shell velocity of escort ship (m/s)
- Canvas size (D)
- Number of escort ships (1-99)
- Battleship type (U, M, R, or S)
- Number of battleship movements (k) - for parts 2, 3, and 4

### Output Files
- **Parts 1 & 2:** `Main.txt`, `Escortship.txt`, `Battleship.txt`
- **Parts 3 & 4:** `MainC.txt`, `Final.txt`

For detailed instructions, see [RUN_INSTRUCTIONS.md](RUN_INSTRUCTIONS.md).

## Learning Outcomes

- Structured program design in C
- Simulation modelling and randomised systems
- Strategic decision logic implementation
- Incremental development and testing
- File I/O and data persistence
- Memory management and array handling
- Mathematical modelling (projectile physics)

## Ship Types

### Battleships
- **U** - USS Iowa (BB-61) with 50-caliber Mark 7 gun
- **M** - MS King George V with (356mm) Mark VII gun
- **R** - Richelieu with (15inch) Mle 1935 gun
- **S** - Sovetsky Soyuz-class with (16inch) B-37 gun

### Escort Ships
- **Ea** - 1943A-class Destroyer (SK C/34 naval gun)
- **Eb** - Gabbiano-class Corvette (L/47 dual-purpose gun)
- **Ec** - Matsu-class Destroyer (Type 89 dual-purpose gun)
- **Ed** - F-class Escort Ship (SK C/32 naval gun)
- **Ee** - Japanese Kaibokan ((4.7 inch) naval guns)

## Technical Details

### Physics Model
- Gravitational acceleration: 9.81 m/s²
- Projectile range calculations using standard ballistic equations
- Angle-based firing arcs (min/max angles)
- Velocity-dependent range determination

### Battlefield Representation
- 2D grid-based canvas (configurable size D×D)
- Random ship placement with collision avoidance
- Real-time position tracking
- Distance calculations between ships



Developed as a first-year programming assignment, demonstrating progressive complexity in simulation design and C programming fundamentals.
