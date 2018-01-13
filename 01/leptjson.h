#ifndef LEPTJSON_H__
#define LEPTJSON_H__

typedef enum {
	LEPT_NULL,
	LEPT_FALSE,
	LEPT_TRUE,
	LEPT_NUMBER,
	LEPT_STRING,
	LEPT_OBJECT
} lept_type;

/*

��һ�汾��������ֻ������null/true/false 
�Ϸ�JSON��ʽ��
	JSON-text = ws value ws
	ws = *(%x20 / %x09 / %x0A / %x0D)
	value = null / false / true 
	null  = "null"
	false = "false"
	true  = "true" 
	
	JSON����������ɣ��հ� + ֵ + �հ�
	Ŀǰ��ȡ��value�� null/false/true 
*/ 

enum {
    LEPT_PARSE_OK = 0,                               // �������� 
    LEPT_PARSE_EXPECT_VALUE,						 // JSONֻ����һ���հ�(�ո��Ʊ�������з����س���) 
    LEPT_PARSE_INVALID_VALUE,						 // ���涨������ֵ�⻹������ֵ 
    LEPT_PARSE_ROOT_NOT_SINGULAR  					 // һ��ֵ�Ŀհ׺�������ֵ 
};

// �������JSON���ݣ�����ֻ����null/ true/ flase����ֻ��typeһ�� 
typedef struct {
	lept_type type;
} lept_value;

int lept_parse(lept_value* v, const char* json);     // ����json���ַ�����Ӧ���ģ�Ϊconst 
lept_type lept_get_type(const lept_value* v);        // ���ʽ������ȡJSON���� 

#endif // LEPTJSON_H__
















