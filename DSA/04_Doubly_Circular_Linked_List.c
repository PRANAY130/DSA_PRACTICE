#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly circular linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a doubly circular linked list of n elements
struct Node* createDoublyCircularList(int n) {
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
            newNode->next = head;  // Make it circular
            newNode->prev = head;  // Make it circular
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
        temp = newNode;
    }
    return head;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;

        *head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        struct Node* last = (*head)->prev;

        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to insert after a specific element
void insertAfter(struct Node* head, int key, int data) {
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Element %d not found!\n", key);
}

// Function to insert before a specific element
void insertBefore(struct Node** head, int key, int data) {
    struct Node* temp = *head;
    do {
        if (temp->data == key) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;

            newNode->prev = temp->prev;
            newNode->next = temp;
            temp->prev->next = newNode;
            temp->prev = newNode;

            if (temp == *head) {
                *head = newNode;
            }
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Element %d not found!\n", key);
}

// Function to insert at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position > 1) {
        insertAtEnd(head, data);
    } else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

// Function to delete a node at the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* last = (*head)->prev;
    struct Node* temp = *head;

    if (*head == (*head)->next) {
        *head = NULL;
        free(temp);
        return;
    }

    last->next = temp->next;
    temp->next->prev = last;
    *head = temp->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* last = (*head)->prev;
    struct Node* temp = last;

    if (*head == (*head)->next) {
        *head = NULL;
        free(temp);
        return;
    }

    last->prev->next = *head;
    (*head)->prev = last->prev;
    free(temp);
}

// Function to delete a specific node by key
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prevNode = NULL;
    do {
        if (temp->data == key) {
            if (temp == *head) {
                deleteAtBeginning(head);
                return;
            } else if (temp->next == *head) {
                deleteAtEnd(head);
                return;
            }

            prevNode = temp->prev;
            prevNode->next = temp->next;
            temp->next->prev = prevNode;
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);

    printf("Element %d not found!\n", key);
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
    for (int i = 1; i < position && temp->next != *head; i++) {
        temp = temp->next;
    }

    if (temp->next == *head && position > 1) {
        deleteAtEnd(head);
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

// Function to display the doubly circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Main function with menu for operations
int main() {
    struct Node* head = NULL;
    int n, choice, data, key, position;

    // Create a doubly circular linked list with 'n' elements
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    head = createDoublyCircularList(n);

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
        printf("9. Delete at a specific position\n");
        printf("10. Display the list\n");
        printf("11. Exit\n");
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
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 10:
                printList(head);
                break;
            case 11:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
