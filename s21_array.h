#ifndef S21_ARRAY_H_
#define S21_ARRAY_H_

#include <iostream>

namespace s21 {
template <class T, size_t N>
class array {
    public:
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;
        
        array() : size_(N) {
            array_ = new value_type[N];
        }

        array(const std::initializer_list<value_type> &items) : size_(N) {
            if (items.size() != N) {
                throw std::length_error("Wrong Size Of Initilizer List.");
            }
            array_ = new value_type[N];
            std::copy(items.begin(), items.end(), array_);
        }

        array(const array &a) : size_(N) {
            array_ = new value_type[N];
            std::copy(a.array_, a.array_ + a.size() - 1, array_);   
        }

        array(array &&a) {
            array_ = a.array_;
            size_ = a.size_;
            a.array_ = nullptr;
            a.size_ = 0;
        }

        ~array() {
            if (array_ != nullptr) {
                delete[] array_;
            }
        }

        array operator=(const array &a) noexcept {
            if (array_ != nullptr) { delete[] array_; }
            array_ = new value_type[N];
            std::copy(a.array_, a.array_ + a.size() - 1, array_);
            return (*this);
        }

        reference at(size_type pos) {
            if (pos > size_ - 1) {
                throw std::length_error("Wrong Bounds.");
            }
            return *(array_ + pos);
        }

        reference operator[](size_type pos) noexcept { return (*this).at(pos); }

        const_reference front() const noexcept { return *array_; }

        const_reference back() const noexcept { return *(array_ + size_ - 1); }

        iterator data() noexcept { return array_; }

        iterator begin() {
            return array_;
        }

        iterator end() {
            return array_ + size_;
        }

        bool empty() const noexcept { return (size_ == 0); }

        size_type size() const noexcept { return size_; }

        size_type max_size() const noexcept { return size_; };

        void swap(array& other) {
            std::swap(other.array_, array_);
        }

        void fill(const_reference value) noexcept {
            for (size_type i = 0; i < size_; ++i) {
                array_[i] = value;
            }
        }
        
    private:
        iterator array_;
        size_type size_;
};
}

#endif