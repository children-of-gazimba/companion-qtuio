#include "main_widget.h"

#include <QHostAddress>
#include <QJsonDocument>

#include <QHBoxLayout>

#include <QGraphicsView>
#include <QPainter>
#include <QtMath>
#include <QBrush>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , width_(800)
    , height_(600)
    , marker_list_()
    , scene_(0)
    , view_(0)
    , tuio_handler_(0)
{
    tuio_handler_ = new QTuioHandler(this);

    initWidgets();
    initLayout();

    connect(tuio_handler_, &QTuioHandler::cursorEvent,
            this, &MainWidget::onCursorEvent);
    connect(tuio_handler_, &QTuioHandler::tokenEvent,
            this, &MainWidget::onTokenEvent);
    connect(tuio_handler_, &QTuioHandler::blobEvent,
            this, &MainWidget::onBlobEvent);
}

MainWidget::~MainWidget()
{
    scene_->deleteLater();
    for(auto m : marker_list_) {
        delete m;
    }
}

void MainWidget::onCursorEvent(QMap<int, QTuioCursor> active_cursors, QVector<QTuioCursor> dead_cursors)
{
    // add cursor
    for(auto id: active_cursors.keys())
    {
        QTuioCursor cursor = active_cursors[id];
        if(!marker_list_.keys().contains(id)) {
            auto marker = new QGraphicsEllipseItem(0,0,10,10);
            marker->setX(width_ * (1-cursor.x()));
            marker->setY(height_ * (1-cursor.y()));
            marker_list_[id] = marker;
            scene_->addItem(marker);
        } else {
            marker_list_[id]->setX(width_ * (1-cursor.x()));
            marker_list_[id]->setY(height_ * (1-cursor.y()));
        }
    }

    // remove all dead cursors
    for(QTuioCursor c: dead_cursors)
    {
        int id = c.id();
        if(marker_list_.keys().contains(id)) {
            scene_->removeItem(marker_list_[id]);
            delete marker_list_[id];
            marker_list_.remove(id);
        }
    }
}

void MainWidget::onTokenEvent(QMap<int, QTuioToken> active_token, QVector<QTuioToken> dead_token)
{
    for(auto id: active_token.keys()) {

        QTuioToken token = active_token[id];
        if(!token_list_.keys().contains(id)) {
            auto marker = new QGraphicsRectItem(0,0,10,10);
            marker->setBrush(QBrush(Qt::red));
            marker->setX(width_ * (1-token.x()));
            marker->setY(width_ * (1-token.y()));
            marker->setRotation(qRadiansToDegrees(token.angle()));
            token_list_[id] = marker;
            scene_->addItem(marker);
        } else {
            token_list_[id]->setX(width_ * (1-token.x()));
            token_list_[id]->setY(width_ * (1-token.y()));
            token_list_[id]->setRotation(qRadiansToDegrees(token.angle()));
        }
    }

    for(QTuioToken t: dead_token) {
        int id = t.id();
        if(token_list_.keys().contains(id)) {
            scene_->removeItem(token_list_[id]);
            delete token_list_[id];
            token_list_.remove(id);
        }
    }

}

void MainWidget::onBlobEvent(QMap<int, QTuioBlob> active_bobs, QVector<QTuioBlob> dead_bobs)
{
    for(auto id: active_bobs.keys()) {

        QTuioBlob bob = active_bobs[id];
        if(!blob_list_.keys().contains(id)) {
            auto marker = new QGraphicsEllipseItem(0,0,bob.width() * width_ ,bob.height() * height_);
            marker->setBrush(QBrush(Qt::blue));
            marker->setX(width_ * (1-bob.x()));
            marker->setY(width_ * (1-bob.y()));
            marker->setRotation(qRadiansToDegrees(bob.angle()));
            blob_list_[id] = marker;
            scene_->addItem(marker);
        } else {
            blob_list_[id]->setX(width_ * (1-bob.x()));
            blob_list_[id]->setY(width_ * (1-bob.y()));
            blob_list_[id]->setRotation(qRadiansToDegrees(bob.angle()));
        }
    }

    for(QTuioBlob t: dead_bobs) {
        int id = t.id();
        if(blob_list_.keys().contains(id)) {
            scene_->removeItem(blob_list_[id]);
            delete blob_list_[id];
            blob_list_.remove(id);
        }
    }


}

void MainWidget::initWidgets()
{
    scene_ = new QGraphicsScene();
    scene_->setSceneRect(0,0, width_ , height_);

    view_ = new QGraphicsView(scene_, this);
    view_->setRenderHints(QPainter::Antialiasing);
}

void MainWidget::initLayout()
{
    QHBoxLayout *root = new QHBoxLayout;
    root->addWidget(view_);

    setLayout(root);
}


