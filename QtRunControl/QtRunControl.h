#pragma once

/*
* ·ÂÕæ¿ØÖÆGUI
* @date : 2018/10/13
* @author : jihang
*/

#include <QtWidgets/QMainWindow>
#include "ui_QtRunControl.h"
#include "HLAPortAdapter.h"

class QtRunControl : public QMainWindow {

	Q_OBJECT

public:
	QtRunControl(QWidget *parent = Q_NULLPTR);

public slots:
	void prepare();
	void ready();
	void run();
	void pause();
	void continuE();

private:
	Ui::QtRunControlClass ui;
	HLAPortAdapter *ha;
};