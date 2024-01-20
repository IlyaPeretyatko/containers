#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>

#include "s21_containers.h"

TEST(Stack, PushPopSizeEmpty1) {
    s21::stack<int> test;
    test.push(5);
    test.push(4);
    test.push(3);
    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), 3);
    test.pop();
    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), 4);
    test.pop();
    EXPECT_EQ(test.size(), 1);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), 5);
    test.pop();
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.empty(), true);
}

TEST(Stack, PushPopSizeEmpty2) {
    s21::stack<std::string> test;
    test.push("bebra");
    test.push("aboba");
    test.push("kek");
    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), "kek");
    test.pop();
    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), "aboba");
    test.pop();
    EXPECT_EQ(test.size(), 1);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.top(), "bebra");
    test.pop();
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.empty(), true);
}

TEST(Stack, Swap) {
    s21::stack<int> test1;
    test1.push(5);
    test1.push(4);
    test1.push(3);
    s21::stack<int> test2;
    test2.push(5);
    test2.push(4);
    test1.swap(test2);
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test2.size(), 3);
    EXPECT_EQ(test1.top(), 4);
    EXPECT_EQ(test2.top(), 3);
    test1.pop();
    EXPECT_EQ(test1.size(), 1);
    EXPECT_EQ(test1.top(), 5);
    test2.pop();
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.top(), 4);
}

TEST(Stack, Equating) {
    s21::stack<int> test1;
    test1.push(5);
    test1.push(4);
    test1.push(3);
    s21::stack<int> test2;
    test2.push(5);
    test2.push(4);
    test1 = test2;
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test1.top(), 4);
    test1.pop();
    EXPECT_EQ(test1.size(), 1);
    EXPECT_EQ(test1.top(), 5);
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.top(), 4);
    test2.pop();
    EXPECT_EQ(test2.size(), 1);
    EXPECT_EQ(test2.top(), 5);
}

TEST(Stack, ConstructorBasic) {
    s21::stack<int> test;
    EXPECT_EQ(test.empty(), true);
}

TEST(Stack, ConstructorCopy) {
    s21::stack<int> test2;
    test2.push(5);
    test2.push(4);
    s21::stack<int> test1(test2);
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test1.top(), 4);
    test1.pop();
    EXPECT_EQ(test1.size(), 1);
    EXPECT_EQ(test1.top(), 5);
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.top(), 4);
    test2.pop();
    EXPECT_EQ(test2.size(), 1);
    EXPECT_EQ(test2.top(), 5);
}

TEST(Stack, ConstructorInitList) {
    std::initializer_list<int> elems {1, 2, 3, 4, 5};
    s21::stack<int> test(elems);
    EXPECT_EQ(test.size(), 5);
    EXPECT_EQ(test.top(), 5);
    test.pop();
    EXPECT_EQ(test.size(), 4);
    EXPECT_EQ(test.top(), 4);
    test.pop();
    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.top(), 3);
}

TEST(Queue, PushPopSizeEmpty) {
    s21::queue<int> test;
    test.push(5);
    test.push(4);
    test.push(3);
    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.back(), 3);
    EXPECT_EQ(test.front(), 5);
    test.pop();
    EXPECT_EQ(test.size(), 2);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.back(), 3);
    EXPECT_EQ(test.front(), 4);
    test.pop();
    EXPECT_EQ(test.size(), 1);
    EXPECT_EQ(test.empty(), false);
    EXPECT_EQ(test.back(), 3);
    EXPECT_EQ(test.front(), 3);
    test.pop();
    EXPECT_EQ(test.size(), 0);
    EXPECT_EQ(test.empty(), true);
}

TEST(Queue, Swap) {
    s21::queue<int> test1;
    test1.push(5);
    test1.push(4);
    test1.push(3);
    s21::queue<int> test2;
    test2.push(5);
    test2.push(4);
    test1.swap(test2);
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test2.size(), 3);
    EXPECT_EQ(test1.front(), 5);
    EXPECT_EQ(test2.front(), 5);
    EXPECT_EQ(test1.back(), 4);
    EXPECT_EQ(test2.back(), 3);
    test1.pop();
    EXPECT_EQ(test1.size(), 1);
    EXPECT_EQ(test1.front(), 4);
    test2.pop();
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.front(), 4);
}

TEST(Queue, Equating) {
    s21::queue<int> test1;
    test1.push(5);
    test1.push(4);
    test1.push(3);
    s21::queue<int> test2;
    test2.push(5);
    test2.push(4);
    test1 = test2;
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test1.back(), 4);
    EXPECT_EQ(test1.front(), 5);
    test1.pop();
    EXPECT_EQ(test1.size(), 1);
    EXPECT_EQ(test1.front(), 4);
    EXPECT_EQ(test1.back(), 4);
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.back(), 4);
    EXPECT_EQ(test2.front(), 5);
    test2.pop();
    EXPECT_EQ(test2.size(), 1);
    EXPECT_EQ(test2.front(), 4);
    EXPECT_EQ(test2.back(), 4);
}

TEST(Queue, ConstructorBasic) {
    s21::queue<int> test;
    EXPECT_EQ(test.empty(), true);
}

TEST(Queue, ConstructorCopy) {
    s21::queue<int> test2;
    test2.push(5);
    test2.push(4);
    s21::queue<int> test1(test2);
    EXPECT_EQ(test1.size(), 2);
    EXPECT_EQ(test1.back(), 4);
    EXPECT_EQ(test1.front(), 5);
    test1.pop();
    EXPECT_EQ(test1.back(), 4);
    EXPECT_EQ(test1.front(), 4);
    EXPECT_EQ(test2.size(), 2);
    EXPECT_EQ(test2.back(), 4);
    EXPECT_EQ(test2.front(), 5);
    test2.pop();
    EXPECT_EQ(test2.back(), 4);
    EXPECT_EQ(test2.front(), 4);
}

TEST(Queue, ConstructorInitList) {
    std::initializer_list<int> elems {1, 2, 3, 4, 5};
    s21::queue<int> test(elems);
    EXPECT_EQ(test.size(), 5);
    EXPECT_EQ(test.back(), 5);
    EXPECT_EQ(test.front(), 1);
    test.pop();
    EXPECT_EQ(test.size(), 4);
    EXPECT_EQ(test.back(), 5);
    EXPECT_EQ(test.front(), 2);
    test.pop();
    EXPECT_EQ(test.size(), 3);
    EXPECT_EQ(test.back(), 5);
    EXPECT_EQ(test.front(), 3);
}

TEST(Array, Constructors) {
    s21::array<int, 10> test;
    EXPECT_EQ(test.size(), 10);
    EXPECT_FALSE(test.empty());
    test.fill(5);
    s21::array<int, 10> test2(test);
    EXPECT_EQ(test2.size(), 10);
    EXPECT_FALSE(test2.empty());
    EXPECT_EQ(test2[8], 5);
}

TEST(Array, ConstructorInitList) {
    std::initializer_list<int> elems {1, 2, 3, 4, 5};
    s21::array<int, 5> test(elems);
    EXPECT_EQ(test[0], 1);
    EXPECT_EQ(test[1], 2);
    EXPECT_EQ(test[2], 3);
    EXPECT_EQ(test[3], 4);
    EXPECT_EQ(test[4], 5);
}

TEST(Array, Equating) {
    s21::array<int, 5> test1;
    s21::array<int, 5> test2;
    test2.fill(8);
    test1 = test2;
    EXPECT_EQ(test1[3], 8);
}

TEST(Array, FrontBackData) {
    s21::array<int, 5> test1;
    test1.fill(8);
    test1[0] = 3;
    test1.at(4) = 9;
    EXPECT_EQ(test1.front(), 3);
    EXPECT_EQ(test1.back(), 9);
    EXPECT_EQ(*(test1.data()), 3);
    EXPECT_EQ(*(test1.data() + 1), 8);
}

TEST(Array, Swap) {
    s21::array<int, 5> test1;
    s21::array<int, 5> test2;
    test1.fill(8);
    test2.fill(5);
    test1.swap(test2);
    EXPECT_EQ(test1.front(), 5);
    EXPECT_EQ(test2.back(), 8);
}

TEST(Array, Iterator) {
    s21::array<int,5> test;
    test.fill(11);
    test[3] = 8;
    std::stringstream ss;
    for (auto i : test) {
        ss << i << " ";
    }
    EXPECT_EQ(ss.str(), "11 11 11 8 11 ");
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

