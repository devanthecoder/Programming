#include <iostream>
#include <vector>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector <int> v;
    for(int i=0;i<T;i++){
        int n;
        cin >> n;
        string a;
        cin >> a;
        int m;
        cin >> m;
        string b,c;
        cin >> b >> c;
        for(int i=0;i<m;i++){
            a = (c[i]=='D')?(a+b.at(i)):(b.at(i) + a);
        }
        cout << a << endl;
    }
}