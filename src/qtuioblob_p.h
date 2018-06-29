#ifndef TUIO_BLOB_H
#define TUIO_BLOB_H

#include <cmath>
#include <Qt>

class QTuioBlob
{
    public:

        QTuioBlob(int id = -1)
            : id_(id)
            , x_()
            , y_()
            , angle_()
            , width_()
            , height_()
            , area_()
            , vx_()
            , vy_()
            , vr_()
            , acceleration_()
            , rotation_accel_()
        {}

        int id() const {return id_;}

        void setX(float x ) {
            if (state() == Qt::TouchPointStationary &&
                    !qFuzzyCompare(x_ + 2.0, x + 2.0)) { // +2 because 1 is a valid value, and qFuzzyCompare can't cope with 0.0
                setState(Qt::TouchPointMoved);
            }
            x_ = x;
        }
        float x() const {return x_;}

        void setY(float y) {

            if (state() == Qt::TouchPointStationary &&
                    !qFuzzyCompare(y_ + 2.0, y + 2.0)) { // +2 because 1 is a valid value, and qFuzzyCompare can't cope with 0.0
                setState(Qt::TouchPointMoved);
            }
            y_ = y;
        }
        float y() const { return y_;}


        void setVX(float vx) { vx_ = vx; }
        float vx() const { return vx_; }

        void setVY(float vy) { vy_ = vy; }
        float vy() const { return vy_; }

        void setAcceleration(float acceleration) { acceleration_ = acceleration; }
        float acceleration() const { return acceleration_; }

        void setAngle(float angle)
        {
            if (angle > M_PI)
                angle = angle - M_PI * 2.0; // zero is pointing upwards, and is the default; but we want to have negative angles when rotating left
            if (state() == Qt::TouchPointStationary &&
                    !qFuzzyCompare(angle_ + 2.0, angle + 2.0)) { // +2 because 1 is a valid value, and qFuzzyCompare can't cope with 0.0
                setState(Qt::TouchPointMoved);
            }
            angle_ = angle;
        }
        float angle() const { return angle_; }

        void setState(const Qt::TouchPointState &state) { state_ = state; }
        Qt::TouchPointState state() const { return state_; }

        void setWidth(float w) { width_ = w;}
        float width() const { return width_;}

        void setHeight(float h) { height_ = h;}
        float height() const { return height_;}

        void setArea(float a) { area_ = a;}
        float area() const { return area_;}

        void setVR(float rs) { vr_ = rs;}
        float vr() const { return vr_;}

        void setRotationAcceleration(float ra) { rotation_accel_ = ra;}
        float rotationAcceleration() const { return rotation_accel_;}

    private:
        int id_;
        float x_;
        float y_;
        float angle_;
        float width_;
        float height_;
        float area_;
        float vx_;
        float vy_;
        float vr_;
        float acceleration_;
        float rotation_accel_;
        Qt::TouchPointState state_;

};

#endif // TUIO_BLOB_H
