#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
	
	int x,y,z,m,na;
	cout<<"Inserisci l'altezza : "<<endl;
	cin>>x;
	cout<<"\33[32m";
	z=120;
	na=1;
	for(int j=0;j<x;j++)
	{
		cout<<"\33["<<j+10<<";"<<z<<"H";
		for(int i=0;i<na;i++)
	    {
		cout<<"*";
	    }	
	    z-=1;
	    na=na+2;
	    for(int g=0;g<x;g++)
	    {
	    m=rand()%34+33;	
		cout<<"\33["<<m<<";"<<z<<"H";
	    }
	}

	return 0;
}









