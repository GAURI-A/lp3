#include<iostream>
using namespace std;
void iterative(int n){
 
    int previous = 0;
    int current = 1;
    int next;

    cout<<previous <<" ";
    cout<<current<<" ";
    for (int i = 2; i <= n; i++) {
        next = previous + current;
        previous = current;
        current = next;
        cout<<next<<" ";
    }
    cout<<endl;


    
}
int recursive(int n) {
    if (n <= 1) {
        return n;
    }
   
    return recursive(n - 1) + recursive(n - 2);
}
int main(){
    int n;
    cin>>n;

    iterative(n);

    for(int i=0;i<=n;i++){
        cout<<recursive(i)<<" ";
    }cout<<endl;


    return 0;

}