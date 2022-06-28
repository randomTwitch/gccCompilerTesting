// #include "NotMySpace_Main_theReUnion.hh"
#include "inheritance.hh"

// --------- THIS IS GLOBAL NAMESPACE -------------------------- //
// declaring global variable defined after main //
// must be defined here // cant be after main
int globalVar = 0;
// declaring global function //
// defined after main //
void globalFunc ();

int main ()
{
  // the try blocks ensure that after its done stacks gets empty //
  // the labels are unique though but it wont jump all the way bottom skip //
  goto label;
  label0:
  return 0;
  /* This code needs "NotMySpace_Main_theReUnion.hh"
    // auto list = { 1, 3, 4 };

    // ::NotMySpace::Main mainObj = *new ::NotMySpace::Main ();

    // ::MySpace::Main mCo = *new ::MySpace::Main ();
    // mCo.a = 0;
    // mCo.MyFunc (0);
    */
  // int a = static_cast<int> (0); // must to must label
  thread_local auto ai = 0;

  /* This code requires "SpacePtr_Main.h"
  ::SpacePtr::Main sptrMobj = *new ::SpacePtr::Main (); // anon obj initi
  int a0 = 0; // cant pass this to the constructor
  ::SpacePtr::Main(*new int{a0});
  //::SpacePtr::Main sptrMobj0 = *new ::SpacePtr::Main (9);
  sptrMobj.func (); // pointers dot ops Objects arrow -> ops
  ::SpacePtr::Main sptrMobj1{ *new ::SpacePtr::Main };
*/

  /* This code requires "SpaceFunc.h" */
  // ------------------ goto label -------------------------------------- //
  label:
    /*try
      {
        // goto label;

        SpaceFunc::Main obj = *new SpaceFunc::Main ();
        // attempting to get pointer to a function
        // pointer to functions work for static functions only
        // instantiating a template with 3rd arg optional //
        ::SpaceFunc::tempClass<int, void> tC
          = *new ::SpaceFunc::tempClass<int, void> ();
        tC.func0 ();
        delete &tC; // its useless to call // it will exist until main
        try
          {
            try
              {
                // a word of caution always use pointers inside try block //
                // so they gets deleted afterwards that the only way //
                // to ensure nothing else gets jabaited //
                // never trust smart, shared <||> unique, weak pointers //
                // they use lazy deletion, ie you never no might as well when
                // where how they are part of non standard library // iso
                // certified // amazon authors are cheap bastards // this is
                // better than for loop or any other shit you can think of
                // //
                std::cout << "--- Start of try Block ---" << endl;
                ::SpaceFunc::tempClass<int, void> tC
                  = *new ::SpaceFunc::tempClass<int, void> ();
                tC.func0 ();
                delete &tC; // not gets deleted until out of the block
                std::cout << "--- End of try Block ---" << endl;
                // if inside a for loop it would be deleted after each iteration
                throw *new std::exception ();
              }
            catch (int x)
              {
              }
            catch (std::exception e)
              {
                // e.what();
                throw; // this will be caught by the outer try block
              }
          }
        catch (std::exception ())
          {

          }
        catch (...)
          {
            throw;
            // std::cout << "---END OF FIRST CATCH---" << endl;
          }

        *obj.tfunc<int *, 0, 3> ()
          = 50; // changing the static memeber variable //
        std::cout << "Static Member Value: " << *obj.tfunc<int *, 0, 3> ()
                  << endl;
      }
    catch (...)
      {
        std::cout << "---END OF FIRST CATCH---" << endl;
      }*/

    /*try
      {
        // const getter setter function reading const member
        const SpaceFunc::Main constObj = *new SpaceFunc::Main ();
        // if this const object returns a reference type
        constObj.func (); // *this is a const pointer cannot assign to member
                          // variables [this* const] constObj.func(); // const
                          // object cannot use getter function of non const type
                          // to access const members
      }
    catch(...)
      {
      }*/

    try
      {
        // testing explicit constructor //
        // without declaring it explicit the call would be ambiguous //
        // the way that this object instantiates is through the copy constructor
        // which calls the no arg constructor explicitly overriding the default
        ::spacefunc::Main sfObj = *new ::spacefunc::Main ();

        // Testint objects array inistantiation and constructor initialization
        std::cout << "--- Testing Array instantiation ---" << endl;
        // for the third array object instatiation for which i have not provided
        // anything "no arg constructor" was called but not copied into array
        ::SpaceFunc::Main SfObj[3]
          = { *new ::SpaceFunc::Main (10), *new ::SpaceFunc::Main () };
        std::cout << "--- Instatiating third array object ---" << endl;
        // copy assignment operator is deleted
        // now have to define "operator=" inside the class for this to work
        // SfObj[2] = *new ::SpaceFunc::Main();

        // ------------ for assigning same object to itself----------------- //
        // this class defines no arg, copy constructors and "operator=" too //
        // what happens now is: first assignment operator gets called //
        // then from inside the assignment operator copy constructor is called
        // // the returnning object is of type main inside the assignment
        // operator // so the compiler assigns its address through copy
        // constructor to obj // copy constructor and assignment operator //
        // dont define both or you will be stuck in a loop //
        // making assignment operator return an object will stuck you in a loop
        // //
        sfObj = sfObj;                                        // ITS ME //
        ::spacefunc::Main sfObj1 = *new ::spacefunc::Main (); // Copy Con Me //
        sfObj
          = sfObj1; // ITS ME --- ITS NOT ME // calling assignment op twice //
      }
    catch(...)
      {
      }

    // ostream &os = operator<< (std::cout, "test\n");
    // os << "test\n";

    try
      {
        // ---------------------- Inheritance.hh --------------------------- //
        std::cout << "---Inheritance---" << endl;
        ::spacefunc::Inheritance iobj = *new ::spacefunc::Inheritance ();
        std::cout << "---object instatiation done---" << endl;
        iobj.basePubFunc ();
        // there is no copy constructor or assignment operator defined for
        // conversion from derived class to base class or even itself
        // the whole cpp halts at some point in the code //
        // (::spacefunc::Main (iobj)).basePubFunc (); // wrong
        // the base copy constructor called //
        //::spacefunc::Main *baseObj = &iobj; // correct
        // polymorphism //
        (*(::spacefunc::Main *)&iobj).basePubFunc (); // correct
        ((::spacefunc::Main *)&iobj)->basePubFunc (); // correct
        // same as above but on referencing or dereferecing //
        // the arrow operator is used with this which has address //
        // we use [*(this).] for [this->] member access //
        // which means iobj is a pointer type so we use dot operator with it //
        // polymorphism //
        iobj.::spacefunc::Main::basePubFunc ();
        iobj.derivedPubFunc ();
        // virtual function overriding calls derived class function not base //
        iobj.basePubFunc ();
        // never use static or dynamic casting ops because one way or another
        // a new object will be created, so better to have a base class objects
        // in the code always ready to converted to derived class objects
        // means base class objects will obly contain the base part
        // than you have to write an assignemnt operator in derived class that
        // takes base class object and set its contents to the derived class
        // object's base part contents respectively
        std::cout << "Moving on from Virtual Base functions and classes"
                  << endl;
        // when object casts to same type its static but if derived type dynamic
        // //
      }
    catch(...) {  }

    try
      {
#warning when have time define macros that warning
        // void (*ptrFunc) (void);
        // ptrFunc=globalFunc;
        void (*ptrFunc) (void) = (((void (*) (void))::globalFunc));
void (*ptrFuncc) (void) = *new (void (*) (void));
        void (&refffFunc) (void) = (((void (&) (void))::globalFunc));
        void (&&reffFunc) (void) = (((void (&) (void))::globalFunc));
        // typedef, alias, typeof, sizeof, using // #define macros might as well
        (*ptrFunc) ();
        // well its an array then malloc done sure as well //
        // assign arr[0] to arr&& type object  //
        void (&refFunc) (void) = ::globalFunc; refFunc();
        //---------------- LAMBDAS ------------//
        // return type deduced as int //
        auto c = [] (int a, int b) { return 0; };
        // return typed mentioned as int //
        // compiler creates a lambda class type and operator() with args as args
        // d is infact a named lambda a temporary object on stack not heap //
        // trying to take its address gives error as temporary object //
        // dereferencing it gives d's type as [int(*)(int,int)] rt and args
        // pointer function // new operator doesnt works with lambdas //
        auto d = [] (int a, int b) -> int { return 0; };
        auto e = [=] (int a, int b) -> int const { return 0; };
        // generic lambdas templates C++20 //
        // []<typename T> (T &x, T &y) {};
        // capture clause can be this, =, & // cap by value, cap by reference //
        // when = used as capture clause the outer scope variables used inside
        // the body of lambda are copies to lambda // [=](){} // [&](){} //
        // same as defining [operator() const] cannot modify
        // after lambda parameters you can use word mutable which makes this
        // lambda not const //
        // -- class __Lambda6c5
        // -- {
        // --  public:
        // --    __Lambda6c5(unsigned& arg1) : count(arg1) {}
        // --    auto operator()(int x, int y) const { ++count; return x < y; }
        // --    private:
        // --    unsigned& count;
        // --  }
        // the outer variables inside this lambda are used as references //
        // the mutable word is not needed in this case //
        // [=] capture by value is the default // if you dont mention any //
        // the understament means that all outer are passed by reference to lamb
        auto f = [&] (int a, int b) -> int const { return 0; };
        // capturing specific variables by reference or by copy //
        // now f is the only variable avaiable to this lambda //
        // removing & means f that its passed by value to lambda //
        // if there was a b in outer scope the lamba cant shadow error //
        auto g = [&f, e, &d, c] (int a, int b) -> int const { return 0; };
        // e and c are not allowed while = must be first declaration //
        // which means all the outer var are passed by value //
        auto h = [=, &f, &d] (int a, int b) -> int const { return 0; };
        auto i = [&, e, c] (int a, int b) -> int const { return 0; };
        // as lambdas are local to a function, can be args or return type
        // makes no sense to mark them as virtual members to inherit them from
        // if they can be declared and defined later in a class or function //
        // inside a class they have access to this pointer //
        // [captureclause](args){lambdabody}; //

        std::cout << 'c' << endl;
      }
    catch (...) {  }
    goto label0;
  }
  // the push back vectors tainer non standard libs would be gone without a
  // trace straight into oblivion // dont even bother about
  // smart ptrs a temporary neusense  done sure as well// sob sob sob
  // --------------- THIS IS GLOBAL NAMESPACE ----------------- //
  // Defining global function //
  void globalFunc(void)
  {
    if (globalVar == 0)
      {
        ::std::cout << "I am global function" << endl;
        return;
      }
    ::std::cout << "I am not global function" << endl;
  }
  void (*gPf) (void) = *new (void (*) (void));
  auto gL = [] (int a, int b) { return 0; };
  typeof(gPf) gF(typeof(gPf) a, typeof(gL) b) { return *new (void (*) (void)); }
