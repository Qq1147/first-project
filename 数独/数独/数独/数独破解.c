#include"pch.h"
#include<stdio.h>

#if(1)
void pojie(int num[9][9]);
int pojie_p(int num[9][9], int i, int j);
int jiancha(int num[9][9]);
int panduan(int num[9][9], int i, int j);
int panduan_xie(int num[9][9], int i, int j);
int panduan_hang(int num[9][9], int i, int j);
int panduan_shu(int num[9][9], int i, int j);
int panduan_fujin(int num[9][9], int i, int j);
#endif

int main()
{
	int n, tmp, x, i = 0, j = 0;
	int num[9][9] = { 0 };
	printf("数独傻瓜式破解\n");
	printf("请输入已有的数字,没有的0补充\n");
	printf("例如:123456000\n");
//	int num[9][9] = { {0,0,4,6,0,2,0,0,0 }, {6,0,0,0,3,0,0,0,4}, {0,2,0,4,0,0,0,9,0},{9,8,0,0,0,0,3,5,0},{1,0,3,0,0,0,0,4,0},{0,6,0,0,0,0,8,0,7},{0,3,0,0,2,0,0,7,0},{0,0,0,0,6,1,0,0,5},{0,0,9,3,0,0,4,0,0} };

	for (i=0;i<9;i++)
	{
		printf("[%d][%d]:", i + 1, j + 1);
		scanf_s("%d", &n);
		x = 8;
		while (x>=0)
		{
			tmp = n % 10;
			n = n / 10;
			num[i][x] =tmp;
			x--;
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			printf("%d", num[i][j]);
		}
		printf("\n");
	}
	pojie(num);
	system("pause");
	return 0;
}
void pojie(int num[9][9])
{
	int NUM;
	int i=0, j=0;
	NUM=jiancha(num);//首先检查输入有没有问题
	if (NUM == 1)
	{
		printf("输入有误\n");
		exit(1);
	}
	/*下面是解法思路*/
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			if (num[i][j] == 0)
				goto ij;
		}
	}//得到第一个0的位置
ij:
	printf("\n\n");
	pojie_p(num, i, j);//破解完成
	printf("破解完成\n");
	printf("\n\n");
	NUM =jiancha(num);//再检查一遍
	if (NUM == 1)
	{
		printf("输入有误\n");
		exit(1);
	}
	return;
}
int pojie_p(int num[9][9], int i, int j)
{
	int x,n=0;
	int a, b,tmp=1;
	int q, w;
	q = w = 0;
	int NUM=0;//1为有误，0为无误
	for (x=1;x<10;x++)
	{
		num[i][j] = x;//赋值到指定坐标里
		if (1)
		{
			if ((i == j) || ((i + j) == 8))//判断斜或者交叉
			{
//				NUM = panduan_xie(num, i, j);
			}
			if (NUM == 1)
			{
				NUM = 0;
				continue;//判断斜或者交叉有该数
			}
			NUM = panduan_hang(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//判断有该数
			}
			NUM = panduan_shu(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//判断有该数
			}
			NUM = panduan_fujin(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//判断有该数
			}
		}
		/*上面是判断行竖斜交集是否有误*/
		if (1)
		{
			for (a = 0; a < 9; a++)//这里是得到下一个0的位置
			{
				for (b = 0; b < 9; b++)
				{
					if (num[a][b] == 0)
					{
						goto aa;
					}
					if ((a == 8) && (b == 8))//若到了[8][8]位置，可以输出了
					{
						for (q = 0; q < 9; q++)
						{
							for (w = 0; w < 9; w++)
							{
								printf("%d", num[q][w]);
							}
							printf("\n");
						}
						printf("\n\n");
						tmp = 1;
						return tmp;
					}
				}
			}
		}
		bb:
		if (0)
		{
		aa:
			tmp=pojie_p(num, a, b);
			if (tmp==1)
			{
				return tmp;
			}
		}
	}
	if (x == 10)
	{
		num[i][j] = 0;//循环1-9都没有适合的数，重新设置为0并返回上一层
	}
	return;//返回上一层

}
#if(1)
int jiancha(int num[9][9])
{
	int i = 0, j = 0, n = 0;//n=[i][j]
	int NUM=0;//1为有误，0为无误
	for(i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			n = num[i][j];//得到坐标num的值
			if (n==0)
			{
				continue;//n==0跳过此次循环
			}
			NUM = panduan(num,i,j);
			if (NUM==1)
			{
				goto jiancha_over;//有误结束
			}
		}
	}
jiancha_over:

	return NUM;
}
int panduan(int num[9][9], int i, int j)
{
	/*判断num[i][j]行竖斜附近是否有相同值	*/
	/*有相同值返回1，无相同值返回0			*/
	int n, tmp, NUM=0;

	if ((i==j)||((i+j)==8))//需要判断斜是否有相同值
	{
//		NUM=panduan_xie(num, i, j);
		if (NUM == 1)
			goto panduan_over;
	}
	NUM = panduan_hang(num, i, j);
	if (NUM == 1)
		goto panduan_over;
	NUM = panduan_shu(num, i, j);
	if (NUM == 1)
		goto panduan_over;
	NUM = panduan_fujin(num, i, j);
	if (NUM == 1)
		goto panduan_over;
panduan_over:
	return NUM;
}
int panduan_xie(int num[9][9], int i, int j)
{
	/*判断num[i][j]斜是否有相同值	*/
	/*有相同值返回1，无相同值返回0	*/
	int z,NUM=0;
	int x, y;
	if (i == j)
	{
		for (z = 0; z < 9; z++)
		{
			if (z == i)
			{
				continue;
			}
			if (num[i][i] == num[z][z])
			{
				NUM = 1;
				break;
			}
		}
	}
	if (8==(i+j))
	{
		for (x=0,y=8;;x++,y--)
		{
			if ((x==9))
			{
				break;//循环结束
			}
			if (((i==x)&&(j==y))||(num[x][y]==0))
			{
				continue;
			}
			if (num[i][j]==num[x][y])
			{
				NUM = 1;
				break;
			}
		}
	}
	return NUM;
}
int panduan_hang(int num[9][9], int i, int j)
{
	/*判断num[i][j]行是否有相同值	*/
	/*有相同值返回1，无相同值返回0	*/
	int z;
	int NUM=0;
	for (z=0;z<9;z++)
	{
		if (num[i][z]==0)
		{
			continue;//num[i][z]==0
		}
		if (j==z)
		{
			continue;
		}
		if (num[i][j]==num[i][z])
		{
			NUM = 1;//相同有误
			break;
		}
	}
	return NUM;
}
int panduan_shu(int num[9][9], int i, int j)
{
	/*判断num[i][j]竖是否有相同值	*/
	/*有相同值返回1，无相同值返回0	*/
	int z;
	int NUM = 0;
	for (z = 0; z < 9; z++)
	{
		if (num[z][j] == 0)
		{
			continue;//num[z][j]==0
		}
		if (i == z)
		{
			continue;
		}
		if (num[i][j] == num[z][j])
		{
			NUM = 1;//相同有误
			break;
		}
	}
	return NUM;
}
int panduan_fujin(int num[9][9], int i, int j)
{
	/*判断num[i][j]附近是否有相同值	*/
	/*有相同值返回1，无相同值返回0	*/
	int x, y, z,tmp,NUM=0;
	x = i / 3;
	y = j / 3;
	x = x * 3;
	y = y * 3;

	for(z=0;z<3;z++)
	{
		for (tmp=0;tmp<3;tmp++)
		{
			if (((i==x+z)&&(j==y+tmp))||(num[x+z][y+tmp]==0))
			{
				continue;
			}
			if (num[i][j]==num[x+z][y+tmp])
			{
				NUM = 1;
				goto fujin_over;
			}
		}
	}
fujin_over:
	return NUM;
}
#endif//检查行竖斜附近是否有相同值
