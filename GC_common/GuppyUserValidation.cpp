#include "GuppyUserValidation.h"

GuppyUserValidation::GuppyUserValidation(){
    GuppyUserValidationVar=false;
    this->MessageObjectType = MessageType::GUPPYUSERVALIDATION;
}

GuppyUserValidation::GuppyUserValidation(bool GuppyUserValidationVar) : GuppyUserValidationVar(GuppyUserValidationVar){
    this->MessageObjectType = MessageType::GUPPYUSERVALIDATION;
}



bool  GuppyUserValidation::GetGuppyUserValidationVar() const{
    return GuppyUserValidationVar;
}


QDataStream& GuppyUserValidation::serialize(QDataStream& out) const {
    QString SerialGuppyUserValidationVar;
    if (GuppyUserValidationVar == true) SerialGuppyUserValidationVar = "1";
    else SerialGuppyUserValidationVar = "0";
    out << SerialGuppyUserValidationVar;
    return out;
}

QDataStream& GuppyUserValidation::deserialize(QDataStream& inStream){
    QString SerialGuppyUserValidationVar;
    inStream >> SerialGuppyUserValidationVar;
    if (SerialGuppyUserValidationVar == "1") GuppyUserValidationVar = true;
    else GuppyUserValidationVar = false;
    return inStream;
}
