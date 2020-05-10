#include "load.h"
#include "ui_load.h"
#include "mainwindow.h"
#include "QDebug"
#include <QGraphicsScene>
#include<QGraphicsView>                   //graphicsview类
#include <qfiledialog.h>                //getopenfilename 类申明
#include <qlabel.h>                     //label类
#include "head.h"
#include "queue.h"
#include "Astar.h"
#include "iostream"

using namespace std;



Load::Load(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load)
{
    ui->setupUi(this);
}

Load::~Load()
{
    delete ui;
}



void Load::on_pushButton_2_clicked()
{
    this->close();
}

void Load::on_pushButton_clicked()
{
	clock_t startTime, endTime;
	startTime = clock();//计时开始
	Mat origin_Image = imread("hit_map_2.jpg"); //读取图片

	/*namedWindow("origin", WINDOW_FREERATIO);
	imshow("origin", origin_Image);*/

	cout << "原图像：" << endl;
	cout << "row=" << origin_Image.rows << endl;
	cout << "col=" << origin_Image.cols << endl;
	cout << "正在解算原始目标点坐标......" << endl;

	if (!origin_Image.data)
	{
		cout << "Reading ERROR!" << endl;
		return ;
	}
	blur(origin_Image, origin_Image, Size(10, 10));//滤波处理

	//像素处理
	Mat dst;
	cvtColor(origin_Image, dst, COLOR_BGR2GRAY);
	int height = origin_Image.rows;
	int width = origin_Image.cols;
	int channels = origin_Image.channels();
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (channels == 3)
			{
				if (origin_Image.at<Vec3b>(row, col)[0] < 80 && origin_Image.at<Vec3b>(row, col)[1] > 180 && origin_Image.at<Vec3b>(row, col)[2] > 180)
				{
					origin_Image.at<Vec3b>(row, col)[0] = 0;
					origin_Image.at<Vec3b>(row, col)[1] = 0;
					origin_Image.at<Vec3b>(row, col)[2] = 0;
				}

				if (origin_Image.at<Vec3b>(row, col)[0] < 130 && origin_Image.at<Vec3b>(row, col)[1] < 120 && origin_Image.at<Vec3b>(row, col)[2]>140)
				{
					origin_Image.at<Vec3b>(row, col)[0] = 255;
					origin_Image.at<Vec3b>(row, col)[1] = 255;
					origin_Image.at<Vec3b>(row, col)[2] = 255;
				}

				if ((origin_Image.at<Vec3b>(row, col)[0] < 255 && origin_Image.at<Vec3b>(row, col)[0] > 0) ||
					(origin_Image.at<Vec3b>(row, col)[1] < 255 && origin_Image.at<Vec3b>(row, col)[1] > 0) ||
					(origin_Image.at<Vec3b>(row, col)[2] < 255 && origin_Image.at<Vec3b>(row, col)[2] > 0))
				{
					origin_Image.at<Vec3b>(row, col)[0] = 123;
					origin_Image.at<Vec3b>(row, col)[1] = 123;
					origin_Image.at<Vec3b>(row, col)[2] = 123;
				}
			}
		}
	}

	//镜像处理后的图片
	Mat src = origin_Image;
	Mat img, change_src;
	if (!src.data)
	{
		cout << "ERROR : could not load image.";
		return;
	}

	//转化边缘检测后的图为灰度图
	cvtColor(src, change_src, COLOR_BGR2GRAY);
	//Guass滤波
	GaussianBlur(change_src, change_src, Size(9, 9), 2, 2);
	//霍夫圆变换 输出img
	vector<Vec3f> pcircles;
	HoughCircles(change_src, pcircles, HOUGH_GRADIENT, 1, 10, 2, 25, 1, 40);
	src.copyTo(img);
	cout << "目标点数目 ： " << pcircles.size() << endl;
	PQUEUE pS1 = create_queue();//创建空队列pS1
	PQUEUE pS2 = create_queue();//创建空队列pS2
	//将圆画在原图片上。
	for (int i = 0; i < pcircles.size(); i++)
	{
		Vec3f cc = pcircles[i];
		circle(img, Point(cc[0], cc[1]), cc[2], Scalar(0, 0, 255), 2, LINE_AA);
		circle(img, Point(cc[0], cc[1]), 2, Scalar(255, 0, 4), 2, LINE_AA);
		en_queue(pS1, cc[0]);
		en_queue(pS2, cc[1]);
	}
	empty(pS1);
	empty(pS2);
	int* circle_x = traverse_queue_return(pS1, pcircles.size()); //导出储存有x坐标的队列
	int* circle_y = traverse_queue_return(pS2, pcircles.size()); //导出储存有y坐标的队列
	cout << "目标点坐标：" << endl;
	for (int i = 0; i < pcircles.size(); i++) {
		cout << "(" << circle_x[i] << "," << circle_y[i] << ")" << endl;
	}
	destroy_queue(pS1);  //销毁pS1
	destroy_queue(pS2);  //销毁pS2

	//对图像黑白化 输出BW
	cout << "图像二值化处理......" << endl;
	cout << endl;

	Mat BW = origin_Image;
	int BWheight = BW.rows;
	int BWwidth = BW.cols;
	int BWchannels = BW.channels();
	for (int row = 0; row < BWheight; row++)
	{
		for (int col = 0; col < BWwidth; col++)
		{
			if (BWchannels == 3)
			{
				if (origin_Image.at<Vec3b>(row, col)[0] == 255 && origin_Image.at<Vec3b>(row, col)[1] == 255 && origin_Image.at<Vec3b>(row, col)[2] == 255)
				{
					BW.at<Vec3b>(row, col)[0] = 255;
					BW.at<Vec3b>(row, col)[1] = 255;
					BW.at<Vec3b>(row, col)[2] = 255;
				}
				if (origin_Image.at<Vec3b>(row, col)[0] == 0 && origin_Image.at<Vec3b>(row, col)[1] == 0 && origin_Image.at<Vec3b>(row, col)[2] == 0)
				{
					BW.at<Vec3b>(row, col)[0] = 255;
					BW.at<Vec3b>(row, col)[1] = 255;
					BW.at<Vec3b>(row, col)[2] = 255;
				}
				if (origin_Image.at<Vec3b>(row, col)[0] > 50 && origin_Image.at<Vec3b>(row, col)[1] < 250 && origin_Image.at<Vec3b>(row, col)[2] >50)
				{
					BW.at<Vec3b>(row, col)[0] = 0;
					BW.at<Vec3b>(row, col)[1] = 0;
					BW.at<Vec3b>(row, col)[2] = 0;
				}
			}
		}
	}
	Mat size = BW;
	Mat Tem;
	cout << "图像压缩......" << endl;
	cout << endl;
	cout << RATE << endl;
	cout << endl;

	cv::resize(size, Tem, Size(), RATE, RATE); //图像压缩
	cout << " 压缩后图片的长：" << Tem.rows << endl;
	cout << " 压缩后图片的宽：" << Tem.cols << endl;
	cout << endl;

	for (int i = 0; i < 12; i++) {
		circle_x_change[i] = int(circle_x[i] * RATE);
		circle_y_change[i] = int(circle_y[i] * RATE);
	}
	cout << "压缩后目标点坐标" << endl;
	for (int i = 0; i < pcircles.size(); i++) {
		cout << "(" << circle_x_change[i] << "," << circle_y_change[i] << ")" << endl;
	}
	imwrite("black.jpg", Tem);
	cout << "正在生成单通道矩阵......" << endl;
	cout << endl;
	//单通道输出txt
	mat_CV_8UC1 = imread("black.jpg", IMREAD_GRAYSCALE); //载入灰度图 
	ofstream File4(FILENAME, ios::out | ios::binary);
	ofstream File3("file2.txt", ios::out | ios::binary);

	for (unsigned int row = 0; row < mat_CV_8UC1.rows; ++row)
	{
		uchar* ptr = mat_CV_8UC1.ptr<uchar>(row);
		for (unsigned int col = 0; col < mat_CV_8UC1.cols; ++col)
		{
			W2B[col][row] = (int(ptr[col]) > 50 ? 1 : 0);
			File4 << (int(ptr[col]) > 50 ? 1 : 0) << " ";
			File3 << (int(ptr[col]) > 50 ? 1 : 0);

		}
		File4 << endl;
	}

	cout << endl;

	//读取生成文件
	int data1[r][c] = { 0 };
	ifstream infile;//定义读取文件流，相对于程序来说是in
	infile.open(FILENAME);//打开文件
	ofstream File2("验证.txt", ios::out | ios::binary);
	for (int i = 0; i < r; i++)//定义行循环
	{
		for (int j = 0; j < c; j++)//定义列循环
		{

			infile >> data1[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
			File2 << data1[i][j];
		}
		cout << endl;
	}
	QString II = this->ui->comboBox_2->currentText();
	QString JJ = this->ui->comboBox->currentText();

	int ii = II.toInt();
	int jj = JJ.toInt();
	ii -= 1;
	jj -= 1;

	Astar(circle_y_change[ii], circle_x_change[ii], circle_y_change[jj], circle_x_change[jj]);

	int len_changed;

	len_changed = len * (95.67 / 286);

	len = 0;
	QString Lens = QString::number(len_changed);

	this->ui->Line_RouteLength->setText(Lens+"m");

	//Map_ori
	Mat Map_show = imread("tu.jpg");

	for (int row = 0; row < Tem.rows; row++)
	{
		for (int col = 0; col < Tem.cols; col++)
		{
			if (mapp[row][col] == 5) {

				int row2 = int(row * 600 / Tem.rows);
				int col2 = int(col * 500 / Tem.cols);
				circle(Map_show, Point(col2, row2), 2, Scalar(255, 0, 0), 2, LINE_AA);

			}
		}
	}

	cv::Mat Rgb;
	QImage Img1;
	if (Map_show.channels() == 3)//RGB Img

	{
		cvtColor(Map_show, Rgb, COLOR_BGR2RGB);//颜色空间转换
		Img1 = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		Img1 = QImage((const uchar*)(Map_show.data), Map_show.cols, Map_show.rows, Map_show.cols * Map_show.channels(), QImage::Format_Indexed8);
	}
	this->ui->label_3->setPixmap(QPixmap::fromImage(Img1));

	endTime = clock();//计时结束
	qDebug() << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return;
}


void Load::on_Mapshow_clicked()
{
	Mat Map_ori = imread("tu.jpg");
	this->ui->label_3->clear();
	cv::Mat Rgb2;
	QImage Img2;
	if (Map_ori.channels() == 3)//RGB Img

	{
		cvtColor(Map_ori, Rgb2, COLOR_BGR2RGB);//颜色空间转换
		Img2 = QImage((const uchar*)(Rgb2.data), Rgb2.cols, Rgb2.rows, Rgb2.cols * Rgb2.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		Img2 = QImage((const uchar*)(Map_ori.data), Map_ori.cols, Map_ori.rows, Map_ori.cols * Map_ori.channels(), QImage::Format_Indexed8);
	}
	this->ui->label_3->setPixmap(QPixmap::fromImage(Img2));
}

void Load::on_Routeclc_clicked()
{
	this->ui->Line_RouteLength->clear();
	this->ui->label_3->clear();
	on_Mapshow_clicked();
}
