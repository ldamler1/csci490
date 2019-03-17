#ifndef RECURSIONLIST_H
#define RECURSIONLIST_H

class Node {
        friend class List;
        int data;
        Node* next;
    public:
        Node(int& d, Node* n = NULL) { data = d; next = n; }
};

class List {
    public:
        List() { root = NULL; };
        int recursiveLength();
        void print();
        void print_reversely();
        void insert(int d); // at end

    private:
        Node* root;
        int recursiveLength(Node* curr);
        void print(Node* curr);
        void print_reversely(Node* curr);
        void insert(Node*& curr, int d);
};

#endif

