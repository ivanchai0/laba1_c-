#include <iostream>
#include <windows.h>
#include <clocale>
#include <string>

double fraction(double x) {
    return x - (int)x;
}

int charToNum(char x) {
    return (int)x - 48;
}

bool is2Digits(int x) {
    if (x < 0) {
        x = -x;
    }
    if (x >= 10 && x <= 99) {
        return true;
    } else {
        return false;
    }
}

bool isInRange(int a, int b, int num) {
    if ((a <= num && num <= b) || (a >= num && num >= b)) {
        return true;
    } else {
        return false;
    }
}

bool isEqual(int a, int b, int c) {
    if (a == b && b == c) {
        return true;
    } else {
        return false;
    }
}

int abs(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}

bool is35(int x) {
    if ((x % 3 == 0) && (x % 5 == 0)) {
        return false;
    }
    if ((x % 3 == 0) || (x % 5 == 0)) {
        return true;
    }
    return false;
}

int max3(int x, int y, int z) {
    if (x >= y && x >= z) {
        return x;
    } else if (y >= x && y >= z) {
        return y;
    } else {
        return z;
    }
}

int sum2(int x, int y) {
    if ((x + y >= 10) && (x + y <= 19)) {
        return 20;
    } else {
        return x + y;
    }
}

std::string day(int x) {
    switch (x) {
        case 1: return "Понедельник";
        case 2: return "Вторник";
        case 3: return "Среда";
        case 4: return "Четверг";
        case 5: return "Пятница";
        case 6: return "Суббота";
        case 7: return "Воскресенье";
        default: return "это не день недели";
    }
}

std::string listNums(int x) {
    std::string res = "";
    for (int i = 0; i <= x; i++) {
        if (i > 0) {
            res = res + " ";
        }
        res = res + std::to_string(i);
    }
    return res;
}

std::string chet(int x) {
    std::string res = "";
    for (int i = 0; i <= x; i += 2) {
        if (i > 0) {
            res = res + " ";
        }
        res = res + std::to_string(i);
    }
    return res;
}

int numLen(long x) {
    if (x == 0) return 1;
    if (x < 0) x = -x;

    int count = 0;
    while (x > 0) {
        count = count + 1;
        x = x / 10;
    }
    return count;
}

void square(int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void rightTriangle(int x) {
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < x - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int findFirst(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int maxAbs(int arr[], int size) {
    int maximum = arr[0];
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) > abs(maximum)) {
            maximum = arr[i];
        }
    }
    return maximum;
}

int* add(int arr[], int sizeArr, int ins[], int sizeIns, int pos) {
    if (pos < 0) {
        pos = 0;
    } else if (pos > sizeArr) {
        pos = sizeArr;
    }

    int newSize = sizeArr + sizeIns;
    int* result = new int[newSize];

    for (int i = 0; i < pos; i++) {
        result[i] = arr[i];
    }

    for (int i = 0; i < sizeIns; i++) {
        result[pos + i] = ins[i];
    }

    for (int i = pos; i < sizeArr; i++) {
        result[i + sizeIns] = arr[i];
    }

    return result;
}


int* reverseBack(int arr[], int size) {
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = arr[size - 1 - i];
    }
    return result;
}

int* findAll(int arr[], int size, int x, int& resultSize) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }

    int* result = new int[count];
    resultSize = count;

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            result[j] = i;
            j++;
        }
    }

    return result;
}


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    SetConsoleOutputCP(65001);
    int choice;
    do {
        std::cout << "Задачи\n";
        std::cout << "1) 1.1  Дробная часть числа\n";
        std::cout << "2) 1.3  Букву в число\n";
        std::cout << "3) 1.5  Проверка на двузначность\n";
        std::cout << "4) 1.7  Вхождение числа в диапазон\n";
        std::cout << "5) 1.9  Равенство трёх чисел\n";
        std::cout << "6) 2.1  Модуль числа\n";
        std::cout << "7) 2.3  Делится на 3 или 5 (но не на оба)\n";
        std::cout << "8) 2.5  Максимум из трёх чисел\n";
        std::cout << "9) 2.7  Двойная сумма (10-19 -> 20)\n";
        std::cout << "10) 2.9  День недели\n";
        std::cout << "11) 3.1  Числа от 0 до x\n";
        std::cout << "12) 3.3  Чётные числа от 0 до x\n";
        std::cout << "13) 3.5  Длина числа\n";
        std::cout << "14) 3.7  Квадрат из звёздочек\n";
        std::cout << "15) 3.9  Правый треугольник из звёздочек\n";
        std::cout << "16) 4.1  Поиск первого вхождения в массиве\n";
        std::cout << "17) 4.3  Максимум по модулю в массиве\n";
        std::cout << "18) 4.5  Вставка массива в массив\n";
        std::cout << "19) 4.7  Реверс массива (новый массив)\n";
        std::cout << "20) 4.9  Все вхождения числа в массиве\n";
        std::cout << "0.    Выход\n";

        std::cout << "Введите номер задачи: ";
        std::cin >> choice;

        while (!std::cin || choice < 0 || choice > 20) {
            std::cout << "Введите число от 0 до 20: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cin >> choice;
        }
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case 1: {
                double x;
                std::cout << "Введите x: ";
                if (std::cin >> x) {
                    std::cout << "Дробная часть: " << fraction(x) << std::endl;
                    std::cin.ignore(10000, '\n');
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 2: {
                char x;
                std::cout << "Введите символ (цифру от 0 до 9): ";
                std::cin >> x;

                if (x >= '0' && x <= '9' && std::cin.peek() == '\n') {
                    std::cout << "Результат: " << charToNum(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести одну цифру от 0 до 9!" << std::endl;
                }
                std::cin.ignore(10000, '\n');
                break;
            }
            case 3: {
                int x;
                std::cout << "Введите число: ";
                if (std::cin >> x) {
                    std::cout << std::boolalpha << is2Digits(x) << std::endl;
                    std::cin.ignore(10000, '\n');
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 4: {
                int a;
                int b;
                int num;
                std::cout << "Введите правую и левую границу и число: " << std::endl;
                if ((std::cin >> a) && (std::cin >> b) && (std::cin >> num)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << std::boolalpha <<isInRange(a, b, num) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 5: {
                int a;
                int b;
                int c;
                std::cout << "Введите три числа" << std::endl;
                if ((std::cin >> a) && (std::cin >> b) && (std::cin >> c)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << std::boolalpha << isEqual(a, b, c) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 6: {
                int x;
                std::cout << "Введите число: " << std::endl;
                if ((std::cin >> x)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << abs(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 7: {
                int x;
                std::cout << "Введите число: " << std::endl;
                if ((std::cin >> x)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << std::boolalpha << is35(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 8: {
                int x;
                int y;
                int z;
                std::cout << "Введите три числа: " << std::endl;
                if ((std::cin >> x) && (std::cin >> y) && (std::cin >> z)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << max3(x, y, z) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 9: {
                int x;
                int y;
                std::cout << "Введите два числа: " << std::endl;
                if ((std::cin >> x) && (std::cin >> y)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << sum2(x, y) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 10: {
                int x;
                std::cout << "Введите число: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    std::cout << day(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 11: {
                int x;
                std::cout << "Введите число: " << std::endl;
                if ((std::cin >> x) && (x >= 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << listNums(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести неотрицательное число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 12: {
                int x;
                std::cout << "Введите число: " << std::endl;
                if ((std::cin >> x) && (x >= 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << chet(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести неотрицательное число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 13: {
                long x;
                std::cout << "Введите число: " << std::endl;
                if ((std::cin >> x) && (x >= 0)) {
                    std::cin.ignore(10000, '\n');
                    std::cout << numLen(x) << std::endl;
                } else {
                    std::cout << "Нужно ввести неотрицательное число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 14: {
                int x;
                std::cout << "Введите x: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    if (x > 0) {
                        square(x);
                    } else {
                        std::cout << "Размер должен быть больше 0!" << std::endl;
                    }
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 15: {
                int x;
                std::cout << "Введите x: ";
                if (std::cin >> x) {
                    std::cin.ignore(10000, '\n');
                    if (x > 0) {
                        rightTriangle(x);
                    } else {
                        std::cout << "Размер должен быть больше 0!" << std::endl;
                    }
                } else {
                    std::cout << "Нужно ввести число!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                break;
            }
            case 16: {
                int arr[100];
                int n;
                std::cout << "Сколько элементов? (от 1 до 100): ";
                std::cin >> n;

                for (int i = 0; i < n; i++) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }

                int x;
                std::cout << "Введите x: ";
                std::cin >> x;
                std::cin.ignore(10000, '\n');

                std::cout << "Индекс: " << findFirst(arr, n, x) << std::endl;
                break;
            }
            case 17: {
                int arr[100];
                int n;
                std::cout << "Сколько элементов? (от 1 до 100): ";
                std::cin >> n;
                for (int i = 0; i < n; i++) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }
                std::cout << "Максимум по модулю: " << maxAbs(arr, n) << std::endl;
                break;
            }
            case 18: {
                int arr[100], ins[100];
                int n1, n2, pos;

                std::cout << "Сколько элементов в arr? (от 1 до 100): ";
                std::cin >> n1;
                for (int i = 0; i < n1; i++) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }

                std::cout << "Сколько элементов в ins? (от 1 до 100): ";
                std::cin >> n2;
                for (int i = 0; i < n2; i++) {
                    std::cout << "ins[" << i << "] = ";
                    std::cin >> ins[i];
                }

                std::cout << "Введите pos: ";
                std::cin >> pos;
                std::cin.ignore(10000, '\n');

                int* result = add(arr, n1, ins, n2, pos);
                int newSize = n1 + n2;

                std::cout << "Результат: [";
                for (int i = 0; i < newSize; i++) {
                    if (i > 0) std::cout << ", ";
                    std::cout << result[i];
                }
                std::cout << "]" << std::endl;

                delete[] result;
                break;
            }
            case 19: {
                int arr[100];
                int n;

                std::cout << "Сколько элементов? (от 1 до 100): ";
                std::cin >> n;
                for (int i = 0; i < n; i++) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }
                std::cin.ignore(10000, '\n');

                int* result = reverseBack(arr, n);

                std::cout << "Результат: [";
                for (int i = 0; i < n; i++) {
                    if (i > 0) std::cout << ", ";
                    std::cout << result[i];
                }
                std::cout << "]" << std::endl;

                delete[] result;
                break;
            }
            case 20: {
                int arr[100];
                int n;

                std::cout << "Сколько элементов? (от 1 до 100): ";
                std::cin >> n;
                for (int i = 0; i < n; i++) {
                    std::cout << "arr[" << i << "] = ";
                    std::cin >> arr[i];
                }

                int x;
                std::cout << "Введите x: ";
                std::cin >> x;
                std::cin.ignore(10000, '\n');

                int resultSize;
                int* result = findAll(arr, n, x, resultSize);

                std::cout << "Индексы: [";
                for (int i = 0; i < resultSize; i++) {
                    if (i > 0) std::cout << ", ";
                    std::cout << result[i];
                }
                std::cout << "]" << std::endl;

                delete[] result;
                break;
            }
        }
    } while (choice != 0);
    return 0;
}