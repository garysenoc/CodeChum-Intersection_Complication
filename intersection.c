#include <stdio.h>

int main(){
	
	int n,i,j,steps,move,center,x,y,happen=0;
	
	scanf("%d",&n);
	char arr[n][n];
	
	scanf("%d",&steps);
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			arr[i][j] = '*';
			
	arr[n/2][n/2] = '0';
	x = n/2;
	y = x;
	for(i=1;i<=steps;i++){
	scanf("%d",&move);
		if(i%4==1){
			for(j=1;j<=move;j++){
				if(arr[x-j][y] == '0'){
					arr[x-j][y] = '1';
					happen =1;
					goto here;
				}
				else if(x-j<0){
					happen = 2;
						goto here;
				}
				else{
					arr[x-j][y] = '0';	
				}		
			}
				x = x - move;	
		}
		else if(i%4== 2){
			for(j=1;j<=move;j++){
				if(arr[x][y+j] == '0'){
					arr[x][y+j] = '1';
					happen =1;
					goto here;
				}
				else if(y+j>n-1){
					happen = 2;
					goto here;
				}
				else{
					arr[x][y+j] = '0';	
				}
			}
			y = y+move;	
		}
		else if(i%4 == 3){
			for(j=1;j<=move;j++)
			{
			
				if(arr[x+j][y] == '0'){
					arr[x+j][y] = '1';
					happen =1;
					goto here;
				}
				else if(x+j>n-1){
					happen = 2;
				goto here;
				}
				else{
					arr[x+j][y] = '0';
						
				}	
			}
			x = x+move;
		
		}
		else if(i%4 == 0){
			for(j=1;j<=move;j++){
			
				if(arr[x][y-j] == '0'){
					arr[x][y-j] = '1';
					happen =1;
					goto here;
				}
				else if(y-j<0){
					happen = 2;
					goto here;
				}
				else
				{
				arr[x][y-j] = '0';
				}	
			
			}
			y = y-move;	
		}
	}
	here:
	if(happen ==0)
		printf("No Intersection");
	else if(happen ==1)
		printf("Intersection");
	else if(happen == 2)
		printf("Out of Bounds");
		
}
