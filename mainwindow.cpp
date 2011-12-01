#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "laplacianzc.h"
#include "morphofeatures.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), ".",tr("Image Files (*.png *.jpg *.jpeg *.bmp)"));
    image= cv::imread(fileName.toAscii().data());
    thumb.create(600,300,CV_8UC(15));


    cv::resize(image,thumb,
               cv::Size(thumb.rows,thumb.cols));
    cv::cvtColor(thumb,thumb,CV_BGR2RGB);

    QImage img= QImage((const unsigned char*)(thumb.data),
                       thumb.cols,thumb.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
}



void MainWindow::on_pushButton_2_clicked()
{
    ui->label->clear();
    cv::blur(image,lowp,cv::Size(5,5));
    thumb.create(600,300,CV_8UC(15));
    cv::resize(lowp,thumb,
               cv::Size(thumb.rows,thumb.cols));
    cv::cvtColor(thumb,thumb,CV_BGR2RGB);

    QImage img= QImage((const unsigned char*)(thumb.data),
                       thumb.cols,thumb.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));


}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->clear();
    LaplacianZC laplacian;
    laplacian.setAperture(7);
    cv::Mat flap= laplacian.computeLaplacian(image);
    lowp= laplacian.getLaplacianImage();






    thumb.create(600,300,CV_8UC(15));
    cv::resize(lowp,thumb,
               cv::Size(thumb.rows,thumb.cols));
    cv::cvtColor(thumb,thumb,CV_BGR2RGB);

    QImage img= QImage((const unsigned char*)(thumb.data),
                       thumb.cols,thumb.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_clicked()
{
     ui->label->clear();
     MorphoFeatures morpho;
     morpho.setThreshold(40);
     // Get the edges
     lowp= morpho.getEdges(image);



     thumb.create(600,300,CV_8UC(15));
     cv::resize(lowp,thumb,
                cv::Size(thumb.rows,thumb.cols));
     cv::cvtColor(thumb,thumb,CV_BGR2RGB);

     QImage img= QImage((const unsigned char*)(thumb.data),
                        thumb.cols,thumb.rows,QImage::Format_RGB888);
     ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_pushButton_6_clicked()
{
    cv::Rect rectangle(15,50,380,300);

    cv::Mat result; // segmentation (4 possible values)
    cv::Mat bgModel,fgModel; // the models (internally used)
    // GrabCut segmentation
    cv::grabCut(image,
                // input image
                lowp,
                // segmentation result
                rectangle,
                // rectangle containing foreground
                bgModel,fgModel, // models
                5,
                // number of iterations
                cv::GC_INIT_WITH_RECT); // use rectangle
    // Get the pixels marked as likely foreground
    cv::compare(lowp,cv::GC_PR_FGD,lowp,cv::CMP_EQ);
    // Generate output image


    lowp= lowp&1; // will be 1 if FG

    cv::Mat foreground(image.size(),CV_8UC3,
    cv::Scalar(255,255,255)); // all white image
    image.copyTo(foreground,lowp); // bg pixels not copied

    thumb.create(600,300,CV_8UC(15));
    cv::resize(foreground,thumb,
               cv::Size(thumb.rows,thumb.cols));
    cv::cvtColor(thumb,thumb,CV_BGR2RGB);

    QImage img= QImage((const unsigned char*)(thumb.data),
                       thumb.cols,thumb.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::on_pushButton_7_clicked()
{   IplImage ipl_img = image;
    IplImage *iplimg = &ipl_img;
    cvSetImageROI(iplimg, cvRect(202, 20, 150, 250));
    cvNot(iplimg, iplimg);
    cvResetImageROI(iplimg);

    lowp=iplimg;

    thumb.create(600,300,CV_8UC(15));
    cv::resize(lowp,thumb,
               cv::Size(thumb.rows,thumb.cols));
    cv::cvtColor(thumb,thumb,CV_BGR2RGB);

    QImage img= QImage((const unsigned char*)(thumb.data),
                       thumb.cols,thumb.rows,QImage::Format_RGB888);
    ui->label->setPixmap(QPixmap::fromImage(img));

}
