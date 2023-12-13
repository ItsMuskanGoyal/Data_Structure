// stack using singly linked list

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

        void removeStart(){
            if(this->head == NULL){
                return;
            }
            this->head = this->head->next;
        }

        void insertAtStart(int data){
            Node* newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode;
            }
            else{
                newNode->next = this->head;
                this->head = newNode;
            }
        }
       
        void print(){
            if(this->head == NULL){
                cout << "List is empty" << endl;
            }
            else{
                Node* curr = this->head;
                while(curr != NULL){
                    cout << curr->data << " ";
                    curr = curr->next;
                }
                cout << endl;
            }
        }

        bool isEmpty(){
            return this->head == NULL;
        }
};

class Stack{
    public:
        SinglyLinkedList* list;

        Stack(){
            this->list = new SinglyLinkedList();
        }

        void push(int data){
            this->list->insertAtStart(data);
        }

        void pop(){
            this->list->removeStart();
        }

        int top(){
            return this->list->head->data;
        }

        bool isEmpty(){
            return this->list->isEmpty();
        }

        void print(){
            this->list->print();
        }
};

int main(){
    Stack* stack = new Stack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->print();
    stack->pop();
    stack->pop();
    stack->print();
    cout << stack->isEmpty() << endl;
    return 0;
}
