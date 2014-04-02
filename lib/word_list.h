/** @file word_list.h
 * @brief data structure and associated functions to work with lists of words
 */

#ifndef _WORD_LIST_H_
#define _WORD_LIST_H_

/**
   @breif object encapsulating a list of words

*/
typedef struct word_list* word_list_t;

/** 
    @brief create a new word list
    @param n initial size of word list
    @return a freshly allocated \ref word_list_t

    initialization performs dynamic memory allocation. It is the caller's
    responsibility to call \ref word_list_free on the returned word_list_t
    object when it is no longer needed.
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

/**
   @breif accumulate all values in wl to \ref data
   
   accumulate each item with \ref data by passing each to \ref fnptr

   @param data inital value
   @param fnptr a pointer to the function defining the operation to perform
*/
void 
word_list_inject(const word_list_t wl, void *data,  int(*fnptr)(void*, const char*));

int
word_list_injector( void *wl, const char *w );

#endif
