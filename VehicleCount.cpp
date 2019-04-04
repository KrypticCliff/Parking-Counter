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
               cv::putText(img_input, "STATE: B", cv::Point(10, img_height-30),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_A;
          }

          if (centroid.y < VC::roi_y0) {
               cv::putText(img_input, "STATE: B", cv::Point(10, img_height-30),
                         cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255,255,255));
               vehiclePosition = VP_B;
          }
     }
     return vehiclePosition;
}

void VehicleCount::process() {
    if (img_input.empty())
        return;

    img_width   = img_input.size().width;
    img_height  = img_input.size().height;

    loadConfig();

    cv::line(img_input, cv::Point(VC::roi_x0, VC::roi_y0),
            cv::Point(VC::roi_x1, VC::roi_y1), cv::Scalar(0, 0, 255), 1);

    laneOrientation = LO_NONE;

    if (abs(VC::roi_x0 - VC::roi_x1) < abs(VC::roi_y0 - VC::roi_y1)) {
        laneOrientation = LO_VERTICAL;

        cv::putText(img_input, "(A)", cv::Point(VC::roi_x0-30, VC::roi_y0),
                cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
        cv::putText(img_input, "(B)", cv::Point(VC::roi_x0+10, VC::roi_y0),
                cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
    }

    if (abs(VC::roi_x0 - VC::roi_x1) > abs(VC::roi_y0 - VC::roi_y1)) {
        laneOrientation = LO_HORIZONTAL;

        cv::putText(img_input, "(A)", VC::Point(VC::roi_x0-15, VC::roi_y0+9),
                cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
        cv::putText(img_input, "(B)", VC::Point(VC::roi_x0-15, VC::roi_y0-9),
                cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
    }
}

void VehicleCount::saveConfig() {
    cv::FileStorage fs("config/VehicleCount.xml", cv::FileStorage::WRITE);
    fs << "showOutput"  << showOutput;
    fs << "showAB"      << showAB;
    fs << "vc_roi_x0"   << VC::roi_x0;
    fs << "vc_roi_y0"   << VC::roi_y0;
    fs << "vc_roi_x1"   << VC::roi_x1;
    fs << "vc_roi_y1"   << VC::roi_y1;
    fs.release();
}

void VehicleCount::loadConfig() {
    cv::FileStorage fs("config/VehicleCount.xml", cv::FileStorage::READ);
    showOutput  = (int)fs["showOutput"];
    showAB      = (int)fs["showAB"];
    VC::roi_x0  = (int)fs["vc_roi_x0"];
    VC::roi_y0  = (int)fs["vc_roi_y0"];
    VC::roi_x1  = (int)fs["vc_roi_x1"];
    VC::roi_y1  = (int)fs["vc_roi_y1"];
    fs.release();
}
