#ifndef _MY_GLOBAL_H_
#define _MY_GLOBAL_H_

// ���ļ���ȡ���ڴ滺����
// lpszFile:	�ļ�·��
// pFileBuffer:	�ļ�����
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻�ʵ�ʶ�ȡ��С
DWORD ReadPEFile(IN LPSTR lpszFile, OUT LPVOID* pFileBuffer);

// ���ļ�����pFileBuffer���Ƶ�pImageBufferӳ�񻺴�
// pFileBuffer:		�ļ�����
// pImageBuffer:	ӳ�񻺴�
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻ظ��ƴ�С
DWORD CopyFileBufferToImageBuffer(IN LPVOID pFileBuffer, OUT LPVOID* pImageBuffer);

// ��pImageBufferӳ�񻺴渴�Ƶ�pNewBuffer�ļ�����
// pImageBuffer:	ӳ�񻺴�
// pNewBuffer:		�ļ�����
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻ظ��ƴ�С
DWORD CopyImageBufferToNewBuffer(IN LPVOID pImageBuffer, OUT LPVOID* pNewBuffer);

// ��pNewBuffer�ļ����渴�Ƶ��ļ���
// pMemBuffer:	�ļ�����
// size:		���ƴ�С
// lpszFile:	�ļ�·��
// ����ֵ: 0�Ƿ���ʧ��
BOOL MemeryToFile(IN LPVOID pMemBuffer, IN size_t size, OUT LPSTR lpszFile);

// RvaToFileOffset:���ڴ�ƫ��RVAת����FOA�ļ�ƫ�� Relation Virtual Address -> File Offset Address
// pFileBuffer:	�ļ�����
// dwRva:		�ڴ�ƫ��
// ����ֵ: 0�Ƿ���ʧ��, ���򷵻��ļ�ƫ��
DWORD RvaToFileOffset(IN LPVOID pFileBuffer, IN DWORD dwRva);

//////////////////////////////////////////////////////////////////////////
// ���Ժ��� - ��ӡNTͷ
VOID TestPrintfNTHeaders();
// ���Ժ��� - disk->FileBuffer->ImageBuffer->NewBuffer->disk
VOID TestPELoader();
// ���Ժ��� - �����ο�������Ӵ���
VOID TestAddCodeInCodeSec();
// ���Ժ��� - �����ݶο�������Ӵ���
VOID TestAddCodeInDataSec();
// ���Ժ��� - ����������Ӵ���
VOID TestAddCodeInNewSec();
// ���Ժ��� - ���������Ӵ���
VOID TestAddCodeInExpSec();
// ���Ժ��� - ��ӡĿ¼��
VOID TestPrintDirectory();
// ���Ժ��� - ��ӡ�����
VOID TestPrintExport();

#endif // _MY_GLOBAL_H_