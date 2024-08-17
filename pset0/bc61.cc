// code for counting bytes 
#include<cstdlib>
#include<cstdio>

int main(){
    int bytes= 0;
    while(true){
        char c = fgetc(stdin);
        if(c==EOF){break;}
        bytes++;
    }
    fprintf(stdout,"%d\n",bytes);
    exit(0);
}