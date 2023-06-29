#include <bits/stdc++.h>
using namespace std;
string sKey[12] = {
    "", "abc", "def",
    "ghi", "jkl", "mno",
    "pqrs", "tuv", "wxyz",
    "", " ", ""};
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        // Moi_Truong_Hop_Test_Duoc_Thuc_Hien_O_Day
        string sLine;
        getline(cin, sLine);
        int res = 0;
        for (int i = 0; i < sLine.size(); i++)
        {
            int cur;
            for (int j = 0; j < 12; j++)
            {
                for (int k = 0; k < sKey[j].size(); k++)
                {
                    if (sLine[i] == sKey[j][k])
                    {
                        cur = k + 1;
                    }
                }
            }
            res += cur;
        }
        cout <<"Case #<<"<<t + 1<<": "<<res;
    }
    return 0;
}