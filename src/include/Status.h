//
// Created by nlt on 18-1-4.
// file name: Status.h
// contents: status codes and Macro functions list

#ifndef DATA_STRUCTURE_STATUS_H
#define DATA_STRUCTURE_STATUS_H

// Status code
#define TRUE        1       //true
#define FALSE       0       //false
#define YES         1       //yes
#define NO          0       //NO
#define OK          1       //pass
#define ERROR       0       //error
#define SUCCESS     1       //success
#define UNSUCCESS   0       //fail
#define INFEASIBLE  -1      //not allowed

#ifdef _MATH_H              // in case of conflict
#define OVERFLOW    -2      // heap stack overflow
#define UNDERFLOW   -3      // heap stack under flow
#endif

#ifndef NULL
#define NULL    ((void*)0)
#endif

// type of status
typedef int Status

//Macro functions
// Wait a moment
#define Wait(x)\
{\
    double _Loop_Num_;\
    for(_Loop_Num_=0.01;_Loop_Num_,=100000.0*x;_Loop_Num_+=0.01)\
;\
} //empty loop for waiting a moment


// Press enter to continue
#define PressEnter\
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
};

#endif //DATA_STRUCTURE_STATUS_H
