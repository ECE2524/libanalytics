/** @file analytics.h
 * @brief Routines to help analyze text input
 */

#ifndef _ANALYTICS_H_
#define _ANALYTICS_H_

#include <stdio.h>

#include "word_list.h"
#include "word_map.h"

/**
    @brief extract a list of words from a stream

    @param is input FILE stream

    @return an initialized word_list_t structure containing the words extracted from the stream

    initialization of the word_list_t structure includes dynamic
    memory allocation.  It is the caller's responsibility to call
    \ref word_list_free on the returned object when finished with it.
*/
word_list_t split_words(FILE* is);

/** 
    @brief count occurrences of words in a list


    @param words a list of words

    @return an initialized list of word,integer pairs contained in a \ref word_map_t

    initialization of the \ref word_map_t structure includes dynamic
    memory allocation.  It is the caller's responsibility to call
    \ref word_map_free on the returned object when finished with it.

*/
word_map_t count_words(const word_list_t words);

/** 
    @brief sort a counted word list
    
    Sorts first by numerical value, then alphabetically. The sort is
    done "in place", i.e. the word_map_t object is modified.

    @param wm the word map object to sort 

    @param opt sort options. For now, just set to 0
*/
void sort_counted_words(word_map_t wm, int opt);

#endif
