#include <iostream>
#include <fstream>
#include "functions.h"

#include <iostream>
#include <cstdlib>
#include <vector>

bool validUsername(std::string inputUser) {
  std::vector<char> userVec(inputUser.begin(), inputUser.end());
  bool hasNumber;

  if(inputUser.length() == 0) {
    std::cout << "This username is too short." << std::endl;
    return false;
  }

  // Make sure input isn't too short
  std::vector<char> vecCopy = userVec;
  vecCopy.pop_back();
  vecCopy.pop_back();
  if(vecCopy.size() == 0) {
    std::cout << "Your username was too short. Try again, ol' buddy ol' pal..." << std::endl;
    return false;
  }

  // Check input for a number
  for(size_t idx = 0; idx < userVec.size(); idx++) {
    if(std::isdigit(userVec[idx])) {
      hasNumber = true;
    }
  }
  if(!hasNumber) {
    std::cout << "Your username needs at least 1 number." << std::endl;
    return false;
  }

  return true;
}

int arrayIndex(int idx) {
  std::vector<int> myArray = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int len = myArray.size();

  if(idx >= len) {
    std::cout << "This index is out of bounds. Please provide a valid array index..." << std::endl;
    exit(1);
  } else {
    return myArray[idx];
  }
}

int countPrimes(int param) {
  if (param <= 1) {
    std::cout << "Please insert a number greater than 1" << std::endl;
    exit(1);
  } else if(param > 100) {
    std::cout << "Please insert a number no greater than 100" << std::endl;
    exit(1);
  }
  int count = 0;

  for (int i = 2; i <= param; i++) {
    bool prime = true;
    for (int j = 2; j < i; j++) {
      if (i%j == 0) {
        prime = false;
        break;
      }
    }
    if (prime) {
      count++;
    }
  }
  return count;
}

int factorial(int fact) {
  if (fact < 0 || fact > 12) {
    std::cout << "Please enter a number between 0 and 12 (inclusive)." << std::endl;
    exit(1);
  }

  if(fact == 0) {
    return 1;
  } else {
    return fact * factorial(fact-1);
  }
}

bool samesies(int one, int two) {
  return (one == two);
}

int absolutely(int fact) {
  return std::abs(fact);
}

int magnaCalca(int first, int second) {
  if(std::abs(first) > 100 || std::abs(second) > 100) {
    std::cout << "Please insert integers between -100 and 100 (inclusive)." << std::endl;
    exit(1);
  }

  return ((second > first) ? (second - first) : (first - second));
}
