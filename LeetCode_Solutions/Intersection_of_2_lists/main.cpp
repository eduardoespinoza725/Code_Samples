#include <iostream>
using namespace std;

// *****************************************************************************************
// * Given the head of two linked lists headA and headB, return the node at which the two
// * lists intersect.
// * If the two lists have no intersection at all, return null.
// ******************************************************************************************

struct Node
{
    int val;
    Node * next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution
{
    Node * getIntersectionNode(Node * headA, Node * headB)
    {
        // skips will keep track of if a node has reached the end of its list and moved to the second one
        // Need to track this because if a node reaches the end of the list again, then
        //      it means there is now intersection.
        int skipA = 0;
        int skipB = 0;

        // Copy the nodes passed in
        //      Need to copy so we can keep the originals at the beginning.
        Node * ptrA = headA;
        Node * ptrB = headB;

        // Create a node to hold the node where both lists intersect.
        //      if there is no intersection, will return 0.
        Node * intersectVal = new Node(0);

        // 1. First catche if either of the nodes is empty, return null.
        if(ptrA == nullptr || ptrB == nullptr)
            return nullptr;
        // 1.5. If both head nodes equal eachother, return the first node.
        //      this means they intersect at the beginning.
        else if(ptrA == ptrB)
        {
            intersectVal = ptrA;
            return intersectVal;
        }

        // 2. Traverse through the list until the intersection is found.
        while(ptrA != ptrB)
        {
            // Move both nodes forward by one.
            //      Need to start with this incase one of the lists only has one node
            //      Move the nodes when they equal null NOT BEFORE.
            ptrA = ptrA->next;
            ptrB = ptrB->next;

            // As soon as the nodes intersect, store the intersection node in intersectVal
            // Even if this statement is wrong the if statements ahead will correct any issues
            //      by going through and completing the whole algorithm.
            if(ptrA == ptrB)
            {
                intersectVal = ptrA;
            }

            // If prtA reaches the end of the list AND the counter is still at 0
            //      move ptrA to the beginning of headB and add one to skipA
            // This is necessary so that prtA only moves lists ONCE.
            if(ptrA == nullptr && skipA == 0)
            {
                ptrA = headB;
                skipA++;
            }

            // If prtB reaches the end of the list AND the counter is still at 0
            //      move ptrB to the beginning of headA and add one to skipB
            // This is necessary so that prtB only moves lists ONCE.
            if(ptrB == nullptr && skipB == 0)
            {
                ptrB = headA;
                skipB++;
            }
        }

        // 3. Once the algorithm above is complete, return the value of intersectVal
        //  It will either be 0, nullptr, or a node
        return intersectVal;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
