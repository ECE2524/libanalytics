#include <stdlib.h>

#include "word_map.h"

#include "analytics.h"

static int
cmpwordcount(const void *p1, const void *p2)
{
    return word_node_compare( (* (const word_node_t *) p1), 
                              (* (const word_node_t *) p2) );
}

void sort_counted_words(word_map_t counted, int opt) {
    opt=0;
    word_map_sort(counted, cmpwordcount);
}
