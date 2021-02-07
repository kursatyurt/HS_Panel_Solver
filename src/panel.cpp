#include "panel.hpp"

//Class Constructor
Panel::Panel(int i, const std::vector<Point> &point)
{
    this->panel_num = i;
    this->xm = (point[i].x + point[i+1].x) * 0.5;
    this->ym = (point[i].y + point[i+1].y) * 0.5 ;
    this->sinthe = sin(atan2(point[i+1].y - point[i].y, point[i+1].x - point[i].x));
    this->costhe = cos(atan2(point[i+1].y - point[i].y, point[i+1].x - point[i].x));
}

void Panel::update(const std::vector<Point> &point)
{
    auto i = this-> panel_num;
    this->xm = (point[i].x + point[i+1].x) * 0.5;
    this->ym = (point[i].y + point[i+1].y) * 0.5 ;
    this->sinthe = sin(atan2(point[i+1].y - point[i].y, point[i+1].x - point[i].x));
    this->costhe = cos(atan2(point[i+1].y - point[i].y, point[i+1].x - point[i].x));
}