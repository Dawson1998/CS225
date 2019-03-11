#include <iostream>
#include <cstdlib>
#include "Memory.h"

using namespace std;

int main() {
  // Create a memory
  Memory memory = Memory();

  // Print the statistics
  memory.printStats();
  /* Expected output:
    ==================================
    Available: 0x10000 bits
    Used: 0x10000 bits
    ==================================
    0x0000: Free
  */

  // Allocate 0x4000 bits of memory
  std::cout << "Allocating 4 chunks of memory..." << '\n';
  size_t size = 0x4000;
  unsigned address1 = memory.allocate(size);
  unsigned address2 = memory.allocate(size);
  unsigned address3 = memory.allocate(size);
  unsigned address4 = memory.allocate(size);

  // Print statistics
  memory.printStats();
  /* Expected output:
    ==================================
    Available: 0x0 bits
    Used: 0x0 bits
    ==================================
    0x0000: InUse
    0x4000: InUse
    0x8000: InUse
    0xc000: InUse
  */

  std::cout << "Freeing the second chunk..." << '\n';
  memory.free(address2);
  memory.printStats();
  /* Expected output:
    Freeing the second chunk...
    ==================================
    Available: 0x4000 bits
    Used: 0x4000 bits
    ==================================
    0x0000: InUse
    0x4000: Free
    0x8000: InUse
    0xc000: InUse
  */

  std::cout << "Freeing the third chunk..." << '\n';
  memory.free(address3);
  memory.printStats();
  /* Expected output:
    ==================================
    Available: 0x8000 bits
    Used: 0x8000 bits
    ==================================
    0x0000: InUse
    0x4000: Free
    0xc000: InUse
  */

  std::cout << "Defragmenting..." << '\n';
  memory.defragment();
  memory.printStats();
  /* Expected output:
    ==================================
    Available: 0x8000 bits
    Used: 0x8000 bits
    ==================================
    0x0000: InUse
    0x4000: InUse
    0x8000: Free
  */

  return 0;
}
