#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GATEVALUE(TYPE) int(*GateValue)(void)

typedef struct _Gate{
    GATEVALUE();
}Gate;

int GateGetValue(){return 0;}

typedef struct _GateAnd{
    GATEVALUE();
}GateAnd;
int GateAndValue(){return 1;}

typedef struct _GateOr{
    GATEVALUE();
}GateOr;
int GateOrValue(){return 2;}

typedef struct _GateXor{
    GATEVALUE();
}GateXor;
int GateXorValue(){return 3;}

typedef struct _GateNot{
    GATEVALUE();
}GateNot;
int GateNotValue(){return 4;}

void CreateGate(Gate *obj){
    obj->GateValue = GateGetValue;
}

void CreateGateAND(GateAnd *obj){
    obj->GateValue = GateAndValue;
}

void CreateGateOr(GateOr *obj){
    obj->GateValue = GateOrValue;
}

void CreateGateXOR(GateXor *obj){
    obj->GateValue = GateXorValue;
}

void CreateGateNOT(GateNot *obj){
    obj->GateValue = GateNotValue;
}

int gate_siso(int signal, int gate) {
    if (gate == 4) // not.getValue() == 4
        return !signal;
    else
        return signal;
}
int gate_miso(int signal1, int signal2, int gate){
    if (gate == 1)
        return signal1 && signal2;
    if (gate == 2)
        return signal1 || signal2;
    if (gate == 3)
        return signal1 != signal2;
    
    //error
    return -1;
}

int main(int argc, char *argv[]){
    Gate gate;
    CreateGate(&gate);
    GateAnd and;
    CreateGateAND(&and);
    GateOr or;
    CreateGateOr(&or);
    GateXor xor;
    CreateGateXOR(&xor);
    GateNot not;
    CreateGateNOT(&not);

    char signalInput[20], gateInput[20];
    int signals[4], gates[6], outputs[3];
    char gates_c[6];
    fgets(signalInput, 20, stdin);
    fgets(gateInput, 20, stdin);
    for (int i=0; i<4; i++)
        signals[i] = signalInput[i*2] - '0';// because of ,
        
    for (int i=0; i<6; i++)
        gates_c[i] = gateInput[i*2];

    for (int i=0; i<6; i++) {
        if (gates_c[i] == 'A')
            gates[i] = and.GateValue();
        else if (gates_c[i] == 'O')
            gates[i] = or.GateValue();
        else if (gates_c[i] == 'X')
            gates[i] = xor.GateValue();
        else if (gates_c[i] == 'N')
            gates[i] = not.GateValue();
        else if (gates_c[i] == 'E')
            gates[i] = gate.GateValue();
    }
    //output 1
    int temp1 = gate_siso(signals[0], gates[0]);
    outputs[0] = gate_miso(temp1, signals[1], gates[1]);
    
    //output 2
    int temp2 = gate_miso(outputs[0], signals[2], gates[2]);
    outputs[1] = gate_miso(outputs[0], temp2, gates[3]);
    
    //output 3
    int temp3 = gate_siso(signals[3], gates[4]);
    outputs[2] = gate_miso(outputs[1], temp3, gates[5]);
    
    printf("%d,%d,%d\n", outputs[0], outputs[1], outputs[2]);

    return 0;
}










// 本題必須使用後所附程式碼架構 
// (使用規定架構進行實作並通過所有測資才予以給分，期末會進行檢查) 
// 以下邏輯電路圖，輸入為 I1, I2, I3，輸出為 O1, O2, O3 

// 　　　　　　　　O1 
// I1 -->A---->B　　↑ 
// 　　　　　B------★------------->D　O2 
// I2 --------->B　　　　|　　　　D　↑ 
// 　　　　　　　　　----->C 　D---★-->F　　O3 
// 　　　　　　　　　　　C--->D　　　F　　↑ 
// I3 --------------------------->C　　D　　　F-----★ 
// 　　　　　　　　　　　　　　　　　F 
// I4------------------E--------------------------->F 

// (社團會再放一張更整齊的版本，同學可以去查看) 


// 輸入I1, I2, I3, I4，以及設定AND, OR, XOR, NOT四種邏輯閘與Empty邏輯閘(即不設置邏輯閘) 
// 輸出O1, O2, O3 

// A, E邏輯閘：單輸入單輸出邏輯閘(NOT 與 Empty) 
// B, C, D, F邏輯閘：雙輸入單輸出邏輯閘(AND, OR與XOR) 

// 輸入說明: 
// 第一行依次輸入I1, I2, I3, I4為 0 或 1，中間以逗號間隔。 
// 第二行輸入A, B, C, D, E, F邏輯閘的設定，欲輸入的邏輯閘種類代號如下所示： 
// A：AND Gate 
// O：OR Gate 
// X：XOR Gate 
// N：NOT Gate 
// E：Empty Gate 
// (A邏輯閘僅代表順序第一順位輸入，並非固定為AND閘，只會有N與E邏輯閘種類代號輸入) 
// 輸入順序： 
// I1,I2,I3,I4 
// A,B,C,D,E,F 


// 輸出說明: 
// 輸出O1, O2, O3為 0 或 1，中間以逗號間隔 
// 輸出順序：O1,O2,O3 

// 範例: 

// Sample Input: 
// 0,0,0,0 
// N,A,O,X,N,A 

// Sample Output: 
// 0,0,0 

// ------------- 

// Sample Input: 
// 1,0,1,1 
// E,X,A,A,N,O 

// Sample Output: 
// 1,1,1 


// ------程式碼架構規範之範例--------------------- 

// #include 
// #include 
// #define GATEVALUE(TYPE) int(*GateValue)(void) 
// typedef struct _Gate{ 
// GATEVALUE(); 
// }Gate; 
// int GateGetValue(){return 0;} 
// typedef struct _GateAnd{ 
// GATEVALUE(); 
// }GateAnd; 
// int GateAndValue(){return 1;} 
// void CreateGate(Gate *obj){ 
// obj->GateValue = GateGetValue; 
// } 
// void CreateGateAND(GateAnd *obj){ 
// obj->GateValue = GateAndValue; 
// } 
// int main(int argc, char *argv[]){ 
// Gate gate; 
// CreateGate(&gate); 
// GateAnd and; 
// CreateGateAND(&and); 
// printf("Gate = %d, GateAND = %d\n", gate.GateValue(), and.GateValue()); 
// return 0; 
// } 