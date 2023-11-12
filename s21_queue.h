#ifndef S21_QUEUE_H_
#define S21_QUEUE_H_

#include <iostream>

template <class value_type, 
        class reference = value_type &,
        class const_reference = const value_type &,
        class size_type = size_t>
class queue {
    private:
        struct node {
            value_type value_;
            node * next_;
            node(const_reference value) : value_(value), next_(nullptr) {};
        }
        node * head_;
        node * tail_;
        size_type size_;
    public:
        queue() : head_(nullptr), tail_(nullptr), size_(0) {};

        queue(std::initializer_list<value_type> const &items);

        queue(const queue &q);

        queue(queue &&q);

        ~queue() {
            while (!(this->empty())) {
                this->pop();
            }
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        operator=(queue &&q);

        const_reference front() const {
            if (this->empty()) {
                throw std::length_error("Queue is empty");
            }
            return head_->value;
        }

        const_reference back() const {
            if (this->empty()) {
                throw std::length_error("Queue is empty");
            }
            return tail_->value;
        }

        bool empty() const noexcept { return size_ == 0; }

        size_type size() const noexcept { return size_; }

        void push(const_reference value) noexcept {
            node * newNode = new node(value);
            if (this->empty()) {
                this->head_ = newNode;
                this->tail_ = newNode;
            } else {
                tail_->next = newNode;
                tail_ = newNode;
            }
            ++size_;
        }

        void pop() noexcept {
            if (!(this->empty())) {
                if (size_ == 1) {
                    delete head_;
                } else {
                    node * saveHead = head_;
                    head_ = head_->next;
                    delete saveHead;
                    --size_;
                }
            }
        }


        void swap(queue& other);
};

#endif