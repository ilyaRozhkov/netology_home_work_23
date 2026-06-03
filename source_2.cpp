#include <iostream>
#include <clocale> 
#include <cassert>

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

void testCountGreater() {

    int* empty = nullptr;
    assert(countGreater(empty, 0, 5) == 0);
    assert(countGreater(empty, 0, -10) == 0);

    int single[] = { 10 };
    assert(countGreater(single, 1, 5) == 1);
    assert(countGreater(single, 1, 10) == 0);
    assert(countGreater(single, 1, 15) == 0);

    int less[] = { 1, 2, 3 };
    assert(countGreater(less, 3, 10) == 0);

    int greater[] = { 10, 20, 30 };
    assert(countGreater(greater, 3, 5) == 3);

    int dup[] = { 5, 5, 5, 8, 8, 10 };
    assert(countGreater(dup, 6, 5) == 3);
    assert(countGreater(dup, 6, 7) == 3);
    assert(countGreater(dup, 6, 8) == 1);
    assert(countGreater(dup, 6, 9) == 1);
    assert(countGreater(dup, 6, 10) == 0);

    int neg[] = { -10, -5, 0, 3 };
    assert(countGreater(neg, 4, -6) == 3);
    assert(countGreater(neg, 4, -10) == 3);
    assert(countGreater(neg, 4, 3) == 0);

    std::cout << "Все тесты пройдены!\n";
}

int main() {

    std::setlocale(LC_ALL, "");

    testCountGreater();


    int arr[] = { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int point;
    std::cout << "Введите точку отсчёта: ";
    std::cin >> point;

    int result = countGreater(arr, size, point);
    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << result << std::endl;

    return 0;
}
