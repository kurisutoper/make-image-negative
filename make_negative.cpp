#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    if(argc <= 2) {
        cout << "usage: command [source] [destination]\nExiting...\n";
    }
    else {
        Mat original = imread(argv[1], CV_LOAD_IMAGE_COLOR);

        int nRows = original.rows,
            nCols = original.cols;

        if(original.isContinuous()) {
            nCols *= nRows;
            nRows = 1;
        }

        for(int i = 0; i < nRows; ++i) {
            uchar *p = original.ptr<uchar>(i);
            for(int j = 0; j < 3*nCols; j += 3) {
                p[j] = 255-p[j];
                p[j+1] = 255-p[j+1];
                p[j+2] = 255-p[j+2];
            }
        }

        imwrite(argv[2], original);
    }

    return 0;
}
