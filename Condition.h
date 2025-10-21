#ifndef CONDITION_H
#define CONDITION_H

class Plant;

class Condition {
    protected:
        Plant* cPlant;
        void adjustGrowth(int amount);
        void adjustWater(int amount);
        void adjustNutrition(int amount);

    public:
    Condition(Plant* plant);
    virtual ~Condition();
    virtual void examine() = 0;
};

class Healthy : public Condition {
    public:
        Healthy(Plant* plant);
        ~Healthy();
        void examine() override;
};

class Dehydrated : public Condition {
    public:
        Dehydrated(Plant* plant);
        ~Dehydrated();
        void examine() override;
};

class DehydratedOverGrown : public Condition {
    public:
        DehydratedOverGrown(Plant* plant);
        ~DehydratedOverGrown();
        void examine() override;
};

class DehydratedMalnurished : public Condition {
    public:
        DehydratedMalnurished(Plant* plant);
        ~DehydratedMalnurished();
        void examine() override;
};

class DehydratedMalnurishedOverGrown : public Condition {
    public:
        DehydratedMalnurishedOverGrown(Plant* plant);
        ~DehydratedMalnurishedOverGrown();
        void examine() override;
};

class Malnurished : public Condition {
    public:
        Malnurished(Plant* plant);
        ~Malnurished();
        void examine() override;
};

class MalnurishedOverGrown : public Condition {
    public:
        MalnurishedOverGrown(Plant* plant);
        ~MalnurishedOverGrown();
        void examine() override;
};

class OverGrown : public Condition {
    public:
        OverGrown(Plant* plant);
        ~OverGrown();
        void examine() override;
};

#include "Plant.h"

#endif // CONDITION_H