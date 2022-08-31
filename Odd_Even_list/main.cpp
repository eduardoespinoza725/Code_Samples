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
    ListNode * oddEvenList(ListNode * head)
    {
        // Check if head is null
        if(head == nullptr)
            return nullptr;

        // create three pointers
        ListNode * odd = head;
        // Even will start on the second node of the list
        ListNode * even = head->next;
        // evenHead will start on the same node as even, but will stay there to track it.
        ListNode * evenHead = even;

        // Put odd nodes in one list and the even nodes in another.
        // Then link the evenList to the tail of oddList.
        while(even != nullptr && even->next != nullptr)
        {
            // Make odd->next point to the node in front of the even node
            // This skips over the even node.
            odd->next = even->next;

            // Move the odd pointer forward
            odd = odd->next;

            // Make even->next point to the node in front of the odd node
            // This skips the odd node and seperates the even nodes.
            even->next = odd->next;

            // Move even forward.
            even = even->next;
        }

        // Once the while loop ends, odd will be pointing to the final odd node
        // add evenHead to the end of the odd list.
        // Remember, evenHead points to the first even node and contains an evenList.
        odd->next = evenHead;
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
