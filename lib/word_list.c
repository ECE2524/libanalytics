#include <stdlib.h>
#include <string.h>

#include "analytics.h"

struct word_list {
    char **words;
    size_t count;
    size_t size;
};

word_list_t
word_list_create(size_t n) {
    struct word_list* wl;

    wl = malloc(sizeof(struct word_list));

    wl->words = calloc(n, sizeof(char*));
    wl->words[0] = NULL;
    wl->count = 0;
    wl->size = n;
    return wl;
}

void 
word_list_free(word_list_t wl) {
    char **current;

    current = wl->words;

    while (*current) {
        free(*current);
        ++current;
    }
    free(wl->words);
    free(wl);
}

static int
word_list_grow(word_list_t wl, size_t new) {
    char **newlist;

    newlist = realloc(wl->words, new*sizeof(char*));
    if (newlist != NULL) {
        wl->words = newlist;
        wl->size = new;
        return 0;
    } else {
        /* since we didn't malloc this here it's up to the caller to free if there's a realloc error */
        return -1;
    }
}

int
word_list_insert(word_list_t wl, const char* word) {
    if (wl->count >= wl->size) {
        word_list_grow(wl, 2*(wl->size));
    }
    wl->words[wl->count] = strdup(word);
    wl->count += 1;
    return 0;
}

void
word_list_foreach(const word_list_t wl, void(*fp)(char*)) {
    char** current;

    current = wl->words;
    
    do {
        fp(*current);
    } while (*++current);
}

void
word_list_sort(word_list_t wl, int(*compar)(const void *, const void *)) {
    qsort(wl->words, wl->count, sizeof(char*), compar);
}

void
word_list_inject(const word_list_t wl, void *data,  int(*fnptr)(void*, const char*)) {
    char ** current;

    current = wl->words;

    do {
        fnptr(data, *current);
    } while(*++current);
}

unsigned long
word_list_count(const word_list_t wl) {
    return wl->count;
}

int
word_list_injector( void *wl, const char *w ) {
    return word_list_insert( (word_list_t)wl, w);
}
