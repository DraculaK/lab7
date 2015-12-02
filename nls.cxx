#include <iostream>
#include <cmath>


using namespace std;

void f(double* ys, double* y, const double eta){
 ys[0]=y[1];
 ys[1]=(eta-y[0]*y[0])*y[0];
}

int main(){
  
double k1[2];
double k2[2];
double k3[2];
double ytemp[2];
const double dx = 0.01;
const double N = 100/dx;

double y[2];
const double eta=0.4;
y[0]=1e-5;
y[1]=sqrt(eta)*y[0];

double t = 0;

  for(int i=0; i<N; i++){
    
  f(k1, y, eta);

  ytemp[0] = y[0]+ 0.5 * dx * k1[0];
  ytemp[1] = y[1]+ 0.5 * dx * k1[1];
  
  f(k2, ytemp, eta); 
  
  ytemp[0] = y[0]-dx*k1[0]+2*dx*k2[0];
  ytemp[1] = y[1]-dx*k1[1]+2*dx*k2[1];
  
  f(k3, ytemp, eta);
  
  
  
  y[0]=y[0]+(dx/6.0)*(k1[0]+4*k2[0]+k3[0]); 
  y[1]=y[1]+(dx/6.0)*(k1[1]+4*k2[1]+k3[1]);
  
  cout << i*dx+dx << "\t" << y[0] << "\t" << y[1] << endl;
  }
  
  
 return 0; 
}