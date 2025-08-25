#include <iostream>
#include <vector>
using namespace std;
long long int Power3(int r){
    long long int res = 1;
    for(int i=0;i<r;i++)res*=3;
    return res;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        long long int n;
        cin >> n;
        vector <int> v;
        int temp=n;
        while(temp>0){
            v.push_back(temp%3);
            temp/=3;
        }
        long long int res1=0;
        for(int i=0;i<v.size();i++){
            // cout << v[i] << endl;
            res1 += v[i]*i*Power3(i-1);
        }
        cout << (unsigned long long int)res1+3*n<<endl;
    }
}