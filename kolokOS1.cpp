#include <iostream>
#include <vector>
#include <stdexcept>

/*
 * @brief Генерирует первые n чисел Фибоначчи
 * @param n Количество чисел Фибоначчи для генерации
 * @return Вектор с первыми n числами Фибоначчи
 * @throws std::invalid_argument если n <= 0
 */
std::vector<unsigned long long> generateFibonacciNumbers(int n) {
    if (n <= 0) {
        throw std::invalid_argument("n must be a positive integer");
    }

    std::vector<unsigned long long> fibonacciNumbers;
    fibonacciNumbers.reserve(n);

    try {
        if (n >= 1) {
            fibonacciNumbers.push_back(0);
        }
        if (n >= 2) {
            fibonacciNumbers.push_back(1);
        }

        for (int i = 2; i < n; ++i) {
            // Проверка на переполнение
            if (fibonacciNumbers[i - 1] > ULLONG_MAX - fibonacciNumbers[i - 2]) {
                throw std::overflow_error("Fibonacci number overflow detected");
            }
            fibonacciNumbers.push_back(fibonacciNumbers[i - 1] + fibonacciNumbers[i - 2]);
        }
    }
    catch (const std::bad_alloc& e) {
        throw std::runtime_error("Memory allocation failed while generating Fibonacci numbers");
    }

    return fibonacciNumbers;
}

// Пример использования
int main() {
    try {
        int n;
        std::cout << "Enter the number of Fibonacci numbers to generate: ";
        std::cin >> n;

        auto fibNumbers = generateFibonacciNumbers(n);

        std::cout << "First " << n << " Fibonacci numbers: \n";
        for (size_t i = 0; i < fibNumbers.size(); ++i) {
            std::cout << fibNumbers[i];
            if (i != fibNumbers.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}