#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 4
#define MAX_QUEUE 10000

int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

typedef struct Node {
    int mat[N][N];
    int x, y;
    int cost, level;
    struct Node* parent;
} Node;

Node* pq[MAX_QUEUE];
int pqSize = 0;

int goal[N][N];

void copyMatrix(int src[N][N], int dest[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dest[i][j] = src[i][j];
}

int calculateHeuristic(int mat[N][N]) {
    int h = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int val = mat[i][j];
            if (val != 0) {
                for (int x = 0; x < N; x++) {
                    for (int y = 0; y < N; y++) {
                        if (goal[x][y] == val) {
                            h += abs(x - i) + abs(y - j);
                            break;
                        }
                    }
                }
            }
        }
    return h;
}

Node* createNode(int mat[N][N], int x, int y, int newX, int newY, int level, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    copyMatrix(mat, node->mat);

    int temp = node->mat[x][y];
    node->mat[x][y] = node->mat[newX][newY];
    node->mat[newX][newY] = temp;

    node->x = newX;
    node->y = newY;
    node->level = level;
    node->cost = calculateHeuristic(node->mat) + level;
    node->parent = parent;

    return node;
}

int isGoal(int mat[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] != goal[i][j])
                return 0;
    return 1;
}

void push(Node* node) {
    int i = pqSize++;
    while (i > 0 && pq[(i - 1) / 2]->cost > node->cost) {
        pq[i] = pq[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq[i] = node;
}

Node* pop() {
    if (pqSize == 0) return NULL;
    Node* top = pq[0];
    pq[0] = pq[--pqSize];
    int i = 0;
    while (2 * i + 1 < pqSize) {
        int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (pq[l]->cost < pq[smallest]->cost) smallest = l;
        if (r < pqSize && pq[r]->cost < pq[smallest]->cost) smallest = r;
        if (smallest == i) break;
        Node* temp = pq[i];
        pq[i] = pq[smallest];
        pq[smallest] = temp;
        i = smallest;
    }
    return top;
}

void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printMatrix(node->mat);
}

void solve(int initial[N][N], int x, int y) {
    Node* root = createNode(initial, x, y, x, y, 0, NULL);
    push(root);

    while (pqSize > 0) {
        Node* min = pop();

        if (isGoal(min->mat)) {
            printf("\nSolution found at level %d with cost %d\n\n", min->level, min->cost);
            printf("Intermediate Steps:\n");
            printPath(min);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newX = min->x + rowDir[i];
            int newY = min->y + colDir[i];

            if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
                Node* child = createNode(min->mat, min->x, min->y, newX, newY, min->level + 1, min);
                push(child);
            }
        }
    }

    printf("No solution found.\n");
}

int main() {
    int initial[N][N], blankX, blankY;

    printf("Enter the initial state (4x4, use 0 for blank):\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            scanf("%d", &initial[i][j]);
            if (initial[i][j] == 0) {
                blankX = i;
                blankY = j;
            }
        }

    printf("Enter the goal state (4x4, use 0 for blank):\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &goal[i][j]);

    solve(initial, blankX, blankY);
    return 0;
}
