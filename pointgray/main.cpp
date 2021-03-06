#include "FlyCaptureWrapper.h"

int main() {
  FlyCameraWrapper cam;
  cam.init(14171090);  // serial

  cam.autoGain(true);
  cam.autoGain(false, 10.0);
  cam.autoBrightness(false, 0.0);
  cam.autoShutter(false, 50.0);
  cam.autoExposure(false, 2.0);
  cam.autoSaturation(false, 0.0);
  cam.autoGamma(false, 1.0);
  cam.setWhiteBalance(550, 750);

  cam.start();

  char key;
  do {
    cam.capture();
    cv::imshow("test", cam.img);
    key = cv::waitKey(1);
  } while (key == -1);

  return 0;
}
