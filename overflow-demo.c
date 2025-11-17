// Author: Abhishek Bhagwat
// Title: Buffer Overflow in C
// Usage: ./overflow-demo
// Compile-time flags required: -fno-stack-protector

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

void vulnerableFunction(unsigned long addr) {
  char bffr[MAX];

  // Buffer of size MAX overflows on string input of length 64B, where last 8B are the address to exploit()
  // The crafted string overwrites the 'rip' or next-instruction address
  sprintf(bffr, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%c%c%c%c%c%c\x00\x00", addr & 0xff, (addr & 0xff00) >> 8, (addr & 0xff0000) >> 16, (addr & 0xff000000) >> 24, (addr & 0xff00000000) >> 32, (addr & 0xff0000000000) >> 40);

  printf("[DEBUG] Input String: %s\n", bffr);
}

void exploit() { printf("\nExploited!\n"); }

int main(void) {
  printf("[DEBUG] expolit() Address: %p\n", exploit);
  // void (*pf)() = exploit;
  // printf("[DEBUG] Function pointer at expolit(): %x\n", pf);
  vulnerableFunction((unsigned long)exploit);
  return 0;
}
