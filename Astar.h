#pragma once
#ifndef _ASTAR_H
#define _ASTAR_H

#include "iostream"
#include <list>
#include <cstdlib> 
#include <string>
#include <stdlib.h>
#include <vector>
#include <cmath>
#include<algorithm>
#include<fstream>
#include<typeinfo>
#include <cassert>
#include<stdio.h>

#define FILENAME "file.txt"
#define STEP  10
#define ANGLE 14
#define ROW   315
#define COL   186
int calcx1 = 0, calcy1 = 0, calcx2 = 0, calcy2 = 0, len;
int mapp[ROW][COL] = { 0 };//����һ���������ڴ������

using namespace std;

void Astar();


struct Point1
{

	Point1(int x, int y)
	{
		X = x;
		Y = y;
		F = 0;
		G = 0;
		H = 0;
		parent = NULL;
	}
	Point1()
	{

	}
	void CalcF()
	{
		F = G + H;
	}

	bool operator<(Point1 p2)
	{
		if (F < p2.F)
			return true;
		return false;
	}

	Point1 *parent;
	int F;
	int G;
	int H;
	int X;
	int Y;
};

class CFindPath
{
public:
	CFindPath();
	CFindPath(int map[][COL]);
	//~CFindPath();
	Point1 *GetPath(Point1 start, Point1 end, bool isAngle);//��ȡ·������;
	list<Point1> GetSurroundPoint(Point1 &, bool);//��ȡ��Χ�ɵ���ĵ�;
	bool IsCanReach(int x, int y);//�ж��Ƿ���ǽ��;
	void ChangePoint(Point1 start, Point1 point);//�ı����ڿ����б�ĵ�;
	void AddPoint(Point1 start, Point1 end, Point1 point);//��Ӳ��ڿ����б�ĵ�;
	int CalculateG(Point1, Point1);//����G
	int CalculateH(Point1 end, Point1 point);//����H
	bool IsCanReach(Point1 start, int x, int y, bool isAngle);//�ж��Ƿ�ɵ���;
	Point1 *FindOpenListPoint(Point1 p);
	Point1 *FindColseListPoint(Point1 p);
	Point1 *FPoint(Point1 p);
private:
	list<Point1> openList;//�����б�;
	list<Point1> colseList;//�ر��б�;
	list<Point1> temList;
	int points[ROW][COL];
};

CFindPath::CFindPath()
{

}
CFindPath::CFindPath(int map[][COL])
{
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			points[i][j] = map[i][j];
}
//CFindPath::~CFindPath()
//{
//	delete points;
//}



Point1* CFindPath::GetPath(Point1 start, Point1 end, bool isAngle)//�����㷨A*·������,isAngle��ʾ�Ƿ����Խ���ս�;
{
	openList.push_back(start);
	while (!openList.empty())
	{
		openList.sort();//����Fֵ��С��������;
		Point1 temp = openList.front();//ȡ��Fֵ��С��;
		colseList.push_back(temp);//���뵽�ر��б�;
		openList.pop_front();//�����б���ɾ��Fֵ��С��;
		list<Point1> surroundPoints = GetSurroundPoint(temp, isAngle);//ȡ����Χ�ɵ���ĵ�;      
		while (!surroundPoints.empty())//��ÿ���ɵ������Χ�ĵ�����ж�;
		{
			Point1 point = surroundPoints.front();
			if (FindOpenListPoint(point))//�������б��д��������;	
				ChangePoint(temp, point);//�ж��Ƿ�������·������Ǹı丸�����������ʲôҲ����;		
			else
				AddPoint(temp, end, point);//�����ڿ����б������;		
			surroundPoints.pop_front();
		}
		if (FindOpenListPoint(end))
			return FindOpenListPoint(end);
	}
	return FindOpenListPoint(end);
}



void CFindPath::ChangePoint(Point1 start, Point1 point)//�ı��ĸ�������¼���Fֵ;
{

	int G = CalculateG(start, point);
	if (G < point.G)
	{
		point.parent = new Point1(start);
		point.G = G;
		point.CalcF();
	}
}

void CFindPath::AddPoint(Point1 start, Point1 end, Point1 point)//��ӵ㵽�����б�;
{
	point.parent = new Point1(start);
	point.G = CalculateG(start, point);
	point.H = CalculateH(end, point);
	point.CalcF();
	openList.push_back(point);
}

int  CFindPath::CalculateG(Point1 start, Point1 point)//����Gֵ
{

	int parentG = 0;
	int G = (abs(point.X - start.X) + abs(point.Y - start.Y)) != 2 ? STEP : ANGLE;
	if (point.parent)
		parentG = point.parent->G != 0 ? point.parent->G : 0;
	return G + parentG;

}

int  CFindPath::CalculateH(Point1 end, Point1 point)//����Hֵ;
{
	int step = abs(point.X - end.X) + abs(point.Y - end.Y);
	return step * STEP;

}

Point1* CFindPath::FindOpenListPoint(Point1 p)//���ҵ��Ƿ��ڿ����б���;
{
	list<Point1>::iterator i;
	for (i = openList.begin(); i != openList.end(); i++)
	{
		if (p.X == i->X&&p.Y == i->Y)
		{
			return &*i;
		}
	}
	return NULL;
}

list<Point1> CFindPath::GetSurroundPoint(Point1 &p, bool isAngle)//��ȡ��Χ�ɵ�����;
{
	list<Point1> temPoints;

	for (int i = p.X - 1; i <= (p.X + 1 >= ROW ? p.X : p.X + 1); i++)
		for (int j = p.Y - 1; j <= (p.Y + 1 >= COL ? p.Y : p.Y + 1); j++)
		{
			if (IsCanReach(p, i, j, isAngle))
			{

				Point1 mPoint(i, j);
				temPoints.push_back(mPoint);
			}
		}
	return temPoints;
}
Point1 *CFindPath::FindColseListPoint(Point1 p)
{

	list<Point1>::iterator i;
	for (i = colseList.begin(); i != colseList.end(); i++)
	{
		if (p.X == i->X&&p.Y == i->Y)
		{
			return &*i;
		}
	}
	return NULL;
}

bool CFindPath::IsCanReach(Point1 start, int x, int y, bool isAngle)//�жϵ��Ƿ���Ե���
{
	Point1 point;
	point.X = x;
	point.Y = y;
	if (!IsCanReach(x, y) || FindColseListPoint(point))
	{
		return false;
	}
	else
	{
		if (abs(x - start.X) + abs(y - start.Y) == 1)
			return true;
		else
		{
			if (isAngle)//������Թս�ֱ�ӷ���
				return isAngle;

			//����Ϊ4�ֲ�ͬ�սǵ�����ж�                                  
			if (x < start.X&&y < start.Y)                                      //(����) 0 | 1     //���������λ����4�����������4�ֲ�ͬ�Ĺս�
			{                                                             //    -----|-----
				if (points[start.X][y] == 0 && points[x][start.Y] == 0)          //       1 | 0(���) 
					return true;                                          //
			}
			else if (x<start.X&&y>start.Y)
			{
				if (points[x][start.Y] == 0 && points[start.X][y] == 0)
					return true;
			}
			else if (x > start.X&&y < start.Y)
			{
				if (points[start.X][y] == 0 && points[x][start.Y] == 0)
					return true;
			}
			else if (x > start.X&&y > start.Y)
			{
				if (points[x][start.Y] == 0 && points[start.X][y] == 0)
					return true;
			}
			//return false;

		}
	}
}

bool CFindPath::IsCanReach(int x, int y)//�жϵ��Ƿ����ͨ��
{
	return  points[x][y] == 0;
}


void Astar(int start_x, int start_y, int end_x, int end_y)
{
	
	ifstream infile;//�����ȡ�ļ���������ڳ�����˵��in
	infile.open(FILENAME);//���ļ�
	//int* ptr = &data[0][0];//����
	for (int i = 0; i < ROW; i++)//������ѭ��
	{
		for (int j = 0; j < COL; j++)//������ѭ��
		{
			infile >> mapp[i][j];//��ȡһ��ֵ���ո��Ʊ�������и�������д�뵽�����У����в���ѭ������
			//infile >> *ptr;
			if (mapp[i][j] == 0)
				mapp[i][j] = 1;
			else	mapp[i][j] = 0;
			//cout << map[i][j];

		}
	}
	infile.close();//��ȡ���֮��ر��ļ�

	CFindPath path(mapp);//��ʼ����ͼ;
	Point1 start(start_x, start_y);//���;
	Point1 end(end_x, end_y);//�յ�


	Point1 *point = new Point1();
	point = path.GetPath(start, end, false);
	if (point == NULL)
	{
		cout << "�޷������յ�!" << endl;
	}
	else
	{
		while (point != NULL)
		{
			//cout<<point->X<<","<<point->Y<<endl;
			mapp[point->X][point->Y] = 5;
			calcx1 = point->X;
			calcy1 = point->Y;
			point = point->parent;

			if (point != NULL)
			{
				calcx2 = point->X;
				calcy2 = point->Y;
				if (abs(calcx1 - calcx2) + abs(calcy1 - calcy2) == 1)
					len = len + 10;
				else
					len = len + 14;
			}
		}
	}

	//���ͼ��

	for (int i = 0; i < ROW; i++)//������ѭ��
	{
		for (int j = 0; j < COL; j++)//������ѭ��
		{
			if (mapp[i][j] != 1)
				cout << mapp[i][j];
			else
				cout << " ";
		}
		cout << endl;
	}
	cout << "total lenth is" << len << endl;
	delete point;
	point = NULL;
	//getchar();
	return;

}


#endif // !_ASTAR_H
