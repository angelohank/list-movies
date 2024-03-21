#include "networkrequester.h"

#include <QEventLoop>

NetworkRequester::NetworkRequester( QObject *parent ) :
    QObject( parent ) {}

void NetworkRequester::makeRequest( const QUrl& url ) {
    QNetworkRequest request( url );

    QNetworkReply* response = nullptr;

    try {
        response = manager.get( request );
    } catch( std::exception e ) {
        qDebug() << e.what();
    }

    QEventLoop eventLoop;
    QObject::connect( &manager, SIGNAL( finished( QNetworkReply* ) ), &eventLoop, SLOT( quit() )  );
    eventLoop.exec();

    emit requestFinished( response->readAll() );
    delete( response );
}
