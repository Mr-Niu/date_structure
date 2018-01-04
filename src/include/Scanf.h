//
// Created by nlt on 18-1-4.
//

#ifndef SCANF_C
#define SCANF_C

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

// only read ascii , jump unicode

int Scanf(FILE *fp, char *format, ...)
{
    int *i;
    char *ch, *s;
    float *f;
    int count, k, n;
    int tmp;
    size_t len;
    va_list arglist;
    len = strlen(format);
    for(count=0, k=2; k<=len; k += 2){
        while((tmp = getc(fp))!= EOF){
            if(0<=tmp && 127>=tmp){
                ungetc(tmp, fp);        // push back to file stream
                break;
            }
        }

        if(EOF == tmp)
            break;
        switch (format[k-1]){
            case 'c':                   // read char
                ch = va_arg(arglist, char*);
                if(tmp != EOF)
                        count += fscanf(fp, "%c", ch);
                break;
            case 'd':                   // read integer
                i = va_arg(arglist, int*);
                while((tmp=getc(fp))!= EOF){
                    if((tmp>='0' && tmp<='9') || tmp=='-' || tmp == '+'){
                        ungetc(tmp, fp);
                        break;
                    }
                }

                if(tmp != EOF)
                    count += fscanf(fp, "%d", i);
                break;

            case 'f':                      // read float
                f = va_arg(arglist, float*);
                while((tmp = getc(fp))!=EOF) {
                    if ((tmp >= '0' && tmp <= '9') ||
                        tmp == '-' || tmp == '+' || tmp == '.') {
                        ungetc(tmp, fp);
                        break;
                    }
                }
                if(tmp != EOF)
                    count += fscanf(fp, "%f", f);

                break;
            case 's':                      // read string
                s = va_arg(arglist, char*);
                while ((tmp = getc(fp))!=EOF && (!isprint(tmp)||
                        tmp == ' '))
                    ;
                n=0;
                if(!feof(fp)){
                    ungetc(tmp,fp);
                    while((tmp=getc(fp))!=EOF){
                        if(isprint(tmp) && tmp!=' ')
                            s[n++]=tmp;
                        else
                            break;
                    }
                    ungetc(tmp,fp);
                }
                s[n] = '\0';
                count++;
                break;
            default:
                break;
        }
    }
    va_end(arglist);
    return count;

}



#endif