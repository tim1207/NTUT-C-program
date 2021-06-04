#include <stdio.h>

void type1(int height){
    for(int i=0;i<=height/2;i++){
		for(int j=0;j<=i;j++){
		   printf("*");
		}
		printf("\n");
	}	
	for(int i=1;i<=height/2;i++){
		for(int j=i;j<=height/2;j++){
		   printf("*");
		}
		printf("\n");
	}	
    
    
}
void type2(int height){
    for(int i=0;i<=height/2;i++){
		for(int j=1;j<=height/2-i;j++){
		   printf(".");
		}
		for(int n=0;n<=i;n++){
		   printf("*");
		}
		printf("\n");
	}
	for(int i=1;i<=height/2;i++){
		for(int j=1;j<=i;j++){
		   printf(".");
		}
		for(int n=0;n<=height/2-i;n++){
		   printf("*");
		}
		printf("\n");
	}


}
void type3(int height){
    for(int i=0;i<=height/2;i++){//1
		for(int j=0;j<height/2-i;j++){
	     	printf(".");
		}
		for(int k=0;k<=i*2;k++){
		  printf("*");
		}
		printf("\n");
	}
	for(int m=1;m<=height/2;m++){
		for(int n=0;n<m;n++){
			printf(".");
		}
		for(int a=0;a<height-m*2;a++){
		  printf("*");
		}
		printf("\n");
    }
}


int main(){
    int type,height;
    scanf("%d",&type);
    scanf("%d",&height);
    switch (type)
    {
    case 1:
        type1(height);
        break;
    case 2:
        type2(height);
        break;
    case 3:
        type3(height);
        break;
    
    default:
        break;
    }
}


// 008 
// 請使用 while loop或for loop 
// 第一個輸入意義為選擇三種圖形: 
// 1 三角形方尖方面向右邊 
// 2 三角形方尖方面向左邊 
// 3 菱形 

// 第二個輸入意義為畫幾行 
// (奇數，範圍為 3,5,7,9,....,21) 

// input 
// 1 (第一種圖形，三角形尖方面向右邊) 
// 9 (共 9 行) 
// -------------------------- 
// output 
// * 
// ** 
// *** 
// **** 
// ***** 
// **** 
// *** 
// ** 
// * 
// --------------------------- 
// input 
// 2 (第二種圖形，三角形尖方面向左邊) 
// 5 (共 5 行) 
// --------------------------- 
// output 
// ..* 
// .** 
// *** 
// .** 
// ..* 
// -------------------------- 
// input 
// 3 (第三種圖形: 菱形 ) 
// 3 (共 3 行數) 

// 輸出 
// .* 
// *** 
// .* 