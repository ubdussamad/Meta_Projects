
#include <iostream>


class entity {
private:
  char *  name;
  char *  game;
  char *  fame;

public:
  char * get_name () {
    return name;
  }
  void set_name (char * nm )  {
    name = nm;
  }
};



int main ( )  {
  entity e1;
  char nameX[] = "francis\0";
  std::cout << e1.get_name() << std::endl;
  return 0;
}
  
