#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QObject>
#include "showmodel.h"

class MovieModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( double score READ score NOTIFY scoreChanged )
    Q_PROPERTY( ShowModel* show READ show NOTIFY showChanged )
public:
    MovieModel();
    MovieModel( const double score, ShowModel* show );

    double score() const;
    void setScore( const double score );

    ShowModel* show() const;
    void setShow( ShowModel* show );

    static constexpr const char* SCORE = "score";

signals:
    void scoreChanged();
    void showChanged();

private:
    double _score;
    ShowModel* _show;
};

#endif // MOVIEMODEL_H
