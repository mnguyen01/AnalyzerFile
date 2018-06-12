#ifndef CLUSTER_H_INCLUDED
#define CLUSTER_H_INCLUDED

class Cluster
{
    public:

    Cluster(bool);
    Cluster(bool, double, double, double, unsigned short int, unsigned short int, unsigned short int);
    ~Cluster();

    //fonction
    void displayGap() const ;
    void displayCluster() const ;

    //setters
    void setFirst       (bool StopFirst);
    void setLowest      (double new_Low);
    void setHighest     (double new_Top);
    void setX           (unsigned short int new_X);
    void setY           (unsigned short int new_Y);
    void setTot         (unsigned short int new_Tot);
    void setTimeStamp   (double new_TimeStamp);

    //getters
    bool                    getFirst() const;
    double                  getLowest() const;
    double                  getHighest() const;
    unsigned short int      getX(int i) const;
    unsigned short int      getY(int i) const;
    unsigned short int      getTot(int i) const;
    double                  getTimeStamp(int i) const;
    int                     getMax() const;

    private:

    bool                                m_bool_First;
    double                              m_int_Lowest;
    double                              m_int_Highest;
    std::vector <double>                m_clu_TimeStamp;
    std::vector <unsigned short int>    m_clu_Y;
    std::vector <unsigned short int>    m_clu_X;
    std::vector <unsigned short int>    m_clu_Tot;
};

#endif // CLUSTER_H_INCLUDED
