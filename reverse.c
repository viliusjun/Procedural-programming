//Vilius Junevičius

// Program that reverses the letters in each word from a given text and prints the results to another text file

#include <stdio.h>
#include <stdlib.h>

#define MAX_SYMBOLS 255
#define SPACE ' '

void rearrange (char *string, char **reverse_string);

int main(int argc, char *argv[]){
    if(argc == 3){
        char *file_name1;
        file_name1 = argv[1];
        char *file_name2;
        file_name2 = argv[2];

        // We open the input file
        FILE *input_file;
        input_file = fopen(file_name1, "r");
        if (input_file != NULL) {
            printf("\nThe input file has been opened...\n\n");

            // We open the output file
            FILE *output_file;
            output_file = fopen(file_name2, "w");
            if (output_file != NULL) {
                printf("The output file has been created\n\n");

                //char string[MAX_SYMBOLS];
                char *string = (char *) malloc(MAX_SYMBOLS * sizeof(char));

                char *reverse_string;

                // While not the end of the file, do the following
                while (feof(input_file) == 0){
                    
                    if (fgets(string, MAX_SYMBOLS, input_file) != NULL){

                        rearrange(string, &reverse_string);

                        fputs(reverse_string, output_file);
                    }
                }
                free(string);
                free(reverse_string);

                fclose(input_file);
                fclose(output_file);
            }
            else {
                printf("Cannot create file to write in\n\n");
                return 1;
            }    
        }
        else {
            printf("There is no such file to read from\n\n");
            return 1;
        }
    }
    else {
        printf("Usage:\n");
        printf("./main input_file_name output_file_name\n");
        return 0;
    }

    return 0;
}

// Function that rearrages the letters in each word in reverse
void rearrange (char *string, char **reverse_string){
    
    int length = 0;
    for(int i = 0; string[i] != '\0'; ++i){
        length++;
    }
    
    *reverse_string = (char *) malloc(length * sizeof(char));
    
    int i = 0;
    while(string[i] != '\0') {
        (*reverse_string)[i] = string[i];
        i++;
    } 
    (*reverse_string)[i] = '\0';

    int start = 0, end = 0;
    char temp;
    i = 0;

    while((*reverse_string)[i] != '\0'){
        if((*reverse_string)[i] == SPACE || (*reverse_string)[i] == '\0' || (*reverse_string)[i] == '\n' || (*reverse_string)[i] == '\r'){
            end = i;
            for(int j = start, x = end - 1; j < x; ++j, --x){
                temp = (*reverse_string)[j];
                (*reverse_string)[j] = (*reverse_string)[x];
                (*reverse_string)[x] = temp;
            }
            start = end + 1;
        }
        i++;
    }

    return;
}