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
        };
        node * head_;
        node * tail_;
        size_type size_;
    public:
        queue() : head_(nullptr), tail_(nullptr), size_(0) {};

        //queue(std::initializer_list<value_type> const &items); //

        queue(const queue &other) {
            size_ = 0;
            head_ = nullptr;
            tail_ = nullptr;
            node * point = other.head_;
            while (point != nullptr) {
                push(point->value_);
                point = point->next_;
            }
        }

        //queue(queue &&q);

        ~queue() {
            while (!(this->empty())) {
                this->pop();
            }
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        //operator=(queue &&q); 

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

        void pop() noexcept {
            if (!(this->empty())) {
                if (size_ == 1) {
                    delete head_;
                } else {
                    node * saveHead = head_;
                    head_ = head_->next_;
                    delete saveHead;
                }
                --size_;
            }
        }


        //void swap(queue& other); //
};

#endif