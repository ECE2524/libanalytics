/** @file analytics.h
 * @brief Routines to help analyze text input
 */

#ifndef _ANALYTICS_H_
#define _ANALYTICS_H_

#include <config.h>
#include <stdio.h>

#include "word_list.h"
#include "word_map.h"

/* @brief extract a list of words from a stream
 * @param[in] is, input FILE stream
 * @return a word_list_t structure
 */
word_list_t split_words(FILE* is);

/* @brief count occurrences of words in a list
 * @param[in] words a list of words
 * @return a word_map_t (a list of word_map_node_t)
 */
word_map_t count_words(const word_list_t words);

/* @brief sort a counted word list numerically
 * @param[in,out] base pointer to first object in word list
 * @param[in] num number of elements in array pointed to by \ref{base}
 */
void sort_counted_words(word_map_t wm);

#endif
