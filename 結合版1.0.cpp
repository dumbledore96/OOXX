#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
int mod;
char hand,AI;
int r,F,S,i,j,win=0,step=1;
char table[3][3]={};

void Table(){  //輸出九宮格輸出
    for (i=0 ; i<=2 ; i++){
        for(j=0 ; j<=2 ;j++){
            if(table[i][j]==0)
				cout<<setw(3)<<(i+1)*10+j+1;
			else
				cout<<setw(3)<<table[i][j];
        }
            cout<<endl<<endl;
    }
}

void input(){  //輸入位置代碼
	cout<<"輪到你"<<"，請輸入要填入的位置代碼";
	cin>>r;
	F=(r-10)/10;
    S=(r-1)%10;
   while(1){
		if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
        	cout<<"該位置不存在，請重新輸入";
       		cin>>r;
		}
		else if(table[F][S]!=0){
            cout<<"該位置已使用，請重新輸入";
            cin>>r;
            F=(r-10)/10;
    		S=(r-1)%10;
        }
    	else{
    		F=(r-10)/10;
    		S=(r-1)%10;
    		table[F][S]=hand;
			break;
		}
	}
}

int result(char who){
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(table[i][j]==who){
				win++;
			}
			if(win==3){
				return win;
				break;
			}
		}
		win=0;
	}
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(table[j][i]==who){
				win++;
			}
			if(win==3){
				return win;
				break;
			}
		}
		win=0;
	}
	if((table[0][0]==table[1][1]&&table[0][0]==table[2][2]&&table[0][0]!=0) || (table[0][2]==table[1][1]&&table[0][2]==table[2][0]&&table[0][2]!=0)){
		win=3;
	}
	return win;	
}

void Think(){
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(table[i][j]==hand){
				win++;
			}
			if(win==2){
				if(table[i][0]==table[i][1]&&table[i][2]==0){
					r=10*i+10+3;
					break;
				} 
				else if(table[i][1]==table[i][2]&&table[i][0]==0){ 
					r=10*i+10+1;
					break;
				} 
				else if(table[i][0]==table[i][2]&&table[i][1]==0){ 
					r=10*i+10+2;
					break;
				}
			}
		}
		win=0;
	}
	for(i=0;i<=2;i++){
		for(j=0;j<=2;j++){
			if(table[j][i]==hand){
				win++;
			}
			if(win==2){
				if(table[0][i]==table[1][i]&&table[2][i]==0){
					r=30+i+1;
					break;
				} 
				else if(table[1][i]==table[2][i]&&table[0][i]==0){ 
					r=10+i+1;
					break;
				} 
				else if(table[0][i]==table[2][i]&&table[1][i]==0){ 
					r=20+i+1;
					break;
				}
			}
		}
		win=0;
	}
	if(table[0][0]==table[1][1]&&table[2][2]==0)
		r=33;
	else if(table[0][0]==table[2][2]&&table[1][1]==0)
		r=22;
	else if(table[1][1]==table[2][2]&&table[0][0]==0)
		r=11;
	else if(table[0][2]==table[1][1]&&table[2][0]==0)
		r=31;
	else if(table[2][0]==table[1][1]&&table[0][2]==0)
		r=13;
	else if(table[0][2]==table[2][0]&&table[1][1]==0)
		r=22;
}

void Ain(){
		cout<<"輪到電腦"<<"，請輸入要填入的位置代碼";
		F=(r-10)/10;
    	S=(r-1)%10;
		while(table[F][S]!=0){
			r=rand()%3+1+(rand()%3)*10+10;
			F=(r-10)/10;
    		S=(r-1)%10;
		}
		cout<<r<<endl;
		table[F][S]=AI;
}
int main(){
	cout<<"單人遊戲按 1"<<endl<<"雙人遊戲按 2"<<endl; 
	cin>>mod;
	while(mod!=1&&mod!=2){
		cout<<"錯誤請重新輸入";
		cin>>mod; 
	}
	if(mod==1){
	srand(time(NULL));
	cout<<"歡迎遊玩OOXX遊戲\n請輸入O或X(請輸入大寫)"<<endl;
	cin>>hand;
	while(hand!='O' && hand!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>hand;
    }
 	if(hand=='O')
       AI='X';
    else
    	AI='O';
    Table();
    if(hand=='O'){
    	step=1;
    	input();
	}
	else{
		step=2;
		cout<<"輪到電腦"<<"，請輸入要填入的位置代碼";
		r=22;
		cout<<r<<endl;
		F=(r-10)/10;
    	S=(r-1)%10;
		table[F][S]=AI;
	}
	Table();
	if(step==1){
		for(int k=1;k<=4;k++){
		
		Think();
		Ain();
		Table();
		result(AI);
		if(win==3){
				cout<<"AI Win!"<<endl;
				break;
			}
		input();
		Table();
		result(hand);
		if(win==3){
				cout<<"You Win!"<<endl;
				break;
			}
		}
	}
	else if(step==2){
		for(int k=1;k<=4;k++){
			input();
			Table();
			result(hand);
			if(win==3){
				cout<<"You Win!"<<endl;
				break;
			}
			Think();
			Ain();
			Table();
			result(AI);
			if(win==3){
				cout<<"AI Win!"<<endl;
				break;
			}
		}
	}
	if(win!=3)
		cout<<"平局"<<endl; 
		
}
	else if(mod==2){
	
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
}
