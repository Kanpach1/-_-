//(4) a % b を表示するプログラムを作成せよ。
#include <stdio.h>

int main(void) {
    int a = 2021;
    int b = 1016;
    int c;

    c = a % b;
    printf("a %% b = %d\n", c); // %を表示するために%%を使用
    return 0;
}