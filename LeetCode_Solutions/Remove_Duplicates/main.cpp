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
    ListNode * removeElements(ListNode * head, int val)
    {
        ListNode * curr = head;

        // Skip any duplicates at the start of the list
        // ex: 1,1,1,1,2,4,5...
        while(curr != nullptr && curr->val == val)
        {
            curr = curr->next;
        }

        // Next the first non-val element is reached
        // Or curr if pointing to the end of the list.

        // Move head forward, to the new beginning of list.
        head = curr;
        // Use prev to track the node behind curr
        ListNode * prev = head;

        // Traverse the list until curr reaches null
        // Both prev and curr will move forward one at a time, one after the other.
        while(curr != nullptr)
        {
            // If a val has been found, link prev-next to the node in front of curr
            // This unlinks the node curr is pointing to.
            if(curr->val == val)
                prev->next = curr->next;
            // Else, move prev forward
            else
                prev = curr;
            // Move curr forward
            curr = curr->next;
        }
        return head;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
