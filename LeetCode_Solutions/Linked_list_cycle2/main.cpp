#include <iostream>
using namespace std;

// *****************************************************************************************
// * Given the head of a linked list, return the node where the cycle begins.
// * If there is no cycle, return null.
//
// * There is a cycle in a linked list if there is some node in the list that can be reached
// * again by continuously following the next pointer. Internally, pos is used to denote the
// * index of the node that tail's next pointer is connected to (0-indexed). It is -1 if
// * there is no cycle.
// * Note that pos is not passed as a parameter.
// ******************************************************************************************

struct Node
{
    int val;
    Node * next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    // This function will return the node where the cycle begins
    // This function uses the tortoise and the hare aglorithm
    Node * detectCycle(Node * head)
    {
        if(head == nullptr)
            return nullptr;

        // Both Start at the beginning of the list
        // slow will move one space at a time
        Node * slow = head;
        // fast will move 2 spaces at a time.
        Node * fast = head;

        // Traverse through the list until slow and fast meet
        // This will indicate a cycle exists
        while(fast != nullptr)
        {
            // if a fast finds a nullptr, then a cycle does not exists.
            if (fast->next == nullptr)
                return nullptr;

            // move forward until slow and fast meet.
            slow = slow->next;
            fast = fast->next->next;

            // once they meet end while
            if(slow == fast)
                break;
        }

        // if no cycle was found
        if(slow != fast)
            return nullptr;

        // If cycle exists, Start slow from head
        // Leave fast at the node where they met.
        slow = head;
        while(slow != fast)
        {
            // move both forward by one until they meet
            // They will meet at the beginning of the cycle.
            slow = slow->next;
            fast = fast->next;
        }

        // return the node at the beginning of the cycle.
        return slow;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
