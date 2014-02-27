/** @file word_list.h
 * @brief data structure and associated functions to work with lists of words
 */

#ifndef _WORD_LIST_H_
#define _WORD_LIST_H_

/*
 * @param n initial size of word_list
 */
typedef struct word_list* word_list_t;

/** @brief create a new word list
 * @param n initial size of word list
 * @return a freshly allocated \ref word_list_t
 */
word_list_t
word_list_create(size_t n);

/** 
    @brief free the memory associated with a word list
    @param words NULL terminated array of char*
*/
void 
word_list_free(word_list_t words);

/**
   @brief insert a word into a word list
   @return 0 on successful insert
*/
int 
word_list_insert(word_list_t wl, const char* word);

/**
   @breif apply a function for each item in word list
*/
void 
word_list_foreach(const word_list_t wl, void(*fp)(char*));

/**
   @brief sort a list of words using comparison function
*/
void 
word_list_sort(word_list_t wl, int(*compar)(const void *, const void *));

/**
   @brief count the number of items in a word list
   @param wl the word list
   @return the number of items in word list \ref wl
*/
unsigned long
word_list_count(const word_list_t wl);

void 
word_list_inject(const word_list_t wl, void *data,  int(*fnptr)(void*, const char*));

#endif
