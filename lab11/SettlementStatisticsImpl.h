//
// Created by Balazs on 2024. 12. 04..
//

#ifndef LAB11_SETTLEMENTSTATISTICSIMPL_H
#define LAB11_SETTLEMENTSTATISTICSIMPL_H

#include "SettlementStatistics.h"
#include <map>
#include "Settlement.h"

class SettlementStatisticsImpl : SettlementStatistics {
private:
    multimap<string, Settlement> settlements;
public:
    SettlementStatisticsImpl(const multimap<string, Settlement>& settlements)
            : settlements(settlements) {}
    int numSettlements() const override;

    int numCounties() const override;

    int numSettlementsByCounty(const string &county) const override;

    vector<Settlement> findSettlementsByCounty(const string &county) const override;

    Settlement findSettlementsByNameAndCounty(
            const string &name, const string &county) const override;

    Settlement maxPopulation() const override;

    Settlement minPopulation() const override;

    vector<Settlement> findSettlementsByName(const string &name) override;


};


#endif //LAB11_SETTLEMENTSTATISTICSIMPL_H
