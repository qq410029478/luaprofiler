/*
** LuaProfiler
** Copyright Kepler Project 2005-2007 (http://www.keplerproject.org/luaprofiler)
** $Id: stack.h,v 1.5 2007-08-22 19:23:53 carregal Exp $
*/

/*****************************************************************************
stack.h:
   Simple stack manipulation
*****************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include <time.h>

typedef struct lprofS_sSTACK_RECORD lprofS_STACK_RECORD;

struct lprofS_sSTACK_RECORD {
	clock_t time_marker_function_local_time;
	clock_t time_marker_function_total_time;
    const char *file_defined;
    const char *function_name;
    unsigned MallocFuncName;
	char *source_code;        
	long line_defined;
	long current_line;
    const char* CallerSource;
	float local_time; // millisecond
	float total_time;// millisecond
    unsigned local_step;
    int IsTailCall;
    long TotalMemory;
    //size_t MemoryAllocated;
	lprofS_STACK_RECORD *next;
};

typedef lprofS_STACK_RECORD *lprofS_STACK;

typedef struct lprofP_sSTATE lprofP_STATE;
	
struct lprofP_sSTATE {
   int stack_level;
   int ThreadIndex;
   lprofS_STACK stack_top;
};

void lprofS_push(lprofS_STACK *p, lprofS_STACK_RECORD r);
lprofS_STACK_RECORD lprofS_pop(lprofS_STACK *p);

#endif
