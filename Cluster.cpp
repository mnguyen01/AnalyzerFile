#include <iostream>
#include <iomanip>
#include <vector>

#include "Cluster.h"

using namespace std;

//constructeur 1
Cluster::Cluster(bool first) {
 m_bool_First = first ;
 m_dbl_Moy_Tot = 11515845246265065472 ;
 m_dbl_Lowest_TS = 11515845246265065472 ;
 m_int_Lowest_X = 2147483647 ;
 m_int_Lowest_Y = 2147483647 ;
 m_dbl_Highest_TS = 0 ;
 m_int_Highest_X = 0 ;
 m_int_Highest_Y = 0 ;
 m_int_Highest_YAZS = 1;
}

//constructeur 2
Cluster::Cluster(bool first, double top_TS, double low_TS,int top_X, int low_X, int top_Y, int low_Y, double first_timestamp, int first_x, int first_y, int first_tot ) : m_clu_X(), m_clu_Y(), m_clu_Tot(), m_clu_TimeStamp()
{
 m_bool_First = first ;
 m_dbl_Highest_TS = top_TS ;
 m_dbl_Lowest_TS = low_TS ;
 m_int_Highest_X = top_X ;
 m_int_Lowest_X = low_X ;
 m_int_Highest_Y = top_Y ;
 m_int_Lowest_Y = low_Y ;

 m_clu_TimeStamp.push_back(first_timestamp);
 m_clu_Tot.push_back(first_tot);
 m_clu_X.push_back(first_x);
 m_clu_Y.push_back(first_y);
 }

// destructeur
Cluster::~Cluster() {}

//getter
bool   Cluster::getFirst() const              {return m_bool_First;}
double Cluster::getMoyTot() const             {return m_dbl_Moy_Tot;}
double Cluster::getHighestTS() const          {return m_dbl_Highest_TS;}
double Cluster::getLowestTS() const           {return m_dbl_Lowest_TS;}
int    Cluster::getHighestX() const           {return m_int_Highest_X;}
int    Cluster::getLowestX() const            {return m_int_Lowest_X;}
int    Cluster::getHighestY() const           {return m_int_Highest_Y;}
int    Cluster::getLowestY() const            {return m_int_Lowest_Y;}
int    Cluster::getX(int i) const             {return m_clu_X[i];}
int    Cluster::getY(int i) const             {return m_clu_Y[i];}
int    Cluster::getTot(int i) const           {return m_clu_Tot[i];}
double Cluster::getTimeStamp(int i) const     {return m_clu_TimeStamp[i];}
int    Cluster::getMax() const                {return m_clu_TimeStamp.size();}

//setter
void Cluster::setHighestTS(double new_Top_TS)  { if (m_dbl_Highest_TS < new_Top_TS) {m_dbl_Highest_TS = new_Top_TS;}}

void Cluster::setLowestTS(double new_Low_TS)   { if (new_Low_TS<=0) {m_dbl_Lowest_TS =0; return;}
                                                 if (m_dbl_Lowest_TS > new_Low_TS) {m_dbl_Lowest_TS = new_Low_TS;}}

void Cluster::setHighestX(int new_Top_X)       { if (new_Top_X>=255) {m_int_Highest_X =255; return;}
                                                 if (m_int_Highest_X < new_Top_X) {m_int_Highest_X = new_Top_X;}}

void Cluster::setLowestX(int new_Low_X)        { if (new_Low_X<=0) {m_int_Lowest_X =0; return;}
                                                 if (m_int_Lowest_X > new_Low_X) {m_int_Lowest_X = new_Low_X;}}

void Cluster::setHighestY(int new_Top_Y)       { if (new_Top_Y>=255) {m_int_Highest_Y =255; return;}
                                                 if (m_int_Highest_Y < new_Top_Y) {m_int_Highest_Y = new_Top_Y;}}

void Cluster::setLowestY(int new_Low_Y)        { if (new_Low_Y<=0) {m_int_Lowest_Y =0; return;}
                                                 if (m_int_Lowest_Y > new_Low_Y) {m_int_Lowest_Y = new_Low_Y;}}

void Cluster::setFirst(bool StopFirst)            {m_bool_First = StopFirst ;}
void Cluster::setX(int new_X)           		  {m_clu_X.push_back(new_X) ;}
void Cluster::setY(int new_Y)             		  {m_clu_Y.push_back(new_Y) ;}
void Cluster::setTot(int new_Tot)        		  {m_clu_Tot.push_back(new_Tot) ;}
void Cluster::setTimeStamp(double new_TimeStamp)  {m_clu_TimeStamp.push_back(new_TimeStamp) ;}
void Cluster::setMoyTot(double Moytot)              {m_dbl_Moy_Tot = Moytot ;}


void Cluster::displayGaps() const {
    cout << fixed << setprecision (9) << "-  m_dbl_Lowest_TS: " << m_dbl_Lowest_TS << "   " << "m_dbl_Highest_TS: " << m_dbl_Highest_TS << '\n';
                                 cout << "-  m_int_Lowest_X : " << m_int_Lowest_X  << "   " << "m_int_Highest_X : " << m_int_Highest_X  << '\n';
                                 cout << "-  m_int_Lowest_Y : " << m_int_Lowest_Y  << "   " << "m_int_Highest_Y : " << m_int_Highest_Y  << '\n';
                                 cout << "-  m_dbl_Average_Tot : " << m_dbl_Moy_Tot << '\n';
}

void Cluster::displayCluster() const {
    cout << "-  Taille Cluster = " << m_clu_TimeStamp.size() << '\n' ;
    cout << "--------------------------------------------------------------------------------" << '\n' ;
    for (unsigned int j = 0; j <  m_clu_TimeStamp.size() ; j++){
        cout << "-  pixel numeros " << j << "   " ;
        cout << fixed << setprecision (9) << "TSp = " << m_clu_TimeStamp[j] << "   ";
        cout << "-  X = " << m_clu_X[j] << "   ";
        cout << "-  Y = " << m_clu_Y[j] << "   ";
        cout << "-  Tot = " << m_clu_Tot[j] << '\n' ;
        } cout << "================================================================================" << '\n' ;
        }
