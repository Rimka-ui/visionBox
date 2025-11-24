QPixmap MainWindow::CvMatToQPixmap(Mat matimage)

{
    if(matimage.type()==CV_8UC4)//32 bit depht image
    {
        QImage image(matimage.data, //image DATA
                     matimage.cols, //image width
                     matimage.rows, //image heigth
                     static_cast<int>(matimage.step), //image matrix element type
                     QImage::Format_RGBA8888); // image pixel format

        return QPixmap::fromImage(image.rgbSwapped());
    }
    else if(matimage.type()==CV_8UC3)//24
    {
        QImage image(matimage.data, //image DATA
                     matimage.cols, //image width
                     matimage.rows, //image heigth
                     static_cast<int>(matimage.step), //image matrix element type
                     QImage::Format_RGB888); // image pixel format
        return QPixmap::fromImage(image.rgbSwapped());
    }
    else if(matimage.type()==CV_8UC1)//8
    {
        QImage image(matimage.data, //image DATA
                     matimage.cols, //image width
                     matimage.rows, //image heigth
                     static_cast<int>(matimage.step), //image matrix element type
                     QImage::Format_Grayscale8); // image pixel format
        return QPixmap::fromImage(image);
    }
     return QPixmap();
}

void MainWindow::onSliderValueChanged_1(int value)
{
    cv::Mat blurImg;
    blur(originalImage, blurImg, Size(5,5));

    cv::Mat edges;
    int low = value;
    int high = value * 3;  // le bon ratio !
    if (high < low) high = low + 1;
    Canny(blurImg, edges, low, high);

    QPixmap px = CvMatToQPixmap(edges);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label_contour->setPixmap(px.scaled(w, h, Qt::KeepAspectRatio));
}
