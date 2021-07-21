#include <iostream>
#include <vector>

using namespace std;

typedef void (*func_ptr_t) ();

void foo () {
  static int count = 0;
  count++;
  cout << "The number you've entred is: " << count << endl;
}

void wrapper( func_ptr_t func ) {
  cout << "The function is now wrapper arounf by mee." << endl;
  func ();
}


int main (  void )  {
  //So we're just calling it from here.

  foo ();

  func_ptr_t fancy_new_name = foo;

  fancy_new_name();

  wrapper(foo);
  
  return(0);
}


