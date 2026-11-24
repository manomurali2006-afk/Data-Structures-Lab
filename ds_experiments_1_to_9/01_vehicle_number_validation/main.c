#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    const char states[][3]={"AP","AR","AS","BR","CG","GA","GJ","HR","HP","JH","KA","KL","MP","MH","MN","ML","MZ","NL","OD","PB","RJ","SK","TN","TS","TR","UP","UK","WB","AN","CH","DD","DL","JK","LA","LD","PY"};
    char v[20]; int i,n,found=0,ok=1;
    printf("Enter vehicle number: ");
    if(scanf("%19s",v)!=1) return 1;
    for(i=0;v[i];i++) v[i]=(char)toupper((unsigned char)v[i]);
    n=(int)strlen(v);
    if(n<9||n>10){puts("Invalid length");return 0;}
    for(i=0;i<36;i++) if(v[0]==states[i][0]&&v[1]==states[i][1]) found=1;
    if(!found){puts("Invalid state code");return 0;}
    if(!isdigit((unsigned char)v[2])||!isdigit((unsigned char)v[3])){puts("Invalid RTO code");return 0;}
    for(i=4;i<n-4;i++) if(!isalpha((unsigned char)v[i])) ok=0;
    if(!ok){puts("Invalid series code");return 0;}
    for(i=n-4;i<n;i++) if(!isdigit((unsigned char)v[i])) ok=0;
    puts(ok?"Valid vehicle number":"Invalid registration number");
    return 0;
}
