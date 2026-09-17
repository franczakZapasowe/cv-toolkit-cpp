#include <iostream>
#include <MyColorPicker.hpp>
#include <opencv2/opencv.hpp>

using namespace MyTools;
int main() {

    // std::string path = "/home/mf/C++/OPENCV/Resources/lambo.png";
    // cv::Mat img = cv::imread(path);
    // if (img.empty()) {
    //     std::cerr<<"Failed to load image"<<std::endl;
    //     return -1;
    // }
    //
    // MyTools::HSVRange hsvRange;
    // hsvRange = MyTools::showColorPicker(img);
    //
    // cv::Mat imgHSV, mask;
    // cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);
    // cv::Scalar lower (hsvRange.hmin,hsvRange.smin,hsvRange.vmin);
    // cv::Scalar upper (hsvRange.hmax,hsvRange.smax,hsvRange.vmax);
    // cv::inRange(imgHSV, lower, upper, mask);
    //
    // cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
    // cv::Mat maskDilated;
    // dilate(mask, maskDilated, kernel);
    //
    // imshow("Oryginalna Maska", mask);
    // imshow("Maska po Dylatacji (Pogrubiona)", maskDilated);
    //
    // cv::waitKey(0);

    std::string path = "/home/mf/MyOpenCVTools/randomgeometric.jpg";
    cv::Mat img = cv::imread(path);
    if (img.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    detectAllShapes(img);
    cv::imshow("img",img);
    cv::waitKey(0);
    return 0;
}