/* 文本文件 */
#include<stdio.h>
#include<stdlib.h>
#define N 5
#define Null 0
int write(int *s){
    FILE *fp = fopen("numbers.txt","wb");
    if(fp == Null){
        printf("文件打开失败");
        exit(0);
    }
    int i = 0;
    for(i=0; i<N; i++){
        fprintf(fp,"%d\n",s[i]);
    }
    return 0;
}
int main(){
    FILE *fp = fopen("numbers.txt","rb");
    if(fp == Null){
        printf("文件打开失败");
        exit(0);
    }
    int i = 0,j = 0;
    int temp = 0;
    int s[5] = {0};
    for(i=0; i<N; i++){
        fscanf(fp,"%d",&s[i]);
    }
    for(i=0; i<N-1; i++){
        for(j=0; j<N-1-i; j++){
            if(s[j] > s[j+1]){
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
    write(s);
    fclose(fp);
    fp = Null;
}