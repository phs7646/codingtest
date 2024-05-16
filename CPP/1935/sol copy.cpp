#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
map <char,int> m;
stack <double> s; //후위 연산을 위한 스택
float operate(string exp){
    for(int i=0;i<exp.length();i++){
        if(exp[i]>='A'&&exp[i]<='Z'){
            //숫자로 변환하기
            s.push(m[exp[i]]);
        }
        else{
            float c1,c2;
            //연산자가 들어올 경우
            if(exp[i]=='+'){
                c1=s.top();
                s.pop();
                c2=s.top();
                s.pop();
                s.push(c1+c2);
            }
            else if(exp[i]=='-'){
                c1=s.top();
                s.pop();
                c2=s.top();
                s.pop();
                s.push(c2-c1);
            }
            else if(exp[i]=='/'){
                c1=s.top();
                s.pop();
                c2=s.top();
                s.pop();
                s.push(c2/c1);
            }
            else{
                //곱하기일경우
                c1=s.top();
                s.pop();
                c2=s.top();
                s.pop();
                s.push(c2*c1);
            }
        }
    }
    return s.top();
}
int main(void)
{
    int n;
    cin>>n;
    string exp="";
    cin>>exp;
    for(int i=0;i<n;i++){
        char c =char('A'+i);
        int value;
        cin>>value;
        m.insert({c,value});
    }
    //계산하면 됨
    printf("%.2f", operate(exp));
    //cout<<operate(exp);
    return 0;
}