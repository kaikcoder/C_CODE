/* 十进制转换为四进制 */
/* 模4除4 */
#include<stdio.h>
#define N 4
long conv(int a){
    static long b = 0;
    int r;
    if(a!=0){
        r = a%N;
        conv(a/N);
        b = b*10+r;
    }
}
int main(){
    long after;
    int before;
    printf("输入一个整数：");
    scanf("%d",&before);
    after = conv(before);
    printf("before:%d after:%ld\n",before,after);
    return 0;
}
