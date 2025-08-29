#include<stdio.h>
#include<climits>
#include <time.h>
#include <windows.h>
#include <psapi.h>      
#pragma comment(lib, "psapi.lib")
#define N 100010
//��̬�滮 
long Dynamic_Programming(int n, int nums[]){
	long maxnum = nums[0];
    for(int i = 1; i < n; i++){
        nums[i] = nums[i - 1] + nums[i] > nums[i] ? nums[i - 1] + nums[i] : nums[i];
        maxnum = maxnum > nums[i] ? maxnum : nums[i]; 
    }
    return maxnum;
}
//̰�� 
long Greedy_Algorithm(int n, int nums[]){
	long sum = 0;
    long maxs = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += nums[i];
        maxs = sum > maxs ? sum : maxs;
        if(sum < 0) sum = 0;
    }
    return maxs;
}
//������ 
long maxmidSub(int l, int mid, int r, int nums[]) {
	long sum = 0;
    long maxl = LONG_MIN;
    long maxr = LONG_MIN;
    for (int i = mid; i >= l; i--) {
        sum += nums[i];
        maxl = maxl > sum ? maxl : sum;
    }
    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += nums[i];
        maxr = maxr > sum ? maxr : sum;
    }
    return maxr + maxl;
}
//���� 
long Divide_Conquer(int l, int r, int nums[]){
    if(l == r){
        return nums[l];
    }
    long result;
    int mid = (l + r) / 2;
    long lmax = Divide_Conquer(l, mid, nums);
    long rmax = Divide_Conquer(mid + 1, r, nums);
    long mmax = maxmidSub(l, mid, r, nums);
    result = lmax > rmax ? lmax : rmax;
    result = result > mmax ? result : mmax;
    return result;
} 
int main(){
	int nums[N];
	int n,choose;
	printf("�������鳤�ȣ�");
	scanf("%d",&n);
	printf("�������ݣ�");
	for(int i = 0; i < n; i++){
		scanf("%d",nums + i);
	}
	printf("ѡ���㷨��1��Dynamic Programming �� 2��Greedy Algorithm �� 3��Divide and Conquer����");
	scanf("%d",&choose);
	long result;
	switch(choose){
		case 1 : result = Dynamic_Programming(n,nums);break;
		case 2 : result = Greedy_Algorithm(n,nums);break;
		case 3 : result = Divide_Conquer(0,n,nums);break;
		default : printf("��ʽ����");
	} 
	printf("���������ͣ�%ld\n",result);
	clock_t start = clock();
	double elapsed = (double)(clock() - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("����ʱ�䣺%.3f ms\n", elapsed);
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
        printf("�������������ڴ棩��%zu KB\n", pmc.WorkingSetSize / 1024);
    }
}
