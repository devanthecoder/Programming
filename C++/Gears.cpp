#include <iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int arr[n], freq[101]={0};
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        int isDupli=false;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            if(freq[arr[i]]>1){
                isDupli = true;
                break;
            }
        }
        if(isDupli)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}