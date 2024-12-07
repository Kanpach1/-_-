#include <stdio.h>
#include <math.h>

// 関数 f(x) の定義
double f(double x) {
    return pow(x, 3) - 2 * x + 2;
}

// 関数 f'(x) の定義
double df(double x) {
    return 3 * pow(x, 2) - 2;
}

// ニュートン法による近似解を求める関数
double newton(double x0, double epsilon) {
    double x = x0; // 初期値
    while (fabs(f(x)) > epsilon) { // 許容誤差以下になるまで繰り返し
        x = x - f(x) / df(x); // ニュートン法の式
    }
    return x;
}

int main(void) {
    double x0 = -1;      // 初期値
    double epsilon = 1e-6; // 許容誤差

    printf("ニュートン法による近似解: %.6f\n", newton(x0, epsilon));
    return 0;
}
