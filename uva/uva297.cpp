#include<iostream>
#include<cstring>
using namespace std;
const int lenth=32;
int inde=0;
bool picture[lenth][lenth];
void CreateTree(char * a,int lx,int ly,int rx,int ry);
void drew(int lx,int ly,int rx,int ry);
//全局变量picture,lenth,index
int main(){
    int n;
    cin>>n;
    while(n--){
        memset(picture,0,sizeof(picture));
        char a[10000],b[10000];
        cin>>a;cin>>b;
        inde=0;CreateTree(a,0,0,31,31);
        inde=0;CreateTree(b,0,0,31,31);
        int number=0;
        for(int i=0;i<lenth;i++){
            for(int j=0;j<lenth;j++)number+=picture[i][j];
        }
        cout<<"There are "<<number<<" black pixels."<<endl;
    }
}
//1:(lx+rx)/2+1,ly,rx,(ly+ry)/2
//2:lx,ly,(lx+rx)/2,(ly+ry)/2
//3:lx,(ly+ry)/2+1,(lx+rx)/2,ry
//4:(lx+rx)/2+1,(ly+ry)/2+1,rx,ry
void CreateTree(char * a,int lx,int ly,int rx,int ry){
    if(a[inde]=='p'){
        inde++;
        CreateTree(a,(lx+rx)/2+1,ly,rx,(ly+ry)/2);
        CreateTree(a,lx,ly,(lx+rx)/2,(ly+ry)/2);
        CreateTree(a,lx,(ly+ry)/2+1,(lx+rx)/2,ry);
        CreateTree(a,(lx+rx)/2+1,(ly+ry)/2+1,rx,ry);
    }
    else{
        if(a[inde]=='f'){
            inde++;
            drew(lx,ly,rx,ry);
        }
        else inde++;
    }
}
void drew(int lx,int ly,int rx,int ry){
    for(int i=ly;i<=ry;i++){
        for(int j=lx;j<=rx;j++)picture[i][j]=true;
    }
}