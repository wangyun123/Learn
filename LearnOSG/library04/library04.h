/*
*	4������library04: def�ļ��е�EXPORTS��� 
*
*	�½��ı��ļ�library04.lib�������������£�
*	LIBRARY	"library04"
*	;DESCRIPTION 'library04 windows dynamic link library'
*
*	EXPORTS
*		add4
*		sub4
*	����vs������ lib /out:library04.lib /machine:ix86 /def:library04.def
*
*	ע����dependency���ǿ�����library04.dll�еĺ������ģ�
*	ֻ����2����3���ܿ����������� 
*
*	2017-04-04���������޷���ɶ�̬��ĵ���!!
* 
* 2017-08-17: lib���dll���пɵ����������ɶ�Ӧ��lib�ļ����ṩ�ڱ�������Ϊ���ӽ׶���ʹ��
*		          ���dll����û�пɹ������ĺ������������Ҳ�޷������ɵ�lib���ҵ���Ӧ�ĺ���
*             ���ԣ��ڸù�������dll֮�󴴽�def�ļ���������ʵ�ֶԿ⺯���ĵ���!!
*             ���飺��ʹ��dumpbin /EXPORTS *.dll ���鿴�Ƿ��е�������
*/

#ifndef LIBRARY_04_H
#define LIBRARY_04_H

int add4(int a, int b);
int sub4(int a, int b);
int mul4(int a, int b);
int div4(int a, int b);

#endif //LIBRARY_04_H