#include "activate.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "AES.h"


  

bool m_networkState = false;
bool m_isSystemRunning = true;
int m_passwordLen = 192;
std::vector<string> m_vecSecert;

activate::activate(QWidget *parent)
	: QMainWindow(parent)
{
	initalize();
	if (m_isSystemRunning == false)
	{
		return;
	}
	ui.setupUi(this);
	showMenu();
}

activate::~activate()
{

}

void activate::inputHardwareInfo(hardwareInfo  m_inputHardwareInfo)
{
	m_hardwareInfo = m_inputHardwareInfo;
}

void activate::initalize()
{
	/********
	�˹�����ʱδ��ʹ��
	********/
	/*m_networkState = false;
	checkNetwork *m_checkNetwork = new checkNetwork();
	if (m_checkNetwork->networkState())
	{
	QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("��ʼ���ɹ�"));
	m_networkState = true;
	}
	else
	{
	QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("�����쳣"));
	m_networkState = false;
	}
	m_checkNetwork = NULL;
	delete[] m_checkNetwork;*/

	/***********��ȡ��Կƥ�����к�**************/
	std::ifstream m_infile;
	m_infile.open(m_strPassword, std::ios::in);
	if (!m_infile.is_open())
	{
		m_infile.close();
		std::ofstream m_outfile(m_strPassword, std::ios::out);
		m_outfile.close();
		return ;
	}
	std::string m_strLineData;
	
	while (getline(m_infile, m_strLineData))
	{
		m_password = m_password + m_strLineData;
		m_strLineData.clear();
	}
	m_infile.close();
	if (m_password.size() < m_passwordLen)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("�ͻ�����Ч"));
		m_isSystemRunning = false;
		return;
	}
	AES *m_aes = new AES();
	m_password = m_aes->DecryptionAES(m_password, 1);
	m_aes = NULL;
	delete[] m_aes;
	/***********��ȡ�Ѵ�����Կ**************/
	m_infile.open(m_strBackUp, std::ios::in);
	if (!m_infile.is_open())
	{
		m_infile.close();
		std::ofstream m_outfile(m_strBackUp, std::ios::out);
		m_outfile.close();
		return;
	}
	m_vecBackup.clear();
	while (getline(m_infile, m_strLineData))
	{
		if (m_strLineData.length() == NULL)
		{
			continue;
		}
		m_vecBackup.push_back( m_strLineData);
		m_strLineData.clear();
	}
	m_infile.close();
	
	for (int i = 0; i < m_vecBackup.size(); i++)
	{
		m_isOk = matchPassword(m_vecBackup[i]);
		if (m_isOk == true)
		{
			break;
		}
	}
}

bool activate::m_key(std::vector<string> m_vecKey)
{
	return true;
}

std::string activate::getActivatePaswsword()
{
	std::string m_text;
	QString m_qstr=ui.lineEdit->text();
	m_text = m_qstr.toStdString();
	m_qstr.clear();
	if (m_text.length() == 0)
	{
		return m_text;
	}
	AES *m_aes = new AES();
	m_text = m_aes->DecryptionAES(m_text, 0);
	m_aes = NULL;
	delete[] m_aes;
	return m_text;
}



bool activate::backUp(std::string m_inputBackup)
{
	std::ofstream m_outfile(m_strBackUp, std::ios_base::app);
	if (!m_outfile.is_open())
	{
		m_outfile.open(m_strBackUp, std::ios::out);
	}
	m_outfile << m_inputBackup << endl;
	m_outfile.close();
	m_inputBackup.clear();
	return true;
}

bool activate::matchPassword(string m_inputPassword)
{
	for (int i = 0; i < 128; i++)
	{
		if ((m_inputPassword[i] % (m_password[i] - 47) == 0 || m_inputPassword[i] % (m_password[i] - 64) == 0))
		{
			continue;
		}
		else
		{
			m_inputPassword.clear();
			//QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("����ʧ��"));
			return false;
		}
	}
	m_inputPassword.clear();
	return true;
}

void activate::on_activatePushButton_clicked()
{
	if (m_isOk)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("�Ѽ�������������"));
		return;
	}
	std::string m_text = getActivatePaswsword();
	if (m_text.length()==NULL)
	{
		m_text.clear();
		QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("����ʧ��"));
		return;
	}
	bool flag = matchPassword(m_text);
	
	if (flag == false)
	{
		m_text.clear();
		QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("����ʧ��"));
		//backUp(m_text);
		return;
	}
	else
	{
		ui.noticeLabel->clear();
		ui.noticeLabel->setText(QString::fromLocal8Bit("�Ѽ���"));
		QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("����ɹ�"));
		backUp(m_text);
		m_text.clear();
		m_isOk = true;
		return;
	}
	

}

void activate::updateNeteworkState()
{
	checkNetwork *m_checkNetwork = new checkNetwork();
	if (!m_checkNetwork->networkState())
	{
		//QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("�����쳣"));
		ui.statelabel->setText(QString::fromLocal8Bit("����"));
		ui.statelabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 255);"));
	}
	else
	{
		ui.statelabel->setText(QString::fromLocal8Bit("����"));
		ui.statelabel->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
	}
	m_checkNetwork = NULL;
	delete[] m_checkNetwork;
}

void activate::on_clearPushButton_clicked()
{
	ui.lineEdit->clear();
	QMessageBox::information(this, QString::fromLocal8Bit("������ʾ"), QString::fromLocal8Bit("����ɹ�"));

}

void activate::showMenu()
{
	ui.noticeLabel->setAlignment(Qt::AlignCenter);
	ui.statelabel->setAlignment(Qt::AlignCenter);
	ui.noticeLabel->setText(QString::fromLocal8Bit("δ����"));
	if (m_isOk)
	{
		ui.noticeLabel->clear();
		ui.noticeLabel->setText(QString::fromLocal8Bit("�Ѽ���"));
	}
	/*if (m_networkState)
	{
	ui.statelabel->setText(QString::fromLocal8Bit("����"));
	ui.statelabel->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
	}
	else
	{
	ui.statelabel->setText(QString::fromLocal8Bit("����"));
	ui.statelabel->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 255);"));
	}
	m_qTimer = new QTimer();
	m_qTimer->start(33);
	connect(m_qTimer, SIGNAL(timeout()), this, SLOT(updateData()));*/
}

//
//void activate::activateGetHardwareInfo()
//{
//	getHardInformation *m_getHardInformation = new getHardInformation();
//	m_hardwareInfo = m_getHardInformation->getHardwareInfo();
//	m_getHardInformation = NULL;
//	delete[] m_getHardInformation;
//	std::ofstream m_outfile(m_strHardSoftwareInfo, std::ios::in);
//	if (!m_outfile.is_open())
//	{
//		m_outfile.open(m_strHardSoftwareInfo, std::ios::out);
//	}
//
//	//cout <<"CPU TYPE:" <<m_phy.m_cpuType.c_str()/* << endl*/;
//	m_outfile << "CPU ID:";
//	for (unsigned int i = 0; i < m_hardwareInfo.m_cpuId.size(); i++)
//	{
//		m_outfile << m_hardwareInfo.m_cpuId[i] << endl;
//	}
//	m_outfile << "Really Freq:" << m_hardwareInfo.m_cpuFreq << "MHz" << endl;
//	m_outfile << "CPU Information:" << m_hardwareInfo.m_cpuInformation << endl;
//	m_outfile << "ProcessorArchitecture:" << m_hardwareInfo.m_ProcessorArchitecture << endl;
//	m_outfile << "dwActiveProcessorMask:" << m_hardwareInfo.m_dwActiveProcessorMask << endl;
//	m_outfile << "wNumberOfProcessors:" << m_hardwareInfo.m_dwNumberOfProcessors << endl;
//	m_outfile << "ProcessorLevel:" << m_hardwareInfo.m_wProcessorLevel << endl;
//	m_outfile << "Bios Information:" << m_hardwareInfo.m_bios << endl;
//	for (int i = 0; i < m_hardwareInfo.m_AdapterName.size(); i++)
//	{
//		m_outfile << "Adapter Num:" << i + 1 << endl;
//		m_outfile << "Adapter Name" << ":" << m_hardwareInfo.m_AdapterName[i] << endl;
//		m_outfile << "Adapter Description" << ":" << m_hardwareInfo.m_AdapterDescription[i] << endl;
//		m_outfile << "Adapter Type:" << m_hardwareInfo.m_AdapterType[i] << endl;
//		m_outfile << "Mac:" << m_hardwareInfo.m_macAddress[i] << endl;
//	}
//
//	m_outfile.close();
//}
