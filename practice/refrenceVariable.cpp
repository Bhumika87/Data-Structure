#include <iostream>
using namespace std;
void update1(int n)
{
    // without refrence variable(pass by value) harbar new copy create hogi or new memory allocate hogi hartime
    n++;
}
void update2(int &n)
{
    // with refrence variable no new copy create and point to the same memory allocation with the diffrent name
    // memory yhi use kre but usko alg name dedo
    n++;
}
int main()
{
    int n = 20;
    cout << "Before update Without refrence variable" << n << endl;
    update1(n);
    cout << "After update value didn't change " << n << endl;

    cout << "using refrence variable" << endl;

    int r = 30;
    cout << "Before update With refrence variable" << r << endl;
    update2(r);
    cout << "After update value change " << r;
    return 0;
}