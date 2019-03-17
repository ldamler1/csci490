#ifndef RECURSION_TEMPLATE_LIST_H
#define RECURSION_TEMPLATE_LIST_H
#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class Node {
        template<class U> friend class List;
        T data;
        Node<T>* next;
    public:
        Node(T& d, Node<T>* n = NULL) { data = d; next = n; }
};

template <class T>
class List {
    public:
	List() { root = NULL; };
        int recursiveLength();
        void print();
        void print_reversely();
        void insert(T d); // at end

    private:
	Node<T>* root;
        int recursiveLength(Node<T>* curr);
        void print(Node<T>* curr);
        void print_reversely(Node<T>* curr);
        void insert(Node<T>*& curr, T d);
};

template <class T>
int List<T>::recursiveLength() {
    return recursiveLength(root);
}

template <class T>
void List<T>::insert(T d) {
    insert(root, d);
}

template <class T>
void List<T>::print() {
    print(root);
}

template <class T>
void List<T>::print_reversely() {
    print_reversely(root);
}

template <class T>
int List<T>::recursiveLength(Node<T>* curr) {
    if ( curr == NULL )
       return 0;
    int len = recursiveLength( curr->next );
    return 1+len;
}

template <class T>
void List<T>::print(Node<T>* curr) {
    if ( curr != NULL ) {
        cout << curr->data << " ";
        print(curr->next);
    }
}

template <class T>
void List<T>::print_reversely(Node<T>* curr) {
    if ( curr != NULL ) {
        print_reversely( curr->next );
        cout << curr->data << " ";
    }
}

template <class T>
void List<T>::insert(Node<T>*& curr, T d) {
    if ( curr == NULL )
       curr = new Node<T>(d);
    else
       insert(curr->next, d);
}

#endif

