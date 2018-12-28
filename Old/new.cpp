#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal {
private:
  int height;
  int weight;
  string name;
  static int herd_size;
public:
  int geth(){ return(height);}
  int getwt() { return(weight );}
  string getname() { return(name);}
  void seth ( int h ) { height = h; }
  void setwt ( int wt ) { weight = wt; }
  void setall( int , int , string );
  void setname ( string n ) { name = n; }
  Animal(int, int, string );
  ~Animal();
  Animal();
  static int getnum () { return herd_size;}
  void toString();
};

int Animal::herd_size = 0;
void Animal::setall(int height, int weight , string name) {
  this -> height = height;
  this -> weight = weight;
  this -> name = name;
  Animal::herd_size++;
}


Animal::Animal(int height, int weight , string name) {
  this -> height = height;
  this -> weight = weight;
  this -> height = height;
  Animal::herd_size++;
}

Animal::~Animal() {
  cout << "Animal:" << this->name << " Destroyed!" << endl;
}

Animal::Animal() {
  Animal::herd_size++;
}

void Animal::toString() {
  cout << this->name << " is " << this->height << "cms tall." << endl;
}

int main ( )  {
  Animal fred;
  fred.seth(50);
  fred.setwt(100);
  fred.setname("Fred");

  cout << "The animal's name is: " << fred.getname() <<  " And he is : " <<
    fred.geth() << "cms tall and " << fred.getwt() << "kg fat." << endl;
  return(0);
}
  
