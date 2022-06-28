#include <iostream>
#include "SpaceFunc.h"
using namespace std;

namespace SpaceFunc
{
// a class template //
template <typename t1, typename t2 = t1, typename t3 = double> class tempClass
{
protected:
  t1 templateProA = 10;
  // marked virtual for optional overriding in derived class //
  // marking final makes it un inheritable //
  virtual void templateBaseProFunc () const noexcept final
  {
    std::cout << "I am Base Template's Protected Function" << endl;
  }

private:
  // objects of that class can access all, but not this class can
  // which means you have to use a constructor and pass by referece so that
  // object will have full access to all the members of this class
  // provided you define a constructor that will take in the object of that
  // class and then in the constructor that class's object will have full access
  // and then you can use copy assignment operator = to do the work by that
  // object to access this class's members and functions
  // when you assign object of this class to the other, copy constructor will
  // be called and that object will have full access to this class
  // must be useful in nested classes down the chain
  friend class ::SpaceFunc::Main;
public:
  // defining a copy constructor assignment operator //
  static t1 a; t3 b = 20; t1 c{10};
  tempClass () { std::cout << "Template Constructor" << endl; };
  tempClass (t1) : tempClass (){};
  // General t2 Czeh Republic //
  t2 func0(){ std::cout << "Class Template" << b << endl; }
  // cant be private // thanks //
  ~tempClass(){std::cout<<"The Network Resource Release Destructor Called"<<endl; /*delete *this;*/}
};
// class template ends here //
int ::SpaceFunc::Main::a = 10; // the static member of class
::SpaceFunc::Main::Main () : b (10), c (20) // no arg constructor
{
  std::cout << "No Arg Constructor Called" << endl;
  return;
}
// one arg constructor //
::SpaceFunc::Main::Main (int a) : ::SpaceFunc::Main::Main() // a=10 makes it ambiguous constructor call
{
  a = 1;
  (*this).a = a;
  std::cout << "1 arg Constructor Called" << endl;
  return;
}
// overriding the default copy constructor // must define "operator=" now
// for assignments to work //
::SpaceFunc::Main::Main (const ::SpaceFunc::Main &cC)
{
  std::cout << "Copy Constructor Called" << endl;
}
  int ::SpaceFunc::Main::func0 () { return 0; }
  // defining the const setter getter member function //
  void ::SpaceFunc::Main::func () const { std::cout<<"Reading Const: "<<this->x<<endl; }
  // defining the inline static function declared in "SpaceFunc.h" //
  inline static int func1 () { return 0; } // the inline here is optional //

  // Defining Template Function //
  // using global scoping here makes it erroneos // :: :: :: :: :: :: :: :: ::
  // we have successfully defined outside the class in the same namespace a
  // templated function declared inside class, now it can also be defined
  // outside the namespace in the global //
  template <typename T, int a = 1, int b, typename T0 = int>
  T
  SpaceFunc::Main::tfunc0 ()
  {
    return &this->a;
  }

  // defining the default copy constructor // assignment operator
  // ::SpaceFunc::Main (const ::SpaceFunc::Main &cc) {}
}

// EITHER AN INDIVIDUAL function can be friend of a class or whole class can be
// a friend to another class
// a friend function can be a global function or it
// can be a member of another class
// a function cant be a friend of a class of which its a member so access
// modifiers dont apply to it
// for example a friend function needs to access objects of 2 different classes

// ---------------------- end of namespace ------------------------------- //

namespace spacefunc
{
class Main
{
  // inherited class members have access to it //
  // inherited objects dont have access here //
  // members of this class have complete access here //
  // objects of this class dont have access here //
protected:
  // Inheritance () = default;
  int proA = 10;
  virtual void baseProFunc(){ std::cout<<"I am base Pro Func"<<endl; }
  // inherited class members dont have access to it //
  // inherited objects dont have access here //
  // members of this class have complete access here //
  // objects of this class dont have access here //
private:
  // Inheritance () = delete;
  int priA = 10;
  // this can be "override final" as public in derived class //
  virtual void basePriFunc(){ std::cout<<"I am base Pvt Func"<<endl; }
  // inherited class have complete access here //
  // inherited objects have complete access here //
  // members of this class have complete access here //
  //objects of this class have complete access here //
public:
  // --- BASE CLASS FUNCTIONS --- //
  int pubA = 10;
  virtual void basePubFunc() { std::cout<<"I am base Pub Func"<<endl; }
  // assigning derived class object to base results in derived class
  // destructor never called, only base class, leaves derived class objects
  // in memory this virtual base class destuctor makes sure both gets called
  // virtual ~Main () = default;
  virtual ~Main () { std::cout << "Base Class destructor" << endl; }
  // --- BASE CLASS FUNCTIONS --- //

  explicit Main () = default;
  Main (int a) { std::cout << " yes its me " << &this[0] << endl; }
  // the default no args constructor //
  // the default copy constructor // delegating constructor
  Main (const Main &sp) : Main () { std::cout << "Copy Constructor Me" << endl; }
  // do not allow copying // could be private or explicit // same result
  // same with copy assignment operator // exchanging pointers by reference
  // SpaceFunc (const SpaceFunc &sp) = delete;
  void
  func (const int *c, int *const d, int &e, int &&f, int arr[][4],
        int (&Arr)[][3], int (&Arr0)[], int (&Ar1)[4])
  {
    // pointer to constant
    const int *a;     // the pointer points to a const int, variables
    int *const b = 0; // its a constant pointer that cannot change

    int arrr[][4] = { { 1 }, { 2 }, { 3 }, { 4 } };
    // name of arrr is its memory address adding 2 to it selects first dimension
    // getting the address adding 0 to it selects second dimension
    // dereferencing the final memory address
    std::cout << *(*(arrr + 2) + 0) << endl; // prints 3
    std::cout << *((&arrr[0]) + 2)[0] << endl; // prints 3
  }

  // OPERATOR OVERLOADING BEGINS HERE //
  // only prototypes not defined any where //
  // 1 arg is a MUST // use [this] for the other one //
  // the const arg means that it can take either a const or variable //
  // const references are not allowed //
  // obj.operator<(obj); //
  // if operator cant access private use friend keyword //
  // const and static friends are not allowed //
  ::spacefunc::Main &operator< (const ::spacefunc::Main &) const;
  ::spacefunc::Main &operator< (const int &) const;
  // not defined //
  const ::spacefunc::Main operator+ (const ::spacefunc::Main Ropr) const;
  // this binary operator has no problems with 2 args or 3 args, left or right
  // it is defined outside the class scope in the namespace //
  // this cant be a global function //
  // overloading assignment operator const and non const //
  // global can return *this without problem but stuck in a loop if inside obj
  const ::spacefunc::Main &operator= (const ::spacefunc::Main &Ropr) const;
  const void operator= (::spacefunc::Main &Ropr)
  {
    // checking if objects are of same address //
    // means assigning same object address to same object address //
    std::cout << "ITS ME" << endl;
    if(&Ropr == this){ return;  }
    // these lines will execute if ojects addresses differ //
    std::cout << "ITS NOT ME" << endl;
    //*this = Ropr;
    return;
  }
  const void operator== (Main m) const = delete;
  // cpp20++ //
  // std::partial_ordering operator<=>(const Main& otherBox) const = default;

  // overloading the dafault "operator<<" and "operator>>" //
  // in main.cpp >> [::spacefunc::Main obj; std::cout<<obj;]
  // if it were to be a global then 2 args last one for the this object //
  // std::ostream &operator<< (std::ostream &stream){stream<<"Out we go\n";return stream;}
  // in main.cpp >> [::spacefunc::Main obj; std::cin>>obj;]
  // std::istream &operator>> (std::istream &stream){stream>>*this.a;return stream;}
  std::ostream &operator<< (std::ostream &stream); // not defined
  std::istream &operator>> (std::istream &stream); // not defined

  // uniray operator no args, pre post increment decrement 1 args //
  // +, -, ~, !, &, and * //
  const ::spacefunc::Main operator~ () const; // not defined
  // global uniray 1 args, global pre post inc dec 2 args  //

  // prefix notation //
  ::spacefunc::Main &operator++ (){ /*increment local members*/return *this; };
  // you have to call prefix from inside the postfix and return the copy
  // of the object not the real reference
  // postfix notation // and then maybe test obj++++;
  ::spacefunc::Main operator++ (int){ Main copy =*this; ++(*this); return copy; };

  // it could be an assignment, an indexing, or null indexed initialization //
  // just create size [s] number of copies and return the pointer //
  // remember the pointer object is calling while indexing //
  const ::spacefunc::Main& operator[](size_t s){ return *this; };
  // only declared not defined // could be global or out side class defined //
  const ::spacefunc::Main &operator() (int a, int b, int c = 0) const; // proto

  // START CONVERSION OPERATORS START // CANNOT SPECIFY RETURN TYPE
  // double could be any class, struct, union  aggregates or scalars //
  explicit operator double () const { return 0; }
  operator double & () = delete;
  operator double *** () = delete;
  operator Main * () = delete;
  operator Main & () = delete;

  // ENDS CONVERSION OPERATORS ENDS // THE RETURN TYPE IS TYPE after operator

  // OPERATOR OVERLOADING ENDS HERE //

  // defining a desructor //
  // define a static member which would get the address of the object to be
  // deleted in here set it to nullPtr, pointer still exists in memory
  // might as well counter it
  // ~Main () { this= }
};

// for comparing against integers[or scalars] you have to define your Main
// Constructor that takes integer as explicit other wise the compiler would
// first convert the right side of < to this object first by calling the integer
// constructor and then will compare so this operator function will never be
// used or you can call "obj.operator<(integer)" notation explicitly this will
// work for "obj<integer" comparisons not "integer<obj" comparisons this only
// occurs when working with scalar types while working with other aggregate
// types that also define comparison operators, itll be obvious whose on the
// left side and whose on the right side of the comparison
// when aggrigate types compare with scalars compiler tries to perform
// conversion by calling its constructor to convert from that scalar to this
// object type, similary scalars are pointers too
::spacefunc::Main & ::spacefunc::Main::operator< (const int &) const { return *new ::spacefunc::Main(); }
::spacefunc::Main & ::spacefunc::Main::operator< (const ::spacefunc::Main &) const { return *new ::spacefunc::Main (); }
}

// ------------- GLOBAL OPERATORS ARE DEFINED HERE --------------------- //
// defining global operator functions with 3 args //
// this global function operator cant be const //
// overloading the function signature, for left and right side of comparison //
const ::spacefunc::Main operator+ (const ::spacefunc::Main &Lopr, int Ropr);
const ::spacefunc::Main operator+ (int Ropr, const ::spacefunc::Main &Lopr);
// declared in the ::spacefunc::Main class assignment operator //
// defining it in global scope  //
// there is no other way to define assign op in global scope witout dec in ther //
const ::spacefunc::Main& ::spacefunc::Main::operator= (const ::spacefunc::Main &Ropr) const { return *this; };
