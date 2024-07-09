#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string init,temp;
int A,B;
long long timeslength;
long long maxima = 1000000100;


long long fastexp(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
            if(result > maxima) return maxima;
        }
        base *= base;
        if(base > maxima) return maxima;
        exp /= 2;
    }
    return result;
}
long long calculate(int times) {
    if(A == 0) return init.size();
    if(A == 1) return init.size() + times * B;
    long long Aton = fastexp(A,times);
    long long left = init.size() * Aton;
    long long right = B * (Aton-1) / (A-1);
    return left+right;
}

string recur(int times,int start,int end) {
    //cout << "Func called with " << times << " " << start << " " << end << endl;
    int pos = 0;
    if(times == 0) {
        return init.substr(start,end+1-start);
    }
    string ret;
    long long left = 0;
    long long len = calculate(times-1);
    //cout << "current len is " << len << endl;
    while(pos < temp.size()) {
        long long right = left;
        if(temp[pos] == '$') right += len;
        else right += 1;

        if(end < left) {
            break;
        } else if(start < right) {
            if(temp[pos] == '$') {
                long long distright = end < right?end : right;
                long long distleft = start < left? 0 : start-left;
                ret.append(recur(times-1,distleft,distright-left));
            } else {
                ret.push_back(temp[pos]);
            }
        }
        left = right;
        pos++;
    }
    //cout << "returning " << ret << endl;
    return ret;
}

int main() {
    cin >> init;
    cin >> temp;
    int times;
    cin >> times;
    int start,end;
    cin >> start >> end;
    start--;
    end--;
    for(char c : temp) {
        if(c == '$') A++;
        else B++;
    }
    string answer;
    if(A == 1) {
        string init2 = temp.substr(1,temp.size()-1);
        long long realend = init.size() + times * B -1;
        realend = realend < end?realend : end;
        for(int i = start;i <= realend;i++) {
            if(i < init.size()) answer.push_back(init[i]);
            else {
                int pos = i - init.size();
                answer.push_back(init2[pos%init2.size()]);
            }
        }
    } else {
        int realtimes = 0;
        long long curlength = init.size();
        while(realtimes < times) {
            curlength = A * curlength + B;
            if(curlength > maxima) break;
            if(curlength > end) {
                realtimes++;
                break;
            }
            realtimes++;
        }
        answer = recur(realtimes,start,end);
    }
    while(answer.size() < end-start+1) answer.push_back('-');
    cout << answer;

    return 0;
}