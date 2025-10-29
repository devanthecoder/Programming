#include <iostream>
using namespace std;
int GCD(int a, int b){
    if(!(a%b)) return b;
    return GCD(b, a%b);
}
int LCM(int a, int b){
    return (a*b)/GCD(a,b);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        cout << !((LCM(a,b)/a)==1) + !((LCM(a,b)/b)==1) << endl;
    }
}