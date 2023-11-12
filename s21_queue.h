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
        }
        node * head_;
        node * tail_;
        size_type size_;
    public:
        queue();
        queue(std::initializer_list<value_type> const &items);
        queue(const queue &q);
        queue(queue &&q);
        ~queue();
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

        void push(const_reference value);
        void pop();
        void swap(queue& other);
};

#endif