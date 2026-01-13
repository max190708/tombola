#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main()
{
	srand(time(0));
    // dichiarazione
	int t[91]={0};
	int c[2][3][9]={0};
	int e;
	int v=-1;
	int n=0;
    // elaborazione
	// generazione cartelle 
	for(int p=0;p<2;p++)
	{
		for(int r=0;r<3;r++)
		{
			int k=0;
			while(k<5)
			{
				int d=rand()%9;
				if(c[p][r][d]==0) //p=giocatori,r=righe,d=decine(colonne)
				{
					int x;
					//generazione numeri
					if(d==0)
					{
						x=rand()%9+1;//da 1 a 9
					}
					else if(d==8)
					{
						x=rand()%11+80; // da 80 a 90
					}
					else
					{
						x=rand()%10+(d*10); //tutti gli altri numeri
					}

					bool rpt=false;
					for(int i=0;i<3;i++) // controllo se il numero estratto era già uscito
					{
						if(c[p][i][d]==x)
						{
							rpt=true;
						}
					}

					if(!rpt)
					{
						c[p][r][d]=x;
						k++;
					}
				}
			}
		}
	}

	// gioco 
	while(v==-1)
	{
		do
		{
			e=rand()%90+1;
		}
		while(t[e]==1);

		t[e]=1;
		n++;

		// pulizia schermo e reset cursore
		cout<<"\033[H\033[2J";

		cout<<"--- Numero estratto: "<<e<<" --- (Totali: "<<n<<"/90)\n\n";

		cout<<"Tabellone:\n"; // stampa tabellone
		for(int i=1;i<=90;i++)
		{
			if(t[i]==1)
			{
				cout<<"\033[31m"<<i<<"\033[0m ";
			}
			else
			{
				cout<<i<<" ";
			}

			if(i<10)
			{
				cout<<" ";
			}

			if(i%10==0) // per strutturare bene il tabellone (ogni 10 numeri va a capo)
			{
				cout<<endl;
			}
		}

		for(int p=0;p<2;p++)
		{
			int tot=0;
			cout<<"\nGiocatore "<<p+1<<":\n";

			for(int r=0;r<3;r++)
			{
				for(int d=0;d<9;d++)
				{
					int z=c[p][r][d];

					if(z==0)
					{
						cout<<" . ";
					}
					else
					{
						if(t[z]==1)
						{
							cout<<"\033[31m"; //colora numero in rosso
							if(z<10)
							{
								cout<<" ";
							}
							cout<<z<<"\033[0m "; 
							tot++; //contatore totale
						}
						else
						{
							if(z<10)
							{
								cout<<" ";
							}
							cout<<z<<" ";
						}
					}
				}
				cout<<endl;
			}
			if(tot==15) //se contatore è uguale a 15 , uno dei giocatori viene proclamato vincitore 
			{
				v=p+1;
			}
		}

		if(v!=-1)
		{
			cout<<"\n\nTombola! Vince il giocatore "<<v<<" !!!\n";
		}
		else
		{
			sleep(3); //pausa di 3 secondi prima di aggiornare  tabellone e  cartelle
		}
	}

	return 0;
}

