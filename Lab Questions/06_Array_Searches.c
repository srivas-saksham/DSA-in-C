#include <stdio.h>

#define MAX_SIZE 100  // Define a maximum size for safety

int arrLen;

void arrPrint(int arr[]) {
    printf("\n");
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrInsert(int arr[], int num, int pos) {
    if (pos < 1 || pos > arrLen + 1) {
        printf("Invalid position!\n");
        return;
    }

    if (arrLen >= MAX_SIZE) {
        printf("Array is full! Cannot insert.\n");
        return;
    }

    for (int i = arrLen; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = num;
    arrLen++;

    printf("Updated Array: ");
    arrPrint(arr);
}

void arrDelete(int arr[], int pos) {
    if (pos < 1 || pos > arrLen) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos - 1; i < arrLen - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrLen--;

    printf("Updated Array: ");
    arrPrint(arr);
}

void arrSearchDel(int arr[], int num) {
    int pos = -1;
    for (int i = 0; i < arrLen; i++) {
        if (arr[i] == num) {
            pos = i + 1;
            break;
        }
    }

    if (pos == -1) {
        printf("Element not found!\n");
        return;
    }

    arrDelete(arr, pos);
}

void arrBiSearch(int arr[], int num) {
    int low = 0, high = arrLen - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == num) {
            printf("Element found at Position: %d\n", mid + 1);
            return;
        } else if (arr[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Element not found!\n");
}

// Function to remove duplicates
void arrElmDup(int arr[]) {
    for (int i = 0; i < arrLen; i++) {
        for (int j = i + 1; j < arrLen; ) {
            if (arr[i] == arr[j]) {
                arrDelete(arr, j + 1);
            } else {
                j++;  // Only increment when no deletion occurs
            }
        }
    }

    printf("Updated Array: ");
    arrPrint(arr);
}

// Function to sort the array (needed for binary search)
void arrSort(int arr[]) {
    for (int i = 0; i < arrLen - 1; i++) {
        for (int j = i + 1; j < arrLen; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted Array: ");
    arrPrint(arr);
}

int main() {
    int arr[MAX_SIZE], choice, num, pos;

    printf("Enter Number of Elements in Array: ");
    scanf("%d", &arrLen);

    if (arrLen > MAX_SIZE) {
        printf("Array size exceeds limit!\n");
        return 1;
    }

    for (int i = 0; i < arrLen; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n---- MENU ----\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Search & Delete Element\n");
        printf("4. Sort Array\n");
        printf("5. Binary Search\n");
        printf("6. Remove Duplicates\n");
        printf("7. Display Array\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &num);
                printf("Enter position: ");
                scanf("%d", &pos);
                arrInsert(arr, num, pos);
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                arrDelete(arr, pos);
                break;

            case 3:
                printf("Enter element to search and delete: ");
                scanf("%d", &num);
                arrSearchDel(arr, num);
                break;

            case 4:
                arrSort(arr);
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &num);
                arrBiSearch(arr, num);
                break;

            case 6:
                arrElmDup(arr);
                break;

            case 7:
                arrPrint(arr);
                break;

            case 8:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
