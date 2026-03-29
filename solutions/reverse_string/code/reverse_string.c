#include <stdio.h>

// Challenge 1 — Reverse an Array In-Place
// Difficulty: Easy
// Approach: Two-pointer swap
// - left  starts at index 0
// - right starts at last index (len - 1)
// - Swap arr[left] and arr[right], then move both pointers inward
// - Stop when left >= right (pointers meet or cross)
// time  : O(n) — each element visited at most once
// Space : O(1) — only two pointer variables, no extra array
 


void reverse_array(int *arr, int len) {
    // Edge case: empty array or single element -nothing to reverse in that case
    if(len<=1) return;

    int left  = 0;
    int right = len -1;

    while (left < right){
        // swap using a temporary variable
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left ++;
        right --;
    }
}

// helper to print the array
void print_array(int *arr, int len) {
    if (len == 0){
        printf("[]");
        return;
    }
    printf("[");
    for (int i = 0;i < len; i++){
        printf("%d", arr[i]);
        if (i < len -1) printf(", ");
    }
    printf("]\n");
}

int main(void) {

    //  Test 1: standard odd-length array
    int arr1[] = {1, 2, 3, 4, 5};
    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Before: "); print_array(arr1, len1);
    reverse_array(arr1, len1);
    printf("After : "); print_array(arr1, len1);
    printf("\n");
 
    // Test 2: even-length array
    int arr2[]= {10, 20, 30, 40};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Before: "); print_array(arr2, len2);
    reverse_array(arr2, len2);
    printf("After : "); print_array(arr2, len2);
    printf("\n");
 
    // Test 3: single element — should be unchanged 
    int arr3[]  = {42};
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Before: "); print_array(arr3, len3);
    reverse_array(arr3, len3);
    printf("After : "); print_array(arr3, len3);
    printf("\n");
 
    // Test 4: empty array — should not crash
    int *arr4 = NULL;
    int len4 = 0;
    printf("Before: "); print_array(arr4, len4);
    reverse_array(arr4, len4);
    printf("After : "); print_array(arr4, len4);
    printf("\n");
 
    // Test 5: two elements
    int arr5[]= {7, 3};
    int len5 = sizeof(arr5) / sizeof(arr5[0]);
    printf("Before: "); print_array(arr5, len5);
    reverse_array(arr5, len5);
    printf("After : "); print_array(arr5, len5);
 
    return 0;   
}