#pragma once
#ifndef _HEAD_H
#define _HEAD_H


#include "iostream"
#include "ctime"
#include <fstream>  
#include <iterator>  
#include <vector> 
#include<typeinfo>
#include<stdio.h>
#include <cassert>
#include <opencv2\core\core.hpp>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

#define RATE 0.1
#define FILENAME "file.txt"
#define r 315
#define c 186
int circle_x_change[15], circle_y_change[15];
int W2B[500][500];
Mat mat_CV_8UC1;



#endif
