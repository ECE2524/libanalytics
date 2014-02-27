#include <err.h>
#include <stdlib.h>
#include <string.h>

#include "word_map.h"
#include "word_list.h"

#include "analytics.h"

static int
cmpstringp(const void *p1, const void *p2)
{
    /* The actual arguments to this function are "pointers to
              pointers to char", but strcmp(3) arguments are "pointers
              to char", hence the following cast plus dereference */

    return strcmp(* (char * const *) p1, * (char * const *) p2);
}

static
int word_count_injector(void *wm, const char* word) {
    word_node_t n;
    word_map_t wmptr = (word_map_t)wm;
    int count = 1;

    n = word_map_find(wmptr, word);
    if (n != NULL) {
        word_count_inc(n, 1);
    } else {
        word_map_insert(wmptr, word, count);
    }
    return 0;
}

word_map_t count_words(const word_list_t words) {
    word_map_t wm = word_map_create(word_list_count(words));

    word_list_inject(words, wm, word_count_injector);

    return wm;
}

