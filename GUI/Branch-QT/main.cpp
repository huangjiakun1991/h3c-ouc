#include <QtGui>
#include "Gh3c.h"

void center(QWidget &widget)
{
    int x, y;
    int screenWidth;
    int screenHeight;
    int height, width;
    QSize windowSize;

    QDesktopWidget *desktop = QApplication::desktop();

    width = widget.frameGeometry().width();
    height = widget.frameGeometry().height();

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    x = (screenWidth - width)/2;
    y = (screenHeight - height)/2;

    widget.move(x, y);
}

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	if(!QSystemTrayIcon::isSystemTrayAvailable()){
		QMessageBox::critical(0,QObject::tr("Systray"),QObject::tr("I couldn't detect any system tray on this system."));
		return 1; 
	}
	QApplication::setQuitOnLastWindowClosed(false);
	Gh3c H3C;
	H3C.show();
	center(H3C);

	return app.exec();
}
