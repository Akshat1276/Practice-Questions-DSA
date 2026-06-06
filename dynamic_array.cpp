#include <iostream>

using namespace std;

void resize(int*& arr, int& capacity) {
    capacity *= 2;
    int* newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

int main() {
    int capacity = 1;
    int size = 0;
    int* arr = new int[capacity];
    if (size == capacity)
        resize(arr, capacity);
    arr[size] = 1;
    size++;
    if (size == capacity)
        resize(arr, capacity);
    arr[size] = 2;
    size++;
    if (size == capacity)
        resize(arr, capacity);
    arr[size] = 3;
    size++;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cout << size << "\n";
    cout << capacity << "\n";
    delete[] arr;
}
