#include "GuppyUserValidation.h"

GuppyUserValidation::GuppyUserValidation(){
    GuppyUserValidationVar=false;
    this->MessageObjectType = MessageType::GUPPYUSERVALIDATION;
}

GuppyUserValidation::GuppyUserValidation(bool GuppyUserValidationVar) : GuppyUserValidationVar(GuppyUserValidationVar){
    this->GuppyUserValidationVar = GuppyUserValidationVar;
    this->MessageObjectType = MessageType::GUPPYUSERVALIDATION;
}



bool GuppyUserValidation::GetGuppyUserValidationVar() const{
    return this->GuppyUserValidationVar;
}


QDataStream& GuppyUserValidation::serialize(QDataStream& out) const {
    out << this->GuppyUserValidationVar;
    return out;
}

QDataStream& GuppyUserValidation::deserialize(QDataStream& inStream){
    inStream >> this->GuppyUserValidationVar;
    return inStream;
}
