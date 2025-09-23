#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
};

node *start, *newptr, *ptr, *rear;

node *create_new_node(int);
void insert_node(node *);
void traverseForward(node *);
void traverseBackward(node *);

int main() {
    start = rear = NULL;
    int c;
    char choice = 'y';

    // Membuat node-node baru
    while (choice == 'y' || choice == 'Y') {
        cout << "Nilai baru = ";
        cin >> c;
        cout << "Membuat node baru" << endl;

        newptr = create_new_node(c);
        if (newptr != NULL) {
            cout << "Berhasil membuat node baru" << endl;
        } else {
            cout << "Node baru tidak dapat dibuat" << endl;
            exit(1);
        }

        insert_node(newptr);
        cout << "Node dimasukkan ke list" << endl;

        cout << "Mau membuat node baru? (y/n): ";
        cin >> choice;
    }

    // Pilih arah traversal
    int direction;
    cout << "1. Maju" << endl;
    cout << "2. Mundur" << endl;
    cout << "Arah transversal yang mana? ";
    cin >> direction;

    switch (direction) {
        case 1:
            cout << "Traversal maju: ";
            traverseForward(start);
            break;
        case 2:
            cout << "Traversal mundur: ";
            traverseBackward(rear);
            break;
    }

    return 0;
}

node *create_new_node(int n) {
    ptr = new node;
    ptr->data = n;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

void insert_node(node *np) {
    if (start == NULL) {
        start = rear = np;
    } else {
        rear->next = np;
        np->prev = rear;
        rear = np;
    }
}

void traverseForward(node *head) {
    node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void traverseBackward(node *tail) {
    node *current = tail;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}
