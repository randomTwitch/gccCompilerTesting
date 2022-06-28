#include "spacefunc.hh"
#include <iostream>
using namespace std;

extern "C++"
{
  namespace spacefunc
  {

  }
}

namespace spacefunc
{
// CLASS DECLARATION //
class Inheritance;
// default is private for base classes
// default is public for base structs
// what about unions and enums <><><><><>
// pvt base class will make all its members pvt to the derived class objects //
// giving multiple base inheritance with template class base //
// object of this class can access to all of these bases //
// 2 classes with same base should use virtual while inheriting, so that a
// child class of those 2 classes not have ambiguity with base class members
// or cast child class object to either base class type that share a base
// CLASS DEFINITION could be defined outside in the same namespace or global //
// classes cannot inherit from this "final"
class Inheritance final : public ::spacefunc::Main,
                          public virtual ::SpaceFunc::Main,
                          public ::SpaceFunc::tempClass<int, void>
{
protected:
  // Inheritance () = default;
  int proA = 9;
  // virtual keyword is optional here //
  virtual void baseProFunc() override final { std::cout<<"I am Derived Pro Func"<<endl; }


private:
  // inherits Base Class Constructors //
  // now you can construct derived class objects with arguments that only
  // base classes accept //
  using ::spacefunc::Main::Main;
  // Inheritance () = delete;
  int priA = 9;
  // virtual keyword is optional here //
  virtual void basePriFunc() override final { std::cout<<"I am Derived Pvt Func"<<endl; }


public:
  int pubA = 9;
  Inheritance () : ::spacefunc::Main (9), proA (9), priA (9)
  {
    //(*(::spacefunc::Main *)&iobj)
    // similarly this way you can access the BASE portion of this object //
    // polymorphism //
    (*(::spacefunc::Main *)this).pubA = 0;
    ((::spacefunc::Main &)*this).pubA = 0;
    // ((::spacefunc::Main *)&this)->pubA = 0;
    // (*(::spacefunc::Main *)&this).pubA = 0;
    std::cout << "Derived Class No Arg Constructor" << endl;
  }
  // inherits a particular member of base and makes it this accessor access //
  using ::spacefunc::Main::basePubFunc;
  // virtual keyword is optional here //
  virtual void basePubFunc () override final
  {
    std::cout << "I am the Derived Pub class" << endl;
    // same as using this pointer and casting to base class and dereference it
    ::spacefunc::Main::pubA = 0; return;
  }
  // virtual can only appear on non static member functions //
  // this ones marked for inheritance, any child class that doesnt overrides it
  // will get a compilation error, must override it can have a different
  // signature ie the args not the return type respectively
  // derived classes wont be allowed to override this virtual function "final"
  // "noexcept" tells its a non exception throwing function
  virtual void derivedPubFunc (int a = 0) noexcept(false) final
  {
    // derefecing with array operator gives access to base and derived //
    // polymorphism //
    std::cout << *(&this[5].proA) << endl;
  }
  // the derived class wont have access to this class's destuctor //
  virtual ~Inheritance () final {}
};

class Inheritance0; // class declaration //
// defining an abstract // if no member variables or functions = interface //
class Inheritance0 :  public ::spacefunc::Main
{
protected:
private:
public:
  // a pure virtual function makes class abstarct //
  // cannot instantiate only derive from this class //
  // constructors destructors for implementors only // can have pointers* or
  // reference& types
  // only the derived class can call constructor or destructor //
  // deriving class must define the pure virtual functions //
  // not defining in derived class would result derived class being abstact too
  virtual void pubFunc () noexcept = 0;
  virtual ~Inheritance0 () noexcept = default;
};
}
