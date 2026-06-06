/*
 * ============================================================
 * Problem: Dynamic Array (Manual Implementation)
 * Topic:   Arrays / Memory Management
 * ============================================================
 *
 * Problem Statement:
 *   Implement a dynamic array from scratch in C++ without using
 *   std::vector. The array should automatically double its capacity
 *   whenever it runs out of space, similar to how std::vector works
 *   internally.
 *
 * Operations implemented:
 *   - pushBack(value) : append an element; resize if needed
 *   - printArray()    : print all elements
 *
 * Example:
 *   Input:  pushBack(1), pushBack(2), pushBack(3)
 *   Output: Elements: 1 2 3  |  Size: 3  |  Capacity: 4
 *
 * ============================================================
 * Approach: Amortized Doubling
 *
 *   Start with capacity = 1. When size reaches capacity, allocate
 *   a new array of double the capacity, copy all elements over,
 *   and free the old memory. This ensures that each element is
 *   copied at most O(log n) times on average across all insertions.
 *
 * Time  Complexity: O(1) amortized per pushBack (O(n) worst-case per resize)
 * Space Complexity: O(n) — at most 2x the number of stored elements
 * ============================================================
 */

#include <iostream>
#include <cassert>
using namespace std;

// -------------------------------------------------------------------
// resize: doubles the capacity of the array and migrates all elements
// Parameters:
//   arr      - reference to the raw pointer (updated to new memory)
//   size     - current number of valid elements (needed for copying)
//   capacity - current capacity (doubled in-place)
// -------------------------------------------------------------------
void resize(int*& arr, int size, int& capacity) {
    capacity *= 2;

    int* newArr = new int[capacity];

    // Copy existing elements to the new, larger array
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;   // Free old memory to prevent leaks
    arr = newArr;
}

// -------------------------------------------------------------------
// pushBack: appends a value to the array; triggers resize if full
// -------------------------------------------------------------------
void pushBack(int*& arr, int& size, int& capacity, int value) {
    if (size == capacity) {
        resize(arr, size, capacity);   // Expand before writing
    }
    arr[size] = value;
    size++;
}

// -------------------------------------------------------------------
// printArray: prints all elements, size, and current capacity
// -------------------------------------------------------------------
void printArray(int* arr, int size, int capacity) {
    cout << "Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << "  |  Size: " << size
         << "  |  Capacity: " << capacity << "\n";
}

// -------------------------------------------------------------------
// Test Cases
// -------------------------------------------------------------------
void runTests() {
    // --- Test 1: Single element ---
    {
        int capacity = 1, size = 0;
        int* arr = new int[capacity];

        pushBack(arr, size, capacity, 42);

        assert(size == 1);
        assert(arr[0] == 42);
        assert(capacity == 1);  // No resize needed yet

        delete[] arr;
        cout << "Test 1 Passed: Single element insert\n";
    }

    // --- Test 2: Resize triggered (capacity doubling) ---
    {
        int capacity = 1, size = 0;
        int* arr = new int[capacity];

        pushBack(arr, size, capacity, 1);  // capacity stays 1, size = 1
        pushBack(arr, size, capacity, 2);  // triggers resize -> capacity = 2
        pushBack(arr, size, capacity, 3);  // triggers resize -> capacity = 4

        assert(size == 3);
        assert(arr[0] == 1);
        assert(arr[1] == 2);
        assert(arr[2] == 3);
        assert(capacity == 4);  // Doubled twice: 1 -> 2 -> 4

        delete[] arr;
        cout << "Test 2 Passed: Capacity doubling on overflow\n";
    }

    // --- Test 3: Multiple resizes with correct element preservation ---
    {
        int capacity = 1, size = 0;
        int* arr = new int[capacity];

        for (int i = 1; i <= 8; i++) {
            pushBack(arr, size, capacity, i);
        }

        assert(size == 8);
        assert(capacity == 8);  // 1 -> 2 -> 4 -> 8

        for (int i = 0; i < size; i++) {
            assert(arr[i] == i + 1);  // All elements must survive resizes
        }

        delete[] arr;
        cout << "Test 3 Passed: All elements preserved across multiple resizes\n";
    }

    // --- Test 4: Edge case — empty array ---
    {
        int capacity = 1, size = 0;
        int* arr = new int[capacity];

        assert(size == 0);
        assert(capacity == 1);

        delete[] arr;
        cout << "Test 4 Passed: Empty array initialisation\n";
    }
}

// -------------------------------------------------------------------
// Main
// -------------------------------------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Run all tests
    runTests();
    cout << "\nAll tests passed!\n\n";

    // Demo: show the array state after a sequence of inserts
    int capacity = 1, size = 0;
    int* arr = new int[capacity];

    pushBack(arr, size, capacity, 10);
    pushBack(arr, size, capacity, 20);
    pushBack(arr, size, capacity, 30);
    pushBack(arr, size, capacity, 40);
    pushBack(arr, size, capacity, 50);

    cout << "Demo output after 5 inserts:\n";
    printArray(arr, size, capacity);

    delete[] arr;
    return 0;
}
