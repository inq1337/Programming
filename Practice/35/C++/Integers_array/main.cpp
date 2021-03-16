#include <iostream>

struct IntArray {
  int *data;
  int size;
};

void create(IntArray& arr, int size) {
    arr.data = new int[size];
    arr.size = size;
}

void create(IntArray* arr, int size) {
    arr->data = new int[size];
    arr->size = size;
}

int get(IntArray& arr, int index) {
    if (index < 0 or index >= arr.size) {
        std::cerr << "The index is outside the array" << std::endl;
        exit(1);
    }
    return arr.data[index];
}

int get(IntArray* arr, int index) {
    if (index < 0 or index >= arr->size) {
        std::cerr << "The index is outside the array" << std::endl;
        exit(1);
    }
    return arr->data[index];
}

void set(IntArray& arr, int index, int value) {
    if (index < 0 or index >= arr.size) {
        std::cerr << "The index is outside the array" << std::endl;
        exit(1);
    }
    arr.data[index] = value;
}

void set(IntArray* arr, int index, int value) {
    if (index < 0 or index >= arr->size) {
        std::cerr << "The index is outside the array" << std::endl;
        exit(1);
    }
    arr->data[index] = value;
}

void print(IntArray& arr)
{
    std::cout << "[";
    for (int i = 0; i < arr.size - 1; i++)
    {
        std::cout << arr.data[i] << ", ";
    }
    std::cout << arr.data[arr.size - 1] << "]";
}

void print(IntArray* arr)
{
    std::cout << "[";
    for (int i = 0; i < arr->size - 1; i++)
    {
        std::cout << arr->data[i] << ", ";
    }
    std::cout << arr->data[arr->size - 1] << "]";
}

void resize(IntArray& arr, int newSize) {
    if (newSize > arr.size) {
        int* newArr = new int[newSize];

        for (int i = 0; i < arr.size; ++i) {
            newArr[i] = arr.data[i];
        }
        for (int i = arr.size; i < newSize; ++i) {
            newArr[i] = 0;
        }

        delete[] arr.data;
        arr.data = newArr;
        arr.size = newSize;
    }
    else {
        int* newArr = new int[newSize];

        for (int i = 0; i < newSize; ++i) {
            newArr[i] = arr.data[i];
        }

        delete[] arr.data;
        arr.data = newArr;
        arr.size = newSize;
    }
}

void resize(IntArray* arr, int newSize) {
    if (newSize > arr->size) {
        int* newArr = new int[newSize];

        for (int i = 0; i < arr->size; ++i) {
            newArr[i] = arr->data[i];
        }
        for (int i = arr->size; i < newSize; ++i) {
            newArr[i] = 0;
        }

        delete[] arr->data;
        arr->data = newArr;
        arr->size = newSize;
    }
    else {
        int* newArr = new int[newSize];

        for (int i = 0; i < newSize; ++i) {
            newArr[i] = arr->data[i];
        }

        delete[] arr->data;
        arr->data = newArr;
        arr->size = newSize;
    }
}

void destroy(IntArray& arr) {
    if (!arr.data) {
        return;
    }

    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
}

void destroy(IntArray* arr) {
    if (!arr->data) {
        return;
    }

    delete[] arr->data;
    arr->data = nullptr;
    arr->size = 0;
}

int main() {
    IntArray arr;
    create(arr, 30);

    for (int i = 0; i < 30; i++) {
        set(arr, i, i + 1);
    }

    print(arr);
    resize(arr, 50);
    print(arr);
    resize(arr, 10);
    print(arr);
    destroy(arr);
}
