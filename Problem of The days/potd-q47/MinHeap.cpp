#include "MinHeap.h"

MinHeap::MinHeap(const vector<int> & vector)
{
    int inf = numeric_limits<int>::min();
    elements.push_back(inf);
    elements.insert(elements.end(), vector.begin(), vector.end());
    buildHeap();
}

MinHeap::MinHeap()
{
    int inf = numeric_limits<int>::min();
    elements.push_back(inf);
}

void MinHeap::buildHeap()
{
    std::sort(elements.begin() + 1, elements.end());
}

void MinHeap::heapifyDown(int index)
{
    int length = elements.size();
    int leftChildIndex = 2 * index;
    int rightChildIndex = 2 * index + 1;

    if (leftChildIndex >= length)
        return; // index is a leaf

    int minIndex = index;

    if (elements[index] > elements[leftChildIndex]) {
        minIndex = leftChildIndex;
    }

    if ((rightChildIndex < length)
        && (elements[minIndex] > elements[rightChildIndex])) {
        minIndex = rightChildIndex;
    }

    if (minIndex != index) {
        // need to swap
        int temp = elements[index];
        elements[index] = elements[minIndex];
        elements[minIndex] = temp;
        heapifyDown(minIndex);
    }
}

void MinHeap::heapifyUp(int index)
{
    if (index < 2)
        return;

    int parentIndex = index / 2;

    if (elements[parentIndex] > elements[index]) {
        int temp = elements[parentIndex];
        elements[parentIndex] = elements[index];
        elements[index] = temp;
        heapifyUp(parentIndex);
    }
}

void MinHeap::insert(int newValue)
{
    int length = elements.size();
    elements.push_back(newValue);
    heapifyUp(length);
}

int MinHeap::peek() const
{
    return elements.at(1);
}

int MinHeap::pop()
{
    int length = elements.size();
    int p = -1;

    if (length > 1) {
        p = elements[1];
        elements[1] = elements[length - 1];
        elements.pop_back();
        heapifyDown(1);
    }

    return p;
}

void MinHeap::print() const
{
    if (elements.size() > 1) {
        int length = elements.size();
        cout << "[";
        for (int i = 1; i < length - 1; i++) {
            cout << elements[i] << ", ";
        }
        cout << elements[elements.size() - 1] << "]" << endl;
    } else {
        cout << "[ ]" << endl;
    }
}
