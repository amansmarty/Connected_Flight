#include<iostream>
using namespace std;
int main() {
    char b[]="xyz";
    char* c=&b[1];
    cout<<++c<<endl;
    cout<<c<<endl;
    
    return 0;
}