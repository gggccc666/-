#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
const int MAXN=1010;
vector <string> allword[MAXN];
int main(){
    size_t maxlength[200]={0};//
    string line,word;
    int linecnt=0;
    while(getline(cin,line)){
        int i=0;
        stringstream ss(line);
        while(ss>>word){
            maxlength[i]=max(maxlength[i],word.length());
            i++;
            allword[linecnt].push_back(word);
                   
        }
    linecnt++;
    }
    for(int i=0;i<linecnt;i++){
        for(int j=0;j<allword[i].size();j++){
            if(j<allword[i].size()-1)
            cout<<left<<setw(maxlength[j]+1)<<allword[i][j];
            else 
            cout<<left<<allword[i][j];
        }
        cout<<endl;
    }
    return 0;
}