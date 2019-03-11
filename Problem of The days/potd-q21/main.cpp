#include <iostream>
#include "potd.h"

using namespace std;

int main() {
    // Tests for sum
    std::vector<double> v1;
    for(double i = 0; i < 10; i++)
        v1.push_back(i);

    cout << "v1: ";
    for (vector<double>::iterator it = v1.begin(); it != v1.end(); it++)
        cout << ' ' << *it;
    cout << endl;

    double s1 = sum(v1.begin(), v1.end());
    cout << "Sum of all elements in v1: " << s1 << endl;

    double s2 = sum(v1.begin(), v1.end() - 5);
    cout << "Sum of the first half of v1: " << s2 << endl;

    double s3 = sum(v1.begin() + 5, v1.end());
    cout << "Sum of the second half of v1: " << s3 << endl;


    // Tests for max_iter
    std::vector<double> v2;
    v2.push_back(102);
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(8);
    v2.push_back(100);
    v2.push_back(4);
    v2.push_back(-1);
    v2.push_back(3);
    v2.push_back(0);
    v2.push_back(9);

    cout << "\nv2: ";
    for (vector<double>::iterator it = v2.begin(); it != v2.end(); it++)
        cout << ' ' << *it;
    cout << endl;

    vector<double>::iterator it1 = max_iter(v2.begin(), v2.end());
    cout << "The largest element in v2: " << *it1 << endl;

    vector<double>::iterator it2 = max_iter(v2.begin(), v2.end() - 5);
    cout << "The largest element in the first half of v2: " << *it2 << endl;

    vector<double>::iterator it3 = max_iter(v2.begin() + 5, v2.end());
    cout << "The largest element in the first half of v2: " << *it3 << endl;

    // Tests for sort_vector
    std::vector<double> v3 = v2;
    std::vector<double> v4 = v2;

    // Sort the entire array
    cout << "\nv3: ";
    for (vector<double>::iterator it = v3.begin(); it != v3.end(); it++)
        cout << ' ' << *it;
    cout << endl;

    sort_vector(v3.begin(), v3.end());
    cout << "Sorted v3: ";
    for (vector<double>::iterator it = v3.begin(); it != v3.end(); it++)
        cout << ' ' << *it;
    cout << endl;


    // Sort part of the array
    cout << "\nv4: ";
    for (vector<double>::iterator it = v4.begin(); it != v4.end(); it++)
        cout << ' ' << *it;
    cout << endl;

    sort_vector(v4.begin()+2, v4.end()-2);
    cout << "Partially sort_vectored v4: ";
    for (vector<double>::iterator it = v4.begin(); it != v4.end(); it++)
        cout << ' ' << *it;
    cout << endl;

}
