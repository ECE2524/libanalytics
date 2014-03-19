/** @file word_map.h
 * @brief data structure and associated functions to work with lists of words, integer pairs
 */

#ifndef _WORD_MAP_H_
#define _WORD_MAP_H_

typedef struct word_map* word_map_t;
typedef struct word_map_node* word_node_t;

enum { AMAP_SORT_DESCENDING=0x00, 
       AMAP_SORT_ASCENDING=0x01 };

/**
 * @param n initial size of word_map
 */
word_map_t word_map_create(size_t n);

/**
 * @param an initialized word_map object
 */
void word_map_free(word_map_t words);

/**
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
word_node_compare(const word_node_t n1, const word_node_t n2, int opt);

/**
   @brief apply a function to each item in word map

   @param wm the word map
   
   @param fcnt pointer to function that is called for each item in \ref wm

   Note that this is a specialized case of \ref word_map_nforeach
   where \ref n happens to be the number of items in \ref wm

 */
void
word_map_foreach(const word_map_t wm, void(*fnct)(const char*, int));

/**
   @brief apply a function to the first n word map items

   @param wm the word map
   
   @param fcnt pointer to function that is called for each item in \ref wm

   @param n number of items in wordmap to apply \ref fnct to
 */
void
word_map_nforeach(const word_map_t wm, void(*fnct)(const char*, int), int n);

#endif
