# How to Run the Escort Ship Battle Programs

## Quick Start

Simply run any of the programs in your terminal:

```bash
./pi1
./pi2
./pi3
./pi4
```

## What to Expect

When you run a program, you'll see:

1. **Welcome Message**: "--- You Are Welcomed To The Battlefield ---"

2. **Main Menu** with options:
   - 1. Procedure
   - 2. Instructions
   - 3. Simulation Statistic
   - 4. Exit Main Menu

3. **If you choose option 1**, the program will ask for:
   - Maximum velocity of battleship shell (Vb_max)
   - Shell velocity of escort ship (m/s)
   - Size of canvas (D)
   - Number of escort ships (1-99)
   - Battleship type (U, M, R, or S)
   - Number of battleship movements (k) - for pi2, pi3, pi4

## Output Files

After running, check these files for results:

### pi1 and pi2:
- `Main.txt` - Main battle information
- `Escortship.txt` - Escort ship results
- `Battleship.txt` - Battleship results

### pi3 and pi4:
- `MainC.txt` - Main battle information
- `Final.txt` - Final battle results

## View Output Files

To see the results, use:

```bash
# View a specific output file
cat Main.txt
cat Escortship.txt
cat Battleship.txt

# Or for pi3/pi4
cat MainC.txt
cat Final.txt

# View all output files at once
cat *.txt
```

## Example Run

```bash
./pi1
# Then follow the prompts:
# 1 (choose Procedure)
# 100 (enter Vb_max)
# 50 (enter shell velocity)
# 10 (canvas size)
# 5 (number of escort ships)
# U (battleship type)
```



