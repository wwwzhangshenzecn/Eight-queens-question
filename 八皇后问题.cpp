/*
	��̽��"�˻ʺ�����":����һ��8*8�ľ��θ������ŷ�8��
�ʺ�,Ҫ�������������:���������ʺ󶼲�����ͬһ��/��/�Խ�
��(б�ʵ���1/-1).
	Ҫ���̸������е�һ�е�һ���лʺ�Ľ�
(ע����������8�����ֱ�ʾ,�磺������{1,5,8,6,3,7,2,4},��
��'1'��ʾ��һ�е�һ�м�(1,1)���лʺ�, ��ͬ)
*/
/*
	0.�ṹ�����,int **a=8*8���飨��ʼΪ0��ֵΪ1����ʺ������£���stack s(����8�ʺ�λ�ã����ڷ�������ݼ�¼).
	1.��⺯�����ᣬ������б����б�������������ʺ�ͬһֱ��
	2.���ݣ����ûʺ���1�����ݻʺ���0
	3.����ʺ������

	�еݹ飬��ѭ������¼��λ��
*/
#include<iostream>
#include<stack>
#include<time.h>
using namespace std;
#define N 9
int a[N][N]={0}; //���̣�x[1-8]\y[1-8]
stack<int > Y; //��¼����Ů����������
bool Determine(int x,int y){
	/*
		�ж�Ů��λ���Ƿ�ì�ܣ�
			1.x�᷽���ܳ�ͻ������һ��Ů��
			2.��б�����ܳ�ͻ������һ��Ů����б��Ϊ1
			3.��б�����ܳ�ͻ������һ��Ů����б��Ϊ-1
			4.y��fang���ܳ�ͻ
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
		���Ů��λ�ã��������磺{1,5,8,6,3,7,2,4}
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
		�˻ʺ����⡣
	*/
	if(x==9)
		Print();//���������
	else{
		int j=1,i=x;
		for(j=1;j<N;j++){ //��ѭ��
			bool I_J=Determine(i,j);
			if(I_J){ //�ܷ���
				a[i][j]=1;
				Y.push(j); //��¼
				Queen(i+1);	//�ݹ�
				a[i][j]=0;
				Y.pop(); //����
			}//if
		}//for
	}//else
}
int main(){
	Queen(1);//��92���
	return 0;
}