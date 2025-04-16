/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
   int findLength(ListNode *&head)
   {
      int len = 0;
      ListNode *temp = head;
      while (temp != NULL)
      {
         len++;
         temp = temp->next;
      }
      return len;
   }
   ListNode *reverseKGroup(ListNode *head, int k)
   {

      int length = findLength(head);

      if (head == NULL || k == 1)
      {
         return head;
      }
      if (head->next == NULL)
      {
         return head;
      }
      if (length < k)
      {
         return head;
      }
      ListNode *recans = NULL;
      ListNode *prev = NULL;
      ListNode *curr = head;
      int pos = 0;
      ListNode *Nextnode = curr->next;
      while (pos < k)
      {
         Nextnode = curr->next;
         curr->next = prev;
         prev = curr;
         curr = Nextnode;
         pos++;
      }
      if (Nextnode != NULL)
      {
         head->next = reverseKGroup(Nextnode, k);
      }

      return prev;
   }
};