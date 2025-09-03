#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
typedef struct Matrix{
    int vertical;
    int horizontal;
    Matrix():vertical(0),horizontal(0){}
    Matrix(int v,int h):vertical(v),horizontal(h){}
}matrix;
matrix arr[26];
int getnum(string a);
int main(){
    int n;
    cin>>n;
    while(n--){
        char name;
        cin>>name;
        cin>>arr[name-'A'].vertical;
        cin>>arr[name-'A'].horizontal;
    }
    string equation;
    getchar();
    while(getline(cin,equation)){
        int num=getnum(equation);
        if(num==-1) cout<<"error"<<endl;
        else cout<<num<<endl;
    }
}
int getnum(string a){
    if(!(a.length()-1))return 0;
    else{
        int cnt=0;
        stack <matrix> m;
        for(int i=0;i<a.length();i++){
            char alpha=a.at(i);
            if(isalpha(alpha))m.push(arr[alpha-'A']);
            else if(alpha==')'){
                matrix temp_1=m.top();
                m.pop();
                matrix temp_2=m.top();
                m.pop();
                if(temp_1.vertical!=temp_2.horizontal)return -1;
                else {cnt+=temp_1.vertical*temp_1.horizontal*temp_2.vertical;
                matrix temp_3(temp_2.vertical,temp_1.horizontal);
                m.push(temp_3);
                }
            }
        }
        return cnt;
    }
}