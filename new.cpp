#include <iostream>
//const int i;
int main(){
int i=12; sizeof(i);
int *pi= &i;
int* pf=new int ;
std::cout<<pf<<' '<<pi<<std::endl;
delete pf;
std::cout<<2147483647+1<<std::endl;
std::cout<<2147483647L+1<<std::endl;
int k{2147483647};
int l=2147483648;
long int m{2147483649};
std::cout<<k<<std::endl;
std::cout<<l<<std::endl;
std::cout<<m<<std::endl;
bool i{true};
if (i){}else{};
}