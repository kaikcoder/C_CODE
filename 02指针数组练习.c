/* 指针数组练习题 */
#include<stdio.h>
#include<string.h>
#define N 4
void sort(char *ss[],int n){
    int i,j;
    char *v;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(strcmp(ss[i],ss[j])<0){
                v = ss[i];
                ss[i] = ss[j];
                ss[j] = v;
            }
        }
    }

}
int main(){
    char *arr[] = {"65","128","99","986"};
    int i;
    sort(arr,N);
    for(i=0; i<N; i++){
        printf("%s",arr[i]);
    }
    return 0;
}
