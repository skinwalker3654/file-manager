#ifndef UTIL_H
#define UTIL_H

#define BUFF_SIZE  256
#define MAX_TOKENS   4

typedef enum {
    RED,
    GREEN,
    AQUA,
    YELLOW,
    DARK_BLUE,
} color_t;

void print(char *msg,color_t color);
void print_help(void);

#endif
