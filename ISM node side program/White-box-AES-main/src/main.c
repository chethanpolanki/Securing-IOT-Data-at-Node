#include "wbaes.h"

int main()
{
    unsigned char IN[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
    u8 key[16] = {0};
    unsigned char OUT[16];
    unsigned char OOUT[16];
    shares *ptx[128];
    shares *k[11][128];
    shares *ctx[128];
    printf("input");
    printState(IN);
    printf("aes_128_encrypt");
    aes_128_encrypt(IN, key, OOUT);
    printState(OOUT);
    ///// encode plaintexts
    encode_ptx(IN, ptx);
    genenkey(key, k);
    ///// encryption
    wbaes(ptx, k, ctx);
    ///// decode ciphertexts
    decode_ctx(ctx, OUT);
    printf("decoded output");
    printState(OUT);

    printf("key");
    printState(key);

    return 0;
}