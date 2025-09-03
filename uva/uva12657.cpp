#include<iostream>
#include<sstream>
using namespace std;
const int MAXN=100010;
void init(int n);
void insert(int a,int num);
void delete_(int a);
void move1(int x,int y);
void move2(int x,int y);
void exchange(int x,int y);
void reverse();
int idx=2;
int l[MAXN],r[MAXN],e[MAXN];
bool reversed=false;
int main(){
    int n,m;
    int times=0;
    while(cin>>n>>m){
        times++; 
        idx=2;      
        r[1]=0,l[0]=1;
        init(n);
        int j=m;
        reversed=false;
        while(j--){
            int num,x,y;
            scanf("%d",&num);
            if(num!=4)scanf("%d %d",&x,&y);                
            switch(num){ 
                case 1:if(reversed){move2(x+1,y+1);break;}else{move1(x+1,y+1);break;}
                case 2:if(reversed){move1(x+1,y+1);break;}else{move2(x+1,y+1);break;}
                case 3:exchange(x+1,y+1);break;
                case 4:reversed=!reversed;break;
            }
            
        }
        long long sum=0;
        bool add = true;
        if(!reversed)for(int i = r[1]; i != 0; i = r[i]){
            if(add) sum += e[i];
            add = !add;
        }
        else{
            for(int i = l[0]; i != 1; i = l[i]){
            if(add) sum += e[i];
            add = !add;
        }
        }
        cout<<"Case "<<times<<": "<<sum<<endl;
    }
    return 0;
}
void init(int n){
    for(int i=1;i<=n;i++)
        insert(i,i);
//编号i节点插入的是i-1
}
void insert(int a,int num){
    //在a后插入
    e[idx]=num;
    l[idx]=a,r[idx]=r[a];
    l[r[a]]=idx,r[a]=idx;
    idx++;
}
void delete_(int a){
    if(a==0||a==1)return;
    r[l[a]]=r[a];
    l[r[a]]=l[a];
}
void move1(int x,int y){
    if(x==l[y])return ;
    delete_(x);
    int z=l[y];
    l[x]=z,r[x]=y;
    r[z]=x,l[y]=x;
}
void move2(int x,int y){
    if(x==r[y])return ;
    delete_(x);
    int z=r[y];
    l[x]=y,r[x]=z;
    r[y]=x,l[z]=x;
}
void exchange(int x,int y){
    
    if (r[x] == y) {
        // x 和 y 相邻，x 在 y 左边
        int lx = l[x], ry = r[y];
        r[lx] = y; l[y] = lx;
        r[y] = x; l[x] = y;
        r[x] = ry; l[ry] = x;
        return ;
    }
    else if (r[y] == x) {
        // y 和 x 相邻，y 在 x 左边
        exchange(y, x);  // 直接调用上面情况
        return ;
    }
    int lx=l[x],rx=r[x];
    int ly=l[y],ry=r[y];
    l[x]=ly,r[x]=ry;
    r[ly]=x;l[ry]=x;
    l[y]=lx,r[y]=rx;
    r[lx]=y,l[rx]=y;
}


