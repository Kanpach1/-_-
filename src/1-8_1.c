
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUFFER_SIZE 256              // 入力バッファのサイズ
#define M_PI 3.14159265358979323846  // 円周率

void get_line(char *buffer, int size);

int main(void) {
    char buffer[BUFFER_SIZE];
    double A_deg, b, c;             // 入力用変数（角度A、辺b、辺c）
    double A_rad, a;                // 計算用変数（ラジアンの角度A、辺a）

    // 角度Aの入力
    printf("角度 A (度) を入力してください: ");
    get_line(buffer, BUFFER_SIZE);
    A_deg = atof(buffer);           // 文字列を浮動小数点数に変換

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
        printf("角度 A は 0 より大きく 180 より小さい値を入力してください。\n");
        return 1;
    }
    if (b <= 0 || c <= 0) {
        printf("辺 b および 辺 c は正の値を入力してください。\n");
        return 1;
    }

    // 角度Aをラジアンに変換
    A_rad = A_deg * M_PI / 180.0;

    // 余弦定理による辺aの計算
    a = sqrt(b * b + c * c - 2 * b * c * cos(A_rad));

    // 結果の出力
    printf("辺 a の長さ: %.2f\n", a);

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
            return;
        }
    }
}
