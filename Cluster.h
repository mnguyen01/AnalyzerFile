#ifndef CLUSTER_H_INCLUDED
#define CLUSTER_H_INCLUDED

class Cluster
{
    public:

    Cluster(bool);
    Cluster(bool, double, double, int, int, int, int, double, int, int, int);
    ~Cluster();

    //fonction
    void displayGaps() const ;
    void displayCluster() const ;

    //getters
    bool    getFirst() const;

    double  getLowestTS() const;
    double  getHighestTS() const;
    int     getLowestX() const;
    int     getHighestX() const;
    int     getLowestY() const;
    int     getHighestY() const;
    int     getX(int i) const;
    int     getY(int i) const;
    int     getTot(int i) const;
    double  getTimeStamp(int i) const;
    int     getMax() const;
    double  getMoyTot() const;

    //setters
    void setFirst     (bool StopFirst);
    void setLowestTS  (double new_Low_TS);
    void setHighestTS (double new_Top_TS);
    void setLowestX   (int new_Low_X);
    void setHighestX  (int new_Top_X);
    void setLowestY   (int new_Low_Y);
    void setHighestY  (int new_Top_Y);
    void setX         (int new_X);
    void setY         (int new_Y);
    void setTot       (int new_Tot);
    void setTimeStamp (double new_TimeStamp);
    void setMoyTot    (double MoyTot);


    private:

    bool                 m_bool_First;

    double               m_dbl_Lowest_TS;
    double               m_dbl_Highest_TS;
    int                  m_int_Lowest_X;
    int                  m_int_Highest_X;
    int                  m_int_Lowest_Y;
    int                  m_int_Highest_Y;

    double               m_dbl_Moy_Tot;

    std::vector <double> m_clu_TimeStamp;
    std::vector <int>    m_clu_Y;
    std::vector <int>    m_clu_X;
    std::vector <int>    m_clu_Tot;
};

#endif // CLUSTER_H_INCLUDED
