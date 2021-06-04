#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int b=0,out=0,i,num=0,x;
    int base[4]={0};
    char input;
    for(i=0;i<5;i++)
    {
        scanf(" %c",&input);
        if (input=='1')
        	num=1;
    	else if (input=='2')
        	num=2;
    	else if (input=='3')
        	num=3;
    	else if (input=='H')
        	num=4;

        if(input == 'O')
        {
            out++;
            if (out == 3)// 3out
            {
                base[0] = base[1] = base[2] = base[3] = 0;
                break;
            }
        	
        }
        else
        {
            base[0] = 1;
            for(x=3;x>=0;x--)
            {
                if (base[x] == 1)
                {
                    base[x + num] = 1;
    				base[x] = 0;
                }
                
            }
        }
    				
	}
	for(i=1;i<4;i++)//1 to 3 base
  		printf("%d\n",base[i]);   
}


// 002. 跑壘問題 

// 輸入棒球隊球員打擊結果，計算出隊得分。假設球員打擊情況： 
// 安打：以1, 2, 3 和 H代表一、二、三和全(四)壘打。 
// 出局：以 O表示 (OUT)。 
// 簡化版的規則如下： 
// 球場 上有四個壘包， 稱為本壘、一、二和三壘。 
// 本壘握球棒打的稱「擊球員」 ，在另外三個壘包的稱為「跑員」。 
// 當擊球員打擊「安打」時， 擊球員與跑壘員可移動；「出局」時，跑壘員不動，擊球員離場換下一位。 
// 比賽開始由第 1位打擊，接著2, 3, 4, 5位球員。 
// 打出 K 壘打時，場上球員(擊球員和跑壘員)會前進 K個壘包。本壘到一壘，接著二、三壘，最後回到本壘。回到本壘可得 1分。 
// 每達到三個出局數時，壘包清空(跑壘員都得離開)，重新開始。 
// 輸入5位打者打擊資料，輸出最後一、二、三壘狀況，有人為1，沒人為0。 

// --------------- 
// Input 
// 1 
// 1 
// O 
// O 
// 1 

// Output 
// 1 
// 1 
// 1 

// --------------- 
// Input 
// 1 
// H 
// O 
// 3 
// 1 

// Output 
// 1 
// 0 
// 0 