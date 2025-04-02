#ifndef CONNECTIONREADER_H
#define CONNECTIONREADER_H
#include "Blocks/Block.h"
#include "Blocks/Connection.h"


class ConnectionReader {
public:
    ConnectionReader() {};
    static Connection* extract(QQuickItem* anchor);

    static ConnectionReader* Instance()
    {
        if (instance == nullptr)
        {
            instance = new ConnectionReader();
        }
        return instance;
    }

private:
    static ConnectionReader* instance;

    static QUuid readUuidProperty(QQuickItem* anchor, QString propertyName);
    static std::string readProperty(QQuickItem* anchor, QString propertyName);
};



#endif //CONNECTIONREADER_H
