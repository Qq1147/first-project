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
	printf("����ɵ��ʽ�ƽ�\n");
	printf("���������е�����,û�е�0����\n");
	printf("����:123456000\n");
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
	NUM=jiancha(num);//���ȼ��������û������
	if (NUM == 1)
	{
		printf("��������\n");
		exit(1);
	}
	/*�����ǽⷨ˼·*/
	for (i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			if (num[i][j] == 0)
				goto ij;
		}
	}//�õ���һ��0��λ��
ij:
	printf("\n\n");
	pojie_p(num, i, j);//�ƽ����
	printf("�ƽ����\n");
	printf("\n\n");
	NUM =jiancha(num);//�ټ��һ��
	if (NUM == 1)
	{
		printf("��������\n");
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
	int NUM=0;//1Ϊ����0Ϊ����
	for (x=1;x<10;x++)
	{
		num[i][j] = x;//��ֵ��ָ��������
		if (1)
		{
			if ((i == j) || ((i + j) == 8))//�ж�б���߽���
			{
//				NUM = panduan_xie(num, i, j);
			}
			if (NUM == 1)
			{
				NUM = 0;
				continue;//�ж�б���߽����и���
			}
			NUM = panduan_hang(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//�ж��и���
			}
			NUM = panduan_shu(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//�ж��и���
			}
			NUM = panduan_fujin(num, i, j);
			if (NUM == 1)
			{
				NUM = 0;
				continue;//�ж��и���
			}
		}
		/*�������ж�����б�����Ƿ�����*/
		if (1)
		{
			for (a = 0; a < 9; a++)//�����ǵõ���һ��0��λ��
			{
				for (b = 0; b < 9; b++)
				{
					if (num[a][b] == 0)
					{
						goto aa;
					}
					if ((a == 8) && (b == 8))//������[8][8]λ�ã����������
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
		num[i][j] = 0;//ѭ��1-9��û���ʺϵ�������������Ϊ0��������һ��
	}
	return;//������һ��

}
#if(1)
int jiancha(int num[9][9])
{
	int i = 0, j = 0, n = 0;//n=[i][j]
	int NUM=0;//1Ϊ����0Ϊ����
	for(i=0;i<9;i++)
	{
		for (j=0;j<9;j++)
		{
			n = num[i][j];//�õ�����num��ֵ
			if (n==0)
			{
				continue;//n==0�����˴�ѭ��
			}
			NUM = panduan(num,i,j);
			if (NUM==1)
			{
				goto jiancha_over;//�������
			}
		}
	}
jiancha_over:

	return NUM;
}
int panduan(int num[9][9], int i, int j)
{
	/*�ж�num[i][j]����б�����Ƿ�����ֵͬ	*/
	/*����ֵͬ����1������ֵͬ����0			*/
	int n, tmp, NUM=0;

	if ((i==j)||((i+j)==8))//��Ҫ�ж�б�Ƿ�����ֵͬ
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
	/*�ж�num[i][j]б�Ƿ�����ֵͬ	*/
	/*����ֵͬ����1������ֵͬ����0	*/
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
				break;//ѭ������
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
	/*�ж�num[i][j]���Ƿ�����ֵͬ	*/
	/*����ֵͬ����1������ֵͬ����0	*/
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
			NUM = 1;//��ͬ����
			break;
		}
	}
	return NUM;
}
int panduan_shu(int num[9][9], int i, int j)
{
	/*�ж�num[i][j]���Ƿ�����ֵͬ	*/
	/*����ֵͬ����1������ֵͬ����0	*/
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
			NUM = 1;//��ͬ����
			break;
		}
	}
	return NUM;
}
int panduan_fujin(int num[9][9], int i, int j)
{
	/*�ж�num[i][j]�����Ƿ�����ֵͬ	*/
	/*����ֵͬ����1������ֵͬ����0	*/
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
#endif//�������б�����Ƿ�����ֵͬ
