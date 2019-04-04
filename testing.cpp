#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::FileStorage fs ("config/VehicleCount.xml", cv::FileStorage::WRITE);

    fs << "Test1" << 5;
    fs << "Test2" << 6;
    fs << "Test3" << 3;

    fs.release();
}
