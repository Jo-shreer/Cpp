/*
Bitfields allow the packing of data in a structure using a specific number of bits, useful in embedded or protocol programming.
  */

struct Flags 
{
    unsigned int flag1 : 1;
    unsigned int flag2 : 2;
};
