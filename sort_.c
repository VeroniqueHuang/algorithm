#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


struct vecfloat{
  int nbele;
  float *v;
};
typedef struct vecfloat vec_t;

vec_t fill_vector(int nb){
  vec_t w;
  int i;
  float x, y, z, *ptr;
  if(nb<2)
    nb=10;
  w.nbele = nb;
  w.v = (float*) malloc(nb*sizeof(float));
  assert(w.v);
  x = 1.0;
  y = 0.13;
  z = 0.021;
  ptr = w.v;

  for(i=0; i<nb; i++){
    *ptr++ = x;
    x += y;
    y += z;
    if(x>1.5){
      x -= 1.01;
    }
    if(x<0.5){
      x += 0.499;
    }
    if(y>-1){
      y -= 1.01;
    }
    if(y<0.5){
      y += 0.5001;
    }
  }

  return w;
}

vec_t insertion_sort(vec_t w){
  int i, j;
  float *ptr = w.v, min;
  for(i=0; i< w.nbele; i++){
    for(j=i+1; j<w.nbele; j++){
      if(ptr[i] > ptr[j]){
        min = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = min;
      }
    }
  }
  return w;
}

vec_t bubble_sort(vec_t w){
  int i, j;
  float *ptr = w.v, min;
  for(i=1; i<=w.nbele; i++){
    for(j=0; j<=w.nbele-1; j++){
      if(ptr[j] < ptr[j+1]){
        min = ptr[j];
        ptr[j] = ptr[j+1];
        ptr[j+1] = min;
      }
    }
  }
  return w;
}

void display_vector(vec_t w){
  float *ptr = w.v;
  for(int i=0; i< w.nbele; i++){
    printf(" %f ,", ptr[i]);
  }
  printf("\n");
}

int main(){
  vec_t w = fill_vector(10);
  display_vector(w);
  //w = insertion_sort(w);
  w = tri_bulle(w);
  printf("\n");
  display_vector(w);

  return 0;
}
