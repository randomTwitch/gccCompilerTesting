#include <iostream>
using namespace std;

int main (int argc, char* argv[], char* envp[])
{
  cout << "Hello World " << argc << " !" << argv[1] << " ! " << envp[0] << " ! " << endl;
  
  //char ch = 'A';
  //char *a = &ch;
  char *a;
  cout << &a << endl;
  cin >> a;
  return 0;
}