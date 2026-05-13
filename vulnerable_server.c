#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <ctype.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void url_decode(char *src, char *dest) {
    char a, b;

    while (*src) {

        if ((*src == '%') &&
            ((a = src[1]) && (b = src[2])) &&
            (isxdigit(a) && isxdigit(b))) {

            if (a >= 'a')
                a -= 'a' - 'A';

            if (a >= 'A')
                a = a - 'A' + 10;
            else
                a -= '0';

            if (b >= 'a')
                b -= 'a' - 'A';

            if (b >= 'A')
                b = b - 'A' + 10;