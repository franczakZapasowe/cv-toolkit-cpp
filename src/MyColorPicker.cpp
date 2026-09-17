#include "MyColorPicker.hpp"

static cv::Mat prepareContour(const cv::Mat &img) {
    cv::Mat imgGray, imgBlur, imgCanny, kernel, imgDil;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(imgGray, imgBlur, cv::Size(7,7), 5,0);
    cv::Canny(imgBlur, imgCanny, 25,75);
    kernel = cv::getStructuringElement(cv::MORPH_RECT,cv::Size(5,5));
    cv::dilate(imgCanny, imgDil,kernel);
    return imgDil;
}


namespace MyTools {
    HSVRange showColorPicker(cv::Mat& img) {
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

    void detectAllShapes(cv::Mat & img) {
        cv::Mat imgDil = prepareContour(img);
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;

        cv::findContours(imgDil,contours,hierarchy, cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);

        std::vector<std::vector<cv::Point>> conPoly(contours.size());
        std::vector<cv::Rect> boundRect(contours.size());
        std::string shape;


        for (int i = 0; i < contours.size(); i++) {
            int area = cv::contourArea(contours[i]); //liczymy ile pikseli
            if (area>1000) {
                float circuit = arcLength(contours[i],true); // liczymy obwod figury
                cv::approxPolyDP(contours[i],conPoly[i],0.02*circuit,true);
                boundRect[i] = cv::boundingRect(conPoly[i]);
                int numCorners = static_cast<int>(conPoly[i].size());
                if (numCorners == 3) shape = "Triangle";
                else if (numCorners == 4) {
                    float ratio = static_cast<float>(boundRect[i].width)/static_cast<float>(boundRect[i].height);
                    if (ratio >= 0.95 && ratio <= 1.05) shape = "Square";
                    else shape = "Rectangle";
                }
                else if (numCorners == 5) shape = "Pentagon";
                else if (numCorners == 6) shape = "Hexagon";
                else if (numCorners > 6) shape = "Circle";

                cv::rectangle(img,boundRect[i].tl(),boundRect[i].br(),cv::Scalar(0,255,0),5);
                cv::putText(img, shape, {boundRect[i].x, boundRect[i].y-5 },cv::FONT_HERSHEY_PLAIN, 0.75, cv::Scalar(0,69,255),1.5);
                cv::drawContours(img,conPoly,i,cv::Scalar(255,0,255),5);
            }
        }
    }
}
