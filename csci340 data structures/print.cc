#include <iostream>
using namespace std;

void recursive_print(int n) {
    if ( n <= 0 )
        return;
    recursive_print( n-1 );
    cout << n << ' ';
}

void reverse_print(int n) {
    if ( n <= 0 )
        return;
    cout << n << ' ';
    reverse_print( n-1 );
}

int main() {
    recursive_print( 10 );
    cout << endl;
    reverse_print( 10 );
    cout << endl;
}
