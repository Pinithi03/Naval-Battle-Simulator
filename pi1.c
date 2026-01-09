#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>


#define ESCORT_SHIP_COUNT 5
#define BATTLESHIP_COUNT 4
#define GRAVITY 9.81 // Gravitational acceleration (m/s^2)

// Structure to represent a ship
typedef struct {
    char ship_notation[3];
    char type_name[100];
    char gun_name[100];
    float impact;
    int angle_range;
    int min_angle;
    int max_angle;
    float max_velocity;
    float min_velocity;
} Ship;

// Function to calculate maximum range
float calculateMaxRange(float initial_velocity, int max_angle) {
    float theta_rad = max_angle * M_PI / 180.0; // Convert angle to radians
    return (initial_velocity * initial_velocity * sin(2 * theta_rad)) / GRAVITY;
}

// Function to calculate minimum range
float calculateMinRange(float initial_velocity, int min_angle) {
    float theta_rad = min_angle * M_PI / 180.0; // Convert angle to radians
    return (initial_velocity * initial_velocity * sin(theta_rad) * sin(theta_rad)) / (2 * GRAVITY);
}

// Function to check if a ship is destroyed
bool isShipDestroyed(float impact) {
    // Assuming a ship is destroyed if it is hit by a shell
    return impact > 0;
}

int main() {
    FILE *Main, *Escortship, *Battleship;
    
    
    Main = fopen("./Main.txt", "w");
    Escortship = fopen("./Escortship.txt", "w");
    Battleship = fopen("./Battleship.txt", "w");
	
    if (Main == NULL || Escortship == NULL || Battleship == NULL) {
        printf("File cannot be created");
        return -1;
    }
    
    fprintf(Escortship, "   -- You Lost -- \n\n");
    fprintf(Battleship, "   -- You Won -- \n\n");
    
    // Declare and initialize ships
    Ship eships_array[5];
    Ship bships_array[4];

    
    printf("\t--- You Are Welcomed To The Battlefield ---\n\n\n");
	
	int choice;
	do{
	
	
	printf("Main Menu\n\n1.Proceedure.\n2.Instructions.\n3.Simulation statistic.\n4.Exit Main Menu\n\n");
	printf("Select Your Choice:");
	scanf("%d", &choice);
	
	
	
	if(choice == 1){
		printf("\n--- Submenu ---\n\n");
		char *bship_names[] = {"USS Iowa (BB-61)", "MS King George V", "Richelieu", "Sovetsky Soyuz-class"};
    	char *bship_notations[] = {"U", "M", "R", "S"};
    	char *bgun_names[] = {"50-caliber Mark 7 gun", "(356mm)Mark VII gun", "(15inch)Mle 1935 gun", "(16inch)B-37 gun"};
    	
    	//function to copy strings(strcpy)
		int i;
    	for ( i = 0; i < 4; i++) {
        strcpy(bships_array[i].ship_notation, bship_notations[i]);
        strcpy(bships_array[i].type_name, bship_names[i]);
        strcpy(bships_array[i].gun_name, bgun_names[i]);
   	 }
   	  	// Print battleship informations
    	printf( "\nLoading The Battleship Details:\n\n");
    	printf("///////////////////////\n");
  	    for ( i = 0; i < 4; i++) {
        printf("B_ship Notation: %s\n", bships_array[i].ship_notation);
        printf("B_ship Ship Name: %s\n", bships_array[i].type_name);
        printf("B_ship Gun Name: %s\n\n", bships_array[i].gun_name);
    }
    	 // Assign values to escort ships
    char *eship_notations[] = {"Ea", "Eb", "Ec", "Ed", "Ee"};
    char *etype_names[] = {"1943A-class Destroyer", "Gabbiano-class Corvette", "Matsu-class Destroyer", "F-class Escort Ship", "Japanese Kaibokan"};
    char *egun_names[] = {"SK C/34 naval gun", "L/47 dual-purpose gun", "Type 89 dual-purpose gun", "SK C/32 naval gun", "(4.7 inch)naval guns"};
    float eimpacts[] = {0.08, 0.06, 0.07, 0.05, 0.04};
    int eangle_ranges[] = {20, 30, 25, 50, 70};
    float Vb_max = 0.0; // Maximum velocity of the battleship shell
    printf("--Enter the maximum velocity of the battleship shell (Vb_max): ");
    scanf("%f", &Vb_max);

    for ( i = 0; i < 5; i++) {
        strcpy(eships_array[i].ship_notation, eship_notations[i]);
        strcpy(eships_array[i].type_name, etype_names[i]);
        strcpy(eships_array[i].gun_name, egun_names[i]);
        eships_array[i].impact = eimpacts[i];
        eships_array[i].angle_range = eangle_ranges[i];
        eships_array[i].min_angle = rand() % 90; // Randomly generate min angle between 0 and 89.
        eships_array[i].angle_range = eangle_ranges[i];
        if (strcmp(eships_array[i].ship_notation, "Ea") == 0) {
            eships_array[i].max_velocity = 1.2 * Vb_max;
        } else {
            eships_array[i].max_velocity = rand() / (float)RAND_MAX * Vb_max; // Randomly generate max velocity
        }
        eships_array[i].min_velocity = rand() / (float)RAND_MAX * eships_array[i].max_velocity; // Randomly generate min velocity
        eships_array[i].max_angle = eships_array[i].min_angle + eships_array[i].angle_range; // Calculate max angle
    }
    	// Print escort ship information 
    printf("\n Loading The Escort Ship Details:\n\n");
    for ( i = 0; i < 5; i++) {
        printf("E_Ship Notation: %s\n", eships_array[i].ship_notation);
        printf( "E_Ship Type Name: %s\n", eships_array[i].type_name);
        printf( "E_Ship Angle Range: %d\n", eships_array[i].angle_range);
        printf( "E_Ship Gun Name: %s\n", eships_array[i].gun_name);
        printf( "E_Ship Impact: %.2f\n", eships_array[i].impact);
        printf( "E_Ship Min Angle: %d\n", eships_array[i].min_angle);
        printf( "E_Ship Max Angle: %d\n", eships_array[i].max_angle);
        printf( "E_Ship Max Velocity: %.2f\n", eships_array[i].max_velocity);
        printf( "E_Ship Min Velocity: %.2f\n\n", eships_array[i].min_velocity);
    }
            
    	printf("-- Shall We Play? --\n\n");
    	break;
    	
	}
	else if(choice == 2){
		printf("-- Instructions --\n\n");
	
	}
	else if(choice == 3){
		printf("-- Simulation Statistic --\n\n");
	}
 	else if(choice == 4) {
            printf("-- Exit Main Menu -- \n");
            return 0;
        }
    else {
            printf("Invalid choice. Your choice must be between 1 to 4 ::::..\n\n");
        }
	
	}while(1);
	
	
    // Input shell velocity of the escort ship
    float shell_velocity;
    printf("--Enter the shell velocity of the escort ship (m/s): ");
    scanf("%f", &shell_velocity);

    // Declare and initialize ships
    Ship eships[5];
    Ship bships[4];

   

    // Seed the random number generator
    srand(time(NULL));

    int D, num_escort_ships;

    printf("Enter the size of the canvas (D): ");
    scanf("%d", &D);
    printf("Enter the number of escort ships (between 1 and 99): ");
    scanf("%d", &num_escort_ships);

    if (num_escort_ships < 1 || num_escort_ships > 100) {
        printf("Invalid number of escort ships. Please enter a number between 1 and 99.\n");
        fclose(Main);
        fclose(Escortship);
        return 1;
    }

    // Array of ship names
    char *ship_names[] = {"Ea", "Eb", "Ec", "Ed", "Ee"};

    // Initialize canvas
    char canvas[D][D][3];
    int i, j;
    for ( i = 0; i < D; i++) {
        for (j = 0; j < D; j++) {
            canvas[i][j][0] = '\0';
        }
    }

    // Place the escort ships randomly on the canvas and save their positions
    fprintf(Main, "Escort Ship Positions:\n");
    for ( i = 0; i < num_escort_ships; i++) {
        // Generate random coordinates for the ship
        int x, y;
        do {
            x = rand() % D;
            y = rand() % D;
        } while (canvas[x][y][0] != '\0'); // Ensure the cell is empty

        // Place the ship on the canvas with a unique identifier
        strcpy(canvas[x][y], ship_names[i % 5]); // Store the ship name in the cell

        // Save the ship position and details to the file
        fprintf(Main, "Ship %d: %s at position (%d, %d)\n", i + 1, ship_names[i % 5], x, y);
    }

    // Place the battleship on the canvas
    char bship[2];
    printf("Enter the Battleship type (U, M, R, S): ");
    scanf(" %s", bship);

    int x_battleship, y_battleship;
    do {
        x_battleship = rand() % D;
        y_battleship = rand() % D;
        } while (canvas[x_battleship][y_battleship][0] != '\0'); // Ensure the cell is empty

    // Place the battleship on the canvas
    strcpy(canvas[x_battleship][y_battleship], bship);
    fprintf(Main, "\nBattleship %s at position (%d, %d)\n", bship, x_battleship, y_battleship);

    // Print the canvas with ships
    printf("\nLoading The Battleship Ships\n");
    printf("---------The Battlefield [Starts]---------\n");
    for ( i = 0; i < D; i++) {
        for ( j = 0; j < D; j++) {
            if (canvas[i][j][0] == '\0') {
                printf(" . "); // Empty cell
            } else {
                printf("%s ", canvas[i][j]); // Ship cell
            }
        }
        printf("\n");
    }
    printf("---------The Battlefield [Ends]----------");
 // Calculate and print maximum and minimum ranges for each escort ship
    printf("\nProjectile Ranges Of Escort Ship:\n");
    for ( i = 0; i < 5; i++) {
        float max_range = calculateMaxRange(shell_velocity, eships_array[i].max_angle);
        float min_range = calculateMinRange(shell_velocity, eships_array[i].min_angle);
        printf("Escort Ship %s: Max Range = %.2f m, Min Range = %.2f m\n", eships_array[i].ship_notation, max_range, min_range);
    }
    
    // Print distances between Escort Ships and Battleships
    fprintf(Main, "\nDistances between E_Ships and B_ships:\n");
    for ( i = 0; i < num_escort_ships; i++) {
        int eship_x = -1, eship_y = -1, x, y;
        for ( x = 0; x < D; x++) {
            for ( y = 0; y < D; y++) {
                if (strcmp(canvas[x][y], ship_names[i % 5]) == 0) {
                    eship_x = x;
                    eship_y = y;
                    break;
                }
            }
            if (eship_x != -1) break;
        }
        if (eship_x != -1) {
            float distance = sqrt(pow(x_battleship - eship_x, 2) + pow(y_battleship - eship_y, 2));
            fprintf(Main, "Distance between %s and BattleShip: %.2f\n", ship_names[i % 5], distance);
        }
    }

    


    // Assign values to escort ships
    char *eship_notations[] = {"Ea", "Eb", "Ec", "Ed", "Ee"};
    char *etype_names[] = {"1943A-class Destroyer", "Gabbiano-class Corvette", "Matsu-class Destroyer", "F-class Escort Ship", "Japanese Kaibokan"};
    char *egun_names[] = {"SK C/34 naval gun", "L/47 dual-purpose gun", "Type 89 dual-purpose gun", "SK C/32 naval gun", "(4.7 inch)naval guns"};
    float eimpacts[] = {0.08, 0.06, 0.07, 0.05, 0.04};
    int eangle_ranges[] = {20, 30, 25, 50, 70};
    float Vb_max = 0.0; // Maximum velocity of the battleship shell
    

    for ( i = 0; i < 5; i++) {
        strcpy(eships_array[i].ship_notation, eship_notations[i]);
        strcpy(eships_array[i].type_name, etype_names[i]);
        strcpy(eships_array[i].gun_name, egun_names[i]);
        eships_array[i].impact = eimpacts[i];
        eships_array[i].angle_range = eangle_ranges[i];
        eships_array[i].min_angle = rand() % 90; // Randomly generate min angle (0-89)
        eships_array[i].angle_range = eangle_ranges[i];
        if (strcmp(eships_array[i].ship_notation, "Ea") == 0) {
            eships_array[i].max_velocity = 1.2 * Vb_max;
        } else {
            eships_array[i].max_velocity = rand() / (float)RAND_MAX * Vb_max; // Randomly generate max velocity
        }
        eships_array[i].min_velocity = rand() / (float)RAND_MAX * eships_array[i].max_velocity; // Randomly generate min velocity
        eships_array[i].max_angle = eships_array[i].min_angle + eships_array[i].angle_range; // Calculate max angle
    }

    // Assign values to battleships
    char *bship_names[] = {"USS Iowa (BB-61)", "MS King George V", "Richelieu", "Sovetsky Soyuz-class"};
    char *bship_notations[] = {"U", "M", "R", "S"};
    char *bgun_names[] = {"50-caliber Mark 7 gun", "(356mm)Mark VII gun", "(15inch)Mle 1935 gun", "(16inch)B-37 gun"};

    for ( i = 0; i < 4; i++) {
        strcpy(bships_array[i].ship_notation, bship_notations[i]);
        strcpy(bships_array[i].type_name, bship_names[i]);
        strcpy(bships_array[i].gun_name, bgun_names[i]);
        bships_array[i].impact = 0; // Not initialized for battleships in this simplified version
        bships_array[i].angle_range = 0; // Not initialized for battleships in this simplified version
    }

    // Print escort ships
    fprintf(Main, "\nEscort Ship Details:\n");
    for ( i = 0; i < 5; i++) {
        fprintf(Main, "Escort Ship Notation: %s\n", eships_array[i].ship_notation);
        fprintf(Main, "Escort Ship Type Name: %s\n", eships_array[i].type_name);
        fprintf(Main, "Escort Ship Angle Range: %d\n", eships_array[i].angle_range);
        fprintf(Main, "Escort Ship Gun Name: %s\n", eships_array[i].gun_name);
        fprintf(Main, "Escort Ship Impact: %.2f\n", eships_array[i].impact);
        fprintf(Main, "Escort Ship Min Angle: %d\n", eships_array[i].min_angle);
        fprintf(Main, "Escort Ship Max Angle: %d\n", eships_array[i].max_angle);
        fprintf(Main, "Escort Ship Max Velocity: %.2f\n", eships_array[i].max_velocity);
        fprintf(Main, "Escort Ship Min Velocity: %.2f\n\n", eships_array[i].min_velocity);
    }

    // Print battleships
    fprintf(Main, "\nBattleship Details:\n");
    for ( i = 0; i < 4; i++) {
        fprintf(Main, "Battleship Notation: %s\n", bships_array[i].ship_notation);
        fprintf(Main, "Battleship Ship Name: %s\n", bships_array[i].type_name);
        fprintf(Main, "Battleship Gun Name: %s\n", bships_array[i].gun_name);
        fprintf(Main, "Battleship Impact: %.2f\n", bships_array[i].impact);
        fprintf(Main, "Battleship Angle Range: %d\n", bships_array[i].angle_range);
        fprintf(Main, "Battleship Min Angle: %d\n", bships_array[i].min_angle);
        fprintf(Main, "Battleship Max Angle: %d\n\n", bships_array[i].max_angle);
    }
    
    
     // Simulate the battle
    // Assume battleship fires at random escort ship
    int target_escort_ship = rand() % num_escort_ships;
    float bshell_impact = 0.9; // Example shell impact value for battleship
    bool battleship_destroyed = false;
    int battleship_index = -1;
    float total_time = 0.0; // Total time taken in the battle

    for (i = 0; i < num_escort_ships; i++) {
        // Assume each escort ship fires once
        float eshell_impact = 0.7; // Example shell impact value for escort ship
        if (i == target_escort_ship) {
            // Calculate if battleship is destroyed
            battleship_destroyed = isShipDestroyed(bshell_impact);
            if (battleship_destroyed) {
                battleship_index = i;
                total_time += 1.0; // Assuming each shot takes 1 second
                break;
            }
        } else {
            // Calculate if current escort ship is destroyed
            bool escort_ship_destroyed = isShipDestroyed(eshell_impact);
            if (escort_ship_destroyed) {
                fprintf(Escortship, "Escort Ship %d (%s) destroyed the battleship.\n", i + 1, ship_names[i % 5]);
            }
        }
    }

    // Print if battleship is destroyed
    if (battleship_destroyed) {
        fprintf(Escortship, "Battleship destroyed by Escort Ship %d (%s).\n", battleship_index + 1, ship_names[battleship_index % 5]);
    } else {
        fprintf(Escortship, "Battleship survived the attack.\n");
    }

    // Write details of escort ships hit by the battleship to the file
    fprintf(Battleship, "Details of Escort Ships Hit by the Battleship:\n");
    float time_to_hit = 0.0; // Initialize time_to_hit outside the loop
    for (i = 0; i < num_escort_ships; i++) {
        if (i != target_escort_ship) {
            // Check if the current escort ship was hit
            bool escort_ship_hit = isShipDestroyed(0.7); // Assuming shell impact value for escort ship
            if (escort_ship_hit) {
                // Write hit details with current time_to_hit value
                fprintf(Battleship, "\nEscort Ship %d hit by the Battleship at time %.2f seconds.\n", i + 1, time_to_hit);
                // Increment time_to_hit for the next hit
                time_to_hit += 1.0; // Assuming each shot takes 1 second
            }
        }
    }

    // Calculate total time taken
    total_time += time_to_hit;

    // Write total time taken to the relevant file
    if (battleship_destroyed) {
        fprintf(Escortship, "\nTotal time taken for the battle: %.2f seconds (Battleship destroyed).\n", total_time);
    } else {
        fprintf(Escortship, "\nTotal time taken for the battle: %.2f seconds (Battleship survived).\n", total_time);
    }

    
	fclose(Main); // Close the initial condition file
	fclose(Battleship); // Close the final condition file
    fclose(Escortship); // Close the final condition file

    return 0;
}
