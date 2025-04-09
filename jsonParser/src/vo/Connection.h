#ifndef CONNECTION_H
#define CONNECTION_H

#include <QUuid>

struct Connection
{
    QUuid from;
    QUuid to;
};

#endif //CONNECTION_H
