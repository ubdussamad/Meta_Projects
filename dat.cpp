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
            return this->first_name;
        }

        int ac ( ) const {
            return this->account_num;
        }

        Paccount operator+ ( const Paccount& X ) const {
            std::string x = this->nm() + X.nm();
            int acc = this->account_num + X.ac();
            // std::cout << "The new ac is: " << acc << std::endl;
            return  Paccount (x , "Joint" , acc );
        }

        // friend vointx (  const Paccount& instance)

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

void printac ( const Paccount& instance ) {
    std::cout << "The number of this account holder is:" << instance.ac() << std::endl;
}

int main (  void )  {
    auto x = Paccount ("Sid","P." , 25);
    auto y = Paccount ("Zack" , "Night" , 25 );
    printx(x);
    printx(y);

    Paccount z = (x + y);
    printx(z);
    printac(z);
    return 0;
}