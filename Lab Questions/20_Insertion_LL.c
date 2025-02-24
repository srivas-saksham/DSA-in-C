/*WAP to implement Singly Linked List that stores data as integer and perform following operations:
Insert a new node in the beginning and end of the list
Insert a new node after a given node in the list.
Insert a new node before a given node in the list.*/


#include <stdio.h>
#include <stdlib.h>

//Structure fora node in the singly linked list
struct Node {
    int data;       //Stores integer data
    struct Node* next;  //Pointer to the next node
};

//Function to display all elements in the list
void printList(struct Node* head) {
    struct Node* temp = head;

    //If list is empty
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

//Function to insert a node at the end of the list
void insertNode(struct Node** head, int value){
    //Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //ifthe list is empty, make the new node the head
    if(*head == NULL){
        *head = newNode;
        return;
    }

    //Traverse to the last node
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    //Insert the new node at the end
    temp->next = newNode;
}

void insertBeg(struct Node** head, int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(struct Node* head, int val){
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    temp->next = newNode;
}

void insertAfter(struct Node* head, int val, int pos){
    struct Node* temp = head;
    int count = 1;
    while(count < pos){
        temp = temp->next;
        count++;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(struct Node* head, int val, int pos) {
    struct Node* temp = head;
    int count = 1;

    while (count < pos-1) {
        temp = temp->next;
        count++;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}


int main(){
    struct Node* head = NULL;
    int n, value;

    //Prompt user for number of elements
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    //Insert elements into the linked list
    printf("Enter %d elements: \n", n);
    for(int i = 0; i < n; i++){
        printf("Enter Element %d: ", i+1);
        scanf("%d", &value);
        insertNode(&head, value);
    }

    //Inserting element in beginning of the linked list
    int newVal;
    int pos;
    printf("Enter Element to Insert in Beginning: ");
    scanf("%d", &newVal);
    insertBeg(&head, newVal);
    printList(head);

    //Inserting element in beginning of the linked list
    printf("Enter Element to Insert in End: ");
    scanf("%d", &newVal);
    insertEnd(head, newVal);
    printList(head);

    //Inserting element in after a position on the linked list
    printf("Enter Element to Insert: ");
    scanf("%d", &newVal);
    printf("Enter Position After which the Element will be Inserted: ");
    scanf("%d", &pos);
    insertAfter(head, newVal, pos);
    printList(head);

    //Inserting element in before a position on the linked list
    printf("Enter Element to Insert: ");
    scanf("%d", &newVal);
    printf("Enter Position Before which the Element will be Inserted: ");
    scanf("%d", &pos);
    insertBefore(head, newVal, pos);
    printList(head);

    return 0;
}