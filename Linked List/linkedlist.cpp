#include <iostream>
using namespace std;

class Node{
    public:
        char id;
        Node *next;

        Node(){
            next = NULL;
        }
};

class LinkedList{
    public:
        Node *head;
        Node *tail;

        LinkedList(){
            head = tail = NULL;
        }

        void insertToHead(char data){
            Node *node = new Node;
            node -> id = data;

            if(head == NULL){
                head = tail = node;
            }else{
                Node *tmp = head;
                head = node;
                head -> next = tmp;
            }
        }

        void insertToTail(char data){
            Node *node = new Node;
            node -> id = data;

            if(head == NULL){
                head = tail = node;
            }else{
                tail -> next = node;
                tail = node;
            }
            
        }

        void insertDataAfter(char data, char after){
            if(head == NULL){
                cout << "Error : LinkedList is Empty!" << endl;
            }else if(after == tail->id){
                insertToTail(data);
            }else{
                Node *tmp = head;
                while(tmp != NULL && tmp->id!=after){
                    tmp = tmp->next;
                }

                if(tmp == NULL){
                    cout << "After data not found" << endl;
                }else{
                    Node*newNode = new Node();
                    newNode->id = data;
                    
                    newNode->next = tmp->next;
                    tmp->next = newNode;
                }
            }
        }

        void printAll(){
            Node *tmp = head;
            while(tmp != NULL){
                cout << tmp -> id << " > ";
                tmp = tmp -> next;
            }
        }
};

int main(){
    LinkedList *list1 = new LinkedList();

    Node *node1 = new Node();
    node1 -> id = 'A';

    list1 -> head = node1;
    list1 -> tail = node1;

    cout << list1 -> head -> id << endl;
    cout << list1 -> tail -> id << endl;

    // insert to tail
    Node *node2 = new Node();
    node2 -> id = 'B';

    list1 -> tail -> next = node2;
    list1 -> tail = node2;

    cout << list1 -> head -> id << endl;
    cout << list1 -> tail -> id << endl;

    //insert to head
    Node *nodeX = new Node();
    nodeX -> id = 'X';

    Node *tmp = list1 -> head;
    list1 -> head = nodeX;
    list1 -> head -> next = tmp;

    cout << list1 -> head -> id << endl;
    cout << list1 -> tail -> id << endl;


    // After creating function
    list1 -> insertToHead('Y');
    list1 -> insertToTail('C');

    cout << list1 -> head -> id << endl;
    cout << list1 -> tail -> id << endl;

    list1 -> insertDataAfter('Z', 'K');

    cout << endl;

    list1 -> printAll();
}
