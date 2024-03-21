#ifndef MOVIECONTROLLER_H
#define MOVIECONTROLLER_H

#include <QObject>
#include <QJsonDocument>

#include "./model/moviemodel.h"
#include "./converter/movieconverter.h"
#include "./network/networkrequester.h"

class MovieController : public QObject {
public:
    MovieController();
    QList<MovieModel*> moviesConverter( const QByteArray& data );
    QList<MovieModel*> searchWithParamns( const QString& filter );
    void doRequest( QUrl url );

private:
    QList<MovieModel*> _movies;
    MovieConverter _converter;
    NetworkRequester _requester;
    QJsonDocument dataToJSON( const QByteArray& data ) const;
};

#endif // MOVIECONTROLLER_H
