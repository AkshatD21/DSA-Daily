// APPROACH 1:
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // Base case: if the list has less than two nodes, no swapping needed
        if (!head || !head->next)
        {
            return head;
        }

        // Swap the current two nodes
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};

// APPROACH 2:

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *node = dummy;

        while (node != NULL)
        {
            ListNode *first = node->next;
            ListNode *second = NULL;
            if (first != NULL)
            {
                second = first->next;
            }
            if (second != NULL)
            {
                ListNode *sn = second->next;
                second->next = first;
                node->next = second;
                first->next = sn;
                node = first;
            }
            else
            {
                break;
            }
        }
        return dummy->next;
    }
};