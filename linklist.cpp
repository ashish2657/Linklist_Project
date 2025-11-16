#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;
class SinglyNode {
public:
    int data;
    SinglyNode* next;
    SinglyNode(int d) {
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList {
private:
    SinglyNode* head;

public:
    SinglyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        SinglyNode* newNode = new SinglyNode(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at beginning.\n";
    }

    void deleteNode() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        int value;
        cout << "Enter data to delete: ";
        cin >> value;

        SinglyNode* temp = head;
        SinglyNode* prev = NULL;

        while (temp != NULL) {
            if (temp->data == value) {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Node deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Data not found.\n";
    }

    void traversal() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        SinglyNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int d) {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    DoublyNode* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtBeginning() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        DoublyNode* newNode = new DoublyNode(value);
        if (head != NULL)
            head->prev = newNode;
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at beginning.\n";
    }

    void deleteNode() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        int value;
        cout << "Enter data to delete: ";
        cin >> value;

        DoublyNode* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                else
                    head = temp->next;

                if (temp->next != NULL)
                    temp->next->prev = temp->prev;

                delete temp;
                cout << "Node deleted.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Data not found.\n";
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        DoublyNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList sList;
    DoublyLinkedList dList;
    char choice, listType;

    do {
        system("cls");
        cout << "Linked List Program\n";
        cout << "Choose List Type:\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "Choice: ";
        listType = getch();

        system("cls");
        switch (listType) {
        case '1':
            cout << "Singly Linked List Menu:\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Delete Node\n";
            cout << "3. traversal List\n";
            cout << "Enter option: ";
            choice = getch();
            switch (choice) {
            case '1': sList.insertAtBeginning(); break;
            case '2': sList.deleteNode(); break;
            case '3': sList.traversal(); break;
            default: cout << "\nInvalid option.\n"; break;
            }
            break;

        case '2':
            cout << "Doubly Linked List Menu:\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Delete Node\n";
            cout << "3. traversal list\n";
            cout << "Enter option: ";
            choice = getch();
            switch (choice) {
            case '1': dList.insertAtBeginning(); break;
            case '2': dList.deleteNode(); break;
            case '3': dList.display(); break;
            default: cout << "\nInvalid option.\n"; break;
            }
            break;

        default:
            cout << "\nInvalid list type selected.\n";
            break;
        }

        cout << "\n\nPress 1 to continue, any other key to exit: ";
        choice = getch();

    } while (choice == '1');

    return 0;
}

