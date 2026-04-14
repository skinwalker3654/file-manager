#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

typedef struct command_t {
    int argc;
    char **argv;
} command_t;

command_t *command_init(void);
int parse_command(command_t *command,char *input);
void free_command(command_t *command);

#endif
