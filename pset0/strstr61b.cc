#include <cstring>
#include <cassert>
#include <cstdio>

char* mystrstr(const char* s1, const char* s2) {
    const char* s1_ptr = s1;
    const char* s2_ptr = s2;
    bool big_flag = 0;
    while(*s1!='\0' && *s2!='\0'){
        if(*s1!=*s2){
            s1++;
        }
        else{
            s1_ptr = s1;
            s2_ptr = s2;
            bool flag = 1;
            while(*s2_ptr!='\0' && *s1_ptr!='\0'){
                if(*s1_ptr==*s2_ptr){
                    s1_ptr++;
                    s2_ptr++;
                    continue;
                }
                else{
                    s1++;
                    flag = 0;
                    break;
                }
            }
            if(flag){
                big_flag=1;
                break;
            }
        }
    }
    if(big_flag){
        return (char*) s1;
    }
    return nullptr;
}

int main(int argc, char* argv[]) {
    assert(argc == 3);
    printf("strstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], strstr(argv[1], argv[2]));
    printf("mystrstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], mystrstr(argv[1], argv[2]));
    assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));
}