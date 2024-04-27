#include <iostream>
using namespace std;

// Define the Node structure with data, next, and prev pointers
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Constructor for Node
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Function to append a new node to the end of the list
void append(Node** head, int value) {
    Node* newNode = new Node(value);
    if (*head == nullptr) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next!= nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find the last node in the list
Node* lastNode(Node* root) {
    while (root && root->next) {
        root = root->next;
    }
    return root;
}

// Function to partition the list around a pivot value
Node* partition(Node* l, Node* h) {
    int x = h->data;
    Node* i = l->prev;

    for (Node* j = l; j!= h; j = j->next) {
        if (j->data <= x) {
            i = (i == nullptr)? l : i->next;
            swap(i->data, j->data);
        }
    }
    i = (i == nullptr)? l : i->next;
    swap(i->data, h->data);
    return i;
}

// Function to perform quicksort on the list
void quickSort(Node* l, Node* h) {
    if (h!= nullptr && l!= h && l!= h->next) {
        Node* p = partition(l, h);
        quickSort(l, p->prev);
        quickSort(p->next, h);
    }
}

// Function to print the list
void printList(Node* node) {
    while (node!= nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    append(&head, 30);
    append(&head, 3);
    append(&head, 4);
    append(&head, 20);
    append(&head, 5);

    cout << "Linked List before sorting: ";
    printList(head);

    Node* last = lastNode(head);
    quickSort(head, last);

    cout << "Linked List after sorting: ";
    printList(head);

    return 0;
}