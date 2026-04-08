#include <stdio.h>


typedef struct {
    int max;
    int min;
    int valid; // 0 if array was empty, otherwise 1
} Result;

Result find_max_min(int arr[], int len) {
    Result r = {0, 0, 0};
    
    if (len == 0) {
        return r;
    }

    r.max = arr[0];
    r.min = arr[0];
    r.valid = 1;
    
    for (int i = 1; i < len; i++) {
        if (arr[i] > r.max) {
            r.max = arr[i];
        }
        if (arr[i] < r.min) {
            r.min = arr[i];
        }
    }
    return r;
}

void run_test(char *label, int arr[], int len) {
    printf("Test: %s\n", label);

    if (len == 0) {
        printf(" Array: []\n");
    } else {
        printf(" Array: [");
        for (int i = 0; i < len; i ++) {
            printf("%d", arr[i]);
            if(i < len -1) printf(", ");
        }
        printf("]\n");  
    }
    Result r = find_max_min(arr, len);

    if (!r.valid) {
        printf(" Result: Array is empty, no max or min.\n");
    } else {
        printf(" Result: Max = %d, Min = %d\n", r.max, r.min);
    }
    printf("\n");
}

int main (void) {
    // Base case
    int a[] = {3, 1, 7, 2, 9, 4};
    int size_of_a = sizeof(a) / sizeof(a[0]);
    run_test("Stardard assorted array", a, size_of_a);

    // single element array
    int b[] = {42};
    int size_of_b = sizeof(b) / sizeof(b[0]);
    run_test("Single element array", b, size_of_b);

    // Null array
    run_test("Empty array", NULL, 0);

    // all elements identical
    int c[] = {5, 5, 5, 5};
    int size_of_c = sizeof(c) / sizeof(c[0]);
    run_test("All elements identical", c, size_of_c);

    // all negative elements
    int d[] = {-3, -1, -7, -2, -9};
    int size_of_d = sizeof(d) / sizeof(d[0]);
    run_test("All negative elements", d, size_of_d);

    // already sorted in ascending order
    int e[] = {1, 2, 3, 4, 5};
    int size_of_e = sizeof(e) / sizeof(e[0]);
    run_test("Already sorted ascending", e, size_of_e);

    // Already sorted in descending order
    int f[] = {5, 4, 3, 2, 1};
    int size_of_f = sizeof(f) / sizeof(f[0]);
    run_test("Already sorted descending", f, size_of_f);

    //Max and min at the same position (impossible by definition, but mix of extremes)
    int g[] = {100, -100};
    int size_of_g = sizeof(g) / sizeof(g[0]);
    run_test("two elements -- extreme spread", g, size_of_g);

}

