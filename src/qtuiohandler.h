#ifndef QQTuioHandler_H
#define QQTuioHandler_H

#include <QObject>
#include <QMap>
#include <QUdpSocket>
#include <QVector>

#include "qtuiocursor_p.h"
#include "qtuiotoken_p.h"
#include "qoscbundle_p.h"
#include "qoscmessage_p.h"
#include "udp_client.h"

class QTuioHandler : public QObject
{
    Q_OBJECT
public:
    explicit QTuioHandler(QObject *parent = nullptr);
    explicit QTuioHandler(const QHostAddress& ip, unsigned port, QObject *parent = nullptr);
    virtual ~QTuioHandler();

signals:
    void cursorEvent(const QMap<int, QTuioCursor>& active_cursors,
                     const QVector<QTuioCursor>& dead_cursors);
    void tokenEvent(QMap<int, QTuioToken> active_token, QVector<QTuioToken> dead_token);

public slots:
    void processPackets(const QByteArray&, const QHostAddress&, unsigned);

    void process2DCurSource(const QOscMessage &message);
    void process2DCurAlive(const QOscMessage &message);
    void process2DCurSet(const QOscMessage &message);
    void process2DCurFseq(const QOscMessage &message);

    void process2DObjSource(const QOscMessage &message);
    void process2DObjAlive(const QOscMessage &message);
    void process2DObjSet(const QOscMessage &message);
    void process2DObjFseq(const QOscMessage &message);

protected:

    UdpClient *client_;
    QMap<int, QTuioCursor> active_cursors_;
    QVector<QTuioCursor> dead_cursors_;
    QMap<int, QTuioToken> active_tokens_;
    QVector<QTuioToken> dead_tokens_;
};

#endif // QQTuioHandler_H
