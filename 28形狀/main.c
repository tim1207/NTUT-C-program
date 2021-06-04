#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#define ShapeText(TYPE) char name[10]; double (*perimeter)(struct TYPE*); double (*area)(struct TYPE*);
typedef struct shape_s {
	ShapeText(shape_s);
} shape_t;
typedef struct circle_s {
	ShapeText(circle_s);
	double radius;
} circle_t;
typedef struct rectangle_s {
	ShapeText(rectangle_s);
	double length;
	double width;
} rectangle_t;
typedef struct square_s {
	ShapeText(square_s);
	double edge;
} square_t;
typedef struct triangle_s {
	ShapeText(triangle_s);
	double	a,b,c;
} triangle_t;
double CirclePerimeter(circle_t* c) {
	return 2 * 3.14 * c->radius;
}
double SquarePerimeter(square_t* s) {
	return s->edge * 4;
}
double TrianglePerimeter(triangle_t* t) {
	return t->a + t->b + t->c;
}
double RectanglePerimeter(rectangle_t* r) {
	return (r->length + r->width) * 2;
}


int main() {
	int n = 0;
	scanf("%d", &n);
	shape_t* shape[n];
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		//printf("debug : %c\n",c);
		if (c == 'C') {
			shape[i] = malloc(sizeof(circle_t));
			scanf(" %lf", &(((circle_t*)shape[i])->radius));
			((circle_t*)shape[i])->perimeter = CirclePerimeter;
			//printf("debug : %lf\n",(((circle_t*)shape[i])->radius));
			
		}
		else if (c == 'R') {
			shape[i] = malloc(sizeof(rectangle_t));
			scanf(" %lf %lf", &(((rectangle_t*)shape[i])->length),&(((rectangle_t*)shape[i])->width));
			((rectangle_t*)shape[i])->perimeter = RectanglePerimeter;
			//printf("debug : %lf %lf\n",(((rectangle_t*)shape[i])->length),(((rectangle_t*)shape[i])->width));
		}
		else if (c == 'S') {
			shape[i] = malloc(sizeof(square_t));
			scanf(" %lf", &(((square_t*)shape[i])->edge));
			((square_t*)shape[i])->perimeter = SquarePerimeter;
			//printf("debug : %lf %lf\n",(((square_t*)shape[i])->edge));
		}
		else if (c == 'T') {
			shape[i] = malloc(sizeof(triangle_t));
			scanf(" %lf %lf %lf", &(((triangle_t*)shape[i])->a),&(((triangle_t*)shape[i])->b),&(((triangle_t*)shape[i])->c));
			((triangle_t*)shape[i])->perimeter = TrianglePerimeter;
			//printf("debug : %lf %lf %lf\n",(((triangle_t*)shape[i])->a),(((triangle_t*)shape[i])->b),(((triangle_t*)shape[i])->c));
			
		}
	}
	double total = 0;
	for(int i = 0 ; i < n ;i++){
		double perimeter = shape[i]->perimeter(shape[i]);
		printf("%.2lf\n",perimeter);
		total += perimeter;
	}
	printf("%.2lf\n",total);
}
/*
利用結構 struct 定義
Shape（圖形）, Circle（圓）, Rectangle（矩形）, Square（正方形）, Triangle（三角形）。
圓有半徑，矩形有長和寬，正方形有邊長，三角形有三個邊。
計算各個圖形的周長，以及所有圖形的周長加總。
此題須使用以下struct及function pointer實作，否則不予計分。
(使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查)

輸入說明:
圖形個數、圖形種類與其屬性
圖形種類以代號輸入，代號如下所示：
C：圓形，屬性內容具有radius (圓周率請使用3.14)
R：矩形，屬性內容具有length、width
S：正方形，屬性內容具有edge
T：三角形，屬性內容具有3個edge

輸出說明：
各個圖形的周長、各個圖形的周長總和
(四捨五入到小數點後第2位，總和請先加總好再四捨五入)

Sample Input：
4
T 2.2 3.3 4.4
S 1.1
R 1.1 2.2
C 1.0

Sample Output：
9.90
4.40
6.60
6.28
27.18

-----------------

Sample Input：
1
C 0.31847

Sample Output：
2.00
2.00



------程式碼架構規範之範例---------------------
#define ShapeText(TYPE) char name[10];
double (*perimeter)(struct TYPE*);
double (*area)(struct TYPE*);
typedef struct shape_s {
ShapeText(shape_s);
} shape_t;
typedef struct circle_s {
ShapeText(circle_s);
double radius;
} circle_t;
*/