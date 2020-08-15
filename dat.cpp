#include <iostream>
class Paccount;
void printx (const Paccount& instance);


class Paccount {
    private:
        std::string first_name;
        std::string last_name;
        int account_num;
    
    public:
        Paccount ( std::string f_name , std::string l_name = "" , int a_num = 0  );     
        std::string nm () const {
            return first_name;
        }
        

};

Paccount::Paccount (std::string f_name , std::string l_name, int a_num  ) :
            first_name(f_name) ,
            last_name(l_name)  ,
            account_num(a_num) {
                std::cout << "Object with name: " << first_name << std::endl;
            }

void printx ( const Paccount& instance ) {
    std::cout << "The name of this account holder is:" << instance.nm() << std::endl;
}

int main (  void )  {
    auto x = Paccount ("Sid","P." , 110025);
    auto y = Paccount ("Zack");
    printx(x);
    printx(y);
    return 0;
}