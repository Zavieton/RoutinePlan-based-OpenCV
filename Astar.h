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
int mapp[ROW][COL] = { 0 };//定义一个矩阵，用于存放数据

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
	Point1 *GetPath(Point1 start, Point1 end, bool isAngle);//获取路径链表;
	list<Point1> GetSurroundPoint(Point1 &, bool);//获取周围可到达的点;
	bool IsCanReach(int x, int y);//判断是否是墙壁;
	void ChangePoint(Point1 start, Point1 point);//改变已在开启列表的点;
	void AddPoint(Point1 start, Point1 end, Point1 point);//添加不在开启列表的点;
	int CalculateG(Point1, Point1);//计算G
	int CalculateH(Point1 end, Point1 point);//计算H
	bool IsCanReach(Point1 start, int x, int y, bool isAngle);//判断是否可到达;
	Point1 *FindOpenListPoint(Point1 p);
	Point1 *FindColseListPoint(Point1 p);
	Point1 *FPoint(Point1 p);
private:
	list<Point1> openList;//开启列表;
	list<Point1> colseList;//关闭列表;
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



Point1* CFindPath::GetPath(Point1 start, Point1 end, bool isAngle)//核心算法A*路径查找,isAngle表示是否可以越过拐角;
{
	openList.push_back(start);
	while (!openList.empty())
	{
		openList.sort();//根据F值由小到大排序;
		Point1 temp = openList.front();//取出F值最小的;
		colseList.push_back(temp);//加入到关闭列表;
		openList.pop_front();//开启列表中删除F值最小的;
		list<Point1> surroundPoints = GetSurroundPoint(temp, isAngle);//取出周围可到达的点;      
		while (!surroundPoints.empty())//对每个可到达的周围的点进行判断;
		{
			Point1 point = surroundPoints.front();
			if (FindOpenListPoint(point))//若开启列表中存在这个点;	
				ChangePoint(temp, point);//判断是否是最优路径如果是改变父结点若不是则什么也不做;		
			else
				AddPoint(temp, end, point);//若不在开启列表则加入;		
			surroundPoints.pop_front();
		}
		if (FindOpenListPoint(end))
			return FindOpenListPoint(end);
	}
	return FindOpenListPoint(end);
}



void CFindPath::ChangePoint(Point1 start, Point1 point)//改变点的父结点重新计算F值;
{

	int G = CalculateG(start, point);
	if (G < point.G)
	{
		point.parent = new Point1(start);
		point.G = G;
		point.CalcF();
	}
}

void CFindPath::AddPoint(Point1 start, Point1 end, Point1 point)//添加点到开启列表;
{
	point.parent = new Point1(start);
	point.G = CalculateG(start, point);
	point.H = CalculateH(end, point);
	point.CalcF();
	openList.push_back(point);
}

int  CFindPath::CalculateG(Point1 start, Point1 point)//计算G值
{

	int parentG = 0;
	int G = (abs(point.X - start.X) + abs(point.Y - start.Y)) != 2 ? STEP : ANGLE;
	if (point.parent)
		parentG = point.parent->G != 0 ? point.parent->G : 0;
	return G + parentG;

}

int  CFindPath::CalculateH(Point1 end, Point1 point)//计算H值;
{
	int step = abs(point.X - end.X) + abs(point.Y - end.Y);
	return step * STEP;

}

Point1* CFindPath::FindOpenListPoint(Point1 p)//查找点是否在开启列表中;
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

list<Point1> CFindPath::GetSurroundPoint(Point1 &p, bool isAngle)//获取周围可到达结点;
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

bool CFindPath::IsCanReach(Point1 start, int x, int y, bool isAngle)//判断点是否可以到达
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
			if (isAngle)//如果可以拐角直接返回
				return isAngle;

			//以下为4种不同拐角的情况判断                                  
			if (x < start.X&&y < start.Y)                                      //(到点) 0 | 1     //到点和起点的位置有4种情况所以有4种不同的拐角
			{                                                             //    -----|-----
				if (points[start.X][y] == 0 && points[x][start.Y] == 0)          //       1 | 0(起点) 
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

bool CFindPath::IsCanReach(int x, int y)//判断点是否可以通过
{
	return  points[x][y] == 0;
}


void Astar(int start_x, int start_y, int end_x, int end_y)
{
	
	ifstream infile;//定义读取文件流，相对于程序来说是in
	infile.open(FILENAME);//打开文件
	//int* ptr = &data[0][0];//定义
	for (int i = 0; i < ROW; i++)//定义行循环
	{
		for (int j = 0; j < COL; j++)//定义列循环
		{
			infile >> mapp[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
			//infile >> *ptr;
			if (mapp[i][j] == 0)
				mapp[i][j] = 1;
			else	mapp[i][j] = 0;
			//cout << map[i][j];

		}
	}
	infile.close();//读取完成之后关闭文件

	CFindPath path(mapp);//初始化地图;
	Point1 start(start_x, start_y);//起点;
	Point1 end(end_x, end_y);//终点


	Point1 *point = new Point1();
	point = path.GetPath(start, end, false);
	if (point == NULL)
	{
		cout << "无法到达终点!" << endl;
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

	//输出图像

	for (int i = 0; i < ROW; i++)//定义行循环
	{
		for (int j = 0; j < COL; j++)//定义列循环
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
