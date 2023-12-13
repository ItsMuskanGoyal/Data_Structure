#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


class SinglyLinkedList{
    public:
        Node* head;

        SinglyLinkedList(){
            this->head = NULL;
        }

        Node* search(int data){
            if(this->head == NULL){
                return NULL;
            }
            Node* curr = this->head;
            while(curr){
                if(curr->data == data){
                    return curr;
                }
                curr = curr->next;
            }
            return NULL;
        }

        void removeAtk(int k){
            if(k == 0){
                removeStart();
                return;
            }
            Node* curr = this->head;
            while(curr != NULL && k > 1){
                curr = curr->next;
                k--;
            }
            if (k > 1 || curr == NULL || curr->next == NULL){
                cout << "Invalid Position \n"; 
            }
    
            curr->next = curr->next->next;
        }

        void removeStart(){
            if(this->head == NULL){
                return;
            }
            this->head = this->head->next;

        }

        void insertAtStart(int data){
            Node* x = new Node(data);
            if(this->head == NULL){
                this->head = x;
            }else{
                x->next = this->head;
                this->head = x;
            }
        }

        void insertAtk(int data, int k){
            if(k == 0){
                insertAtStart(data);
                return;
            }
            Node* curr = this->head;
            while(k > 1 && curr != NULL ){
                curr = curr->next;
                k--;
            }
            if (k > 0) {
                cout << "Invalid position\n";
                return;
            }

            Node* x = new Node(data);
            x->next = curr->next;
            curr->next = x;
            

        }
};


int main(){
    cout << "Hii";
}