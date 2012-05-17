#include <QtGui>
#include <iostream>
#include <string>
#include "Gh3c.h"

using namespace std;

Gh3c::Gh3c()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    createActions();
    createTrayIcon();
    createMenus();
    createStatusBar();
    QIcon icon1 = QIcon("discont.png");
    trayIcon->setIcon(icon1);
    trayIcon->setVisible(true);
    setWindowIcon(icon1);
    trayIcon->setToolTip("H3C");
    trayIcon->show();

    QCoreApplication::setOrganizationName("OUC");
    QCoreApplication::setApplicationName("H3C");
    QString UserName=NULL;
    QString PassWord=NULL;
    QTimer *timer = new QTimer(this);

    QLabel *nameLabel = new QLabel(tr("Username"));
    nameLine = new QLineEdit;
    nameLine->setReadOnly(false);

    QLabel *pswLabel = new QLabel(tr("Password"));
    pswLine = new QLineEdit;
    pswLine->setReadOnly(false);
    pswLine->setEchoMode(QLineEdit::Password);

    QLabel *deviceLabel = new QLabel(tr("Devicename"));
    devicels = new QComboBox;
    devicels->setEditable(false);
    devicels->insertItem(0, "eth0");
    devicels->insertItem(1, "lo");
    devicels->insertItem(2, "eth1");

    rm = new QCheckBox("Remember Password");
    rm->setCheckState(Qt::Unchecked);

    loadSettings();
    display = new QListWidget;
    display->addItem("The One.");

    connectButton = new QPushButton(tr("&Connect"));
    connectButton->setSizePolicy(QSizePolicy::Expanding,
		QSizePolicy::Expanding);
    discontButton = new QPushButton(tr("&Disconnect"));
    discontButton->setSizePolicy(QSizePolicy::Expanding,
		QSizePolicy::Expanding);
    InitButton();

    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
    connect(rm, SIGNAL(stateChanged(int)), this, SLOT(remember(int)));
    connect(connectButton, SIGNAL(clicked()), this, SLOT(login()));
    connect(discontButton, SIGNAL(clicked()), this, SLOT(disconnect()));
    connect(nameLine, SIGNAL(textChanged(const QString &)), this, SLOT(userchanged()));
    connect(timer, SIGNAL(timeout()), this, SLOT(showtime()));
    timer->start(60000);

    QVBoxLayout *layout = new QVBoxLayout;
    QHBoxLayout *Layout1 = new QHBoxLayout;
    QHBoxLayout *Layout2 = new QHBoxLayout;
    QHBoxLayout *Layout3 = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->setSpacing(20);
    buttonLayout->addWidget(connectButton, 1);
    buttonLayout->addWidget(discontButton, 1);
    Layout1->addWidget(nameLabel, 1);
    Layout1->addWidget(nameLine, 2);
    Layout2->addWidget(pswLabel, 1);
    Layout2->addWidget(pswLine, 2);
    Layout3->addWidget(deviceLabel, 1);
    Layout3->addWidget(devicels, 1);
    layout->addLayout(Layout1,1);
    layout->addLayout(Layout2,1);
    layout->addLayout(Layout3,1);
    layout->addWidget(rm, 1);
    layout->addWidget(display,4);
    layout->addLayout(buttonLayout, 1);
    widget->setLayout(layout);

    setWindowTitle(tr("h3c_ouc"));
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setMinimumSize(420,480);
    setMaximumSize(420,480);
    resize(420,480);
}

void Gh3c::closeEvent(QCloseEvent *event)
{
    if(trayIcon->isVisible()){
	QMessageBox::information(this, tr("Systray"),
	    tr("The program will keep running in the "
	    "system tray. To terminate the program, "
	    "choose <b>Exit</b> in the context menu "
	    "that pops up when clicking this program's "
	    "entry in the system tray."));
        hide();
        event->ignore();
    }
    else{
	trayIcon->show();
	event->ignore();
    }
}

void Gh3c::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
	case QSystemTrayIcon::Trigger:
	    if(isVisible()){
		hide();
	    }
	    else{
		show();
		setWindowState(Qt::WindowNoState);
	    }
	    break;
	default:
	    break;
    }
}

void Gh3c::loadSettings()
{
    QSettings settings;
    UserName = settings.value("username").toString();
    PassWord = settings.value("password").toString();
    QString State = settings.value("state").toString();
    nameLine->setText(UserName);
    pswLine->setText(PassWord);
    if(State == "true"){
	rm->setCheckState(Qt::Checked);
    }
    else{
	rm->setCheckState(Qt::Unchecked);
    }
}

void Gh3c::showtime()
{
    static int countm = 0,counth = 0;
    countm++;
    if(countm == 60){
	countm=0;
	counth++;
    }
    QTime time(counth, countm);
    QString text = time.toString("hh:mm");
    status2->setText(text);
}

void Gh3c::saveSettings()
{
    QSettings settings;
    settings.setValue("username",nameLine->text());
    settings.setValue("password",pswLine->text());
    settings.setValue("state",rm->isChecked());
}

void Gh3c::InitButton()
{
    discontButton->setEnabled(false);
    if(UserName!=NULL){
	connectButton->setEnabled(true);
    }
    else{
	connectButton->setEnabled(false);
    }
}

void Gh3c::about()
{
    QMessageBox::about(this, tr("About the Application"),
		tr("THe <b>Application</b> is an h3c-based campus "
		    "Internet connection program.Be applicable for"
		    "Ocean University of China. "
		    "Copyright (C) 2012 OUC.All rights reserved."));
}

void Gh3c::createActions()
{
    conAction = new QAction(tr("&Connect"), this);
    connect(conAction, SIGNAL(triggered()), this, SLOT(login()));
    conAction->setEnabled(false);

    disAction = new QAction(tr("&Disconnect"), this);
    connect(disAction, SIGNAL(triggered()), this, SLOT(disconnect()));
    disAction->setEnabled(false);

    exitAction = new QAction(tr("&Exit"), this);
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    conAct = new QAction(tr("&Connect"), this);
    conAct->setShortcuts(QKeySequence::New);
    conAct->setStatusTip(tr("Connect the Internet"));
    connect(conAct, SIGNAL(triggered()), this, SLOT(login()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the Application"));
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void Gh3c::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(conAction);
    trayIconMenu->addAction(disAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(exitAction);
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void Gh3c::createMenus()
{
    AppMenu = menuBar()->addMenu(tr("&App"));
    AppMenu->addAction(conAct);
    AppMenu->addSeparator();
    AppMenu->addAction(exitAct);

    HelpMenu = menuBar()->addMenu(tr("&About"));
    HelpMenu->addAction(aboutAct);
}

void Gh3c::createStatusBar()
{
    status1 = new QLabel;
    status1->setMinimumSize(status1->sizeHint());
    status2 = new QLabel;
    status2->setAlignment(Qt::AlignRight);
    status2->setIndent(2);
    statusBar()->addPermanentWidget(status1);
    statusBar()->addPermanentWidget(status2, 1);
    status1->setText("H3C is Ready.");
    status2->setText("00:00");
}

void Gh3c::login()
{	
    char *d = (char *)malloc(100);
    char *u = (char *)malloc(100);
    char *p = (char *)malloc(100);
    strcpy(d,devicels->currentText().toStdString().data());
    strcpy(u,UserName.toStdString().data());
    strcpy(p,PassWord.toStdString().data());
    qDebug()<<d<<" "<<u<<""<<p<<"";
    QIcon icon = QIcon("connect.png");
    status1->setText("Connected");
    trayIcon->setIcon(icon);
//    trayIcon->show();
    updateInterface(LoginMode);
}

void Gh3c::disconnect()
{
    char *d = (char *)malloc(100);
    strcpy(d,devicels->currentText().toStdString().data());
    qDebug()<<d;
    QIcon icon = QIcon("discont.png");
    status1->setText("Disconected");
    trayIcon->setIcon(icon);
//    trayIcon->show();
    updateInterface(LogoutMode);
}

void Gh3c::remember(int state)
{
    if(state == Qt::Checked){
	status1->setText(tr("Saved."));
	saveSettings();
    }
    else{
	status1->setText(tr("Clear."));
	QSettings settings;
	settings.clear();
    }
}

void Gh3c::userchanged()
{
    if(nameLine->text()==NULL){
	conAct->setEnabled(false);
	conAction->setEnabled(false);
	connectButton->setEnabled(false);
    }
    else{
	conAct->setEnabled(true);
	conAction->setEnabled(true);
	connectButton->setEnabled(true);
    }
    disAction->setEnabled(false);
    discontButton->setEnabled(false);
    pswLine->clear();
    rm->setCheckState(Qt::Unchecked);
}

void Gh3c::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange)
    {
	if(windowState() & Qt::WindowMinimized)
	{
	    QTimer::singleShot(0, this, SLOT(hide()));
	}
	QMainWindow::changeEvent(event);
    }
    else{
	event->ignore();
    }
}

void Gh3c::updateInterface(Mode mode)
{
    currentMode = mode;
    switch(currentMode){
    case LoginMode:
	conAct->setEnabled(false);
	conAction->setEnabled(false);
	connectButton->setEnabled(false);
	disAction->setEnabled(true);
	discontButton->setEnabled(true);
	break;
    case LogoutMode:
	conAct->setEnabled(true);
	conAction->setEnabled(true);
	discontButton->setEnabled(false);
	connectButton->setEnabled(true);
	break;
    }
}
