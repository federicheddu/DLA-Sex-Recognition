#include <stdio.h>
#include <stdlib.h>

#define RECORDS 202599
#define STR_LEN 11
#define COMMAND_LEN 255

#define NUM_SPLITS 3
#define NUM_CLASSES 2
#define NUM_FEATURES 39

typedef enum {TRAIN, VAL, TEST} Split;
typedef enum {FEMALE, MALE} Class;

typedef struct {
    char nome[STR_LEN];
    Split split;
    Class class;
    int features[NUM_FEATURES];
} Image;

int main() {

    // Trash variables
    int aux_num;
    char aux_char;
    float progress;
    // String to store system calls
    char command[COMMAND_LEN];
    char folders[NUM_SPLITS][STR_LEN] = {"TrainSet", "ValSet", "TestSet"};
    // Dataset
    Image dataset[RECORDS];
    // File pointers
    FILE *split_file = NULL;
    FILE *class_file = NULL;
    FILE *features_file = NULL;


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
        fscanf(class_file, "%*s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        &dataset[i].features[0], &dataset[i].features[1], &dataset[i].features[2], &dataset[i].features[3], &dataset[i].features[4], &dataset[i].features[5], &dataset[i].features[6], &dataset[i].features[7],
        &dataset[i].features[8], &dataset[i].features[9], &dataset[i].features[10], &dataset[i].features[11], &dataset[i].features[12], &dataset[i].features[13], &dataset[i].features[14], &dataset[i].features[15],
        &dataset[i].features[16], &dataset[i].features[17], &dataset[i].features[18], &dataset[i].features[19], &dataset[i].class, &dataset[i].features[20], &dataset[i].features[21], &dataset[i].features[22],
        &dataset[i].features[23], &dataset[i].features[24], &dataset[i].features[25], &dataset[i].features[26], &dataset[i].features[27], &dataset[i].features[28], &dataset[i].features[29], &dataset[i].features[30],
        &dataset[i].features[31], &dataset[i].features[32], &dataset[i].features[33], &dataset[i].features[34], &dataset[i].features[35], &dataset[i].features[36], &dataset[i].features[37], &dataset[i].features[38]);
    // Close file
    fclose(class_file);


    printf("Do you need to move the files and create directories? (y/n) ");
    scanf(" %c", &aux_char);

    if(aux_char == 'y') {
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
        printf("\nMoving images...\n");
        for(int i=0; i<RECORDS; i++) {

            // Progress bar
            progress = ((i+1)/(float)RECORDS)*100;
            if(progress < 100) printf("\r");
            printf("\rPROGRESS: %2.2f%%", progress);

            // Command to move image
            sprintf(command, "mv ./dataset/%s ./dataset/%s/%d", dataset[i].nome, folders[dataset[i].split], dataset[i].class == MALE ? MALE : FEMALE);
            // Execute command
            system(command);
        }
        printf("\n");
    }

    printf("Do you need to create the feature file for each split? (y/n) ");
    scanf(" %c", &aux_char);


    // Create features file
    printf("\nCreating features file...\n");

    //one file for each split
    for(int i=0; i<NUM_SPLITS; i++) {

        // file data path
        sprintf(command, "./dataset/%s_features.txt", folders[i]);
        features_file = fopen(command, "w");
        if (features_file == NULL) printf("Error opening file");

        // for every class
        for(int k=0; k<NUM_CLASSES; k++) {
            // check every record
            for(int j=0; j<RECORDS; j++) {
                // if the record is in the split and has the class
                if(dataset[j].split == i && dataset[j].class == k) {
                    // write the all his features in a live of the file
                    for(int z=0; z<NUM_FEATURES; z++) {
                        fprintf(features_file, "%d ", dataset[j].features[z]);
                    }
                    // after that, break the line
                    fprintf(features_file, "\n");
                }
            }
        }

        // close file
        fclose(features_file);
    }

    return 0;
}