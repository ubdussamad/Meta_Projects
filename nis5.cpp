#include <iostream>
#define LOG std::cout <<
#define X std::endl;
#include <termios.h>




int main()
{
    struct Person
{
    char name[50];
    int age;
    float salary;
};

    Person p1;

    p1.age += 2; 
    
    std::cout << "Enter Full name: ";
    std::cin.get(p1.name, 50);
    std::cout << "Enter age: ";
    std::cin >> p1.age;
    std::cout << "Enter salary: ";
    std::cin >> p1.salary;
    std::cout << "\nDisplaying Information." << std::endl;
    std::cout << "Name: " << p1.name << std::endl;
    std::cout <<"Age: " << p1.age << std::endl;
    std::cout << "Salary: " << p1.salary;

    return 0;
}