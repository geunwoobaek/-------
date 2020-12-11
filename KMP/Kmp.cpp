#include <bits/stdc++.h>
using namespace std;
vector<int> makePi(const string &str)
{
    int i = 1, j = 0; //twopointer
    int length = str.length();
    vector<int> pi(length, 0);
    while (i < length)
    {
        if (str[j] == str[i])
        { //samepatern
            pi[i++] = ++j;
        }
        else if (j == 0)
            i++;
        else
            j = pi[j - 1];
    }
    return pi;
}
void searchKmp2(const vector<int> &pi, const string &pattern, const string &str)
{
    for(int j=0,i=0;j<str.length();j++) //i=pattern의 위치 j=str의 위치
    {
        if (pattern[i] == str[j])
        {
            if (++i == pattern.length())
                {
                    cout << "end_pos=" << j << "\n"; 
                    i=0;
                }
        }
        else i = pi[i]+1;
    }
}
int main()
{
    string pattern = "abcacabc";
    string str = "asdadqwabcacabccascabcacabccwqeda";
    vector<int> pi = makePi(pattern);
    searchKmp2(pi,pattern,str);
    return 0;
}