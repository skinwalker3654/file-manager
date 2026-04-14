#include "../include/command_parser.h"
#include "../include/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* this function allocates memory for tha string list and puts the argc to 0 
 * if the function fails it returns NULL otherwise it returns the @command */
command_t *command_init() {
    command_t *command = malloc(sizeof(command_t));
    if(!command) {
        print("Error: Failed to allocate memory for the command\n",RED);
        return NULL;
    }

    (*command).argv = malloc(sizeof(char*)*MAX_TOKENS);
    if(!(*command).argv) {
        print("Error: Failed to allocate memory for the command\n",RED);
        return NULL;
    }

    for(int i=0; i<MAX_TOKENS; i++) {
        (*command).argv[i] = malloc(BUFF_SIZE);
        if(!(*command).argv[i]) {
            for(int j=0; j<i; j++) free((*command).argv[j]);
            free((*command).argv);
            free(command);
            return NULL;
        }
    }

    (*command).argc = 0;
    return command;
}

/* this commands seperates user input into tokens and puts them into the @command->argv (list of strings) 
 * it sepereates the tokens between spaces or quotes " "
 * if the function fails it returns -1 otherwise it returns 0 */
int parse_command(command_t *command,char *input) {
    while(*input != '\0') {
        if((*command).argc >= MAX_TOKENS) {
            print("Error: The maximum amount of arguments per command is 4\n",RED); 
            return -1; 
        }

        while(isspace(*input)) input++;

        if(*input == '\0') break;
        if(*input == '"') {
            int counter = 0;
            input++;
            while(*input != '"' && *input != '\0') {
                (*command).argv[(*command).argc][counter++] = *input;
                input++;
            }

            input++;
            (*command).argv[(*command).argc][counter++] = '\0';
            (*command).argc++;

            continue;
        }
        
        int counter = 0;
        while(*input != ' ' && *input != '\0') {
            (*command).argv[(*command).argc][counter++] = *input;
            input++;
        }

        (*command).argv[(*command).argc][counter] = '\0';
        (*command).argc++;
    }

    return 0;
}

/* the command_t requires memory for the string list (argv) so this command frees the memory */
void free_command(command_t *ptr) {
    for(int i=0; i<MAX_TOKENS; i++) 
        if(ptr->argv[i] != NULL) 
            free(ptr->argv[i]);
    free(ptr->argv);
    free(ptr);
}
