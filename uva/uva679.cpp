
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=(1<<21)+10;
int main(){
    int  n,d,l;
    scanf("%d",&n);
    int p=0;
    while(n--){
        int flag=1;
        scanf("%d %d",&d,&l);
        d-=1;
        while(d--){
            if(l%2==0){
                l/=2;
                flag=flag*2+1;
            }
            else{
                l=(1+l)/2;
                flag*=2;
            }
        }
        printf("%d\n",flag);
    }
    return 0;
}