#ifndef LIBRARYCLUSTER_H_INCLUDED
#define LIBRARYCLUSTER_H_INCLUDED

#include <list>
#include "Cluster.h"

class LibraryCluster
{
    public:

    LibraryCluster();
    ~LibraryCluster();

    void displayAllCluster() const;

    //getter
    int getNbrCluster() const ;

    //setter
    void addCluster(Cluster new_Cluster);

    private:
    std::list<Cluster>  m_list_Cluster ;

};

#endif // LIBRARYCLUSTER_H_INCLUDED
