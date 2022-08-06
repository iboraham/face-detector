
vector<Rect> faceDetector(Mat &img)
{
    CascadeClassifier face_cascade;
    if (!face_cascade.load("./data/haarcascade_frontalface_alt.xml"))
    {
        throw(runtime_error("Error loading face cascade"));
    }
    vector<Rect> faces;
    face_cascade.detectMultiScale(img, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    if (faces.size() == 0)
    {
        throw(runtime_error("No faces detected"));
    }
    else
    {
        return faces;
    }
}