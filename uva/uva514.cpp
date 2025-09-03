/*
先进后出，是栈
我们利用栈实现这样一个算法，假设指定顺序为q[n]，模拟栈为a。
对于一个q[i]而言，要么等于栈顶元素，要么大于栈顶元素，还未入栈
所以我们对q从头开始扫，若是栈为空或者栈顶小于q[i]，则栈顶元素到q[i]之间得元素入栈
若是小于栈顶，结束
若是等于栈顶，出栈一个
*/
#include<iostream>
#include<stack>
using namespace std;
stack <int> all;
bool judge(int *q,int n);
int main(){
    int n;
    while(scanf("%d",&n)&&n!=0){
    int arr[n];
    while(1){
    cin>>arr[0];
    if(!arr[0]){
        cout<<"\n";
        break;
    }
    else{
    for(int i=1;i<n;i++)cin>>arr[i];
    cout<<(judge(arr,n)?"Yes\n":"No\n");
    }
}
}
return 0;
    }
bool judge(int *q,int n){
    while(!all.empty())all.pop();
    int i=0,maxn=0;
    for(;i<n;i++){
        if(all.empty()||q[i]>all.top()){
            for(int k=maxn;k<q[i]-1;k++)all.push(k+1);
            maxn=q[i];
        }
        else if(q[i]<all.top())return 0;
        else if(q[i]==all.top())all.pop();
    }
    return 1;
}
