#include <iostream>
using namespace std;

int f(int n) {
    if ( n==0 || n==1 )
       return 1;
    return f( n-1 ) + f( n-2 );
}

int main() {
    for (int i=0; i<20; i++)
        cout << f(i) << endl;
    return 0;
}
