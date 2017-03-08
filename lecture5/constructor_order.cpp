/*
 * inheritance1.cpp
 *
 *      Author: Kurt Nørmark / Simonas Saltenis
 *
 *      Illustrates constructors and destructors in a hierarchy: the order of their calls, as well as implicit call of default constructors
 */

#include <iostream>
#include <string>

using namespace std;

class Base1
{
    int i;
    
    public:
	Base1(int a): i{a}
 	{ cout << "Base1 constructor" << endl; };
 
	~Base1()
    { cout << "Base1 destructor" << endl;  };
};

class Base2
{
    bool j;
    
    public:
	Base2(): j{false}     // a default constructor
	{ cout << "Base2 default constructor" << endl; };

	Base2(bool b): j(b)
	{ cout << "Base2 constructor" << endl; };

	~Base2()
	{ cout << "Base2 destructor" << endl;  };

};
 
class Derived: public Base1, public Base2
{
    double d;
    public:
 
	Derived(int i, double b):
		d{b},
        Base2(),
		Base1{i}
	{ cout << "Derived constructor" << endl; };
 
	~Derived()
	{ cout << "Derived destructor" << endl;  };
};
 
int main()
{
	Derived d1{1, 1.0};
    cout << "end" << endl;
}