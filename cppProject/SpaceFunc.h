#include <iostream>
using namespace std;

namespace SpaceFunc
{
class Main
{
public:
  // a function template //
  template <typename T, int a,int b, typename T0=int> T tfunc () { return &this->a; };
  // declaration here but definition in the "spacefunc.hh"
  template <typename T, int a, int b, typename T0 = int> T tfunc0 ();

public:
  const int x = 0;
  static int a;
  mutable int b = 20; // mutable can be changed by const objects
  int c{ 10 };
  Main ();
  Main (int);
  int func0 ();
  static int func1() { return 0; } // cannot declare must define
  void func (){ std::cout<<this->x<<endl; }                  // defined in spacefunc.hh
  void func () const; // overloading const function declaration  // defined in spacefunc.hh
  // cant be defined outside the class // must be defined here
  // can access public and private //
  // the global function that can access any member of the class provided you pass the object to it
  friend void ffunc (const Main &){};
  // copy constructor assignment operator// defined in spacefunc.hh
  Main (const Main &cc);
};

  }
