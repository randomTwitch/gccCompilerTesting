#include <iostream>
#include <string>
#include <regex>
#include <memory> // modules for non standard library pointers
#include <iosfwd> // the forwards declarations the standard cpp
#include <c++/bitset>
using namespace std;

namespace SpacePtr {
class Main
{
  int a;

public:
  Main () { return; }
  Main (int a)
  {
    a = 1;
    (*this).a = a;
    std::cout << "Constructor called" << endl;
    return;
  }
  static int func0(){ return 0; }
  void func ()
  {
    // nullPtr object in non assigning initialization
    // if you remove the nullPtr it would assign the default value nullPtr still
    void *ptrNull{ nullptr }; // can be casted to any type saving space

    // technically following the comma operator rule only the last one should be
    // null rest volatile pointer
    void *ptr1, *ptr2, *ptr3 = nullptr;
    // not allowing c style int* casting or dynamic casting
    // int a=0;int *(a); // error redifinition of a with different type
    int *b = new int{};
    // first * declates the pointer to int* type second * dereferences it
    int **a = &b; // what ?
    int ***x = &a;
    int ****y = &x;
    int *****z = &y; // now that makes sense
    auto g = z; // i dont even no
    int *&c = b;
    // d is integer type
    int &d0 = *new int{};
    // cant move past to &&&
    int &&d= 10; // dereferencing the pointer d whose address of pointer equals 10
    // void* e = &&b; // use of undeclared label b address of pointer's address
    int *&&f = &*b;
    // int &&&g= *d; // cant move on
    // if you dont no how to flip bits and use * for division
    // miltiplication operator has to be a deep joke
    // the dot produts and package dependences
    // last but not the least function pointers
    // and array of function pointers with initializers { --- }
    int (*ptrFunc) (void);
    ptrFunc = this->func0; ptrFunc=&func0;
    int (*ptrArrFunc[1]) (void){ this->func0 };
    ptrArrFunc[0] = *new (int (*) (void)); // anonymous function no body

    char32_t *h0, h1 = u'\u0219';
    const char *h2 = u8"\U0001F607 is O:-)";
    const wchar_t *h3 = L"zyxw";
    const char16_t *h4 = uR"(An unescaped \ character)";
    const char* const h5 = R"xyz()")xyz";
    const char* const h6 {R"xyz()")xyz"};
    char const* const h8{}; // same as above
    char* const h7{}; // a pointer that is constant

    // using <string> containers
    string str = *new string(); str.clear();
    char ch = '!';
    /*
    // multibyte character wont go in have to stringfy it ie double quote
    cout << "\u0219" << endl;
    cout << "\U00000219" << endl;
    cout << u8"\U0001F607 is O:-)"<< endl;
    cout << L"zyxw" << endl;
    cout << R"(An unescaped \ character)" << endl; // raw strings
    */

    // Ordinary character literals of type char, // for example 'a'
// UTF-8 character literals of type char (char8_t in C++20), // for example u8'a'
    // Wide-character literals of type wchar_t, // for example L'a' UTF-16
    // character literals of type char16_t, // for example u'a'
    // UTF-32 character literals of type char32_t, // for example U'a'

    char u1 = 'A';          // 'A'
    char u2 = '\101';       // octal, 'A'
    char u3 = '\x41';       // hexadecimal, 'A'
    char u4 = '\u0041';     // \u UCN 'A'
    char u5 = '\U00000041'; // \U UCN 'A'

    // POINTER ARITHMETIC
    // name of array is pointer to first element
    // creates an anonymous array dereferences it to h10
    // ie address if the first element of the array
    int& h10 = *new int[3]{9,8,7};
    int* h{&h10}; int& h9= *h; h9++; ++h10; //
    std::cout << h10 << endl; // yep 11 it is
    int *h11 = new int[3]{ 6, 5, 4 }; h11[0]=0; *h11=0; h11++; h11 = &h11[0]; *h11=*&*&*&h11[0]; int** xx= &h11; int* xxx=h11; // &&h11;

    int y0{ 9 };    // int y0 = 9;
    int *y1{ &y0 }; // int*y1(&y0);
    int* y2{ new int{0} }; // int *y2{new int}; // int *y2{new int()}; // int* y2= new int; // int* y2= new int(); // int* y2= new int{1};
    delete y2; y2 = nullptr;
    delete[] h11; h11 = nullptr;

    // new operator allocates on the heap which means [new array] they wont be contiguous
    // use single dimensional array and map row next to column - in classes
    /* creating an array of pointer to double types
auto carrots{ new double[rows][4] {} };
    double** carrots{ new double*[rows] {} };
    for (size_t i = 0; i < rows; ++i)
    carrots[i] = new double[columns] {};
...
for (size_t i = 0; i < rows; ++i)
delete[] carrots[i];
delete[] carrots;
*/
    // this->func(); (*this).func(); // the clumsy looking

    // #include <bitset>
    // bitset<3> bitset{1111111111101010101}; std::cout<<bitset.to_string()<<endl; // 101

    // testing <memory> module // new creates memory on the heap unique_shared_weak_ptr uses them //
    unique_ptr<char> &ptrUni = *new unique_ptr<char> ();
    // none of the statements in comments 3 in total works //
    // unique_ptr<char> ptrUni1 = new char('c'); // unique_ptr<char>& ptrUni1 = *new char('c');
    // malloc'ed the character inside braces // standard library crap // template'ed the standard // malloc might be a pre processor macro
    unique_ptr<char> ptrUni0{ new char{ 'c' } }; // unique_ptr<char>& ptrUni1 = *new char(); // unique_ptr<char>& ptrUni1 = *new char{'c'};
    char heapChar = 's'; // new is called implicitly and assigned results
    char nonHeapChar{ 's' }; // this ones on the stack
    char chary = *new char ('s'); // the unique sir pointer is taketh address to my char set in the line beloweth
    unique_ptr<char> ptrUni1{&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&chary}; // works with all 3 chars defined above
    // had to explicitly convert the unique sir to address type
    unique_ptr<char>& ptrUni2 = *new unique_ptr<char>(&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&chary);
    // making a uniquePtr of pointer to characters // after this arrays must be easy to follow array of arrays uniquePtr[s]
    char *ptrChary = &chary;
    unique_ptr<char *> ptrUni3{ &ptrChary };
    unique_ptr<char *> &ptrUni4 = *new unique_ptr<char *> (&ptrChary);

    std::unique_ptr<double> pdata { std::make_unique<double>(999.0) }; // what ever this is might as well

    // unique pointers to arrays
    std::unique_ptr<char[6]>& ptrUniArr = *new std::unique_ptr<char[6]>();

    // ptrUni1.get() gives you the address of the pointer
    std::cout << *ptrUni1.get () << '\t' << chary << endl;

    // creating a pointer on heap instead of stack
    int *ptrInt = *new int *(0);

    // releasing the Unique Pointer, would give the pointer to char i passed before
    //ptrUni1.reset (new char{ 'q' }); // smart pointer reset
    char *chary0 = ptrUni1.release (); // smart pointers release
    // changing chary0 will change chary
    *chary0 = *new char ('r'); // this will change the original "chary" value
    chary0 = new char ('q'); // this will not change the "chary" value
    // should be ashowing me the address but its showing the value
    std::cout << chary0 << endl; // q
    std::cout << chary << endl;  // s // smart pointer changed nothing
    delete chary0; // safely deleting the raw pointer released by the smart pointer "unique_ptr" = nullPtr

    int dd = 0;
    int &rdd = dd;
    int *pdd = &dd;
    int *prdd = &rdd;

    // using <string>
    string s = *new string ("s", 0, 1);
    string s0 = *new string ("str") + *new string ("str") + *new string ("str") + (" " + s);
    s += *new string ("str") + 'x' + *new string ("str");
    s += 'x' + *new string ("str") + 'x' + (" " + s) + 'x' + std::to_string (0);

    string text;
    std::getline (std::cin, text, '#');
    std::cout<<text<<endl;
    char t = text[0]; // plain char arrays cannot be stored in containers



    // Testing the standard library objects cout and its predecessers
    // std::ostream* OS = &std::cout; OS->put('S'); OS->write("Hello", 7);
    // std::basic_ostream<char, std::char_traits<char>>* bOS =  OS; bOS->write("YELLOW", 8);
    // std::ios::~ios_base(); //std::ios_base;

    // std::cout << c << endl;
    // std::cout << &b << endl;
    // std::cout << sizeof() <<  endl;
    // std::cout << static_cast<int*>(ptr1) <<  endl;
  }
};
}
