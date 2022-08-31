#include <iostream>
using namespace std;

// ************************************************************************
// * This program implements a singly linked list and its member functions
// * NOTE: Linked lists cant move backwords, only forwards.
// *    Can only start at the beginning of the list and traverse forward.
// *    unable to go straight into an index.
// ************************************************************************

class MyLinkedList
{
public:
    // ************************************************************************
    // * Definition of a singly linked list
    // * To create a singly linked liist, first define a node
    // *    the class will contain a sentinal node called head.
    // *    head will keep track of the first element and will also be used
    // *    to traverse the list.
    // * Node:  [val|next]-->nullptr
    // ************************************************************************
    struct Node
    {
        int val;
        Node * next;
        explicit Node(int x) : val(x), next(nullptr) {};
    };

    // The list will start empty with head equal null and size = 0
    MyLinkedList()
    {
        size = 0;
        head = nullptr;
    }

    // **********************************************************************
    // * Get the value of the ith node in the linked list.
    // * If the index is invalid, return -1
    // **********************************************************************
    int get(int index)
    {
        // If invalid index passed in return -1.
        if (index < 0 || index >= size) return -1;

        // count will keep track of the index we are currently looking at.
        int count = 0;

        // Create a temp node that will start from the beginning of the list.
        Node * curr = head;

        // Traverse the list using curr.
        // Once curr reaches nullptr, end of list is reached.
        while(curr != nullptr)
        {
            // Once count == index,
            // index has been found and return the val in that index
            if (count==index) return curr->val;

            // if index has not been found yet, keep traversing the list.
            curr = curr->next;
            count++;
        }
        return -1;
    }

    // **********************************************************************
    // * Add a node of value val before the first element of the linked list.
    // * After insertion, the new node will be the first node of the list.
    // **********************************************************************
    void addAtHead(int val)
    {
        // Initialize a new node temp with the value passed in.
        // temp = [val|next]
        Node * temp = new Node(val);

        // Link the temp node to the current head node
        temp->next = head;
        // Assign temp node to be the new head.
        head = temp;

        // Increment size.
        size++;
    }

    // **********************************************************************
    // * Append a node of value val as the last element of the list.
    // **********************************************************************
    void addAtTail(int val)
    {
        // If the list is empty, make the val passed in a new head node.
        if(head == nullptr)
        {
            head = new Node(val);
        }
        else
        {
            // 1. initialize temp to head inorder to traverse the entire list
            //      without moving the head node
            Node * temp = head;

            // 2. Traverse until nullptr is reached.
            while(temp->next != nullptr)
            {
                // 3. If the next node is nullptr, this means we have found the final node of the list
                temp = temp->next;
            }

            // 4. Link temp->next (tail) to a new node with the value passed in
            //      This efficient because instead of creating a new node and manually
            //      linking it, you can just link the tail node to a new node.
            temp->next = new Node(val);
        }

        // increment size
        size++;
    }

    // **********************************************************************
    // * Add a node val BEFORE the index,th node in the list.
    // * If index equals the length of the list, the node will be appended to
    // *    the end of the list.
    // * If index is greater than the length, the node will not be inserted.
    // **********************************************************************
    void addAtIndex(int index, int val)
    {
        // if index is invalid, do nothing.
        if (index > size) {
            return;
        }

        // if index passed in is 0, insert at head
        if (index==0)
        {
            addAtHead(val);
            return;
        }

        // create a counter to keep track of the index of the list as it traverses the list.
        int count = 0;

        // Curr will keep track of the entire list
        Node * curr = head;

        // Create a new node with val, so that we can link it into the list.
        Node * temp = new Node(val);

        // Traverse through the list and stop BEFORE the given index is reached.
        // NOTE: this syntax is new to me,
        //      count is being incremented, i think like a for loop
        while (++count < index)
        {
            curr = curr->next;
        }

        // After the index is found, Link the new node's next to the next node in the list
        // This links the new node with the next node in the list
        temp->next = curr->next;

        // This links the previous's node next to temp
        curr->next = temp;

        size++;

    }

    // **********************************************************************
    // * Delete the index'th node in the list, if the index is valid.
    // **********************************************************************
    void deleteAtIndex(int index)
    {
        // if head is null or if index is invalid, do nothing.
        if(head == nullptr || index < 0 || index >= size)
            return;

        // If given index is 0, move head forward one.
        //      this deletes the first node.
        if(index == 0)
        {
            head = head->next;
        }

        // If index is greater than 0 but <= size
        else
        {
            // create a counter to keep track of the index of the current node.
            int count = 0;

            // Create a new node to traverse the list.
            Node * curr = head;

            // Traverse the list and stop BEFORE the given index is reached.
            while(++count < index)
            {
                curr = curr->next;
            }

            // link current node to two nodes further down the list.
            //      basically skip over the node we want to delete.
            curr->next = curr->next->next;
        }

        // decrement size.
        size--;
    }

private:
    int size;
    Node * head;
};

int main() {
    auto * myList = new MyLinkedList;
    myList->addAtHead(1);
    myList->addAtTail(3);
    myList->addAtIndex(1,2);
    myList->deleteAtIndex(1);

    cout << myList->get(0) << endl;
    cout << myList->get(1) << endl;
    cout << myList->get(2) << endl;
    cout << myList->get(3) << endl;

    return 0;
}
