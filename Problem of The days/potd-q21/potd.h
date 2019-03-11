#ifndef POTD_H
#define POTD_H

#include <string>
#include <vector>

using namespace std;

/** Returns the sum of elements between start to end. 
	The value at start is included, while the value at end is not.
	*/
double sum(vector<double>::iterator start, vector<double>::iterator end);

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end);

/** Sort, in descending order, part of an array between start to end. 
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end);


#endif
