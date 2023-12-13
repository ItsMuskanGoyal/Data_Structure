#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

class doublyLinkedList{
    public:
        Node* head;
        Node* tail;

        doublyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }

        void InsertAtStart(int data){
            Node* newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                newNode->next = this->head;
                this->head->prev = newNode;
                this->head = newNode;
            }
        }

        void InsertAtEnd(int data){
            Node* newNode = new Node(data);
            if(this->head == NULL){
                this->head = newNode;
                this->tail = newNode;
            }
            else{
                this->tail->next = newNode;
                newNode->prev = this->tail;
                this->tail = newNode;
            }
        }

        void removeAtStart(){
            if(this->head == NULL){
                cout << "List is empty" << endl;
            }
            else{
                Node* temp = this->head;
                this->head = this->head->next;
                this->head->prev = NULL;
                delete temp;
            }
        }

        void removeAtEnd(){
            if(this->head == NULL){
                cout << "List is empty" << endl;
            }
            else{
                Node* temp = this->tail;
                this->tail = this->tail->prev;
                this->tail->next = NULL;
                delete temp;
            }
        }

};


int main(){
    
}