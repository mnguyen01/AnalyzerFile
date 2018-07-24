#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

#include <ctime>


#include "Cluster.h"
#include "LibraryCluster.h"

using namespace std;

string const FICHIER("Fichier/cd.txt");

const int N1 = 256 ; // taille capteur
const double N2 = 0.000000025 ; // Toa Croase * N2
const double N3 = 0.0000000015625 ; // Toa Fine * N3
const double N4 = 0.000000101 ; // Gaps TimeStamp
const int N5 = 15 ; // Gaps position
const int MANTISSE = 12 ;

int main()
{
    clock_t t_initial;
    clock_t t_finalSort;
    clock_t t_finalFusion;
    clock_t t_finalAnalyzer;
    double t_cpu;
    t_initial = clock ();

    int coordinates(0), tot(0);
	double toaCoarse(0), toaFine(0);

	int x(0), y(0);
	double timeStamp(0);

	ifstream flux(FICHIER.c_str());
	string ligne("file not found");
	char commentaire('.'), Display('.');

    Cluster currentCluster(true);
	Cluster tamponClusterXinF(true);
	Cluster tamponClusterXsuP(true);
	Cluster tamponClusterYinF(true);
   	Cluster tamponClusterYsuP(true);
	Cluster tamponClusterXinFYinf(true);
	Cluster tamponClusterXsuPYsuP(true);

	Cluster tamponClusterTSinF(true);
	Cluster tamponClusterTSinFXinF(true);
	Cluster tamponClusterTSinFXsuP(true);
	Cluster tamponClusterTSinFYinF(true);
   	Cluster tamponClusterTSinFYsuP(true);
	Cluster tamponClusterTSinFXinFYinf(true);
	Cluster tamponClusterTSinFXsuPYsuP(true);

    LibraryCluster libraryForCluster;

	if(flux)
	{
	    cout << "sorts of data..." << endl;

        while (getline(flux,ligne))
		{
		    flux.get(commentaire);
            flux.putback(commentaire);
            if (commentaire!='#')
            {
				// recover
				flux >> coordinates ;
				flux >> toaCoarse ;
				flux >> toaFine ;
				flux >> tot ;

				// calculate
				x = coordinates%N1 ;
				y = coordinates/N1 ;
				timeStamp = (toaCoarse*N2)-(toaFine*N3) ;

                if (currentCluster.getFirst()==true)
                {
                    currentCluster.setFirst(false);
                    currentCluster.setTimeStamp(timeStamp);
                    currentCluster.setX(x);
                    currentCluster.setY(y);
                    currentCluster.setTot(tot);
                    currentCluster.setHighestTS(timeStamp+N4);
                    currentCluster.setLowestTS(timeStamp-N4);
                    currentCluster.setHighestX(x+N5);
                    currentCluster.setLowestX(x-N5);
                    currentCluster.setHighestY(y+N5);
                    currentCluster.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()  >= x         )&
                         ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    currentCluster.setTimeStamp(timeStamp);
                    currentCluster.setX(x);
                    currentCluster.setY(y);
                    currentCluster.setTot(tot);
                    currentCluster.setHighestTS(timeStamp+N4);
                    currentCluster.setLowestTS(timeStamp-N4);
                    currentCluster.setHighestX(x+N5);
                    currentCluster.setLowestX(x-N5);
                    currentCluster.setHighestY(y+N5);
                    currentCluster.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         !( currentCluster.getLowestX()  <  x         ) & (currentCluster.getHighestX()  >= x         )&
                         ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterXinF.setFirst(false);
                    tamponClusterXinF.setTimeStamp(timeStamp);
                    tamponClusterXinF.setX(x);
                    tamponClusterXinF.setY(y);
                    tamponClusterXinF.setTot(tot);
                    tamponClusterXinF.setHighestTS(timeStamp+N4);
                    tamponClusterXinF.setLowestTS(timeStamp-N4);
                    tamponClusterXinF.setHighestX(x+N5);
                    tamponClusterXinF.setLowestX(x-N5);
                    tamponClusterXinF.setHighestY(y+N5);
                    tamponClusterXinF.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & !(currentCluster.getHighestX() >  x         )&
                         ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterXsuP.setFirst(false);
                    tamponClusterXsuP.setTimeStamp(timeStamp);
                    tamponClusterXsuP.setX(x);
                    tamponClusterXsuP.setY(y);
                    tamponClusterXsuP.setTot(tot);
                    tamponClusterXsuP.setHighestTS(timeStamp+N4);
                    tamponClusterXsuP.setLowestTS(timeStamp-N4);
                    tamponClusterXsuP.setHighestX(x+N5);
                    tamponClusterXsuP.setLowestX(x-N5);
                    tamponClusterXsuP.setHighestY(y+N5);
                    tamponClusterXsuP.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()  >= x         )&
                         !( currentCluster.getLowestY()  <  y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterYinF.setFirst(false);
                    tamponClusterYinF.setTimeStamp(timeStamp);
                    tamponClusterYinF.setX(x);
                    tamponClusterYinF.setY(y);
                    tamponClusterYinF.setTot(tot);
                    tamponClusterYinF.setHighestTS(timeStamp+N4);
                    tamponClusterYinF.setLowestTS(timeStamp-N4);
                    tamponClusterYinF.setHighestX(x+N5);
                    tamponClusterYinF.setLowestX(x-N5);
                    tamponClusterYinF.setHighestY(y+N5);
                    tamponClusterYinF.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()  >= x         )&
                         ( currentCluster.getLowestY()   <= y         ) & !(currentCluster.getHighestY() >  y         ))
                {
                    tamponClusterYsuP.setFirst(false);
                    tamponClusterYsuP.setTimeStamp(timeStamp);
                    tamponClusterYsuP.setX(x);
                    tamponClusterYsuP.setY(y);
                    tamponClusterYsuP.setTot(tot);
                    tamponClusterYsuP.setHighestTS(timeStamp+N4);
                    tamponClusterYsuP.setLowestTS(timeStamp-N4);
                    tamponClusterYsuP.setHighestX(x+N5);
                    tamponClusterYsuP.setLowestX(x-N5);
                    tamponClusterYsuP.setHighestY(y+N5);
                    tamponClusterYsuP.setLowestY(y-N5);

                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         !( currentCluster.getLowestX()   < x         ) & (currentCluster.getHighestX()  >= x         )&
                         !( currentCluster.getLowestY()   < y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterXinFYinf.setFirst(false);
                    tamponClusterXinFYinf.setTimeStamp(timeStamp);
                    tamponClusterXinFYinf.setX(x);
                    tamponClusterXinFYinf.setY(y);
                    tamponClusterXinFYinf.setTot(tot);
                    tamponClusterXinFYinf.setHighestTS(timeStamp+N4);
                    tamponClusterXinFYinf.setLowestTS(timeStamp-N4);
                    tamponClusterXinFYinf.setHighestX(x+N5);
                    tamponClusterXinFYinf.setLowestX(x-N5);
                    tamponClusterXinFYinf.setHighestY(y+N5);
                    tamponClusterXinFYinf.setLowestY(y-N5);
                }
                else if (( currentCluster.getLowestTS()  <= timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & !(currentCluster.getHighestX()  > x         )&
                         ( currentCluster.getLowestY()   <= y         ) & !(currentCluster.getHighestY()  > y         ))
                {
                    tamponClusterXsuPYsuP.setFirst(false);
                    tamponClusterXsuPYsuP.setTimeStamp(timeStamp);
                    tamponClusterXsuPYsuP.setX(x);
                    tamponClusterXsuPYsuP.setY(y);
                    tamponClusterXsuPYsuP.setTot(tot);
                    tamponClusterXsuPYsuP.setHighestTS(timeStamp+N4);
                    tamponClusterXsuPYsuP.setLowestTS(timeStamp-N4);
                    tamponClusterXsuPYsuP.setHighestX(x+N5);
                    tamponClusterXsuPYsuP.setLowestX(x-N5);
                    tamponClusterXsuPYsuP.setHighestY(y+N5);
                    tamponClusterXsuPYsuP.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS()  < timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()  >= x         )&
                         ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterTSinF.setFirst(false);
                    tamponClusterTSinF.setTimeStamp(timeStamp);
                    tamponClusterTSinF.setX(x);
                    tamponClusterTSinF.setY(y);
                    tamponClusterTSinF.setTot(tot);
                    tamponClusterTSinF.setHighestTS(timeStamp+N4);
                    tamponClusterTSinF.setLowestTS(timeStamp-N4);
                    tamponClusterTSinF.setHighestX(x+N5);
                    tamponClusterTSinF.setLowestX(x-N5);
                    tamponClusterTSinF.setHighestY(y+N5);
                    tamponClusterTSinF.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS()  <  timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         !( currentCluster.getLowestX()   <  x         ) & (currentCluster.getHighestX()  >= x         )&
                          ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterTSinFXinF.setFirst(false);
                    tamponClusterTSinFXinF.setTimeStamp(timeStamp);
                    tamponClusterTSinFXinF.setX(x);
                    tamponClusterTSinFXinF.setY(y);
                    tamponClusterTSinFXinF.setTot(tot);
                    tamponClusterTSinFXinF.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFXinF.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFXinF.setHighestX(x+N5);
                    tamponClusterTSinFXinF.setLowestX(x-N5);
                    tamponClusterTSinFXinF.setHighestY(y+N5);
                    tamponClusterTSinFXinF.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS() <  timeStamp ) & (currentCluster.getHighestTS()  >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & !(currentCluster.getHighestX()  >  x         )&
                         ( currentCluster.getLowestY()   <= y         ) & (currentCluster.getHighestY()   >= y         ))
                {
                    tamponClusterTSinFXsuP.setFirst(false);
                    tamponClusterTSinFXsuP.setTimeStamp(timeStamp);
                    tamponClusterTSinFXsuP.setX(x);
                    tamponClusterTSinFXsuP.setY(y);
                    tamponClusterTSinFXsuP.setTot(tot);
                    tamponClusterTSinFXsuP.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFXsuP.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFXsuP.setHighestX(x+N5);
                    tamponClusterTSinFXsuP.setLowestX(x-N5);
                    tamponClusterTSinFXsuP.setHighestY(y+N5);
                    tamponClusterTSinFXsuP.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS()  < timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()  >= x         )&
                         !( currentCluster.getLowestY()   < y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterTSinFYinF.setFirst(false);
                    tamponClusterTSinFYinF.setTimeStamp(timeStamp);
                    tamponClusterTSinFYinF.setX(x);
                    tamponClusterTSinFYinF.setY(y);
                    tamponClusterTSinFYinF.setTot(tot);
                    tamponClusterTSinFYinF.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFYinF.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFYinF.setHighestX(x+N5);
                    tamponClusterTSinFYinF.setLowestX(x-N5);
                    tamponClusterTSinFYinF.setHighestY(y+N5);
                    tamponClusterTSinFYinF.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS()  < timeStamp ) & (currentCluster.getHighestTS()  >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & (currentCluster.getHighestX()   >= x         )&
                         ( currentCluster.getLowestY()   <= y         ) & !(currentCluster.getHighestY()  >  y         ))
                {
                    tamponClusterTSinFYsuP.setFirst(false);
                    tamponClusterTSinFYsuP.setTimeStamp(timeStamp);
                    tamponClusterTSinFYsuP.setX(x);
                    tamponClusterTSinFYsuP.setY(y);
                    tamponClusterTSinFYsuP.setTot(tot);
                    tamponClusterTSinFYinF.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFYinF.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFYinF.setHighestX(x+N5);
                    tamponClusterTSinFYinF.setLowestX(x-N5);
                    tamponClusterTSinFYinF.setHighestY(y+N5);
                    tamponClusterTSinFYinF.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS()  <  timeStamp ) & (currentCluster.getHighestTS() >= timeStamp )&
                         !( currentCluster.getLowestX()   <  x         ) & (currentCluster.getHighestX()  >= x         )&
                         !( currentCluster.getLowestY()   <  y         ) & (currentCluster.getHighestY()  >= y         ))
                {
                    tamponClusterTSinFXinFYinf.setFirst(false);
                    tamponClusterTSinFXinFYinf.setTimeStamp(timeStamp);
                    tamponClusterTSinFXinFYinf.setX(x);
                    tamponClusterTSinFXinFYinf.setY(y);
                    tamponClusterTSinFXinFYinf.setTot(tot);
                    tamponClusterTSinFXinFYinf.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFXinFYinf.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFXinFYinf.setHighestX(x+N5);
                    tamponClusterTSinFXinFYinf.setLowestX(x-N5);
                    tamponClusterTSinFXinFYinf.setHighestY(y+N5);
                    tamponClusterTSinFXinFYinf.setLowestY(y-N5);
                }
                else if (!( currentCluster.getLowestTS() <  timeStamp ) & (currentCluster.getHighestTS()  >= timeStamp )&
                         ( currentCluster.getLowestX()   <= x         ) & !(currentCluster.getHighestX()  >  x         )&
                         ( currentCluster.getLowestY()   <= y         ) & !(currentCluster.getHighestY()  >  y         ))
                {
                    tamponClusterTSinFXsuPYsuP.setFirst(false);
                    tamponClusterTSinFXsuPYsuP.setTimeStamp(timeStamp);
                    tamponClusterTSinFXsuPYsuP.setX(x);
                    tamponClusterTSinFXsuPYsuP.setY(y);
                    tamponClusterTSinFXsuPYsuP.setTot(tot);
                    tamponClusterTSinFXsuPYsuP.setHighestTS(timeStamp+N4);
                    tamponClusterTSinFXsuPYsuP.setLowestTS(timeStamp-N4);
                    tamponClusterTSinFXsuPYsuP.setHighestX(x+N5);
                    tamponClusterTSinFXsuPYsuP.setLowestX(x-N5);
                    tamponClusterTSinFXsuPYsuP.setHighestY(y+N5);
                    tamponClusterTSinFXsuPYsuP.setLowestY(y-N5);
                }
                else
                {
                    libraryForCluster.addCluster(currentCluster);
                    currentCluster = new Cluster(true);
                    currentCluster.setTimeStamp(timeStamp);
                    currentCluster.setX(x);
                    currentCluster.setY(y);
                    currentCluster.setTot(tot);
                    currentCluster.setHighestTS(timeStamp+N4);
                    currentCluster.setLowestTS(timeStamp-N4);
                    currentCluster.setHighestX(x+N5);
                    currentCluster.setLowestX(x-N5);
                    currentCluster.setHighestY(y+N5);
                    currentCluster.setLowestY(y-N5);
                    currentCluster.setFirst(false);

                    if (tamponClusterXinF.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterXinF);
                        tamponClusterXinF = new Cluster(true);
                    }
                    if (tamponClusterXsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterXsuP);
                        tamponClusterXsuP = new Cluster(true);
                    }
                    if (tamponClusterYinF.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterYinF);
                        tamponClusterYinF = new Cluster(true);
                    }
                    if (tamponClusterYsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterYsuP);
                        tamponClusterYsuP = new Cluster(true);
                    }
                    if (tamponClusterXinFYinf.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterXinFYinf);
                        tamponClusterXinFYinf = new Cluster(true);
                    }
                    if (tamponClusterXsuPYsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterXsuPYsuP);
                        tamponClusterXsuPYsuP = new Cluster(true);
                    }
                    if (tamponClusterTSinF.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinF);
                        tamponClusterTSinF = new Cluster(true);
                    }
                    if (tamponClusterTSinFXinF.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFXinF);
                        tamponClusterTSinFXinF = new Cluster(true);
                    }
                    if (tamponClusterTSinFXsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFXsuP);
                        tamponClusterTSinFXsuP = new Cluster(true);
                    }
                    if (tamponClusterTSinFYinF.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFYinF);
                        tamponClusterTSinFYinF = new Cluster(true);
                    }
                    if (tamponClusterTSinFYsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFYsuP);
                        tamponClusterTSinFYsuP = new Cluster(true);
                    }
                    if (tamponClusterTSinFXinFYinf.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFXinFYinf);
                        tamponClusterTSinFXinFYinf = new Cluster(true);
                    }
                    if (tamponClusterTSinFXsuPYsuP.getFirst()==false)
                    {
                        libraryForCluster.addCluster(tamponClusterTSinFXsuPYsuP);
                        tamponClusterTSinFXsuPYsuP = new Cluster(true);
                    }
				}
			}
		}
	}
	else
    {
        cout << "ERREUR 01 = file not found" << endl;
    }
	libraryForCluster.addCluster(currentCluster);
	if (tamponClusterXinF.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterXinF);
        }
	if (tamponClusterXsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterXsuP);
        }
	if (tamponClusterYinF.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterYinF);
        }
	if (tamponClusterYsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterYsuP);
        }
	if (tamponClusterXinFYinf.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterXinFYinf);
        }
	if (tamponClusterXsuPYsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterXsuPYsuP);
        }
    if (tamponClusterTSinF.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinF);
        }
	if (tamponClusterTSinFXinF.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFXinF);
        }
	if (tamponClusterTSinFXsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFXsuP);
        }
	if (tamponClusterTSinFYinF.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFYinF);
        }
	if (tamponClusterTSinFYsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFYsuP);
        }
	if (tamponClusterTSinFXinFYinf.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFXinFYinf);
        }
	if (tamponClusterTSinFXsuPYsuP.getFirst()==false)
        {
            libraryForCluster.addCluster(tamponClusterTSinFXsuPYsuP);
        }

    cout <<"number of cluster before = "<< libraryForCluster.getNbrCluster() << endl;
    t_finalSort = clock ();
    t_cpu = ((t_finalSort - t_initial));
    cout <<"during : "<< t_cpu << "ms" << endl;

    cout <<"fusion of cluster..." << endl;
    libraryForCluster.fusionDuTurfu();
    t_finalFusion = clock ();
    t_cpu = ((t_finalFusion - t_initial)-t_finalSort);
    cout <<"during : "<< t_cpu << "ms" << endl;
    cout <<"number of cluster after = "<< libraryForCluster.getNbrCluster() << endl;

    cout <<"Analyzer..." << endl;
    libraryForCluster.AnalyzerDuTurfu();
    t_finalAnalyzer = clock ();
    t_cpu = ((t_finalAnalyzer - t_initial)-t_finalFusion);
    cout <<"during : "<< t_cpu << "ms" << endl;

    cout <<"display all cluster ? y/n" << endl;
    cin >> Display ;
    if (Display == 'y')
    { libraryForCluster.displayAllCluster(); }

    return 0;
}
