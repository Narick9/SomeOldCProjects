#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main()
{
    char s[] = "Say friend and come";
    encrypt(s);
    printf("Encrypted in '%s'\n", s);
    printf("Check sum %i\n", checksum(s));
    encrypt(s);
    printf("Decrypted back to '%s'\n", s);
    printf("Check sum %i", checksum(s));
    return 0;
}