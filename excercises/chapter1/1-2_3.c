//(3) 平方和　a^2 + b^2 を表示するプログラムを作成せよ。
#include <stdio.h>

int main(void) {
    int a = 2021;
    int b = 1016;
    int c;

    c = a * a + b * b;
    printf("a^2 + b^2 = %d\n", c);
    return 0;
}