// Chris Hartmann
// KSU Fall 2022 Operating Systems
// Lab 2: banker.c

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// # of processes
#define n 5

// # of resource types
#define m 3


// Calculate the need matrix for the current snapshot
void calculateNeed(int need[n][m], int max[n][m], int allocation[n][m]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Check to determine if the system is in a safe state and if so, outputs
// the safe sequence
bool isSafe(int available[], int max[][m], int allocation[][m]) {
    // An array of size 'n*m' where 'need[i,j] = k' means process P[i] may
    // need 'k' more instances of resource type R[j] to complete its task
    int need[n][m];

    // Calculate the need matrix
    calculateNeed(need, max, allocation);

    // An array of size 'm' where 'work' is a workable copy of the 'available'
    // array
    int work[m];
    for(int i = 0; i < m; i++) {
        work[i] = available[i];
    }

    // An array of size 'n' where 'finish[i]' determines whether that process
    // has already appeared in the safe sequence previously
    bool finish[n] = {false};

    // An array of size 'n' to determine the 'safe sequence'
    int safeSeq[n];

    // An int to track which idex of the safe sequence we are checking for
    int count = 0;

    // Loop through the number of processes to enter the safe sequence
    while(count < n) {

        // Set up a flag to check if a match was found
        bool found = false;

        // Loop through the number of processes to determine if any of them
        // satisfy a safe state
        for(int i = 0; i < n; i++) {

            // If Process[i] has not already appeared in the safe sequence
            if(finish[i] == false) {

                // If the resources needed by Process[i] are less than what
                // is available, consider that process as having been
                // completed, "deallocating" the resources it took and adding
                // that process to the safe sequence
                int j;
                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j])
                        break;
                }
                if(j == m) {
                    for(int k = 0; k < m; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }

        // If a process requires more resources than the system could ever
        // allocate to it, then the system is not safe
        if(found = false) {
            printf("System is not in safe state.\n");
            return false;
        }
    }

    // The safe sequence has been built, meaning the system is in a safe state
    printf("System is in safe state.\nSafe sequence is: ");
    for(int i = 0; i < n; i++) {
        printf("%i ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

// 
int main() {
    // An array of size 'm' where 'available[j] = k' means there are 'k'
    // instances of resource type R[j] available for allocation
    int available[m];

    // An array of size 'n*m' where 'max[i,j] = k' means process P[i] may
    // request at most 'k' instances of resource type R[j]
    int max[n][m];

    // An array of size 'n*m' where 'allocation[i,j] = k' means process P[i]
    // is currently allocated 'k' instances of resource type R[j]
    int allocation[n][m];

    // Use file operations to read the given data from the input file
    FILE *file;
    
    // If the file was successfully opened ...
    if(file = fopen("input.txt", "r")) {
        // If not at the end of file, receive input for available
        if(!feof(file)) {
            fscanf(file, "%d %d %d", &available[0], &available[1], &available[2]);
        }

        // If not at the end of file, receive input for max
        for(int i = 0; i < n; i++) {
            if(!feof(file)) {
                fscanf(file, "%d %d %d", &max[i][0], &max[i][1], &max[i][2]);
            }
        }
        
        // If not at the end of file, receive input for allocation
        for(int i = 0; i < n; i++) {
            if(!feof(file)) {
                fscanf(file, "%d %d %d", &allocation[i][0], &allocation[i][1], &allocation[i][2]);
            }
        }

        // Close file stream after reaching end of needed inputs/file
        fclose(file);
    }

    // Check for safe state and output result
    isSafe(available, max, allocation);

    return 0;
}










