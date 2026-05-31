#include <iostream>
#include <windows.h>

int countGreater(int* arr, int size, int point) {
    int left = 0;
    int right = size; 

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= point) {
            left = mid + 1;
        }
        else {
            right = mid;    
        }
    }

    return size - left;
}

int main() {

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int point;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> point;

    int result = countGreater(arr, size, point);
    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << result << std::endl;

    return 0;
}
