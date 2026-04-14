#ifndef OPERATIONS_H
#define OPERATIONS_H

void show_files(void);
void make_directory(char *dirname);
void remove_directory(char *dirname);
void change_current_working_directory(char *dirname);
void print_current_working_directory(void);
void create_file(char *filename);
void delete_file(char *filename);
void copy_file(char *sourcefile,char *destfile);
void show_file_content(char *filename);
void clear_terminal(void);

#endif
