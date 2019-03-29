#include "VehicleCount.h"

namespace VC {
     cv::Mat img_input1;
     cv::Mat img_input2;

     int roi_x0 = 0;
     int roi_y0 = 0;
     int roi_x1 = 0;
     int roi_y1 = 0;

     int numOfRec = 0;
     int startDraw = 0;
}

VehicleCount::VehicleCount(): key(0), showAB(0), countAB(0), countBA(0),
                              firstTime(true), showOutput(true)
{
     std::cout << "VehicleCount()" << std::endl;
}

VehicleCount::~VehicleCount() {
     std::cout << "VehicleCount()" << std::endl;
}

void VehicleCount::setInput(const cv::Mat &i) {
     img_input = i;
}

/*
void VehicleCount::setTrack(const cvb::CvTracks &t) {

}
*/

VehiclePosition VehicleCount::getVehiclePosition(const cv::Point2d centroid) {

}
