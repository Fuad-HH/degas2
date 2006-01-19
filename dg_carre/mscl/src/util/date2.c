/*  VERSION : 28.05.95 19:11  */
#include <stdio.h>
#include <time.h>
date2(dt)
char *dt;
{
     struct tm *t;
     long s;
     int y;
     time(&s); t = localtime(&s); y = t->tm_year;
     sprintf(dt,"%02d.%02d.%02d", t->tm_mday, (t->tm_mon)+1, y);
     return;
}
date2_(dt)
char *dt;
{
     return date2(dt);
}
