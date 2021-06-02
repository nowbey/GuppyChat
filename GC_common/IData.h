#ifndef IDATA_H
#define IDATA_H

#include <QString>
#include <QDataStream>

class IData
{
public:
    IData();

    virtual const QByteArray& serialize();
    virtual void deserialize(QDataStream& inStream);

private:

};

#endif // IDATA_H
