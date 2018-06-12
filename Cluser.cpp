#include <iostream>
#include <iomanip> // nombre apres virgule
#include <vector>

#include "Cluster.h"

using namespace std;


//constructeur 1
Cluster::Cluster(bool first) {
 m_bool_First = first ;
  }

//constructeur 2
Cluster::Cluster(bool first, double top, double low, double first_timestamp, unsigned short int first_x, unsigned short int first_y, unsigned short int first_tot ) : m_clu_X(), m_clu_Y(), m_clu_Tot(), m_clu_TimeStamp() {
 m_bool_First = first ;
 m_int_Highest = top ;
 m_int_Lowest = low ;
 m_clu_TimeStamp.push_back(first_timestamp);
 m_clu_Tot.push_back(first_tot);
 m_clu_X.push_back(first_x);
 m_clu_Y.push_back(first_y);
  }

// destructeur
Cluster::~Cluster() {}

//getter
bool                  Cluster::getFirst() const             {return m_bool_First;}
double                Cluster::getHighest() const           {return m_int_Highest;}
double                Cluster::getLowest() const            {return m_int_Lowest;}
unsigned short int    Cluster::getX(int i) const            {return m_clu_X[i];}
unsigned short int    Cluster::getY(int i) const            {return m_clu_Y[i];}
unsigned short int    Cluster::getTot(int i) const          {return m_clu_Tot[i];}
double                Cluster::getTimeStamp(int i) const    {return m_clu_TimeStamp[i];}
int                   Cluster::getMax() const               {return m_clu_TimeStamp.size();}

//setter
void Cluster::setFirst(bool StopFirst)              {m_bool_First = StopFirst;}
void Cluster::setX(unsigned short int new_X)        {m_clu_X.push_back(new_X) ;}
void Cluster::setY(unsigned short int new_Y)        {m_clu_Y.push_back(new_Y) ;}
void Cluster::setTot(unsigned short int new_Tot)    {m_clu_Tot.push_back(new_Tot) ;}
void Cluster::setTimeStamp(double new_TimeStamp)    {m_clu_TimeStamp.push_back(new_TimeStamp) ;}
void Cluster::setHighest(double new_Top)            { if (m_int_Highest <= new_Top)
                                                            m_int_Highest = new_Top; }
void Cluster::setLowest(double new_Low)             { if (m_int_Lowest >= new_Low)
                                                            m_int_Lowest = new_Low; }


void Cluster::displayGap() const {
    cout << fixed << setprecision (10) << "m_int_Lowest : " << m_int_Lowest  << '\t';
    cout << "m_int_Highest : " << m_int_Highest  <<'\n' << '\n' ;
}

void Cluster::displayCluster() const {
    cout << "Taille Cluster = " << m_clu_TimeStamp.size() << '\n' ;
    for (int j = 0; j <  m_clu_TimeStamp.size() ; j++){
        cout << "pixel numeros " << j << '\t' << '\t' ;
        cout << fixed << setprecision (13) << "m_clu_TimeStamp = " << m_clu_TimeStamp[j] << '\t';
        cout << "m_clu_X = " << m_clu_X[j] << '\t';
        cout << "m_clu_Y = " << m_clu_Y[j] << '\t';
        cout << "m_clu_Tot = " << m_clu_Tot[j] << '\n' ;
    }
    cout <<'\n' ;
}
