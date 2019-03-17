#include <iostream>
using namespace std;

int loop_sum( int n ) {
    int sum = 0;
    while ( n > 0)
        sum += n--;
    return sum;
}

int recursive_sum( int n ) {
    if ( n <= 0 )
        return 0;
    return recursive_sum( n-1 ) + n;
}

int main() {
    cout << loop_sum( 10 ) << endl;
    cout << recursive_sum( 10 ) << endl;
    return 0;
}
