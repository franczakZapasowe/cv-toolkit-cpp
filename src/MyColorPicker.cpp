#include "MyColorPicker.hpp"

namespace MyTools {
    HSVRange showColorPicker(const cv::Mat& img) {
        int hmin = 0, hmax = 179, smin = 0, smax = 255, vmin = 0, vmax = 255;

        cv::Mat imgHSV, mask;
        cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

        cv::namedWindow("Trackbars", cv::WINDOW_AUTOSIZE);
        cv::createTrackbar("Hue Min", "Trackbars",&hmin,179);
        cv::createTrackbar("Hue Max", "Trackbars",&hmax,179);
        cv::createTrackbar("Sat Min", "Trackbars",&smin,255);
        cv::createTrackbar("Sat Max", "Trackbars",&smax,255);
        cv::createTrackbar("Val Min", "Trackbars",&vmin,255);
        cv::createTrackbar("Val Max", "Trackbars",&vmax,255);

        while (true) {

            cv::Scalar lower(hmin,smin,vmin);
            cv::Scalar upper(hmax,smax,vmax);

            cv::inRange(imgHSV,lower,upper,mask);

            cv::imshow("img", img);
            cv::imshow("imgHSV", imgHSV);
            cv::imshow("mask", mask);
            if (cv::waitKey(1) == 27) { break; }
        }
        cv::destroyAllWindows();
        return {hmin, hmax, smin, smax, vmin, vmax};
    }
}
