#ifndef MAINSCREENCONTROL_H
#define MAINSCREENCONTROL_H

#include <QObject>
#include "./network/networkrequester.h"

class MainScreenControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString sessionDescription READ sessionDescription WRITE setSessionDescription NOTIFY sessionDescriptionChanged )

public:
    explicit MainScreenControl( QObject* parent = nullptr );

public slots:
    void doStart();
    QString sessionDescription() const;
    void setSessionDescription( const QString& sessionDescription );

signals:
    void sessionDescriptionChanged();

private:
    QString _sessionDescription;
    NetworkRequester _requester;
};

#endif // MAINSCREENCONTROL_H
