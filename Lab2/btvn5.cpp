#include <bits/stdc++.h>

using namespace std;

int n, m, a[20][20];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) cin >> a[i][j];

    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= m; ++y)
            for (int w = 2; y + w - 1 <= n; ++w)
                for (int h = 2; x + h - 1 <= m; ++h)
                {
                    bool ok = true;
                    for (int i = x; ok && i <= x + h - 1; ++i)
                        if (a[i][y + w] == 1 || a[i][y - 1]) ok = false;
                    for (int i = y; ok && i <= y + w - 1; ++i)
                        if (a[x - 1][i] == 1 || a[x + h][i] == 1) ok = false;
                    for (int i = x; ok && i <= x + h - 1; ++i)
                        for (int j = y; ok && j <= y + w - 1; ++j)
                            if (a[i][j] == 0) ok = false;

                    if (ok) cout << "[" << y - 1 << ',' << x - 1 << ',' << w << ',' << h << ']' << endl;
                }
            
    return 0;
}