#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;

void Test_A()
{
    int n = 0;
    cin >> n;

    if (n % 2)
    {
        cout << "NO" << "\n";
        return;
    }

    int ret_1 = n / 2;
    int begin = 1;
    while (begin * begin < ret_1)
    {
        begin++;
    }

    if (begin * begin == ret_1)
    {
        cout << "YES" << "\n";
        return;
    }

    if (n % 4)
    {
        cout << "NO" << "\n";
    }
    else
    {
        int ret_2 = n / 4;
        begin = 1;
        while (begin * begin < ret_2)
        {
            begin++;
        }

        if (begin * begin == ret_2)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}

void Test_B()
{
    int n = 0, m = 0;
    cin >> n >> m;

    int index = 0;
    vector<vector<char>> p(n, vector<char>(m));
    if (m % 2)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (index == 0)
                {
                    index = 1;
                    p[i][j] = 'B';
                }
                else
                {
                    index = 0;
                    p[i][j] = 'W';
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i += 2)
        {
            for (int j = 0; j < m; j++)
            {
                if (j % 2 == 0)
                {
                    p[i][j] = 'B';
                }
                else
                {
                    p[i][j] = 'W';
                }
            }
        }

        for (int i = 1; i < n; i += 2)
        {
            for (int j = 0; j < m; j++)
            {
                if (j % 2 == 0)
                {
                    p[i][j] = 'W';
                }
                else
                {
                    p[i][j] = 'B';
                }
            }
        }
    }

    if ((n * m) % 2 == 0)
    {
        if (p[n - 1][m - 1] == 'B')
        {
            p[n - 1][m - 2] = 'B';
        }
        else
        {
            p[n - 1][m - 1] = 'B';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << p[i][j];
        }
        cout << "\n";
    }
}

void Test_C()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<double> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    double ans = -1;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, ((nums[i] - nums[i - 1]) / 2));
    }

    double num = max({ nums[0], ans, k - nums.back() });
    printf("%.10lf\n", num);
}

void Test_D()
{
    int n = 0, m = 0;
    cin >> n >> m;

    if ((ll)m * m > n || n % 2 != m % 2)
    {
        cout << "NO" << "\n";
    }
    else
    {
        cout << "YES" << "\n";
    }
}

void Test_E()
{
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<int> nums(m + 1);
    for (int i = 0; i <= m; i++)
    {
        cin >> nums[i];
    }

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
    {
        ret[i] = nums[m] & 1;
        nums[m] >>= 1;
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int time = 0;
        bool ok = true;
        for (int j = 0; j < n; j++)
        {
            if ((nums[i] & 1) != ret[j])
            {
                ++time;
            }
            if (time > k)
            {
                ok = false;
                break;
            }
            nums[i] >>= 1;
        }
        if (ok)
        {
            ++ans;
        }
    }
    cout << ans << "\n";
}

//注意可以花钱多座站
void Test_F()
{
    int n = 0, m = 0, a = 0, b = 0;
    cin >> n >> m >> a >> b;

    if (a * m > b)
    {
        int ans = (n / m) * b;
        if ((n % m) * a > b)
        {
            ans += b;
        }
        else
        {
            ans += (n % m) * a;
        }
        cout << ans << "\n";
    }
    else
    {
        cout << n * a << "\n";
    }
}

void Test_G() {
    int n = 0;
    cin >> n;
    vector<int> nums;
    int mn = INT_MAX;
    while (n--) {
        int m = 0;
        cin >> m;
        int mn_1 = 0, mn_2 = 0;
        while (m--) {
            int num = 0;
            cin >> num;
            mn = min(mn, num);
            if (mn_1 == 0) {
                mn_1 = num;
            }
            else {
                if (num < mn_1) {
                    mn_2 = mn_1;
                    mn_1 = num;
                }
                else {
                    if (mn_2 == 0) {
                        mn_2 = num;
                    }
                    else {
                        if (num < mn_2) {
                            mn_2 = num;
                        }
                    }
                }
            }
        }
        nums.push_back(mn_2);
    }

    int index = 0, min_num = nums[0];
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] < min_num) {
            index = i;
            min_num = nums[i];
        }
    }

    int ans = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (i != index) {
            ans += nums[i];
        }
    }
    cout << ans + mn << "\n";
}

void Test_H()
{
    int n = 0, m = 0;
    cin >> n >> m;
    if (m > n)
    {
        cout << "NO" << "\n";
    }
    else if (m == n)
    {
        cout << "YES" << "\n";
    }
    else
    {
        priority_queue<int> pq;
        pq.push(n);
        while (!pq.empty())
        {
            int ret = pq.top();
            pq.pop();
            if (ret % 3 == 0)
            {
                if (ret / 3 == m || ret / 3 * 2 == m)
                {
                    cout << "YES" << "\n";
                    return;
                }
                pq.push(ret / 3);
                pq.push(ret / 3 * 2);
            }
        }
        cout << "NO" << "\n";
    }
}

void Test_I()
{
    int n = 0;
    cin >> n;
    vector<int> nums;
    map<int, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        if (!hash_map.count(num))
        {
            nums.push_back(num);
        }
        hash_map[num]++;
    }

    int mx = -1;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        mx = max(mx, hash_map[nums[i]]);
    }

    if (mx > nums.size() - 1)
    {
        if (mx == nums.size())
        {
            cout << nums.size() - 1 << "\n";
        }
        else
        {
            cout << nums.size() << "\n";
        }
    }
    else
    {
        cout << mx << "\n";
    }
}

void Test_J()
{
    int n = 0;
    cin >> n;
    char a;
    cin >> a;
    string s;
    cin >> s;

    if (a == 'g')
    {
        cout << 0 << "\n";
        return;
    }

    vector<int> color, green;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'g')
        {
            green.push_back(i);
        }
        else if (s[i] == a)
        {
            color.push_back(i);
        }
    }

    sort(color.begin(), color.end());
    sort(green.begin(), green.end());
    int mx = -1;
    for (int i = 0; i < (int)color.size(); i++)
    {
        int left = 0, right = green.size();
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (green[mid] < color[i])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int ans = (left == green.size() ? n - color[i] + green[0] : green[left] - color[i]);
        mx = max(mx, ans);
    }
    cout << mx << "\n";
}

int main()
{
    int test = 0;
    cin >> test;
    while (test--) {
        Test_G();
    }
    return 0;
}