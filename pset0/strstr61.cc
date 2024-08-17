#include <cstring>
#include<cassert>
#include<cstdio>
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
// char* mystrstr(const char* s1, const char* s2){
//     int s1_len = strlen(s1);
//     int s2_len = strlen(s2);
//     if(s1_len<s2_len){return nullptr;}
//     //intial answer_pointer will be the starting index
//     int s1_start = 0;
//     int s2_start = 0;
//     int curr_ans_pos = 0;
//     int big_flag = 0;
//     while(s1_start<=s1_len-s2_len){
//         if(s1[s1_start]!=s2[s2_start]){
//             s1_start++;
//             continue;
//         }
//         else{
//             curr_ans_pos = s1_start;
//             int flag = 0;
//             for(int i=0;i<s2_len;i++){
//                 if(s1[curr_ans_pos]==s2[i]){
//                     curr_ans_pos++;
//                     continue;
//                 }
//                 else{
//                     s1_start++;
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag==0){
//                 // we have got the answer
//                 big_flag = 1;
//                 break;
//             }
//         }
//     }
//     if(big_flag){
//         return (char*)s1+s1_start;
//     }
//     return nullptr;
// }
int main(int argc, char* argv[]){
    assert(argc==3);
    printf("strstr(\"%s\",\"%s\") = %p\n", argv[1],argv[2],strstr(argv[1],argv[2]));
    printf("mystrstr(\"%s\", \"%s\") = %p\n", argv[1], argv[2], mystrstr(argv[1], argv[2]));
    assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));
}