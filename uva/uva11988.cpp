#include<iostream>
#include<string>
using namespace std;
const int MAXN=100010;
int ne[MAXN];
int main(){
    string arr;
    while(getline(cin,arr)){
        int len=arr.size();
        int p=0,behind=0;
//用behind表示最后一个字符的位置，让ne指向-1表示没有数了
        ne[0]=-1;
        for(int i=0;i<len;i++){
            if(arr[i]=='['){
                p=0;
            }
            else if(arr[i]==']'){
                p=behind;
            }
            else{
//无非就是考虑ne[]怎么变，p和behind怎么变
//ne[i]指向ne[p]原来指向的索引，然后被ne[p]插入
//p要被更新为i，即新插入的那个，为光标所在处
                ne[i+1]=ne[p];
                ne[p]=i+1;
                if(behind==p)behind=i+1;
                p=i+1;
            }
        }
        for(int i=ne[0];i+1;i=ne[i])printf("%c",arr[i-1]);
        cout<<endl; 
    }
return 0;
}