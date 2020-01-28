#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long int ullint;

struct paire {
  ullint fun;
  ullint fdeux;
};

//------------------------------------------------------------------------------
ullint fibo1(int n){
  if(n<2){return 1;}
  else{
    return fibo1(n-1)+fibo1(n-2);
  }
}
//------------------------------------------------------------------------------
ullint fibo2(int n){
  ullint f[100];
  f[0]=1;
  f[1]=1;
  for(int i=2; i<=n; i++){
    f[i]=f[i-1]+f[i-2];
  }
  return f[n];
}
//------------------------------------------------------------------------------
ullint fibo3(int n){
  int a = 1;
  int b = 1;
  int i,c;
  for(i=2; i<=n ; i++){
    c = a + b;
    b = a;
    a = c;
  }
  return c;
}

//------------------------------------------------------------------------------

typedef struct paire paire;

paire fiblog(int n){
  paire mi,res;
  int i;
  if(n<2){
    res.fun = (ullint)1;
    res.fdeux = (ullint)1;
    return res;
  }
  i = n>>1; //decalage à droite => diviser par 2
  mi= fiblog(i);
  if(n&0x01){//if n impair
    res.fdeux = mi.fun*mi.fun + mi.fdeux*mi.fdeux;
    res.fun = mi.fun*mi.fun + 2*mi.fun*mi.fdeux;
    return res;
  }//if n pair
  res.fun = mi.fun*mi.fun + mi.fdeux*mi.fdeux;
  res.fdeux = (2*mi.fun - mi.fdeux)*mi.fdeux;
  return res;
}

ullint fibo4(int n){
  paire res;
  if(n>=0 && n<92){
    res=fiblog(n);
    return res.fun;
  }
  return (ullint)0;
}

//clock_t time;
//time = clock();
//time = (clock() - time)/CLOCKS_PER_SEC;
//printf("time : %f \n" ,(double)time);

int main(int argc, char **argv){
  if(argc != 2 || (uint)atoi(argv[1])>=92  ){
    printf("Usage : number_inferior_92\n");
    return 0;
  }

  int time;

  int n = (uint)atoi(argv[1]);

  time = (int)clock();
  //printf("result1 : %llu \n" ,fibo1(n));
  //printf("result2 : %llu \n" ,fibo2(n));
  //printf("result3 : %llu \n" ,fibo3(n));
  //printf("result4 : %llu \n" ,fibo4(n));
  time = (int)clock() - time;
  printf("time of : %d \n" ,time);

  /*45   result : 1836311903
  time 1 : 6011304
  time 2 : 61
  time 3 : 60
  time 4 : 41
  */

  /*91 result: 7540113804746346429
  time 1 : too long
  time 2 : 60
  time 3 : 59? result is false
  time 4 : 57
  */

  return 0;
}
