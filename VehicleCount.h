// Coded By Clifton Rawlings
// March 28, 2019
// Inspired by Simple Vehicle Counter - GitHub #URL#

#pragma once

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

enum LaneOrientation {
    LO_NONE          = 0,
    LO_HORIZONTAL    = 1,
    LO_VERTICAL       = 2
};

enum VehiclePosition {
    VP_NONE = 0,
    VP_A    = 1,
    VP_B    = 2
};

class VehicleCount {
private:
    cv::Mat img_input;
    int key;
    int img_width;
    int img_height;
    int showAB;
    long countAB;
    long countBA;
    bool firstTime;
    bool showOutput;
    LaneOrientation laneOrientation;

    //cvb::CvTracks tracks;
    //std::map<cvb::CvID, std::vector<CvPoint2D64f> > points;
    //std::map<cvb::CvID, VehiclePosition> positions;

public:
     VehicleCount();
     ~VehicleCount();

     void setInput(const cv::Mat &i);
     //void setTrack(const cvb::CvTracks &t);
     void process();

private:
     VehiclePosition getVehiclePosition(const cv::Point2d centroid);
     void saveConfig();
     void loadConfig();
};
