#include <iostream>
using namespace std;

// *****************************************************************************************
// * Given head, the head of a linked list, determine if the linked list has a cycle in it.
// * There is a cycle in a linked list if there is some node in the list that can be reached
// * again by continuously following the next pointer. Internally, pos is used to denote the
// * index of the node that tail's next pointer is connected to.
// *
// * Note that pos is not passed as a parameter.
// *
// * Return true if there is a cycle in the linked list. Otherwise, return false.
// ******************************************************************************************

// Definition of a singly linked list
struct Node
{
    int val;
    Node * next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(Node * head)
    {
        // If head is null return false
        if(head == nullptr)
            return false;

        // Create 2 nodes, one will start at the beginning and the other 1 ahead
        Node * slow = head;
        Node * fast = head->next;

        // Keep traversing through the list until you find where they equal the same
        while(slow != fast)
        {
            // If fast equal nullptr at any time, this means there is no cycle
            //      the list has no cylce, it just ends.
            if(fast == nullptr || fast->next == nullptr)
                return false;

            // Move both nodes forward
            // slow by 1
            slow = slow->next;
            // fast by 2, slow will be right behind it!
            fast = fast->next->next;
        }
        // The while loop ending means there was a match indicating that it has a cycle.
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
