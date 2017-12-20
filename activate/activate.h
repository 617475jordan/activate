#ifndef ACTIVATE_H
#define ACTIVATE_H

#include <QtWidgets/QMainWindow>
#include "ui_activate.h"
#include <qt_all_vs2013_x86.h>
#include "checkNetwork.h"
#include "getHardInformation.h"
using namespace std;
class activate : public QMainWindow
{
	Q_OBJECT

public:
	activate(QWidget *parent = 0);
	~activate();
	void                      inputHardwareInfo(hardwareInfo  m_inputHardwareInfo);

private:
	Ui::activateClass          ui;
	QTimer                     *m_qTimer;
private:
	void                       initalize();
	bool                       m_key(std::vector<string> m_vecKey);
	std::string                getActivatePaswsword();
	bool                       backUp(std::string m_inputBackup);
	bool                       matchPassword(string m_inputPassword);
	void                       showMenu();
	void                       activateGetHardwareInfo();
	
private slots:
	void                       on_activatePushButton_clicked();
	void                       updateNeteworkState();
	void                       on_clearPushButton_clicked();

private:
	std::string                m_strLineData;
	std::string                m_password;
	std::string                m_strPassword = "data\\password.index";
	std::string                m_strBackUp   = "data\\backup.index";
	bool                       m_isOk = false;
	hardwareInfo               m_hardwareInfo;
protected:
	vector<string>             m_vecBackup;
};

#endif // ACTIVATE_H
