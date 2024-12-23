#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sieveV6(int n) {

    int p_small[11] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    if (n <= 10) {
        return p_small[n];
    }

    // bound for the size 
    unsigned int size = (n * (log(n) + log(log(n)) - 1 + ((log(log(n)) - 2) / log(n))) + 900)/3;
    
    // giant string 
    unsigned char *a = calloc(size, sizeof(unsigned char));
    unsigned int bound = (unsigned int) sqrt(size+ (size << 0x1 ) ) / 3 + 1;
    int i = 0;

    
    n -= 2;
    

    while (i <= bound) {
        if (!a[i]) {
            int multdex = 1;
            for (int y=((i<<0x2)+5-(i&0x1))+((1+(i>>0x1))<<0x1); y<size; y+=(i+(i<<0x1)+5-(i&0x1))+(-1+ ((multdex&0x1)<<0x1))*(((1+(i>>0x1))<<0x1))) {
                a[y] = 1;
                multdex++;
            }
            n--;
        }
        i++;
    }


    while (n) {
        n -= !a[i];
        i++;
    }

    i--;
    free(a);
    return i+(i<<0x1)+5-(i&0x1);
}