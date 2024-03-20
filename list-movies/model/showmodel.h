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

private:
    double _average;
    QString _nome;
    QString _imagem;
    QString _descricao;
    QList<QString> _generos;
};

#endif // SHOWMODEL_H
