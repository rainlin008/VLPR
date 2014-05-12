#ifndef VLPR_H
#define VLPR_H

#include <QtGui/QMainWindow>
#include "ui_vlpr.h"
#include "utility.h"

class QAction;
class QMenu;
class QDesktopWidget;
class QWidget;
class QGroupBox;
class QGridLayout;
class QLabel;
class QTextEdit;
class QScrollArea;

class VLPR : public QMainWindow
{
	Q_OBJECT

public:

	VLPR(QWidget *parent = 0, Qt::WFlags flags = 0);
	~VLPR();
	void showImg(QLabel *label,QImage img);
	void createMenus();
	void createActions();
	void updateLog(QString text);

private:

	Ui::VLPRClass ui;
	cv::Mat image; //输入图片
	cv::Mat gray; //灰度图
	cv::Mat car; //车牌区域
	cv::Mat charOne; //省份字符
	cv::Mat charTwo; //地级市字符
	cv::Mat charThree; //牌照字符一
	cv::Mat charFour; //牌照字符二
	cv::Mat charFive; //牌照字符三
	cv::Mat charSix; //牌照字符四
	cv::Mat charSeven; //牌照字符五

	QAction *openAction;//打开图片
	QAction *quitAction;//退出系统
	QAction *grayAction;//灰度化
	QAction *imgAction;//查看原图
	QAction *blurAction;//平滑滤波
	QAction *edgeDetectAction;//边缘检测
	QAction *thresAction;//二值化
	QAction *morphologyAction;//数学形态学处理
	QAction *locateAction;//定位车牌

	QMenu *fileMenu;
	QMenu *preDeal;
	QMenu *locateMenu;
	QMenu *divMenu;
	QMenu *charRecoMenu;

	QWidget *cenWidget;

	QGroupBox *groupBox1;
	QScrollArea *scrollArea1;
	QLabel *label1;

	QGroupBox *groupBox2;
	QScrollArea *scrollArea2;
	QLabel *label2;

	QGroupBox *groupBox_char[7];
	QScrollArea *scrollArea_char[7];
	QLabel *label_char[7];

	QTextEdit *logEdit;
	QScrollArea *scrollArea3;

private slots:

	void on_OpenImage_clicked();
	void on_Gray_clicked();
	void on_Show_Image_clicked();
	void on_edgeDetect_clicked();
	void on_thres_clicked();
	void dilateErode();
	void on_blur_clicked();
	void on_locate_clicked();
};

#endif // VLPR_H
