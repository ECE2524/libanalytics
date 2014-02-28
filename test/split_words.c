#include <stdio.h>
#include <stdlib.h>

#include "word_list.h"
#include "analytics.h"

void print_word(char* word) {
    printf("'%s'\n", word);     
}

int main() {
    word_list_t words;
    
    words = split_words(stdin);

    word_list_foreach(words, print_word);

    word_list_free(words);

    return 0;
}
