#ifndef MAINSCREENCONTROL_H
#define MAINSCREENCONTROL_H

#include <memory>
#include <QObject>
#include "./controller/moviecontroller.h"

class MainScreenControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString sessionDescription READ sessionDescription WRITE setSessionDescription NOTIFY sessionDescriptionChanged )
    Q_PROPERTY( QList<MovieModel*> movies READ movieList NOTIFY moviesChanged )

public:
    explicit MainScreenControl( QObject* parent = nullptr );

    void loadInitialMovies();
    QList<QObject*> moviesToObject( QList<MovieModel*> movies ) const;

public slots:
    void doStart();
    QString sessionDescription() const;
    void setSessionDescription( const QString& sessionDescription );

    int qtMovies() const;

    void search( const QString& filter );

    QList<MovieModel*> movieList() const;

    void selectedMovie( const int index );
    void setMovies( QList<MovieModel*>& movies );

signals:
    void sessionDescriptionChanged();
    void moviesChanged();

    void movies( QList<QObject*> movies );
    void showDetail( QObject* movie );

private:
    MovieModel* _movie;
    QList<MovieModel*> _initialMovies;
    QList<MovieModel*> _movies;
    QString _sessionDescription;
    std::unique_ptr<MovieController> _controller;
};

#endif // MAINSCREENCONTROL_H
