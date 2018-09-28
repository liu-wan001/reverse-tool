#ifndef REVERSE_TOOL_H
#define REVERSE_TOOL_H

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// Creverse_toolApp: 
// 有关此类的实现，请参阅 reverse_tool.cpp
//

class Creverse_toolApp : public CWinApp
{
public:
	Creverse_toolApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern Creverse_toolApp theApp;
#endif // REVERSE_TOOL_H

