#ifndef NETWORKREQUESTER_H
#define NETWORKREQUESTER_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

class NetworkRequester : public QObject {
    Q_OBJECT
public:
    explicit NetworkRequester( QObject* parent = nullptr );
    void makeRequest( const QUrl& url );

signals:
    void requestFinished( const QByteArray& data );

private:
    QNetworkAccessManager manager;
};

#endif // NETWORKREQUESTER_H
