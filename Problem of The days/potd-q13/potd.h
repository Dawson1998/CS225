//
// Write a templated function `more` which takes in two variables of the same
// type and returns whichever variable is greater than (`>`) the other.
//
#pragma once

template<typename T> const T & more(const T &one, const T &two) {
  return (one > two) ? one : two;
}
