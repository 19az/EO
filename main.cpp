
#include <locale.h>
#include <stdio.h>

#include "inc/sorting/sorting.h"
#include "inc/text/text.h"
#include "inc/text/partitions/line_partition.h"

#include "inc/error_handling/error_handling.h"

int compare_lines_pointers(const void* a, const void* b);

int main(int argc, const char **argv)
{
    const char *i_file_name = NULL;
    const char *o_file_name = NULL;

    if (argc == 3) 
    {
        i_file_name = argv[1];
        o_file_name = argv[2];
    }
    else
    {
        fprintf(stderr, "Wrong number of arguments given");
        return 1;
    }

    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    Text *text = construct_text_file(i_file_name, &part_line);
    if (text == NULL) 
        fprintf(stderr, "cannot construct text");

    FILE *file_out = fopen(o_file_name, "w");
    if (file_out == NULL)
    {
        fprintf(stderr, "cannot open output file");
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

int compare_lines_pointers(const void* a, const void* b) {
    return (int) (((const Line*) a)->start -
                  ((const Line*) b)->start);
}
