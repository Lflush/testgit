#include <iostream>
using namespace std;

// 扩展欧几里得算法，求出a和b的最大公约数和x,y满足ax+by=gcd(a,b)
long long extgcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
// 求出a在模m下的逆元，即满足ax=1 (mod m)的x
long long inv(long long a, long long m)
{
    long long x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m;
}
// 中国剩余定理，求出同余方程组的解
long long crt(long long n, long long *a, long long *b)
{
    long long M = 1;
    for (long long i = 0; i < n; i++)
    {
        M *= a[i];
    }
    long long x = 0;
    long long *mi = new long long[n + 1]{0};
    for (long long i = 0; i < n; i++)
    {
        mi[i] = M / a[i];
        long long ei = inv(mi[i], a[i]);
        x = (x + b[i] * mi[i] * ei) % M;
    }
    return x;
}

int main()
{
    long long n;
    cin >> n;
    long long *a = new long long[n + 1];
    long long *b = new long long[n + 1]; // 同余方程组的模数和常数
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    long long x = crt(n, a, b);
    cout << x << endl; // 输出解的值
    return 0;
}
