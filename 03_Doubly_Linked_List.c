#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a doubly linked list of n elements
struct Node* createDoublyLinkedList(int n) {
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
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
        }
        temp = newNode;
    }
    return head;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    if (*head != NULL) {
        (*head)->prev = newNode;
    }

    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert after a specific element
void insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to insert before a specific element
void insertBefore(struct Node** head, int key, int data) {
    struct Node* temp = *head;
    if (temp == NULL) {
        printf("The list is empty!\n");
        return;
    }

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }

    temp->prev = newNode;
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d does not exist. Inserting at the end instead.\n", position);
        insertAtEnd(head, data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    *head = temp->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
}

// Function to delete a specific node by key
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to delete a node after a specific element
void deleteAfter(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("No node found after %d or element not found!\n", key);
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;

    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }

    free(toDelete);
}

// Function to delete a node before a specific element
void deleteBefore(struct Node** head, int key) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("No node to delete before %d\n", key);
        return;
    }

    struct Node* temp = *head;

    if ((*head)->data == key) {
        printf("There is no node before %d\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("Element %d not found!\n", key);
        return;
    }

    struct Node* toDelete = temp->prev;

    if (toDelete->prev != NULL) {
        toDelete->prev->next = temp;
        temp->prev = toDelete->prev;
    } else {
        *head = temp;
        temp->prev = NULL;
    }

    free(toDelete);
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
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d does not exist.\n", position);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
}

// Function to display the doubly linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    printf("NULL <- ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu for operations
int main() {
    struct Node* head = NULL;
    int n, choice, data, key, position;

    // Create a doubly linked list with 'n' elements
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    head = createDoublyLinkedList(n);

    while (1) {
        printf("\n*** Menu ***\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after an element\n");
        printf("4. Insert before an element\n");
        printf("5. Insert at a specific position\n");
        printf("6. Delete at the beginning\n");
        printf("7. Delete at the end\n");
        printf("8. Delete a specific element\n");
        printf("9. Delete after an element\n");
        printf("10. Delete before an element\n");
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
