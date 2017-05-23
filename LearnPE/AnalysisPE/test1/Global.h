#ifndef _MY_GLOBAL_H_
#define _MY_GLOBAL_H_

// 将文件读取到内存缓冲区
// lpszFile:	文件路径
// pFileBuffer:	文件缓存
// 返回值: 0是返回失败, 否则返回实际读取大小
DWORD ReadPEFile(IN LPSTR lpszFile, OUT LPVOID* pFileBuffer);

// 将文件缓存pFileBuffer复制到pImageBuffer映像缓存
// pFileBuffer:		文件缓存
// pImageBuffer:	映像缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyFileBufferToImageBuffer(IN LPVOID pFileBuffer, OUT LPVOID* pImageBuffer);

// 将pImageBuffer映像缓存复制到pNewBuffer文件缓存
// pImageBuffer:	映像缓存
// pNewBuffer:		文件缓存
// 返回值: 0是返回失败, 否则返回复制大小
DWORD CopyImageBufferToNewBuffer(IN LPVOID pImageBuffer, OUT LPVOID* pNewBuffer);

// 将pNewBuffer文件缓存复制到文件中
// pMemBuffer:	文件缓存
// size:		复制大小
// lpszFile:	文件路径
// 返回值: 0是返回失败
BOOL MemeryToFile(IN LPVOID pMemBuffer, IN size_t size, OUT LPSTR lpszFile);

// RvaToFileOffset:将内存偏移RVA转换成FOA文件偏移 Relation Virtual Address -> File Offset Address
// pFileBuffer:	文件缓存
// dwRva:		内存偏移
// 返回值: 0是返回失败, 否则返回文件偏移
DWORD RvaToFileOffset(IN LPVOID pFileBuffer, IN DWORD dwRva);

//////////////////////////////////////////////////////////////////////////
// 测试函数 - 打印NT头
VOID TestPrintfNTHeaders();
// 测试函数 - disk->FileBuffer->ImageBuffer->NewBuffer->disk
VOID TestPELoader();
// 测试函数 - 向代码段空闲区添加代码
VOID TestAddCodeInCodeSec();
// 测试函数 - 向数据段空闲区添加代码
VOID TestAddCodeInDataSec();
// 测试函数 - 向新增节添加代码
VOID TestAddCodeInNewSec();
// 测试函数 - 向扩大节添加代码
VOID TestAddCodeInExpSec();
// 测试函数 - 打印目录项
VOID TestPrintDirectory();
// 测试函数 - 打印输出表
VOID TestPrintExport();

#endif // _MY_GLOBAL_H_