#include <iostream>

int main(){
char c;
std::cout<<"entrez un caractère "<<std::endl;
std::cin>>c;
if (c=='q'){std::cout<<'q'<<std::endl;}
else{std::cout<<"pas q"<<std::endl;};
char d;
do {std::cout<<"entrez un caractère "<<std::endl;
std::cin>>d;}while(d !='q');
char e;
while(e!='q'){std::cout<<"entrez un caractère "<<std::endl;
std::cin>>e;};
}