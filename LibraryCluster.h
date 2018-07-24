#ifndef LIBRARYCLUSTER_H_INCLUDED
#define LIBRARYCLUSTER_H_INCLUDED

#include <list>
#include <vector>
#include "Cluster.h"

class LibraryCluster
{
    public:

    LibraryCluster();
    ~LibraryCluster();

    void displayAllCluster();
    void fusionDuTurfu();
    void AnalyzerDuTurfu();

    //getter
    int getNbrCluster() const;

    //setter
    void addCluster(Cluster new_Cluster);

    private:
    std::vector<int>                 m_vect_Size;
    std::list<Cluster>               m_list_Cluster ;
    std::list<Cluster>::iterator     it;
    std::list<Cluster>::iterator     compIt;

};

#endif // LIBRARYCLUSTER_H_INCLUDED
