#include <iostream>

using namespace std;
class Solution
{
    

public:
struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* current = head;
        ListNode* pre = new ListNode();
        ListNode* vir_head = new ListNode();
        vir_head->next = head;
        pre=vir_head;   // 不是pre->next = head，不然又创建一个虚拟头节点
        while(current != nullptr)
        {
            current = current->next;
            size++;
        }
        delete current;
        if(n > size || n < 1)
            return head;
        int num = size - n + 1;
        
        while(num != 1)
        {
            pre = pre->next;
            num--;
        }
        ListNode* temp = pre->next;
        
        
        if(temp == head && temp->next == nullptr)
        {
            head = nullptr;
            return head;
        }
            
        
        pre->next = temp->next;
        
        head = vir_head->next;
        delete vir_head;
        vir_head = nullptr;
        return head;
        
    }

};
void printList(Solution::ListNode* head) {
    Solution::ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case 1: head = [1, 2], n = 2
    Solution::ListNode* head1 = new Solution::ListNode(1);
    head1->next = new Solution::ListNode(2);
    int n1 = 2;
    printList(head1);
    Solution::ListNode* result1 = solution.removeNthFromEnd(head1, n1);
    cout << "Test case 1: ";
    printList(result1); // Expected output: 2

    // Clean up memory
    while (result1 != nullptr) {
        Solution::ListNode* temp = result1;
        result1 = result1->next;
        delete temp;
    }

    return 0;
}
