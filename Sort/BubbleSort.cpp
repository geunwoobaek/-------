#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> vec;
int BubbleSort(vector<int> &vec){
    //한번실행할때마다 무조건 오른쪽으로 최소 하나씩정렬됨
    //만약정렬되지 않으면탈출
    int swap_cnt=0;
    int length=vec.size();
    for(int i=length-1;i>0;i--){
        int swap_this_turn=0;
        for(int j=0;j<i;j++){
            if(vec[j]>vec[j+1]) {
                swap(vec[j],vec[j+1]);
                swap_this_turn++;
            }
        }
        swap_cnt+=swap_this_turn;
        if(swap_this_turn==0) break;
    }
    return swap_cnt;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>N;vec.resize(N);
for(int i=0;i<vec.size();i++) cin>>vec[i];
cout<<BubbleSort(vec);
return 0;
}