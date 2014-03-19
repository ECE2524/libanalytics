#include <stdlib.h>

#include "word_map.h"

#include "analytics.h"

static int
cmpwordcount(const void *p1, const void *p2)
{
    return word_node_compare( (* (const word_node_t *) p1), 
                              (* (const word_node_t *) p2), AMAP_SORT_DESCENDING );
}

static int
cmpwordcount_asc(const void *p1, const void *p2)
{
    return word_node_compare( (* (const word_node_t *) p1), 
                              (* (const word_node_t *) p2), AMAP_SORT_ASCENDING );
}

void sort_counted_words(word_map_t counted, int opt) {
    if ( opt & AMAP_SORT_ASCENDING ) {
        word_map_sort(counted, cmpwordcount_asc);
    } else {
        word_map_sort(counted, cmpwordcount);
    }
}
