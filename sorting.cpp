#include "sorting.h"

void insertionSort(std::vector<int>& A) {
    int n = static_cast<int>(A.size());
    for (int i = 1; i < n; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = v;
    }
}

static void merge(std::vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = A[left + i];
    for (int j = 0; j < n2; ++j) R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        }
        else {
            A[k++] = R[j++];
        }
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

void mergeSort(std::vector<int>& A, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}