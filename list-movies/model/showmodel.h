#ifndef SHOWMODEL_H
#define SHOWMODEL_H

#include <QObject>
#include <QString>
#include <QList>

class ShowModel : public QObject {
    Q_OBJECT
    Q_PROPERTY( double average READ average NOTIFY averageChanged )
    Q_PROPERTY( QString nome READ nome NOTIFY nomeChanged )
    Q_PROPERTY( QString imagem READ imagem NOTIFY imagemChanged )
    Q_PROPERTY( QString descricao READ descricao NOTIFY descricaoChanged )
    Q_PROPERTY( QList<QString> generos READ generos NOTIFY generosChanged )

public:
    ShowModel();
    ShowModel( const QString& nome, const QString& imagem, const QString& descricao );

    double average() const;
    void setAverage( const double average );

    QString nome() const;
    void setNome( const QString& nome );

    QString imagem() const;
    void setImagem( const QString& path );

    QString descricao() const;
    void setDescricao( const QString& descricao );

    QList<QString> generos() const;
    void setGeneros( const QList<QString>& generos );

    static constexpr const char* SHOW = "show";
    static constexpr const char* NAME = "name";
    static constexpr const char* SUMMARY = "summary";
    static constexpr const char* GENRES = "genres";
    static constexpr const char* RATING = "rating";
    static constexpr const char* AVERANGE = "average";
    static constexpr const char* IMAGE = "image";
    static constexpr const char* ORIGINAL = "original";
    static constexpr const char* MEDIUM = "medium";

signals:
    void averageChanged();
    void nomeChanged();
    void imagemChanged();
    void descricaoChanged();
    void generosChanged();

private:
    double _average;
    QString _nome;
    QString _imagem;
    QString _descricao;
    QList<QString> _generos;
};

#endif // SHOWMODEL_H
