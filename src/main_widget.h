#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QObject>
#include <QWidget>

#include <QMap>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>

#include "udp_client.h"
#include "qtuiohandler.h"

class MainWidget : public QWidget
{
        Q_OBJECT
    public:
        explicit MainWidget(QWidget *parent = nullptr);
        virtual ~MainWidget();

    signals:

    public slots:
        void onCursorEvent(QMap<int, QTuioCursor> active_cursors, QVector<QTuioCursor> dead_cursors);
        void onTokenEvent(QMap<int, QTuioToken> active_cursors, QVector<QTuioToken> dead_cursors);
        void onBlobEvent(QMap<int, QTuioBlob> active_bobs, QVector<QTuioBlob> dead_bobs);

    private:
        void initWidgets();
        void initLayout();

    private:
        int width_;
        int height_;

        QMap<int, QGraphicsEllipseItem*> marker_list_;
        QMap<int, QGraphicsRectItem*> token_list_;
        QMap<int, QGraphicsEllipseItem*> blob_list_;

        QGraphicsScene *scene_;
        QGraphicsView *view_;

        QTuioHandler *tuio_handler_;
};

#endif // MAIN_WIDGET_H
