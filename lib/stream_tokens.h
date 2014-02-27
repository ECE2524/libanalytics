#include <stdio.h>

/*
 * @file functions for retreiving tokens from streams
 */

enum {
    TOK_INJECT_COMPACT=0x01
};

/*
 * @brief retreive the next token in a stream
 * @param[in] fp stream to read from
 * @param[out] token
 * @param pred function pointer to delimiter predicate
*/
int next_token(FILE* fp, char **token, const char*);

/*
 * @breif retreive each token from a stream calling fnptr each time
 */
int
token_inject(FILE *fp, const char* delim, void* data, int(*fnptr)(void*, const char*), int options);
