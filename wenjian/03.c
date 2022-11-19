#include<stdio.h>
#include<stdlib.h>
#define N 3
#define null 0
struct student{
    int id;//学号
    float height;//身高
}s[N];
int main ()
{
   FILE *fp = fopen("s.txt","w");
    if(fp == null){
        printf("文件打开失败");
        exit(0);
    }
    int i = 0;
    for(i=0; i<N; i++){
        scanf("%d %f",&s[i].id,&s[i].height);
        fwrite(&s[i],sizeof(s[i]),1,fp);
    }
    fclose(fp);
    fp = null;
}