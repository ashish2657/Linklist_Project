#include<iostream>
using namespace std;

class NODE {
public:
    int DATA;
    NODE* NEXT;
    NODE(int d) {
        DATA = d;
        NEXT = NULL;
    }
};

class LinkList {
    NODE* head;

public:
    LinkList() {
        head = NULL;
    }

    void insertAtBeginning() {
        int data;
        cout << "\nEnter node data: ";
        cin >> data;
        NODE* newNode = new NODE(data);
        newNode->NEXT = head;
        head = newNode;
        cout << "\nNode inserted at beginning.\n";
    }

    void insertAtEnd() {
        int data;
        cout << "\nEnter node data: ";
        cin >> data;
        NODE* newNode = new NODE(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        NODE* temp = head;
        while (temp->NEXT != NULL) {
            temp = temp->NEXT;
        }
        temp->NEXT = newNode;
        cout << "\nNode inserted at end.\n";
    }

    void traverse() {
        if (head == NULL) {
            cout << "\nLinked List is empty.\n";
            return;
        }
        NODE* temp = head;
        cout << "\nLinked List: ";
        while (temp != NULL) {
            cout << temp->DATA << " -> ";
            temp = temp->NEXT;
        }
        cout << "NULL\n";
    }

    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "\nList is empty.\n";
            return;
        }
        NODE* temp = head;
        head = head->NEXT;
        delete temp;
        cout << "\nNode deleted from beginning.\n";
    }

    void deleteAtEnd() {
        if (head == NULL) {
            cout << "\nList is empty.\n";
            return;
        }
        if (head->NEXT == NULL) {
            delete head;
            head = NULL;
            cout << "\nLast node deleted.\n";
            return;
        }
        NODE* temp = head;
        while (temp->NEXT->NEXT != NULL) {
            temp = temp->NEXT;
        }
        delete temp->NEXT;
        temp->NEXT = NULL;
        cout << "\nNode deleted from end.\n";
    }
};

int main() {
    LinkList l;
    char choice;

    do {
        cout << "\n\t --- Linked List Menu ---\n\n";
        cout << "1. Insert at Beginning \t2. Insert at End\n\n";
        cout << "3. Delete at Beginning \t4. Delete at End\n\n";
        cout << "5. Traverse \t\t6. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            l.insertAtBeginning();
            break;
        case '2':
            l.insertAtEnd();
            break;
        case '3':
            l.deleteAtBeginning();
            break;
        case '4':
            l.deleteAtEnd();
            break;
        case '5':
            l.traverse();
            break;
        case '6':
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice.\n";
        }

    } while (choice != '6');

    return 0;
}

