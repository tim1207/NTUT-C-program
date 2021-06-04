#include <stdio.h>
#include <stdlib.h>

double type_183(int a,int b,int c,int d,int e){
    int monthly=183;
    double misc;

    misc=a*0.08+b*0.1393+c*0.1349+d*1.1287+e*1.4803;
    if(misc>monthly){
        return misc;
    }
    else
        return monthly;
    // return monthly + abs(misc-monthly);
}

double type_383(int a,int b,int c,int d,int e){
    int monthly=383;
    double misc;

    misc=a*0.07+b*0.1304+c*0.1217+d*1.1127+e*1.2458;
    if(misc>monthly){
        return misc;
    }
    else
        return monthly;
    // return monthly + abs(misc-monthly);
}

double type_983(int a,int b,int c,int d,int e){
    int monthly=983;
    double misc;

    misc=a*0.06+b*0.1087+c*0.1018+d*0.9572+e*1.1243;
    if(misc>monthly){
        return misc;
    }
    else
        return monthly;
    // return monthly + abs(misc-monthly);
}

int main()
{
    int a,b,c,d,e;
    double t1,t2,t3;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    scanf("%d",&d);
    scanf("%d",&e);

    t1=type_183(a,b,c,d,e);
    t2=type_383(a,b,c,d,e);
    t3=type_983(a,b,c,d,e);

    if((t1 < t2)&&(t1 < t3)){
        printf("183\n");
    }
    else if((t2 < t1)&&(t2 < t3)){
        printf("383\n");
    }
    
    else{
        printf("983\n");
    }
    return 0;
}

// 006 
// 輸入每月網內、網外、市話、通話時間(sec)及網內、網外 簡訊則數，求最佳資費。 
// 費率如下表： 
// *月租費也要納入考量 
// 資費類型 183型 383型 983型 
// 月租費 183元 383元 983元 
// 優惠內容 月租費可抵等額通信費 
// 語音 網內 0.08 0.07 0.06 
// (元/秒) 網外 0.1393 0.1304 0.1087 
// 市話(元/秒) 0.1349 0.1217 0.1018 
// 簡訊 網內 1.1287 1.1127 0.9572 
// (元/則) 網外 1.4803 1.2458 1.1243 

// 輸入 網內語音(sec)、網外語音(sec)、市話(sec)、網內簡訊數、網外簡訊數 測試資料。 

// Sample Input： 
// 500 
// 120 
// 13 
// 2 
// 5 

// Sample Output： 
// 183 

// Sample Input： 
// 200 
// 200 
// 200 
// 200 
// 200 

// Sample Output： 
// 383 
