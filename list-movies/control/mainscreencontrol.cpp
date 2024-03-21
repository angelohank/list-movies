#include "mainscreencontrol.h"

#include <QObject>
#include <QDebug>
#include <QList>

MainScreenControl::MainScreenControl( QObject* parent ) :
    QObject( parent ),
    _movies( {} ),
    _sessionDescription( "Em alta" ),
    _controller( new MovieController() ){}

void MainScreenControl::loadInitialMovies() {
    //TODO carregar series em alta
}

QList<QObject*> MainScreenControl::moviesToObject( QList<MovieModel*> movies ) const {
    QList<QObject*> movieObjects = {};

    for( MovieModel* movie : _movies ) {
        QObject* object = qobject_cast<QObject*>( movie );

        if( object ) {
            movieObjects.append( movie );
        }
    }

    return movieObjects;
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

void MainScreenControl::search( const QString& filter ) {
    setSessionDescription( "Resultados" );
    _movies = _controller->searchWithParamns( filter );

    QList<QObject*> movieObjects = moviesToObject( _movies );

    emit movies( movieObjects );
}

QList<MovieModel*> MainScreenControl::movieList() const {
    return _movies;
}

void MainScreenControl::selectedMovie( const int index ) {
    qDebug() << index;

    _movie = movieList().at( index );

    QObject* movieObject = qobject_cast<QObject*>( _movie );

    emit showDetail( movieObject );
}
