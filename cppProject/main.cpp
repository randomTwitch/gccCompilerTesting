// #include "NotMySpace_Main_theReUnion.hh"
#include "spacefunc.hh"

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
    tC.func0 ();
    *obj.tfunc<int*,0,3> () = 50; // changing the static memeber variable //
    std::cout << "Static Member Value: " << *obj.tfunc<int *, 0, 3> () << endl;
    // const getter setter function reading const member
    const SpaceFunc::Main constObj = *new SpaceFunc::Main ();
    // if this const object returns a reference type
    constObj.func (); // *this is a const pointer cannot assign to member variables [this* const]
     // constObj.func(); // const object cannot use getter function of non const type to access const members


    // testing explicit constructor //
    // without declaring it explicit the call would be ambiguous //
    ::spacefunc::SpaceFunc sfObj = *new ::spacefunc::SpaceFunc (10);
    ::spacefunc::SpaceFunc sfObj1 = *new ::spacefunc::SpaceFunc (20);
    sfObj1 = sfObj;

    goto label0;
}
