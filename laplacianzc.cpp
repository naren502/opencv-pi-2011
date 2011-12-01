#include "laplacianzc.h"



cv::Mat LaplacianZC::computeLaplacian(const cv::Mat& image) {
    // Compute Laplacian
    cv::Laplacian(image,laplace,CV_32F,aperture);
    // Keep local copy of the image
    // (used for zero-crossings)
    img= image.clone();
    return laplace;
}

// Get the Laplacian result in 8-bit image
// zero corresponds to gray level 128
// if no scale is provided, then the max value will be
// scaled to intensity 255
// You must call computeLaplacian before calling this
cv::Mat LaplacianZC::getLaplacianImage(double scale) {
    if (scale<0) {
        double lapmin, lapmax;
        cv::minMaxLoc(laplace,&lapmin,&lapmax);
        scale= 127/ std::max(-lapmin,lapmax);
    }
    cv::Mat laplaceImage;
    laplace.convertTo(laplaceImage,CV_8U,scale,128);
    return laplaceImage;
}

