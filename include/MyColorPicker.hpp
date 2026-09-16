#pragma once
#include <opencv2/opencv.hpp>

namespace MyTools {
    struct HSVRange {
        int hmin, hmax, smin, smax, vmin, vmax;
    };

    HSVRange showColorPicker(const cv::Mat& img);
}
