#include <bits/stdc++.h>
using namespace std;
void Merge(const vector<int> &vec, vector<int> &answer, int left, int right);
int main()
{ 
    vector<int> vec;
    vector<int> answer;
    for(int i=0;i<100;i++) vec.push_back(rand()%1000);
    Merge(vec,answer,0,99);
    for(auto i:answer) cout<<i<<",";
    return 0;
}

void Merge(const vector<int> &vec, vector<int> &answer, int left, int right)
{
    if (right == left)
    {
        answer.push_back(vec[left]);
        return;
    }
    vector<int> left_vec;
    vector<int> right_vec;
    Merge(vec, left_vec, left, right / 2);
    Merge(vec, right_vec, right / 2 + 1, right);
    for (int idx = left,left_idx=0,right_idx=0; idx <= right; idx++) 
    {   
        if(left_idx==left_vec.size()) answer.push_back(right_vec[right_idx++]); //왼쪽 다 탐색했을떄
        else if(right_idx==right_vec.size()) answer.push_back(left_vec[right_idx++]); //오른쪽 다 탐색했을때
        else if(left_vec[left_idx]>right_vec[right_idx]) answer.push_back(right_vec[right_idx++]); //비교해서 작은값넣기
        else answer.push_back(left_vec[left_idx++]); 
    }
    left_vec.clear();
    right_vec.clear();
}
