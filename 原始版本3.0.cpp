#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int turn=0,fin=0,ok=0;
    int a[5][5]={};
    char word[3];
    //輸入先手
    cout<<"歡迎遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>word[1];
    while(word[1]!='O' && word[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>word[1];
    }
    if(word[1]=='O')
        word[2]='X';
    if(word[1]=='X')
        word[2]='O';
    
    while(fin==0){  //主迴圈開始
        int input,i,j;
              
        for (i=1 ; i<=3 ; i++){ //輸出九宮格
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<word[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<word[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        } 

        cout<<"輪到"<<word[turn%2+1]<<"，請輸入要填入的位置代碼";  //輸入位置代碼
        cin>>input;
        do{
			i=input/10;
        	j=input%10;	
        	if(input!=11 && input!=12 && input!=13 && input!=21 && input!=22 && input!=23 && input!=31 && input!=32 && input!=33){
				ok=1;
				cout<<"該位置不存在，請重新輸入";
            	cin>>input;
			}
        	
        	else if(a[i][j]!=0){
        		ok=1;
        		cout<<"該位置已使用，請重新輸入";
            	cin>>input;
			}	
			else{
				ok=0;
			}
		}while(ok==1);
        
        a[i][j]=turn%2+1;

        for(i=1 ; i<=3 ; i++){  //判斷勝負
            if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=0){
                fin=turn%2+1;
            }
            if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[1][i]!=0){
                fin=turn%2+1;
            }
        }
        if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[1][1]!=0){
            fin=turn%2+1;
        }
        if(a[1][3]==a[2][2] && a[2][2]==a[3][1] && a[3][1]!=0){
            fin=turn%2+1;
        }
        
        ok=0;  //判斷平局
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==0)
                    ok=1;
                
            }
        }
        if(ok==0 && fin==0){
            fin=3;
        }
        
        turn++;        
    }

    for (int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ;j++){
            if (a[i][j]==1)
                cout<<setw(3)<<word[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<word[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl<<endl;
    } 
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<word[fin]<<"獲勝"<<endl;
    }    
    return 0;
}
