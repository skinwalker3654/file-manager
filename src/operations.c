#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/operations.h"
#include "../include/util.h"
#include <sys/stat.h>
#include <dirent.h>

/* this function prints all the files and folders in the current directory */
void show_files() {
    DIR *current_dir = opendir(".");
    if(current_dir == NULL) {
        print("Error: Failed to read the files\n",RED);
        return;
    }
    
    struct dirent *entry;
    struct stat st;

    while((entry = readdir(current_dir))!=NULL) {
        if(entry->d_name[0] == '.') continue;
        stat(entry->d_name,&st);

        if(S_ISDIR(st.st_mode)) {
            char *message = malloc(strlen(entry->d_name)+2);
            strcpy(message,entry->d_name);
            message[strlen(entry->d_name)] = ' ';
            message[strlen(entry->d_name)+1] = '\0';
            print(message,DARK_BLUE);
            free(message);
        } else {
            printf("%s ",entry->d_name);
        }
    }
    
    printf("\n");
    closedir(current_dir);
}

/* this function creates a new directory in the current working directory */
void make_directory(char *filename) {
    if(mkdir(filename,0755)!=0) {
        print("Error: Failed to create the directory\n",RED);
        print("Hint: Make sure that no other directory exists with the same name in the current working directory\n",YELLOW);
        return;
    }

    print("Directory created successfully\n",GREEN);
}

/* this function deletes a directory from the current working directory */
void remove_directory(char *dirname) {
    struct stat st; 
    if(stat(dirname,&st)==-1) {
        print("Error: This directory does not exists\n",RED);
        return;
    }

    if(!S_ISDIR(st.st_mode)) {
        print("Error: You cannot remove regular files with the rmdir command\n",RED);
        return;
    }

    if(remove(dirname)==-1) {
        print("Error: Failed to delete this directory\n",RED);
        print("Hint: Make sure that this directory exists OR if the directory is not empty\n",YELLOW);
        return;
    }

    print("Directory removed successfully\n",GREEN);
}

/* this function changes the position that we are working on the system by going to a different directory */
void change_current_working_directory(char *dirname) {
    if(chdir(dirname)==-1) {
        print("Error: Failed to change current working directory\n",RED);
        print("Hint: Make sure that this directory path exists in your system\n",YELLOW);
        return;
    }
}

/* this function prints the path of the current working directory */
void print_current_working_directory() {
    char buffer[1024];
    if(getcwd(buffer,1024)==NULL) {
        print("Error: Failed to read the current working directory path\n",RED);
        return;
    }

    char *message = strdup(buffer);
    print(message,GREEN);
    free(message);
    printf("\n");
}

/* this function creates new files in the current working directory */
void create_file(char *filename) {
    /* checking if the file exists */
    FILE *test = fopen(filename,"r");
    if(test != NULL) {
        print("Error: This file already exists in the current working directory\n",RED);
        fclose(test);
        return;
    }

    FILE *file = fopen(filename,"w");
    fclose(file);
    print("File created successfully\n",GREEN);
}

/* this function removes a file from the current working directory */
void delete_file(char *filename) {
    struct stat st; 
    if(stat(filename,&st)==-1) {
        print("Error: This file does not  exists\n",RED);
        return;
    }

    if(S_ISDIR(st.st_mode)) {
        print("Error: You cannot remove directorys with the rm command\n",RED);
        return;
    }

    remove(filename);
    print("File removed successfully\n",GREEN);
}

/* this function takes the contents of the @sourcefile and puts the to the @destfile */
void copy_file(char *sourcefile, char *destfile) {
    struct stat st;
    if(stat(sourcefile,&st)==-1) {
        print("Error: Source file does not exists\n",RED);
        return;
    }

    if(S_ISDIR(st.st_mode)) {
        print("Error: You cannot copy contents from directorys\n",RED);
        print("Hint: Make sure to pass a regular file as an argument\n",YELLOW);
        return;
    }

    stat(destfile,&st);
    if(S_ISDIR(st.st_mode)) {
        print("Error: You cannot write the contents of a file into a directory\n",RED);
        print("Hint: Make sure to pass a regular file as an argument\n",YELLOW);
        return;
    }

    FILE *file = fopen(sourcefile,"r");
    if(!file) {
        print("Error: Source file does not exists\n",RED);
        return;
    }

    fseek(file,0,SEEK_END);
    long size = ftell(file);
    char buffer[size+1];
    rewind(file);

    int len = fread(buffer,1,size,file);
    if(len == 0) {
        print("Error: The source file is empty\n",RED);
        fclose(file);
        return;
    }

    buffer[len] = '\0';
    fclose(file);

    FILE *dest = fopen(destfile,"w");
    if(!dest) {
        print("Error: Failed to create the dest file\n",RED);
        fclose(file);
        return;
    }

    fwrite(buffer,1,len,dest);
    fclose(dest);
    print("Contents were copied successfully\n",GREEN);
}

/* this function prints the contents of a file into the terminal */
void show_file_content(char *filename) {
    struct stat st;
    if(stat(filename,&st)==-1) {
        print("Error: This file does not exists\n",RED);
        return;
    }

    if(S_ISDIR(st.st_mode)) {
        print("Error: Directorys dont have text contents\n",RED);
        return;
    }

    FILE *file = fopen(filename,"r");
    if(!file) {
        print("Error: Failed to open this file\n",RED);
        print("Hint: Make sure that the file exists in the current working directory\n",YELLOW);
        return;
    }

    fseek(file,0,SEEK_END);
    long size = ftell(file);
    char buffer[size+1];
    rewind(file);

    int len = fread(buffer,1,size,file);
    if(len == 0) {
        print("Error: This file is empty\n",RED);
        fclose(file);
        return;
    }
        
    buffer[len] = '\0';
    fclose(file);
    
    printf("%s",buffer);
}

/* this function clears the terminal */
void clear_terminal() {
    system("clear");
}
