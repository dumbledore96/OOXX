# OOXX遊戲

## 原始版本
### 原始版本1.0
```c=
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t=0,fin=0;
    int a[5][5]={};
    char w[3];
    cout<<"歡迎遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';
    
    while(fin==0){
        int r,i,j;
        
       
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        } 

        cout<<"輪到"<<w[t%2+1]<<"，請輸入要填入的位置代碼";
        cin>>r;
        while(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
            cout<<"該位置不存在，請重新輸入";
            cin>>r;
        }
        i=r/10;
        j=r%10;
        while(a[i][j]!=0){
            cout<<"該位置已使用，請重新輸入";
            cin>>r;
            i=r/10;
            j=r%10;
        }
        a[i][j]=t%2+1;

        for(i=1 ; i<=3 ; i++){
            if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=0){
                fin=t%2+1;
            }
            if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[1][i]!=0){
                fin=t%2+1;
            }
        }
        if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[1][1]!=0){
            fin=t%2+1;
        }
        if(a[1][3]==a[2][2] && a[2][2]==a[3][1] && a[3][1]!=0){
            fin=t%2+1;
        }
        
        int tie=0;
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==0)
                    tie=1;
                
            }
        }
        if(tie==0 && fin==0){
            fin=3;
        }
        
        t++;        
    }

    for (int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ;j++){
            if (a[i][j]==1)
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl;
    } 
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<w[fin]<<"獲勝"<<endl;
    }    
    return 0;
}
```


### 原始版本2.0
1. 修正輸入錯誤值的漏洞
```c=
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int t=0,fin=0,ok=0;
    int a[5][5]={};
    char w[3];
    cout<<"歡迎遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';
    
    while(fin==0){
        int r,i,j;
        
       
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        } 

        cout<<"輪到"<<w[t%2+1]<<"，請輸入要填入的位置代碼";
        cin>>r;
        do{
			i=r/10;
        	j=r%10;	
        	if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
				ok=1;
				cout<<"該位置不存在，請重新輸入";
            	cin>>r;
			}
        	
        	else if(a[i][j]!=0){
        		ok=1;
        		cout<<"該位置已使用，請重新輸入";
            	cin>>r;
			}	
			else{
				ok=0;
			}
		}while(ok==1);
        
        a[i][j]=t%2+1;

        for(i=1 ; i<=3 ; i++){
            if(a[i][1]==a[i][2] && a[i][2]==a[i][3] && a[i][1]!=0){
                fin=t%2+1;
            }
            if(a[1][i]==a[2][i] && a[2][i]==a[3][i] && a[1][i]!=0){
                fin=t%2+1;
            }
        }
        if(a[1][1]==a[2][2] && a[2][2]==a[3][3] && a[1][1]!=0){
            fin=t%2+1;
        }
        if(a[1][3]==a[2][2] && a[2][2]==a[3][1] && a[3][1]!=0){
            fin=t%2+1;
        }
        
        ok=0;
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==0)
                    ok=1;
                
            }
        }
        if(ok==0 && fin==0){
            fin=3;
        }
        
        t++;        
    }

    for (int i=1 ; i<=3 ; i++){
        for(int j=1 ; j<=3 ;j++){
            if (a[i][j]==1)
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl;
    } 
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<w[fin]<<"獲勝"<<endl;
    }    
    return 0;
}
```
### 原始版本3.0
1. 修復最後九宮格輸出排版問題
2. 修改變數名稱，增加修改便利性

```c=
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
```
## 斥赤AI版
### 斥赤AI版1.0

```c=
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
srand(time(NULL));
    int turn=0,fin=0,ok=0;
    int a[5][5]={};
    char w[3];
    
    cout<<"遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';
    
    while(fin==0){
        int r,i,j;
        r+=10*(rand()%4+1);
       
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        } 

        cout<<"輪到"<<w[turn%2+1]<<"，請輸入要填入的位置代碼"<<endl;
        if(turn%2+1!=1)
		{
			int repeat=0;
			r+=rand()%3+1;
		i=r/10;
        	j=r%10;	
			while(repeat==0)
			{
			
	    
		
		 if(a[i][j]!=0){
        		ok=0;
            	r=rand()%3+1+10*(rand()%3)+10;		
		       i=r/10;
        	j=r%10;	
		
			}
			else repeat=1;
			}
			
			}
			
		if(turn%2+1==1)
		{
		
		cin>>r;
        do{
			i=r/10;
        	j=r%10;	
        	if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
				ok=1;
				cout<<"該位置不存在，請重新輸入";
            	cin>>r;
			}
        	
        	else if(a[i][j]!=0){
        		ok=1;
        		cout<<"該位置已使用，請重新輸入";
            	cin>>r;
			}	
			else{
				ok=0;
			}
		}while(ok==1);
        }
        a[i][j]=turn%2+1;

        for(i=1 ; i<=3 ; i++){
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
        
        ok=0;
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
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl;
    } 
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<w[fin]<<"獲勝"<<endl;
    }    
    return 0;}
```

### 斥赤AI版2.0
```c=
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
srand(time(NULL));
    int turn=0,fin=0,ok=0;
    int a[5][5]={};
    char w[3];

    cout<<"歡迎遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';

    while(fin==0){
        int r,i,j;
        r+=10*(rand()%3+1);
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        }

        cout<<"輪到"<<w[turn%2+1]<<"，請輸入要填入的位置代碼"<<endl;
        if(turn%2+1!=1)
		{
			int repeat=0;

			while(repeat==0)
			{
            if(a[i][j]!=0){
                ok=0;
                r=rand()%3+1+10*(rand()%3)+10;
                i=r/10;
                j=r%10;	}
            else if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33)
            {
                ok=0;
                r=rand()%3+1+10*(rand()%3)+10;
                i=r/10;
                j=r%10;
            }
            else{
                i=r/10;
                j=r%10;

                repeat=1;}
			}
			cout<<r<<endl;
		}

		if(turn%2+1==1)
		{
            cin>>r;
            do{
                i=r/10;
                j=r%10;
                if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
                    ok=1;
                    cout<<"該位置不存在，請重新輸入";
                    cin>>r;
                }

                else if(a[i][j]!=0){
                    ok=1;
                    cout<<"該位置已使用，請重新輸入";
                    cin>>r;
                }
                else{
                    ok=0;
                }
            }while(ok==1);
        }
        a[i][j]=turn%2+1;

        for(i=1 ; i<=3 ; i++){
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

        ok=0;
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
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl;
    }
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<w[fin]<<"獲勝"<<endl;
    }
    return 0;
}
```
### 斥赤AI版3.0
```c=
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
srand(time(NULL));
    int turn=0,fin=0,ok=0;
    int a[5][5]={};
    char w[3];
    
    cout<<"遊玩OOXX遊戲\n請輸入先手為O或X(請輸入大寫)"<<endl;
    cin>>w[1];
    while(w[1]!='O' && w[1]!='X'){
        cout<<"非O或X，請重新輸入";
        cin>>w[1];
    }
    if(w[1]=='O')
        w[2]='X';
    if(w[1]=='X')
        w[2]='O';
    
    while(fin==0){
        int r,i,j;
       
        for (i=1 ; i<=3 ; i++){
            for(j=1 ; j<=3 ;j++){
                if (a[i][j]==1)
                    cout<<setw(3)<<w[1];
                else if(a[i][j]==2)
                    cout<<setw(3)<<w[2];
                else
                    cout<<setw(3)<<i*10+j;
            }
            cout<<endl<<endl;
        } 
        cout<<"輪到"<<w[turn%2+1]<<"，請輸入要填入的位置代碼"<<endl;
        if(turn%2+1!=1){
			int repeat=0,b[5][5]={},ok=0;
			r=0;						
			for(i=1;i<=3;i++){
                for(j=1;j<=3;j++){
                    b[i][j]=a[i][j];
                }
			}
			for(i=1;i<=3;i++){			
                for(j=1;j<=3;j++){
                    if(b[i][j]=0){   
                        for(i=1 ; i<=3 ; i++){
                            if(b[i][1]==b[i][2] && b[i][2]==b[i][3] && b[i][1]!=0){
                                r=i*10+j;repeat=1; i=r/10;
                                j=r%10;
                            }
                            else if(b[1][i]==b[2][i] && b[2][i]==b[3][i] && b[1][i]!=0){
                                r=i*10+j; repeat=1;i=r/10;
                                j=r%10;                       
                            }
                        }
                        if(b[1][1]==b[2][2] && b[2][2]==b[3][3] && b[1][1]!=0){
                            r=i*10+j; repeat=1;i=r/10;
                            j=r%10;
                        }
                        else if(b[1][3]==b[2][2] && b[2][2]==b[3][1] && b[3][1]!=0){
                            r=i*10+j; repeat=1;i=r/10;
                            j=r%10;
                        }
                    }
                    
                }
		    }
            if(a[2][2]==0){
                r=22;i=2;j=2;
                repeat=1;
            }
                            
            while(repeat==0){
                
                if(a[i][j]!=0){
                    ok=0; 		
                    r=rand()%3+1+10*(rand()%3)+10;		
                    i=r/10;
                    j=r%10;	
                }
                else if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
                    ok=0;
                    r=rand()%3+1+10*(rand()%3)+10;		
                    i=r/10;
                    j=r%10;	
                }
                else{
                    i=r/10;
                    j=r%10;               
                    repeat=1;
                }
            }
			cout<<r<<endl;
		}
			
		if(turn%2+1==1){
            cin>>r;
            do{
                i=r/10;
                j=r%10;	
                if(r!=11 && r!=12 && r!=13 && r!=21 && r!=22 && r!=23 && r!=31 && r!=32 && r!=33){
                    ok=1;
                    cout<<"該位置不存在，請重新輸入";
                    cin>>r;
                }
                
                else if(a[i][j]!=0){
                    ok=1;
                    cout<<"該位置已使用，請重新輸入";
                    cin>>r;
                }	
                else{
                    ok=0;
                }
            }while(ok==1);
        }
        a[i][j]=turn%2+1;

        for(i=1 ; i<=3 ; i++){
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
        
        ok=0;
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
                cout<<setw(3)<<w[1];
            else if(a[i][j]==2)
                 cout<<setw(3)<<w[2];
            else
                cout<<setw(3)<<i*10+j;
        }
         cout<<endl<<endl;
    } 
    if(fin==3){
        cout<<"平局"<<endl;
    }
    else{
        cout<<"恭喜"<<w[fin]<<"獲勝"<<endl;
    }    
    return 0;
}
```
有問題請反白並留言