char* create_tab(int n){
char* i = new char[n];
return i;
};

int main(){
int m=3; char* tabl = create_tab(m); delete tabl; int k=12; int* pi=&k; (*pi)= (*pi)+1; int& ri =k;
}