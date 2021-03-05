//图像模糊1(中值滤波+双边滤波)
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat src;
	char a1[] = "input";
	char a2[] = "medianBlur";
	char a3[] = "bilateralFilter";
	char a4[] = "bilateralFilter+filter";
	src = imread("F:/image/1.2.png");
	if (!src.data)
	{
		printf("can not find the picture");
		return -1;
	}

	namedWindow(a1, WINDOW_AUTOSIZE);
	imshow(a1, src);
	Mat dst = Mat::zeros(src.size(), src.type());
	Mat dst1 = Mat::zeros(src.size(), src.type());
	Mat dst2 = Mat::zeros(src.size(), src.type());
	medianBlur(src, dst, 9);
	bilateralFilter(src, dst1, 30, 150, 3);
	Mat kernel = (Mat_<char>(3,3)<<0,-1,0,-1,5,-1,0,-1,0);
	filter2D(dst1, dst2, -1, kernel);
	namedWindow(a2, WINDOW_AUTOSIZE);
	imshow(a2, dst);
	namedWindow(a3, WINDOW_AUTOSIZE);
	imshow(a3, dst1);
	namedWindow(a4, WINDOW_AUTOSIZE);
	imshow(a4, dst2);
	//Mat dst = Mat::zeros(src.size(), src.type());
	//Mat dst1 = Mat::zeros(src.size(), src.type());
	//blur(src, dst, Size(1, 15), Point(-1, -1));//Size大写（）括号里面要奇数，
	//GaussianBlur(src, dst1, Size(3, 3), 30, 30);
	//imshow(a2, dst);
	//imshow(a3, dst1);
	waitKey(0);
	return 0;
}