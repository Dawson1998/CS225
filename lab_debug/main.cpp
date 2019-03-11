#include "sketchify.h"

/**
 * A simple wrapper function that invokes sketchify on files in the current
 * directory. Input is read from`in.png` and the resulting image is written
 * to `out.png`.
 */
int main() {
    sketchify("in.png", "out.png");
    return 0;
}
