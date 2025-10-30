#include "Request.h"


/**
 * @details Constructor for the Place request class
 * @param plant The plant to be assigned a gardener
 */
Place::Place(Plant* plant){
    this->plant=plant;
}

/**
 * @details assigns the gardener parameter to the request
 * @param me The gardener to be assigned to the request
 */

void Place::setParam(Gardener* me){
    this->param=me;
}

/**
 * @details assigns the gardener to the plant 
 */
void Place::execute(){
    if(param!=nullptr && plant!=nullptr){
        plant->setGardener(param);
    }else{
        cout<<"Place request execution failed: missing parameter(s)."<<endl;
    }
}

/**
 * @details Constructor for the Water request class
 * @param plant The plant to be watered
 */
Water::Water(Plant* plant){
    this->plant=plant;
}

/**
 * @details waters the plant
 */
void Water::execute(){
    if(plant!=nullptr){
        plant->water();
    }else{
        cout<<"Water request execution failed: missing plant parameter."<<endl;
    }
}

/**
 * @details Constructor for the Fertilize request class
 * @param plant The plant to be fertilized
 */
Fertilise::Fertilise(Plant* plant){
    this->plant=plant;
}

/**
 * @details fertilises the plant
 */
void Fertilise::execute(){
    if(plant!=nullptr){
        plant->fertilise();
    }else{
        cout<<"Fertilize request execution failed: missing plant parameter."<<endl;
    }
}

/**
 * @details Constructor for the Prune request class
 * @param plant The plant to be pruned
 */
Prune::Prune(Plant* plant){
    this->plant=plant;
}

/**
 * @details prunes the plant
 */
void Prune::execute(){
    if(plant!=nullptr){
        plant->prune();
    }else{
        cout<<"Prune request execution failed: missing plant parameter."<<endl;
    }
}


