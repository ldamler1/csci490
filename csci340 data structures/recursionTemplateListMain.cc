#include <iostream>
#include "recursionTemplateList.h"
using namespace std;

int main() {
    List<int> myList;
    int i;
    for (i=0; i<10; i++)
       myList.insert(i);

    myList.print();
    cout << endl;
    myList.print_reversely();
    cout << endl;
    cout << "Length of the list: " << myList.recursiveLength() << endl;

    List<string> strList;
    strList.insert("One");
    strList.insert("Two");
    strList.insert("Three");
    strList.insert("Four");
    strList.print();
    cout << endl;
    strList.print_reversely();
    cout << endl;
    cout << "Length of the list: " << strList.recursiveLength() << endl;

    return 0;
}

