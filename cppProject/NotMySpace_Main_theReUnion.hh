#include "MySpace_Main.hh"
#include <vector>
//#include <tr1/array>

#define myMac ((3 - (2 + 4)) - (0 / (2 + 3))) * 3

namespace NotMySpace
{
class Main
{
public:
  int a, b, c;
  void func ()
  {
    int a = (0xa.0p+0 - 0xb.0p-0) + 0x0c.0p-0; // hexa
    int b = 010;                               // octal
    int c = 0b0100 ^ 0b0010;                   // binary
  };
};
union theReUnion
{
  theReUnion();
  public:private:protected:
  enum enu{a=0,b,c};
  enum class e : char {a=0,b=-enu::a,c='a'};
  typedef e EnU;
  using e = EnU;
  // the tr1 folder
  // std::tr1::array<int, 9> x = *new std::tr1::array<int, 9> ();

  // standard template library is not documented and shows no hints
  // the container library is documented and showed hints
  // now this works because it skips the first 2 args, the comma operator rule
  // Constructor takes 3 args in total overloaded with 2 args constructor
  // templated and the anonymous object's pointer is passed
  // cant debug the code to find out if vector ops create anonymous
  // objects and waste space or pass by reference which also waste space&time
  // stack and registers
  // which leads to the question if containers are really optimized
  // containers are only useful with for(;:) loop
  std::vector<double> conV = *new std::vector<double> ({ 0, 1 });


  ~theReUnion ();
};
}
