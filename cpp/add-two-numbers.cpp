#include <iostream>
#import <ListNode>

using namespace std;

class Solution {
    public:
        // function to add two reverse linked lists, return the sum
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            // create a new list to store the sum
            ListNode dummy(0);
            // create a pointer to the new list
            ListNode* curr = &dummy;
            // create a carry variable to store the carry
            int carry = 0;
            // while l1 or l2 is not null or carry is not 0
            while(l1 || l2 || carry){
                // get sum of current digits
                int sum = (l1? l1->val : 0) + (l2? l2->val : 0) + carry;
                // update carry and l1
                if (l1){
                    carry += l1->val;
                    l1 = l1->next;
                }
                // update carry and l2
                if (l2){
                    carry += l2->val;
                    l2 = l2->next;
                }
                // create a new node with the last digit of sum
                curr->next = new ListNode(sum % 10);
                // update carry to first digit of sum
                carry /= 10;
                // update curr to the next node
                curr = curr->next;
            }
            // return the head of the sum list
        return dummy.next;
        }
};
