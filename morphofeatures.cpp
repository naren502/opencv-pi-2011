#include "morphofeatures.h"
#include "mainwindow.h"

MorphoFeatures::MorphoFeatures()
{
}

cv::Mat MorphoFeatures::getEdges(const cv::Mat &image) {
    // Get the gradient image
    cv::Mat result;
    cv::morphologyEx(image,result,
                     cv::MORPH_GRADIENT,cv::Mat());
    // Apply threshold to obtain a binary image
    applyThreshold(result);
    return result;
}

void MorphoFeatures::applyThreshold(cv::Mat &result) {
    // Apply threshold on result
    if (threshold>0)
        cv::threshold(result, result,
                      threshold, 255, cv::THRESH_BINARY);
}
