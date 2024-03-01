#include <iostream>
#include <cstdlib>
#include <ctime>

template<typename T>
void printArray(T* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
int partition(T* arr, int start, int end) {
    T pivot = arr[end];
    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[end]);
    return i + 1;
}

template<typename T>
int randomPartition(T* arr, int start, int end) {
    srand(time(0));
    int randomIndex = start + rand() % (end - start);
    std::swap(arr[randomIndex], arr[end]);
    return partition(arr, start, end);
}

template<typename T>
void quickSort(T* arr, int start, int end) {
    if (start < end) {
        int partitionIndex = randomPartition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

template<typename T>
T* generateRandomNumbers(int n) {
    srand(time(0));
    T* numbers = new T[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = rand() % 10000 + 1;
    }

    return numbers;
}

int main()
{
    int length = 100;
    int* array = generateRandomNumbers<int>(length);
    printArray(array, length);
    quickSort(array, 0, length - 1);
    printArray(array, length);
    delete[] array;
}