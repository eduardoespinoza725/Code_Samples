#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode * next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode * removeNthFromEnd(ListNode * head, int n)
    {
        // Catch if head is empty or invalid number passed in, return null
        if(head == nullptr || n < 0)
            return nullptr;
        // If list only contains one element, delete head and return it.
        if(head->next == nullptr)
        {
            head = nullptr;
            return head;
        }

        // Create 2 nodes, one to track head, other to traverse list and find size of list.
        ListNode * main = head;
        ListNode * ref = head;
        int size = 0;

        // Traverse list and find size.
        while(ref != nullptr)
        {
            ref = ref->next;
            size++;
        }

        // If the number passed in equals size, delete head
        // Remember, we want to delete the number Nth from back
        // so a list with 5 elements (4 indexes) -> 01234
        // Nth from the back -> 43210
        // 4 == 4
        if(size == n)
        {
            head = head->next;
            return head;
        }
        else
        {
            // Return ref to head so it can be used again.
            ref = head;

            // loop through the list, skipping the first one, since we take care of it earlier.
            for(int i = 1; i < n; i++)
            {
                // The loop will stop when n equals the index we are looking for
                ref = ref->next;
            }

            // Using the 2 pointer technique move both nodes forward by one until ref reaches null.
            // ref starts at the index n
            // main starts at head.
            while (ref->next != nullptr)
            {
                ref = ref->next;
                main = main->next;
            }

            // return ref to beginning.
            ref = head;

            // Move ref forward by one, until it reaches the node before main.
            while (ref->next != main)
            {
                ref = ref->next;
            }

            // once ref reaches the node before main, link ref to the node after main.
            // this unlinks main node.
            ref->next = ref->next->next;
        }
        return head;
    }
};

int main() {
    for(int i = 0; i < 3; i++)
        cout << i << endl;
    return 0;
}
