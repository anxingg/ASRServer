
// ASRServerDlg.h : ͷ�ļ�
//

#pragma once

#include "Config.h"
#include "BaseSocket.h"
#include "Log.h"
#include "ClientList.h"

#include "afxcmn.h"
#include "afxwin.h"


// CASRServerDlg �Ի���
class CASRServerDlg : public CDialog
{
// ����
public:
	CASRServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ASRSERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//��������
	Config * pConfig;
	//�����SOCKET
	CBaseSocket ServerSocket;
	//��־��
	Log m_WriteLog;
	//�ͻ����б�
	ClientList clientList;
	ClientTTSDataReqList clientReqList;
	list<TTSThreadData *> ttsThreadList;
public:
	//����������
	BOOL OnListen();
	//ASRServer Socket ��Ϣ����
	LONG OnASRServerSocketMsg(UINT wParam, long lParam);
	//�ͻ�������
	void Accept();
	//�ͻ��˶Ͽ�����
	void ClientDisConnect(SOCKET clientSocket);
	//�ر�SOCKET�����SOCKET��Դ
	void ClientClose(Client * pClient);
	//���յ�����
	void ReadData(SOCKET  clientSocket);
	//�������յ�������
	void ProcData(Client * pClient,char * szBuffer);
	//��ͻ��˷�������
	void SendData(SOCKET clientSocket,const char * szBuffer,int nSize);
	//�ָ�����
	void SplitData(int m,char* pmsg,CString ip);
	//д��־���ڽ�����ʾ��־
	void Log(Log::LogLevel level,CString log);
	static unsigned __stdcall ASRThread(void *info);

public:
	CTreeCtrl mTreeClient;
	CString listenPort;
	CListBox mListMessage;
	CButton bt_Exit;
	CString m_Message;
	afx_msg void OnBnClickedButtonExit();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDisclient();
	afx_msg void OnLbnDblclkListMessage();
};