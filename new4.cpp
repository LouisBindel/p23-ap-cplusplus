#include <iostream>

void swap(int* x,int* y){
int aux= *x; *x=*y;*y=aux;
}

int main(){


int a =17;
int b = 1;
swap(&a,&b);
std::cout<<(a==1)<<std::endl;

}