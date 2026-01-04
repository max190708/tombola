#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
    srand(time(0));
    // t=tabellone, c=cartelle[gioc][riga][col], e=estratto, v=vincitore, n=num_estratti
    int t[91]={0}, c[2][3][9]={0}, e, v=-1, n=0;

    // Generazione cartelle
    for(int p=0; p<2; p++) {
        for(int r=0; r<3; r++) {
            int k=0;
            while(k<5) {
                int d=rand()%9; // Colonna (decina)
                if(c[p][r][d]==0) {
                    int x;
                    if(d==0) x=rand()%9+1;
                    else if(d==8) x=rand()%11+80;
                    else x=rand()%10+(d*10);

                    // Controllo se il numero x esiste gia nella colonna d
                    bool rpt=false;
                    for(int i=0; i<3; i++) if(c[p][i][d]==x) rpt=true;

                    if(!rpt) { c[p][r][d]=x; k++; }
                }
            }
        }
    }

    // Gioco
    while(v==-1) {
        do { 
            e=rand()%90+1;
            } 
            while(t[e]);
        t[e]=1; n++;

        cout<<"\n--- ESTRATTO: "<<e<<" --- ("<<n<<"/90)\nTABELLONE:\n";
        for(int i=1; i<=90; i++) {
            if(t[i]) cout<<" X ";
            else { if(i<10) cout<<" "; cout<<i<<" "; }
            if(i%10==0) cout<<endl;
        }

        for(int p=0; p<2; p++) {
            int tot=0;
            cout<<"\nGIOCATORE "<<p+1<<":\n";
            for(int r=0; r<3; r++) {
                for(int d=0; d<9; d++) {
                    int z=c[p][r][d];
                    if(z==0) cout<<" . ";
                    else if(t[z]) { cout<<" X "; tot++; }
                    else { if(z<10) cout<<" "; cout<<z<<" "; }
                }
                cout<<endl;
            }
            if(tot==15) 
            v=p+1;
        }

        if(v!=-1) {
            cout<<"\nTOMBOLA! VINCE GIOCATORE "<<v<<endl;
        } else {
            // Pausa di 2 secondi usando ctime
            long s=time(0)+2;
            while(time(0)<s); 
        }
    }
    return 0;
}