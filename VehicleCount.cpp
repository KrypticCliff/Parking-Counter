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

/* MODIFY
void VehicleCount::setTrack(const cvb::CvTracks &t) {

}
*/

VehiclePosition VehicleCount::getVehiclePosition(const cv::Point2d centroid) {
     VehiclePosition vehiclePosition = VP_NONE;

     if (laneOrientation == LO_HORIZONTAL) {
          if (centroid.x < VC::roi_x0) {
               cv::putText(img_input, "STATE: A", cv::Point(10, img_height/2),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_A;
          }

          if (centroid.x > VC::roi_x0) {
               cv::putText(img_input, "STATE: B", cv::Point(10, img_height/2),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_B;
          }
     }

     if (laneOrientation == LO_VERTICAL) {
          if (centroid.y > VC::roi_y0) {
               cv::putText(img_input, "STATE: B", cv::Point(10, img_height/2),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_A;
          }

          if (centroid.y < VC::roi_y0) {
               cv::putText(img_input, "STATE: B", cv::Point(10, img_height/2),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_B;
          }
     }
     return vehiclePosition;
}

void VehicleCount::process() {
     
}
