#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* createNode(int n) {
    Node* p = new Node();
    p->data = n;
    p->next = nullptr;
    return p;
}

void insertEnd(Node*& head, int n) {
    Node* newNode = createNode(n);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* evenThenOddLinkedList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data % 2 == 0) {
            if (evenHead == nullptr) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == nullptr) {
                oddHead = curr;
                oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = curr->next;
    }

    if (evenHead == nullptr) {
        return oddHead;
    } else {
        evenTail->next = oddHead;
        if (oddTail != nullptr) {
            oddTail->next = nullptr;
        }
        return evenHead;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    Node* head = nullptr;
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        std::cin >> val;
        insertEnd(head, val);
    }

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    head = evenThenOddLinkedList(head);

    std::cout << "Modified Linked List: ";
    printLinkedList(head);

    return 0;
}
