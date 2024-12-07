#include <stdio.h>

int main(void) {
    int a;      // a の値を定義
    int b;      // b の値を定義
    int diff;   // 差を定義

    // 変数の初期化
    a = 2021;   // a に 2021 を代入
    b = 1016;   // b に 1016 を代入

    // 計算
    diff = a - b;  // a と b の差を計算

    // 結果の出力
    printf("a - b = %d\n", diff);  // 差を表示

    return 0;
}
