#include <iostream>
using namespace std;

int fn4(int);			// Forward declaration

int fn5(int n){
	if ( n <= 0 ) 
            return 0;
	n *= 2;			// Multiply the value by two
	return fn4( n );
}
int fn4(int n){
	if ( n > 100) 
            return n;
	cout << n << ' ';
	n -= 1;			// Decrement the value by 1
	return fn5(n);
}

int main() {

    int result = fn5( 5 );
    cout << endl;
    cout << "Final result: " << result << endl;

    return 0;
}
