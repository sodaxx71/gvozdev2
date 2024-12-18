#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

void zadanie1() {
    double number;
    std::cout << "Введите число с плавающей запятой: ";
    std::cin >> number;
    std::cout << "Научная нотация: " << std::scientific << number << std::endl;
}

void zadanie2() {
    int number;
    std::cout << "Введите целое число: ";
    std::cin >> number;
    if (number % 2 == 0)
        std::cout << "Число четное." << std::endl;
    else
        std::cout << "Число нечетное." << std::endl;
}

bool isPrime(int number) {
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void zadanie3() {
    int number;
    std::cout << "Введите целое число: ";
    std::cin >> number;
    if (isPrime(number))
        std::cout << "Число простое." << std::endl;
    else
        std::cout << "Число не простое." << std::endl;
}

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void zadanie4() {
    int number;
    std::cout << "Введите неотрицательное целое число: ";
    std::cin >> number;
    std::cout << "Факториал: " << factorial(number) << std::endl;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void zadanie5() {
    int a, b;
    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;
    std::cout << "НОД: " << gcd(a, b) << std::endl;
}

void zadanie6() {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << i * j << "\t";
        }
        std::cout << std::endl;
    }
}

void zadanie7() {
    int N, sum = 0;
    std::cout << "Введите число N: ";
    std::cin >> N;
    for (int i = 2; i <= N; i += 2) {
        sum += i;
    }
    std::cout << "Сумма четных чисел от 1 до " << N << ": " << sum << std::endl;
}

void zadanie8() {
    double num1, num2;
    char op;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите оператор (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    switch (op) {
    case '+':
        std::cout << "Результат: " << num1 + num2 << std::endl;
        break;
    case '-':
        std::cout << "Результат: " << num1 - num2 << std::endl;
        break;
    case '*':
        std::cout << "Результат: " << num1 * num2 << std::endl;
        break;
    case '/':
        if (num2 != 0)
            std::cout << "Результат: " << num1 / num2 << std::endl;
        else
            std::cout << "Ошибка: деление на ноль!" << std::endl;
        break;
    default:
        std::cout << "Некорректный оператор!" << std::endl;
        break;
    }
}

void zadanie9() {
    int day;
    std::cout << "Введите число от 1 до 7: ";
    std::cin >> day;

    switch (day) {
    case 1: std::cout << "Понедельник:("; break;
    case 2: std::cout << "Вторник:("; break;
    case 3: std::cout << "Среда:|"; break;
    case 4: std::cout << "Четверг:|"; break;
    case 5: std::cout << "Пятница:)"; break;
    case 6: std::cout << "Суббота:)"; break;
    case 7: std::cout << "Воскресенье:)"; break;
    default: std::cout << "Некорректное число!"; break;
    }

    std::cout << std::endl;
}

int sumArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

void zadanie10() {
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int totalSum = sumArray(arr, size);

    std::cout << "Сумма элементов массива: " << totalSum << std::endl;
    delete[] arr;
}

void reverseArray(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void zadanie11() {
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    reverseArray(arr, size);

    std::cout << "Реверсированный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    std::cout << std::endl;
}

void zadanie12() {
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int maxVal = std::numeric_limits<int>::min();
    int minVal = std::numeric_limits<int>::max();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > maxVal) maxVal = arr[i];
        if (arr[i] < minVal) minVal = arr[i];
    }

    std::cout << "Максимальное значение: " << maxVal
        << "\nМинимальное значение: " << minVal
        << std::endl;
    delete[] arr; 
}

void bubbleSort(std::string* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void zadanie13() {

    int size;

    std::cout << "Введите количество строк: ";
    std::cin >> size;

    
    std::cin.ignore();

    std::string* arr = new std::string[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "Введите строку #" << (i + 1) << ": ";
        getline(std::cin, arr[i]);
    }

    bubbleSort(arr, size);

    std::cout << "Отсортированные строки:" << std::endl;

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "\n";
    }

    delete[] arr; 
}

double average(double a, double b) {
    return(a + b) / 2.0;
}

void zadanie14() {
    double num1, num2;

    std::cout << "Введите первое число: ";
    std::cin >> num1;

    std::cout << "Введите второе число: ";
    std::cin >> num2;

    std::cout << "Среднее значение: " << average(num1, num2) << std::endl;
}

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void zadanie15() {
    int n;
    std::cout << "Введите номер Фибоначчи: ";
    std::cin >> n;
    std::cout << n << "-е число Фибоначчи: " << fibonacci(n) << std::endl;
}

double averageArray(int* arr, int size) {
    double sum = 0;
    for (int i = 0;i < size;++i)
        sum += arr[i];
    return sum / size;
}

void zadanie16() {
    int size;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите элементы массива: ";
    for (int i = 0;i < size;++i)
        std::cin >> arr[i];

    std::cout << "Среднее значение массива: " << averageArray(arr, size) << std::endl;

    delete[] arr;  
}

void countVowelsAndConsonants(const char* str, int& vowels, int& consonants) {
    vowels = 0;
    consonants = 0;

    const char vowelsArray[] = "AEIOUaeiou";

    for (int i = 0; str[i] != '0'; ++i) {
        char ch = str[i];
        if (isalpha(ch)) {
            if (strchr(vowelsArray, ch)) {
                ++vowels;
            }
            else {
                ++consonants;
            }
        }
    }
}

void zadanie17() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];

    std::cout << "Введите строку: ";
    std::cin.getline(str, MAX_LENGTH);

    int vowels = 0, consonants = 0;
    countVowelsAndConsonants(str, vowels, consonants);

    std::cout << "Количество гласных: " << vowels << std::endl;
    std::cout << "Количество согласных: " << consonants << std::endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    int choice;

    do {
        std::cout << "\nВыберите задание (1-17), или введите 0 для выхода: ";
        std::cin >> choice;

        switch (choice) {
        case 1: zadanie1(); break;
        case 2: zadanie2(); break;
        case 3: zadanie3(); break;
        case 4: zadanie4(); break;
        case 5: zadanie5(); break;
        case 6: zadanie6(); break;
        case 7: zadanie7(); break;
        case 8: zadanie8(); break;
        case 9: zadanie9(); break;
        case 10: zadanie10(); break;
        case 11: zadanie11(); break;
        case 12: zadanie12(); break;
        case 13: zadanie13(); break;
        case 14: zadanie14(); break;
        case 15: zadanie15(); break;
        case 16: zadanie16(); break;
        case 17: zadanie17(); break;
        case 0:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Некорректный выбор! Пожалуйста, попробуйте снова." << std::endl;
            break;
        }
    } while (choice != 0);

      return  0;
}