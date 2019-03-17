#include <iostream>
#include <cstdlib>
#include "recursionList.h"
using namespace std;


int List::recursiveLength() {
    return recursiveLength(root);
}

void List::insert(int d) {
    insert(root, d);
}

void List::print() {
    print(root);
}

void List::print_reversely() {
    print_reversely(root);
}

int List::recursiveLength(Node* curr) {
    if ( curr == NULL )
       return 0;
    int len = recursiveLength( curr->next );
    return 1+len;
}

void List::print(Node* curr) {
    if ( curr != NULL ) {
        cout << curr->data << " ";
        print(curr->next);
    }
}

void List::print_reversely(Node* curr) {
    if ( curr != NULL ) {
        print_reversely( curr->next );
        cout << curr->data << " ";
    }
}

void List::insert(Node*& curr, int d) {
    if ( curr == NULL )
       curr = new Node(d);
    else
       insert(curr->next, d);
}

int main() {
    List myList;
    int i;
    for (i=0; i<10; i++)
       myList.insert(i);

    myList.print();
    cout << endl;
    myList.print_reversely();
    cout << endl;
    cout << "Length of the list: " << myList.recursiveLength() << endl;
    return 0;
}


