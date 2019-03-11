#include "Stack.h"
#include <stack>
// `int size()` - returns the number of elements in the stack (0 if empty)
int Stack::size() const {
  return S.size();
}

// `bool isEmpty()` - returns if the list has no elements, else false
bool Stack::isEmpty() const {
  return S.empty();
}

// `void push(int val)` - pushes an item to the stack in O(1) time
void Stack::push(int value) {
  S.push(value);
}

// `int pop()` - removes an item off the stack and returns the value in O(1) time
int Stack::pop() {
  if(S.empty())
    return -1;
  int i = S.top();
  S.pop();
  return i;
}
