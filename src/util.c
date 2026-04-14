#include "../include/util.h"
#include <stdio.h>

/* this function prints messages with the colors that are on the color_t enum */
void print(char *msg,color_t color) {
    switch(color) {
        case RED: printf("\x1b[31m%s\x1b[0m",msg); break;
        case GREEN: printf("\x1b[32m%s\x1b[0m",msg); break;
        case AQUA: printf("\x1b[36m%s\x1b[0m",msg); break;
        case YELLOW: printf("\x1b[33m%s\x1b[0m",msg); break;
        case DARK_BLUE: printf("\x1b[34m%s\x1b[0m",msg); break;
    }
}

/* this function prints informatoins and the syntax of every command */
void print_help() {
    printf("\nCommands:\n");
    print("  ls",DARK_BLUE); print("  : this command prints all the files and directorys into the terminal\n",YELLOW);
    print("  mkdir \"directory name\"",DARK_BLUE); print("  : this command creates a new directory into the current working directory\n",YELLOW);
    print("  rmdir \"directory name\"",DARK_BLUE); print("  : this command deletes a directory from the current working directory\n",YELLOW);
    print("  echo \"message\"",DARK_BLUE); print("   : this command prints a message to the console\n",YELLOW);
    print("  cp \"source file\" \"dest file\"",DARK_BLUE); print("  : this command copies the contents of the source file and puts the to the dest file\n",YELLOW);
    print("  cat \"file name\"",DARK_BLUE); print("  : this command prints the contents of the file into the console\n",YELLOW);
    print("  touch \"file name\"",DARK_BLUE); print("  : this command creates a new file into the current working directory\n",YELLOW);
    print("  rm \"file name\"",DARK_BLUE); print("  : this command removes a file from the current working directory\n",YELLOW);
    print("  cd \"directory name\"",DARK_BLUE); print("  : this command changes the directory that we are currently working on\n",YELLOW);
    print("  pwd",DARK_BLUE); print("  : this command shows the path of the current directory that we are working on\n",YELLOW);
    print("  clear",DARK_BLUE); print("  : this command clears the terminal\n",YELLOW);
    print("  help",DARK_BLUE); print("  : this command shows this text\n",YELLOW);
    print("  exit",DARK_BLUE); print("  : this commands exits the program\n\n",YELLOW);
}
