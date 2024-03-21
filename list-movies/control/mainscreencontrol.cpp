#include "mainscreencontrol.h"

#include <QDebug>
#include <QList>

constexpr int MAX_SIZE = 5;

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _movies( {} ),
    _sessionDescription( "Em alta" ),
    _controller( new MovieController() ){}

void MainScreenControl::loadInitialMovies() {
    //TODO carregar series em alta
}

void MainScreenControl::doStart() {
    loadInitialMovies();
}

QString MainScreenControl::sessionDescription() const {
    return _sessionDescription;
}

void MainScreenControl::setSessionDescription( const QString &sessionDescription ) {
    if( _sessionDescription == sessionDescription ) {
        return;
    }

    _sessionDescription = sessionDescription;
    emit sessionDescriptionChanged();
}

int MainScreenControl::qtMovies() const {
    return _movies.size();
}

void MainScreenControl::moviesConverter( const QByteArray& data ) {
    _movies = _controller->moviesConverter( data );
    emit qtMoviesChanged();
}

QList<MovieModel*> MainScreenControl::search( const QString& filter ) {
    setSessionDescription( "Resultados" );
    _movies = _controller->searchWithParamns( filter );

    return _movies;
}
