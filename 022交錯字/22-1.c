#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int n = 0;
	char str[100];
	scanf("%d", &n);
	getchar();
	fgets(str, 100, stdin);

	int len = strlen(str);
	int max = 0;
	for(int i = 0; i < len; i++) {
		int flag = 0;
		if (str[i] >= 65 && str[i] <= 90) flag = 1;
		int p = i;

		int sum = 0;
		while(str[p] != '\0' && p <= len) {
			int count = 0;
			int flag2 = 0;
			for(int j = 0; j < n; j++) {
				if(p > len - 1) break;
				if(flag == 1) {
					if(str[p] >= 97 && str[p] <= 122) break;
					else {
						//printf("1%c", str[p]);
						count++;
						if(count == n) {
							flag = !flag;
							flag2 = 1;
						}
					}
				}else {
					if(str[p] >= 65 && str[p] <= 90) break;
					else {
					    //printf("2%c", str[p]);
						count++;
						if(count == n) {
							flag = !flag;
							flag2 = 1;
						}
					}
				}
				p++;
			}

			if(p > len - 1) break;
			if(flag2 == 0) break;
			if(flag2 == 1) {
				//printf("ggg");
				sum += n;
				if(sum > max) max = sum;
			}

			flag2 = 0;
			count = 0;
			for(int j = 0; j < n; j++) {
				if(p > len - 1) break;
				if(flag == 1) {
					if(str[p] >= 97 && str[p] <= 122) break;
					else {
						//printf("3%c", str[p]);
						count++;
						if(count == n) {
							flag = !flag;
							flag2 = 1;
						}
					}
				}else {
					if(str[p] >= 65 && str[p] <= 90) break;
					else {
						//printf("4%c", str[p]);
						count++;
						if(count == n) {
							flag = !flag;
							flag2 = 1;
						}
					}
				}
				p++;
			}
			if(p > len - 1) break;
			//printf("\n-------\n");
			if(flag2 == 1) {
				//printf("ggg");
				sum += n;
				if(sum > max) max = sum;
			}
		}
	}


	printf("%d", max);
	return 0;
}