#ifndef LAPLACIANZC_H
#define LAPLACIANZC_H

#include "mainwindow.h"

class LaplacianZC
{
private:
    // original image
    cv::Mat img;
    // 32-bit float image containing the Laplacian
    cv::Mat laplace;
    // Aperture size of the laplacian kernel
    int aperture;

public:


    LaplacianZC() : aperture(3) {}
    // Set the aperture size of the kernel
    void setAperture(int a) {
        aperture= a;
    }
    cv::Mat computeLaplacian(const cv::Mat& image);
    cv::Mat getLaplacianImage(double scale=-1.0);


};

#endif // LAPLACIANZC_H
