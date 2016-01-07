#include<iostream>
#include<cmath>

using namespace std;

int main(){

	const int dim = 2;
	double H, q[dim], p[dim], t = 0;
	const double e = 0.6, dt = 0.05, tEnd = 20*M_PI;

	//Anfangswerte:
	q[0] = 1-e; //q1
	q[1] = 0;	//q2
	p[0] = 0;	//p1
	p[1] = sqrt((1+e)/(1-e)); //p2
	H    = 0.5*(p[0]*p[0]+p[1]*p[1])-1/sqrt(q[0]*q[0]+q[1]*q[1]);

	cout << t << "\t" << H << "\t" << q[0] << "\t" << q[1] << endl;

	while (t<=tEnd){
		t += dt; 
			
		double a = q[0]*q[0]+q[1]*q[1]; //Alte Werte sichern
		for (int i=0; i<dim; i++){
			p[i] -= dt*q[i]/pow(a,1.5);
			q[i] += dt*p[i];
		}
		H = 0.5*(p[0]*p[0]+p[1]*p[1])-1/sqrt(q[0]*q[0]+q[1]*q[1]);
		
		cout << t << "\t" << H << "\t" << q[0] << "\t" << q[1] << endl;
	}

return 0;
}
