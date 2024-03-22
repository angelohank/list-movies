#include "moviecontroller.h"

#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

constexpr char* URL = "http://api.tvmaze.com/search/shows?q=";

MovieController::MovieController() :
    _movies( {} ){}

QList<MovieModel*> MovieController::moviesConverter( const QByteArray& data ) {
    QJsonDocument moviesToJSON = dataToJSON( data );
    QJsonObject jsonObject = moviesToJSON.object();

    _movies = _converter.fromJson( moviesToJSON );

    return _movies;
}

QList<MovieModel*> MovieController::searchWithParamns( const QString& filter ) {
    QString urlWithParamns = ( URL + filter );
    doRequest( QUrl( urlWithParamns ) );

    return _movies;
}

QList<MovieModel*> MovieController::searchInitialMovies() {
    QList<QString> movieNameList = {
        "The Office",
        "Breaking Bad",
        "The Big Bang Theory",
        "The Walking Dead",
        "Stranger Things",
        "Loki",
        "Gameof Thrones",
        "House of Dragons",
        "The Boys"
    };

    QList<MovieModel*> initialMovies = {};

    for( QString name : movieNameList ) {
        initialMovies.append( searchWithParamns( name ).first() );
    }

    return initialMovies;
}

void MovieController::doRequest( QUrl url ) {
    QObject::connect( &_requester, &NetworkRequester::requestFinished, this, &MovieController::moviesConverter );

    _requester.makeRequest( url );
}

QJsonDocument MovieController::dataToJSON( const QByteArray& data ) const {
    QJsonDocument JSON = QJsonDocument::fromJson( data );
    return JSON;
}
