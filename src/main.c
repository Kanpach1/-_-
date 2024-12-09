#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256  // 入力バッファのサイズ

void get_line(char *buffer, int size);  // 標準入力から1行を取得する関数

int main(void) {
    char buffer[BUFFER_SIZE];
    int a, b, c;  // 入力用変数（整数a, b, c）

    // ユーザーに入力を促す
    printf("整数を3つ入力してください:\n");

    // 1つ目の整数を入力
    printf("1つ目の整数: ");
    get_line(buffer, BUFFER_SIZE);
    a = atoi(buffer);  // 文字列を整数に変換

    // 2つ目の整数を入力
    printf("2つ目の整数: ");
    get_line(buffer, BUFFER_SIZE);
    b = atoi(buffer);  // 文字列を整数に変換

    // 3つ目の整数を入力
    printf("3つ目の整数: ");
    get_line(buffer, BUFFER_SIZE);
    c = atoi(buffer);  // 文字列を整数に変換

    // 最大値を求める
    int MAX = a;
    if (b > MAX) {
        MAX = b;
    }
    if (c > MAX) {
        MAX = c;
    }
    

    // 結果を出力
    printf("最大値は: %d\n", MAX);

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
