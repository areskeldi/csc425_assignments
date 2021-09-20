#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int long long size = ((long long int)atoi(argv[1]))*1024*1024;
    int* allocate = (int*)malloc(size);

    while (1){
        fflush(stdout);
        for(int i=0; i<size/sizeof(int); i++){
            allocate[i] = i;
	printf("updated");
        }
    }

    return 0;
}
