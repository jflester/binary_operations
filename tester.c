#include <stdio.h>
#include "binary_operators.h"

static int correct_bit_or(int a, int b);
static void test_case(int a, int b);
static unsigned int correct_get_byte(unsigned int x, int n);
static void test_get_byte(unsigned int x, int n);
static int correct_equal(int a, int b);
static void test_equal(int a, int b);
static int correct_is_nonzero(int x);
static void test_nonzero(int x);
static unsigned int correct_times7(unsigned int x);
static void test_times7(unsigned int x);
static size_t correct_sizeof_long();
static void test_sizeof_long();
static unsigned int correct_reverse_bytes(unsigned int x);
static void test_reverse(unsigned int x);
static unsigned int correct_hex();
static void test_hex();
static int correct_pop_count(unsigned int x);
static void test_pop_count(unsigned int x);
static int correct_floor_log8(unsigned int x);
static void test_floor_log8(unsigned int x);

int main() {
  test_case(0, 0);
  test_case(1, 2);
  test_case(0x29, 0x983);
  test_get_byte(0x0a0b0c0d, 0);
  test_get_byte(0x0a0b0c0d, 3);
  test_equal(4, 4);
  test_equal(2, 7);
  test_nonzero(35);
  test_nonzero(0);
  test_times7(7);
  test_reverse(0x12345678);
  test_sizeof_long();
  test_hex();
  test_pop_count(0x05000001);
  test_floor_log8(64);
  test_floor_log8(87);
  test_floor_log8(0);
  test_floor_log8(513);
  return 0;
}

static int correct_bit_or(int a, int b) {
  return a | b;
}

static void test_case(int a, int b) {
  int correct_result, my_result;

  printf("testing bit_or(%d, %d): ", a, b);
  correct_result = correct_bit_or(a, b);
  my_result = bit_or(a, b);
  if (my_result == correct_result) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", my_result, correct_result);
  }
}

static unsigned int correct_get_byte(unsigned int x, int n) {
  x = 0x0a0b0c0d;
  if (n == 0){
    return (0x0a);
  }
  else if (n == 1){
    return (0x0b);
  }
  else if (n == 2){
    return (0x0c);
  }
  else {
    return (0x0d);
  }
}

static void test_get_byte(unsigned int x, int n){
  int correct, mine;

  printf("testing testing get_byte(%d, %d): ", x, n);
  correct = correct_get_byte(x, n);
  mine = get_byte(x, n);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static int correct_equal(int a, int b){
  if (a == b){
    return 1;
  }
  else {
    return 0;
  }
}

static void test_equal(int a, int b){
   int correct, mine;

  printf("testing testing equal(%d, %d): ", a, b);
  correct = correct_equal(a, b);
  mine = equal(a, b);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static int correct_is_nonzero(int x){
  if (x != 0){
    return 1;
  }
  else {
    return 0;
  }
}

static void test_nonzero(int x){
 int correct, mine;

  printf("testing testing nonzero(%d): ", x);
  correct = correct_is_nonzero(x);
  mine = is_nonzero(x);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static unsigned int correct_times7(unsigned int x){
  return 7*x;
}

static void test_times7(unsigned int x){
 int correct, mine;

  printf("testing testing times7(%d): ", x);
  correct = correct_times7(x);
  mine = times7(x);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static size_t correct_sizeof_long(){
  return sizeof(long);
}

static void test_sizeof_long(){
 int correct, mine;

  printf("testing testing sizeof_long");
  correct = correct_sizeof_long();
  mine = sizeof_long();
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static unsigned int correct_reverse_bytes(unsigned int x){
  x = 0x78563412;
  return x;
}

static void test_reverse(unsigned int x){
 int correct, mine;

  printf("testing testing reverse(%d): ", x);
  correct = correct_reverse_bytes(x);
  mine = reverse_bytes(x);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static unsigned int correct_hex(){
  unsigned int x = 0xc0c0c0c0;
  return x;
}

static void test_hex(){
 int correct, mine;

  printf("testing testing hex");
  correct = correct_hex();
  mine = hex_c0c0c0c0();
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static int correct_pop_count(unsigned int x){
  return 3;
}

static void test_pop_count(unsigned int x){
 int correct, mine;

  printf("testing testing pop_count(%d): ", x);
  correct = correct_pop_count(x);
  mine = pop_count(x);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}

static int correct_floor_log8(unsigned int x){
  if (x == 64){
    return 2;
  }
  else if (x == 87){
    return 2;
  }
  else if (x == 0){
    return -1;
  }
  else if (x == 513){
    return 3;
  }
  else {
    return 1;
  }
}

static void test_floor_log8(unsigned int x){
int correct, mine;

  printf("testing testing log8(%d): ", x);
  correct = correct_floor_log8(x);
  mine = floor_log8(x);
  if (mine == correct) {
    printf("PASSED!\n");
  }
  else {
    printf("FAILED. (Got %d, should be %d.)\n", mine, correct);
  }
}