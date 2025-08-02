#include <iostream>
#include <cmath>
using namespace std;

// Get digit at a given position (0 = LSD)
int GetDigit(int number, int digit) {
    return (number / static_cast<int>(pow(10, digit))) % 10;
}

// Find maximum value in array
int FindMaxValue(int* A, int n) {
    int maxVal = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxVal) maxVal = A[i];
    }
    return maxVal;
}

// Perform counting sort on a specific digit
void CountingSortByDigit(int* from, int* to, int n, int digit) {
    const int base = 10;
    int count[base] = {0};

    // Count digit frequencies
    for (int i = 0; i < n; i++) {
        int d = GetDigit(from[i], digit);
        count[d]++;
    }

    // Compute prefix sums
    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    // Stable placement into 'to' array
    for (int i = n - 1; i >= 0; i--) {
        int d = GetDigit(from[i], digit);
        to[--count[d]] = from[i];
    }
}

// Optimized Radix Sort (d + 1 passes)
void RadixSort(int* A, int n) {
    int* B = new int[n];
    int* from = A;
    int* to = B;

    // Determine number of digits (d)
    int maxVal = FindMaxValue(A, n);
    int maxDigits = 0;
    while (maxVal > 0) {
        maxVal /= 10;
        maxDigits++;
    }

    // Do counting sort for each digit
    for (int d = 0; d < maxDigits; d++) {
        CountingSortByDigit(from, to, n, d);
        swap(from, to); // swap pointers
    }

    // Final copy if result is not in original array
    if (from != A) {
        for (int i = 0; i < n; i++)
            A[i] = from[i];
    }

    delete[] B;
}

// Debug print
void PrintArray(int* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "]\n";
}

// Test
int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Before sorting:\n";
    PrintArray(A, n);

    RadixSort(A, n);

    cout << "After sorting:\n";
    PrintArray(A, n);
    return 0;
}
