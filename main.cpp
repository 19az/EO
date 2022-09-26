
#include <locale.h>
#include <stdio.h>

#include "inc/sorting/sorting.h"
#include "inc/text/text.h"
#include "inc/text/partitions/line_partition.h"

#include "inc/error_handling/error_handling.h"

#include <string.h>

int compare_lines_pointers(const void *a, const void *b);

int main(int argc, char **argv) {
    const char *i_file_name = argv[argc - 2];
    const char *o_file_name = argv[argc - 1];

    setlocale(LC_ALL, "en_US.utf8");
    Text *text = construct_text_file(i_file_name, &part_line);
    if (text == NULL) {
        ERR_REPORT_MSSG("cannot construct text");
    }

    FILE *file_out = fopen(o_file_name, "w");
    if (file_out == NULL) {
        ERR_REPORT_MSSG("cannot open output file");
        destruct_text(text);
        return 1;
    }
    
    quick_sort(text->parts,
               text->n_parts,
               text->part->size,
               compare_lines_lex_utf8);
    print_all_parts_stream(file_out, text);
    fprintf(file_out, "\n*****************************************\n");

    quick_sort(text->parts,
               text->n_parts,
               text->part->size,
               compare_lines_reverse_lex_utf8);
    print_all_parts_stream(file_out, text);
    fprintf(file_out, "\n*****************************************\n");

    quick_sort(text->parts,
               text->n_parts,
               text->part->size,
               compare_lines_pointers);
    print_all_parts_stream(file_out, text);

    destruct_text(text);
    fclose(file_out);
    return 0;
}

int compare_lines_pointers(const void *a, const void *b) {
    return (int) (((const Line*) a)->start - ((const Line*) b)->start);
}
