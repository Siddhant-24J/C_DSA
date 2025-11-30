/*
 * C Programming Questions and Answers (1-20)
 * Each question is followed by its complete, standalone code solution
 * Each answer is independent with its own required libraries and main function
 * 
 * INSTRUCTIONS: To compile a specific question, uncomment the corresponding
 * #if 0 and change it to #if 1, and comment out all other solutions.
 * Only ONE solution should be active at a time (change #if 0 to #if 1).
 */

// ============================================================================
// QUESTION 1: BST Tree Assignment with following options
// Insert, Traversal without recursion Pre-order, exit
// ============================================================================

#if 1  // Change to #if 0 to disable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    
    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Traversal without recursion Pre-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Pre-order traversal: ");
                    preorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 1

// ============================================================================
// QUESTION 2: Insertion sort with Read, sort, display, exit options
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[100], n = 0, choice, i;
    
    while (1) {
        printf("\n1. Read\n2. Sort\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Elements read successfully.\n");
                break;
            case 2:
                if (n == 0) {
                    printf("Please read elements first.\n");
                } else {
                    insertionSort(arr, n);
                    printf("Array sorted successfully.\n");
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 2

// ============================================================================
// QUESTION 3: BST Tree Assignment with following options
// Insert, Traversal without recursion In-order, exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Traversal without recursion In-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 3

// ============================================================================
// QUESTION 4: BST Tree Assignment with following options
// Insert, Traversal without recursion Post-order, exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    
    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        
        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }
    
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Traversal without recursion Post-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Post-order traversal: ");
                    postorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 4

// ============================================================================
// QUESTION 5: Merge Sort with Read, sort, display, exit options
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[100], n = 0, choice, i;
    
    while (1) {
        printf("\n1. Read\n2. Sort\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter elements: ");
                for (i = 0; i < n; i++) {
                    scanf("%d", &arr[i]);
                }
                printf("Elements read successfully.\n");
                break;
            case 2:
                if (n == 0) {
                    printf("Please read elements first.\n");
                } else {
                    mergeSort(arr, 0, n - 1);
                    printf("Array sorted successfully.\n");
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 5

// ============================================================================
// QUESTION 6: Tree Assignment with following options
// Delete, Traversal without recursion Pre-order, exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    
    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);
        
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Delete\n2. Traversal without recursion Pre-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Data deleted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Pre-order traversal: ");
                    preorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 6

// ============================================================================
// QUESTION 7: Tree Assignment with following options
// Delete, Traversal without recursion In-order, exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;
    
    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Delete\n2. Traversal without recursion In-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Data deleted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 7

// ============================================================================
// QUESTION 8: Tree Assignment with following options
// Delete, Traversal without recursion Post-order, exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    
    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;
        
        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }
    
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
    printf("\n");
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Delete\n2. Traversal without recursion Post-order\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Data deleted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Post-order traversal: ");
                    postorderNonRecursive(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 8

// ============================================================================
// QUESTION 9: Binary Search assignment (Can include any sort to sort numbers)
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[100], n, key, i, result;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    result = binarySearch(arr, 0, n - 1, key);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    
    return 0;
}

#endif  // End of Question 9

// ============================================================================
// QUESTION 10: Implement BST with following functions
// 1. Insert, 2. Count nodes, 3. Display with any traversal
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Count nodes\n3. Display (In-order)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                printf("Total nodes: %d\n", countNodes(root));
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 10

// ============================================================================
// QUESTION 11: Implement BST with following functions
// 1. Insert, 2. Mirror Image, 3. Display with any traversal
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* mirror(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    
    struct Node* temp = root->left;
    root->left = mirror(root->right);
    root->right = mirror(temp);
    
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Mirror Image\n3. Display (In-order)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                root = mirror(root);
                printf("Tree mirrored successfully.\n");
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 11

// ============================================================================
// QUESTION 12: Implement BST with following functions
// 1. Insert, 2. Height of Tree, 3. Display with any traversal
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Height of Tree\n3. Display (In-order)\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                printf("Height of tree: %d\n", height(root));
                break;
            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 12

// ============================================================================
// QUESTION 13: Implement BST with following functions
// 1. Delete, 2. Count nodes, 3. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Delete\n2. Count nodes\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("Data deleted successfully.\n");
                break;
            case 2:
                printf("Total nodes: %d\n", countNodes(root));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 13

// ============================================================================
// QUESTION 14: Implementation of Cuckoo Hashing
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 11
#define MAX_ITERATIONS 50

struct HashTable {
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];
};

void initTable(struct HashTable* ht) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        ht->table1[i] = -1;
        ht->table2[i] = -1;
    }
}

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return (key / TABLE_SIZE) % TABLE_SIZE;
}

bool insert(struct HashTable* ht, int key) {
    int pos1 = hash1(key);
    int pos2 = hash2(key);
    
    if (ht->table1[pos1] == -1) {
        ht->table1[pos1] = key;
        return true;
    }
    
    if (ht->table2[pos2] == -1) {
        ht->table2[pos2] = key;
        return true;
    }
    
    int evicted = ht->table1[pos1];
    ht->table1[pos1] = key;
    key = evicted;
    
    int iterations = 0;
    bool useTable1 = false;
    
    while (iterations < MAX_ITERATIONS) {
        if (useTable1) {
            pos1 = hash1(key);
            if (ht->table1[pos1] == -1) {
                ht->table1[pos1] = key;
                return true;
            }
            evicted = ht->table1[pos1];
            ht->table1[pos1] = key;
            key = evicted;
        } else {
            pos2 = hash2(key);
            if (ht->table2[pos2] == -1) {
                ht->table2[pos2] = key;
                return true;
            }
            evicted = ht->table2[pos2];
            ht->table2[pos2] = key;
            key = evicted;
        }
        useTable1 = !useTable1;
        iterations++;
    }
    
    return false;
}

bool search(struct HashTable* ht, int key) {
    int pos1 = hash1(key);
    int pos2 = hash2(key);
    
    return (ht->table1[pos1] == key || ht->table2[pos2] == key);
}

void display(struct HashTable* ht) {
    int i;
    printf("Table 1: ");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (ht->table1[i] != -1) {
            printf("[%d] = %d  ", i, ht->table1[i]);
        }
    }
    printf("\nTable 2: ");
    for (i = 0; i < TABLE_SIZE; i++) {
        if (ht->table2[i] != -1) {
            printf("[%d] = %d  ", i, ht->table2[i]);
        }
    }
    printf("\n");
}

int main() {
    struct HashTable ht;
    initTable(&ht);
    int choice, key;
    
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if (insert(&ht, key)) {
                    printf("Key inserted successfully.\n");
                } else {
                    printf("Insertion failed. Table might be full or cycle detected.\n");
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(&ht, key)) {
                    printf("Key found.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                display(&ht);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 14

// ============================================================================
// QUESTION 15: Implementation of Matching Parenthesis problem
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = c;
    }
}

char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

int isMatchingPair(char opening, char closing) {
    if (opening == '(' && closing == ')') return 1;
    if (opening == '{' && closing == '}') return 1;
    if (opening == '[' && closing == ']') return 1;
    return 0;
}

int checkParenthesis(char* expression) {
    struct Stack s;
    initStack(&s);
    int i;
    
    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            push(&s, expression[i]);
        } else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (isEmpty(&s)) {
                return 0;
            }
            if (!isMatchingPair(pop(&s), expression[i])) {
                return 0;
            }
        }
    }
    
    return isEmpty(&s);
}

int main() {
    char expression[MAX];
    
    printf("Enter expression: ");
    scanf("%s", expression);
    
    if (checkParenthesis(expression)) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }
    
    return 0;
}

#endif  // End of Question 15

// ============================================================================
// QUESTION 16: AVL Tree – 1. Insert, 2. Display, 3. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }
    
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }
    
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;
    
    while (1) {
        printf("\n1. Insert\n2. Display (In-order)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Data inserted successfully.\n");
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("In-order traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 16

// ============================================================================
// QUESTION 17: Hashing - Linear Probing, Modulo 11 function, 2 slot
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define SLOT_SIZE 2

struct HashTable {
    int table[TABLE_SIZE][SLOT_SIZE];
    int count[TABLE_SIZE];
};

void initTable(struct HashTable* ht) {
    int i, j;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < SLOT_SIZE; j++) {
            ht->table[i][j] = -1;
        }
        ht->count[i] = 0;
    }
}

int hashFunction(int key) {
    return key % 11;
}

int insert(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int i;
    
    if (ht->count[index] < SLOT_SIZE) {
        for (i = 0; i < SLOT_SIZE; i++) {
            if (ht->table[index][i] == -1) {
                ht->table[index][i] = key;
                ht->count[index]++;
                return 1;
            }
        }
    }
    
    int originalIndex = index;
    index = (index + 1) % TABLE_SIZE;
    
    while (index != originalIndex) {
        if (ht->count[index] < SLOT_SIZE) {
            for (i = 0; i < SLOT_SIZE; i++) {
                if (ht->table[index][i] == -1) {
                    ht->table[index][i] = key;
                    ht->count[index]++;
                    return 1;
                }
            }
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    return 0;
}

int search(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int i;
    
    for (i = 0; i < SLOT_SIZE; i++) {
        if (ht->table[index][i] == key) {
            return 1;
        }
    }
    
    int originalIndex = index;
    index = (index + 1) % TABLE_SIZE;
    
    while (index != originalIndex) {
        for (i = 0; i < SLOT_SIZE; i++) {
            if (ht->table[index][i] == key) {
                return 1;
            }
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    return 0;
}

void display(struct HashTable* ht) {
    int i, j;
    printf("Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        for (j = 0; j < SLOT_SIZE; j++) {
            if (ht->table[i][j] != -1) {
                printf("%d ", ht->table[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct HashTable ht;
    initTable(&ht);
    int choice, key;
    
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if (insert(&ht, key)) {
                    printf("Key inserted successfully.\n");
                } else {
                    printf("Insertion failed. Table is full.\n");
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(&ht, key)) {
                    printf("Key found.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                display(&ht);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 17

// ============================================================================
// QUESTION 18: Hashing - Linear Probing, Modulo 12 function, 3 slot
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 12
#define SLOT_SIZE 3

struct HashTable {
    int table[TABLE_SIZE][SLOT_SIZE];
    int count[TABLE_SIZE];
};

void initTable(struct HashTable* ht) {
    int i, j;
    for (i = 0; i < TABLE_SIZE; i++) {
        for (j = 0; j < SLOT_SIZE; j++) {
            ht->table[i][j] = -1;
        }
        ht->count[i] = 0;
    }
}

int hashFunction(int key) {
    return key % 12;
}

int insert(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int i;
    
    if (ht->count[index] < SLOT_SIZE) {
        for (i = 0; i < SLOT_SIZE; i++) {
            if (ht->table[index][i] == -1) {
                ht->table[index][i] = key;
                ht->count[index]++;
                return 1;
            }
        }
    }
    
    int originalIndex = index;
    index = (index + 1) % TABLE_SIZE;
    
    while (index != originalIndex) {
        if (ht->count[index] < SLOT_SIZE) {
            for (i = 0; i < SLOT_SIZE; i++) {
                if (ht->table[index][i] == -1) {
                    ht->table[index][i] = key;
                    ht->count[index]++;
                    return 1;
                }
            }
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    return 0;
}

int search(struct HashTable* ht, int key) {
    int index = hashFunction(key);
    int i;
    
    for (i = 0; i < SLOT_SIZE; i++) {
        if (ht->table[index][i] == key) {
            return 1;
        }
    }
    
    int originalIndex = index;
    index = (index + 1) % TABLE_SIZE;
    
    while (index != originalIndex) {
        for (i = 0; i < SLOT_SIZE; i++) {
            if (ht->table[index][i] == key) {
                return 1;
            }
        }
        index = (index + 1) % TABLE_SIZE;
    }
    
    return 0;
}

void display(struct HashTable* ht) {
    int i, j;
    printf("Hash Table:\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        for (j = 0; j < SLOT_SIZE; j++) {
            if (ht->table[i][j] != -1) {
                printf("%d ", ht->table[i][j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct HashTable ht;
    initTable(&ht);
    int choice, key;
    
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                if (insert(&ht, key)) {
                    printf("Key inserted successfully.\n");
                } else {
                    printf("Insertion failed. Table is full.\n");
                }
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(&ht, key)) {
                    printf("Key found.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                display(&ht);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 18

// ============================================================================
// QUESTION 19: Conversion of Infix to Postfix
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Stack {
    char arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++s->top] = c;
    }
}

char pop(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top--];
    }
    return '\0';
}

char peek(struct Stack* s) {
    if (!isEmpty(s)) {
        return s->arr[s->top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    initStack(&s);
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

#endif  // End of Question 19

// ============================================================================
// QUESTION 20: Graph Traversal - 1. Read Graph, 2. BFS, 3. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int data) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

int adj[MAX][MAX];
int visited[MAX];
int n;

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Graph read successfully.\n");
}

void BFS(int start) {
    struct Queue q;
    initQueue(&q);
    int i;
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    visited[start] = 1;
    enqueue(&q, start);
    
    printf("BFS traversal: ");
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        
        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int choice, start;
    
    while (1) {
        printf("\n1. Read Graph\n2. BFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 20

/*
 * C Programming Questions and Answers (21-40)
 * Each question is followed by its complete, standalone code solution
 * Each answer is independent with its own required libraries and main function
 * 
 * INSTRUCTIONS: To compile a specific question, uncomment the corresponding
 * #if 0 and change it to #if 1, and comment out all other solutions.
 * Only ONE solution should be active at a time (change #if 0 to #if 1).
 */

// ============================================================================
// QUESTION 21: Graph Traversal - 1. Read Graph, 2. DFS, 3. Exit
// ============================================================================

#if 1  // Change to #if 0 to disable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Graph read successfully.\n");
}

void DFS(int start) {
    int i;
    visited[start] = 1;
    printf("%d ", start);
    
    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int choice, start;
    
    while (1) {
        printf("\n1. Read Graph\n2. DFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                printf("DFS traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 21

// ============================================================================
// QUESTION 22: Singly Linked list with following options
// 1. Insert from Front, 2. Delete from Front, 3. Display list, 4. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Element inserted at front successfully.\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Element deleted from front successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from Front\n2. Delete from Front\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 22

// ============================================================================
// QUESTION 23: Singly Linked list with following options
// 1. Insert from End, 2. Delete from End, 3. Display list, 4. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Element inserted at end successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
    printf("Element deleted from end successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from End\n2. Delete from End\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 23

// ============================================================================
// QUESTION 24: Singly Linked list with following options
// 1. Insert from Front, 2. Delete at given position, 3. Display list, 4. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Element inserted at front successfully.\n");
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Element deleted at position %d successfully.\n", pos);
        return;
    }
    
    struct Node* current = head;
    int i;
    for (i = 1; i < pos - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Position out of range.\n");
        return;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Element deleted at position %d successfully.\n", pos);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data, pos;
    
    while (1) {
        printf("\n1. Insert from Front\n2. Delete at given position\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 24

// ============================================================================
// QUESTION 25: Conversion of Postfix to Infix
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Stack {
    char arr[MAX][MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, char* str) {
    if (s->top < MAX - 1) {
        strcpy(s->arr[++s->top], str);
    }
}

void pop(struct Stack* s, char* str) {
    if (!isEmpty(s)) {
        strcpy(str, s->arr[s->top--]);
    } else {
        str[0] = '\0';
    }
}

void postfixToInfix(char* postfix, char* infix) {
    struct Stack s;
    initStack(&s);
    int i;
    char op1[MAX], op2[MAX], temp[MAX];
    
    for (i = 0; postfix[i] != '\0'; i++) {
        if ((postfix[i] >= 'a' && postfix[i] <= 'z') || (postfix[i] >= 'A' && postfix[i] <= 'Z') || (postfix[i] >= '0' && postfix[i] <= '9')) {
            char operand[2];
            operand[0] = postfix[i];
            operand[1] = '\0';
            push(&s, operand);
        } else {
            pop(&s, op2);
            pop(&s, op1);
            
            temp[0] = '(';
            temp[1] = '\0';
            strcat(temp, op1);
            char op[2];
            op[0] = postfix[i];
            op[1] = '\0';
            strcat(temp, op);
            strcat(temp, op2);
            strcat(temp, ")");
            
            push(&s, temp);
        }
    }
    
    pop(&s, infix);
}

int main() {
    char postfix[MAX], infix[MAX];
    
    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    
    postfixToInfix(postfix, infix);
    
    printf("Infix expression: %s\n", infix);
    
    return 0;
}

#endif  // End of Question 25

// ============================================================================
// QUESTION 26: Implement Doubly linked list to
// 1. Insert node, 2. Find nodes having even numbers
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted successfully.\n");
}

void findEvenNumbers() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    printf("Nodes with even numbers: ");
    int found = 0;
    
    while (current != NULL) {
        if (current->data % 2 == 0) {
            printf("%d ", current->data);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No even numbers found.");
    }
    printf("\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert node\n2. Find nodes having even numbers\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                findEvenNumbers();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 26

// ============================================================================
// QUESTION 27: Implementation of Circular Queue – Insert, Display, delete
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct CircularQueue {
    int arr[MAX];
    int front, rear;
    int size;
};

void initQueue(struct CircularQueue* q, int size) {
    q->front = q->rear = -1;
    q->size = size;
}

int isEmpty(struct CircularQueue* q) {
    return q->front == -1;
}

int isFull(struct CircularQueue* q) {
    return (q->rear + 1) % q->size == q->front;
}

void enqueue(struct CircularQueue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    
    q->arr[q->rear] = data;
    printf("Element inserted successfully.\n");
}

int dequeue(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }
    
    int data = q->arr[q->front];
    
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    
    return data;
}

void display(struct CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main() {
    struct CircularQueue q;
    int size, choice, data;
    
    printf("Enter size of queue: ");
    scanf("%d", &size);
    initQueue(&q, size);
    
    while (1) {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2:
                display(&q);
                break;
            case 3:
                data = dequeue(&q);
                if (data != -1) {
                    printf("Deleted element: %d\n", data);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 27

// ============================================================================
// QUESTION 28: Reversing Stack using Queue
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

int isStackFull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, int data) {
    if (isStackFull(s)) {
        printf("Stack is full.\n");
        return;
    }
    s->arr[++s->top] = data;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int data) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

void displayStack(struct Stack* s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    int i;
    for (i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void reverseStack(struct Stack* s) {
    struct Queue q;
    initQueue(&q);
    
    while (!isStackEmpty(s)) {
        enqueue(&q, pop(s));
    }
    
    while (!isEmpty(&q)) {
        push(s, dequeue(&q));
    }
    
    printf("Stack reversed successfully.\n");
}

int main() {
    struct Stack s;
    initStack(&s);
    int choice, data;
    
    while (1) {
        printf("\n1. Push\n2. Display\n3. Reverse Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&s, data);
                break;
            case 2:
                displayStack(&s);
                break;
            case 3:
                reverseStack(&s);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 28

// ============================================================================
// QUESTION 29: Implement Doubly linked list to Swap first and last node
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted successfully.\n");
}

void swapFirstLast() {
    if (head == NULL || head->next == NULL) {
        printf("List has less than 2 nodes. Cannot swap.\n");
        return;
    }
    
    struct Node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    if (head == last) {
        printf("Only one node in list.\n");
        return;
    }
    
    int temp = head->data;
    head->data = last->data;
    last->data = temp;
    
    printf("First and last nodes swapped successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert node\n2. Swap first and last node\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertNode(data);
                break;
            case 2:
                swapFirstLast();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 29

// ============================================================================
// QUESTION 30: Implement BFS on Graph
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int data) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = data;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1;
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return data;
}

int adj[MAX][MAX];
int visited[MAX];
int n;

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Graph read successfully.\n");
}

void BFS(int start) {
    struct Queue q;
    initQueue(&q);
    int i;
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    visited[start] = 1;
    enqueue(&q, start);
    
    printf("BFS traversal: ");
    
    while (!isEmpty(&q)) {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        
        for (i = 0; i < n; i++) {
            if (adj[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int choice, start;
    
    while (1) {
        printf("\n1. Read Graph\n2. BFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 30

// ============================================================================
// QUESTION 31: Doubly Linked list with following options
// 1. Insert from Front, 2. Delete from end
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Element inserted at front successfully.\n");
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->prev->next = NULL;
        free(current);
    }
    printf("Element deleted from end successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from Front\n2. Delete from end\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                deleteEnd();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 31

// ============================================================================
// QUESTION 32: Doubly Linked list with following options
// 1. Insert from End, 2. Delete from front
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Element inserted at end successfully.\n");
}

void deleteFront() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Element deleted from front successfully.\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from End\n2. Delete from front\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 32

// ============================================================================
// QUESTION 35: Doubly Linked list with following options
// 1. Insert from Front, 2. Delete nodes having even numbers
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Element inserted at front successfully.\n");
}

void deleteEvenNumbers() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    int deleted = 0;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        if (current->data % 2 == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            free(current);
            deleted++;
        }
        
        current = next;
    }
    
    if (deleted > 0) {
        printf("Deleted %d node(s) with even numbers.\n", deleted);
    } else {
        printf("No even numbers found to delete.\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from Front\n2. Delete nodes having even numbers\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                deleteEvenNumbers();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 35

// ============================================================================
// QUESTION 36: Doubly Linked list with following options
// 1. Insert from End, 2. Delete nodes having odd numbers
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    printf("Element inserted at end successfully.\n");
}

void deleteOddNumbers() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    int deleted = 0;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        if (current->data % 2 != 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            free(current);
            deleted++;
        }
        
        current = next;
    }
    
    if (deleted > 0) {
        printf("Deleted %d node(s) with odd numbers.\n", deleted);
    } else {
        printf("No odd numbers found to delete.\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from End\n2. Delete nodes having odd numbers\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 2:
                deleteOddNumbers();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 36

// ============================================================================
// QUESTION 37: Doubly Linked list with following options
// 1. Insert from Front, 2. Delete nodes having numbers divisible by 3
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertFront(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Element inserted at front successfully.\n");
}

void deleteDivisibleBy3() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* current = head;
    int deleted = 0;
    
    while (current != NULL) {
        struct Node* next = current->next;
        
        if (current->data % 3 == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            
            free(current);
            deleted++;
        }
        
        current = next;
    }
    
    if (deleted > 0) {
        printf("Deleted %d node(s) with numbers divisible by 3.\n", deleted);
    } else {
        printf("No numbers divisible by 3 found to delete.\n");
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        printf("\n1. Insert from Front\n2. Delete nodes having numbers divisible by 3\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                deleteDivisibleBy3();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 37

// ============================================================================
// QUESTION 38: Graph Traversal - 1. Read Graph, 2. DFS, 3. Exit
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    printf("Graph read successfully.\n");
}

void DFS(int start) {
    int i;
    visited[start] = 1;
    printf("%d ", start);
    
    for (i = 0; i < n; i++) {
        if (adj[start][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    int choice, start;
    
    while (1) {
        printf("\n1. Read Graph\n2. DFS\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                for (int i = 0; i < n; i++) {
                    visited[i] = 0;
                }
                printf("DFS traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 38

// ============================================================================
// QUESTION 39: Graph - Shortest Path Finding using Dijkstra's algorithm
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n;
int graph[MAX][MAX];

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix (use 0 for no edge, weight for edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }
    
    printf("Graph read successfully.\n");
}

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index, v;
    
    for (v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void dijkstra(int src) {
    int dist[MAX];
    int sptSet[MAX];
    int i, count, v;
    
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;
    
    for (count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        
        for (v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d: INF\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int choice, src;
    
    while (1) {
        printf("\n1. Read Graph\n2. Dijkstra's Algorithm\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                dijkstra(src);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 39

// ============================================================================
// QUESTION 40: Graph - Shortest Path Finding using Dijkstra's algorithm
// ============================================================================

#if 0  // Change to #if 1 to enable this solution

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int n;
int graph[MAX][MAX];

void readGraph() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix (use 0 for no edge, weight for edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }
    
    printf("Graph read successfully.\n");
}

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index, v;
    
    for (v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void dijkstra(int src) {
    int dist[MAX];
    int sptSet[MAX];
    int i, count, v;
    
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;
    
    for (count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        
        for (v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && 
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printf("Shortest distances from vertex %d:\n", src);
    for (i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Vertex %d: INF\n", i);
        } else {
            printf("Vertex %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int choice, src;
    
    while (1) {
        printf("\n1. Read Graph\n2. Dijkstra's Algorithm\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                readGraph();
                break;
            case 2:
                printf("Enter source vertex: ");
                scanf("%d", &src);
                dijkstra(src);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#endif  // End of Question 40
// ============================================================================