//图像模糊1
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src;
	char a1[] = "input";
	char a2[] = "blur";
	char a3[] = "gaussian";
	src = imread("F:/image/1.7.png");
	if (!src.data)
	{
		printf("can not find the picture");
		return -1;
	}

	namedWindow(a1,WINDOW_AUTOSIZE);
	imshow(a1,src);

	Mat dst = Mat::zeros(src.size(),src.type());
	Mat dst1 = Mat::zeros(src.size(), src.type());
	blur(src,dst,Size(1,15),Point(-1,-1));//Size大写（）括号里面要奇数，
	GaussianBlur(src,dst1,Size(3,3),30,30);
	imshow(a2, dst);
	imshow(a3, dst1);
	waitKey(0);
	return 0;
}