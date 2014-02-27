#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stream_tokens.h"

#define INITIAL_BUFFER_SIZE 4096

enum tokenizer_errors {
    TOK_EOF = -1,
    TOK_ALLOCATION = -2,
};

/* Extract the next token from the stream
 * @param[in] fp stream to read from
 * @param[out] token string. Memory will be allocated for each token and must be freed by the caller
 * 
 */ 
int next_token(FILE * fp, char **token, const char* delim)
{
    size_t buf_size = INITIAL_BUFFER_SIZE, diff;
    *token = malloc(buf_size*sizeof(char));
    char *ptr = *token;
    char *temp;
    int len = 0;
    int c;

    while (((c = fgetc(fp)) != EOF) && strchr(delim, c) == NULL) {
        diff = ptr - *token;
        if ( diff >= buf_size ) {
            temp = realloc(*token, 2*buf_size*sizeof(char));
            if (temp != NULL) {
                buf_size = 2*buf_size;
                *token = temp;
                ptr = *token + diff;
            } else {
                free(token);
                return TOK_ALLOCATION;
            }
        }
        *ptr++ = c;
        ++len;
    }
    *ptr = '\0';

    if (c == EOF) {
        return TOK_EOF;
    }

    return len;
}

int
token_inject(FILE *fp, const char* delim, void* data, int(*fnptr)(void*, const char*), int options) {
    char *tok = NULL;
    int ret = 0;
    
    while (next_token(fp, &tok,  delim) != EOF) {
        if ( !(options && TOK_INJECT_COMPACT) || strlen(tok) > 0) {
            ret = fnptr(data, tok);
        }
        free(tok);
    }
    free(tok);
    return ret;
}
