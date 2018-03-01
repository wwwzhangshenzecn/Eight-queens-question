/*
	编程解决"八皇后问题":即在一个8*8的矩形格子中排放8个
皇后,要满足的条件包括:任意两个皇后都不能在同一行/列/对角
线(斜率等于1/-1).
	要求编程给出所有第一行第一列有皇后的解
(注：解的输出用8个数字表示,如：基本解{1,5,8,6,3,7,2,4},其
中'1'表示第一行第一列即(1,1)处有皇后, 后同)
*/
/*
	0.结构体设计,int **a=8*8数组（初始为0，值为1代表皇后已置下），stack s(放置8皇后位置，用于放置与回溯记录).
	1.检测函数，横，竖，正斜，反斜都不能与其他皇后同一直线
	2.回溯，放置皇后置1，回溯皇后置0
	3.输出皇后问题解

	行递归，列循环，记录列位置
*/
#include<iostream>
#include<stack>
#include<time.h>
using namespace std;
#define N 9
int a[N][N]={0}; //棋盘，x[1-8]\y[1-8]
stack<int > Y; //记录置下女王的竖坐标
bool Determine(int x,int y){
	/*
		判断女王位置是否矛盾：
			1.x轴方向不能冲突，仅有一个女王
			2.正斜方向不能冲突，仅有一个女王，斜率为1
			3.反斜方向不能冲突，仅有一个女王，斜率为-1
			4.y轴fang向不能冲突
	*/
	int i,j;
	for(i=1;i<N;i++){
		if(a[i][y]==1 &&i!=x) return false; // 1.
		
		j=-1*i+x+y;
		if(j>=1&&j<=8&& a[i][j]==1 &&i!=x) return false;//3.
		
		j=i-x+y;
		if(j>=1&&j<=8&& a[i][j]==1 &&i!=x) return false; //2.

		if(a[x][i]==1 &&i!=x) return false; // 4.
		
	}
	return true;
}
void Print(){
	/*
		输出女王位置，基本解如：{1,5,8,6,3,7,2,4}
	*/
	stack<int > temp=Y;
	int a[N]={0},i=N-1;
	while(!temp.empty())
		a[i--]=temp.top(),temp.pop();
	cout<<"{ ";
	for(int i=1;i<N;i++){
		if(i<N-1)
			cout<<a[i]<<" , ";
		else
			cout<<a[i];
	}
	cout<<" }"<<endl;
}
void Queen(int x){
	/*
		八皇后问题。
	*/
	if(x==9)
		Print();//输出基本解
	else{
		int j=1,i=x;
		for(j=1;j<N;j++){ //列循环
			bool I_J=Determine(i,j);
			if(I_J){ //能放置
				a[i][j]=1;
				Y.push(j); //记录
				Queen(i+1);	//递归
				a[i][j]=0;
				Y.pop(); //回溯
			}//if
		}//for
	}//else
}
int main(){
	Queen(1);//共92组解
	return 0;
}