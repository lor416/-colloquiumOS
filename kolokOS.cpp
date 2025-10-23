#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

bool isNumberPalindrome(long long number) {
    if (number < 0) {
        throw std::invalid_argument("Negative numbers cannot be palindromes");
    }

    std::string numStr = std::to_string(number);
    int left = 0;
    int right = numStr.length() - 1;

    while (left < right) {
        if (numStr[left] != numStr[right]) {
            return false;
        }
        ++left;
        --right;
    }

    return true;
}

int main() {
    try {
        long long number;
        std::cout << "Enter a number: ";

        // Проверка на корректный ввод числа
        if (!(std::cin >> number)) {
            // Очищаем флаги ошибок
            std::cin.clear();
            // Удаляем ошибочные символы из буфера
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Invalid input: please enter a valid number");
        }

        // Проверка на переполнение (если введено число больше максимального для long long)
        if (std::cin.fail()) {
            throw std::overflow_error("Number is too large or too small");
        }

        // Проверка на отрицательное число (хотя это уже есть в функции)
        if (number < 0) {
            throw std::invalid_argument("Negative numbers are not allowed");
        }

        bool result = isNumberPalindrome(number);
        std::cout << number << " is " << (result ? "" : "not ") << "a palindrome" << std::endl;

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Input error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::overflow_error& e) {
        std::cerr << "Overflow error: " << e.what() << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }

    return 0;
}