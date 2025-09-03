//我们可以通过LR序号计算出一个节点的编号，能否通过层次建立一个二叉树？
//或者我们没必要建立一颗树，只需要判断能否构成一颗根据其序号排序输出？
//我们根据序号创建一个结构体，放入集合里面，再按顺序输出就可以
//那么关键就是判断是否能够形成一棵树
//判断重复简单，放入集合的时候就判断，如果相等(相等但值不一样，没说清楚)就not complete
//判断双亲节点是否缺失也简单，我们每放入一个节点，就判断其双亲节点是否存在
//1.成功读取，考虑把scanf字符串放在while循环里面，然后调获取value和位置。
//我们遇到()就输出树的值，并清空树
//2.建立树：创建函数传入value和位置，从根节点开始，根据步数，没有节点就创建
//直到走到对应位置，并赋值
//3.遍历，采用BFS宽度优先遍历，用队列，取出一个节点就放入其两个子节点
#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<sstream>
#define LOCAL
using namespace std;
const int mlen=260;
struct BiTree{//c++不需要typedef，struct完就是类型名
    int value;
    struct BiTree *lchild,*rchild;
    BiTree():value(-1),lchild(NULL),rchild(NULL){}
};
BiTree *root=new BiTree;
bool CreateTree(char *s);
bool TraverseTree(int *len_2,int *arr);
int main(){
    //读入s，如果长为2说明读入括号，则遍历树并输出，再初始化树
    //权且不管内存泄露问题
    char s[mlen];
    int num[mlen];
    bool flag=0;
    int len=0;
    #ifdef LOCAL
    freopen("uva.out","w",stdout);
    freopen("uva.in","r",stdin);
    #endif
    do{
        memset(s,0,mlen);
        scanf("%s",s);
        if(strlen(s)==0)return 0;
        if(strlen(s)==2){
            int length=0;
            if(flag==1){
                printf("not complete\n");
                len=0;flag=0;
            }
            else if(!TraverseTree(&length,num)){
                printf("not complete\n");
                len=0;
            }
            else if(len!=length){
                printf("not complete\n");
                len=0;
            }
            else {
                for(int i=0;i<length;i++){
                if(i)printf(" ");
                printf("%d",num[i]);
            }
            printf("\n");
            len=0;
        }
            root->value=-1;root->lchild=NULL;root->rchild=NULL;
        }
        else {
            bool a=CreateTree(s);
            if(!a)flag=1;
            len++;
        }
    }
    while(1);
    return 0;
}
bool CreateTree(char *s){//给出节点构造字符，构造对应节点，重复将输出0
    //(12345，LLRR)
    BiTree *TempTree=root;
    char *pos=strchr(s,',');
    int va;
    sscanf(s+1,"%d",&va);
    int length=strchr(s,')')-pos-1;
    if(length==0){
        if(root->value==-1){
            root->value=va;
            return 1;
        }
        else return 0;
    }
    for(int i=0;i<length;i++){
        if(*(pos+i+1)=='L'){
            if(TempTree->lchild==NULL)
                TempTree->lchild=new BiTree;
            TempTree=TempTree->lchild;
        }
        else{
            if(TempTree->rchild==NULL)
                TempTree->rchild=new BiTree;
            TempTree=TempTree->rchild;
        }
    }
    if(TempTree->value==-1){
        TempTree->value=va;
        return 1;
    }
    else return 0;
}
bool TraverseTree(int *len_2,int *arr){//给一个int数组地址，如果树是正确的，返回一并填充数组
    int i=0;
    queue <BiTree> que;
    que.push(*root);
    while(!que.empty()){
        BiTree temp=que.front();
        que.pop();
        if(temp.value==-1)return 0;
        else arr[i++]=temp.value;
        if(temp.lchild!=NULL)que.push(*(temp.lchild));
        if(temp.rchild!=NULL)que.push(*(temp.rchild));
    }
    *len_2=i;//刚好等于树的个数
    return 1;
}