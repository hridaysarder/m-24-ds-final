#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        map<string, int> mp;
        stringstream ss(s);
        string word,maxWord;
        int count = 0;
        while (ss >> word)
        {
            mp[word]++;
            if (mp[word] > count)
            {
                count = mp[word];
                maxWord = word;
            }
        }
        cout << maxWord << " " << count << endl;
    }
    return 0;
}