#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_names(char *file_name, char ***names, int *num_names) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    *num_names = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        (*num_names)++;
        *names = (char **)realloc(*names, (*num_names) * sizeof(char *));
        (*names)[(*num_names) - 1] = strdup(line);
    }

    fclose(file);
}

void read_numbers(char *file_name, char ***numbers, int *num_numbers) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char line[100];
    *num_numbers = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        (*num_numbers)++;
        *numbers = (char **)realloc(*numbers, (*num_numbers) * sizeof(char *));
        (*numbers)[(*num_numbers) - 1] = strdup(line);
    }

    fclose(file);
}

void generate_vcard(char **names, char **numbers, int num_entries, char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    for (int i = 0; i < num_entries; i++) {
        fprintf(file, "BEGIN:VCARD\n");
        fprintf(file, "FN:%s", names[i]);
        fprintf(file, "TEL:%s", numbers[i]);
        fprintf(file, "END:VCARD\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s name_list.txt number_list.txt output.vcf\n", argv[0]);
        exit(1);
    }

    char *name_file = argv[1];
    char *number_file = argv[2];
    char *output_file = argv[3];

    char **names = NULL;
    int num_names = 0;
    read_names(name_file, &names, &num_names);

    char **numbers = NULL;
    int num_numbers = 0;
    read_numbers(number_file, &numbers, &num_numbers);

    if (num_names != num_numbers) {
        printf("Error: Number of names and numbers don't match\n");
        exit(1);
    }

    generate_vcard(names, numbers, num_names, output_file);

    for (int i = 0; i < num_names; i++) {
        free(names[i]);
        free(numbers[i]);
    }
    free(names);
    free(numbers);

    return 0;
}
