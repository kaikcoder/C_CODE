#include<stdio.h>
#include<stdlib.h>
#define N 3
#define null 0
struct student{
    int id;//ѧ��
    float height;//���
}s[N];
// д�����ݵ��ļ�
int write_s(){
    FILE *fp = fopen("stu.txt","w");
    if(fp == null){
        printf("�ļ���ʧ��");
        exit(0);
    }
    int i = 0;
    for(i=0; i<N; i++){
        scanf("%d %f",&s[i].id,&s[i].height);
        fprintf(fp,"%d %.1f\n",s[i].id,s[i].height);
    }
    fclose(fp);
    fp = null;
}

// ͳ�����ݵĸ���
int sum_s(){
    FILE *fp = fopen("stu.txt","r");
    if(fp == null){
        printf("�ļ���ʧ��");
        exit(0);
    }
    int i = 0; 
    struct student temp; 
    struct student a[N];   
    for(i=0; i<N; i++){
        fscanf(fp,"%d %f",&a[i].id,&a[i].height);
    }
    
    // �����ݽ�������
    for(i=0; i<N-1; i++){
        int j = 0;
        for(j=0; j<N-i-1; j++){
            if(a[j].height > a[j+1].height){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    // ͳ�����ݵĸ���
    float t = a[0].height;
    int count = 1;
    int n1 = N;
    printf("���  ����\n");
    for(i=1; i<N; i++){
        if(a[i].height == t){
            count++;
        }
        else{
            if(count >= 1){
                printf("%.1f   %d\n",a[i-1].height,count);
            }
             count = 1;
             t = a[i].height;
        }
       
    }
    if(count >= 1){
                printf("%.1f   %d\n",a[i-1].height,count);
    }
    printf("����%d��",n1);
    return 0;
    fclose(fp);
}

int main(){
    write_s();//�����ݶ���������ļ�
    sum_s();//ͳ����ͬ��ߵ�����
    return 0;
}