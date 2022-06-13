#include "spacefunc.hh"
#include <iostream>
using namespace std;

namespace spacefunc
{
// default is private for base classes
// default is public for base structs
// what about unions and enums <><><><><>
// pvt base class will make all its members pvt to the derived class objects //
class Inheritance : public ::spacefunc::Main
{
protected:
  // Inheritance () = default;
  int proA = 9;
  void baseProFunc(){ std::cout<<"I am Derived Pro Func"<<endl; }


private:
  // inherits Base Class Constructors //
  // now you can construct derived class objects with arguments that only
  // base classes accept //
  using ::spacefunc::Main::Main;
  // Inheritance () = delete;
  int priA = 9;
  void basePriFunc(){ std::cout<<"I am Derived Pvt Func"<<endl; }


public:
  int pubA = 9;
  Inheritance () : ::spacefunc::Main (9), proA (9), priA (9)
  {
    //(*(::spacefunc::Main *)&iobj)
    // similarly this way you can access the BASE portion of this object //
    (*(::spacefunc::Main *)this).pubA = 0;
    std::cout << "Derived Class No Arg Constructor" << endl;
  }
  // inherits a particular member of base and makes it this accessor access //
  using ::spacefunc::Main::basePubFunc;
  void basePubFunc() { std::cout << "I am the Derived Pub class" << endl; }
};
}
