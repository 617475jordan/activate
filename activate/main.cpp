#include "activate.h"
#include <QtWidgets/QApplication>
#include "getHardInformation.h"
#include <string>
#include <fstream>

#ifdef WIN32  
#include <direct.h> 
#include <io.h>
#endif  
#ifdef linux   
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h> 
#include <dirent.h> 
#endif
using namespace std;
void                     activateGetHardwareInfo();//硬件信息获取
void                     fileIsOver();//文件夹存在判断

hardwareInfo             m_hardwareInfo;

int main(int argc, char *argv[])
{
	fileIsOver();
	activateGetHardwareInfo();
	QApplication a(argc, argv);
	activate w;
	w.inputHardwareInfo(m_hardwareInfo);
	w.show();
	return a.exec();
}



void activateGetHardwareInfo()
{
	std::string         m_strHardSoftwareInfo = "data\\hardSoftwareInfo.index";
	getHardInformation *m_getHardInformation = new getHardInformation();
	m_hardwareInfo = m_getHardInformation->getHardwareInfo();
	m_getHardInformation = NULL;
	delete[] m_getHardInformation;
	std::ofstream m_outfile(m_strHardSoftwareInfo, std::ios::in);
	if (!m_outfile.is_open())
	{
		m_outfile.open(m_strHardSoftwareInfo, std::ios::out);
	}

	m_outfile << "CPU ID:";
	for (unsigned int i = 0; i < m_hardwareInfo.m_cpuId.size(); i++)
	{
		m_outfile << m_hardwareInfo.m_cpuId[i] << endl;
	}
	m_outfile << "Really Freq:" << m_hardwareInfo.m_cpuFreq << "MHz" << endl;
	m_outfile << "CPU Information:" << m_hardwareInfo.m_cpuInformation << endl;
	m_outfile << "ProcessorArchitecture:" << m_hardwareInfo.m_ProcessorArchitecture << endl;
	m_outfile << "dwActiveProcessorMask:" << m_hardwareInfo.m_dwActiveProcessorMask << endl;
	m_outfile << "wNumberOfProcessors:" << m_hardwareInfo.m_dwNumberOfProcessors << endl;
	m_outfile << "ProcessorLevel:" << m_hardwareInfo.m_wProcessorLevel << endl;
	m_outfile << "Bios Information:" << m_hardwareInfo.m_bios << endl;
	for (int i = 0; i < m_hardwareInfo.m_AdapterName.size(); i++)
	{
		m_outfile << "Adapter Num:" << i + 1 << endl;
		m_outfile << "Adapter Name" << ":" << m_hardwareInfo.m_AdapterName[i] << endl;
		m_outfile << "Adapter Description" << ":" << m_hardwareInfo.m_AdapterDescription[i] << endl;
		m_outfile << "Adapter Type:" << m_hardwareInfo.m_AdapterType[i] << endl;
		m_outfile << "Mac:" << m_hardwareInfo.m_macAddress[i] << endl;
	}

	m_outfile.close();
}

void fileIsOver()
{
	string dir = "data";
	if (access(dir.c_str(), 0) == -1)
	{
		//cout << dir << " is not existing" << endl;
		//cout << "now make it" << endl;
#ifdef WIN32  
		int flag = mkdir(dir.c_str());
#endif  
#ifdef linux   
		int flag = mkdir(dir.c_str(), 0777);
#endif  
		/*if (flag == 0)
		{
		cout << "make successfully" << endl;
		}
		else {
		cout << "make errorly" << endl;
		}*/
	}
	else
	{
		return;
	}
}
