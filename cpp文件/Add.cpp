//����ͷ�ļ���printf��stdio.h�ļ�������
#include <stdio.h>
//����Add
int Add(int a, int b)
//������ӵĽ��
{
	return a + b;
}
//�������Զ����á�����ֵ�����õĳ�������������ֵ����Ϊint
int main()
{
	//�������ͱ���result
	int result;
	//��Add��������ֵ�������result
	result = Add(2, 3);
	//printf����ַ�����"%d"����ռλ��
	printf("%d", result);
	//������������������ֵһ����Ϊ0
	return 0;
}