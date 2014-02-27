#ifndef _WORD_MAP_H_
#define _WORD_MAP_H_

typedef struct word_map* word_map_t;
typedef struct word_map_node* word_node_t;


/*
 * @param n initial size of word_map
 */
word_map_t word_map_create(size_t n);

/*
 * @param words NULL terminated array of word_map objects
 */
void word_map_free(word_map_t words);

/*
 * @param wm pointer to word map structure
 * @param word, word to find
 * @return a pointer to the node containing the entry for word or NULL if no matching entry is found.
 */
word_node_t 
word_map_find(const word_map_t wm, const char* word);


int
word_map_insert(word_map_t wm, const char* key, int val);

void
word_map_sort(word_map_t wm, int(*compar)(const void*, const void*));

unsigned long
word_map_count(const word_map_t wm);

void
word_count_inc(word_node_t node, int value);

int
word_node_compare(const word_node_t n1, const word_node_t n2);

void
word_map_foreach(const word_map_t wm, void(*fnct)(const char*, int));

void
word_map_nforeach(const word_map_t wm, void(*fnct)(const char*, int), int);

#endif
