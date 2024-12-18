#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// to avoid trash values,we are using the empty spaces for loop
const int mazesize=15;
char maze[mazesize][mazesize]; //declaration of array for rows and colums
void printmaze(); ///it is used for display
void generatemaze(); ///it is used for creation
int playerstartY=1;
int playerstartX=1;
int playerhealth=10;
bool moveplayer(int dx,int dy);
void defeatenemy();
void printmaze()
{
	cout<<endl;
	for(int row=0;row<mazesize;row++)
	{
		for(int col=0;col<mazesize;col++)
		{
			cout<<maze[row][col]<<" "; //double spaces would be more feasible
		}
		cout<<endl;
	}
}
void generatemaze()
{
	for(int i=0;i<mazesize;i++)
	{
		for(int j=0;j<mazesize;j++)
		{
			maze[i][j]=' '; //to trash out the garbage values and show empty spaces
		}
	}
	for(int col=0;col<mazesize;col++) //for top and bottom boundaries
	{
		maze[0][col]='-';  //for first row
		maze[mazesize-1][col]='-'; //for last row
	}
	for(int row=0;row<mazesize;row++) // for left and right boundary
	{
		maze[row][0]='-'; //for first column
		maze[row][mazesize-1]='-'; //for last colum
	}
	maze[playerstartX][playerstartY]='P';
	int treasuremazeX=rand() %(mazesize-1);
	int treasuremazeY=rand() %(mazesize-1);
	if(treasuremazeX==0)
	treasuremazeX=1;
	if(treasuremazeY==0)
	treasuremazeY=1;
	maze[treasuremazeX][treasuremazeY]='T';
	
	int numofobstacles=rand()%10+4;
	for(int i=0;i<numofobstacles;i++)
	{
	int	obstaclex=rand()%mazesize;
	int	obstacley=rand()%mazesize;
	if(maze[obstaclex][obstacley]==' ')
		maze[obstaclex][obstacley]='O';
	}
	int numofenemies=rand()%10+4;
	for(int i=0;i<numofenemies;i++)
	{
	int	enemyx=rand()%mazesize;
	int	enemyy=rand()%mazesize;
	if(maze[enemyx][enemyy]==' ')
		maze[enemyx][enemyy]='E';
	}
	int numofdoors=rand()%5+2;
	for(int i=0;i<numofdoors;i++)
	{
	int	doorx=rand()%mazesize;
	int	doory=rand()%mazesize;
	if(maze[doorx][doory]==' ')
		maze[doorx][doory]=char(219);
	}
}
int main()
{
	srand(time(0));
	generatemaze();
	printmaze();
	int steps=0;
	while(playerhealth>0)
	{
		steps ++;
		bool treasure=0;
		char direction;
		cout<<"Enter a direction(u,d,l,r):";
		cin>>direction;
		system("cls");
		switch(direction)
		{
			case 'u':
				treasure=moveplayer(-1,0);
				break;
			case 'd':
				treasure=moveplayer(1,0);
				break;
			case 'l':
				treasure=moveplayer(0,-1);
				break;
			case 'r':
				treasure=moveplayer(0,1);
				break;
			default:
				cout<<"You have entered an invalid direction:"<<endl;
				break;
			}
			if(treasure==1)
			{
			cout<<"You found the treasure";
			break;
		}
		printmaze();
		cout<<"your current health is:"<<playerhealth<<endl;
	}
	if(playerhealth<=0)
	cout<<"You ran out of health. Game Over";
	else
	cout<<"You won the game";
}
bool moveplayer(int dx,int dy)
{
	int newX=playerstartX+dx;
	int newY=playerstartY+dy; //indicating new direction
	
	if (maze[newX][newY]=='T') //agla player next direction pe shaid treasure na para hn is liye checkpoint ha yeh
	return 1;
	if(maze[newX][newY]=='-')
	{cout<<"You hit a wall!";
	playerhealth--;
	return 0; //our player was moving towards boundary,thats why we switched to use return 0; so that there is no affect of direction on the player
    }
	if(maze[newX][newY]=='O')
	{cout<<"You hit an obstacle!";
	playerhealth--;
	return 0; //our player was moving towards obstacle,thats why we switched to use return 0; so that there is no affect of direction on the player
    }
    if(maze[newX][newY]=='E')
	{cout<<"You encountered an enemy!";
	defeatenemy(); 
}
	if(maze[newX][newY]== char(219))
	{cout<<"You Entered a door";
	playerhealth+=5;
}
	
	maze[playerstartX][playerstartY]=' ';
	playerstartX=newX; //on left, always comes the update thing
	playerstartY=newY;
	maze[playerstartX][playerstartY]='P';
	return 0;
}
void defeatenemy()
{
	while(playerhealth>0)
	{
	int enemy=rand()%10+1;
	int inp;
	cout<<"Enter a number between 1 and 10 \nand if the gap between your and enemy number it >=3,\nyour points will increase +5,\n"<<endl<<
    "And if you lost, your points will be deducted -4 "<<endl;
    cin>>inp;
    int ans=enemy-inp;
    if(ans<=0)
    ans*=-1;
    if(ans>=3)
    {
	cout<<"Your won the number"<<" enemy guess "<<enemy<<" your guess "<<inp<<endl;
    playerhealth+=3;
    return;
}
else
{
cout<<"you lost.Try again";
playerhealth-=4;
cout<<"current health"<<playerhealth<<endl;
}
    
}
return ;
}












