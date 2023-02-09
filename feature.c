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
    int aux_num = 0;
    float progress = 0;
    // String to store system calls
    char command[COMMAND_LEN];
    char folders[NUM_SPLITS][STR_LEN] = {"TrainSet", "ValSet", "TestSet"};
    // Dataset
    Image image;
    // File pointers
    FILE *split_file = NULL;
    FILE *class_file = NULL;
    FILE *features_file[NUM_SPLITS] = {NULL, NULL, NULL};


    // Open split file
    split_file = fopen("./metadata/list_eval_partition.txt", "r");
    if (split_file == NULL) printf("Error opening file");
    // Open class file
    class_file = fopen("./metadata/list_attr_celeba.txt", "r");
    if (class_file == NULL) printf("Error opening file");
    // Open features files
    sprintf(command, "./dataset/%s_features.txt", folders[TRAIN]);
    features_file[TRAIN] = fopen(command, "w");
    if (features_file == NULL) printf("Error opening file");
    sprintf(command, "./dataset/%s_features.txt", folders[VAL]);
    features_file[VAL] = fopen(command, "w");
    if (features_file == NULL) printf("Error opening file");
    sprintf(command, "./dataset/%s_features.txt", folders[TEST]);
    features_file[TEST] = fopen(command, "w");
    if (features_file == NULL) printf("Error opening file");


    // Read file name and split category

    for(int j = 0; j < NUM_CLASSES; j++) {

        rewind(split_file);
        rewind(class_file);

        // Skip first 2 lines of the class file
        while ((aux_num = fgetc(class_file)) != '\n' && aux_num != EOF) {/* nothing, just skip the line */}
        while ((aux_num = fgetc(class_file)) != '\n' && aux_num != EOF) {/* nothing, just skip the line */}

        for(int k = 0; k < RECORDS; k++) {
            // Read file name and split category
            fscanf(split_file, "%s %d", image.nome, &image.split);
            fscanf(class_file, "%*s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                &image.features[0], &image.features[1], &image.features[2], &image.features[3], &image.features[4], &image.features[5], &image.features[6], &image.features[7],
                &image.features[8], &image.features[9], &image.features[10], &image.features[11], &image.features[12], &image.features[13], &image.features[14], &image.features[15],
                &image.features[16], &image.features[17], &image.features[18], &image.features[19], &image.class, &image.features[20], &image.features[21], &image.features[22],
                &image.features[23], &image.features[24], &image.features[25], &image.features[26], &image.features[27], &image.features[28], &image.features[29], &image.features[30],
                &image.features[31], &image.features[32], &image.features[33], &image.features[34], &image.features[35], &image.features[36], &image.features[37], &image.features[38]);
            
            if(image.class == j) {
                // write the all his features in a live of the file
                for(int z=0; z<NUM_FEATURES; z++) {
                    fprintf(features_file[image.split], "%d ", image.features[z]);
                }
                // after that, break the line
                fprintf(features_file[image.split], "\n");
            }

            // Progress bar
            aux_num++;
            progress = (aux_num/(float)RECORDS*NUM_CLASSES)*100;
            printf("PROGRESS: %2.2f%%", progress);
            if(progress < 100) printf("\r");
        }
    }
    printf("\nFiles created successfully!\n");
    
    // Close file
    fclose(split_file);
    fclose(class_file);
    fclose(features_file[TRAIN]);
    fclose(features_file[VAL]);
    fclose(features_file[TEST]);

    return 0;
}