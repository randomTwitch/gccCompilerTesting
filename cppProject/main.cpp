// #include "NotMySpace_Main_theReUnion.hh"
#include "inheritance.hh"

int main ()
{
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
  label:
    SpaceFunc::Main obj = *new SpaceFunc::Main ();
    // attempting to get pointer to a function
    // pointer to functions work for static functions only
    // instantiating a template with 3rd arg optional //
    ::SpaceFunc::tempClass<int, void> tC
      = *new ::SpaceFunc::tempClass<int, void> ();
    tC.func0 (); delete &tC; // its useless to call // it will exist until main
    try
      {
        // a word of caution always use pointers inside try block //
        // so they gets deleted afterwards that the only way //
        // to ensure nothing else gets jabaited //
        // never trust smart, shared <||> unique, weak pointers //
        // they use lazy deletion, ie you never no might as well when where how
        // they are part of non standard library // iso certified //
        // amazon authors are cheap bastards //
        // this is better than for loop or any other shit you can think of //
        std::cout << "--- Start of try Block ---" << endl;
        ::SpaceFunc::tempClass<int, void> tC
          = *new ::SpaceFunc::tempClass<int, void> ();
        tC.func0 (); delete &tC; // not gets deleted until out of the block
        std::cout << "--- End of try Block ---" << endl;
        // if inside a for loop it would be deleted after each iteration
        // throw tC;
      }
    catch (std::exception e)
      {
        // e.what();
      }
    *obj.tfunc<int*,0,3> () = 50; // changing the static memeber variable //
    std::cout << "Static Member Value: " << *obj.tfunc<int *, 0, 3> () << endl;
    // const getter setter function reading const member
    const SpaceFunc::Main constObj = *new SpaceFunc::Main ();
    // if this const object returns a reference type
    constObj.func (); // *this is a const pointer cannot assign to member variables [this* const]
     // constObj.func(); // const object cannot use getter function of non const type to access const members


    // testing explicit constructor //
    // without declaring it explicit the call would be ambiguous //
    // the way that this object instantiates is through the copy constructor
    // which calls the no arg constructor explicitly overriding the default
    ::spacefunc::Main sfObj = *new ::spacefunc::Main ();

    // Testint objects array inistantiation and constructor initialization
    std::cout << "--- Testing Array instantiation ---" << endl;
    // for the third array object instatiation for which i have not provided
    // anything "no arg constructor" was called but not copied into array
    ::SpaceFunc::Main SfObj[3] = { *new ::SpaceFunc::Main (10), *new ::SpaceFunc::Main () };
    std::cout << "--- Instatiating third array object ---" << endl;
    // copy assignment operator is deleted
    // now have to define "operator=" inside the class for this to work
    // SfObj[2] = *new ::SpaceFunc::Main();

    // ------------ for assigning same object to itself----------------- //
    // this class defines no arg, copy constructors and "operator=" too //
    // what happens now is: first assignment operator gets called //
    // then from inside the assignment operator copy constructor is called //
    // the returnning object is of type main inside the assignment operator //
    // so the compiler assigns its address through copy constructor to obj //
    // copy constructor and assignment operator //
    // dont define both or you will be stuck in a loop //
    // making assignment operator return an object will stuck you in a loop //
    sfObj = sfObj; // ITS ME //
    ::spacefunc::Main sfObj1 = *new ::spacefunc::Main (); // Copy Con Me //
    sfObj = sfObj1; // ITS ME --- ITS NOT ME // calling assignment op twice //

    ostream &os = operator<< (std::cout, "test\n");
    os << "test\n";

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
    (*(::spacefunc::Main *)&iobj).basePubFunc (); // correct
    ((::spacefunc::Main *)&iobj)->basePubFunc (); // correct

    goto label0;
}
