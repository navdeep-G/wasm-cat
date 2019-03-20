#include <iostream>
#include <string>

#include "cat.h"
#include "emscripten/bind.h"

using namespace emscripten;
using namespace std;

Cat::Cat(string n): name(n) {}

string Cat::getGreeting () {
  return "Je m'appelle " + name + ", bonjour de C++!";
}

void Cat::makeSound () {
  cout << "meow!" << '\n';
}

EMSCRIPTEN_BINDINGS (c) {
  class_<Cat>("Cat")
    .constructor<string>()
    .function("makeSound", &Cat::makeSound)
    .function("getGreeting", &Cat::getGreeting);
}
