#include <iostream>
#include <iomanip>
#include <cmath>
#include <list>
#include <vector>

#include <stdio.h>
#include <iostream>
#include <algorithm>

#include "Cluster.h"
#include "LibraryCluster.h"

using namespace std;

const int DEF = 12  ;

//constructeur 1
LibraryCluster::LibraryCluster() : m_vect_Size(50, 0) {}

// destructeur
LibraryCluster::~LibraryCluster() {}

int LibraryCluster::getNbrCluster() const {return m_list_Cluster.size();}

void LibraryCluster::addCluster(Cluster new_Cluster) {m_list_Cluster.push_back(new_Cluster);}

void LibraryCluster::displayAllCluster()
{
    for (it=m_list_Cluster.begin(); it!=m_list_Cluster.end(); ++it)
    {
        it->displayGaps();
        it->displayCluster();
        //(*it).displayCluster();
    }
}

void LibraryCluster::fusionDuTurfu()
{
    int i(0);
    int xI(0), yI(0), xS(0), yS(0);
	double tSI(0), tSS(0);
    int compXI(0), compYI(0), compXS(0), compYS(0);
	double compTSI(0), compTSS(0);

    for (it=m_list_Cluster.begin(); it!=m_list_Cluster.end(); ++it)
    {
        tSI=it->getLowestTS();     tSS=it->getHighestTS();
        xI=it->getLowestX();     xS=it->getHighestX();     yI=it->getLowestY();     yS=it->getHighestY();
        i = 0;

        //for (compIt=it; compIt!=m_list_Cluster.end(); ++compIt)
          for (compIt=it; ((i<50) & (compIt!=m_list_Cluster.end()))  ; ++compIt  , ++i)
        {

            compTSI=compIt->getLowestTS();     compTSS=compIt->getHighestTS();
            compXI=compIt->getLowestX();     compXS=compIt->getHighestX();     compYI=compIt->getLowestY();     compYS=compIt->getHighestY();
            if (((abs(tSI-compTSI)<=0.00005 )&(abs(tSS-compTSS)<=0.00005)&(abs(xI-compXI)<=30 )&(abs(xS-compXS)<=30 )&(abs(yI-compYI)<=30 )&(abs(yS-compYS)<=30 ))&
                (!((abs(tSI-compTSI)==0)&(abs(tSS-compTSS)==0)&(abs(xI-compXI)==0)&(abs(xS-compXS)==0)&(abs(yI-compYI)==0)&(abs(yS-compYS)==0))))
            {
                for(int k = 0; k < (*compIt).getMax() ; k++)
                {
                    it->setTimeStamp(compIt->getTimeStamp(k));
                    it->setX(compIt->getX(k));
                    it->setY(compIt->getY(k));
                    it->setTot(compIt->getTot(k));
                    /*it->setHighestTS(compIt->getHighestTS());
                    it->setLowestTS(compIt->getLowestTS());
                    it->setHighestX(compIt->getHighestX());
                    it->setLowestX(compIt->getLowestX());
                    it->setHighestY(compIt->getHighestY());
                    it->setLowestY(compIt->getLowestY());*/
                }
                compIt = m_list_Cluster.erase (compIt);
                compIt--;
            }
        }
    }
}

void LibraryCluster::AnalyzerDuTurfu()
{
    double MoyTot;
    for (it=m_list_Cluster.begin(); it!=m_list_Cluster.end(); ++it)
    {
        for(int k = 0; k < (*it).getMax() ; k++)
        {
            MoyTot+=(it->getTot(k));
        }
        it->setMoyTot(MoyTot/(*it).getMax());
        MoyTot = 0 ;
        m_vect_Size[(*it).getMax()/DEF]+=1;
    }


    for(unsigned int m = 0; m < m_vect_Size.size() ; m++)
    {
        if (!( m_vect_Size[m]==0))
        cout << m_vect_Size[m] << " valu between " << m*DEF << " and " << (m+1)*DEF << endl;
    }
}
