#include <iostream>
#include <iomanip>
#include <list>
#include <vector>

#include "Cluster.h"
#include "Cluster.cpp"
#include "LibraryCluster.h"

using namespace std;

//constructeur 1
LibraryCluster::LibraryCluster() {}

// destructeur
LibraryCluster::~LibraryCluster() {}

int LibraryCluster::getNbrCluster() const {return m_list_Cluster.size();}

void LibraryCluster::addCluster(Cluster new_Cluster) {m_list_Cluster.push_back(new_Cluster);}

void LibraryCluster::displayAllCluster() const
{
	/*for (int k = 0; k <  m_list_Cluster.size() ; k++)
    {
        m_list_Cluster[k].displayCluster();
    }*/
}
