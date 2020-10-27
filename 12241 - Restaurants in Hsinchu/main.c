#include <stdio.h>

long long divisor = 1e9 + 7;

typedef struct {
    long long a, b, c, d;
} Mat;

Mat multiple(Mat mat1, Mat mat2)
{
    Mat ans = {
        .a = ((mat1.a * mat2.a) % divisor + (mat1.b * mat2.c) % divisor) % divisor,
        .b = ((mat1.a * mat2.b) % divisor + (mat1.b * mat2.d) % divisor) % divisor,
        .c = ((mat1.c * mat2.a) % divisor + (mat1.d * mat2.c) % divisor) % divisor,
        .d = ((mat1.c * mat2.b) % divisor + (mat1.d * mat2.d) % divisor) % divisor
    };
    return ans;
}

Mat fastPower(Mat mat, long long n)
{
    if(n == 1) return mat;

    Mat temp = fastPower(mat, n / 2);

    if(n & 1)
        return multiple(multiple(temp, temp), mat);
    else
        return multiple(temp, temp);
}

int main(void)
{

#ifndef ONLINE_JUDGE
    freopen("test", "r", stdin);
#endif

    long long n;
    while(scanf("%lld", &n) != EOF) {

        // [Fn, Fn-1] = Mat^(n-2) * [F2, F1]

        if(n <= 2) {
            printf("1\n");
            continue;
        }

        Mat mat = {.a = 1, .b = 1, .c = 1, .d = 0};
        Mat ansMat = fastPower(mat, n - 2);

        printf("%lld\n", (ansMat.a + ansMat.b) % divisor);
    }

    return 0;
}
