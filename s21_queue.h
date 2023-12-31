#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include <iostream>

namespace s21 {
template <class T>
class queue {
    public:
        using value_type = T;
        using reference = T &;
        using size_type = size_t;
        using const_reference = const T &;

        queue() : head_(nullptr), tail_(nullptr), size_(0) {};

        queue(const std::initializer_list<value_type> &items) : head_(nullptr), tail_(nullptr), size_(0) {
            for (auto i: items) {
                push(i);
            }
        }

        queue(const queue &other) : head_(nullptr), tail_(nullptr), size_(0) {
            node * point = other.head_;
            while (point != nullptr) {
                push(point->value_);
                point = point->next_;
            }
        }

        queue(queue &&other) {
            std::swap(head_, other.head_);
            std::swap(tail_, other.tail_);
            std::swap(size_, other.size_);
            while (!(other.empty())) {
                other.pop();
            }
        }

        ~queue() {
            while (!(this->empty())) {
                this->pop();
            }
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        queue operator=(const queue &other) noexcept {
            if (this != &other) {
                queue tmp(other);
                this->swap(tmp);
            }
            return *this;
        } 

        const_reference front() const {
            if (this->empty()) {
                throw std::length_error("Queue is empty");
            }
            return head_->value_;
        }

        const_reference back() const {
            if (this->empty()) {
                throw std::length_error("Queue is empty");
            }
            return tail_->value_;
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
                tail_ = newNode;
            } else {
                tail_->next_ = newNode;
                tail_ = newNode;
            }
            ++size_;
        }

        void pop() {
            if (this->empty()) {
                throw std::length_error("Queue is empty");
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

        void swap(queue& other) noexcept {
            std::swap(head_, other.head_);
            std::swap(tail_, other.tail_);
            std::swap(size_, other.size_);
        }

        private:
            struct node {
                value_type value_;
                node * next_;
                node(const_reference value) : value_(value), next_(nullptr) {};
            };
            node * head_;
            node * tail_;
            size_type size_;
};
}

#endif