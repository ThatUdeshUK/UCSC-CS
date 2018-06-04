#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of the memory
#define MAX 2600

// Function prototypes
void allocate(char *processID, int size);
void release(char *processID);
void snapshot();

// Create a stuct the stucture the memory node
struct memory {
    char *processID;
    int start;
    int size;
    int isFree;
    struct memory *next;
};

// Starting node of the linked list
struct memory *START = NULL;

int main() {
    printf("\n**Commands**\nA : Allocate Memory\nR : Release Memory\nS : Print Snapshot\nQ : Quit\n\n");
    allocate("System", 400);
    snapshot();
    char command;
    int run = 1;
    while (run == 1) {
        printf("\nEnter command:");
        scanf(" %c", &command);
        switch (command) {
            case 'A':
                printf("Enter process id: ");
                char in[10];
                scanf("%s", &in);
                char *processId = (char *) malloc(strlen(in) + 1);
                strcpy(processId, in);
                printf("Enter memory size: ");
                int size;
                scanf("%d", &size);
                allocate(processId, size);
                snapshot();
                break;
            case 'R':
                printf("Enter process id: ");
                char releaseProcessId[10];
                scanf("%s", &releaseProcessId);
                release(releaseProcessId);
                snapshot();
                break;
            case 'S':
                snapshot();
                break;
            case 'Q':
                run = 0;
                break;
            default:
                printf("Invalid Command\n\n**Commands**\nA : Allocate Memory\nR : Release Memory\nS : Print Snapshot\nQ : Quit\n");
                break;
        }
    }
    return 0;
}

// Allocate memory
void allocate(char *processID, int size) {
    // Check whether starting node is null and if so whether memory size is compatible
    if (START == NULL) {
        if (MAX >= size) {
            printf("Allocate %s of size: %d\n", processID, size);
            // Allocate memory for a node
            struct memory *temp = (struct memory*) malloc(sizeof(struct memory));
            // Check whether memory is allocated
            if (temp != NULL) {
                // Assign process data to the allocated process memory node
                temp->processID = processID;
                temp->start = 0;
                temp->size = size;
                temp->isFree = 0;

                // Check whether more memory is available if so create free memory node
                if (MAX > size) {
                    struct memory *freeMemory = (struct memory*) malloc(sizeof(struct memory));
                    // Check whether memory is allocated 
                    if (freeMemory != NULL) {
                        freeMemory->processID = "Free";
                        freeMemory->start = size;
                        freeMemory->size = MAX - size;
                        freeMemory->isFree = 1;
                        freeMemory->next = NULL;

                        // Connect process memory node
                        temp->next = freeMemory;
                    } else {
                        printf("Out of memory");
                    }
                }
                // Assign process node to starting node
                START = temp;
            } else {
                printf("Out of memory");
            }
        } else {
            printf("No memory available");
        }
    } else {
        // Create temporary node to traverse linked list 
        struct memory *PTR = START;

        // Flag to check whether memory is allocated or not
        int noMemoryAvailable = 1;

        // Check whether linked list is not null 
        while (PTR != NULL) {
            // Check whether a free pratition is available and that partition's size is compatible with size needed
            if (PTR->isFree == 1 && PTR->size >= size) {
                printf("Allocate %s of size: %d\n", processID, size);
                // Change noMemory flag to false
                noMemoryAvailable = 0;
                // Keep end location of free memory partion 
                int end = PTR->start + PTR->size;
                // Create new free memory partion if existing free parttiion's size is greater than needed 
                if (PTR->size > size) {
                    struct memory *freeMemory = (struct memory*) malloc(sizeof(struct memory));
                    if (freeMemory != NULL) {
                        freeMemory->processID = "Free";
                        freeMemory->start = PTR->start + size;
                        freeMemory->size = end - freeMemory->start;
                        freeMemory->isFree = 1;
                        freeMemory->next = PTR->next;

                        // Connect newly created free memory partition to linked list
                        PTR->next = freeMemory;
                    } else {
                        printf("Out of memory");
                    }
                }
                // Assign process data and change the size to process's size
                PTR->processID = processID;
                PTR->size = size;
                PTR->isFree = 0;
                break;
            }
            PTR = PTR->next;
        }
        if (noMemoryAvailable) 
            printf("No memory available");
    }
}

// Release memory
void release(char *processID) {
    // Flag to check whether process is released or not
    int processNotReleased = 1;

    // Create two temporary node to traverse linked list 
    struct memory *PTR = START;
    struct memory *PREPTR = NULL;

    // Check whether linked list is not empty
    while (PTR != NULL) {
        // Check whrther processID exist's in linked lst
        if (strcmp(processID, PTR->processID) == 0) {
            printf("Release %s\n", processID);
            // Change processNotReleased to false
            processNotReleased = 0;
            // Change process to a free partition 
            free(PTR->processID);
            PTR->processID = "Free";
            PTR->isFree = 1;
            // Assign the next node to temporary variable
            struct memory *POSTPTR = PTR->next;
            // Check whether next node is not null and it is free
            if (POSTPTR != NULL && POSTPTR->isFree == 1) {
                // Expand the changed free partion size to fill next free partition
                PTR->size = PTR->size + POSTPTR->size;
                PTR->next = POSTPTR->next;
                // Free the memory of the redundent node
                free(POSTPTR);
            }
            // Check whether previous node is not null and it is free
            if (PREPTR != NULL && PREPTR->isFree == 1) {
                // Expand the previous free partion size to fill changed free partition
                PREPTR->size = PREPTR->size + PTR->size;
                PREPTR->next = PTR->next;
                // Free the memory of the redundent node
                free(PTR);
            }
            break;
        }
        PREPTR = PTR;
        PTR = PTR->next;
    }
    if (processNotReleased) 
        printf("No process with id: %s\n", processID);
}

// Print snapshot of memory
void snapshot() {
    printf("\n-- Memory Snapshot : START --\n");
    // Create two temporary node to traverse linked list 
    struct memory *PTR = START;
    while (PTR != NULL) {
        // Print processId, start, end, size of partition and whether partition is free 
        printf("Process: %s, Start: %d, End: %d, Size: %d, IsFree: %d\n", PTR->processID, PTR->start, PTR->start + PTR->size, PTR->size, PTR->isFree);
        PTR = PTR->next;
    }
    printf("-- Memory Snapshot : END --\n\n");
}