#include <iostream>
#include <vector>
#include "Friend.h"

int main() {
    std::vector<std::vector<int>> M1 = {{1,0,1,0,0}, {0,1,0,1,1}, {1,0,1,0,1}, {0,1,0,1,0}, {0,1,1,0,1}};
	int count1 = findCircleNum(M1);
    std::cout << "Number of friend circle for class 1 is "<< count1 << std::endl;

    std::vector<std::vector<int>> M2 = {{1,1,0},{1,1,0},{0,0,1}};
	int count2 = findCircleNum(M2);
    std::cout << "Number of friend circle for class 2 is "<< count2 << std::endl;

    std::vector<std::vector<int>> M3 = {{1,1,0,0,0,0}, 
				{1,1,0,1,0,0}, 
				{0,0,1,0,1,0},
				{0,1,0,1,0,0},
				{0,0,1,0,1,0},
				{0,0,0,0,0,1}};
	int count3 = findCircleNum(M3);
    std::cout << "Number of friend circle for class 3 is "<< count3 << std::endl;

	return 0;
}
