/* ��Խ�����Ԫ��֮�� */
#include<stdio.h>
int main(){
    int a[4][4] = {0};
    int i = 0,j = 0,sum = 0;
    /* �������� */
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            scanf("%d",&a[i][j]);
        }
    }
    /* ��Խ�����Ԫ��֮�� */
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(i == j || i+j == 3){
                  sum += a[i][j];
            }
        }
    }
    printf("�Խ����ϵ�Ԫ��֮��Ϊ%d",sum);
    return 0;
}