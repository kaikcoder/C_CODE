/* 求对角线上元素之和 */
#include<stdio.h>
int main(){
    int a[4][4] = {0};
    int i = 0,j = 0,sum = 0;
    /* 输入数组 */
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d",&a[i][j]);
        }
    }
    /* 求对角线上元素之和 */
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(i == j || i+j == 3){
                  sum += a[i][j];
            }
        }
    }
    printf("对角线上的元素之和为%d",sum);
    return 0;
}