/*
 * virtual.cpp
 *
 *      Author: Kurt Nørmark / Simonas Saltenis
 *
 *      Illustrates run-time polymorphism in C++: virtual member functions
 */
 
// Class B inherits from A. We activate virtual (vf) and non-virtual (f) functions
// on a parameter passed by value, by a pointer, and by reference.

#include <iostream>

using namespace std;

class A
{
    double a;
    
    public:
    virtual void vf(double d)
    { cout << "virtual vf in A" << endl; };
    
    void f(double d)
    { cout << "f in A" << endl; };
};

class B : public A
{
    double b;
 
    public:
    void vf(double d) override
    { cout << "virtual vf in B" << endl; }

    void f(double d)
    { cout << "f in B" << endl; }
};

void f1(A a)
{
    a.vf(1.0);       // vf in A. Why?  Because a is sliced during parameter passing.
    a.f(2.0);        // f in A - static binding.
    cout << endl;
}

void f2(A *ap)
{
    ap->vf(3.0);     // vf in B.
    ap->A::vf(3.0);  // vf in A  - enforce call of vf from A, with use of the scope resolution operator ::
    ap->f(4.0);      // f in A - static binding.

    //ap->B::f(4.0);                    // error: 'B' is not a base of 'A'
    dynamic_cast<B*>(ap)->f(4.0);     // f in B - the programmer guarantee that ap is of type B*.

    cout << endl;
}

void f3(A &ar)
{
  ar.vf(5.0);      // vf in B
  ar.A::vf(3.0);   // vf in A
  ar.f(6.0);       // f in A
                                    // Same as for pointers:
  //ar.B::f(4.0);                     // error: 'B' is not a base of 'A'
  dynamic_cast<B&>(ar).f(4.0);      // f in B.

  cout << endl;
}

int main()
{
  B  b1;
             // We pass b1 to f1, f2 and f3
  f1(b1);    //    ... by value             (a copy of b1 is passed)
  f2(&b1);   //    ... a pointer by value   (a pointer to b1 is passed)
  f3(b1);    //    ... by C++ reference     (b1 as such is passed)
}
