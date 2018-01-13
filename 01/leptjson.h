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

第一版本解析器，只解析：null/true/false 
合法JSON格式：
	JSON-text = ws value ws
	ws = *(%x20 / %x09 / %x0A / %x0D)
	value = null / false / true 
	null  = "null"
	false = "false"
	true  = "true" 
	
	JSON由三部分组成：空白 + 值 + 空白
	目前可取的value有 null/false/true 
*/ 

enum {
    LEPT_PARSE_OK = 0,                               // 正常解析 
    LEPT_PARSE_EXPECT_VALUE,						 // JSON只含有一个空白(空格、制表符、换行符、回车符) 
    LEPT_PARSE_INVALID_VALUE,						 // 除规定的三种值外还有其他值 
    LEPT_PARSE_ROOT_NOT_SINGULAR  					 // 一个值的空白后还有其他值 
};

// 解析后的JSON数据，现在只解析null/ true/ flase，故只有type一种 
typedef struct {
	lept_type type;
} lept_value;

int lept_parse(lept_value* v, const char* json);     // 解析json，字符串不应更改，为const 
lept_type lept_get_type(const lept_value* v);        // 访问结果，获取JSON类型 

#endif // LEPTJSON_H__
















