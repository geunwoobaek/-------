#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void reverse(string &s,int i,int n){
    for(;i<n;)
    { swap(s[i++],s[n--]); }
}
bool nextPermutation(string& s)
{
    // 1. s(수열)에 대해서 s[i-1]<s[i]를 만족하는 가장 큰수를 찾는다.
    // 2. 1번에서 찾은 i-1에 대하여 s[i-1]<s[j]를 만족하는 가장 큰 j를 찾는다
    // 3. s[i-1] s[j]를 바꿔치기한다.
    // 4. s[i..n-1]를 reverse시킨다.
    int i, j;
    i = j = s.size()-1;
    while (s[i - 1] >= s[i]) if (--i== 0) return false; //1번에 해당하는 i찾기
    while(s[j]<=s[i-1]) if(--j==0) return false; //2번에 해당하는 j찾기
    swap(s[j],s[i-1]);
    reverse(s,i,s.size()-1);
    return true;
}
int main(){
    string s="1234";
    while(nextPermutation(s)){
        cout<<s<<"\n";
    }
    return 0;
}
