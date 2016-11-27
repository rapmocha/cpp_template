// Copyright 2016 rapmocha

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <iostream>
#include <string>
#include <vector>

void cpp11_test();
void opencv_test();
void boost_test();


void hello_world() {
    cpp11_test();
    opencv_test();
    boost_test();
    std::cout << "Goodbye World!" << std::endl;
}


void cpp11_test() {
    // C++11 test
    using std::cout;
    using std::endl;
    std::vector<int> v = {0, 2, 1, 5};
    for (auto &infile : v) cout << infile << " ";
    cout << endl;
}


void opencv_test() {
    // OpenCV test
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    const std::string INFILE = "resources/gazelle.jpg";
    cv::Mat img = cv::imread(INFILE, CV_LOAD_IMAGE_COLOR);
    cv::namedWindow("OpenCV test", cv::WINDOW_AUTOSIZE);
    cv::imshow("OpenCV test", img);
    cv::waitKey(0);
}


void boost_test() {
    const boost::filesystem::path INDIR("resources");
    boost::filesystem::directory_iterator begin(INDIR);
    boost::filesystem::directory_iterator end;
    for (; begin != end; ++begin) {
        std::cout << *begin << std::endl;
    }
}

