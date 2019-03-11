#ifndef _PET_H
#define _PET_H

#include <string>

using namespace std;

class Pet {
 public:
  // Declare your constructors here!
  Pet();
  Pet(string a, int b, string c, string d);

  // Other member functions
  void setName(string newName);
  void setBY(int newBY);
  void setType(string newType);
  void setOwnerName(string newName);
  string getName();
  int getBY();
  string getType();
  string getOwnerName();

 private:
  string name;
  int birth_year;
  string type;
  string owner_name;
};

#endif
