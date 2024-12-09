/*
 * src/1-8_2.c
 * このファイルは 1-8_2 です。
 * ## 問題内容
 *  三角形ABCについて、角度 A（度数法、小数を含む）、辺 b（小数を含む）、辺 c（小数を含む）を入力すると、
 *  三角形 ABC の面積を求めるプログラムを作成してください。
 */

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define BUFFER_SIZE 256  // 入力バッファのサイズ


void get_line(char *buffer, int size);

int main(void) {
    char buffer[BUFFER_SIZE];
    double A_deg, b, c;     // 入力用変数（角度A、辺b、辺c）
    double A_rad, area;     // 計算用変数（ラジアンの角度A、面積）

    // 角度Aの入力
    printf("角度 A (度) を入力してください: ");
    get_line(buffer, BUFFER_SIZE);
    A_deg = atof(buffer);  // 文字列を浮動小数点数に変換

    // 辺bの入力
    printf("辺 b を入力してください: ");
    get_line(buffer, BUFFER_SIZE);
    b = atof(buffer);

    // 辺cの入力
    printf("辺 c を入力してください: ");
    get_line(buffer, BUFFER_SIZE);
    c = atof(buffer);

    // 入力値の検証
    if (A_deg <= 0 || A_deg >= 180) {
        printf("❌ 角度 A は 0 より大きく 180 より小さい値を入力してください。\n");
        return 1;
    }
    if (b <= 0 || c <= 0) {
        printf("❌ 辺 b および 辺 c は正の値を入力してください。\n");
        return 1;
    }

    // 角度Aをラジアンに変換
    A_rad = A_deg * M_PI / 180.0;

    // 面積の計算
    area = 0.5 * b * c * sin(A_rad);

    // 結果の出力
    printf("三角形の面積: %.2f\n", area);

    return 0;
}

// 標準入力から1行を取得する関数
void get_line(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';  // 入力エラー時は空文字列にする
        return;
    }

    // 改行文字を削除
    for (int i = 0; i < size; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
    }
}
