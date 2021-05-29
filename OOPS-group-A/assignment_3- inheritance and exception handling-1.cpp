/* Types of Inheritance
In C++, we have 5 different types of Inheritance. Namely,
1. Single Inheritance
2. Multiple Inheritance
3. Hierarchical Inheritance
4. Multilevel Inheritance
5. Hybrid Inheritance
*/



// Single Inheritence
#include <iostream>
using namespace std; 

class Vehicle
{
public:
 Vehicle()
{
cout<< "This is a Vehicle"<<endl;
}
};
class FourWheeler { 
public:
FourWheeler()
{
cout<< "This is a 4 wheeler Vehicle"<<endl;
}
};
class Car: public Vehicle,
 public FourWheeler
{
 };
 int main()
 {
 Car obj;return 0;
 }
