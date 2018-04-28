class Barel {
    double m_amount;
    double  m_alcohol;
    
    public:
        Barel(double, double);    

        double getAmount();
        double getAlcohol();

        void setAmount(double&);
        void setAlcohol(double&);

        void pourOut(Barel&, double&);
};