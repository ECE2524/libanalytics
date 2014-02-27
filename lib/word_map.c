#include <stdlib.h>
#include <string.h>

#include "word_map.h"

struct word_map_node {
    char *word;
    int count;
};

struct word_map {
    struct word_map_node **nodes;
    size_t count;
    size_t size;
};

static struct word_map_node*
create_node(const char* word, int count) {
    struct word_map_node* node;

    node = malloc(sizeof(struct word_map_node));

    node->word = strdup(word);
    node->count = count;
    return node;
}

word_map_t
word_map_create(size_t n) {
    struct word_map* wm;

    wm = malloc(sizeof(struct word_map));

    wm->nodes = calloc(n, sizeof(struct word_map_node*));
    wm->nodes[0] = NULL;
    wm->count = 0;
    wm->size = n;
    return wm;
}

static int
word_map_grow(word_map_t wm, int new_size) {
    struct word_map_node **new_nodes;

    new_nodes = realloc(wm->nodes, new_size*sizeof(struct word_map_node*));

    if (new_nodes != NULL) {
        wm->nodes = new_nodes;
        wm->size = new_size;
        return 0;
    } else {
        return -1;
    }
}

int
word_map_insert(word_map_t wm, const char* key, int val) {
    word_node_t node;

    node = word_map_find(wm, key);

    if (node == NULL) {
        if (wm->count >= wm->size) {
            word_map_grow(wm, 2*wm->size);
        }
        wm->nodes[wm->count++] = create_node(key, val);
        wm->nodes[wm->count] = NULL;
    } else {
        node->count = val;
    }

    return 0;
}

word_node_t
word_map_find(word_map_t const wm, const char* word) {
    struct word_map_node** current;

    current = wm->nodes;

    while(*current) {
        if (strcmp((*current)->word, word) == 0) {
            return *current;
        }
        ++current;
    }
    return NULL;
}

void
word_map_sort(word_map_t wm, int(*compar)(const void*, const void*)) {
    qsort(wm->nodes, wm->count, sizeof(struct word_map_node*), compar);
}

void word_map_free(word_map_t words) {
    struct word_map_node **current;

    current = words->nodes;

    while(*current) {
        free((*current)->word);
        free(*current);
        ++current;
    }
    free(words->nodes);
    free(words);
}

unsigned long
word_map_count(const word_map_t wm) {
    return wm->count;
}

void
word_count_inc(word_node_t node, int value) {
    node->count += value;
}

int
word_node_compare(const word_node_t p1, const word_node_t p2) {
    if (p2->count == p1->count)
        return strcmp(p1->word, p2->word);
    return p2->count - p1->count;
}

void
word_map_foreach(const word_map_t wm, void(*fnct)(const char* key, int val)) {
    word_map_nforeach(wm, fnct, 0);
}

void
word_map_nforeach(const word_map_t wm, void(*fnct)(const char* key, int val), int nlimit) {
    int count;
    struct word_map_node **current;

    current = wm->nodes;

    count = ( nlimit == 0 ? wm->count : nlimit );
    while(*current && count-- > 0) {
        fnct((*current)->word, (*current)->count);
        ++current;
    }
}
