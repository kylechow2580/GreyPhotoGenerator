#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
using namespace cv;

int main(){
    string folderName = "Input/";
    cout << "Num of photo: "; 
    int num;
    cin >> num;

    cout << "Output format: ";
    string format;
    cin >> format;

    for(int i=1;i<=num;i++)
    {
        stringstream ss;
        ss << folderName << i << ".jpg";
        string filename = ss.str();
        Mat image = imread(filename);

        Mat gray_image;
        cvtColor( image, gray_image, CV_BGR2GRAY);


        imshow("Image",image);

        stringstream outputss;
        outputss << "Output/" << i << format;
        string outputfilename = outputss.str();
        imwrite(outputfilename,gray_image);
    }
    cout << "All files converted completely" << endl;
}
