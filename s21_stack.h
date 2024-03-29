#ifndef S21_STACK_H_
#define S21_STACK_H_

#include <iostream>

namespace s21 {
template <class T>
class stack {
    public:
        using value_type = T;
        using reference = T &;
        using size_type = size_t;
        using const_reference = const T &;

        stack() : head_(nullptr), size_(0) {};

        stack(const std::initializer_list<value_type> &items) : head_(nullptr), size_(0) {
            for (auto i: items) {
                push(i);
            }
        }

        stack(const stack &other) : head_(nullptr), size_(0) {
            node * point = other.head_;
            stack buffer;
            while (point != nullptr) {
                buffer.push(point->value_);
                point = point->next_;
            }
            point = buffer.head_;
            while (point != nullptr) {
                push(point->value_);
                point = point->next_;
            }

        }

        stack(stack &&other) {
            head_ = other.head_;
            size_ = other.size_;
            other.head_ = nullptr;
            other.size_ = 0;
        }

        ~stack() {
            while (!(this->empty())) {
                this->pop();
            }
            head_ = nullptr;
            size_ = 0;
        }

        stack operator=(const stack &other) noexcept {
            if (this != &other) {
                stack tmp(other);
                this->swap(tmp);
            }
            return *this;
        } 

        const_reference top() const {
            if (this->empty()) {
                throw std::length_error("Stack is empty");
            }
            return head_->value_;
        }

        bool empty() const noexcept { return size_ == 0; }

        size_type size() const noexcept { return size_; }

        void push(const_reference value) {
            node * newNode = new node(value);
            if (newNode == nullptr) {
                throw std::length_error("Memory was not allocated");
            }
            if (this->empty()) {
                head_ = newNode;
            } else {
                newNode->next_ = head_;
                head_ = newNode;
            }
            ++size_;
        }

        void pop() {
            if (this->empty()) {
                throw std::length_error("Stack is empty");
            }
            if (size_ == 1) {
                delete head_;
            } else {
                node * saveHead = head_;
                head_ = head_->next_;
                delete saveHead;
            }
            --size_;
        }

        void swap(stack& other) noexcept {
            std::swap(head_, other.head_);
            std::swap(size_, other.size_);
        }

        private:
            struct node {
                value_type value_;
                node * next_;
                node(const_reference value) : value_(value), next_(nullptr) {};
            };
            node * head_;
            size_type size_;
};
}

#endif