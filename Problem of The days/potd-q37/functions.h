#pragma once

#include <string>
/* FUNCTION 0
   This function returns whether the requested Username is valid.
   A valid username should have a minimum of 3 chars and at least 1 number
   @param inputUser: String, the username you want to validate
   */
bool validUsername(std::string inputUser);

/* FUNCTION 1
   This function returns the element of a bool array of size 15
   @param idx: idx of element you want returned
   */
int arrayIndex(int idx);

/* FUNCTION 2
   This function is passed an integer and computes the number
   of primes between one and the inputed number inclusive.
   @param param: Int, range between 2 and 100
   */
int countPrimes(int param);

/* FUNCTION 3
   This function recursively calculates a number's factorial
   @param fact: Int, range between 0 and 12, inclusive
   */
int factorial(int fact);

/* FUNCTION 4
   This function returns whether two numbers are the same or not
   @param one: Int, range between -(INT_MAX/2) and INT_MAX/2
   @param two: Int, range between -(INT_MAX/2) and INT_MAX/2
   */
bool samesies(int inone, int intwo);

/*  FUNCTION 5
	This function returns a number's absolute value
	@param absolutely: any valid 32 bit signed integer
	*/
int absolutely(int y);

/* FUNCTION 6
   This function calculates the distance between two numbers
   @param first  Int, range between -100 and 100, inclusive
   @param second Int, range between -100 and 100, inclusive
   */
int magnaCalca(int first, int second);
