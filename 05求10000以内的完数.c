/* 找出10000以内的所有完数 */
#include<stdio.h>
#include<math.h>
int main(){
    int n = 0,m = 0,i = 0,s = 0;
    for(n=2;  n<10000; n++){
        s = 1;
        m = sqrt(n);
        for(i=2; i<=m; i++){
            if(n%i == 0){
                s += i +n/i;
            }
        }
        if(n == m*m){
            s = s-m;
        }
        if(s == n){
            printf("完数有：%d\n",s);
        }
    }
    return 0;
}