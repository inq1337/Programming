#include <iostream>

void create (int **arr, int size, int a0 = 0, int d = 0) {
    *arr = new int[size];
    (*arr)[0] = a0;

    for (int i = 1; i < size; ++i) {
        (*arr)[i] = (*arr)[i-1] + d;
    }
}

int *sort(int *arr, int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = arr[i];
      j = i;
      while(j > 0 and arr[j-1]>key) {
         arr[j] = arr[j-1];
         j--;
      }
      arr[j] = key;
   }

   return arr;
}

int *print (int *arr, int size) {
    std::cout << "[";
    for (int i = 0; i < size - 1; ++i) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size-1] << "]";

    return  arr;
}

void destroy(int **arr) {
    if (*arr) {
        delete[] *arr;
        *arr = nullptr;
    }
}

int main() {
    int size, firstElem, step;
    std::cout << "Enter space-separated length, first number, and step of the arithmetic progression\n";
    std::cin >> size >> firstElem >> step;
    int *arr;

    create(&arr, size, firstElem, step);
    sort(arr, size);
    print(arr, size);
    destroy(&arr);
}
