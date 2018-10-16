
/*
* ·ÂÕæ¿ØÖÆGUI
* @date : 2018/10/13
* @author : jihang
*/

#include <iostream>
#include <QTextStream> 

#include "QtRunControl.h"

#define READY_TO_RUN "ReadyToRun"

using namespace std;

QtRunControl::QtRunControl(QWidget *parent)
	: QMainWindow(parent) {
	ha = new HLAPortAdapter();
	ui.setupUi(this);
}

void QtRunControl::prepare() {
	QTextStream textStream(stdout);
	ha->createFederation(ha->fedFile, ha->federationName);
	ha->federateId = ha->joinFederation(ha->federateName, ha->federationName);
	ha->initial();
	ha->registerSynchronization(READY_TO_RUN);
	ui.textBrowser->append("prepared!");
}

void QtRunControl::ready() {
	ha->synchronizationAchieved(READY_TO_RUN);
	ha->enableTimePolicy(0.01);
	ha->pubAndSub();
	ha->rigister();
	ui.textBrowser->append("ready!");
}

void QtRunControl::run() {
	ha->simulate();
}

void QtRunControl::pause() {
}

void QtRunControl::continuE() {
}