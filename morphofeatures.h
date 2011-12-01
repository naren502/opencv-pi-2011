#ifndef MORPHOFEATURES_H
#define MORPHOFEATURES_H
#include "mainwindow.h"
class MorphoFeatures
{
private:
// threshold to produce binary image
int threshold;
// structuring elements used in corner detection
cv::Mat cross;
cv::Mat diamond;
cv::Mat square;
cv::Mat x;

public:
    MorphoFeatures();
    void setThreshold(int a) {
        threshold= a;
    }
    void applyThreshold(cv::Mat &result);
    cv::Mat getEdges(const cv::Mat &image);
};

#endif // MORPHOFEATURES_H
