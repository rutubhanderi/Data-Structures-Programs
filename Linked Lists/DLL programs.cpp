//DLL programs
#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

//create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the beginning 
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

//  insert a node at the end 
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}
//insert node at any position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int currentPosition = 0;
    while (currentPosition < position - 1 && current->next != NULL) {
        current = current->next;
        currentPosition++;
    }
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}
//Delete first node
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}
//Delete last node
void deleteLastNode(struct Node** head)
{
	if(*head==NULL)
	{
		printf("List is empty.Nothing to delete.\n");
		return;
	}
	struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    if (current->prev != NULL) {
        current->prev->next = NULL;
    } 
	else {
        
        *head = NULL;
    }
    free(current);
}

//Delete node at any position
void deleteAtPosition(struct Node** head, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }
    if (position == 0 || *head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }
    struct Node* current = *head;
    int currentPosition = 0;
    while (currentPosition < position && current != NULL) {
        current = current->next;
        currentPosition++;
    }
    if (current == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}
//concatenate 2 lists
void concatenateLists(struct Node** list1, struct Node** list2) {
    if (*list1 == NULL) {
        *list1 = *list2;
    } else if (*list2 != NULL) {
        struct Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = *list2;
        (*list2)->prev = current;
    }
}
//sort list
void bubbleSort(struct Node** head) {
    int swapped;
    struct Node* current;
    struct Node* last = NULL;

   
    if (*head == NULL)
        return;

    do {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->data > current->next->data) {
                
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
//reverse list
void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* temp = NULL;
    
    while (current != NULL) {
     
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        

        current = current->prev;
    }
    
   
    if (temp != NULL) {
        *head = temp->prev;
    }
}
//search node
struct Node* searchValue(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// print and display
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    
    insertAtEnd(&list1, 10);
    insertAtEnd(&list1, 20);
    insertAtEnd(&list1, 30);

   
    insertAtEnd(&list2, 40);
    insertAtEnd(&list2, 50);
    insertAtEnd(&list2, 60);

    
    printf("First DLL: ");
    displayList(list1);

    
    printf("Second DLL: ");
    displayList(list2);

    
    

    return 0;
}
