#include <stdio.h>
int f(int n, int coinType[], int k) {
	int p=0, i=0, coin=0, min_coin=0;
	int min_number[100]={0};
	int min_first_element[100]; 
	for (p=0; p<100; p++) 
		min_number[p]=0;
	for (p=1;p<=n;p++){
		min_coin = n; 
		for(i=0;i<k;i++){
			coin = coinType[i];
			if (((p-coin)>=0)&&((1+min_number[p-coin])<min_coin)) 
				min_coin = 1 + min_number[p-coin];	
		} 
		min_number[p] = min_coin; 
		min_first_element[p] = coin;
	}
		for (p=1; p<=n; p++) {
			printf("f(%d)=1+min( f(%d-%d) + f(%d-%d) +f(%d-%d) +f(%d-%d) )\n",p,p,9,p,7,p,3,p,1);
			printf("(%d, %d)\n", p, min_number[p]);
		}
}


int main(){
	int coinType[10]={1, 3, 7, 9}; 
	int k=4;
	//int coinType[10]={5, 4, 2, 1}; 
	int n =18; //8
	f(n, coinType, k);
	return 0;
} 