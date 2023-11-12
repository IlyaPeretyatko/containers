#include "s21_queue.h"

int main() {
    queue<int> aboba;
    aboba.push(5);
    aboba.push(3);
    aboba.push(7);
    queue<int> bebra(aboba);
    return 0;
}