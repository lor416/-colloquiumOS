#include <iostream>
#include <memory>
#include <stdexcept>

/**
 * @brief Узел связного списка
 */
template<typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;

    ListNode(const T& value) : data(value), next(nullptr) {}
};

/**
 * @brief Класс связного списка
 */
template<typename T>
class LinkedList {
private:
    std::shared_ptr<ListNode<T>> head;

public:
    LinkedList() : head(nullptr) {}

    /**
     * @brief Добавляет элемент в начало списка
     * @param value Значение для добавления
     */
    void pushFront(const T& value) {
        auto newNode = std::make_shared<ListNode<T>>(value);
        newNode->next = head;
        head = newNode;
    }

    /**
     * @brief Разворачивает связный список итеративным методом
     * @throws std::runtime_error если операция не удалась
     */
    void reverseIterative() {
        try {
            std::shared_ptr<ListNode<T>> prev = nullptr;
            std::shared_ptr<ListNode<T>> current = head;
            std::shared_ptr<ListNode<T>> next = nullptr;

            while (current != nullptr) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

        }
        catch (const std::exception& e) {
            throw std::runtime_error("Failed to reverse linked list: " + std::string(e.what()));
        }
    }

    /**
     * @brief Выводит список на экран
     */
    void print() const {
        auto current = head;
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << " -> ";
            }
            current = current->next;
        }
        std::cout << " -> NULL" << std::endl;
    }

    /**
     * @brief Проверяет, пуст ли список
     * @return true если список пуст, иначе false
     */
    bool isEmpty() const {
        return head == nullptr;
    }
};

// Пример использования
int main() {
    try {
        LinkedList<int> list;
        for (int i = 5; i >= 1; --i) {
            list.pushFront(i);
        }
        std::cout << "Original list: ";
        list.print();
        list.reverseIterative();
        std::cout << "Reversed list: ";
        list.print();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}