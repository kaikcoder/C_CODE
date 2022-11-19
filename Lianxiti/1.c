// 有1,2,3,4能组成多少个三位数
#include<stdio.h>
int main(){
    int i = 0;
    int count = 0;
    for(i=1; i<5; i++){
        int j = 0;
        for(j=1; j<5; j++){
            int k = 0;
            for(k=1; k<5; k++){
                if(i!=j && j!=k && i!=k){
                printf("%d,%d,%d\n",i,j,k);
                count++;
                }
            }
        }
    }
    printf("有%d个",count);
    return 0;
}