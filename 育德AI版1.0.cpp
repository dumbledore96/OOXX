#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
char hand,AI;
int r,F,S,i,j,win=0,step=1;
char table[3][3]={};

void Table(){
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

void input(){
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
				cout<<"你輸了，電腦獲勝"<<endl;
				break;
			}
		input();
		Table();
		result(hand);
		if(win==3){
				cout<<"你贏了!"<<endl;
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
				cout<<"你贏了!"<<endl;
				break;
			}
			Think();
			Ain();
			Table();
			result(AI);
			if(win==3){
				cout<<"你輸了，電腦獲勝"<<endl;
				break;
			}
		}
	}
}
