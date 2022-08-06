#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <stdexcept>

using namespace cv;
using namespace std;

#include "detector.hpp"
vector<Rect> faceDetector(Mat &img);

int main(int argc, char **argv)
{
    string filename;
    Mat img;
    // Read image from given file
    if (argc < 2)
    {
        img = imread("docs/Lenna.png", IMREAD_COLOR);
        filename = "docs/Lenna.png";
    }
    else
    {
        img = imread(argv[1], IMREAD_COLOR);
        filename = argv[1];
    }
    if (!img.data)
    {
        printf("No image data \n");
        return -1;
    }
    // Find faces in image
    vector<Rect> faces = faceDetector(img);
    printf("%ld faces detected\n", faces.size());
    for (int i = 0; i < faces.size(); i++)
    {
        printf("Face %d: x = %d, y = %d, width = %d, height = %d\n", i, faces[i].x, faces[i].y, faces[i].width, faces[i].height);
        // Draw a rectangle around each face
        rectangle(img, faces[i], Scalar(0, 255, 0), 2, 8, 0);
    }
    // Save image with faces detected
    imwrite(filename + ".faces.png", img);
    return 0;
}
