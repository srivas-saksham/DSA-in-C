/*WAP to implement SIngly Linked List the stores data as integer and perform followin goperations:
Delete a node in the beginiing and end of the list.
Delete the node that comes after a given node in the linked list.
Search and element in the linked list. If found, delete it.*/


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

//Function to insert a node at the end of the list
void insertNode(struct Node** head, int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    //If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

//Function to display all elements in the list
void printList(struct Node* head){
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List Elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Function to delete the first node
struct Node* deleteFirst(struct Node* head){
    struct Node* ptr = head;
    head = ptr->next;
    free(ptr);

    return head;
}

//Function to delete the last node
struct Node* deleteLast(struct Node* head){
    struct Node* ptr = head;
    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;

    return head;
}

//Function to delete node after a given node
struct Node* deleteAfter(struct Node* head, int val){
    struct Node* ptr = head;
    while(ptr->data != val){
        ptr = ptr->next;
    }
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

//Function to delete a given node
struct Node* deleteValue(struct Node* head, int val){
    struct Node* ptr = head;
    while(ptr->next->data != val){
        ptr = ptr->next;
    }
    if(ptr->next == NULL){
        printf("Element Not Found!");
    }
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

void main(){
    struct Node* start = NULL;
    int n, value;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter Element %d: ", i+1);
        scanf("%d", &value);
        insertNode(&start, value);
    }

    // Deleting First Node
    printf("\nDeleting First Node: \n");
    start = deleteFirst(start);
    printList(start);

    // Deleting Last Node
    printf("\nDeleting Last Node: \n");
    start = deleteLast(start);
    printList(start);

    
    // Deleting the Node After Value
    printf("\nEnter the Value whose next Node is to be Deleted: ");
    scanf("%d", &value);
    start = deleteAfter(start, value);
    printList(start);

    // Deleting the Node with Value n
    printf("\nEnter the Element to Delete: ");
    scanf("%d", &value);
    start = deleteValue(start, value);
    printList(start);
}