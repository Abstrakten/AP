#include <iostream>

//Here is the function with call-by-value parameters: 
double max(double a, double b){
    return a < b ? b : a;
}

//Make a version with C-style call by reference parameters - pointers passed by value.
double max(double* a, double* b){
    std::cout << "! ";
    return max(*a, *b);
}

//Make a version with call by C++ references. Also, return a double&.
double max()

int main(){

    double a = 1;
    double b = 2;

    double *ap = &a;
    double *bp = &a;

    std::cout << max(a,b) << std::endl;
    std::cout << max(ap,bp) << std::endl;
    std::cout << max(*ap,*bp) << std::endl;



}