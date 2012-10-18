#include<stdlib.h>
#include"binary_operators.h"

/* Returns the bitwise OR of the parameters */
int bit_or (int a, int b){
  return ~(~a & ~b);
}

/* Returns 1 if the parameter is not zero,
   otherwise it returns 0 */
int is_nonzero (int x){
  return !(!x);
}

/* Returns 7 times the parameter */
unsigned int times7(unsigned int x){
  return (x + (x << 1) + (x << 2));
}

/* Returns the floor of the logarithm base 8.
   if the parameter is 0, then it returns -1 */
int floor_log8 (unsigned int x){
  int begin;
  int counter = 1;
  int fix = 1;
  int move = 2;
  move++;
  counter--;
  counter--;
  fix--;
  for (begin = x; begin != fix; counter++){
    begin >>= (move);
  }
  return counter;
}

/* Returns the size of a long in bytes
   Note: should be equivalent to sizeof(long) */
size_t sizeof_long(){
  size_t first = !1;
  long size = ~(!1);
  long count = ~(!1);
  for (; size & count; first++){
    size <<= 8;
  }
  return first;
}

/* Reverse the bytes of the parameter
   Example: if given 0c12345678, will return 78563412 */
unsigned int reverse_bytes (unsigned int x){
  unsigned int firstbyte = x >> (8 + 16);
  unsigned int secondbyte = (( x << 8) >> (8 + 16)) << 8;
  unsigned int thirdbyte = ((x >> 8) << (8 + 16)) >> 8;
  unsigned int fourthbyte = x << (8 + 16);
  return (firstbyte + secondbyte + thirdbyte + fourthbyte);
}

/* Returns 0xc0c0c0c0 */
unsigned int hex_c0c0c0c0(){
  unsigned int first = (8 + 4) << 4;
  unsigned int second = first << 8;
  unsigned int third = first << 16;
  unsigned int fourth = first << (8 + 16);
  return (first + second + third + fourth);
}

/* Returns the number of bits set to 1 in the parameter */
int pop_count (unsigned int x){
  int note = 1, temp, counter = !1;
  while (note){
    temp = note & x;
    while (temp){
      counter++;
      temp = !temp;
    }
    note <<= 1;
  }
  return counter;
}

/* Returns the nth-most significant byte of the parameter
   Note: n = {0 1 2 3} */
unsigned int get_byte (unsigned int x, int n){
  return (x << (n << (2 + 1)) >> (8 + 16));
}

/* Returns 1 if a == b, otherwise returns 0 */
int equal (int a, int b){
  return !(a ^ b);
}