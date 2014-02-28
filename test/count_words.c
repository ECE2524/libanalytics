#include <stdio.h>

#include "analytics.h"

void
print_word_count(const char *word, int count) {
    printf("%d %s\n", count, word);
}

int main() {
    word_list_t wl;
    word_map_t counted;

    wl = word_list_create(10);

    word_list_insert(wl, "one");
    word_list_insert(wl, "two");
    word_list_insert(wl, "two");
    word_list_insert(wl, "three");
    word_list_insert(wl, "three");
    word_list_insert(wl, "three");
    word_list_insert(wl, "four");
    word_list_insert(wl, "four");
    word_list_insert(wl, "four");
    word_list_insert(wl, "four");

    counted = count_words(wl);
    
    word_map_foreach(counted, print_word_count);

    word_map_free(counted);
    word_list_free(wl);

    return 0;
}
