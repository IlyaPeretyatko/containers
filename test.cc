#include <gmock/gmock.h>
#include <gtest/gtest.h>

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

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

