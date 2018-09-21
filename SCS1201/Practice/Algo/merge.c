#include <stdio.h>

int merge(int arr[], int l, int m, int r) {
    int i, j;

    int nl = m - l + 1;
    int nr = r - m;

    int L[nl], R[nr];

    for (i = 0; i < nl; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < nr; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = j = 0;
    int a = l;

    while (i < nl && j < nr) {
        if (L[i] < R[j]) {
            arr[a] = L[i];
            i++;
        } else {
            arr[a] = R[j];
            j++;
        }
        a++;
    }

    while (i < nr) {
        arr[a] = L[i];
        i++;
        a++;
    }

    while (j < nr) {
        arr[a] = R[j];
        j++;
        a++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l+r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int x[8] = {60, 30, 20, 10, 40, 25, 70, 80};

    mergeSort(x, 0, 7);

    int i = 0;
    for (; i < 8; i++) {
        printf("%d\n", x[i]);
    }
}