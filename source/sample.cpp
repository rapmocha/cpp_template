// Copyright 2016 rapmocha

#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>


void hello_world() {
    using std::cout;
    using std::endl;
    const std::string INFILE = "resources/gazelle.jpg";

    cout << "OpenCV version: " << CV_VERSION << endl;

    // C++11 test
    std::vector<int> v = {0, 2, 1, 5};
    for (auto &infile : v) cout << infile << " ";
    cout << endl;

    // OpenCV test
    cv::Mat img = cv::imread(INFILE, CV_LOAD_IMAGE_COLOR);
    cv::namedWindow("OpenCV test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV test", img);
    cv::waitKey(0);

    cout << "Goodbye World!" << endl;
    return;
}
