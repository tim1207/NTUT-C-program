#include<stdio.h>
typedef struct Shapetype{
    float (*perimeter)();
}Shape;
typedef struct Circletype{
	float radius;
}Circle;
typedef struct Rectangletype{
	float element[2];
}Rectangle;
typedef struct Squaretype{
	float edge;
}Square;
typedef struct Triangletype{
	float edge[3];
}Triangle;
float CirclePerimeter(Circle *obj) {return 2*3.14 * obj->radius;}
float RectanglePerimeter(Rectangle *obj) {return 2* ((obj->element[0])+(obj->element[1]));}
float SquarePerimeter(Square *obj){return 4*obj->edge;}
float TrianglePerimeter(Triangle *obj) {return (obj->edge[0])+(obj->edge[1])+(obj->edge[2]);}
int main(){
	Circle circle;
	Rectangle rectangle;
	Triangle triangle;
	Square square;
	Shape s;
	int i,j,num=0,n;
	char type;
	float print[100],final=0;
	scanf(" %d",&n);
	for(i=0;i<n;i++){
		scanf(" %c",&type);
		switch(type){
			case 'C':
				scanf(" %f",&circle.radius);
				s.perimeter=CirclePerimeter;
				print[num]=s.perimeter(&circle);
				break;
			case 'R':
				for(j=0;j<2;j++)scanf(" %f",&rectangle.element[j]);
				s.perimeter=RectanglePerimeter;
				print[num]=s.perimeter(&rectangle);
				break;
			case 'S':
				scanf(" %f",&square.edge);
				s.perimeter=SquarePerimeter;
				print[num]=s.perimeter(&square);
				break;
			case 'T':
				for(j=0;j<3;j++)scanf(" %f",&triangle.edge[j]);
			    s.perimeter=TrianglePerimeter;
				print[num]=s.perimeter(&triangle);
				break;
		}
		num+=1;

	}
	for(i=0;i<n;i++){
		final+=print[i];
		printf("%0.2f\n",print[i]);
	}
	printf("%0.2f\n",final);
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>

// #define PI 3.14
// #define ShapeText(TYPE) char name[10];



// typedef struct shape_s {
//     ShapeText(shape_s);
//     double (*perimeter) (struct shape_s*);
//     double length;
//     double width;
//     double *edge;
// } shape_t;

// typedef struct circle_s {
//     ShapeText(circle_s);
//     double (*perimeter) (struct circle_s*);
//     double radius;
// } circle_t;

// double perimeter(struct shape_s* shape){
//     if (!strcmp(shape->name, "R"))
//         return 2 * (shape->length + shape->width);
//     if (!strcmp(shape->name, "S"))
//         return 4 * shape->edge[0];
//     else
//         return shape->edge[0] + shape->edge[1] + shape->edge[2];
// }

// double perimeter_c(struct circle_s* circle) {
//     return 2 * circle->radius * PI;
// }

// void clearBuffer() {
//     char c;
//     do {
//         c = getchar();
//     } while (c != '\n' && c != EOF);
// }

// int main(){
//     int count;
//     double total = 0;
//     scanf("%d", &count);
//     clearBuffer();
//     double result[count];
    
//     for (int i=0; i<count; i++) {
//         double perimeter_value;
//         char name;
//         scanf("%c", &name);
//         if (name == 'C') {
//             circle_t circle;
//             strcpy(circle.name, "C");
//             scanf("%lf", &circle.radius);
//             circle.perimeter = perimeter_c;
//             perimeter_value = circle.perimeter(&circle);
//         } else if (name == 'T') {
//             shape_t triangle;
//             triangle.edge = (double*) malloc(3 * sizeof(double));
//             strcpy(triangle.name, "T");
//             scanf("%lf%lf%lf", triangle.edge, triangle.edge+1, triangle.edge+2);
//             triangle.perimeter = perimeter;
//             perimeter_value = triangle.perimeter(&triangle);
//         } else if (name == 'S') {
//             shape_t square;
//             square.edge = (double*) malloc(sizeof(double));
//             strcpy(square.name, "S");
//             scanf("%lf", square.edge);
//             square.perimeter = perimeter;
//             perimeter_value = square.perimeter(&square);
//         } else if (name == 'R') {
//             shape_t rectangle;
//             strcpy(rectangle.name, "R");
//             scanf("%lf%lf", &(rectangle.length), &(rectangle.width));
//             rectangle.perimeter = perimeter;
//             perimeter_value = rectangle.perimeter(&rectangle);
//         } else {
//             perimeter_value = 0;
//         }
//         clearBuffer();
        
//         total += perimeter_value;
//         perimeter_value *= 100;
//         perimeter_value = round(perimeter_value);
//         perimeter_value /= 100;
//         result[i] = perimeter_value;
//     }
    
//     for (int i=0; i<count; i++)
//         printf("%.2lf\n", result[i]);
    
//     printf("%.2lf\n", total);
//     return 0;
// }




// 利用結構 struct 定義 
// Shape（圖形）, Circle（圓）, Rectangle（矩形）, Square（正方形）, Triangle（三角形）。 
// 圓有半徑，矩形有長和寬，正方形有邊長，三角形有三個邊。 
// 計算各個圖形的周長，以及所有圖形的周長加總。 
// 此題須使用以下struct及function pointer實作，否則不予計分。 
// (使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查) 

// 輸入說明: 
// 圖形個數、圖形種類與其屬性 
// 圖形種類以代號輸入，代號如下所示： 
// C：圓形，屬性內容具有radius (圓周率請使用3.14) 
// R：矩形，屬性內容具有length、width 
// S：正方形，屬性內容具有edge 
// T：三角形，屬性內容具有3個edge 

// 輸出說明： 
// 各個圖形的周長、各個圖形的周長總和 
// (四捨五入到小數點後第2位，總和請先加總好再四捨五入) 

// Sample Input： 
// 4 
// T 2.2 3.3 4.4 
// S 1.1 
// R 1.1 2.2 
// C 1.0 

// Sample Output： 
// 9.90 
// 4.40 
// 6.60 
// 6.28 
// 27.18 

// ----------------- 

// Sample Input： 
// 1 
// C 0.31847 

// Sample Output： 
// 2.00 
// 2.00 



// ------程式碼架構規範之範例--------------------- 
// #define ShapeText(TYPE) char name[10]; 
// double (*perimeter)(struct TYPE*); 
// double (*area)(struct TYPE*); 
// typedef struct shape_s { 
// ShapeText(shape_s); 
// } shape_t; 
// typedef struct circle_s { 
// ShapeText(circle_s); 
// double radius; 
// } circle_t; 