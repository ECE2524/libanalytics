#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

#include "stream_tokens.h"

int main() {
    char * tok = NULL;
    int len;
    while((len = next_token(stdin, &tok, " .,:?!\n")) >= 0) {
        if (len > 0) {
            puts(tok);
            free(tok);
        }
    }
}
