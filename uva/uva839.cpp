//本题看测试数据应该是要每个天平都平衡才可以，所以我们维护一个全局变量记录是否存在天平不平衡
//递归函数我们返回子天平的重量和，如果某一边为零就递归得到这边的子天平之和，
#include<iostream>
#include<sstream>
using namespace std;
bool if_mobile=1;
int cal_balance();
int main(){
    int n;
    cin>>n;
    getchar();
    while(n--){
        string white;
        getline(cin,white);
        if_mobile=1;
        cal_balance();
        if(if_mobile)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(n)cout<<endl;
    }
    return 0;
}
int cal_balance(){
    string a;
    getline(cin,a);
    istringstream iss(a);
    int w1,d1,w2,d2;
    iss>>w1>>d1>>w2>>d2;
    if(w1==0)w1+=cal_balance();
    if(w2==0)w2+=cal_balance();
    if(w1*d1!=w2*d2||d1==0||d2==0)if_mobile=0;
    return w1+w2;
}