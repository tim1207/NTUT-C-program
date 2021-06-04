#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#define GATEVALUE(TYPE) int(*GateValue)(void)
enum gateValue{
    get,
    And,
    Or,
    Xor,
    Not,
    Empty
} GateValue;
typedef struct _Gate{
    GATEVALUE();
}Gate;
typedef struct _GateAnd{
    GATEVALUE();
}GateAnd;
typedef struct _GateOr{
    GATEVALUE();
}GateOr;
typedef struct _GateXor{
    GATEVALUE();
}GateXor;
typedef struct _GateNot{
    GATEVALUE();
}GateNot;
typedef struct _GateEmpty{
    GATEVALUE();
}GateEmpty;
int GateGetValue(){return get;}
int GateAndValue(){return And;}
int GateOrValue(){return Or;}
int GateXorValue(){return Xor;}
int GateNotValue(){return Not;}
int GateEmptyValue(){return Empty;}
void CreateGate(Gate *obj){
    obj->GateValue = GateGetValue;
}
void CreateGateAND(GateAnd *obj){
    obj->GateValue = GateAndValue;
}
void CreateGateOR(GateAnd *obj){
    obj->GateValue = GateOrValue;
}
void CreateGateXOR(GateAnd *obj){
    obj->GateValue = GateXorValue;
}
void CreateGateNOT(GateAnd *obj){
    obj->GateValue = GateNotValue;
}
void CreateGateEMPTY(GateAnd *obj){
    obj->GateValue = GateEmptyValue;
}
int operate(int a,int b,int opa){
    if(opa == And){
        return a && b;
    }else if(opa == Or){
        return a || b;
    }else if (opa ==Xor){
        return a^b;
    }
    return 0;
}
int main(int argc, char *argv[]){
    Gate gate[6];
    char g[6];
    int input[4];
    int result[3];
    scanf("%d,%d,%d,%d",&input[0],&input[1],&input[2],&input[3]);
    scanf(" %c,%c,%c,%c,%c,%c",&g[0],&g[1],&g[2],&g[3],&g[4],&g[5]);
    for(int i = 0 ; i < 6 ; i++){
        if(g[i] == 'A'){
            CreateGateAND( ((Gate*)&gate[i])); 
        }else if(g[i]=='O'){
            CreateGateOR( ((Gate*)&gate[i])); 
        }else if(g[i]=='X'){
            CreateGateXOR( ((Gate*)&gate[i])); 
        }else if(g[i]=='N'){
            CreateGateNOT( ((Gate*)&gate[i])); 
        }else if(g[i]=='E'){
            CreateGateEMPTY( ((Gate*)&gate[i])); 
        }
    }
    input[0] = gate[0].GateValue() == Not ? !input[0]:input[0];
    input[3] = gate[4].GateValue() == Not ? !input[3]:input[3];
    int C_result = 0;
    result[0] = operate(input[0],input[1],gate[1].GateValue());
    C_result = operate(result[0],input[2],gate[2].GateValue());
    result[1] = operate(result[0],C_result,gate[3].GateValue());
    result[2] = operate(result[1],input[3],gate[5].GateValue());
    printf("%d,%d,%d",result[0],result[1],result[2]);
return 0;
}
/*
本題必須使用後所附程式碼架構
(使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查)
以下邏輯電路圖，輸入為 I1, I2, I3，輸出為 O1, O2, O3

　　　　　　　　O1
I1 -->A---->B　　↑
　　　　　B------★------------->D　O2
I2 --------->B　　　　|　　　　D　↑
　　　　　　　　　----->C 　D---★-->F　　O3
　　　　　　　　　　　C--->D　　　F　　↑
I3 --------------------------->C　　D　　　F-----★
　　　　　　　　　　　　　　　　　F
I4------------------E--------------------------->F

(社團會再放一張更整齊的版本，同學可以去查看)
https://cdn.discordapp.com/attachments/595858445140361217/846418694301417514/image0.png

輸入I1, I2, I3, I4，以及設定AND, OR, XOR, NOT四種邏輯閘與Empty邏輯閘(即不設置邏輯閘)
輸出O1, O2, O3

A, E邏輯閘：單輸入單輸出邏輯閘(NOT 與 Empty)
B, C, D, F邏輯閘：雙輸入單輸出邏輯閘(AND, OR與XOR)

輸入說明:
第一行依次輸入I1, I2, I3, I4為 0 或 1，中間以逗號間隔。
第二行輸入A, B, C, D, E, F邏輯閘的設定，欲輸入的邏輯閘種類代號如下所示：
A：AND Gate
O：OR Gate
X：XOR Gate
N：NOT Gate
E：Empty Gate
(A邏輯閘僅代表順序第一順位輸入，並非固定為AND閘，只會有N與E邏輯閘種類代號輸入)
輸入順序：
I1,I2,I3,I4
A,B,C,D,E,F


輸出說明:
輸出O1, O2, O3為 0 或 1，中間以逗號間隔
輸出順序：O1,O2,O3

範例:

Sample Input:
0,0,0,0
N,A,O,X,N,A

Sample Output:
0,0,0

-------------

Sample Input:
1,0,1,1
E,X,A,A,N,O

Sample Output:
1,1,1


------程式碼架構規範之範例---------------------

#include
#include
#define GATEVALUE(TYPE) int(*GateValue)(void)
typedef struct _Gate{
GATEVALUE();
}Gate;
int GateGetValue(){return 0;}
typedef struct _GateAnd{
GATEVALUE();
}GateAnd;
int GateAndValue(){return 1;}
void CreateGate(Gate *obj){
obj->GateValue = GateGetValue;
}
void CreateGateAND(GateAnd *obj){
obj->GateValue = GateAndValue;
}
int main(int argc, char *argv[]){
Gate gate;
CreateGate(&gate);
GateAnd and;
CreateGateAND(&and);
printf("Gate = %d, GateAND = %d\n", gate.GateValue(), and.GateValue());
return 0;
}


*/