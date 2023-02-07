#include <stdio.h>
#include <stdlib.h>

#define RECORDS 202599
#define STR_LEN 11
#define COMMAND_LEN 255

#define NUM_SPLITS 3
#define NUM_CLASSES 2

typedef enum {TRAIN, VAL, TEST} Split;
typedef enum {FEMALE, MALE} Class;

typedef struct {
    char nome[STR_LEN];
    Split split;
    Class class;
} Image;

int main() {

    // Trash variables
    int aux_num;
    char aux_char[STR_LEN];
    // String to store system calls
    char command[COMMAND_LEN];
    char folders[NUM_SPLITS][STR_LEN] = {"TrainSet", "ValSet", "TestSet"};
    // Dataset
    Image dataset[RECORDS];
    // File pointers
    FILE *split_file = NULL;
    FILE *class_file = NULL;


    // Open split file
    split_file = fopen("./metadata/list_eval_partition.txt", "r");
    if (split_file == NULL) printf("Error opening file");
    // Read file name and split category
    for (int i = 0; i < RECORDS; i++)
        fscanf(split_file, "%s %d", dataset[i].nome, &dataset[i].split);
    // Close file
    fclose(split_file);

    // Open class file
    class_file = fopen("./metadata/list_attr_celeba.txt", "r");
    if (class_file == NULL) printf("Error opening file");
    // Skip first 2 lines
    while ((aux_num = fgetc(class_file)) != '\n' && aux_num != EOF) {/* nothing, just skip the line */}
    while ((aux_num = fgetc(class_file)) != '\n' && aux_num != EOF) {/* nothing, just skip the line */}
    // Read class
    for (int i = 0; i < RECORDS; i++)
        fscanf(class_file, "%*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d", &dataset[i].class);
    // Close file
    fclose(class_file);

    // Create directories
    for(int i=0; i<NUM_SPLITS; i++) {
        sprintf(command, "mkdir ./dataset/%s", folders[i]);
        system(command);
        for(int j=0; j<NUM_CLASSES; j++) {
            sprintf(command, "mkdir ./dataset/%s/%d", folders[i], j);
            system(command);
        }
    }

    // Move images
    for(int i=0; i<RECORDS; i++) {

        // Progress bar
        printf("PROGRESS: %2.2f%%\r", ((i+1)/(float)RECORDS));

        // Command to move image
        sprintf(command, "mv ./dataset/%s ./dataset/%s/%d", dataset[i].nome, folders[dataset[i].split], dataset[i].class == MALE ? MALE : FEMALE);
        // Execute command
        system(command);
    }

    return 0;
}