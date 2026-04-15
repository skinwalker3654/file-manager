#include "../include/executer.h"
#include "../include/operations.h"
#include "../include/util.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* this function takes the parsed command and evaluetes the syntax and which operations to use */
int execute_command(command_t *command) {
    if(strcmp(command->argv[0],"ls")==0) {
        if(command->argc != 1) {
            print("Error: The command ls does not require any arguments\n",RED);
            print("Correct ussage: ls\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        show_files();
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"cat")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command cat\n",RED);
            print("Correct ussage: cat \"file name\"\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        show_file_content(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"echo")==0) {
        if(command->argc != 2) {
            print("Error: Invalid usage of the comand echo\n",RED);
            print("Correct usage: echo \"message\"",YELLOW);
            command->argc = 0;
            return -1;
        }

        printf("%s\n",command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"cd")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command cd\n",RED);
            print("Correct ussage: cd \"directory name\"\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        change_current_working_directory(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"pwd")==0) {
        if(command->argc != 1) {
            print("Error: The command pwd does not require any arguments\n",RED);
            print("Correct ussage: pwd\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        print_current_working_directory();
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"touch")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command touch\n",RED);
            print("Correct ussage: touch \"file name\"\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        create_file(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"rm")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command rm\n",RED);
            print("Correct ussage: rm \"file name\"\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        delete_file(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"cp")==0) {
        if(command->argc != 3) {
            print("Error: Invalid ussage of the command cp\n",RED);
            print("Correct ussage: cp \"source file name\" \"dest file name\"\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        copy_file(command->argv[1],command->argv[2]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"mkdir")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command mkdir\n",RED);
            print("Correct ussage: mkdir \"directory name\\n",YELLOW);
            command->argc = 0;
            return -1;
        }
    
        make_directory(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"rmdir")==0) {
        if(command->argc != 2) {
            print("Error: Invalid ussage of the command rmdir\n",RED);
            print("Correct ussage: rmdir \"directory name\\n",YELLOW);
            command->argc = 0;
            return -1;
        }
    
        remove_directory(command->argv[1]);
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"clear")==0) {
        if(command->argc != 1) {
            print("Error: The command clear does not require any arguments\n",RED);
            print("Correct ussage: clear\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        clear_terminal();
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"help")==0) {
        if(command->argc != 1) {
            print("Error: The command help does not require any arguments\n",RED);
            print("Correct ussage: help\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        print_help();
        command->argc = 0;
        return 0;
    } else if(strcmp(command->argv[0],"exit")==0) {
        if(command->argc != 1) {
            print("Error: The command exit does not require any arguments\n",RED);
            print("Correct ussage: exit\n",YELLOW);
            command->argc = 0;
            return -1;
        }

        free_command(command);
        print("Exiting...\n",YELLOW);
        exit(EXIT_SUCCESS);
    } else {
        print("Error: Invalid command\n",RED);
        print("Hint: Type help for more details\n",YELLOW);
        command->argc = 0;
        return -1;
    }

    return 0;
}
