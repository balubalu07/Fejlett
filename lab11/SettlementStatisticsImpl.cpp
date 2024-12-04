//
// Created by Balazs on 2024. 12. 04..
//

#include "SettlementStatisticsImpl.h"
#include <algorithm>

int SettlementStatisticsImpl::numSettlements() const {
    return settlements.size();
}

int SettlementStatisticsImpl::numCounties() const {
    map<string, bool> counties;
    for (const auto& settlement : settlements) {
        counties[settlement.first] = true;
    }
    return counties.size();
}

int SettlementStatisticsImpl::numSettlementsByCounty(const string &county) const {
    return count_if(settlements.begin(),settlements.end(),[county](const pair<string, Settlement>& e){
        return e.second.getCounty() == county;
    });
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByCounty(const string &county) const {
    vector<Settlement> result;

    auto range = settlements.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(it->second);
    }

    return result;
}

Settlement SettlementStatisticsImpl::findSettlementsByNameAndCounty(const string &name, const string &county) const {
    auto range = settlements.equal_range(county);
    for (auto it = range.first; it != range.second; ++it) {
        if(it->second.getName() == name) return it->second;
    }
    throw invalid_argument("Settlement not found");
}

Settlement SettlementStatisticsImpl::maxPopulation() const {
    int maxpop=0;
    Settlement res("","",0);
    for(auto& [key,value]: settlements){
        if(value.getPopulation()>maxpop){
            maxpop=value.getPopulation();
            res=value;
        }
    }
    return res;
}

Settlement SettlementStatisticsImpl::minPopulation() const {
    int minpop=100000;
    Settlement res("","",0);
    for(auto& [key,value]: settlements){
        if(value.getPopulation()<minpop){
            minpop=value.getPopulation();
            res=value;
        }
    }
    return res;
}

vector<Settlement> SettlementStatisticsImpl::findSettlementsByName(const string &name) {
    vector<Settlement> result;
    for(auto& [key,value]: settlements){
        if(value.getName()==name) result.push_back(value);
    }
    return result;
}
