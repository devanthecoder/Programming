// #include <stdio.h>
// #include <math.h>

// // Recursive function to multiply two numbers
// long long int fastMultiply(long long int x, long long int y, int n) {
//     if(n==1){
//         return x*y;
//     }
// int m = (n+1)/2;
// long long int div = pow(10,m);
// long long int a=x/div,b=x%div;
// long long int c = y/div,d=y%div;
// long long int ac = fastMultiply(a,c,m),bd=fastMultiply(b,d,m), ad = fastMultiply(a,d,m), bc=fastMultiply(b,c,m);

// /*ac,bd,ad,bc are variables as defined in the problem statement.
// Code to compute them correctly should have been filled above.
// current_product is the variable that has to hold the product computed in this function call.
// It's definition is partially filled for you in the statement below. Complete it. Do not change anything in the part of the formula we already wrote below.*/
//     long long int current_product=ac * (long long int)pow(div, 2)+ (ad+bc)*div + bd; 
    
//     //Keep the below two statements in the function as it is. Do not change them.
//     printf("The ac, bd, ad and bc are : %lld %lld %lld %lld. The partial prodcut=%lld\n", ac, bd, ad, bc,current_product);
//     return current_product;
// }

// //DO NOT CHANGE ANYTHING BELOW

// int main() {
//     long long int x, y;
//     int n;
    
//     // Input: two numbers and number of digits
//     scanf("%lld %lld %d", &x, &y, &n);
    
//     // Calculate the result using fast multiplication
//     long long int result = fastMultiply(x, y, n);
    
//     // Output the result.
//     printf("Product of %lld and %lld is: %lld\n", x, y, result);
    
//     return 0;
// }
#include <stdio.h>

// Recursive function to multiply two numbers
long long int fastMultiply(long long int x, long long int y, int n) {
    if (n == 1) {
        return x * y;
    }
    
    int m = (n + 1) / 2;
    long long int div = 1;
    for (int i = 0; i < m; i++) {
        div *= 10;  // Correct integer-based division
    }
    
    long long int a = x / div, b = x % div;
    long long int c = y / div, d = y % div;
    
    long long int ac = fastMultiply(a, c, m);
    long long int bd = fastMultiply(b, d, m);
    long long int ad = fastMultiply(a, d, m);
    long long int bc = fastMultiply(b, c, m);
    
    long long int current_product = ac * div * div + (ad + bc) * div + bd;
    
    printf("The ac, bd, ad and bc are : %lld %lld %lld %lld. The partial product=%lld\n", ac, bd, ad, bc, current_product);
    
    return current_product;
}

// DO NOT CHANGE ANYTHING BELOW

int main() {
    long long int x, y;
    int n;
    
    // Input: two numbers and number of digits
    scanf("%lld %lld %d", &x, &y, &n);
    
    // Calculate the result using fast multiplication
    long long int result = fastMultiply(x, y, n);
    
    // Output the result.
    printf("Product of %lld and %lld is: %lld\n", x, y, result);
    
    return 0;
}
