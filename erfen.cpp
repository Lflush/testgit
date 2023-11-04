#include <iostream>
using namespace std;
#include <algorithm>
const int mod=1000000007;

int main()
{
    long long n;
    // cin >> n;
    scanf("%lld",&n);
    long long *a = new long long[n + 1];
    for (long long i = 0; i < n; i++)
    {
        // cin >> a[i];
        scanf("%lld",&a[i]);
    }
    long long q = 0;
    long long pos, x, y;
    // cin >> q;
    scanf("%lld",&q);
    for (long long i = 0; i < q; i++)
    {
        // cin >> pos >> x >> y;
        scanf("%lld %lld %lld",&pos,&x,&y);
        for (long long j = 0; j < pos; j++)
        {
            if (x == 1)
            {
                a[j] += y;
            }
            else if (x == 2)
            {
                a[j] *= y;
            }
            a[j]=a[j]%mod;
        }
        reverse(a,a+pos);
        reverse(a+pos,a+n);
        reverse(a,a+n);
    }
    for (long long i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}