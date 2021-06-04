#include <stdio.h>
int gcd(int a, int b){ 
	return b? gcd(b, a%b):a;
}

int abs(int a) {
	if(a < 0) a = -a;
	return a;
}

int main() {
	char c = 'y';
	while(c == 'y') {
		int x, y, x1, y1;
		char cha, op;
		scanf("%d%c%d", &x, &cha, &y);
		getchar();
		scanf("%d%c%d", &x1, &cha, &y1);
		getchar();
		scanf("%c", &op);
		getchar();
		scanf("%c", &c);
		getchar();
		if(y == 0 || y1 == 0) {
			printf("ERROR\n");
			continue;
		}

		if(op == '+') {
			x = x * y1 + x1 * y;
			y = y * y1;
		}else if(op == '-') {
			x = x * y1 - x1 * y;
			y = y * y1;
		}else if(op == '*') {
			x *= x1;
			y *= y1;
		}else {
			if(x1 == 0) {
				printf("ERROR\n");
				continue;
			}
			x *= y1;
			y *= x1;
			if(y < 0) { x = -x; y = -y;}
			
		}

		if(x == 0) {
			printf("0\n");
			continue;
		}

		while(gcd(abs(x), abs(y)) != 1) {
			int g = gcd(abs(x), abs(y));
			x /= g;
			y /= g;
		}
		
		if(x >= 0) {
			if(x > y) {
				int n, n1;
				n = x / y;
				n1 = x % y;
				if(n1) 
					printf("%d(%d/%d)\n", n, n1, y);
				else 
					printf("%d\n", n);
			}else {
				if(x == y)
					printf("1\n");
				else
					printf("%d/%d\n", x, y);
			}
		}else {
			x = -x;
			if(x > y) {
				int n, n1;
				n = x / y;
				n1 = x % y;
				if(n1)
					printf("-%d(%d/%d)\n", n, n1, y);
				else
					printf("-%d\n", n);
			}else {
				if(x == y)
					printf("-1\n");
				else
					printf("-%d/%d\n", x, y);
			}
		}
	}
	return 0;
}
