#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../intro.h"

#include "../cs225/PNG.h"
using cs225::PNG;

#include "../cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <vector>

// default constructor
TEST_CASE("HSLAPixel's default constructor creates a white pixel", "[weight=1]") {
  HSLAPixel pixel;
  REQUIRE( pixel.l == 1 );
}

TEST_CASE("HSLAPixel's default constructor creates an opaque pixel", "[weight=1]") {
  HSLAPixel pixel;
  REQUIRE( pixel.a == 1 );
}


// 3-param constructor
TEST_CASE("HSLAPixel's HSL constructor creates a pixel with provided HSL values", "[weight=1]") {
  HSLAPixel pixel(260, 0.8, 0.7);
  REQUIRE( pixel.h == 260 );
  REQUIRE( pixel.s == 0.8 );
  REQUIRE( pixel.l == 0.7 );
}

TEST_CASE("HSLAPixel's HSL constructor creates an opaque pixel", "[weight=1]") {
  HSLAPixel pixel(260, 0.8, 0.7);
  REQUIRE( pixel.a == 1 );
}


// 4-param constructor
TEST_CASE("HSLAPixel's HSLA constructor creates a pixel with provided HSLA values", "[weight=1]") {
  HSLAPixel pixel(260, 0.8, 0.7, 0.4);
  REQUIRE( pixel.h == 260 );
  REQUIRE( pixel.s == 0.8 );
  REQUIRE( pixel.l == 0.7 );
  REQUIRE( pixel.a == 0.4 );
}


// Image tests
TEST_CASE("Rotate in_01.png", "[weight=1]") {
  rotate("tests/in_01.png", "tests/out.png");
  
  PNG expected, actual;
  expected.readFromFile("tests/out_01.png");
  actual.readFromFile("tests/out.png");

  REQUIRE(expected == actual);
}

TEST_CASE("Rotate in_02.png", "[weight=1]") {
  rotate("tests/in_02.png", "tests/out.png");
  
  PNG expected, actual;
  expected.readFromFile("tests/out_02.png");
  actual.readFromFile("tests/out.png");

  REQUIRE(expected == actual);
}

TEST_CASE("Rotate in_03.png", "[weight=1]") {
  rotate("tests/in_03.png", "tests/out.png");
  
  PNG expected, actual;
  expected.readFromFile("tests/out_03.png");
  actual.readFromFile("tests/out.png");

  REQUIRE(expected == actual);
}

bool compareColor(const HSLAPixel & p1, const HSLAPixel & p2) {
  if (p1.l == 0 && p2.l == 0) { return true; }
  else if (p1.l == 1 && p2.l == 1) { return true; }
  else if (p1.a == 0 && p2.a == 0) { return true; }
  else {
    return (
      p1.h == p2.h &&
      p1.s == p2.s &&
      p1.l == p2.l &&
      p1.a == p2.a
    );
  }
}

TEST_CASE("Creative artwork contains at least three unique colors", "[weight=5][part=3]") {
  int width = 800;
  PNG png = myArt(width, width);
  std::vector<HSLAPixel> colors;

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < width; y++) {
      HSLAPixel p = png.getPixel(x, y);
      bool containsPixel = false;;
      for (HSLAPixel color : colors) {
        if (compareColor(p, color)) { containsPixel = true; break; }
      }

      if (!containsPixel) { colors.push_back(p); }
      if (colors.size() >= 3) { return; }
    }
  }

  if (colors.size() < 3) {
    FAIL("Creative artwork does not contian three unique colors.");
  }
}

