#include <iostream>
using namespace std;

// ********************************************************************
// * Given the head of a linked list, reverse the
// * list, and return the reversed list.
// *
// * There are many ways to reverse a list.
// * This program contains 3 different solutions.
// * The first solutions uses 3 pointers and is the one I prefer
// * The second uses 2 pointers
// * The third is a solution using recursion.
// ********************************************************************

// Definition of a singly-linked list
struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

// Solution using 3 pointers
class Solution
{
public:
    ListNode * reverseList(ListNode * head)
    {
        // If head == null or if list only contains one element return head
        if(!head || !head->next)
            return head;

        // Initialize 3 pointers prev points to null, curr points to head, and nextNode is emtpy
        ListNode * prev = nullptr;  // This will reverse the entire list INCLUDING null,
                                    // this will be at the beginning of list
        ListNode * curr = head;
        ListNode * nextNode;

        // Traverse the list until curr == null
        while(curr)
        {
            // Store the next current node in nextNode
            nextNode = curr->next;

            // Change next current node
            // This is where the reversing happens
            curr->next = prev;

            // Move prev and curr one step forward
            prev = curr;
            curr = nextNode;
        }
        // Move head to the end of the list
        head = prev;
        return head;
    }
};

// Solution using 2 pointers
class Solution2
{
public:
    ListNode * reverseList2(ListNode * head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        // currHead will point to the newest head node
        // head will always point to the original head node.
        ListNode * currHead = head;

        // Traverse the list until null is reached.
        while(head->next)
        {
            // Use temp pointer p to indicate the next node of the head node.
            ListNode * p = head->next;

            // Link the "next" field of head to the "next" field of p
            head->next  = p->next;

            // Link the "next" of p to the currHead.
            p->next = currHead;

            // Set currHead to be p
            currHead = p;
        }
        return currHead;
    }
};

class Solution3
{
public:
    ListNode * reverseList3(ListNode * head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode * rest = reverseList3(head->next);
        head->next->next = head;

        head->next = nullptr;

        return rest;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
