#ifndef SHOWMODEL_H
#define SHOWMODEL_H

#include <QString>
#include <QList>

class ShowModel
{
public:
    ShowModel();

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

private:
    double _average;
    QString _nome;
    QString _imagem;
    QString _descricao;
    QList<QString> _generos;
};

#endif // SHOWMODEL_H
