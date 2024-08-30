#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        string s;
        int num;
        cin >> s >> num;
        mp[s].push_back(num);
    }
    for (auto it : mp)
    {
        sort(it.second.begin(), it.second.end(), greater<int>());

        for (int val : it.second)
        {
            cout << it.first << " " << val << endl;
        }
    }
    return 0;
}