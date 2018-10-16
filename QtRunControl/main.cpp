#include "QtRunControl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	QtRunControl w;
	w.show();
	return a.exec();
}
