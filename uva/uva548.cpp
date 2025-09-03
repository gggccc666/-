//已知中序和后序，尝试通过序列建立树
//关键是如何通过中序和后序递归确定子树？
//对于一串数，我们通过后序的最后的一个数即为根，再在中序里面找到根，左右数列即为子树。
//我们每次将根值赋给value，当数串长度只有根的时候就return。注意讨论左/右子树为空的情况
//最短路径我们通常用深度优先DFS遍历
//初步考虑createtree或main读取函数或者main里面调用两个函数？的问题
//初步排除dfs逻辑问题，初步排除createtree函数递归调用的参数问题
//初步排除createtree的逻辑问题
//每次叶子输出为零，我们改变叶子的初值为6，输出六，也就是叶子改变的逻辑没变。
//输出num，和in[]，post[],能正常输出，没问题
#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
using namespace std;
const int maxn=10010;
struct node{
    int value;
    struct node * lchild;
    struct node * rchild;
    node():value(-1),lchild(NULL),rchild(NULL){}
};
int in[maxn],post[maxn],maxsum,leave;
node *root;
//全局变量 root,in,post,maxsum,leave
void CreateTree(node *TempTree,int StaIn,int EndIn,int StaPo,int EndPo){
    TempTree->value=post[EndPo];
    if(StaPo==EndPo){
        TempTree->lchild=NULL;TempTree->rchild=NULL;
        return ;
    }
    int i;
    for(i=StaIn;i<EndIn+1;i++) if(in[i]==post[EndPo])break;
    if(i==StaIn) TempTree->lchild=NULL;
    else {
        TempTree->lchild=new node;
        CreateTree(TempTree->lchild,StaIn,i-1,StaPo,StaPo+i-1-StaIn);
    }
    if(i==EndIn) TempTree->rchild=NULL;
    else{
        TempTree->rchild=new node;
        CreateTree(TempTree->rchild,i+1,EndIn,StaPo+i-StaIn,EndPo-1);
    }
    return ;
}
void dfs(node *TempTree,int sum){    
    if(TempTree!=NULL)sum+=TempTree->value;
    if(TempTree->lchild==NULL&&TempTree->rchild==NULL){
        if(sum<=maxsum){            
            if(sum==maxsum){
                if(TempTree->value<leave)leave=TempTree->value;
            }
            else {
                maxsum=sum;
                leave=TempTree->value;
            }
        }
        return ;
    }
    if(TempTree->lchild!=NULL)dfs(TempTree->lchild,sum);
    if(TempTree->rchild!=NULL)dfs(TempTree->rchild,sum);
    return ;
}
int main(){
    while(1){
        maxsum=100000000;leave=0;root=new node;
        memset(in,0,maxn);memset(post,0,maxn);
        string a,b;
        getline(cin,a);getline(cin,b);
        if(a.empty())break;
        int num,count=0;
        istringstream issa(a);
        while(issa>>num){in[count++]=num;}
        count=0;
        istringstream issb(b);
        while(issb>>num)post[count++]=num;
        CreateTree(root,0,count-1,0,count-1);
        dfs(root,0);
        cout<<leave<<endl;
    }
}

