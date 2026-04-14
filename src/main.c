#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/util.h"
#include "../include/executer.h"
#include "../include/command_parser.h"
#include "../include/operations.h"

int main(void) {
    char input[BUFF_SIZE];
    command_t *comm = command_init();
    if(!comm) {
        print("Error: Failed to initilize the program\n",RED);
        return 1;
    }

    while(true) {
        print("file-manager> ",AQUA);
        if(fgets(input,BUFF_SIZE,stdin)==NULL) {
            print("Error: Input failure\n",RED);
            continue;
        }

        input[strcspn(input,"\n")] = '\0';

        if(parse_command(comm,input)==-1) {
            (*comm).argc = 0;
            continue; 
        }

        execute_command(comm);
    }

    return 0;
}
