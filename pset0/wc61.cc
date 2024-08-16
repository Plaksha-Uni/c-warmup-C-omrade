// code for counting words and lines
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cctype>
int main(){
    int count_lines = 0;
    int count_bytes = 0;
    int count_words = 0;
    char prev = ' ';
    while(true){
        
        char c = fgetc(stdin);
        if(c==EOF){
            if(!isspace(prev) && prev!='\0'){
                count_words++;
            }
            break;}
        count_bytes++;
        if(isspace(c) && prev!=c && c!='\n'){
            count_words++;
    
        }
        if(c=='\n'){
            count_lines++;
        }
        prev = c;
    }
    fprintf(stdout,"%d %d %d\n",count_lines,count_words,count_bytes);
    exit(0);
}