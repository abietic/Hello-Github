#include <iostream>
void change(std::string list[],int& W,int N)
{
	if(W == N)
	{
		W = 0;
		return;
	}
	for(int i = W;i<N;i++)
	{
		list[i] = list[i+1];
	}
}
int main()
{
	int N;
	std::cin>>N;
	int n = N;
	std::string list[N],perform[N];
	for(int i = 0;i<N;i++)
	{
		std::cin>>list[i];
	}
	int W,S;
	char t;
	std::cin>>W>>t>>S;
	W--;
	int count = 0;
	while(S<=N)
	{
		W = (W+S-1)%N;
		perform[count++] = list[W];
		N--;
		change(list,W,N);
	}
	for(int j = 1;S != 1/*Ҫ����һ����S==1ʱ���ѭ����Ͳ��������������о�runtime erro֮ǰ������Ϊ���û���� = =; */;j++,(W = (W+1)%N))
	{
		if(!(j%S))
		{
			perform[count++] = list[W];
			N--;
			change(list,W,N);
		}
		if(!N)
		{
			break;
		}
	}
	for(int k = 0;k<n;k++)
	{
		std::cout<<perform[k]<<std::endl;
	}
	return 0;
}
