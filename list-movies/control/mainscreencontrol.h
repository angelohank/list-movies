#ifndef MAINSCREENCONTROL_H
#define MAINSCREENCONTROL_H

#include <memory>
#include <QObject>
#include "./network/networkrequester.h"
#include "./controller/moviecontroller.h"

class MainScreenControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString sessionDescription READ sessionDescription WRITE setSessionDescription NOTIFY sessionDescriptionChanged )

public:
    explicit MainScreenControl( QObject* parent = nullptr );

public slots:
    void doStart();
    QString sessionDescription() const;
    void setSessionDescription( const QString& sessionDescription );

    void moviesConverter( const QByteArray& data);
    QList<MovieModel*> search( const QString& filter );

signals:
    void sessionDescriptionChanged();

private:
    QString _sessionDescription;
    NetworkRequester _requester;
    std::unique_ptr<MovieController> _controller;
};

#endif // MAINSCREENCONTROL_H
