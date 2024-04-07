#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void findObjectContours(const Mat& inputImage, Mat& outputImage) 
{
    Mat gray, blurred, edges;
    cvtColor(inputImage, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, blurred, Size(5, 5), 0);
    Canny(blurred, edges, 30, 150);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(edges.clone(), contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours.size(); i++) 
    {
        drawContours(outputImage, contours, static_cast<int>(i), Scalar(0, 255, 0), 1);
    }
}

int main() 
{
    Mat image = imread("image1.jpg");
    Mat contour_image = Mat::zeros(image.size(), CV_8UC3);
    findObjectContours(image, contour_image);
    imshow("Object Contours", contour_image);
    waitKey(0);
    return 0;
}
