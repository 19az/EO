#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "rwfile.h"

int get_file_size(const char *filename) {
    if (filename == NULL) {
        return ERR_ARGS_NULL_GET_FILE_SIZE;
    }

    struct stat st;
    if (stat(filename, &st) == -1) {
        return ERR_STAT_GET_FILE_SIZE;
    }
    return (int) st.st_size;
}

int read_file(const char *filename, char *buffer, size_t nSymbols) {
    if (nSymbols == 0) {
        return 0;
    }
    if (filename == NULL || buffer == NULL) {
        return ERR_ARGS_NULL_READ_FILE;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return ERR_FILE_OPEN_READ_FILE;
    }
    int read_ret = (int) fread(buffer, sizeof(char), nSymbols, file);

    fclose(file);
    return read_ret;
}

size_t count_char_buffer(const char *buffer, char ch) {
    if (buffer == NULL) {
        return 0;
    }

    size_t count = 0;
    while (*buffer != '\0') {
        count += (*buffer++ == ch);
    }
    return count;
}

size_t read_line_buffer(const char *line_start) {
    if (line_start == NULL) {
        return 0;
    }

    return (size_t) (strchr(line_start, '\n') - line_start);
}

void putnchar(const char *start, size_t length) {
    for (size_t i = 0; i < length; i++) {
        putchar(start[i]);
    }
}
