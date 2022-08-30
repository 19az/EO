#include <stdio.h>

#include "text.h"

int main(int argc, char **argv) {
    Text text;
    int ret = 0;
    if ((ret = read_text_file(&text, argv[argc - 1])) <= 0) {
        printf("Error occured during reading text: %d\n", ret);
        return 1;
    }

    parse_lines_text(&text);
    sort_lines_reverse_lexicographic_quick_sort(&text);
    print_all_lines_stdout(&text);

    dealloc_struct_text(&text);
    return 0;
}
