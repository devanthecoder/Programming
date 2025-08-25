#include <iostream>
// #include <cmath>
#include <vector>
using namespace std;
long long int Power10(int r){
    long long int res = 1;
    for(int i=0;i<r;i++)res*=10;
    return res;
}
int main(){
    int T;
    cin >> T;
    for(int i=0;i<T;i++){
        long long int n;
        cin >> n;
        int r=1;
        vector <long long int> v;
        while(n/(Power10(r)+1)>0){
            long long int factor = Power10(r)+1;
            // cout << factor << " " << n/factor << endl;
            if(n % factor==0){
                v.insert(v.begin(), (long long int)n/factor);
            }
            r++;
        }
        cout << v.size() << endl;
        for(long long int i:v) {
            if((i!=v[v.size()-1]))cout << i << " ";
            else cout << i << endl;
        }
    }
}