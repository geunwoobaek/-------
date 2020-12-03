#include <bits/stdc++.h>
#define Max 20
using namespace std;
int SegmentTree[2 * Max];
int length;
int MakeSegmentTree(int num, int *arr, int left, int right)
{
    if (num >= length)
        return SegmentTree[num] = arr[num - length];
    int LeftValue = MakeSegmentTree(num * 2, arr, left, right / 2);
    int RightValue = MakeSegmentTree(num * 2 + 1, arr, right / 2 + 1, right);
    SegmentTree[num] = LeftValue + RightValue;
    return SegmentTree[num];
}
int query(int node, int left, int right, int start, int end)
{
    if (right < start || left > end)
        return 0; //범위 벗어날때
    if (left <= start && right >= end)
        return SegmentTree[node]; //해당하는 노드가 있을때
    int nextRight = (start + end) / 2 < right ? (start + end) / 2 : right;
    return query(node * 2, left, nextRight, start,  (start + end) / 2) + query(node * 2 + 1, (start + end) / 2 + 1, right, (start + end) / 2 + 1, end);
}
void update(int node, int value)
{
    SegmentTree[node+length]=value;
    for(int cur=node+length;cur>1;cur>>=1){
        SegmentTree[cur>>1]=SegmentTree[cur]+SegmentTree[cur+1];
    }
}
int main()
{
    int arr[] = {1,3,5,7,9,11}; 
    length = sizeof(arr) / sizeof(int);
    MakeSegmentTree(1, arr, 0, length);
    cout << query(1, 2, 6, 0, 7) << endl;
    cout << query(1, 0, 0, 0, 7) << endl;
    cout << query(1, 2, 2, 0, 7) << endl;
    cout << query(1, 1, 3, 0, 7) << endl;
    update(2, 1); 
    cout<<"";
    return 0;
}