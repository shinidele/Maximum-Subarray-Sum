#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int n;        
    srand((unsigned)time(NULL)); 
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("输入数据格式错误！");          
    }    
    for (int i = 0; i < n; ++i) {
    	// [-10000,10000]
        int x = rand() % 20001 - 10000;   
        printf("%d ", x);
    }
}
