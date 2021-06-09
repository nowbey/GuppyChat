#ifndef GUPPYUSERVALIDATION_H
#define GUPPYUSERVALIDATION_H
#include "IGuppyMessage.h"

class GuppyUserValidation : public IGuppyMessage
{
public:
    GuppyUserValidation();
    GuppyUserValidation(bool GuppyUserValidationVar);


private:
    bool GuppyUserValidationVar;

public:
    bool GetGuppyUserValidationVar() const;

    QDataStream& serialize(QDataStream& out) const;
    QDataStream& deserialize(QDataStream& inStream);

};

#endif // GUPPYUSERVALIDATION_H
