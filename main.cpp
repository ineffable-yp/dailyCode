#include <iostream>
#include <opencv2/opencv.hpp>
#include "my_convolution.h"
 
using namespace std;
using namespace cv;
 
//高斯核构造函数
Mat Gaussian_kernal(int kernal_size, int sigma)
{
    const double PI = 3.14159265358979323846;
    int m = kernal_size / 2;
    Mat kernal(kernal_size, kernal_size, CV_32FC1);
    float s = 2 * sigma*sigma;
    for (int i = 0; i < kernal_size; i++)
    {
        for (int j = 0; j < kernal_size; j++)
        {
            int x = i - m, y=j - m;
            kernal.ptr<float>(i)[j] = exp(-(x*x + y*y) / s) / (PI*s);
        }
    }
    return kernal;
}
 
//3*3均值卷积核
cv::Mat average_kernal_3 = (Mat_<float>(3,3) << 0.111, 0.111 ,0.111,
                                                0.111, 0.111, 0.111,
                                                0.111, 0.111, 0.111);
 
//5*5均值卷积核
cv::Mat average_kernal_5 = (Mat_<float>(3,3) << 0.04, 0.04 ,0.04, 0.04, 0.04,
                                                0.04, 0.04 ,0.04, 0.04, 0.04,
                                                0.04, 0.04 ,0.04, 0.04, 0.04,
                                                0.04, 0.04 ,0.04, 0.04, 0.04,
                                                0.04, 0.04 ,0.04, 0.04, 0.04);
//sobel边缘检测算子
cv::Mat sobel_y_kernal= (Mat_<float>(3,3) << -1, -2 ,-1,
                                              0,  0 , 0,
                                              1,  2 , 1);
cv::Mat sobel_x_kernal= (Mat_<float>(3,3) << -1,  0 , 1,
                                             -2,  0 , 2,
                                             -1,  0 , 1);
 
//prewitt边缘检测算子
cv::Mat prewitt_y_kernal= (Mat_<float>(3,3) << -1, -1 ,-1,
                                                0,  0 , 0,
                                                1,  1 , 1);
cv::Mat prewitt_x_kernal= (Mat_<float>(3,3) << -1,  0 , 1,
                                               -1,  0 , 1,
                                               -1,  0 , 1);
 
int main(){
    My_Convolution myconvolution;   
    Mat image=imread("lena.jpg");
    imshow("src",image);
 
    Mat dst_prewitt;
    //高斯卷积
    Mat dst_gaussian;
    myconvolution.load_kernal(Gaussian_kernal(7,2));
    myconvolution.convolute(image,dst_gaussian);
 
    imshow("dst_gaussian",dst_gaussian);
    //均值3*3
    Mat dst_aver_3;
    myconvolution.load_kernal(average_kernal_3);
    myconvolution.convolute(image,dst_aver_3);
    imshow("dst_aver_3",dst_aver_3);
    //均值5*5
    Mat dst_aver_5;
    myconvolution.load_kernal(average_kernal_5);
    myconvolution.convolute(image,dst_aver_5);
    imshow("dst_aver_5",dst_aver_5);
    //sobel操作
    Mat dst_sobel_x;
    Mat dst_sobel_y;
 
    myconvolution.load_kernal(sobel_x_kernal);
    myconvolution.convolute(image,dst_sobel_x);
    imshow("dst_sobel_x",dst_sobel_x);
 
    myconvolution.load_kernal(sobel_y_kernal);
    myconvolution.convolute(image,dst_sobel_y);
    imshow("dst_sobel_y",dst_sobel_y);
 
    //prewitt操作
    Mat dst_prewitt_x;
    Mat dst_prewitt_y;
 
    myconvolution.load_kernal(prewitt_x_kernal);
    myconvolution.convolute(image,dst_prewitt_x);
    imshow("dst_prewitt_x",dst_prewitt_x);
 
    myconvolution.load_kernal(prewitt_y_kernal);
    myconvolution.convolute(image,dst_prewitt_y);
    imshow("dst_prewitt_y",dst_prewitt_y);
    waitKey(0);
    return 0;
}
 
 