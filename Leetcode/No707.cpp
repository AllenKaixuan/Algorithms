class MyLinkedList {
struct Node
{
    int val;
    Node* next;
    Node(int val){this->next = nullptr; this->val = val;}
};
Node* head;
public:
    MyLinkedList() {
        
        head = new Node(0);
    }
    
    int get(int index) {
        Node* current = this->head;
        while(current->next != nullptr)
        {
            if(index < 0)
                return current->val;
            current = current->next;
            index--;
        }
        if(current->next == nullptr && index < 0)
            return current->val;
        return -1;
    }
    
    void addAtHead(int val) {
        Node* current = new Node(val);
        if(this->head->next == nullptr)
            this->head->next = current;
        else
        {
            current->next = head->next;
            head->next = current;
        }
        
    }
    
    void addAtTail(int val) {
        Node* current = this->head;
        Node* temp = new Node(val);
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
        
    }
    
    void addAtIndex(int index, int val) {
        Node* temp = new Node(val);
        Node* current = this->head;
        while(current->next != nullptr)
        {
            if(index == 0)
               break;  
            current = current->next;
            index--;
        }
        if(current->next == nullptr)
            current->next = temp;
        else
        {
            temp->next = current->next;
            current->next = temp;
        }
        
    }
    
    void deleteAtIndex(int index) {
        
        Node* current = this->head;
        while(current->next != nullptr)
        {
            if(index == 0)
            {
                Node* temp = new Node(0);
                temp = current->next;
                current->next = temp->next;
                delete temp; 
                return;
            }
                
            current = current->next;
            index--;
        }
        if(index != 0)
            return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 **/ 

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> commands = {"MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"};
    std::vector<std::vector<int>> params = {{}, {1}, {3}, {1, 2}, {1}, {1}, {1}};
    
    MyLinkedList* obj = nullptr;
    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "MyLinkedList") {
            obj = new MyLinkedList();
            std::cout << "MyLinkedList created" << std::endl;
        } else if (commands[i] == "addAtHead") {
            obj->addAtHead(params[i][0]);
            std::cout << "addAtHead(" << params[i][0] << ")" << std::endl;
        } else if (commands[i] == "addAtTail") {
            obj->addAtTail(params[i][0]);
            std::cout << "addAtTail(" << params[i][0] << ")" << std::endl;
        } else if (commands[i] == "addAtIndex") {
            obj->addAtIndex(params[i][0], params[i][1]);
            std::cout << "addAtIndex(" << params[i][0] << ", " << params[i][1] << ")" << std::endl;
        } else if (commands[i] == "get") {
            int result = obj->get(params[i][0]);
            std::cout << "get(" << params[i][0] << ") = " << result << std::endl;
        } else if (commands[i] == "deleteAtIndex") {
            obj->deleteAtIndex(params[i][0]);
            std::cout << "deleteAtIndex(" << params[i][0] << ")" << std::endl;
        }
    }
    
    delete obj;
    return 0;
}
