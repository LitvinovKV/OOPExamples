#include "barel.h"

Barel::Barel(double amount, double alcohol) {
    m_alcohol = alcohol;
    m_amount = amount;
}

double Barel::getAmount() {
    return m_amount;
}

double Barel::getAlcohol() {
    return m_alcohol;
}

void Barel::setAmount(double& newAmount) {
    m_amount = newAmount;
} 

void Barel::setAlcohol(double& newAlcohol) {
    m_alcohol = newAlcohol;
}

void Barel::pourOut(Barel& otherBarel, double& amountCup) {
    m_alcohol = (m_alcohol * m_amount + otherBarel.getAlcohol() * amountCup)/(m_amount + amountCup);
    m_amount++;
    double newAmountCup = otherBarel.getAmount() - amountCup; 
    otherBarel.setAmount(newAmountCup);
}