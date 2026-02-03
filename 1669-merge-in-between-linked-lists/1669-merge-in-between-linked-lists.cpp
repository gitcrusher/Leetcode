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
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        // int count = 1;
        ListNode* l1 = list1;
        for(int i = 0 ; i < a-1;i++){
            l1=l1->next;
        }

        ListNode* temp = l1;
        for(int i =a-1 ;i<=b;i++){
            temp = temp->next;
        }

        l1->next = list2;

        ListNode* l2 = list2;
        while(l2->next != nullptr){
            l2 = l2->next;
        }

        l2->next = temp;



        // while(l1->next!=nullptr){
        //     if(count==a){
        //         prev->next = list2;
        //     }
        //     if(count ==b){
        //         temp = l1->next;
        //         break;
        //     }
        //     prev = l1;
        //     l1=l1->next;
        //     count++;
        // }
        // while(l2->next != nullptr){
        //     l2=l2->next;
        // }
        // l2->next = temp;

        return list1;
    }
};