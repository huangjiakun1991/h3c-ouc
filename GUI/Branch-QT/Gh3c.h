#ifndef GH3C_H
#define GH3C_H

#include <QMainWindow>
#include <QSystemTrayIcon>

class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QComboBox;
class QListWidget;
class QMenu;
class QAction;
class QActionGroup;
class QTimer;

class Gh3c : public QMainWindow
{
    Q_OBJECT

    public:
	Gh3c();
	enum Mode {LoginMode, LogoutMode};

    protected:
      void closeEvent(QCloseEvent *event);
      void changeEvent(QEvent *event);

    public slots:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
	void remember(int);
    	void login();
    	void disconnect();
	void about();
	void userchanged();
	void showtime();

    private:
	void createTrayIcon();
	void createActions();
	void createMenus();
	void createStatusBar();
	void updateInterface(Mode mode);
	void loadSettings();
	void saveSettings();
	void InitButton();

	QSystemTrayIcon *trayIcon;
	QMenu *AppMenu;
	QMenu *HelpMenu;
	QMenu *trayIconMenu;
	QActionGroup *alignmentGroup;
	QAction *conAct;
	QAction *exitAct;
	QAction *aboutAct;
	QAction *conAction;
	QAction *disAction;
	QAction *exitAction;	
	QPushButton *connectButton;
    	QPushButton *discontButton;
	QLineEdit *nameLine;
	QLineEdit *pswLine;
	QComboBox *devicels;
    	QCheckBox *rm;
	QListWidget *display;
	QLabel *status1;
	QLabel *status2;
	QTimer *timer;

	Mode currentMode;
	QString UserName;
	QString PassWord;
};

#endif
