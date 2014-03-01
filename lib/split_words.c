#include "stream_tokens.h"
#include "word_list.h"
#include "analytics.h"

static int
word_list_injector( void *wl, const char *w ) {
    return word_list_insert( (word_list_t)wl, w);
}

word_list_t split_words(FILE* fp) {
    word_list_t wl = word_list_create(100);
    
    token_inject(fp, " \n\t.,?!-", wl, word_list_injector, TOK_INJECT_COMPACT);

    return wl;
}

