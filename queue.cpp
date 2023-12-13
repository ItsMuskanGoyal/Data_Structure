// queue using doubly linkedlist

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

class queue{
    public:
        Node* head;
        Node* tail;

        queue(){
            this->head = NULL;
            this->tail = NULL;
        }

        void enqueue(int data){
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

        void dequeue(){
            if(this->head == NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                Node* temp = this->head;
                this->head = this->head->next;
                this->head->prev = NULL;
                delete temp;
            }
        }

        void print(){
            if(this->head == NULL){
                cout << "Queue is empty" << endl;
            }
            else{
                Node* temp = this->head;
                while(temp){
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main(){
    queue* q = new queue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->print();
    q->dequeue();
    q->print();
    q->dequeue();
    q->print();

}