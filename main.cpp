
#include <stdio.h>

#include "inc/sorting/sorting.h"
#include "inc/text/text.h"
#include "inc/text/partitions/line_partition.h"

#include "inc/error_handling/error_handling.h"

int main(int argc, char **argv) {
    const char *i_file = argv[argc - 1];
    //const char *o_file = argv[2];

    Text *text = construct_text_file(i_file, &part_line);
    if (text == NULL) {
        ERR_REPORT_MSSG("cannot construct text");
    }

    quick_sort(text->parts, text->n_parts, text->part->size, compare_lines_reverse_lex);
    print_all_parts_stream(stdout, text);

    destruct_text(text);
    return 0;
}
