//
//  LinkedList.h
//  Assignment4
//
//  Created by kareem ahmed shawky on 4/7/23.
//

#ifndef LinkedList_h
#define LinkedList_h
#include <vector>
using namespace std;

class LinkedList
{
    struct node
    {
        int item;
        int count;
        node* next;
    };
    node* head;
public:
    LinkedList()
    {
        head = NULL;
    }
    void InsNode(int num)
    {
        if (head == NULL)
        {
            head = new node();
            head->item = num;
            head->count = 1;
            head->next = NULL;
        }
        else
        {
            node* newNode = new node();
            newNode->item = num;
            newNode->count = 1;
            newNode->next = head;
            head = newNode;
        }
    }
    void RemoveNode(int n)
    {
        if (head == NULL)
        {
            cout << "Linked List is empty" << endl;
            return;
        }
        if (head->item == n)
        {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        node* current = head;
        while (current->next != NULL && current->next->item != n)
        {
            current = current->next;
        }
        if (current->next == NULL)
        {
            cout << "Value is not in the linked list";
            return;
        }
        node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "The list is empty" << endl;
            return;
        }
        node* current = head;
        while (current != NULL)
        {
            cout << current->item << " ";
            current = current->next;
        }
        cout << endl;
    }
     void createList(vector<int> v)
    {
        node* current = head;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            int num = v[i];
            if (head == NULL)
            {
                head = new node();
                head->item = num;
                head->count = 1;
                head->next = NULL;
            }
            else
            {
                node* current = head;
                while (current != NULL && current->item != num)
                {
                    current = current->next;
                }
            }
            if (current == NULL)
            {
                node* newNode = new node();
                newNode->item = num;
                newNode->count = 1;
                newNode->next = head;
                head = newNode;
            }
            else
            {
                current->count++;
            }
        }
    }

    int sumList()
    {
        int sum = 0;
        node* current = head;
        while (current != NULL)
        {
            sum += current->item * current->count;
            current = current->next;
        }
        return sum;
    }
};

#endif
