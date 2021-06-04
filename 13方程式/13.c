#include <stdio.h>
int gcd(int n1, int n2) {
    if (n2)
        return abs(gcd(n2, n1 % n2));
    else
        return abs(n1);
}

void funtion(int *a, int *b) //約分
{
	while(gcd(abs(*a), abs(*b)) != 1) {
		int g = gcd(abs(*a), abs(*b));
			*a /= g;
			*b /= g;
		}

	if( ((*a)*(*b)) < 0 ) {
		*a = -abs(*a);
		*b = abs(*b);
	}else if( (*a)*(*b) > 0) {
		*a = abs(*a);
		*b = abs(*b);
	}
}

int main() {
	int x1, y1, x2, y2;
    char c;
	scanf("%d%c%d", &x1,&c,&y1);
	scanf("%d%c%d", &x2,&c,&y2);
	int m1 = y1-y2, m2 = x1-x2;
	int b1 = x2*y1-x1*y2, b2 = x2-x1;
	funtion(&m1, &m2);
	funtion(&b1, &b2);
    //約分後
	if(m1 == 0 || b1 == 0) //value is 0
    {
		if(m1 == 0 && m2 == 0) 
        {
			printf("y=0\n");
		}
		else if(m1 == 0) // 沒x
        {
			if(abs(b1) % b2 == 0) printf("y=%d\n", b1/b2);//整除
			else printf("y=%d/%d\n", b1, b2);
		}
		else if(b1 == 0) //沒b
        {
			if(abs(m1) % m2 == 0) 
				if(m1/m2 == 1) printf("y=x\n");
				else if(m1/m2 == -1) printf("y=-x\n");
				else printf("y=%dx\n", m1/m2);
			else printf("y=%d/%dx\n", m1, m2);
		}
	}
    else {
		if((abs(m1) % m2 == 0) && (abs(b1) % b2 == 0)) //皆整除
        {
            if(m1/m2 == 1) printf("y=x%+d\n",b1/b2);
			else if(m1/m2 == -1) printf("y=-x%+d\n", b1/b2);
			else printf("y=%dx%+d\n", m1/m2, b1/b2);
        }
			
		else if(abs(m1) % m2 == 0){
            if(m1/m2 == 1) printf("y=x%+d/%d\n",b1, b2);
			else if(m1/m2 == -1) printf("y=-x%+d/%d\n", b1, b2);
			else printf("y=%dx%+d/%d\n", m1/m2, b1, b2);
        }
			
		else if((abs(b1) % b2 == 0))
			printf("y=%d/%dx%+d\n", m1, m2, b1/b2);
		else
			printf("y=%d/%dx%+d/%d\n", m1, m2, b1, b2);
	}
	return 0;
}







// 013 
// 輸入平面上兩個點，求直線方程式 
// 輸入兩點座標，(x1, y1), (x2, y2) 
// 輸出 y = mx + b(其中，m=(y1-y2)/(x1-x2)、b = (x2y1-x1y2)/(x2-x1)) 

// ex: 
// input: 
// 1,0 
// 0,-1 

// output: 
// y=x-1 

// ------------- 

// input: 
// 1,0 
// 0,1 

// output: 
// y=-x+1
















