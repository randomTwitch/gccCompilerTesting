// #include "NotMySpace_Main_theReUnion.hh"
#include "SpacePtr_Main.h"

int main ()
{
  /* This code needs "NotMySpace_Main_theReUnion.hh"
    // auto list = { 1, 3, 4 };

    // ::NotMySpace::Main mainObj = *new ::NotMySpace::Main ();

    // ::MySpace::Main mCo = *new ::MySpace::Main ();
    // mCo.a = 0;
    // mCo.MyFunc (0);
    */
  int a = static_cast<int> (0);
  thread_local auto ai = 0;

  /* This code requires "SpacePtr_Main.h" */
  ::SpacePtr::Main sptrMobj = *new ::SpacePtr::Main (); // anon obj initi
  sptrMobj.func(); // pointers dot ops Objects arrow -> ops

  return 0;
}
