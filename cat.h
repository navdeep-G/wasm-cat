#ifndef Cat_H
#define Cat_H

#include <string>

using std::string;

class Cat {
  string name;

  public:
    Cat (string n);
    string getGreeting ();
    void makeSound ();
};

#endif
