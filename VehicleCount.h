// Coded By Clifton Rawlings
// March 28, 2019
// Inspired by

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

enum LaneOrientation {
    LO_NONE          = 0,
    LO_HORIZONTAL    = 1,
    LO_VERTIAL       = 2
};

enum VehiclePosition {
    VP_NONE = 0,
    VP_A    = 1,
    VP_B    = 2
};

class VehicleCount {
private:
    cv::Mat img_in;
    LaneOrientation laneOrientaiton;
    int key;
    int img_width;
    int img_height;
    int showAB;
    long countAB;
    long countBA;
    bool firstTime;
    bool displayOut;

};
