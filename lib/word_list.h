#ifndef _WORD_LIST_H_
#define _WORD_LIST_H_

/*
 * @param n initial size of word_list
 */
typedef struct word_list* word_list_t;

word_list_t
word_list_create(size_t n);

/*
 * @param words NULL terminated array of char*
 */
void 
word_list_free(word_list_t words);

int 
word_list_insert(word_list_t wl, const char* word);

void 
word_list_foreach(const word_list_t wl, void(*fp)(char*));

void 
word_list_sort(word_list_t wl, int(*compar)(const void *, const void *));

unsigned long
word_list_count(const word_list_t wl);

void 
word_list_inject(const word_list_t wl, void *data,  int(*fnptr)(void*, const char*));

#endif
