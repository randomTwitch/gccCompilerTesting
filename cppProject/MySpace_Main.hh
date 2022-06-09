#include "main.h"
#include <iostream>
#include "array"
using namespace std;

namespace MySpace
{
class Main
{
public:
#ifdef notMyMac
  int a{ myMac }, b, c;
#elif myMac
  int a, b, c;
#else
  int a, b, c;
#endif
  void MyFunc (int a)
  {
    if (a != 0)
      {
        std::cout << "Hello, World! a\n";
        switch (a)
          {
            // std::cout << "this line wont exe" << std::endl;
          label1:
            std::cout << "I am label1" << std::endl;
          case 0:
            {
              cin >> a;
              goto label0;
              break;
            }
          label0:
            std::cout << "I am label0" << std::endl;
          case 1:
            {
              cin >> a;
              goto label1;
              break;
            }
          default:
            {
              break;
            }
          }

      }
    else if (b != 0)
      {
        std::cout << "Hello, World! b\n";
      }
    else if (c == 0)
      {
#ifdef myMac
        std::cout << "Hello, World! c\n" << __TIMESTAMP__ << std::endl;
        VariadicMacros ("@Line#", "Hello, World! c\n");
        LostAndFoundBaggageClaim ("Hello: ");

        int array[((2 < 1) ? ((1 < 0) ? ((0 < 0) ? -1 : 3) : 2) : 1)];
        // either give an array initial size or
        // initialize array with elements or
        // on the right hand of the equal you cant skip 0 with empty array
        array[0] = *new int[0]{}; // its true anonymous array with 0 size
        std::cout << array[0] << std::endl;
        // this is an array with no initializer list or size
        int array1[]{};
        int array2[] = {}; // same above
        int array3[0];     // no initilizer or inilitializing list
        // this appends a null character at the end
        // you can pass "array4" to cout and the \o at the end terminates
        // its size is the size of all characters in the string + \o
        // name of the Array is the pointer to first member
        char array4[]{ "This is an array" }; // Array initializer
        // no need for new operator
        // must be Array initializer or string literal
        char array5[] = "This is a string literal";
        // error
        // char array5[] = *new char[]{"this is a string"};
        int array6[][2] = { { 0, 1 }, { 1, 2 }, { 2, 3 } };
        char array7[][3] = { "ab", "de", "ij", "lm" };
        // testing auto with imported array module with C++20 range for loop
        // std::array<double, 4> array8 = *new std::array<double, 4> ();
        // array8 = { 0, 1, 2, 3 };
        // only allowed in initialization expression
        for (std::array<double, 4> array = *new std::array<double, 4> ();
             auto x : a++, ++b, ++c, array)
          {
            std::cout << a << b << c << x << '\n';
          }
        // testing containers from <array>
        std::array<double, 4> array8 = *new std::array<double, 4> ();
        array8 = { 0, 1, 2, 3 }; array8[0] = 0;
        array8[0];
        double *a = &array8[0]; // can be auto
                                // this statement wouldve been possible if
        // a=array8;            // it were not a container type
        // defining new container type from <array> to test
        // pointer assignments and dereferencing to array8 container
        std::array<double, 4> array9 = *new std::array<double, 4> ();
        array8 = array9; // has to be strictly double and size
        // name of the container is pointer reference to its first object
        std::array<double, 4> &ptrConArray = array8;
        std::array<double, 4> ptrConArray0 = ptrConArray; // pointer to pointer
        std::array<double, 4> *ptrConArray1 = &ptrConArray;

        std::cin >> *a;
#endif
      }
  }
};
}
