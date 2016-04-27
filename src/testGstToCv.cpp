#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int, char**)
{
    cout << "OpenCV version : " << CV_VERSION << endl;
  cout << "Major version : " << CV_MAJOR_VERSION << endl;
  cout << "Minor version : " << CV_MINOR_VERSION << endl;
  cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;

    VideoCapture cap;
    int res = cap.open("tcpclientsrc host=172.24.1.1 port=5200 ! gdpdepay ! rtph264depay ! avdec_h264 ! videoconvert ! appsink", CAP_GSTREAMER); // open the default camera

    cout << "Camera open returns " << res << endl;    

    if (!cap.isOpened()) { // check if we succeeded
        cout << "Camera is not opened!" << endl;
        return -1;
    }

    namedWindow("PiCam",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("PiCam", frame);
        if(waitKey(5) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
