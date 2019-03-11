#include <iostream>

#include "Queen.h"
#include "Piece.h"

void printPiece(Piece *p) {
  std::cout << "In printPiece, printType() of the same memory address is: "
       << p->getType() << std::endl;
}

int main() {
  Queen *q = new Queen();

  std::cout << "In main, printType() of Queen *q is: "
       << q->getType() << std::endl;

  printPiece(q);

  delete q;  // Don't forget to free your memory! :)
  return 0;
}
