#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n) 
{
    // Cast src and dest to char pointers for byte-wise copying
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    // Copy byte by byte
    for (size_t i = 0; i < n; i++) 
    {
        d[i] = s[i];
    }

    return dest;
}
