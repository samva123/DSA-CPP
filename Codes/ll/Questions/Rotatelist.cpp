#include<bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
// class ListNode {
//     int val;
//     ListNode next;
//     ListNode() {}
//     ListNode(int val) { this.val = val; }
//     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// };

// class Solution {
//     public int getlen(ListNode head){
//         ListNode temp = head;
//         int len  = 0;
//         while(temp != null){
//             len++;
//             temp = temp.next;

//         }
//         return len;
//     }
//     public ListNode rotateRight(ListNode head, int k) {
//         if(head == null || head.next == null ) return head;
//         int n = getlen(head);
//         k = k%n;
//         if(k == 0) return head;
        
        
        
//         ListNode temp = head;

//         while(temp.next != null){
//             temp = temp.next;
//         }
//         ListNode tail = temp;
//         tail.next = head;


//         int act  = n-k;

//         ListNode curr = head;
//         while(act > 1){
//             curr = curr.next;
//             act--;
//         }

//         ListNode newHead  = curr.next;
//         curr.next = null;
//         return newHead;

        
        
//     }
// }













// /**
//  * Definition for singly-linked list.
//  * public class ListNode {
//  *     int val;
//  *     ListNode next;
//  *     ListNode() {}
//  *     ListNode(int val) { this.val = val; }
//  *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
//  * }
//  */
// class Solution {
//     public int getlen(ListNode head){
//         ListNode temp = head;
//         int len  = 0;
//         while(temp != null){
//             len++;
//             temp = temp.next;

//         }
//         return len;
//     }
//     public ListNode rotateRight(ListNode head, int k) {

//         if(head == null || head.next == null || k == 0) return head;
//         int n = getlen(head);
//         k = k%n;
//         ListNode temp = head;

//         List<Integer>rotate = new ArrayList<>();
//         while(temp != null){
//             rotate.add(temp.val);
//             temp = temp.next;
//         }

//         List<Integer>result  = new ArrayList<>();
//         result.addAll(rotate.subList(n-k , n));
//         result.addAll(rotate.subList(0, n-k));


//         ListNode temp1  =head;
//         int i  = 0;
//         while(temp1 != null){
//             temp1.val = result.get(i);
//             i++;
//             temp1 = temp1.next;
//         }


//         return head;
        
//     }
// }