#include <stdio.h>
#include <stdlib.h>

// Define the structure for a circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list of n elements
struct Node* createCircularLinkedList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int data, i;

    // Loop to create 'n' nodes
    for (i = 1; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        // Create a new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = head; // Point to head to make it circular

        if (head == NULL) {
            head = newNode;
            temp = head; // Store the last node for linking back to head
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    // Complete the circular link
    temp->next = head;

    return head;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode; // Link it to itself if list is empty
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Insert the new node at the beginning and adjust the circular link
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    newNode->next = *head;
    temp->next = newNode;
}

// Function to insert after a specific element
void insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Element %d not found!\n", key);
}

// Function to insert before a specific element
void insertBefore(struct Node** head, int key, int data) {
    if (*head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the head itself is the key
    if ((*head)->data == key) {
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    if (temp == *head) {
        printf("Element %d not found!\n", key);
        free(newNode);
        return;
    }

    prev->next = newNode;
    newNode->next = temp;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position != 1) {
        printf("Position %d does not exist. Inserting at the end instead.\n", position);
        insertAtEnd(head, data);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    if (*head == (*head)->next) {
        free(*head);
        *head = NULL;
    } else {
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Function to delete a specific node
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->data == key && temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }

    do {
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    if (temp == *head) {
        printf("Element %d not found!\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to delete a node after a specific element
void deleteAfter(struct Node* head, int key) {
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* toDelete = temp->next;
            if (toDelete == head) {
                printf("No node to delete after %d\n", key);
                return;
            }
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Element %d not found!\n", key);
}

// Function to delete a node before a specific element
void deleteBefore(struct Node** head, int key) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("No node to delete before %d\n", key);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* beforePrev = NULL;

    if (temp->data == key) {
        printf("There is no node before %d\n", key);
        return;
    }

    do {
        beforePrev = prev;
        prev = temp;
        temp = temp->next;
    } while (temp != *head && temp->data != key);

    if (temp == *head) {
        printf("Element %d not found!\n", key);
        return;
    }

    if (prev == *head) {
        deleteAtBeginning(head);
    } else {
        beforePrev->next = temp;
        free(prev);
    }
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; temp->next != *head && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == *head && position != 1) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key, position;

    while (1) {
        printf("\nCircular Linked List Operations Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specific element\n");
        printf("4. Insert before a specific element\n");
        printf("5. Insert at a specific position\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete at the end\n");
        printf("8. Delete a specific node\n");
        printf("9. Delete after a specific element\n");
        printf("10. Delete before a specific element\n");
        printf("11. Delete at a specific position\n");
        printf("12. Display the list\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter element to insert after: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAfter(head, key, data);
                break;
            case 4:
                printf("Enter element to insert before: ");
                scanf("%d", &key);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertBefore(&head, key, data);
                break;
            case 5:
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(&head, data, position);
                break;
            case 6:
                deleteAtBeginning(&head);
                break;
            case 7:
                deleteAtEnd(&head);
                break;
            case 8:
                printf("Enter value of node to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 9:
                printf("Enter element to delete after: ");
                scanf("%d", &key);
                deleteAfter(head, key);
                break;
            case 10:
                printf("Enter element to delete before: ");
                scanf("%d", &key);
                deleteBefore(&head, key);
                break;
            case 11:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 12:
                printList(head);
                break;
            case 13:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
