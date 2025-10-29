#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        string s = "NO";
        if((n%2) && (a%2) && (b%2))s="YES";
        if(!(n%2) && !(a%2) && !(b%2))s="YES";
        if((n%2) && !(a%2) && (b%2) && (b>a))s="YES";
        if(!(n%2) && (a%2) && !(b%2) && (b>a))s="YES";
        cout << s << endl;
    }
}