#include <cstring>
#include <exception>
#include <iostream>
#include <memory>

#include "opencv2/opencv.hpp"


#include <kos_net.h>

#include "general.h"
#include "publisher.h"

namespace consts {
constexpr int PublicationIntervalInSec = 5;
} // namespace consts

const char* GetBrokerAddress()
{
    const char* brokerAddress = getenv("MQTT_BROKER_ADDRESS");
    if (brokerAddress)
    {
        return brokerAddress;
    }
    throw std::runtime_error{"Failed to get MQTT broker address."};
}

int GetBrokerPort()
{
    if (auto brokerPortEnvVariable = getenv("MQTT_BROKER_PORT"))
    {
        try
        {
            return std::stoi(brokerPortEnvVariable);
        }
        catch (const std::logic_error&)
        {}
    }
    throw std::runtime_error{"Failed to get MQTT broker port."};
}


using namespace cv;
 
int camera(){
 
  cv::VideoCapture cap;
 
  // Check if camera opened successfully
  while(1) {
    cap.open("rtsp://USER:PASSWORD@10.0.2.11:554/cam1");

    if(!cap.isOpened()){
      std::cerr << "Error opening video stream or file" << std::endl;
      sleep(1);
      continue;
    }

    std::cerr << "Stream open OK" << std::endl;
    break;
  }

  int i =0;
  while(1){ 
    cv::Mat frame;
    // Capture frame-by-frame

    cap >> frame;

    // If the frame is empty, try next
    if (frame.empty())
      continue;
 
    std::cerr << "frame number" << i++ << std::endl;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
  return 0;
}



int main(void) try
{
    if (!wait_for_network())
    {
        throw std::runtime_error{"Error: Wait for network failed!"};
    }

    camera();

#if 0
    mosqpp::lib_init();
    auto pub = std::make_unique<Publisher>("publisher", GetBrokerAddress(), GetBrokerPort());
    while (true)
    {
        sleep(consts::PublicationIntervalInSec);
        pub->send_time();
    }

    mosqpp::lib_cleanup();
#endif

    return EXIT_SUCCESS;
}
catch (const std::exception& exc)
{
    std::cerr << app::AppTag << exc.what() << std::endl;
    return EXIT_FAILURE;
}
